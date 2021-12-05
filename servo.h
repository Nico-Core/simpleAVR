// Copyright 2015 Nicolas Kohr. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef ___SERVO__H__
#define ___SERVO__H__

#include <avr/io.h>
#include <util/atomic.h>
#include <avr/interrupt.h>

#include <stdint.h>

#include "uart.h"

#define TIMER0A 0
#define TIMER0B 1
#define TIMER2A 2
#define TIMER2B 3

#ifndef _PRESCALE_
	#define _PRESCALE_
	
	#define PRE0_0 ( 1 << CS00 )
	#define PRE0_8 ( 1 << CS01 )
	#define PRE0_64 ( ( 1 << CS00 ) | ( 1 << CS01 ) )
	#define PRE0_256 ( 1 << CS02 )
	#define PRE0_1024 ( ( 1 << CS00 ) | ( 1 << CS02 ) )
	
	#define PRE2_0 ( 1 << CS20 )
	#define PRE2_8 ( 1 << CS21 )
	#define PRE2_32 ( ( 1 << CS20 ) | ( 1 << CS21 ) )
	#define PRE2_64 ( 1 << CS22 )
	#define PRE2_128 ( ( 1 << CS20 ) | ( 1 << CS22 ) )
	#define PRE2_256 ( ( 1 << CS21 ) | ( 1 << CS22 ) )
	#define PRE2_1024 ( ( 1 << CS20 ) | ( 1 << CS21 ) | ( 1 << CS22 ) )
#endif


class servo
{
public:
					servo( uint8_t _timer_, uint8_t _pre_, uint16_t _20m_Count_, uint8_t _irq_count_ );
					~servo();
	
		void		speed( uint16_t sp );
volatile void		timer_isr( void );	

private:
volatile uint16_t	_20mCount;
volatile uint16_t	spCount;
volatile uint8_t	*port, pin;


					servo( const servo &c );
					servo& operator=( const servo &c );

}; 

#endif //___SERVO__H__
