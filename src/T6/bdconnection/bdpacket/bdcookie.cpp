// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE540
void __thiscall bdInetAddr::bdInetAddr(bdInetAddr *this)
{
  bdInAddr::bdInAddr(&this->m_addr);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE550
void __thiscall bdInetAddr::~bdInetAddr(bdInetAddr *this)
{
  this->m_addr.inUn.m_iaddr = -559038737;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE560
void __thiscall bdInetAddr::bdInetAddr(bdInetAddr *this, const bdInetAddr *other)
{
  bdInAddr::bdInAddr(&this->m_addr);
  *this = *other;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE5A0
void __thiscall bdInetAddr::set(bdSecurityKeyMap *this, bdSecurityKeyMapListener *listener)
{
  this->m_listener = listener;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE5B0
bool __thiscall bdInetAddr::isValid(bdInetAddr *this)
{
  const bdInetAddr *v2; // eax
  bdInetAddr v4; // [esp+4h] [ebp-4h] BYREF

  bdInetAddr::bdInetAddr(&v4);
  return !bdSequenceNumber::operator==(this, v2);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE5E0
unsigned int __thiscall bdInetAddr::toString(bdInetAddr *this, char *const str, const unsigned int size)
{
  if ( bdInetAddr::isValid(this) )
    return bdInAddr::toString(&this->m_addr, str, size);
  else
    return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE610
bdInAddr *__thiscall bdInetAddr::getInAddr(bdInetAddr *this, bdInAddr *result)
{
  bdInAddr *v2; // eax

  v2 = result;
  *result = this->m_addr;
  return v2;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE620
bool __thiscall bdInetAddr::serialize(
        bdInetAddr *this,
        void *data,
        const unsigned int size,
        const unsigned int offset,
        unsigned int *newOffset)
{
  return bdBytePacker::appendBuffer(data, size, offset, newOffset, this, 4u);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE650
bool __thiscall bdInetAddr::deserialize(
        bdInetAddr *this,
        const void *data,
        const unsigned int size,
        const unsigned int offset,
        unsigned int *newOffset)
{
  return bdBytePacker::removeBuffer(data, size, offset, newOffset, this, 4u);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE680
bdInetAddr *__cdecl bdInetAddr::Any(bdInetAddr *result)
{
  bdInetAddr::bdInetAddr(result);
  bdInetAddr::set((bdSecurityKeyMap *)result, 0);
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE6B0
void __thiscall bdInetAddr::bdInetAddr(bdInetAddr *this, const char *address)
{
  bdInAddr::bdInAddr(&this->m_addr);
  bdInetAddr::set(this, address);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE6D0
void __thiscall bdInetAddr::bdInetAddr(bdInetAddr *this, const unsigned int address)
{
  bdInAddr::bdInAddr(&this->m_addr);
  bdInetAddr::set((bdSecurityKeyMap *)this, (bdSecurityKeyMapListener *)address);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE6F0
void __thiscall bdTrulyRandomImpl::getRandomUByte8(
        bdTrulyRandomImpl *this,
        unsigned __int8 *in,
        const unsigned int length)
{
  bdGetRandomUChar8(in, length);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE710
unsigned int __thiscall bdTrulyRandomImpl::getRandomUInt(bdTrulyRandomImpl *this)
{
  unsigned __int8 randomBytes[4]; // [esp+0h] [ebp-4h] BYREF

  *(_DWORD *)randomBytes = this;
  bdTrulyRandomImpl::getRandomUByte8(this, randomBytes, 4u);
  return *(_DWORD *)randomBytes;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE730
bdStringData *__cdecl getEmptyStringData()
{
  *g_emptyString = 0;
  return (bdStringData *)g_emptyStringData;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE740
bdStringData *__thiscall bdString::getStringData(bdString *this)
{
  return (bdStringData *)(this->m_string - 12);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE750
void __thiscall bdString::addReference(bdString *this, bdStringData *stringData)
{
  ++stringData->m_referenceCount;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE750
void __thiscall bdString::addReference(bdString *this, bdStringData *stringData)
{
  ++stringData->m_referenceCount;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE760
void __thiscall bdString::bdString(bdString *this, const bdString *s)
{
  bdStringData *StringData; // eax
  bdString *v3; // ecx

  this->m_string = s->m_string;
  StringData = bdString::getStringData(this);
  bdString::addReference(v3, StringData);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE780
void __thiscall bdString::initialize(bdString *this)
{
  bdStringData *EmptyStringData; // eax
  bdString *v2; // ecx
  bdStringData *StringData; // eax
  bdString *v4; // ecx

  EmptyStringData = getEmptyStringData();
  v2->m_string = (char *)&EmptyStringData[1];
  StringData = bdString::getStringData(v2);
  bdString::addReference(v4, StringData);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE7A0
void __thiscall bdString::allocateBuffer(bdString *this, const unsigned int length)
{
  unsigned int v3; // eax
  unsigned int v4; // esi
  char *v5; // eax

  v3 = (length + 1) >> 6;
  if ( (((_BYTE)length + 1) & 0x3F) != 0 )
    ++v3;
  v4 = v3 << 6;
  v5 = (char *)bdMemory::allocate((v3 << 6) + 12);
  *((_DWORD *)v5 + 2) = v4;
  *((_DWORD *)v5 + 1) = length;
  *(_DWORD *)v5 = 1;
  this->m_string = v5 + 12;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE7F0
void __thiscall bdString::freeBuffer(bdString *this, bdStringData *stringData)
{
  bdMemory::deallocate(stringData);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE810
void __thiscall bdString::bdString(bdString *this, const char *const s)
{
  unsigned int v3; // eax
  unsigned int v4; // edi

  v3 = strlen(s);
  v4 = v3;
  if ( v3 )
  {
    bdString::allocateBuffer(this, v3);
    memcpy((unsigned __int8 *)this->m_string, (unsigned __int8 *)s, v4 + 1);
  }
  else
  {
    bdString::initialize(this);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE860
void __thiscall bdString::removeReference(bdString *this, bdStringData *stringData)
{
  if ( stringData->m_referenceCount-- == 1 )
    bdString::freeBuffer(this, stringData);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE880
void __thiscall bdString::~bdString(bdString *this)
{
  bdStringData *StringData; // eax
  bdString *v2; // ecx

  StringData = bdString::getStringData(this);
  bdString::removeReference(v2, StringData);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE890
bdString *__thiscall bdString::operator=(bdString *this, const bdString *s)
{
  bdStringData *StringData; // eax
  bdString *v4; // ecx
  bdStringData *v5; // eax
  bdString *v6; // ecx

  if ( this->m_string != s->m_string )
  {
    StringData = bdString::getStringData(this);
    bdString::removeReference(v4, StringData);
    this->m_string = s->m_string;
    v5 = bdString::getStringData(this);
    bdString::addReference(v6, v5);
  }
  return this;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookie.cpp:0x9CE8D0
char *__cdecl bdCommonAddrInfo::getBriefInfo(const bdCommonAddr *addr, char *buf, const unsigned int length)
{
  unsigned int v3; // ebx
  char *v4; // esi
  bdAddr *PublicAddr; // eax
  bdInetAddr *v6; // eax
  bdAddr *v7; // eax
  int v8; // eax
  char *v9; // esi
  unsigned int i; // ebx
  bdAddr *LocalAddrByIndex; // eax
  char *v12; // esi
  char *v13; // esi
  char *v15; // [esp-10h] [ebp-BCh]
  char *end; // [esp+10h] [ebp-9Ch]
  char *v17; // [esp+14h] [ebp-98h]
  char addrsString[120]; // [esp+18h] [ebp-94h] BYREF
  char addrString[22]; // [esp+90h] [ebp-1Ch] BYREF

  v3 = length;
  v4 = buf;
  v17 = buf;
  end = &buf[length];
  PublicAddr = bdCommonAddr::getPublicAddr((bdNATTraversalPacket *)addr);
  XAnimClientNotifyList::GetNotifyList((bdTrulyRandomImpl *)PublicAddr);
  if ( bdInetAddr::isValid(v6) )
  {
    v7 = bdCommonAddr::getPublicAddr((bdNATTraversalPacket *)addr);
    bdAddr::toString(v7, addrString, 0x16u);
    v8 = bdSnprintf(buf, length, "Public Addr: %s\n", addrString);
  }
  else if ( bdCommonAddr::getLocalAddrs((bdCommonAddr *)addr)->m_size )
  {
    v9 = addrsString;
    bdCommonAddr::getLocalAddrs((bdCommonAddr *)addr);
    for ( i = 0; i < bdCommonAddr::getLocalAddrs((bdCommonAddr *)addr)->m_size; ++i )
    {
      LocalAddrByIndex = bdCommonAddr::getLocalAddrByIndex((bdCommonAddr *)addr, i);
      v12 = &v9[bdAddr::toString(LocalAddrByIndex, v9, addrString - v9)];
      v9 = &v12[bdSnprintf(v12, addrString - v12, ", ")];
    }
    v15 = v17;
    *(v9 - 2) = 0;
    v8 = bdSnprintf(v15, length, "Local Addr: %s\n", addrsString);
    v4 = v17;
    v3 = length;
  }
  else
  {
    v8 = bdSnprintf(buf, length, "Empty Common Addr\n");
  }
  if ( v8 <= 0 || v8 > end - v4 )
  {
    v17 = end - 1;
    v13 = end - 1;
    if ( v3 )
      *(end - 1) = 0;
  }
  else
  {
    v13 = &v4[v8];
  }
  return &v13[v3 - (_DWORD)end];
}

#endif // __UNIMPLEMENTED__
