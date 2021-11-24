// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdshutdownackchunk.cpp:0x9CF220
void __thiscall bdByteBuffer::~bdByteBuffer(bdByteBuffer *this)
{
  unsigned __int8 *m_data; // eax

  this->__vftable = (bdByteBuffer_vtbl *)&bdByteBuffer::`vftable';
  m_data = this->m_data;
  if ( m_data && this->m_allocatedData )
    bdMemory::deallocate(m_data);
  this->m_data = 0;
  this->m_readPtr = 0;
  this->m_writePtr = 0;
  bdReferencable::~bdReferencable(this);
}

#endif // __UNIMPLEMENTED__
