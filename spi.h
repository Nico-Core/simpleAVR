// Copyright 2015 Nicolas Kohr. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef __SPI_H__
#define __SPI_H__


#include <stdint.h>
#include <stdlib.h>

#include <avr/io.h>

//SCK Frequency
#define SCKMODE0 SPCR &= ~( 1 << SPR0 ) | ( 1 << SPR1 );		// f/4
#define SCKMODE1 SPCR &= ~( 1 << SPR1 ); SPCR |= ( 1 << SPR0 ); // f/16
#define SCKMODE2 SPCR &= ~( 1 << SPR0 ); SPCR |= ( 1 << SPR1 ); // f/64
#define SCKMODE3 SPCR |= ( 1 << SPR0 ) | ( 1 << SPR1 );			// f/128

// SPI Mode
#define SPIMODE0 SPCR &= ~( ( 1 << CPOL ) | ( 1 << CPHA ) );	// Leading (Rising) Edge
#define SPIMODE1 SPCR &= ~( 1 << CPOL ); SPCR |= ( 1 << CPHA ); // Trailing (Falling) Edge
#define SPIMODE2 SPCR &= ~( 1 << CPHA ); SPCR |= ( 1 << CPOL ); // Leading (Falling) Edge
#define SPIMODE3 SPCR |= ( 1 << CPOL ) | ( 1 << CPHA );			// Trailing (Rising) Edge

//The SPI Clock Rate Select reduces by half
#define SPI2XENABLED SPSR |= ( 1 << SPI2X );
#define SPI2XDISABLED SPSR &= ~( 1 << SPI2X );

#define SS_ON PORTB |= ( 1 << PORTB2 );
#define SS_OFF PORTB &= ~( 1 << PORTB2 );

#define MSBENABLED SPCR &= ~( 1 << DORD );
#define LSBENABLED SPCR |= ( 1 << DORD );


class spi
{

public:
				spi( void ) {;}
				~spi( void ) {;}
	
	void		initMaster( void ) const;
	void		initSlave( void ) const;
	
	uint8_t		Getc( void ) const;
	void		Putc( uint8_t c) const;
	
	void		Gets( char *str ) const;
	void		Puts( const char *str ) const;
	
	void		Getd( uint8_t *data, size_t size ) const;
	void		Putd( const uint8_t *data, size_t size ) const;

};

extern spi SPI;

#endif //__SPI_H__
