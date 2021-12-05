// Copyright 2015 Nicolas Kohr. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "ringBuffer.h"


ringBuffer::ringBuffer( int16_t bufsize ) : bufferSize( bufsize ), writePos( 0 ), readPos( 0 )
{
	pbuffer = ( uint8_t * ) calloc( bufsize, sizeof( uint8_t ) );
}


ringBuffer::~ringBuffer()
{
	free( pbuffer );
} 


uint8_t	ringBuffer::read( uint8_t *data )
{
	*data = pbuffer[readPos];
	
	if( readPos == bufferSize ){
			readPos = 0;
		
			return bufferSize;
	}else{
			return readPos++;
	}
}


int16_t ringBuffer::write( uint8_t *data )
{
	pbuffer[writePos] = *data;
	
	if( writePos == bufferSize ){
			writePos = 0;
			
			return bufferSize;
	}else{
			return writePos++;
	}
}

	
int8_t ringBuffer::read( uint8_t *data, int16_t pos ) const
{
	if( pos > bufferSize || pos < 0 )
			return -1;
		
	*data = pbuffer[pos];
		
	return 0;
}


int8_t ringBuffer::write( uint8_t *data, int16_t pos )
{
	if( pos > bufferSize || pos < 0 )
			return -1;
	
	pbuffer[pos] = *data;
	
	return 0;
}


int16_t ringBuffer::getWritePos( void ) const
{
	return writePos;
}


int16_t	ringBuffer::getReadPos( void ) const
{
	return readPos;
}
