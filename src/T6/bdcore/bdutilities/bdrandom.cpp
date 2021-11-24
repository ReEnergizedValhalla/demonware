// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdrandom.cpp:0x9D0AB0
void __thiscall bdBitBuffer::bdBitBuffer(bdBitBuffer *this, const unsigned int capacityBits, const bool typeChecked)
{
  unsigned int v4; // eax
  char bits; // [esp+12h] [ebp-Eh] BYREF
  unsigned __int8 byte; // [esp+13h] [ebp-Dh] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  this->__vftable = (bdBitBuffer_vtbl *)&bdReferencable::`vftable';
  this->m_refCount = 0;
  this->__vftable = (bdBitBuffer_vtbl *)&bdBitBuffer::`vftable';
  v7 = 0;
  this->m_data.m_data = 0;
  this->m_data.m_size = 0;
  v4 = ((capacityBits & 7) != 0) + (capacityBits >> 3);
  this->m_data.m_capacity = v4;
  if ( v4 )
    this->m_data.m_data = (unsigned __int8 *)bdMemory::allocate(v4);
  LOBYTE(v7) = 1;
  this->m_writePosition = 0;
  this->m_maxWritePosition = 0;
  this->m_readPosition = 0;
  this->m_failedRead = 0;
  this->m_typeChecked = typeChecked;
  if ( typeChecked )
  {
    byte = -1;
    bdBitBuffer::writeBits(this, &byte, 1u);
  }
  else
  {
    bits = 0;
    bdBitBuffer::writeBits(this, &bits, 1u);
  }
  this->m_readPosition = 1;
}

#endif // __UNIMPLEMENTED__
