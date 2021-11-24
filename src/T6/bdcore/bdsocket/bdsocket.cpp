// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdsocket.cpp:0x9D07D0
bool __thiscall bdBitBuffer::readRangedUInt32(
        bdBitBuffer *this,
        unsigned int *u,
        const unsigned int begin,
        const unsigned int end,
        unsigned int typeChecked)
{
  unsigned int v5; // ebx
  bool result; // al
  unsigned int v8; // eax
  unsigned int v9; // ecx

  v5 = end;
  if ( (_BYTE)typeChecked )
  {
    result = bdBitBuffer::readDataType(this, BD_BB_RANGED_UNSIGNED_INTEGER32_TYPE);
    if ( this->m_typeChecked )
    {
      if ( !result
        || !bdBitBuffer::readDataType(this, BD_BB_UNSIGNED_INTEGER32_TYPE)
        || !bdBitBuffer::readBits(this, &typeChecked, 0x20u)
        || !bdBitBuffer::readDataType(this, BD_BB_UNSIGNED_INTEGER32_TYPE)
        || !bdBitBuffer::readBits(this, (void *)&end, 0x20u) )
      {
        return 0;
      }
      if ( begin != typeChecked || v5 != end )
        bdLogMessage(
          BD_LOG_ERROR,
          "err/",
          "bdCore/bitBuffer",
          "c:\\t6\\code\\DemonWare\\bdCore\\bdContainers\\bdBitBuffer.cpp",
          "bdBitBuffer::readRangedUInt32",
          0x11Du,
          "Range error. Expected: (%u,%u), read: (%u,%u)",
          begin,
          v5,
          typeChecked,
          end);
    }
    else if ( !result )
    {
      return result;
    }
  }
  v8 = 0;
  if ( v5 != begin )
    v8 = bdBitOperations::highBitNumber(v5 - begin) + 1;
  typeChecked = 0;
  if ( !bdBitBuffer::readBits(this, &typeChecked, v8) )
    return 0;
  v9 = begin + typeChecked;
  result = 1;
  *u = begin + typeChecked;
  if ( v9 <= v5 )
  {
    if ( v9 < begin )
      v9 = begin;
    *u = v9;
  }
  else
  {
    *u = v5;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocket.cpp:0x9D08E0
void __thiscall bdFastArray<unsigned char>::pushBack(
        bdFastArray<unsigned char> *this,
        const unsigned __int8 *value,
        const unsigned int n)
{
  unsigned int m_size; // eax
  unsigned int m_capacity; // ecx
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // edi
  unsigned __int8 *v10; // ebx

  m_size = this->m_size;
  m_capacity = this->m_capacity;
  v6 = n;
  v7 = n + m_size;
  if ( m_capacity < v7 )
  {
    v8 = v7 - m_capacity;
    if ( v8 <= m_capacity )
      v8 = m_capacity;
    v9 = m_capacity + v8;
    v10 = 0;
    if ( m_capacity + v8 )
    {
      v10 = (unsigned __int8 *)bdMemory::allocate(m_capacity + v8);
      if ( this->m_size )
        memcpy(v10, this->m_data, this->m_size);
    }
    bdMemory::deallocate(this->m_data);
    this->m_data = v10;
    this->m_capacity = v9;
    v6 = n;
  }
  if ( v6 )
    memcpy(&this->m_data[this->m_size], (unsigned __int8 *)value, v6);
  this->m_size += v6;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocket.cpp:0x9D0960
bdBitBuffer *__thiscall bdBitBuffer::`scalar deleting destructor'(bdBitBuffer *this, unsigned int a2)
{
  bdBitBuffer::~bdBitBuffer(this);
  if ( (a2 & 1) != 0 )
    bdMemory::deallocate(this);
  return this;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocket.cpp:0x9D0990
void __thiscall bdBitBuffer::writeBits(bdBitBuffer *this, const void *bits, const unsigned int numBits)
{
  unsigned int v3; // eax
  unsigned int v5; // edi
  unsigned __int8 *m_data; // edx
  unsigned int v7; // ebx
  unsigned int v8; // eax
  char v9; // cl
  char v10; // dl
  unsigned int v11; // edi
  char v12; // cl
  char v13; // bl
  unsigned int m_writePosition; // eax
  unsigned __int8 *v15; // [esp+Ch] [ebp-20h]
  unsigned int v16; // [esp+1Ch] [ebp-10h]
  unsigned int bitsToWrite; // [esp+20h] [ebp-Ch]
  unsigned int bitsWritten; // [esp+24h] [ebp-8h]

  v3 = numBits;
  v5 = (numBits + this->m_writePosition - 1) >> 3;
  if ( v5 >= this->m_data.m_size )
  {
    bdFastArray<unsigned char>::ensureCapacity(&this->m_data, v5 + 1);
    m_data = this->m_data.m_data;
    this->m_data.m_size = v5 + 1;
    v3 = numBits;
    m_data[v5] = 0;
  }
  v7 = v3;
  bitsToWrite = v3;
  if ( v3 )
  {
    v16 = (v3 - 1) >> 3;
    do
    {
      v8 = this->m_writePosition & 7;
      if ( v7 >= 8 - v8 )
      {
        v9 = 8 - v8;
        bitsWritten = 8 - v8;
      }
      else
      {
        v9 = v7;
        bitsWritten = v7;
      }
      v10 = (255 >> (8 - v8)) | (-1 << (v8 + v9));
      v11 = (numBits - v7) >> 3;
      v12 = (numBits - v7) & 7;
      if ( v16 <= v11 )
        v13 = 0;
      else
        v13 = *((_BYTE *)bits + v11 + 1);
      v15 = &this->m_data.m_data[this->m_writePosition >> 3];
      *v15 = v10 & *v15 | ~v10 & (((unsigned __int8)(v13 << (8 - v12)) | (unsigned __int8)(*((_BYTE *)bits + v11) >> v12)) << v8);
      this->m_writePosition += bitsWritten;
      m_writePosition = this->m_writePosition;
      v7 = bitsToWrite - bitsWritten;
      bitsToWrite -= bitsWritten;
      if ( this->m_maxWritePosition > m_writePosition )
        m_writePosition = this->m_maxWritePosition;
      this->m_maxWritePosition = m_writePosition;
    }
    while ( v7 );
  }
}

#endif // __UNIMPLEMENTED__
