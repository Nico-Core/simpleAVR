// Copyright 2015 Nicolas Kohr. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "uart.h"

void _uart_::Gets( char *str ) const
{
	uint8_t buffer;
	
	for( buffer = this ->Getc(); buffer != '\0' ; str++ ){
		*str = buffer;
		buffer = this ->Getc();
	}
	
	str++;
	*str = '\0';
}


void _uart_::Puts( const char *str ) const
{
	while(  *str != '\0' ){
		this ->Putc( *str );
		
		str++;
	}
	
	this ->Putc( '\0' );
}


void _uart_::Getd( uint8_t *data, size_t size ) const
{
	for( size_t i = 0; i < size; i++, data++ ){
		*data = this ->Getc();
	}
}


void _uart_::Putd( const uint8_t *data, size_t size ) const
{
	for( size_t i = 0; i < size; i++, data++ ){
		this ->Putc( *data );
	}
}


#if defined( UDR )

_uart0_ UART;

_uart0_::_uart0_( void )
{
	UBRRH = UBRRH_VALUE;
	UBRRL = UBRRL_VALUE;
		
#if USE_2X
	UCSRA |= ( 1 << U2X );
#else
	UCSRA &= ~( 1 << U2X );
#endif
		
	UCSRB |= ( 1 << RXEN ) | ( 1 << TXEN );
	UCSRC &= ~( 1 << UMSEL );
	UCSRC |= ( 1 << URSEL ) | (1 << UCSZ1) | (1 << UCSZ0);
		
		
#ifdef ISRUART
	UCSRB |= ( 1 << RXCIE );
	UCSRB |= ( 1 << UDRIE );
#endif
}


_uart0_::~_uart0_( void )
{	
}


uint8_t _uart0_::Getc( void ) const
{
	while( !( UCSRA & ( 1<< RXC ) ) );
	
	return UDR;
}


void _uart0_::Putc( uint8_t c) const
{
	while( !( UCSRA & ( 1 << UDRE ) ) );
	
	UDR = c;
}


int8_t	_uart0_::framingError( void ) const
{
	return ( UCSRA & ( 1 << FE ) );
}


int8_t	_uart0_::dataOverRun( void ) const
{
	return ( UCSRA & ( 1 << DOR ) );
}


int8_t	_uart0_::parityError( void ) const
{
	return ( UCSRA & ( 1 << UPE ) );
}

#endif


#if defined( UDR0 )

_uart0_ UART0;

_uart0_::_uart0_( void )
{
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
	
	#if USE_2X
	UCSR0A |= ( 1 << U2X0 );
	#else
	UCSR0A &= ~( 1 << U2X0 );
	#endif
	
	UCSR0B |= ( 1 << RXEN0 ) | ( 1 << TXEN0 );
	UCSR0C &= ~( 1 << UMSEL00 );
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
	
	#ifdef ISRUART
	UCSR0B |= ( 1 << RXCIE0 );
	UCSR0B |= ( 1 << UDRIE0 );
	#endif
}


_uart0_::~_uart0_( void )
{
}


uint8_t _uart0_::Getc( void ) const
{
	while( !( UCSR0A & ( 1<< RXC0 ) ) );
	
	return UDR0;
}


void _uart0_::Putc( uint8_t c) const
{
	while( !( UCSR0A & ( 1 << UDRE0 ) ) );
	
	UDR0 = c;
}


int8_t _uart0_::framingError( void ) const
{
	return ( UCSR0A & ( 1 << FE0 ) );
}


int8_t _uart0_::dataOverRun( void ) const
{
	return ( UCSR0A & ( 1 << DOR0 ) );
}


int8_t _uart0_::parityError( void ) const
{
	return ( UCSR0A & ( 1 << UPE0 ) );
}

#endif


#if defined( UDR1 )

_uart1_ UART1;

_uart1_::_uart1_( void )
{
	UBRR1H = UBRRH_VALUE;
	UBRR1L = UBRRL_VALUE;
	
	#if USE_2X
	UCSR1A |= ( 1 << U2X1 );
	#else
	UCSR1A &= ~( 1 << U2X1 );
	#endif
	
	UCSR1B |= ( 1 << RXEN1 ) | ( 1 << TXEN1 );
	UCSR1C &= ~( 1 << UMSEL10 );
	UCSR1C |= (1 << UCSZ11) | (1 << UCSZ10);
	
	#ifdef ISRUART
	UCSR1B |= ( 1 << RXCIE1 );
	UCSR1B |= ( 1 << UDRIE1 );
	#endif
}


_uart1_::~_uart1_( void )
{
}


uint8_t _uart1_::Getc( void ) const
{
	while( !( UCSR1A & ( 1<< RXC1 ) ) );
	
	return UDR1;
}


void _uart1_::Putc( uint8_t c) const
{
	while( !( UCSR1A & ( 1 << UDRE1 ) ) );
	
	UDR1 = c;
}


int8_t _uart1_::framingError( void ) const
{
	return ( UCSR1A & ( 1 << FE1 ) );
}


int8_t _uart1_::dataOverRun( void ) const
{
	return ( UCSR1A & ( 1 << DOR1 ) );
}


int8_t _uart1_::parityError( void ) const
{
	return ( UCSR1A & ( 1 << UPE1 ) );
}

#endif