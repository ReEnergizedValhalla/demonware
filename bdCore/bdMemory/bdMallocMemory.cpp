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

#include "bdMallocMemory.h"

#include "bdAlignedOffsetMemory.h"
#include "bdPlatform/bdPlatformLog/bdPlatformLog.h"

#define BD_MEMORY_MAGIC 0xBDBD

bdMallocMemory::bdMemoryChainElement* bdMallocMemory::recordMemory(bdMallocMemory::bdMemoryChainElement* link, unsigned int size, bool aligned)
{
	if (!link)
	{
		return 0;
	}
	m_mutex.lock();
	link->m_magic = BD_MEMORY_MAGIC;
	link->m_size = size;
	link->m_aligned = aligned;
	link->m_next = m_memoryChain;
	link->m_prev = 0;
	if (m_memoryChain)
	{
		m_memoryChain->m_prev = link;
	}
	m_allocatedBytes += size;
	++m_numAllocations;
	m_memoryChain = link;
	m_mutex.unlock();
	return link + 1;
}

void bdMallocMemory::eraseMemory(bdMemoryChainElement* link)
{
	m_mutex.lock();
	if (link->m_magic != BD_MEMORY_MAGIC)
	{
		m_mutex.unlock();
		bdLogMessage(BD_LOG_ERROR, "err/", "mallocmemory", __FILE__, __FUNCTION__, __LINE__, " BD_MEMORY_MAGIC is incorrect.");
		m_mutex.lock();
	}

	if (link->m_prev)
	{
		link->m_prev->m_next = link->m_next;
	}
	else
	{
		m_memoryChain = link->m_next;
	}

	if (link->m_next)
	{
		link->m_next->m_prev = link->m_prev;
	}
	m_allocatedBytes -= link->m_size;
	--m_numAllocations;
	m_mutex.unlock();
}

bdMallocMemory::bdMemoryChainElement* bdMallocMemory::allocate(unsigned int size)
{
	bdMemoryChainElement* alloc;

	alloc = (bdMemoryChainElement*)bdAlignedOffsetMalloc(size + sizeof(bdMemoryChainElement), 8, sizeof(bdMemoryChainElement));
	return recordMemory(alloc, size, 0);
}

bdMallocMemory::bdMemoryChainElement* bdMallocMemory::reallocate(void* p, unsigned int size)
{
	void* realloc;
	unsigned int origSize;

	if (p)
	{
		origSize = *((unsigned int*)p - 4) + sizeof(bdMemoryChainElement);
		eraseMemory((bdMemoryChainElement*)p - 1);
		realloc = bdAlignedOffsetRealloc((char*)p - sizeof(bdMemoryChainElement), origSize, size + sizeof(bdMemoryChainElement), 8, sizeof(bdMemoryChainElement));
		return recordMemory((bdMemoryChainElement*)realloc, size, 0);
	}
	return allocate(size);
}

bdMallocMemory::bdMemoryChainElement* bdMallocMemory::alignedAllocate(unsigned int size, unsigned int align)
{
	bdMemoryChainElement* alloc;

	alloc = (bdMemoryChainElement*)bdAlignedOffsetMalloc(size + sizeof(bdMemoryChainElement), align, sizeof(bdMemoryChainElement));
	return recordMemory(alloc, size, 1);
}

void bdMallocMemory::deallocate(void* p)
{
	if (p)
	{
		eraseMemory((bdMemoryChainElement*)p - 1);
		bdAlignedOffsetFree((char*)p - sizeof(bdMemoryChainElement));
	}
}

bdMallocMemory::bdMemoryChainElement* bdMallocMemory::alignedReallocate(void* p, unsigned int size, unsigned int align)
{
	unsigned int origSize;
	void* realloc;

	if (p)
	{
		origSize = *((unsigned int*)p - 4) + 20;
		eraseMemory((bdMemoryChainElement*)p - 1);
		realloc = bdAlignedOffsetRealloc((char*)p - sizeof(bdMemoryChainElement), origSize, size + sizeof(bdMemoryChainElement), align, sizeof(bdMemoryChainElement));
		return recordMemory((bdMemoryChainElement*)realloc, size, 1);
	}
	return alignedAllocate(size, align);
}
