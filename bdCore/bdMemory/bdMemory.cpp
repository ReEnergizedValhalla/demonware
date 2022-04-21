// SPDX-License-Identifier: GPL-3.0-or-later
#include "bdCore/bdCore.h"

void* (*bdMemory::m_allocateFunc)(const unsigned int) = NULL;
void (*bdMemory::m_deallocateFunc)(void*) = NULL;
void* (*bdMemory::m_reallocateFunc)(void*, const unsigned int) = NULL;
void* (*bdMemory::m_alignedAllocateFunc)(const unsigned int, const unsigned int) = NULL;
void (*bdMemory::m_alignedDeallocateFunc)(void*) = NULL;
void* (*bdMemory::m_alignedReallocateFunc)(void*, const unsigned int, const unsigned int) = NULL;

void bdMemory::setAllocateFunc(void* (*allocator)(const unsigned int))
{
	m_allocateFunc = allocator;
}

void bdMemory::setDeallocateFunc(void (*deallocator)(void*))
{
	m_deallocateFunc = deallocator;
}

void bdMemory::setReallocateFunc(void* (*reallocator)(void*, const unsigned int))
{
	m_reallocateFunc = reallocator;
}

void bdMemory::setAlignedAllocateFunc(void* (*allocator)(const unsigned int, const unsigned int))
{
	m_alignedAllocateFunc = allocator;
}

void bdMemory::setAlignedDeallocateFunc(void (*deallocator)(void*))
{
	m_alignedDeallocateFunc = deallocator;
}

void bdMemory::setAlignedReallocateFunc(void* (*reallocator)(void*, const unsigned int, const unsigned int))
{
	m_alignedReallocateFunc = reallocator;
}

void* (*bdMemory::getAllocateFunc())(const unsigned int)
{
	return m_allocateFunc;
}

void (*bdMemory::getDeallocateFunc())(void*)
{
	return m_deallocateFunc;
}

void* (*bdMemory::getReallocateFunc())(void*, const unsigned int)
{
	return m_reallocateFunc;
}

void* (*bdMemory::getAlignedAllocateFunc())(const unsigned int, const unsigned int)
{
	return m_alignedAllocateFunc;
}

void (*bdMemory::getAlignedDeallocateFunc())(void*)
{
	return m_alignedDeallocateFunc;
}

void* (*bdMemory::getAlignedReallocateFunc())(void*, const unsigned int, const unsigned int)
{
	return m_alignedReallocateFunc;
}

void* bdMemory::allocate(const unsigned int size)
{
	void* alloc;

	if (m_allocateFunc)
	{
		g_MemoryThreadLock.lock();
		alloc = m_allocateFunc(size);
		g_MemoryThreadLock.unlock();
		if (!alloc)
		{
			DebugBreak();
		}
		return alloc;
	}
	return 0;
}

void bdMemory::deallocate(void* p)
{
	if (m_deallocateFunc)
	{
		g_MemoryThreadLock.lock();
		m_deallocateFunc(p);
		g_MemoryThreadLock.unlock();
	}
}

void* bdMemory::reallocate(void* p, const unsigned int size)
{
	void* realloc;

	if (m_reallocateFunc)
	{
		g_MemoryThreadLock.lock();
		realloc = m_reallocateFunc(p, size);
		g_MemoryThreadLock.unlock();
		if (!realloc)
		{
			DebugBreak();
		}
		return realloc;
	}
	return 0;
}