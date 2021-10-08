//=============================================================================
// Project:       OEM
// Copyright:     DeepVision AB
// Author:        Fredrik Elmgren 
// Revision:      
//-----------------------------------------------------------------------------
// Description:	  Interface class DSSP OEM
//    
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Revision History:
//
// 
// 
//=============================================================================

//
// ********************************
// ****     Received data      ****
// ********************************
// 
// ** Ping Return Packet **
//  SOP1 0xFE 
//  SOP2 0x05
//  Size High
//  Size Low
//  Type 0x11
//  Sequence nr 0-255, +1 per ping
//  Active Sides
//  Time High [ms]
//  Time Low  [ms]
//  D_Ch0[0] Channel 0
//  D_Ch1[1] Channel 1	
//  ...
//  D_Ch0[nSamples-1]
//  D_Ch1[nSamples-1]
//  ChkSum 
//
//  Next packet
//  If single side packet only data for that side is transmitted


#ifndef __DSSPInterface2_H
#define __DSSPInterface2_H

typedef unsigned short U16;
typedef unsigned char U8;
typedef unsigned int U32;

void DSSPSend( const U8* pBytes, int nBytes ); // Needs to implemented

class CDSSPInterface
{
public:
	CDSSPInterface( );
	
	void Reset();				// Set baudrate to 9600 before Reset command

	// SONAR interface
	void SetPulse( 
		U32 nPeriods, 			// 0-off, min 4, max TBD
		float StartFreq,		// [Hz] 
		float DeltaFreq 		// [Hz] positive, end frequency = StartFreq + DeltaFreq
		);

	void SetSampling(
		U32 nSamples,			// Number of samples return in the Ping Return Packet
		U32 decimation,			// Sample resolution = 0.1781303[mm] * decimation, min TBD, max TBD
		bool left,				// True if left side
		bool right,				// 
		bool onePing			// false if continuous pinging
		);

	void Run( U32 baudrate );	// Start pinging and send data
	
protected:
	void SetReg( U16 reg, U32 value );
};

#endif //#ifndef __DSSPInterface2_H
