// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdhmacsha1.cpp:0x9D0CE0
void __thiscall bdBitBuffer::writeDataType(bdBitBuffer *this, const bdBitBufferDataType dataType)
{
  if ( this->m_typeChecked )
    bdBitBuffer::writeRangedUInt32(this, dataType, 0, 0x1Fu, 0);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhmacsha1.cpp:0x9D0D00
bdHash *__thiscall bdHash::`scalar deleting destructor'(bdHash *this, unsigned int a2)
{
  bdHash::~bdHash(this);
  if ( (a2 & 1) != 0 )
    bdMemory::deallocate(this);
  return this;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhmacsha1.cpp:0x9D0D30
void __thiscall bdHashTiger192::~bdHashTiger192(bdHashTiger192 *this)
{
  this->__vftable = (bdHashTiger192_vtbl *)&bdHashTiger192::`vftable';
  bdHash::~bdHash(this);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhmacsha1.cpp:0x9D0D40
char __thiscall bdHashTiger192::hash(
        bdHashTiger192 *this,
        const unsigned __int8 *data,
        const unsigned int dataSize,
        unsigned __int8 *result,
        unsigned int *resultSize)
{
  unsigned int *v5; // esi
  int hash; // eax
  int v7; // eax

  v5 = resultSize;
  if ( *resultSize > 0x18 )
    bdLogMessage(
      BD_LOG_WARNING,
      "warn/",
      "hashtiger192",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdHashTiger192.cpp",
      "bdHashTiger192::hash",
      0x21u,
      "Tiger hash only requires result buffer of 24 bytes. Remainder of buffer will not be used");
  resultSize = (unsigned int *)*v5;
  hash = find_hash("tiger");
  v7 = hash_memory(hash, data, dataSize, result, (unsigned int *)&resultSize);
  if ( v7 == 6 )
  {
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "hashtiger192",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdHashTiger192.cpp",
      "bdHashTiger192::hash",
      0x29u,
      "Unable to create tiger hash of less than 24 bytes in length!.");
    return 0;
  }
  else if ( v7 )
  {
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "hashtiger192",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdHashTiger192.cpp",
      "bdHashTiger192::hash",
      0x2Eu,
      "Unable to create hash.");
    return 0;
  }
  else
  {
    *v5 = (unsigned int)resultSize;
    return 1;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhmacsha1.cpp:0x9D0E10
void __thiscall bdHashTiger192::bdHashTiger192(bdHashTiger192 *this)
{
  this->__vftable = (bdHashTiger192_vtbl *)&bdHashTiger192::`vftable';
  if ( register_hash(&tiger_desc) == -1 )
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "hashtiger192",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdHashTiger192.cpp",
      "bdHashTiger192::bdHashTiger192",
      0x14u,
      "Unable to register hash.");
}

#endif // __UNIMPLEMENTED__
