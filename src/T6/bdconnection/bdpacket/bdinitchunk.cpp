// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdinitchunk.cpp:0x9CDDD0
void __thiscall bdArray<bdAddr>::bdArray<bdAddr>(bdArray<bdAddr> *this, const bdArray<bdAddr> *a)
{
  bdAddr *v3; // ebx

  this->m_capacity = a->m_capacity;
  this->m_size = a->m_size;
  if ( a->m_capacity )
  {
    v3 = (bdAddr *)bdMemory::allocate(8 * a->m_capacity);
    bdArray<bdAddr>::copyConstructArrayArray(this, v3, a->m_data, a->m_size);
    this->m_data = v3;
  }
  else
  {
    this->m_data = 0;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitchunk.cpp:0x9CDE30
void __thiscall bdArray<bdAddr>::increaseCapacity(bdArray<bdAddr> *this, const unsigned int increase)
{
  unsigned int m_capacity; // eax
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  bdAddr *m_data; // edi
  unsigned int m_size; // ebx
  unsigned int newCapacity; // [esp+Ch] [ebp-4h]
  bdAddr *newData; // [esp+18h] [ebp+8h]

  m_capacity = this->m_capacity;
  v4 = increase;
  if ( increase <= m_capacity )
    v4 = m_capacity;
  v5 = m_capacity + v4;
  newCapacity = m_capacity + v4;
  newData = 0;
  if ( m_capacity + v4 )
  {
    newData = (bdAddr *)bdMemory::allocate(8 * v5);
    bdArray<bdAddr>::copyConstructArrayArray(this, newData, this->m_data, this->m_size);
  }
  m_data = this->m_data;
  if ( this->m_size )
  {
    m_size = this->m_size;
    do
    {
      bdInetAddr::~bdInetAddr(&m_data->m_address);
      ++m_data;
      --m_size;
    }
    while ( m_size );
    v5 = newCapacity;
  }
  bdMemory::deallocate(this->m_data);
  this->m_capacity = v5;
  this->m_data = newData;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitchunk.cpp:0x9CDEB0
void __thiscall bdArray<bdAddr>::~bdArray<bdAddr>(bdArray<bdAddr> *this)
{
  bdAddr *m_data; // esi
  unsigned int m_size; // ebx

  m_data = this->m_data;
  if ( this->m_size )
  {
    m_size = this->m_size;
    do
    {
      bdInetAddr::~bdInetAddr(&m_data->m_address);
      ++m_data;
      --m_size;
    }
    while ( m_size );
  }
  bdMemory::deallocate(this->m_data);
  this->m_data = 0;
  this->m_size = 0;
  this->m_capacity = 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitchunk.cpp:0x9CDEF0
void __thiscall bdArray<bdAddr>::pushBack(bdArray<bdAddr> *this, const bdAddr *value)
{
  bdAddr *v3; // ecx

  if ( this->m_size == this->m_capacity )
    bdArray<bdAddr>::increaseCapacity(this, 1u);
  v3 = &this->m_data[this->m_size];
  if ( v3 )
    bdAddr::bdAddr(v3, value);
  ++this->m_size;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitchunk.cpp:0x9CDF60
void __thiscall bdCommonAddr::bdCommonAddr(bdCommonAddr *this)
{
  this->__vftable = (bdCommonAddr_vtbl *)&bdReferencable::`vftable';
  this->m_refCount = 0;
  this->__vftable = (bdCommonAddr_vtbl *)&bdCommonAddr::`vftable';
  this->m_localAddrs.m_data = 0;
  this->m_localAddrs.m_capacity = 0;
  this->m_localAddrs.m_size = 0;
  bdAddr::bdAddr(&this->m_publicAddr);
  this->m_natType = BD_NAT_OPEN;
  this->m_hash = 0;
  this->m_isLoopback = 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitchunk.cpp:0x9CDFE0
void __thiscall bdCommonAddr::~bdCommonAddr(bdCommonAddr *this)
{
  bdAddr *m_data; // edi
  unsigned int m_size; // ebx

  this->__vftable = (bdCommonAddr_vtbl *)&bdCommonAddr::`vftable';
  bdInetAddr::~bdInetAddr(&this->m_publicAddr.m_address);
  m_data = this->m_localAddrs.m_data;
  if ( this->m_localAddrs.m_size )
  {
    m_size = this->m_localAddrs.m_size;
    do
    {
      bdInetAddr::~bdInetAddr(&m_data->m_address);
      ++m_data;
      --m_size;
    }
    while ( m_size );
  }
  bdMemory::deallocate(this->m_localAddrs.m_data);
  this->m_localAddrs.m_data = 0;
  this->m_localAddrs.m_size = 0;
  this->m_localAddrs.m_capacity = 0;
  bdReferencable::~bdReferencable(this);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdinitchunk.cpp:0x9CE080
void __thiscall bdCommonAddr::bdCommonAddr(
        bdCommonAddr *this,
        const bdArray<bdAddr> *localAddrs,
        const bdAddr *publicAddr,
        const bdNATType natType)
{
  bdAddr *v6; // eax
  bdAddr *localAddrsa; // [esp+28h] [ebp+8h]

  this->__vftable = (bdCommonAddr_vtbl *)&bdReferencable::`vftable';
  this->m_refCount = 0;
  this->__vftable = (bdCommonAddr_vtbl *)&bdCommonAddr::`vftable';
  this->m_localAddrs.m_capacity = localAddrs->m_capacity;
  this->m_localAddrs.m_size = localAddrs->m_size;
  v6 = 0;
  if ( localAddrs->m_capacity )
  {
    localAddrsa = (bdAddr *)bdMemory::allocate(8 * localAddrs->m_capacity);
    bdArray<bdAddr>::copyConstructArrayArray(&this->m_localAddrs, localAddrsa, localAddrs->m_data, localAddrs->m_size);
    v6 = localAddrsa;
  }
  this->m_localAddrs.m_data = v6;
  bdAddr::bdAddr(&this->m_publicAddr, publicAddr);
  this->m_natType = natType;
  this->m_isLoopback = 1;
  bdCommonAddr::calculateHash(this);
}

#endif // __UNIMPLEMENTED__
