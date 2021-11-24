// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once


#ifdef    __UNIMPLEMENTED__

// bdsingleton.h:0x567DF0
void __thiscall bdSingletonRegistryImpl::bdSingletonRegistryImpl(bdSingletonRegistryImpl *this)
{
  this->__vftable = (bdSingletonRegistryImpl_vtbl *)&bdSingletonRegistryImpl::`vftable';
  this->m_destroyFunctions.m_data = 0;
  this->m_destroyFunctions.m_capacity = 0;
  this->m_destroyFunctions.m_size = 0;
  if ( this->m_destroyFunctions.m_capacity )
    this->m_destroyFunctions.m_data = (void (__cdecl **)())bdMemory::allocate(4 * this->m_destroyFunctions.m_capacity);
  this->m_cleaningUp = 0;
}

#endif // __UNIMPLEMENTED__
