// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdheartbeatackchunk.cpp:0x9CF060
__int32 __thiscall bdEndpointHashingClass::getHash(bdEndpointHashingClass *this, const bdEndpoint *other)
{
  return bdEndpoint::getHash((bdEndpoint *)other);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdheartbeatackchunk.cpp:0x9CF0E0
void __thiscall bdByteBuffer::readArrayEnd(bdByteBuffer *this)
{
  this->m_typeChecked = this->m_typeCheckedCopy;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdheartbeatackchunk.cpp:0x9CF0F0
bool __thiscall bdByteBuffer::read(bdByteBuffer *this, void *data, unsigned int size)
{
  unsigned __int8 *v4; // eax
  unsigned __int8 *m_readPtr; // ecx
  unsigned int v6; // edi
  unsigned int v7; // eax
  bool result; // al

  v4 = &this->m_data[this->m_size];
  m_readPtr = this->m_readPtr;
  v6 = size;
  v7 = v4 - m_readPtr;
  if ( size > v7 )
  {
    bdLogMessage(
      BD_LOG_WARNING,
      "warn/",
      "core/bytebuffer",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdContainers\\bdByteBuffer.cpp",
      "bdByteBuffer::read",
      0x170u,
      "Could not read data from buffer. Insufficient data available.\n");
    return 0;
  }
  else
  {
    result = bdBytePacker::removeBuffer(m_readPtr, v7, 0, &size, data, size);
    this->m_readPtr += v6;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
