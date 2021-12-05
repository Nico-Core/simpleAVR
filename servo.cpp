// Copyright 2015 Nicolas Kohr. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "servo.h"


servo::servo( uint8_t _timer_, uint8_t _pre_, uint16_t _20m_Count_, uint8_t _irq_count_ )
{
	switch ( _timer_ )
	{
		case TIMER0A:
			*port = DDRD;
			pin = PORTD6;
				
			TCCR0B |= ( 1 << _pre_ ) | ( 1 << WGM01 );
			TIMSK0 |= ( 1 << OCIE0A );
			OCR0A = _irq_count_;
			break;
			
		case TIMER0B:
			*port = DDRD;
			pin = PORTD5;
				
			TCCR0B |= ( 1 << _pre_ ) | ( 1 << WGM01 );
			TIMSK0 |= ( 1 << OCIE0B );
			OCR0B = _irq_count_;
			break;
		
		case TIMER2A:
			*port = DDRB;
			pin = PORTB3;
				
			TCCR2B |= ( 1 << _pre_ ) | ( 1 << WGM21 );
			TIMSK0 |= ( 1 << OCIE2A );
			OCR2A = _irq_count_;
			break;
		
		case TIMER2B:
			*port = DDRD;
			pin = PORTD3;
				
			TCCR2B |= ( 1 << _pre_ ) | ( 1 << WGM21 );
			TIMSK0 |= ( 1 << OCIE2B );
			OCR2B = _irq_count_;
			break;
	}
	
	*port |= ( 1 << pin );
		
	_20mCount = _20m_Count_;
		
	spCount = 0;
} 


servo::~servo()
{
}


void servo::speed( uint16_t sp )
{
	ATOMIC_BLOCK(ATOMIC_FORCEON){
		spCount = sp;
	}
}


volatile void servo::timer_isr( void )
{
	static uint16_t counter = 0;
	
	if( counter < spCount )
		*port |= ( 1 << pin );
	else
		*port &= ~( 1 << pin );
		
	if( counter < _20mCount )
		counter++;
	else
		counter = 0;	
		
	UART.puts( "ISR" );
}