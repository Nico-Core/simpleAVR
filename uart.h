// Copyright 2015 Nicolas Kohr. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef __UART_H__
#define __UART_H__

//------UART Speed-------
#ifndef F_CPU
	#undef  F_CPU
	#define F_CPU 16000000UL
#endif

#ifndef BAUD
	#undef BAUD
	#define BAUD 9600
#endif

//----------------------

#include <stdint.h>
#include <stdlib.h>

#include <avr/io.h>
#include <util/setbaud.h>
#include <avr/interrupt.h>

#include "mem.h"

/*
__________________________
Interruptbetrieb fehlt 
__________________________
*/

class _uart_
{
public:
				_uart_( void ){;}
	virtual		~_uart_( void ){;}		
					
virtual	uint8_t	Getc( void ) const = 0;
virtual	void	Putc( uint8_t c) const = 0;
				
	void		Gets( char *str ) const;
	void		Puts( const char *str ) const;
	
	void		Getd( uint8_t *data, size_t size ) const;
	void		Putd( const uint8_t *data, size_t size ) const;
};


#if defined( UDR ) || defined( UDR0 )

class _uart0_ : public _uart_
{
	
public:
				_uart0_( void );
				~_uart0_( void );
	
	uint8_t		Getc( void ) const;
	void		Putc( uint8_t c) const;
	
	int8_t		framingError( void ) const;
	int8_t		dataOverRun( void ) const;
	int8_t		parityError( void ) const;

private:
				_uart0_( const _uart0_& );
				_uart0_ & operator = ( const _uart0_& );
};

#ifdef UDR0
	extern _uart0_ UART0;
#elif UDR
	extern _uart0_ UART;
#endif

#endif


#ifdef UDR1

class _uart1_ : public _uart_
{
	
public:
				_uart1_( void );
				~_uart1_( void );
	
	uint8_t		Getc( void ) const;
	void		Putc( uint8_t c) const;
	
	int8_t		framingError( void ) const;
	int8_t		dataOverRun( void ) const;
	int8_t		parityError( void ) const;

private:
	_uart1_( const _uart1_& );
	_uart1_ & operator = ( const _uart1_& );
};

extern _uart1_ UART1;

#endif


#ifdef UDR2

class _uart2_ : public _uart_
{
	
public:
				_uart2_( void );
				~_uart2_( void );
	
	uint8_t		Getc( void ) const;
	void		Putc( uint8_t c) const;
	
	int8_t		framingError( void ) const;
	int8_t		dataOverRun( void ) const;
	int8_t		parityError( void ) const;

private:
	_uart2_( const _uart2_& );
	_uart2_ & operator = ( const _uart2_& );
};

extern _uart2_ UART2;

#endif


#ifdef UDR3

class _uart3_ : public _uart_
{
	
public:
				_uart3_( void );
				~_uart3_( void );
	
	uint8_t		Getc( void ) const;
	void		Putc( uint8_t c) const;
	
	int8_t		framingError( void ) const;
	int8_t		dataOverRun( void ) const;
	int8_t		parityError( void ) const;

private:
	_uart3_( const _uart3_& );
	_uart3_ & operator = ( const _uart3_& );
};

extern _uart3_ UART3;

#endif


#endif //__UART_H__
