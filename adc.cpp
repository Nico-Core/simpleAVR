// Copyright 2015 Nicolas Kohr. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.


#include "adc.h"

adc ADCON;

adc::adc()
{
	ADMUX = 0;
	ADMUX |= ( 1 << REFS0 );
	
	ADCSRA = 0;
	ADCSRA |= ( 1 << ADEN ) | ( 1 << ADPS0 ) | ( 1 << ADPS1 ) | ( 1 << ADPS2 );
	
	ADCSRA |= ( 1 << ADSC );
	while( ( ADCSRA & ( 1 << ADSC ) ) );
} 


adc::~adc()
{
} 


uint8_t adc::value( uint8_t channel, uint16_t *val )
{
	ADMUX |= channel;
	
	ADCSRA |= ( 1 << ADSC );
	while( ( ADCSRA & ( 1 << ADSC ) ) );

	*val = ADC;
	
	return 1;
}
