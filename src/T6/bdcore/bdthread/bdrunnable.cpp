// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdrunnable.cpp:0x9D0E90
bdHashTiger192 *__thiscall bdHashTiger192::`vector deleting destructor'(bdHashTiger192 *this, unsigned int a2)
{
  bdHashTiger192::~bdHashTiger192(this);
  if ( (a2 & 1) != 0 )
    bdMemory::deallocate(this);
  return this;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdrunnable.cpp:0x9D0EC0
void __thiscall bdMutex::bdMutex(bdMutex *this)
{
  this->m_handle = bdPlatformMutex::createMutex();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdrunnable.cpp:0x9D0EC0
void __thiscall bdMutex::bdMutex(bdMutex *this)
{
  this->m_handle = bdPlatformMutex::createMutex();
}

#endif // __UNIMPLEMENTED__
