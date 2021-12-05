// Copyright 2015 Nicolas Kohr. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "hc.h"


hc::hc()
{
	hcWidth = 0;
}


hc::~hc()
{
} 


void hc::init()
{
	DDRD |= ( 1 << DDD2 ); // Trigger
	DDRD &= ~( 1 << DDD3 ); //Echo
		
	TCCR0A = 0;
	TIMSK0 |= ( 1 << TOIE0 );
		
	TCNT0 = 56; // Timer initialisiert
		
	sei();
}


float hc::lenght( void )
{
	PORTD |= ( 1 << PORTD2 );
	_delay_ms( 20 );
	PORTD &= ~( 1 << PORTD2 );
	_delay_us( 11 );
	PORTD |= ( 1 << PORTD2 );
	

	while( !(PIND & ( 1 << PIND3 )));
	TCCR0B |= ( 1 << CS00 ); // start Timer , kein prescaler
	

	while( (PIND & ( 1 << PIND3 )) && ( count < 8000 ) );
	TCCR0B &= ~( 1 << CS00 ); // stopp Timer
	
	if( count >= 8000 ){ // 200ms rum
		}else{
		hcWidth = SCHALL * ( 25.0 * count / 2);
	}
	
	
	TCNT0 = 56;
	count = 0;
	
	return 0;
}