// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdcookieechochunk.cpp:0x9CEA40
char *__cdecl bdCommonAddrInfo::getBriefInfo(
        const bdReference<bdCommonAddr> addr,
        char *buf,
        const unsigned int length)
{
  bdCommonAddr *m_ptr; // eax
  char *BriefInfo; // esi

  m_ptr = addr.m_ptr;
  BriefInfo = 0;
  if ( addr.m_ptr )
  {
    BriefInfo = bdCommonAddrInfo::getBriefInfo(addr.m_ptr, buf, length);
    m_ptr = addr.m_ptr;
  }
  if ( m_ptr && !InterlockedDecrement(&m_ptr->m_refCount) && addr.m_ptr )
    ((void (__thiscall *)(bdCommonAddr *, int))addr.m_ptr->~bdReferencable)(addr.m_ptr, 1);
  return BriefInfo;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookieechochunk.cpp:0x9CEAD0
int __cdecl bdCommonAddrInfo::getInfo(const bdCommonAddr *addr, char *buf, const unsigned int length)
{
  char *v3; // edi
  __int32 v4; // eax
  __int32 v5; // eax
  const char *v6; // eax
  int v7; // eax
  char *v8; // esi
  bdArray<bdAddr> *LocalAddrs; // eax
  int v10; // eax
  char *v11; // esi
  unsigned int i; // ebx
  bdArray<bdAddr> *v13; // eax
  int v14; // eax
  bdAddr *PublicAddr; // eax
  int v16; // eax
  char *v17; // esi
  bdNATTypeDiscoveryClient::bdNATTypeDiscoveryClientState Hash; // eax
  int v19; // eax
  char *v20; // esi
  const char *loop; // [esp+10h] [ebp-38h]
  char str[24]; // [esp+14h] [ebp-34h] BYREF
  char addrString[22]; // [esp+2Ch] [ebp-1Ch] BYREF

  v3 = &buf[length];
  v4 = bdConnectionStore::getStatus((bdCommonAddr *)addr) - 1;
  if ( v4 )
  {
    v5 = v4 - 1;
    if ( v5 )
    {
      if ( v5 == 1 )
        v6 = "BD_NAT_STRICT";
      else
        v6 = "**UNKNOWN**";
    }
    else
    {
      v6 = "BD_NAT_MODERATE";
    }
  }
  else
  {
    v6 = "BD_NAT_OPEN";
  }
  v7 = bdSnprintf(buf, length, "NAT Type: %s\n", v6);
  if ( v7 <= 0 || v7 > (int)length )
  {
    v8 = v3 - 1;
    if ( length )
      *v8 = 0;
  }
  else
  {
    v8 = &buf[v7];
  }
  LocalAddrs = bdCommonAddr::getLocalAddrs((bdCommonAddr *)addr);
  v10 = bdSnprintf(v8, v3 - v8, "%u Local Addrs Found: \n", LocalAddrs->m_size);
  if ( v10 <= 0 || v10 > v3 - v8 )
  {
    v11 = v3 - 1;
    if ( length )
      *v11 = 0;
  }
  else
  {
    v11 = &v8[v10];
  }
  for ( i = 0; i < bdCommonAddr::getLocalAddrs((bdCommonAddr *)addr)->m_size; ++i )
  {
    v13 = bdCommonAddr::getLocalAddrs((bdCommonAddr *)addr);
    bdAddr::toString(&v13->m_data[i], addrString, 0x16u);
    v14 = bdSnprintf(v11, v3 - v11, "Local Addr %u :  %s \n", i, addrString);
    if ( v14 <= 0 || v14 > v3 - v11 )
    {
      v11 = v3 - 1;
      if ( length )
        *v11 = 0;
    }
    else
    {
      v11 += v14;
    }
  }
  PublicAddr = bdCommonAddr::getPublicAddr((bdNATTraversalPacket *)addr);
  bdAddr::toString(PublicAddr, str, 0x16u);
  v16 = bdSnprintf(v11, v3 - v11, "Public Addr :  %s \n", str);
  if ( v16 <= 0 || v16 > v3 - v11 )
  {
    v17 = v3 - 1;
    if ( length )
      *v17 = 0;
  }
  else
  {
    v17 = &v11[v16];
  }
  loop = "TRUE";
  if ( !bdCommonAddr::isLoopback((bdCommonAddr *)addr) )
    loop = "FALSE";
  Hash = bdCommonAddr::getHash((bdNATTypeDiscoveryClient *)addr);
  v19 = bdSnprintf(v17, v3 - v17, "Addr is loopback : %s  -- Addr Hash : %u \n", loop, Hash);
  if ( v19 <= 0 || v19 > v3 - v17 )
  {
    v20 = v3 - 1;
    if ( length )
      *v20 = 0;
  }
  else
  {
    v20 = &v17[v19];
  }
  return v20 - buf;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookieechochunk.cpp:0x9CECA0
int __cdecl bdCommonAddrInfo::getInfo(const bdReference<bdCommonAddr> addr, char *buf, const unsigned int length)
{
  bdCommonAddr *m_ptr; // eax
  int Info; // esi

  m_ptr = addr.m_ptr;
  Info = 0;
  if ( addr.m_ptr )
  {
    Info = bdCommonAddrInfo::getInfo(addr.m_ptr, buf, length);
    m_ptr = addr.m_ptr;
  }
  if ( m_ptr && !InterlockedDecrement(&m_ptr->m_refCount) && addr.m_ptr )
    ((void (__thiscall *)(bdCommonAddr *, int))addr.m_ptr->~bdReferencable)(addr.m_ptr, 1);
  return Info;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookieechochunk.cpp:0x9CED30
int __cdecl bdSecurityInfo::bufferToString(
        const unsigned __int8 *buffer,
        const unsigned int bufferLen,
        char *outBuffer,
        const unsigned int outBufferLen)
{
  unsigned int v4; // ebx
  char *v5; // esi

  v4 = 0;
  v5 = outBuffer;
  if ( !bufferLen )
    return v5 - outBuffer;
  while ( 1 )
  {
    if ( (v4 & 3) == 0 )
    {
      if ( v4 )
        v5 += bdSnprintf(v5, outBufferLen + outBuffer - v5, " ");
    }
    if ( bdSnprintf(v5, outBufferLen + outBuffer - v5, "%02hhx", buffer[v4]) != 2 )
      break;
    ++v4;
    v5 += 2;
    if ( v4 >= bufferLen )
      return v5 - outBuffer;
  }
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookieechochunk.cpp:0x9CEDA0
int __cdecl bdSecurityInfo::toString(const bdSecurityID *id, char *buffer, unsigned int len)
{
  return bdSecurityInfo::bufferToString(id->ab, 8u, buffer, len);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookieechochunk.cpp:0x9CEDC0
int __cdecl bdSecurityInfo::toString(const bdSecurityKey *key, char *buffer, unsigned int len)
{
  return bdSecurityInfo::bufferToString(key->ab, 0x10u, buffer, len);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookieechochunk.cpp:0x9CEDE0
bdAddr *__thiscall bdEndpoint::getSecID(bdNATTypeDiscoveryPacketReply *this)
{
  return &this->m_mappedAddr;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookieechochunk.cpp:0x9CEDF0
void __thiscall bdEndpoint::bdEndpoint(
        bdEndpoint *this,
        const bdReference<bdCommonAddr> addr,
        const bdSecurityID *secID)
{
  this->m_ca = addr;
  if ( addr.m_ptr )
    InterlockedIncrement(&addr.m_ptr->m_refCount);
  bdSecurityID::bdSecurityID(&this->m_secID, secID);
  if ( addr.m_ptr )
  {
    if ( !InterlockedDecrement(&addr.m_ptr->m_refCount) )
      ((void (__thiscall *)(bdCommonAddr *, int))addr.m_ptr->~bdReferencable)(addr.m_ptr, 1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcookieechochunk.cpp:0x9CEE90
bool __thiscall bdEndpoint::operator==(bdEndpoint *this, const bdEndpoint *other)
{
  bdCommonAddr *m_ptr; // esi
  bool result; // al
  const bdEndpoint *othera; // [esp+10h] [ebp+8h]

  m_ptr = this->m_ca.m_ptr;
  result = 0;
  if ( this->m_ca.m_ptr )
  {
    if ( other->m_ca.m_ptr )
    {
      othera = (const bdEndpoint *)bdCommonAddr::getHash((bdNATTypeDiscoveryClient *)other->m_ca.m_ptr);
      return (const bdEndpoint *)bdCommonAddr::getHash((bdNATTypeDiscoveryClient *)m_ptr) == othera
          && bdSecurityID::operator==(&this->m_secID, &other->m_secID);
    }
  }
  else if ( !other->m_ca.m_ptr )
  {
    return 1;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
