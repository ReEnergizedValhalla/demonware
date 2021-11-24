// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdsemaphore.cpp:0x9D0F00
bdCypher *__thiscall bdCypher::`scalar deleting destructor'(bdCypher *this, unsigned int a2)
{
  bdCypher::~bdCypher(this);
  if ( (a2 & 1) != 0 )
    bdMemory::deallocate(this);
  return this;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsemaphore.cpp:0x9D0F30
void __thiscall bdCypher3Des::~bdCypher3Des(bdCypher3Des *this)
{
  this->__vftable = (bdCypher3Des_vtbl *)&bdCypher3Des::`vftable';
  bdCypher::~bdCypher(this);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsemaphore.cpp:0x9D0F30
void __thiscall bdCypher3Des::~bdCypher3Des(bdCypher3Des *this)
{
  this->__vftable = (bdCypher3Des_vtbl *)&bdCypher3Des::`vftable';
  bdCypher::~bdCypher(this);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsemaphore.cpp:0x9D0F40
char __thiscall bdCypher3Des::init(bdCypher3Des *this, const unsigned __int8 *key, unsigned int keySize)
{
  int cipher; // eax
  symmetric_CBC *p_m_cbc; // [esp-4h] [ebp-10h]
  unsigned __int8 iv[8]; // [esp+0h] [ebp-Ch] BYREF

  p_m_cbc = &this->m_cbc;
  memset(iv, 0, sizeof(iv));
  cipher = find_cipher("3des");
  if ( !cbc_start(cipher, iv, key, keySize, 0, p_m_cbc) )
    return 1;
  bdLogMessage(
    BD_LOG_ERROR,
    "err/",
    "cypher3DES",
    "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdCypher3Des.cpp",
    "bdCypher3Des::init",
    0x2Du,
    "Error starting cipher.");
  return 0;
}

#endif // __UNIMPLEMENTED__
