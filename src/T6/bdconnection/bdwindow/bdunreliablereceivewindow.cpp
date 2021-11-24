// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdunreliablereceivewindow.cpp:0x9CDA80
bool __thiscall bdCommonAddr::operator==(bdCommonAddr *this, const bdCommonAddr *other)
{
  const bdAddr *v3; // eax
  int v4; // ebx
  const bdAddr *v5; // eax
  int v6; // ebx
  bdInetAddr *v7; // eax
  bdAddr *p_m_publicAddr; // ebx
  bdInetAddr *v9; // eax
  bool v10; // zf
  bdAddr *p_otherLocalAddr; // eax
  bool v12; // bl
  bdAddr v14; // [esp+10h] [ebp-40h] BYREF
  bdAddr v15; // [esp+18h] [ebp-38h] BYREF
  bdAddr v16; // [esp+20h] [ebp-30h] BYREF
  bdAddr v17; // [esp+28h] [ebp-28h] BYREF
  bdAddr localAddr; // [esp+30h] [ebp-20h] BYREF
  bdAddr otherLocalAddr; // [esp+38h] [ebp-18h] BYREF
  int v20; // [esp+40h] [ebp-10h]
  int v21; // [esp+4Ch] [ebp-4h]

  v20 = 0;
  if ( this->m_localAddrs.m_size )
  {
    bdAddr::bdAddr(&v16, this->m_localAddrs.m_data);
    v21 = 0;
    v4 = 1;
  }
  else
  {
    bdAddr::bdAddr(&v17);
    v21 = 1;
    v4 = 2;
  }
  v20 = v4;
  bdAddr::bdAddr(&localAddr, v3);
  v21 = 3;
  if ( (v4 & 2) != 0 )
  {
    v4 &= ~2u;
    v20 = v4;
    bdInetAddr::~bdInetAddr(&v17.m_address);
  }
  LOBYTE(v21) = 4;
  if ( (v4 & 1) != 0 )
  {
    v4 &= ~1u;
    v20 = v4;
    bdInetAddr::~bdInetAddr(&v16.m_address);
  }
  if ( other->m_localAddrs.m_size )
  {
    bdAddr::bdAddr(&v14, other->m_localAddrs.m_data);
    LOBYTE(v21) = 5;
    v6 = v4 | 4;
  }
  else
  {
    bdAddr::bdAddr(&v15);
    v21 = 6;
    v6 = v4 | 8;
  }
  v20 = v6;
  bdAddr::bdAddr(&otherLocalAddr, v5);
  v21 = 8;
  if ( (v6 & 8) != 0 )
  {
    v6 &= ~8u;
    v20 = v6;
    bdInetAddr::~bdInetAddr(&v15.m_address);
  }
  LOBYTE(v21) = 9;
  if ( (v6 & 4) != 0 )
    bdInetAddr::~bdInetAddr(&v14.m_address);
  if ( this->m_hash == other->m_hash )
  {
    XAnimClientNotifyList::GetNotifyList((bdTrulyRandomImpl *)&this->m_publicAddr);
    p_m_publicAddr = &this->m_publicAddr;
    if ( !bdInetAddr::isValid(v7) )
      p_m_publicAddr = &localAddr;
    XAnimClientNotifyList::GetNotifyList((bdTrulyRandomImpl *)&other->m_publicAddr);
    v10 = !bdInetAddr::isValid(v9);
    p_otherLocalAddr = &other->m_publicAddr;
    if ( v10 )
      p_otherLocalAddr = &otherLocalAddr;
    v12 = bdAddr::operator==(p_m_publicAddr, p_otherLocalAddr);
    LOBYTE(v21) = 4;
    bdInetAddr::~bdInetAddr(&otherLocalAddr.m_address);
    v21 = -1;
    bdInetAddr::~bdInetAddr(&localAddr.m_address);
    return v12;
  }
  else
  {
    LOBYTE(v21) = 4;
    bdInetAddr::~bdInetAddr(&otherLocalAddr.m_address);
    v21 = -1;
    bdInetAddr::~bdInetAddr(&localAddr.m_address);
    return 0;
  }
}

#endif // __UNIMPLEMENTED__
