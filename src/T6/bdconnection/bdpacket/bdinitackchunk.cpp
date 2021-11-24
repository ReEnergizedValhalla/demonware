// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdinitackchunk.cpp:0x9CE140
void __thiscall bdCommonAddr::bdCommonAddr(bdCommonAddr *this, const bdAddr *publicAddr)
{
  bdInetAddr *v3; // eax
  bdAddr *v4; // ecx

  this->__vftable = (bdCommonAddr_vtbl *)&bdReferencable::`vftable';
  this->m_refCount = 0;
  this->__vftable = (bdCommonAddr_vtbl *)&bdCommonAddr::`vftable';
  this->m_localAddrs.m_data = 0;
  this->m_localAddrs.m_capacity = 0;
  this->m_localAddrs.m_size = 0;
  bdAddr::bdAddr(&this->m_publicAddr, publicAddr);
  this->m_natType = BD_NAT_OPEN;
  this->m_isLoopback = 0;
  XAnimClientNotifyList::GetNotifyList((bdTrulyRandomImpl *)publicAddr);
  bdInetAddr::isValid(v3);
  if ( this->m_localAddrs.m_size == this->m_localAddrs.m_capacity )
    bdArray<bdAddr>::increaseCapacity(&this->m_localAddrs, 1u);
  v4 = &this->m_localAddrs.m_data[this->m_localAddrs.m_size];
  if ( v4 )
    bdAddr::bdAddr(v4, publicAddr);
  ++this->m_localAddrs.m_size;
  bdCommonAddr::calculateHash(this);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitackchunk.cpp:0x9CE210
char __thiscall bdCommonAddr::deserialize(
        bdCommonAddr *this,
        bdReference<bdCommonAddr> me,
        const unsigned __int8 *buffer)
{
  unsigned int m_size; // eax
  bdAddr *m_data; // edi
  bdArray<bdAddr> *p_m_localAddrs; // esi
  unsigned int v6; // ebx
  const unsigned __int8 *v7; // edi
  int v8; // ebx
  bdInetAddr *v9; // eax
  bdAddr *v10; // ecx
  bdCommonAddr *v11; // esi
  char v12; // bl
  bdAddr localAddr; // [esp+10h] [ebp-24h] BYREF
  bdAddr *v15; // [esp+18h] [ebp-1Ch]
  bdCommonAddr *other; // [esp+1Ch] [ebp-18h]
  unsigned int offset; // [esp+20h] [ebp-14h] BYREF
  bool status; // [esp+27h] [ebp-Dh]
  int v19; // [esp+30h] [ebp-4h]

  other = this;
  m_size = this->m_localAddrs.m_size;
  m_data = this->m_localAddrs.m_data;
  p_m_localAddrs = &this->m_localAddrs;
  v19 = 0;
  offset = 0;
  status = 1;
  if ( m_size )
  {
    v6 = m_size;
    do
    {
      bdInetAddr::~bdInetAddr(&m_data->m_address);
      ++m_data;
      --v6;
    }
    while ( v6 );
  }
  bdMemory::deallocate(p_m_localAddrs->m_data);
  v7 = buffer;
  p_m_localAddrs->m_data = 0;
  p_m_localAddrs->m_size = 0;
  p_m_localAddrs->m_capacity = 0;
  v8 = 5;
  do
  {
    bdAddr::bdAddr(&localAddr);
    LOBYTE(v19) = 1;
    if ( status && bdAddr::deserialize(&localAddr, v7, 0x25u, offset, &offset) )
    {
      status = 1;
      XAnimClientNotifyList::GetNotifyList((bdTrulyRandomImpl *)&localAddr);
      if ( bdInetAddr::isValid(v9) )
      {
        if ( p_m_localAddrs->m_size == p_m_localAddrs->m_capacity )
          bdArray<bdAddr>::increaseCapacity(p_m_localAddrs, 1u);
        v10 = &p_m_localAddrs->m_data[p_m_localAddrs->m_size];
        HIBYTE(buffer) = HIBYTE(v10);
        v15 = v10;
        LOBYTE(v19) = 2;
        if ( v10 )
          bdAddr::bdAddr(v10, &localAddr);
        ++p_m_localAddrs->m_size;
      }
    }
    else
    {
      status = 0;
    }
    LOBYTE(v19) = 0;
    bdInetAddr::~bdInetAddr(&localAddr.m_address);
    --v8;
  }
  while ( v8 );
  if ( status
    && (v11 = other, bdAddr::deserialize(&other->m_publicAddr, v7, 0x25u, offset, &offset))
    && bdBytePacker::removeBuffer(v7, 0x25u, offset, &offset, (char *)&buffer + 3, 1u) )
  {
    v12 = 1;
    v11->m_natType = SHIBYTE(buffer);
    bdCommonAddr::calculateHash(v11);
    v11->m_isLoopback = me.m_ptr && bdCommonAddr::operator==(me.m_ptr, v11);
  }
  else
  {
    v12 = 0;
  }
  v19 = -1;
  if ( me.m_ptr && !InterlockedDecrement(&me.m_ptr->m_refCount) )
    ((void (__thiscall *)(bdCommonAddr *, int))me.m_ptr->~bdReferencable)(me.m_ptr, 1);
  return v12;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitackchunk.cpp:0x9CE3C0
bdCommonAddr *__thiscall bdCommonAddr::`scalar deleting destructor'(bdCommonAddr *this, unsigned int a2)
{
  bdCommonAddr::~bdCommonAddr(this);
  if ( (a2 & 1) != 0 )
    bdMemory::deallocate(this);
  return this;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitackchunk.cpp:0x9CE3F0
void __cdecl bdMemory::setAllocateFunc(void *(__cdecl *const allocator)(const unsigned int))
{
  bdMemory::m_allocateFunc = allocator;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitackchunk.cpp:0x9CE400
void __cdecl bdMemory::setDeallocateFunc(void (__cdecl *const deallocator)(void *))
{
  bdMemory::m_deallocateFunc = deallocator;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitackchunk.cpp:0x9CE410
void __cdecl bdMemory::setReallocateFunc(void *(__cdecl *const reallocator)(void *, const unsigned int))
{
  bdMemory::m_reallocateFunc = reallocator;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitackchunk.cpp:0x9CE420
void __cdecl bdMemory::setAlignedAllocateFunc(void *(__cdecl *const allocator)(const unsigned int, const unsigned int))
{
  bdMemory::m_alignedAllocateFunc = allocator;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitackchunk.cpp:0x9CE430
void __cdecl bdMemory::setAlignedDeallocateFunc(void (__cdecl *const deallocator)(void *))
{
  bdMemory::m_alignedDeallocateFunc = deallocator;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitackchunk.cpp:0x9CE440
void __cdecl bdMemory::setAlignedReallocateFunc(
        void *(__cdecl *const reallocator)(void *, const unsigned int, const unsigned int))
{
  bdMemory::m_alignedReallocateFunc = reallocator;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitackchunk.cpp:0x9CE450
void *(__cdecl *__cdecl bdMemory::getAllocateFunc())(const unsigned int)
{
  return bdMemory::m_allocateFunc;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitackchunk.cpp:0x9CE460
void (__cdecl *__cdecl bdMemory::getDeallocateFunc())(void *)
{
  return bdMemory::m_deallocateFunc;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitackchunk.cpp:0x9CE470
void *(__cdecl *__cdecl bdMemory::getReallocateFunc())(void *, const unsigned int)
{
  return bdMemory::m_reallocateFunc;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitackchunk.cpp:0x9CE480
void *__cdecl bdMemory::allocate(const unsigned int size)
{
  void *result; // eax
  void *Func; // esi

  result = 0;
  if ( bdMemory::m_allocateFunc )
  {
    bdMutex::lock(&g_MemoryThreadLock);
    Func = bdMemory::m_allocateFunc(size);
    bdMutex::unlock(&g_MemoryThreadLock);
    if ( !Func )
      DebugBreak();
    return Func;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitackchunk.cpp:0x9CE4C0
void __cdecl bdMemory::deallocate(void *p)
{
  if ( bdMemory::m_deallocateFunc )
  {
    bdMutex::lock(&g_MemoryThreadLock);
    bdMemory::m_deallocateFunc(p);
    bdMutex::unlock(&g_MemoryThreadLock);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitackchunk.cpp:0x9CE4F0
void *__cdecl bdMemory::reallocate(void *p, const unsigned int size)
{
  void *result; // eax
  void *v3; // esi

  result = 0;
  if ( bdMemory::m_reallocateFunc )
  {
    bdMutex::lock(&g_MemoryThreadLock);
    v3 = bdMemory::m_reallocateFunc(p, size);
    bdMutex::unlock(&g_MemoryThreadLock);
    if ( !v3 )
      DebugBreak();
    return v3;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
