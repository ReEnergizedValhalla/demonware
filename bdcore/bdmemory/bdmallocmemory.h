#pragma once

#include <bdCore/bdThread/bdMutex.h>

class bdMallocMemory
{
public:
	struct bdMemoryChainElement
	{
		unsigned __int16 m_magic;
		unsigned int m_size;
		bool m_aligned;
		bdMemoryChainElement* m_prev;
		bdMemoryChainElement* m_next;
	};

protected:
	bdMutex m_mutex;
	bdMemoryChainElement* m_memoryChain;
	unsigned int m_allocatedBytes;
	unsigned int m_numAllocations;
public:
	bdMemoryChainElement* recordMemory(bdMemoryChainElement* link, unsigned int size, bool aligned);
	void eraseMemory(bdMemoryChainElement* link);
	bdMemoryChainElement* allocate(unsigned int size);
	bdMemoryChainElement* reallocate(void* p, unsigned int size);
	bdMemoryChainElement* alignedAllocate(unsigned int size, unsigned int align);
	void deallocate(void* p);
	bdMemoryChainElement* alignedReallocate(void* p, unsigned int size, unsigned int align);
};