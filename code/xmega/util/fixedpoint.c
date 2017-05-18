/////////////////////////////////////////////////////////////////////////////////
// Fixed point library for the xmega.
//
// Author:				Maximilian Stiefel
// Last Modification:	17.05.2017
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "../modules/log.h"
#include "fixedpoint.h"

LOG_INIT("FIXEDPOINT");

/////////////////////////////////////////////////////////////////////////////////
// Print fixed point number
/////////////////////////////////////////////////////////////////////////////////
void fixedPt_printInt(myfixedpoint32_t input) 
{
	LOG_DEBUG("integerRep: %d", input);
}

/////////////////////////////////////////////////////////////////////////////////
// Print fixed point number in bitwise representation
/////////////////////////////////////////////////////////////////////////////////
char *fixedPt_pritntBit(myfixedpoint32_t input, uint8_t print) 
{
	char buffer[33];
	char debugOut[33];
	buffer[32] = '\0';
	debugOut[32] = '\0';
	int j =0;
	
	for(int i=0; i<32; i++) {								// Detect 1s and 0 s
		if((1<<i) & input)
			buffer[i] = '1';
		else
			buffer[i] = '0';
	}
	
	j = 0;
	
	for(int i=31; i>=0; i--) {								// Flip so LSB is right
		debugOut[j] = buffer[i];
		j++;
	}
	if(print)
		LOG_DEBUG("bitwiseRep: %s", debugOut);
}

/////////////////////////////////////////////////////////////////////////////////
// Multiplication
/////////////////////////////////////////////////////////////////////////////////
static inline myfixedpoint32_t fixedPt_mul(myfixedpoint32_t x, myfixedpoint32_t y) 
{
	myfixedpoint32_t xr, xl, yr, yl;
	// Split both operands in a left and right part (xl.xr and yl.yr)
	xl = (x >> NO_OF_DECIMALS);
	xr = (x & ((1 << NO_OF_DECIMALS)-1));
	yl = (y >> NO_OF_DECIMALS);
	yr = (y & ((1<<NO_OF_DECIMALS)-1));
	// Do the actual multiplication
	// acc. to this equation x*(y>>NO_OF_DECIMALS) = ( ( (xl<<NO_OF_DECIMALS)+xr ) * ( (yl<<NO_OF_DECIMALS)+yr ) );
	return ( xl*yl*(1<<NO_OF_DECIMALS) + xl*yr + xr*yl + ( (xr*yr) >> NO_OF_DECIMALS) );
}

/////////////////////////////////////////////////////////////////////////////////
// Division
/////////////////////////////////////////////////////////////////////////////////
static inline myfixedpoint32_t fixedPt_div(myfixedpoint32_t x, myfixedpoint32_t y) 
{
	myfixedpoint32_t out = 0;
	assert(x!=0);
	assert(y!=0);
	out = (x<<NO_OF_DECIMALS)/y;
	if((x<0) != (y<0)) {
		out -= (y-1)/y;
	}
	return out;
}