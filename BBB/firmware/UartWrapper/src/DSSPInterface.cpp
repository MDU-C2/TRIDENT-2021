
#include "stdafx.h"
#include "DSSPInterface.h"

#define REG_COMMAND 0x01
#define C_COMMAND_SHOOT 0x01
#define C_COMMAND_RESET 0x02
#define C_COMMAND_GET_VERSION 0x03

// Pulser
#define REG_PULSER_1_A 0x11
#define REG_PULSER_2_A 0x12

// Power detector	   
#define REG_POW_DET_0_A 0x20
#define REG_POW_DET_1_A 0x21
#define  REG_POW_DET_2_A 0x22
#define  REG_POW_DET_3_A 0x23
#define  REG_POW_DET_4_A 0x24
#define  REG_POW_DET_5_A 0x25
#define  REG_POW_DET_6_A 0x26
		 
	
CDSSPInterface::CDSSPInterface( )
{
}

void CDSSPInterface::Reset()				// Set baudrate to 9600 before Reset command
{
	SetReg( 0xAB,  0x05060708 );
}
	
void CDSSPInterface::SetPulse( 
		U32 nPeriods, 			
		float StartFreq,		
		float DeltaFreq 		
		)
{
	// int nPeriods     - Number of periods
	// float StartFreq  - Start frequency in [Hz]
	// float DeltaFreq  - Chirp delta frequency in [Hz], must be positive, DeltaFreq=(StopFreq-StartFreq)

	U32 chirpDown = 0;
	if( DeltaFreq < 0 ) {
		DeltaFreq = -DeltaFreq;
		chirpDown = 0x80000000;
	}

	if( DeltaFreq < 0 )
		DeltaFreq = -DeltaFreq;

	U32 F0 = (U32)( StartFreq * 0.0131072f + 0.5 );
	U32 dfr = (U32)( DeltaFreq * 1.666667f / nPeriods + 0.5 );
	
	SetReg( REG_PULSER_1_A, (dfr<<16)|(0xFFFF&F0) ); 

	SetReg( REG_PULSER_2_A, chirpDown | ((0x03FF&nPeriods)<<16)  );
}

void CDSSPInterface::SetSampling(
		U32 nSamples,			//
		U32 decimation,			// Sample resolution = 0.1781303[mm] * decimation, min TBD, max TBD
		bool left,				// True if left side
		bool right,				// 
		bool onePing			// false if continuous pinging
		)
{
	// U32 nSamples     - Number of samples
	// U32 decimation   - Sample resolution = 0.1781303[mm] * decimation, min TBD, max TBD
	
	U32 PD_Mode = 1; // 0-sum, 1-max
	
	U32 PD_nSamples = decimation; // Number of ADC samples per Ping-Sample

	unsigned int PD_ActiveChannels = 0x0;
	if( left )
		PD_ActiveChannels |= 0x01;
	if( right )
		PD_ActiveChannels |= 0x02;

	SetReg( REG_POW_DET_1_A, (PD_nSamples<<16) | (PD_ActiveChannels<<3) | (PD_Mode) );	

	SetReg( REG_POW_DET_5_A, nSamples );
	
	
	if( onePing ) {
		SetReg( REG_POW_DET_0_A, 0x1<<16 );
	}
	
}


void CDSSPInterface::Run( U32 baudrate )
{
	switch( baudrate ) {
		case 115200:
			SetReg( 0x01, 694 );	// Set UART and start 115200
			break;
		case 230400:
			SetReg( 0x01, 347 );	// Set UART and start 230400
			break;
		case 460800:
			SetReg( 0x01, 173 );	// Set UART and start 460800
			break;
		case 921600:
			SetReg( 0x01, 86 );	// Set UART and start 921600
			break;
		case 1000000:
			SetReg( 0x01, 80 );	// Set UART and start 1000000
			break;
		default:
			// Error
			break;
	}
}

void CDSSPInterface::SetReg( U16 reg, U32 value )
{
	// Set register packet: 0xA5, A(15:8), A(7:0), D(31:24), D(23:16), D(15:8), D(7:0), Checksum

	int i=0;

	U8 txBuff[8];
	txBuff[0] = 0xF5;	// Start of setup packet
	
	txBuff[1] = (U8)( (reg>>8) & 0xFF );
	txBuff[2] = (U8)( (reg) & 0xFF );

	txBuff[3] = (U8)( (value>>24) & 0xFF );
	txBuff[4] = (U8)( (value>>16) & 0xFF );
	txBuff[5] = (U8)( (value>>8) & 0xFF );
	txBuff[6] = (U8)( (value) & 0xFF );

	txBuff[7] = 0;
	for( i=0; i<7; i++ )
		txBuff[7] += txBuff[i];

	DSSPSend( txBuff, 8 );	 
}
	