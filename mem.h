// Copyright 2015 Nicolas Kohr. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef __MEM_H__
#define __MEM_H__

#include <stdlib.h>

__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" int __cxa_guard_acquire(__guard *);
extern "C" void __cxa_guard_release (__guard *);
extern "C" void __cxa_guard_abort (__guard *);

void * operator new(size_t size);
void operator	delete(void * ptr);

void * operator	new[](size_t size);
void operator	delete[](void * ptr);


#endif /* __MEM_H__ */