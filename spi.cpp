// Copyright 2015 Nicolas Kohr. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "spi.h"

spi SPI;

void spi::initMaster( void ) const
{
	SPCR |= ( 1 << SPE ) | ( 1 << MSTR ) | ( 1 << SPR0 );
	
	DDRB |= ( 1 << DDB2 ) | ( 1 << DDB3 ) | ( 1 << DDB5 );
	DDRB &= ( 1 << DDB4 );
}


void spi::initSlave( void ) const
{
	SPCR |= ( 1 << SPE );
	
	DDRB |= ( 1 << DDB3 );
}


uint8_t	spi::Getc( void ) const
{
	while( !( SPSR & ( 1 << SPIF ) ) );
	
	return SPDR;
}


void spi::Putc( uint8_t c) const
{
	SPDR = c;
	
	while( !( SPSR & ( 1 << SPIF ) ) );
}


void spi::Gets( char *str ) const
{
	uint8_t buffer;
	
	for( buffer = this ->Getc(); buffer != '\0' ; str++ ){
		*str = buffer;
		buffer = this ->Getc();
	}
	
	str++;
	*str = '\0';
}


void spi::Puts( const char *str ) const
{
	while(  *str != '\0' ){
		this ->Putc( *str );
		
		str++;
	}
	
	this ->Putc( '\0' );
}


void spi::Getd( uint8_t *data, size_t size ) const
{
	for( size_t i = 0; i < size; i++, data++ ){
		*data = this ->Getc();
	}
}


void spi::Putd( const uint8_t *data, size_t size ) const
{
	for( size_t i = 0; i < size; i++, data++ ){
		this ->Putc( *data );
	}
}