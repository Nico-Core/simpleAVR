// Copyright 2015 Nicolas Kohr. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef __ADC_H__
#define __ADC_H__

#include <avr/io.h>

#include <stdint.h>

//-------Kanal-------
#define CHAN0 0
#define CHAN1 1
#define CHAN2 2
#define CHAN3 3
#define CHAN4 4
#define CHAN5 5
//-------------------


class adc
{

public:
				adc();
				~adc();
	
	uint8_t		value( uint8_t channel, uint16_t *val );

private:
				adc( const adc &c );
				adc& operator=( const adc &c );
}; //adc

extern adc ADCON;

#endif //__ADC_H__

/*
Mit Interruptbetrieb

class ADC
{
public:
	ADC(const std::string& device);
	~ADC();
	Poco::UInt16 read() const;
private:
	ADC();
	ADC(const ADC&);
	ADC& operator = (const ADC&);
	int _fd;
};
*/