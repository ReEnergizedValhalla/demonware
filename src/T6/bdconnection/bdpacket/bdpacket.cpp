// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF2F0
bool __thiscall bdByteBuffer::writeUInt16(bdByteBuffer *this, int u)
{
  bool result; // al

  result = 0;
  if ( bdByteBuffer::writeDataType(this, BD_BB_UNSIGNED_INTEGER16_TYPE) )
  {
    u = (unsigned __int16)u;
    if ( bdByteBuffer::write(this, &u, 2u) )
      return 1;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF330
bool __thiscall bdByteBuffer::writeNAN(bdByteBuffer *this)
{
  if ( this->m_typeChecked )
    return bdByteBuffer::writeDataType(this, BD_BB_NAN_TYPE);
  bdLogMessage(
    BD_LOG_ERROR,
    "err/",
    "core/bytebuffer",
    "c:\\t6\\code\\DemonWare\\bdCore\\bdContainers\\bdByteBuffer.cpp",
    "bdByteBuffer::writeNAN",
    0xDEu,
    "NaN types cannot be used on not type checked byte buffers");
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF370
bool __thiscall bdByteBuffer::writeNoType(bdByteBuffer *this)
{
  if ( this->m_typeChecked )
    return bdByteBuffer::writeDataType(this, BD_BB_NO_TYPE);
  bdLogMessage(
    BD_LOG_ERROR,
    "err/",
    "core/bytebuffer",
    "c:\\t6\\code\\DemonWare\\bdCore\\bdContainers\\bdByteBuffer.cpp",
    "bdByteBuffer::writeNoType",
    0xECu,
    "No type cannot be written to not type checked byte buffers");
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF3B0
bool __thiscall bdByteBuffer::writeInt64(bdByteBuffer *this, const __int64 i)
{
  unsigned int v2; // ebx
  unsigned int v3; // edi

  v2 = HIDWORD(i);
  v3 = i;
  if ( i == 0x7FFFFFFFFFFFFFFFi64 )
    return bdByteBuffer::writeNAN(this);
  if ( bdByteBuffer::writeDataType(this, BD_BB_SIGNED_INTEGER64_TYPE) )
  {
    i = __PAIR64__(v2, v3);
    if ( bdByteBuffer::write(this, &i, 8u) )
      return 1;
  }
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF410
bool __thiscall bdByteBuffer::writeUInt64(bdByteBuffer *this, const unsigned __int64 u)
{
  unsigned int v2; // ebx
  unsigned int v3; // edi

  v2 = HIDWORD(u);
  v3 = u;
  if ( (HIDWORD(u) & (unsigned int)u) == -1 )
    return bdByteBuffer::writeNAN(this);
  if ( bdByteBuffer::writeDataType(this, BD_BB_UNSIGNED_INTEGER64_TYPE) )
  {
    u = __PAIR64__(v2, v3);
    if ( bdByteBuffer::write(this, &u, 8u) )
      return 1;
  }
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF470
bool __thiscall bdByteBuffer::writeFloat32(bdByteBuffer *this, const float f)
{
  if ( 2147483600.0 == f )
    return bdByteBuffer::writeNAN(this);
  return bdByteBuffer::writeDataType(this, BD_BB_FLOAT32_TYPE) && bdByteBuffer::write(this, &f, 4u);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF4D0
bool __thiscall bdByteBuffer::readBool(bdByteBuffer *this, bool *b)
{
  bool result; // al
  unsigned __int8 byte; // [esp+7h] [ebp-1h] BYREF

  result = bdByteBuffer::readDataType(this, BD_BB_BOOL_TYPE);
  if ( result )
  {
    byte = 0;
    result = bdByteBuffer::read(this, &byte, 1u);
    if ( result )
      *b = byte != 0;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF510
bool __thiscall bdByteBuffer::readUInt16(bdByteBuffer *this, unsigned __int16 *u)
{
  bool result; // al
  unsigned __int16 data; // [esp+4h] [ebp-4h] BYREF

  if ( !bdByteBuffer::readDataType(this, BD_BB_UNSIGNED_INTEGER16_TYPE) )
    return 0;
  result = bdByteBuffer::read(this, &data, 2u);
  if ( result )
  {
    *u = data;
    return result;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF600
bool __thiscall bdByteBuffer::readInt64(bdByteBuffer *this, __int64 *i)
{
  bool v3; // al
  int v4; // edx
  int data[2]; // [esp+4h] [ebp-8h] BYREF

  if ( !bdByteBuffer::readDataType(this, BD_BB_SIGNED_INTEGER64_TYPE) )
    return 0;
  v3 = bdByteBuffer::read(this, data, 8u);
  if ( v3 )
  {
    v4 = data[1];
    *(_DWORD *)i = data[0];
    *((_DWORD *)i + 1) = v4;
    return 1;
  }
  return v3;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF660
bool __thiscall bdByteBuffer::readUInt64(bdByteBuffer *this, unsigned __int64 *u)
{
  bool v3; // al
  int v4; // edx
  int data[2]; // [esp+4h] [ebp-8h] BYREF

  if ( !bdByteBuffer::readDataType(this, BD_BB_UNSIGNED_INTEGER64_TYPE) )
    return 0;
  v3 = bdByteBuffer::read(this, data, 8u);
  if ( v3 )
  {
    v4 = data[1];
    *(_DWORD *)u = data[0];
    *((_DWORD *)u + 1) = v4;
    return 1;
  }
  return v3;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF6C0
bool __thiscall bdByteBuffer::readFloat32(bdByteBuffer *this, float *f)
{
  bool result; // al
  float data; // [esp+4h] [ebp-4h] BYREF

  if ( !bdByteBuffer::readDataType(this, BD_BB_FLOAT32_TYPE) )
    return 0;
  result = bdByteBuffer::read(this, &data, 4u);
  if ( result )
  {
    *f = data;
    return result;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF710
bool __thiscall bdByteBuffer::readString(bdByteBuffer *this, char *const s, const unsigned int maxLen)
{
  bool result; // al
  unsigned int v5; // edi
  unsigned int i; // esi
  char v7; // cl

  result = bdByteBuffer::readDataType(this, BD_BB_SIGNED_CHAR8_STRING_TYPE);
  if ( result && s )
  {
    v5 = maxLen;
    for ( i = 0; ; ++i )
    {
      HIBYTE(maxLen) = 0;
      result = bdByteBuffer::read(this, (char *)&maxLen + 3, 1u);
      v7 = HIBYTE(maxLen);
      if ( i < v5 )
        s[i] = HIBYTE(maxLen);
      if ( !result || !v7 )
        break;
    }
    if ( v5 )
      s[v5 - 1] = 0;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF770
bool __thiscall bdByteBuffer::readBlob(bdByteBuffer *this, unsigned __int8 *const blob, unsigned int *length)
{
  bool result; // al
  bool v5; // al
  unsigned int v6; // esi
  bool v7; // bl
  unsigned int v8; // eax
  unsigned int tempLength; // [esp+4h] [ebp-4h] BYREF

  result = bdByteBuffer::readDataType(this, BD_BB_BLOB_TYPE);
  if ( result )
  {
    tempLength = 0;
    v5 = bdByteBuffer::readUInt32(this, &tempLength);
    v6 = tempLength;
    v7 = v5;
    if ( v5 && blob )
    {
      v8 = *length;
      if ( *length >= tempLength )
        v8 = tempLength;
      v7 = bdByteBuffer::read(this, blob, v8);
      if ( v6 > *length )
        bdLogMessage(
          BD_LOG_WARNING,
          "warn/",
          "core/bytebuffer",
          "c:\\t6\\code\\DemonWare\\bdCore\\bdContainers\\bdByteBuffer.cpp",
          "bdByteBuffer::readBlob",
          0x238u,
          "Reading BLOB (%u bytes) buffer too small (%u bytes).",
          v6,
          *length);
    }
    *length = v6;
    return v7;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF800
bool __thiscall bdByteBuffer::readAndAllocateBlob(bdByteBuffer *this, unsigned __int8 **blob, unsigned int *length)
{
  unsigned __int8 *v3; // esi
  bool DataType; // bl
  unsigned __int8 *v6; // eax
  unsigned int v7; // edx
  bool result; // al
  unsigned int tmpLength; // [esp+Ch] [ebp-4h] BYREF

  v3 = 0;
  tmpLength = 0;
  DataType = bdByteBuffer::readDataType(this, BD_BB_BLOB_TYPE);
  if ( !DataType )
    goto LABEL_7;
  DataType = bdByteBuffer::readUInt32(this, &tmpLength);
  if ( !DataType )
    goto LABEL_7;
  v6 = (unsigned __int8 *)bdMemory::allocate(tmpLength);
  v3 = v6;
  if ( v6 )
    DataType = bdByteBuffer::read(this, v6, tmpLength);
  if ( DataType )
  {
    v7 = tmpLength;
    *blob = v3;
    result = DataType;
    *length = v7;
  }
  else
  {
LABEL_7:
    bdMemory::deallocate(v3);
    return DataType;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF880
bdByteBuffer *__thiscall bdByteBuffer::`vector deleting destructor'(bdByteBuffer *this, unsigned int a2)
{
  bdByteBuffer::~bdByteBuffer(this);
  if ( (a2 & 1) != 0 )
    bdMemory::deallocate(this);
  return this;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF8B0
bool __thiscall bdByteBuffer::writeBool(bdByteBuffer *this, int b)
{
  bool result; // al

  result = 0;
  if ( bdByteBuffer::writeDataType(this, BD_BB_BOOL_TYPE) )
  {
    HIBYTE(b) = b;
    if ( bdByteBuffer::write(this, (char *)&b + 3, 1u) )
      return 1;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF8F0
bool __thiscall bdByteBuffer::writeUByte8(bdByteBuffer *this, int b)
{
  bool result; // al

  result = 0;
  if ( bdByteBuffer::writeDataType(this, BD_BB_UNSIGNED_CHAR8_TYPE) )
  {
    HIBYTE(b) = b;
    if ( bdByteBuffer::write(this, (char *)&b + 3, 1u) )
      return 1;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF930
bool __thiscall bdByteBuffer::writeInt32(bdByteBuffer *this, const int i)
{
  int v2; // edi

  v2 = i;
  if ( i == 0x7FFFFFFF )
    return bdByteBuffer::writeNAN(this);
  if ( bdByteBuffer::writeDataType(this, BD_BB_SIGNED_INTEGER32_TYPE) )
  {
    i = v2;
    if ( bdByteBuffer::write(this, &i, 4u) )
      return 1;
  }
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF980
bool __thiscall bdByteBuffer::writeUInt32(bdByteBuffer *this, const unsigned int u)
{
  unsigned int v2; // edi

  v2 = u;
  if ( u == -1 )
    return bdByteBuffer::writeNAN(this);
  if ( bdByteBuffer::writeDataType(this, BD_BB_UNSIGNED_INTEGER32_TYPE) )
  {
    u = v2;
    if ( bdByteBuffer::write(this, &u, 4u) )
      return 1;
  }
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CF9D0
bool __thiscall bdByteBuffer::writeString(bdByteBuffer *this, const char *const s, const unsigned int maxLen)
{
  unsigned __int8 *v3; // edi
  bool result; // al
  bool v6; // al
  unsigned int v7; // esi
  int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // esi
  bool ok; // [esp+Bh] [ebp-1h]

  v3 = (unsigned __int8 *)s;
  if ( !s )
    return bdByteBuffer::writeNAN(this);
  v6 = bdByteBuffer::writeDataType(this, BD_BB_SIGNED_CHAR8_STRING_TYPE);
  v7 = maxLen;
  ok = v6;
  memchr(v3, 0, maxLen);
  if ( v8 && (v9 = v8 - (_DWORD)v3, v9 < v7) )
  {
    v10 = v9 + 1;
    HIBYTE(s) = 0;
  }
  else
  {
    v10 = v7 - 1;
    HIBYTE(s) = 1;
    bdLogMessage(
      BD_LOG_WARNING,
      "warn/",
      "core/bytebuffer",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdContainers\\bdByteBuffer.cpp",
      "bdByteBuffer::writeString",
      0x14Cu,
      "String was not null terminated. Data will be truncated.");
  }
  result = ok && bdByteBuffer::write(this, v3, v10);
  if ( HIBYTE(s) == 1 )
    result = result && (HIBYTE(s) = 0, bdByteBuffer::write(this, (char *)&s + 3, 1u));
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CFAA0
bool __thiscall bdByteBuffer::writeBlob(bdByteBuffer *this, const void *const blob, const unsigned int length)
{
  return bdByteBuffer::writeDataType(this, BD_BB_BLOB_TYPE)
      && bdByteBuffer::writeUInt32(this, length)
      && bdByteBuffer::write(this, blob, length);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CFB40
bool __thiscall bdByteBuffer::writeArrayStart(
        bdByteBuffer *this,
        unsigned __int8 type,
        unsigned int numElements,
        unsigned int elementSize)
{
  bool v5; // al
  bool v6; // al

  this->m_typeCheckedCopy = this->m_typeChecked;
  this->m_typeChecked = 0;
  v5 = bdByteBuffer::writeUByte8(this, (unsigned __int8)(type + 100));
  this->m_typeChecked = 1;
  v6 = v5 && bdByteBuffer::writeUInt32(this, elementSize * numElements);
  this->m_typeChecked = 0;
  return v6 && bdByteBuffer::writeUInt32(this, numElements);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacket.cpp:0x9CFBB0
bool __thiscall bdByteBuffer::readArrayStart(bdByteBuffer *this, int expectedType, unsigned int *numElements)
{
  int v5; // [esp+0h] [ebp-8h]
  unsigned __int8 type; // [esp+7h] [ebp-1h] BYREF

  this->m_typeCheckedCopy = this->m_typeChecked;
  this->m_typeChecked = 0;
  if ( !bdByteBuffer::readUByte8(this, &type) )
  {
    bdLogMessage(
      BD_LOG_WARNING,
      "warn/",
      "warn",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdContainers\\bdByteBuffer.cpp",
      "bdByteBuffer::readArrayStart",
      0x6Bu,
      "readArrayStart: No array %d\n",
      v5);
    *numElements = 0;
    return 0;
  }
  if ( type - 100 == (unsigned __int8)expectedType )
  {
    this->m_typeChecked = 0;
    return bdByteBuffer::readUByte8(this, (unsigned __int8 *)&expectedType + 3)
        && bdByteBuffer::readUInt32(this, (unsigned int *)&expectedType)
        && bdByteBuffer::readUInt32(this, numElements);
  }
  else
  {
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "err",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdContainers\\bdByteBuffer.cpp",
      "bdByteBuffer::readArrayStart",
      0x72u,
      "readArrayStart: Expected type %d but read type %d\n",
      (unsigned __int8)expectedType,
      type);
    return 0;
  }
}

#endif // __UNIMPLEMENTED__
