// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdmessage.cpp:0x9CD6B0
unsigned int __thiscall bdAddr::toString(bdAddr *this, char *const str, const unsigned int size)
{
  unsigned int v4; // eax
  unsigned int v5; // edi

  v4 = bdInetAddr::toString(&this->m_address, str, size);
  if ( v4 <= size )
    v5 = size - v4;
  else
    v5 = 0;
  return v4 + bdSnprintf(&str[v4], v5, ":%u", this->m_port);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdmessage.cpp:0x9CD700
char __thiscall bdAddr::serialize(
        bdAddr *this,
        void *data,
        const unsigned int size,
        const unsigned int offset,
        unsigned int *newOffset)
{
  unsigned int v5; // ebx
  unsigned int *v6; // esi
  unsigned int v9; // [esp-10h] [ebp-1Ch]
  unsigned int v10; // [esp-8h] [ebp-14h]
  unsigned int *v11; // [esp-4h] [ebp-10h]

  v5 = offset;
  v6 = newOffset;
  v11 = newOffset;
  v10 = offset;
  *newOffset = offset;
  if ( bdInetAddr::serialize(&this->m_address, data, size, v10, v11) )
  {
    v9 = *v6;
    offset = this->m_port;
    if ( bdBytePacker::appendBuffer(data, size, v9, v6, &offset, 2u) )
      return 1;
  }
  *v6 = v5;
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdmessage.cpp:0x9CD760
char __thiscall bdAddr::deserialize(
        bdAddr *this,
        const void *data,
        const unsigned int size,
        const unsigned int offset,
        unsigned int *newOffset)
{
  unsigned int v5; // ebx
  unsigned int *v6; // esi
  unsigned int v7; // edi
  const void *v9; // [esp-10h] [ebp-20h]
  unsigned int v10; // [esp-Ch] [ebp-1Ch]
  unsigned int v11; // [esp-8h] [ebp-18h]
  unsigned int *v12; // [esp-4h] [ebp-14h]

  v5 = size;
  v6 = newOffset;
  v7 = offset;
  v12 = newOffset;
  v11 = offset;
  v10 = size;
  v9 = data;
  *newOffset = offset;
  if ( bdInetAddr::deserialize(&this->m_address, v9, v10, v11, v12)
    && bdBytePacker::removeBuffer(data, v5, *v6, v6, &data, 2u) )
  {
    this->m_port = (unsigned __int16)data;
    return 1;
  }
  else
  {
    *v6 = v7;
    return 0;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdmessage.cpp:0x9CD7D0
void __thiscall bdAddr::bdAddr(bdAddr *this, const char *socketAddress)
{
  bdInetAddr::bdInetAddr(&this->m_address);
  bdAddr::set(this, socketAddress);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdmessage.cpp:0x9CD830
bdReferencable *__thiscall bdReferencable::`scalar deleting destructor'(bdReferencable *this, unsigned int a2)
{
  bdReferencable::~bdReferencable(this);
  if ( (a2 & 1) != 0 )
    bdMemory::deallocate(this);
  return this;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdmessage.cpp:0x9CD860
bool __thiscall bdCommonAddr::isLoopback(bdCommonAddr *this)
{
  return this->m_isLoopback;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdmessage.cpp:0x9CD870
bdNATType __thiscall bdConnectionStore::getStatus(bdCommonAddr *this)
{
  return this->m_natType;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdmessage.cpp:0x9CD880
bdAddr *__thiscall bdCommonAddr::getPublicAddr(bdNATTraversalPacket *this)
{
  return &this->m_addrSrc;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdmessage.cpp:0x9CD890
bdArray<bdAddr> *__thiscall bdCommonAddr::getLocalAddrs(bdCommonAddr *this)
{
  return &this->m_localAddrs;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdmessage.cpp:0x9CD8A0
bool __cdecl bdBytePacker::removeBasicType<unsigned int>(
        const void *buffer,
        const unsigned int bufferSize,
        const unsigned int offset,
        unsigned int *newOffset,
        unsigned int *var)
{
  bool result; // al
  unsigned int nvar; // [esp+0h] [ebp-4h] BYREF

  result = bdBytePacker::removeBuffer(buffer, bufferSize, offset, newOffset, &nvar, 4u);
  if ( result )
    *var = nvar;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdmessage.cpp:0x9CD8E0
void __thiscall bdArray<bdAddr>::copyConstructArrayArray(
        bdArray<bdAddr> *this,
        bdAddr *dest,
        const bdAddr *src,
        const unsigned int n)
{
  unsigned int v4; // edi
  bdAddr *v5; // esi

  v4 = n;
  if ( n )
  {
    v5 = dest;
    do
    {
      if ( v5 )
        bdAddr::bdAddr(v5, (bdAddr *)((char *)v5 + (char *)src - (char *)dest));
      ++v5;
      --v4;
    }
    while ( v4 );
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdmessage.cpp:0x9CD960
bool __cdecl bdBytePacker::appendBasicType<char>(
        void *buffer,
        const unsigned int bufferSize,
        const unsigned int offset,
        unsigned int *newOffset,
        const char *var)
{
  HIBYTE(var) = *var;
  return bdBytePacker::appendBuffer(buffer, bufferSize, offset, newOffset, (char *)&var + 3, 1u);
}

#endif // __UNIMPLEMENTED__
