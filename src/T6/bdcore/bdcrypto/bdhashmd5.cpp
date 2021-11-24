// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdhashmd5.cpp:0x9D04F0
char __thiscall bdBitBuffer::readBits(bdBitBuffer *this, void *bits, unsigned int numBits)
{
  unsigned int v3; // esi
  bdBitBuffer *v4; // edi
  unsigned int m_readPosition; // eax
  unsigned int v7; // eax
  unsigned __int8 v8; // dl
  int v9; // ebx
  unsigned int v10; // eax
  unsigned __int8 v11; // al
  char v12; // cl
  bool v13; // zf
  unsigned int nextByteIndex; // [esp+Ch] [ebp-8h]

  v3 = numBits;
  v4 = this;
  if ( !numBits )
    return 1;
  m_readPosition = this->m_readPosition;
  if ( m_readPosition + numBits <= this->m_maxWritePosition )
  {
    v7 = m_readPosition >> 3;
    while ( v7 < v4->m_data.m_size )
    {
      if ( v3 >= 8 )
        v3 = 8;
      v8 = v4->m_data.m_data[v7];
      v9 = v4->m_readPosition & 7;
      v10 = v7 + 1;
      nextByteIndex = v10;
      if ( v9 + v3 <= 8 )
      {
        v12 = (v8 >> v9) & (255 >> (8 - v3));
      }
      else
      {
        if ( v10 >= v4->m_data.m_size )
          break;
        v11 = v4->m_data.m_data[v10];
        v4 = this;
        v12 = (255 >> (8 - v3)) & ((v8 >> v9) | (v11 << (8 - v9)));
      }
      *(_BYTE *)bits = v12;
      v4->m_readPosition += v3;
      v13 = numBits == v3;
      numBits -= v3;
      bits = (char *)bits + 1;
      if ( v13 )
        return 1;
      v7 = nextByteIndex;
      v3 = numBits;
    }
    v4->m_failedRead = 1;
    return 0;
  }
  else
  {
    this->m_failedRead = 1;
    return 0;
  }
}

#endif // __UNIMPLEMENTED__
