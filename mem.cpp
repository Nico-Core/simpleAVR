// Copyright 2015 Nicolas Kohr. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.


#include "mem.h"

int		__cxa_guard_acquire(__guard *g) {return !*(char *)(g);};
void	__cxa_guard_release (__guard *g) {*(char *)g = 1;};
void	__cxa_guard_abort (__guard *) {};
	
void	__cxa_pure_virtual(void) {};

	
void * operator new(size_t size)
{
	return malloc(size);
}

void operator delete(void * ptr)
{
	free(ptr);
}

void * operator new[](size_t size)
{
	return malloc(size);
}

void operator delete[](void * ptr)
{
	free(ptr);
}