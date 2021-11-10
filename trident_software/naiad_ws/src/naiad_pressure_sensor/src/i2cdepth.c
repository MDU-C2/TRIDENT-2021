#include "i2cdepth.h"

/* I wrote this main for testing
int main()
{
	int run = 1;
	init();
	while(run)
	{
		request_calc();
		printf("Temperature: %f, Depth: %f", temperature(), depth());
		printf("Again? (1/0)\n ");
		scanf("%d", &run);
	}
	return 0;
}
*/
int init()
{
	#ifdef SAVE_TO_FILE
	excel = fopen("sensorOutput.txt", "w");
	#endif
	file = i2c_init();  
	i2c_read_prom(file);	
}

void request_calc()
{
	#ifdef SAVE_TO_FILE
	fopen("sensorOutput.txt", "a");
	#endif
	D1 = 0;
	D2 = 0;
	i2c_read_pressure(file);
	i2c_read_temperature(file);
	calculate();
	#ifdef PRINT_OUTPUT
	printf("Temperature: %f°C, Pressure: %d mbar, Depth: %fm \n", temperature(), P, depth());
	#endif
	#ifdef SAVE_TO_FILE
	fprintf(excel, "%f\t%d\t%f\n", temperature(), P, depth());
	fclose(excel);
	#endif
}

// used by other programs to free buffers allocated in this file
void freeBuf(char* buf){
	#ifdef DEBUG
	printf("freeing address: %p\n", buf);
	#endif
	free(buf);
}

char* request_calc_values()
{
	#ifdef SAVE_TO_FILE
	fopen("sensorOutput.txt", "a");
	#endif
	D1 = 0;
	D2 = 0;
	i2c_read_pressure(file);
	i2c_read_temperature(file);
	calculate();
	char* buf = malloc(100);
	#ifdef DEBUG
	printf("allocating address: %p\n", buf);
	#endif
	sprintf(buf, "%f,%d,%f", temperature(), P, depth());

	#ifdef PRINT_OUTPUT
	printf("Temperature: %f°C, Pressure: %d mbar, Depth: %fm \n", temperature(), P, depth());
	#endif
	#ifdef SAVE_TO_FILE
	fprintf(excel, "%f\t%d\t%f\n", temperature(), P, depth());
	fclose(excel);
	#endif
	return buf;
}

/*
	In the original configuration of the BBB, what is called i2c-2 in the BBB ref manual is referred to as i2c-1 in Linux.
	If the second (technically third) i2c bus is enabled, this may change. If there are problems, check the addresses of 
	the i2c buses with command:
	ls -l /sys/bus/i2c/devices/i2c-*
	The addresses are i2c0: 0x44E0_B000, i2c1: 0x4802_A000, i2c2: 0x4819_C000.
	By default, i2c-1 according to linux will have address 0x4819_C000, which will be i2c2 in the ref manual and header explanations etc.
*/

int i2c_init() 
{
    if ((file = open("/dev/i2c-1",O_RDWR)) < 0) {
		#ifdef PRINT_OUTPUT
        printf("Failed to open the bus. \n");
		#endif
		#ifdef SAVE_TO_FILE
		fprintf(excel, "Failed to open the bus. \n");
		#endif
        /* ERROR HANDLING; you can check errno to see what went wrong */
        exit(1);
    }


    if (ioctl(file,I2C_SLAVE,MS5837_ADDR) < 0) {
		#ifdef PRINT_OUTPUT
        printf("Failed to acquire bus access and/or talk to slave.\n");
		#endif
		#ifdef SAVE_TO_FILE
		fprintf(excel, "Failed to acquire bus access and/or talk to slave. \n");
		#endif
        /* ERROR HANDLING; you can check errno to see what went wrong */
        exit(1);
    }
	
	i2c_write(file, MS5837_RESET);
	usleep(10000); //Wait for reset.
	#ifdef PRINT_OUTPUT
	printf("Init successful\n");
	#endif
	#ifdef SAVE_TO_FILE
	fprintf(excel, "Init successful. \n");
	#endif
	return file;
}

void i2c_read_prom(int file)
{
	uint8_t i, y;
	for ( i = 0 ; i < 7 ; i++ ) {
		i2c_write(file, MS5837_PROM_READ+i*2);
		i2c_read(file, 2);
		for(y = 0; y < bufferlength ; ++y)
		{
			C[i] = (C[i] << 8) | buffer[y];
		}
		#ifdef SAVE_TO_FILE
		fprintf(excel, "C%d: %d \t", i, C[i]);
		#endif
		bufferlength = 0;
		
	}
	#ifdef SAVE_TO_FILE
	fprintf(excel, "\n");
	fclose(excel);
	#endif
	// Verify that data is correct with CRC
	uint8_t crcRead = C[0] >> 12;
	uint8_t crcCalculated = crc4();

	if ( crcCalculated == crcRead ) {   
		#ifdef PRINT_OUTPUT
		printf("CRC check succeeded. \n");
		#endif
		#ifdef SAVE_TO_FILE
		fprintf(excel, "CRC check succeeded. \n");
		#endif
		return;
	}
	else
	{
		#ifdef PRINT_OUTPUT
		printf("CRC check failed. \n");
		#endif
		#ifdef SAVE_TO_FILE
		fprintf(excel, "CRC check failed. \n");
		#endif
		exit(0);
	}
}

uint8_t crc4() 
{
	uint16_t n_rem = 0;

	C[0] = ((C[0]) & 0x0FFF);
	C[8] = 0;
	uint8_t i, n_bit;
	for ( i = 0 ; i < 16; i++ ) {
		if ( i%2 == 1 ) {
			n_rem ^= (uint16_t)((C[i>>1]) & 0x00FF);
		} else {
			n_rem ^= (uint16_t)(C[i>>1] >> 8);
		}
		for ( n_bit = 8 ; n_bit > 0 ; n_bit-- ) {
			if ( n_rem & 0x8000 ) {
				n_rem = (n_rem << 1) ^ 0x3000;
			} else {
				n_rem = (n_rem << 1);
			}
		}
	}
	
	n_rem = ((n_rem >> 12) & 0x000F);

	return n_rem ^ 0x00;
}

void i2c_read_pressure(int file)
{
	uint8_t i;
	i2c_write(file, MS5837_CONVERT_D1_8192);
	usleep(20000);   //Supposedly max conversion time according to datasheet...according to arduino lib. 20 msec, 20000 microsec
	i2c_write(file, MS5837_ADC_READ);
	i2c_read(file, 3);
	for(i = 0; i < bufferlength ; ++i)
	{
		D1 = (D1 << 8) | buffer[i];	
	}
	bufferlength = 0;
}

void i2c_read_temperature(int file)
{
	uint8_t i;
	i2c_write(file, MS5837_CONVERT_D2_8192);
	usleep(20000);   //Supposedly max conversion time according to datasheet...according to arduino lib. 20 msec, 20000 microsec
	i2c_write(file, MS5837_ADC_READ);
	i2c_read(file, 3);
	for(i = 0; i < bufferlength ; ++i)
	{
		D2 = (D2 << 8) | buffer[i];
	}
	bufferlength = 0;
}

void i2c_read(int file, uint8_t bytestoread)
{
    float data;
    char channel;

        if (read(file,buffer,bytestoread) != bytestoread) 
		{
            /* ERROR HANDLING: i2c transaction failed */
			#ifdef PRINT_OUTPUT
            printf("Failed to read from the i2c bus.\n");
			#endif
			#ifdef SAVE_TO_FILE
			fprintf(excel, "Failed to read from the i2c bus.\n");
			#endif
			exit(0);
        }
		else
			bufferlength = bytestoread;

    //}
}

void i2c_write(int file, uint8_t cmd)
{ 
	buffer[0] = cmd;

    if (write(file,buffer,1) != 1) {
        /* ERROR HANDLING: i2c transaction failed */
		#ifdef PRINT_OUTPUT
        printf("Failed to write to the i2c bus.\n");
		#endif
		#ifdef SAVE_TO_FILE
		fprintf(excel, "Failed to write to the i2c bus. \n");
		#endif
		exit(0);
	}
}

void calculate() {
	// Given C1-C6 and D1, D2, calculate TEMP and P
	// Do conversion first and then second order temp compensation
	// This code was stolen from the example code provided for sensor
	
	int32_t dT = 0;
	int64_t SENS = 0;
	int64_t OFF = 0;
	int32_t SENSi = 0;
	int32_t OFFi = 0;  
	int32_t Ti = 0;    
	int64_t OFF2 = 0;
	int64_t SENS2 = 0;
	
	// Terms called
	dT = D2-(uint32_t)C[5]*256l;

		SENS = (int64_t)C[1]*32768l+((int64_t)C[3]*dT)/256l;
		OFF = (int64_t)C[2]*65536l+((int64_t)C[4]*dT)/128l;
		P = (D1*SENS/(2097152l)-OFF)/(8192l);
	
	// Temp conversion
	TEMP = 2000l+(int64_t)dT*C[6]/8388608LL;
	
	//Second order compensation
		if((TEMP/100)<20){         //Low temp
			Ti = (3*(int64_t)dT*(int64_t)dT)/(8589934592LL);
			OFFi = (3*(TEMP-2000)*(TEMP-2000))/2;
			SENSi = (5*(TEMP-2000)*(TEMP-2000))/8;
			if((TEMP/100)<-15){    //Very low temp
				OFFi = OFFi+7*(TEMP+1500l)*(TEMP+1500l);
				SENSi = SENSi+4*(TEMP+1500l)*(TEMP+1500l);
			}
		}
		else if((TEMP/100)>=20){    //High temp
			Ti = 2*(dT*dT)/(137438953472LL);
			OFFi = (1*(TEMP-2000)*(TEMP-2000))/16;
			SENSi = 0;
		}
	
	OFF2 = OFF-OFFi;           //Calculate pressure and temp second order
	SENS2 = SENS-SENSi;
	

		TEMP = (TEMP-Ti);
		P = (((D1*SENS2)/2097152l-OFF2)/8192l)/10;
}

float depth() {
	return ((float)(P*Pa)-101300)/(Fluid_Density*9.80665);
}

float temperature() {
	return TEMP/100.0f;
}

float pressure() {
  return P;
}
