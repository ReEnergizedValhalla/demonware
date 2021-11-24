// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdsequencenumber.cpp:0x9D1580
void __cdecl bdMallocMemory::eraseMemory(bdMallocMemory::bdMemoryChainElement *link)
{
  bdMallocMemory::bdMemoryChainElement *m_prev; // eax
  bdMallocMemory::bdMemoryChainElement *m_next; // eax

  bdMutex::lock(&bdMallocMemory::m_mutex);
  if ( link->m_magic != 0xBDBD )
  {
    bdMutex::unlock(&bdMallocMemory::m_mutex);
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "mallocmemory",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdMemory\\bdMallocMemory.cpp",
      "bdMallocMemory::eraseMemory",
      0xCEu,
      " BD_MEMORY_MAGIC is incorrect.");
    bdMutex::lock(&bdMallocMemory::m_mutex);
  }
  m_prev = link->m_prev;
  if ( m_prev )
    m_prev->m_next = link->m_next;
  else
    bdMallocMemory::m_memoryChain = link->m_next;
  m_next = link->m_next;
  if ( m_next )
    m_next->m_prev = link->m_prev;
  bdMallocMemory::m_allocatedBytes -= link->m_size;
  --bdMallocMemory::m_numAllocations;
  bdMutex::unlock(&bdMallocMemory::m_mutex);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsequencenumber.cpp:0x9D1620
bdMallocMemory::bdMemoryChainElement *__cdecl bdMallocMemory::allocate(const unsigned int size)
{
  bdMallocMemory::bdMemoryChainElement *v1; // eax

  v1 = (bdMallocMemory::bdMemoryChainElement *)bdAlignedOffsetMalloc(size + 20, 8u, 0x14u);
  return bdMallocMemory::recordMemory(v1, size, 0);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsequencenumber.cpp:0x9D1650
bdMallocMemory::bdMemoryChainElement *__cdecl bdMallocMemory::reallocate(void *p, const unsigned int size)
{
  unsigned int v2; // edi
  bdMallocMemory::bdMemoryChainElement *v3; // eax

  if ( !p )
    return bdMallocMemory::allocate(size);
  v2 = *((_DWORD *)p - 4) + 20;
  bdMallocMemory::eraseMemory((bdMallocMemory::bdMemoryChainElement *)p - 1);
  v3 = (bdMallocMemory::bdMemoryChainElement *)bdAlignedOffsetRealloc((char *)p - 20, v2, size + 20, 8u, 0x14u);
  return bdMallocMemory::recordMemory(v3, size, 0);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsequencenumber.cpp:0x9D16A0
bdMallocMemory::bdMemoryChainElement *__cdecl bdMallocMemory::alignedAllocate(
        const unsigned int size,
        const unsigned int align)
{
  bdMallocMemory::bdMemoryChainElement *v2; // eax

  v2 = (bdMallocMemory::bdMemoryChainElement *)bdAlignedOffsetMalloc(size + 20, align, 0x14u);
  return bdMallocMemory::recordMemory(v2, size, 1);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsequencenumber.cpp:0x9D16D0
void __cdecl bdMallocMemory::deallocate(void *p)
{
  if ( p )
  {
    bdMallocMemory::eraseMemory((bdMallocMemory::bdMemoryChainElement *)p - 1);
    bdAlignedOffsetFree((char *)p - 20);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsequencenumber.cpp:0x9D16F0
bdMallocMemory::bdMemoryChainElement *__cdecl bdMallocMemory::alignedReallocate(
        void *p,
        const unsigned int size,
        const unsigned int align)
{
  unsigned int v3; // edi
  bdMallocMemory::bdMemoryChainElement *v4; // eax

  if ( !p )
    return bdMallocMemory::alignedAllocate(size, align);
  v3 = *((_DWORD *)p - 4) + 20;
  bdMallocMemory::eraseMemory((bdMallocMemory::bdMemoryChainElement *)p - 1);
  v4 = (bdMallocMemory::bdMemoryChainElement *)bdAlignedOffsetRealloc((char *)p - 20, v3, size + 20, align, 0x14u);
  return bdMallocMemory::recordMemory(v4, size, 1);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsequencenumber.cpp:0x9D1750
unsigned int __cdecl bdBitOperations::nextPowerOf2(const unsigned int v)
{
  unsigned int result; // eax

  result = ~((((((((((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 4) | ((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 8) | ((((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 4) | ((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 16) | ((((((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 4) | ((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 8) | ((((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 4) | ((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 1) & (((((((((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 4) | ((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 8) | ((((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 4) | ((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 16) | ((((((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 4) | ((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 8) | ((((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 4) | ((v | (v >> 1)) >> 2) | v | (v >> 1));
  if ( result != v )
    result *= 2;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsequencenumber.cpp:0x9D1790
int __cdecl bdBitOperations::highBitNumber(unsigned int v)
{
  int v1; // ecx
  unsigned int v2; // eax

  v1 = (v & 0xFFFF0000) != 0 ? 0x10 : 0;
  v2 = v >> v1;
  if ( ((v >> v1) & 0xFF00) != 0 )
  {
    v1 |= 8u;
    v2 >>= 8;
  }
  if ( (v2 & 0xF0) != 0 )
  {
    v1 |= 4u;
    v2 >>= 4;
  }
  if ( (v2 & 0xC) != 0 )
  {
    v1 |= 2u;
    v2 >>= 2;
  }
  return v1 | (v2 >> 1);
}

#endif // __UNIMPLEMENTED__
