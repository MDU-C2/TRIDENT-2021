//#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <inttypes.h>

//i2c commands:
#define MS5837_ADDR               0x76  		
#define MS5837_ADDR_WRITE		  0xEC
#define MS5837_RESET              0x1E
#define MS5837_ADC_READ           0x00			//Reads from the ADC after a convert call
#define MS5837_PROM_READ          0xA0			//Reads the calibration data from the PROM. Needs 7 reads of 2 bytes after this command
#define MS5837_CONVERT_D1_8192    0x4A			//D1 is pressure. Requests that pressure data be sent to ADC. Should be followed by adc read
#define MS5837_CONVERT_D1_4096	  0x48			//keeps on halving down to OSR 256 at 0x40
#define MS5837_CONVERT_D2_8192    0x5A			//D2 is temperature
#define MS5837_CONVERT_D2_4096	  0x58			//same deal with the OSR number.

#define BUFFER_SIZE				  5				//shouldnt need to be bigger than 3, really.

//#define DEBUG								//Enable debug messages for memory allocation
//#define PRINT_OUTPUT							//Enable result and error print commands
//#define SAVE_TO_FILE							//Enable results and errors saved to text file 

char buffer[BUFFER_SIZE]; 						//i2c buffer for read and write
uint8_t bufferlength;							//keeps track of expected length of buffer.
int file; 										//File handler for i2c 

const float Pa = 100.0f;
const float Fluid_Density = 997.0f;			//997 freshwater, 1029 for seawater

//Functions:
int init();							//Initialization. Runs i2c_init and i2c_read_prom
int i2c_init();								//Opens and sets the i2c port. Writes the reset command
uint8_t crc4();								//CRC check for calibration data in C
void i2c_read_prom(int file);				//Reads calibration values from PROM and sets them to C
void request_calc();						//Overhead function that gets called by ada and calls other functions to calculate temp and depth
void freeBuf(char* buf);
char* request_calc_values();						//same as request_calc but returns values
void i2c_read_pressure(int file);			//Requests pressure data to be sent to ADC, then reads from ADC. Saves to D1
void i2c_read(int file, uint8_t bytestoread);		//general i2c read function
void i2c_write(int file, uint8_t cmd);				//general i2c write function
void i2c_read_temperature(int file);		//Requests temperature data to be sent to ADC, then reads from ADC. Saves to D2
void calculate();				//Calculates the temperature and the pressure from the values of C, D1 and D2
float depth();					//Returns the depth
float temperature();			//Returns the temperature
float pressure();                       //Returns the pressure

#ifdef SAVE_TO_FILE
FILE *excel;
#endif

uint32_t C[8];      //config values from PROM
uint32_t D1; 	//uncompensated pressure value from ADC
uint32_t D2;		//uncompensated temperature value from ADC
int32_t TEMP;	//Temperature | Changed to int32_t from uint32_t since the datasheet says so https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Data+Sheet%7FMS5837-30BA%7FB1%7Fpdf%7FEnglish%7FENG_DS_MS5837-30BA_B1.pdf%7FCAT-BLPS0017 2021-11-11
int32_t P; 		//pressure  (mbar) | Changed to int32_t from uint32_t since the datasheet says so https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Data+Sheet%7FMS5837-30BA%7FB1%7Fpdf%7FEnglish%7FENG_DS_MS5837-30BA_B1.pdf%7FCAT-BLPS0017 2021-11-11
