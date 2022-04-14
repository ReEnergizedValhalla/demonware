/*
* DemonWare
* Copyright (c) 2020-2022 OpenIW
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, version 3.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#include "bdCore/bdThread/bdMutex.h"
#include "bdPlatform/bdPlatform.h"

static bdMutex g_MemoryThreadLock;

inline void* bdMemcpy(void *const dest, const void *const src, const bdUWord len)
{
    memcpy(dest,src,len);
    return dest;
}

template<typename T>
inline T* bdAllocate(const bdUWord n)
{
    return reinterpret_cast<T*>(bdMemory::allocate(n));
}

template<typename T>
inline T* bdDeallocate(T* p)
{
    bdMemory::deallocate(reinterpret_cast<void*>(p));
}

class bdMemory
{
public:
    static void setAllocateFunc(void* (*allocator)(const unsigned int));
    static void setDeallocateFunc(void  (*deallocator)(void*));
    static void setReallocateFunc(void* (*reallocator)(void*, const unsigned int));
    static void setAlignedAllocateFunc(void* (*allocator)(const unsigned int, const unsigned int));
    static void setAlignedDeallocateFunc(void  (*deallocator)(void*));
    static void setAlignedReallocateFunc(void* (*reallocator)(void*, const unsigned int, const unsigned int));
    static void* (*getAllocateFunc())(const unsigned int);
    static void (*getDeallocateFunc())(void*);
    static void* (*getReallocateFunc())(void*, const unsigned int);
    static void* (*getAlignedAllocateFunc())(const unsigned int, const unsigned int);
    static void (*getAlignedDeallocateFunc())(void*);
    static void* (*getAlignedReallocateFunc())(void*, const unsigned int, const unsigned int);
    static void* allocate(const unsigned int size);
    static void deallocate(void* p);
    static void* reallocate(void* p, const unsigned int size);
    //static  void* alignedAllocate(const unsigned int, const unsigned int); Not used
    //static void alignedDeallocate(void*); Not used
    //static void* alignedReallocate(void*, const unsigned int, const unsigned int); Not used
protected:
    static void* (*m_allocateFunc)(const unsigned int);
	static void (*m_deallocateFunc)(void*);
	static void* (*m_reallocateFunc)(void*, const unsigned int);
	static void* (*m_alignedAllocateFunc)(const unsigned int, const unsigned int);
	static void (*m_alignedDeallocateFunc)(void*);
	static void* (*m_alignedReallocateFunc)(void*, const unsigned int, const unsigned int);
private:
    bdMemory();
};