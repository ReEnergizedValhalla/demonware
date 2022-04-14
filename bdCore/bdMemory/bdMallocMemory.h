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