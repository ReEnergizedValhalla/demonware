// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdaddrhandlerefwrapper.cpp:0x9D20B0
void __thiscall bdSessionID::bdSessionID(bdSessionID *this)
{
  bdTaskResult::bdTaskResult(this);
  this->__vftable = (bdSessionID_vtbl *)&bdSessionID::`vftable';
  bdSecurityID::bdSecurityID(&this->m_sessionID);
  *(_DWORD *)this->m_sessionID.ab = 0;
  *(_DWORD *)&this->m_sessionID.ab[4] = 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdaddrhandlerefwrapper.cpp:0x9D2110
void __thiscall bdSessionID::bdSessionID(bdSessionID *this, const bdSessionID *other)
{
  bdTaskResult::bdTaskResult(this);
  this->__vftable = (bdSessionID_vtbl *)&bdSessionID::`vftable';
  bdSecurityID::bdSecurityID(&this->m_sessionID);
  this->m_sessionID = other->m_sessionID;
}

#endif // __UNIMPLEMENTED__
