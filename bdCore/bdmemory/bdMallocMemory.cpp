#include "bdMallocMemory.h"

bdMallocMemory::bdMemoryChainElement* bdMallocMemory::recordMemory(bdMallocMemory::bdMemoryChainElement* link, unsigned int size, bool aligned)
{
	if (!link)
	{
		return 0;
	}
	m_mutex.lock();
	link->m_magic = 0xBDBD;
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
}

bdMallocMemory::bdMemoryChainElement* bdMallocMemory::allocate(unsigned int size)
{
	return nullptr;
}

bdMallocMemory::bdMemoryChainElement* bdMallocMemory::reallocate(void* p, unsigned int size)
{
	return nullptr;
}

bdMallocMemory::bdMemoryChainElement* bdMallocMemory::alignedAllocate(unsigned int size, unsigned int align)
{
	return nullptr;
}

void bdMallocMemory::deallocate(void* p)
{
}

bdMallocMemory::bdMemoryChainElement* bdMallocMemory::alignedReallocate(void* p, unsigned int size, unsigned int align)
{
	return nullptr;
}
