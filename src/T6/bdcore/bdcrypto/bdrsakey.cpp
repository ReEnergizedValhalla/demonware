// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdrsakey.cpp:0x9D05E0
bool __thiscall bdBitBuffer::readDataType(bdBitBuffer *this, const bdBitBufferDataType expectedDataType)
{
  bool result; // al
  signed int v3; // esi
  bool v4; // bl
  unsigned int dataType32; // [esp+0h] [ebp-58h] BYREF
  char string1[40]; // [esp+4h] [ebp-54h] BYREF
  char string2[40]; // [esp+2Ch] [ebp-2Ch] BYREF

  result = 1;
  if ( this->m_typeChecked )
  {
    dataType32 = 0;
    result = bdBitBuffer::readRangedUInt32(this, &dataType32, 0, 0x1Fu, 0);
    if ( result )
    {
      v3 = dataType32;
      v4 = dataType32 == expectedDataType;
      if ( dataType32 != expectedDataType )
      {
        bdBitBuffer::typeToString(expectedDataType, string1, 0x28u);
        bdBitBuffer::typeToString((const bdBitBufferDataType)v3, string2, 0x28u);
        bdLogMessage(
          BD_LOG_ERROR,
          "err/",
          "bdCore/bitBuffer",
          "c:\\t6\\code\\DemonWare\\bdCore\\bdContainers\\bdBitBuffer.cpp",
          "bdBitBuffer::readDataType",
          0x20Bu,
          "Expected: %s , read: %s ",
          string1,
          string2);
      }
      return v4;
    }
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdrsakey.cpp:0x9D0680
void __thiscall bdFastArray<unsigned char>::ensureCapacity(
        bdFastArray<unsigned char> *this,
        const unsigned int capacity)
{
  unsigned int m_capacity; // eax
  unsigned int v4; // ecx
  unsigned int v5; // edi
  unsigned __int8 *v6; // ebx

  m_capacity = this->m_capacity;
  if ( m_capacity < capacity )
  {
    v4 = capacity - m_capacity;
    if ( capacity - m_capacity <= m_capacity )
      v4 = m_capacity;
    v5 = m_capacity + v4;
    v6 = 0;
    if ( m_capacity + v4 )
    {
      v6 = (unsigned __int8 *)bdMemory::allocate(m_capacity + v4);
      if ( this->m_size )
        memcpy(v6, this->m_data, this->m_size);
    }
    bdMemory::deallocate(this->m_data);
    this->m_capacity = v5;
    this->m_data = v6;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdrsakey.cpp:0x9D06E0
bool __thiscall bdBitBuffer::readInt32(bdBitBuffer *this, int *i)
{
  bool result; // al
  int ni; // [esp+4h] [ebp-4h] BYREF

  if ( !bdBitBuffer::readDataType(this, BD_BB_SIGNED_INTEGER32_TYPE) || !bdBitBuffer::readBits(this, &ni, 0x20u) )
    return 0;
  result = 1;
  *i = ni;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdrsakey.cpp:0x9D0720
bool __thiscall bdBitBuffer::readUInt32(bdBitBuffer *this, unsigned int *u)
{
  bool result; // al
  unsigned int nu; // [esp+4h] [ebp-4h] BYREF

  if ( !bdBitBuffer::readDataType(this, BD_BB_UNSIGNED_INTEGER32_TYPE) || !bdBitBuffer::readBits(this, &nu, 0x20u) )
    return 0;
  result = 1;
  *u = nu;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdrsakey.cpp:0x9D0760
void __thiscall bdBitBuffer::~bdBitBuffer(bdBitBuffer *this)
{
  this->__vftable = (bdBitBuffer_vtbl *)&bdBitBuffer::`vftable';
  bdMemory::deallocate(this->m_data.m_data);
  this->m_data.m_data = 0;
  this->m_data.m_size = 0;
  this->m_data.m_capacity = 0;
  bdReferencable::~bdReferencable(this);
}

#endif // __UNIMPLEMENTED__
