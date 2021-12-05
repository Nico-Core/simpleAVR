// Copyright 2015 Nicolas Kohr. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.


#ifndef __RINGBUFFER_H__
#define __RINGBUFFER_H__


#include <stdint.h>
#include <stdlib.h>


#define BUFFERSIZE_MAX INT16_MAX


class ringBuffer
{

public:
				ringBuffer( int16_t bufSize );
				~ringBuffer();
				
	uint8_t	    read( uint8_t *data );
	int16_t		write( uint8_t *data );
	
	int8_t		read( uint8_t *data, int16_t pos ) const;
	int8_t		write( uint8_t *data, int16_t pos );

	int16_t		getWritePos( void ) const;
	int16_t		getReadPos( void ) const;
	
private:
				ringBuffer( const ringBuffer &c );
				ringBuffer& operator=( const ringBuffer &c );
	
	
private:
	uint8_t		*pbuffer;
	int16_t		bufferSize;
	int16_t		writePos;
	int16_t		readPos;

};

#endif //__RINGBUFFER_H__
