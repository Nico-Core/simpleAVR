// Copyright 2015 Nicolas Kohr. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.


#include "eeprom.h"


_eeprom EEPROM;


uint8_t _eeprom::read( uint8_t *addr ) const
{
	return eeprom_read_byte( addr );
}
	
uint16_t _eeprom::read( uint16_t *addr ) const
{
	return eeprom_read_word( addr );
}
	
uint32_t _eeprom::read( uint32_t *addr ) const
{
	return eeprom_read_dword( addr );
}
	
float _eeprom::read( float *addr ) const
{
	return eeprom_read_float( addr );
}
	
void _eeprom::read( void *dst, const void *src, size_t n ) const
{
	eeprom_read_block( dst, src, n );
}
	
void _eeprom::write( uint8_t *addr, uint8_t val ) const
{
	eeprom_update_byte( addr, val );
}
	
void _eeprom::write( uint16_t *addr, uint16_t val ) const
{
	eeprom_update_word( addr, val );
}
	
void _eeprom::write( uint32_t *addr, uint32_t val ) const
{
	eeprom_update_dword( addr, val );
}
	
void _eeprom::write( float *addr,  float val ) const
{
	eeprom_update_float( addr, val );
}
	
void _eeprom::write( const void *src, void *dst, size_t n ) const
{
	eeprom_update_block( src, dst, n );
}
