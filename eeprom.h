// Copyright 2015 Nicolas Kohr. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef __EEPROM_H__
#define __EEPROM_H__

#include <stdint.h>

#include <avr/eeprom.h>

class _eeprom
{
	
public:
	uint8_t		read( uint8_t *addr ) const;
	uint16_t	read( uint16_t *addr ) const;
	uint32_t	read( uint32_t *addr ) const;
	float		read( float *addr ) const;
	void		read( void *dst, const void *src, size_t n ) const;
	
	void		write( uint8_t *addr, uint8_t val ) const;
	void		write( uint16_t *addr, uint16_t val ) const;
	void		write( uint32_t *addr, uint32_t val ) const;
	void		write( float *addr,  float val ) const;
	void		write( const void *src, void *dst, size_t n ) const;
	
};

extern _eeprom EEPROM;

#endif //__EEPROM_H__
