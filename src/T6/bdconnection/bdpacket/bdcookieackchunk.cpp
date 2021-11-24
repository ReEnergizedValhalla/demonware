// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdcookieackchunk.cpp:0x9CEEF0
bdReference<bdCommonAddr> *__thiscall bdEndpoint::getCommonAddr(bdEndpoint *this, bdReference<bdCommonAddr> *result)
{
  bdCommonAddr *m_ptr; // eax

  m_ptr = this->m_ca.m_ptr;
  result->m_ptr = (bdCommonAddr *)this->m_ca;
  if ( m_ptr )
    InterlockedIncrement(&m_ptr->m_refCount);
  return result;
}

#endif // __UNIMPLEMENTED__
