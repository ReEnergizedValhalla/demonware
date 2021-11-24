// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdshutdownchunk.cpp:0x9CF180
bool __thiscall bdByteBuffer::readDataType(bdByteBuffer *this, const bdBitBufferDataType expectedDataType)
{
  bool result; // al
  bdBitBufferDataType v3; // esi
  bool v4; // bl
  unsigned __int8 dataType8; // [esp+3h] [ebp-55h] BYREF
  char string1[40]; // [esp+4h] [ebp-54h] BYREF
  char string2[40]; // [esp+2Ch] [ebp-2Ch] BYREF

  result = 1;
  if ( this->m_typeChecked )
  {
    dataType8 = 0;
    result = bdByteBuffer::read(this, &dataType8, 1u);
    if ( result )
    {
      v3 = dataType8;
      v4 = dataType8 == expectedDataType;
      if ( dataType8 != expectedDataType )
      {
        bdBitBuffer::typeToString(expectedDataType, string1, 0x28u);
        bdBitBuffer::typeToString(v3, string2, 0x28u);
        bdLogMessage(
          BD_LOG_ERROR,
          "err/",
          "core/bytebuffer",
          "c:\\t6\\code\\DemonWare\\bdCore\\bdContainers\\bdByteBuffer.cpp",
          "bdByteBuffer::readDataType",
          0x2A5u,
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
