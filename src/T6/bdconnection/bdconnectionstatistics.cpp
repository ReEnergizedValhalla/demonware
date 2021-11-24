// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdconnectionstatistics.cpp:0x9CDC30
bdAddr *__thiscall bdCommonAddr::getLocalAddrByIndex(bdCommonAddr *this, const unsigned int index)
{
  return &this->m_localAddrs.m_data[index];
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdconnectionstatistics.cpp:0x9CDC40
void __thiscall bdCommonAddr::calculateHash(bdCommonAddr *this)
{
  unsigned int m_size; // eax
  const bdAddr *v3; // eax
  int v4; // ebx
  bdInetAddr *v5; // eax
  int v6; // ecx
  bool v7; // bl
  bdAddr v8; // [esp+Ch] [ebp-64h] BYREF
  bdAddr v9; // [esp+14h] [ebp-5Ch] BYREF
  unsigned int dest; // [esp+1Ch] [ebp-54h] BYREF
  unsigned int tmpHashSize; // [esp+20h] [ebp-50h] BYREF
  bdAddr localAddr; // [esp+24h] [ebp-4Ch] BYREF
  unsigned int offset; // [esp+2Ch] [ebp-44h] BYREF
  bdHashTiger192 tiger; // [esp+30h] [ebp-40h] BYREF
  bdAddr addr; // [esp+34h] [ebp-3Ch] BYREF
  int v16; // [esp+3Ch] [ebp-34h]
  unsigned __int8 hash[24]; // [esp+40h] [ebp-30h] BYREF
  unsigned __int8 data[6]; // [esp+58h] [ebp-18h] BYREF
  int v19; // [esp+6Ch] [ebp-4h]

  v16 = 0;
  bdAddr::bdAddr(&addr);
  m_size = this->m_localAddrs.m_size;
  v19 = 0;
  if ( m_size )
  {
    bdAddr::bdAddr(&v8, this->m_localAddrs.m_data);
    LOBYTE(v19) = 1;
    v4 = 1;
  }
  else
  {
    bdAddr::bdAddr(&v9);
    v4 = 2;
    v19 = 2;
  }
  v16 = v4;
  bdAddr::bdAddr(&localAddr, v3);
  v19 = 4;
  if ( (v4 & 2) != 0 )
  {
    v4 &= ~2u;
    v16 = v4;
    bdInetAddr::~bdInetAddr(&v9.m_address);
  }
  LOBYTE(v19) = 5;
  if ( (v4 & 1) != 0 )
    bdInetAddr::~bdInetAddr(&v8.m_address);
  XAnimClientNotifyList::GetNotifyList((bdTrulyRandomImpl *)&this->m_publicAddr);
  if ( bdInetAddr::isValid(v5) )
  {
    v6 = *(_DWORD *)&this->m_publicAddr.m_port;
    addr.m_address.m_addr.inUn.m_iaddr = this->m_publicAddr.m_address.m_addr.inUn.m_iaddr;
    *(_DWORD *)&addr.m_port = v6;
  }
  else
  {
    addr = localAddr;
  }
  offset = 0;
  v7 = bdAddr::serialize(&addr, data, 6u, 0, &offset) != 0;
  tmpHashSize = 24;
  bdHashTiger192::bdHashTiger192(&tiger);
  LOBYTE(v19) = 6;
  if ( v7
    && bdHashTiger192::hash(&tiger, data, 6u, hash, &tmpHashSize)
    && bdBytePacker::removeBuffer(hash, 0x18u, 0, &offset, &dest, 4u) )
  {
    this->m_hash = dest;
  }
  LOBYTE(v19) = 5;
  bdHashTiger192::~bdHashTiger192(&tiger);
  LOBYTE(v19) = 0;
  bdInetAddr::~bdInetAddr(&localAddr.m_address);
  v19 = -1;
  bdInetAddr::~bdInetAddr(&addr.m_address);
}

#endif // __UNIMPLEMENTED__
