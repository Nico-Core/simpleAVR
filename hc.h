// Copyright 2015 Nicolas Kohr. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef __HC_H__
#define __HC_H__

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <stdint.h>

#define SCHALL 0.3432

volatile uint16_t count = 0;

ISR(TIMER0_OVF_vect){
	TCNT0 = 56;
	count++;
}


class hc
{

public:
	hc();
	~hc();
	
	void init( );
	float lenght( void );

private:
	double hcWidth;

	hc( const hc &c );
	hc& operator=( const hc &c );

};

#endif //__HC_H__
