// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdstreamsocket.cpp:0x9D0B70
void __thiscall bdBitBuffer::bdBitBuffer(
        bdBitBuffer *this,
        const unsigned __int8 *bits,
        const unsigned int numBits,
        const bool dataHasTypeCheckedBit)
{
  int v5; // eax
  bdFastArray<unsigned char> *p_m_data; // ecx
  unsigned __int8 byte; // [esp+17h] [ebp-Dh] BYREF
  int v8; // [esp+20h] [ebp-4h]

  v5 = 0;
  this->__vftable = (bdBitBuffer_vtbl *)&bdReferencable::`vftable';
  this->m_refCount = 0;
  p_m_data = &this->m_data;
  this->__vftable = (bdBitBuffer_vtbl *)&bdBitBuffer::`vftable';
  v8 = 0;
  p_m_data->m_data = 0;
  p_m_data->m_capacity = 0;
  p_m_data->m_size = 0;
  LOBYTE(v8) = 1;
  this->m_writePosition = 0;
  this->m_maxWritePosition = 0;
  this->m_readPosition = 0;
  this->m_failedRead = 0;
  this->m_typeChecked = 0;
  if ( dataHasTypeCheckedBit && numBits )
  {
    LOBYTE(v5) = (numBits & 7) != 0;
    bdFastArray<unsigned char>::pushBack(p_m_data, bits, (numBits >> 3) + v5);
    this->m_writePosition = numBits;
    this->m_maxWritePosition = numBits;
    bdBitBuffer::readBits(this, &this->m_typeChecked, 1u);
  }
  else
  {
    byte = 0;
    bdBitBuffer::writeBits(this, &byte, 1u);
    bdBitBuffer::writeBits(this, bits, numBits);
    this->m_readPosition = 1;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdstreamsocket.cpp:0x9D0C40
void __thiscall bdBitBuffer::writeRangedUInt32(
        bdBitBuffer *this,
        const unsigned int u,
        const unsigned int begin,
        const unsigned int end,
        unsigned int typeChecked)
{
  unsigned int v6; // eax
  unsigned int v7; // ecx

  if ( (_BYTE)typeChecked )
  {
    bdBitBuffer::writeDataType(this, BD_BB_RANGED_UNSIGNED_INTEGER32_TYPE);
    if ( this->m_typeChecked )
    {
      bdBitBuffer::writeDataType(this, BD_BB_UNSIGNED_INTEGER32_TYPE);
      typeChecked = begin;
      bdBitBuffer::writeBits(this, &typeChecked, 0x20u);
      bdBitBuffer::writeDataType(this, BD_BB_UNSIGNED_INTEGER32_TYPE);
      typeChecked = end;
      bdBitBuffer::writeBits(this, &typeChecked, 0x20u);
    }
  }
  v6 = 0;
  if ( end != begin )
    v6 = bdBitOperations::highBitNumber(end - begin) + 1;
  v7 = u;
  if ( u <= end )
  {
    if ( u < begin )
      v7 = begin;
  }
  else
  {
    v7 = end;
  }
  typeChecked = v7 - begin;
  bdBitBuffer::writeBits(this, &typeChecked, v6);
}

#endif // __UNIMPLEMENTED__
