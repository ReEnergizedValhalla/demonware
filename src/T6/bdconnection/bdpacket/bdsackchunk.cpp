// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdsackchunk.cpp:0x9CFEC0
bool __cdecl bdBytePacker::appendBasicType<unsigned int>(
        void *buffer,
        const unsigned int bufferSize,
        const unsigned int offset,
        unsigned int *newOffset,
        const unsigned int *var)
{
  var = (const unsigned int *)*var;
  return bdBytePacker::appendBuffer(buffer, bufferSize, offset, newOffset, &var, 4u);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsackchunk.cpp:0x9CFEF0
void __cdecl bdCryptoUtils::calculateInitialVector(const unsigned int seed, unsigned __int8 *iv)
{
  unsigned __int8 seedBuffer[4]; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int IVSize; // [esp+8h] [ebp-18h] BYREF
  unsigned int tmp; // [esp+Ch] [ebp-14h] BYREF
  bdHashTiger192 tigerHash; // [esp+10h] [ebp-10h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  bdHashTiger192::bdHashTiger192(&tigerHash);
  v6 = 0;
  IVSize = 24;
  tmp = 0;
  bdBytePacker::appendBuffer(seedBuffer, 4u, 0, &tmp, &seed, 4u);
  bdHashTiger192::hash(&tigerHash, seedBuffer, 4u, iv, &IVSize);
  v6 = -1;
  bdHashTiger192::~bdHashTiger192(&tigerHash);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsackchunk.cpp:0x9CFF80
unsigned int __cdecl bdCryptoUtils::getNewIVSeed()
{
  bdTrulyRandomImpl *Instance; // eax

  Instance = bdSingleton<bdTrulyRandomImpl>::getInstance();
  return bdTrulyRandomImpl::getRandomUInt(Instance);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsackchunk.cpp:0x9CFF90
void __cdecl bdCore::init(const bool defaultMemoryFunctions)
{
  if ( bdCore::m_initialized )
  {
    bdLogMessage(
      BD_LOG_WARNING,
      "warn/",
      "core",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdCore.cpp",
      "bdCore::init",
      0x36u,
      "init() has been called twice without an intermediate quit()");
  }
  else
  {
    if ( defaultMemoryFunctions )
    {
      bdMemory::setAllocateFunc(bdMallocMemory::allocate);
      bdMemory::setAlignedAllocateFunc(bdMallocMemory::alignedAllocate);
      bdMemory::setDeallocateFunc(bdMallocMemory::deallocate);
      bdMemory::setAlignedDeallocateFunc(bdMallocMemory::deallocate);
      bdMemory::setReallocateFunc(bdMallocMemory::reallocate);
      bdMemory::setAlignedReallocateFunc(bdMallocMemory::alignedReallocate);
    }
    bdCore::m_initialized = 1;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsackchunk.cpp:0x9D0020
void __cdecl bdBase64::encode(const char *data, char *dest, unsigned int length)
{
  unsigned int v3; // eax
  int v4; // esi
  const char *v5; // ecx
  char v6; // cl
  unsigned int v7; // eax
  char v8; // cl
  int v9; // ebx
  unsigned int v10; // ebx
  char v11; // cl
  unsigned int v12; // eax
  char v13; // cl
  int v14; // ebx
  int v15; // esi

  v3 = 0;
  v4 = 0;
  if ( length )
  {
    v5 = cvt;
    do
    {
      dest[v4] = v5[(unsigned __int8)data[v3] >> 2];
      v6 = data[v3] & 3;
      v7 = v3 + 1;
      v8 = 16 * v6;
      if ( v7 < length )
        v8 |= (data[v7] >> 4) & 0xF;
      v9 = v8;
      v5 = cvt;
      dest[v4 + 1] = cvt[v9];
      v10 = length;
      if ( v7 >= length )
      {
        v12 = v7 + 1;
        dest[v4 + 2] = 61;
      }
      else
      {
        v11 = 2 * (data[v7] & 0xF);
        v12 = v7 + 1;
        v13 = 2 * v11;
        if ( v12 < length )
          v13 |= (data[v12] >> 6) & 3;
        v14 = v13;
        v5 = cvt;
        dest[v4 + 2] = cvt[v14];
        v10 = length;
      }
      v15 = v4 + 3;
      if ( v12 >= v10 )
      {
        dest[v15] = 61;
      }
      else
      {
        dest[v15] = v5[data[v12] & 0x3F];
        v10 = length;
      }
      v3 = v12 + 1;
      v4 = v15 + 1;
    }
    while ( v3 < v10 );
    dest[v4] = 0;
  }
  else
  {
    *dest = 0;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsackchunk.cpp:0x9D00F0
bool __cdecl bdBytePacker::appendBuffer(
        void *dest,
        const unsigned int destSize,
        const unsigned int offset,
        unsigned int *newOffset,
        const void *const src,
        const unsigned int writeSize)
{
  unsigned int v6; // ecx
  bool result; // al
  bool v8; // bl

  v6 = offset + writeSize;
  result = 1;
  *newOffset = offset + writeSize;
  if ( dest && src )
  {
    v8 = v6 <= destSize;
    if ( v6 > destSize )
      bdLogMessage(
        BD_LOG_WARNING,
        "warn/",
        "byte packer",
        "c:\\t6\\code\\DemonWare\\bdCore\\bdUtilities\\bdBytePacker.cpp",
        "bdBytePacker::appendBuffer",
        0x24u,
        "Not enough room left to write %u bytes.",
        writeSize);
    if ( offset <= destSize && v8 )
    {
      memmove((unsigned __int8 *)dest + offset, (unsigned __int8 *)src, writeSize);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsackchunk.cpp:0x9D0180
bool __cdecl bdBytePacker::removeBuffer(
        const void *src,
        const unsigned int srcSize,
        const unsigned int offset,
        unsigned int *newOffset,
        void *const dest,
        const unsigned int readSize)
{
  bool result; // al

  result = 1;
  *newOffset = offset + readSize;
  if ( dest && src )
  {
    if ( offset + readSize > srcSize )
    {
      bdLogMessage(
        BD_LOG_WARNING,
        "warn/",
        "byte packer",
        "c:\\t6\\code\\DemonWare\\bdCore\\bdUtilities\\bdBytePacker.cpp",
        "bdBytePacker::removeBuffer",
        0x6Au,
        "Not enough data left to read %u bytes.",
        readSize);
      return 0;
    }
    if ( offset > srcSize )
      return 0;
    memmove((unsigned __int8 *)dest, (unsigned __int8 *)src + offset, readSize);
    return 1;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsackchunk.cpp:0x9D0200
bool __cdecl bdBytePacker::skipBytes(
        const void *const buffer,
        const unsigned int bufferSize,
        const unsigned int offset,
        unsigned int *newOffset,
        const unsigned int bytes)
{
  bool result; // al

  result = 0;
  *newOffset = offset + bytes;
  if ( buffer )
    return offset + bytes <= bufferSize;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsackchunk.cpp:0x9D0220
bool __cdecl bdBytePacker::rewindBytes(
        const void *const buffer,
        const unsigned int __formal,
        const unsigned int offset,
        unsigned int *newOffset,
        const unsigned int bytes)
{
  bool result; // al

  *newOffset = offset - bytes;
  result = 0;
  if ( buffer )
    return offset >= bytes;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsackchunk.cpp:0x9D0250
bool __cdecl bdBytePacker::removeBasicType<unsigned char>(
        const void *buffer,
        const unsigned int bufferSize,
        const unsigned int offset,
        unsigned int *newOffset,
        unsigned __int8 *var)
{
  bool result; // al
  unsigned __int8 nvar; // [esp+3h] [ebp-1h] BYREF

  result = bdBytePacker::removeBuffer(buffer, bufferSize, offset, newOffset, &nvar, 1u);
  if ( result )
    *var = nvar;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsackchunk.cpp:0x9D0290
bool __cdecl bdBytePacker::appendEncodedUInt16(
        void *buffer,
        const unsigned int bufferSize,
        const unsigned int offset,
        unsigned int *newOffset,
        int value)
{
  bool result; // al
  unsigned int v6; // [esp-18h] [ebp-1Ch]

  if ( (unsigned __int16)value <= 0x7Fu )
  {
    HIBYTE(value) = value;
    return bdBytePacker::appendBuffer(buffer, bufferSize, offset, newOffset, (char *)&value + 3, 1u);
  }
  else
  {
    HIBYTE(value) = BYTE1(value) | 0x80;
    result = 0;
    if ( bdBytePacker::appendBuffer(buffer, bufferSize, offset, newOffset, (char *)&value + 3, 1u) )
    {
      v6 = *newOffset;
      HIBYTE(value) = value;
      if ( bdBytePacker::appendBuffer(buffer, bufferSize, v6, newOffset, (char *)&value + 3, 1u) )
        return 1;
    }
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsackchunk.cpp:0x9D0320
bool __cdecl bdBytePacker::removeEncodedUInt16(
        const unsigned __int8 *buffer,
        const unsigned int bufferSize,
        const unsigned int offset,
        unsigned int *newOffset,
        unsigned __int16 *value)
{
  unsigned __int8 v5; // bl
  bool result; // al
  unsigned __int8 v7; // bl
  unsigned __int8 firstByte; // [esp+Eh] [ebp-2h]
  unsigned __int8 dest; // [esp+Fh] [ebp-1h] BYREF

  v5 = 0;
  if ( !bdBytePacker::removeBuffer(buffer, bufferSize, offset, newOffset, &dest, 1u) )
  {
    result = 0;
    goto LABEL_6;
  }
  v5 = dest;
  result = 1;
  if ( dest < 0x80u )
  {
LABEL_6:
    *value = v5;
    return result;
  }
  firstByte = dest & 0x7F;
  v7 = 0;
  if ( bdBytePacker::removeBuffer(buffer, bufferSize, *newOffset, newOffset, &dest, 1u) )
  {
    v7 = dest;
    result = 1;
  }
  else
  {
    result = 0;
  }
  *value = v7 + (firstByte << 8);
  return result;
}

#endif // __UNIMPLEMENTED__
