// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdecckey.cpp:0x9D1190
void __thiscall bdCypher3Des::bdCypher3Des(bdCypher3Des *this)
{
  this->__vftable = (bdCypher3Des_vtbl *)&bdCypher3Des::`vftable';
  if ( register_cipher(&des3_desc) == -1 )
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "cypher3DES",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdCypher3Des.cpp",
      "bdCypher3Des::bdCypher3Des",
      0x17u,
      "Error registering cipher.");
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdecckey.cpp:0x9D1210
bdCypher3Des *__thiscall bdCypher3Des::`vector deleting destructor'(bdCypher3Des *this, unsigned int a2)
{
  bdCypher3Des::~bdCypher3Des(this);
  if ( (a2 & 1) != 0 )
    bdMemory::deallocate(this);
  return this;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdecckey.cpp:0x9D1240
void __thiscall bdCypherAES::~bdCypherAES(bdCypherAES *this)
{
  this->__vftable = (bdCypherAES_vtbl *)&bdCypherAES::`vftable';
  bdCypher::~bdCypher(this);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdecckey.cpp:0x9D1250
char __thiscall bdCypherAES::init(bdCypherAES *this, const unsigned __int8 *key, unsigned int keySize)
{
  int cipher_id; // eax
  int v5; // eax
  const char *v6; // eax
  unsigned __int8 iv[16]; // [esp+8h] [ebp-14h] BYREF

  memset(iv, 0, sizeof(iv));
  cipher_id = find_cipher_id(aes_desc.ID);
  v5 = cbc_start(cipher_id, iv, key, keySize, 0, &this->m_cbc);
  if ( !v5 )
    return 1;
  v6 = error_to_string(v5);
  bdLogMessage(
    BD_LOG_ERROR,
    "err/",
    "bdCypherAES",
    "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdCypherAES.cpp",
    "bdCypherAES::init",
    0x2Cu,
    "Error starting cipher %s.",
    v6);
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdecckey.cpp:0x9D12F0
char __thiscall bdCypherAES::encrypt(
        bdCypherAES *this,
        const unsigned __int8 *iv,
        const unsigned __int8 *pt,
        unsigned __int8 *ct,
        unsigned int size)
{
  symmetric_CBC *p_m_cbc; // esi
  int v6; // eax
  const char *v7; // eax
  int v9; // eax
  const char *v10; // eax

  p_m_cbc = &this->m_cbc;
  v6 = cbc_setiv(iv, 0x10u, &this->m_cbc);
  if ( v6 )
  {
    v7 = error_to_string(v6);
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "bdCypherAES",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdCypherAES.cpp",
      "bdCypherAES::encrypt",
      0x3Bu,
      "Failed to set IV seed > %s",
      v7);
    return 0;
  }
  else
  {
    v9 = cbc_encrypt(pt, ct, size, p_m_cbc);
    if ( v9 )
    {
      v10 = error_to_string(v9);
      bdLogMessage(
        BD_LOG_ERROR,
        "err/",
        "bdCypherAES",
        "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdCypherAES.cpp",
        "bdCypherAES::encrypt",
        0x47u,
        "Error encrypting > %s",
        v10);
      return 0;
    }
    else
    {
      return 1;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdecckey.cpp:0x9D13A0
char __thiscall bdCypherAES::decrypt(
        bdCypherAES *this,
        const unsigned __int8 *iv,
        const unsigned __int8 *ct,
        unsigned __int8 *pt,
        unsigned int size)
{
  symmetric_CBC *p_m_cbc; // esi
  int v6; // eax
  const char *v7; // eax
  int v9; // eax
  const char *v10; // eax

  p_m_cbc = &this->m_cbc;
  v6 = cbc_setiv(iv, 0x10u, &this->m_cbc);
  if ( v6 )
  {
    v7 = error_to_string(v6);
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "bdCypherAES",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdCypherAES.cpp",
      "bdCypherAES::decrypt",
      0x5Au,
      "Failed to set IV seed > %s",
      v7);
    return 0;
  }
  else
  {
    v9 = cbc_decrypt(ct, pt, size, p_m_cbc);
    if ( v9 )
    {
      v10 = error_to_string(v9);
      bdLogMessage(
        BD_LOG_ERROR,
        "err/",
        "bdCypherAES",
        "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdCypherAES.cpp",
        "bdCypherAES::decrypt",
        0x66u,
        "Error decrypting > %s",
        v10);
      return 0;
    }
    else
    {
      return 1;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdecckey.cpp:0x9D1450
void __thiscall bdCypherAES::bdCypherAES(bdCypherAES *this)
{
  int v1; // eax
  const char *v2; // eax

  this->__vftable = (bdCypherAES_vtbl *)&bdCypherAES::`vftable';
  v1 = register_cipher(&aes_desc) == -1;
  if ( v1 )
  {
    v2 = error_to_string(v1);
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "bdCypherAES",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdCypherAES.cpp",
      "bdCypherAES::bdCypherAES",
      0x12u,
      "Error registering cipher: %s.",
      v2);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdecckey.cpp:0x9D14E0
bdCypherAES *__thiscall bdCypherAES::`scalar deleting destructor'(bdCypherAES *this, unsigned int a2)
{
  bdCypherAES::~bdCypherAES(this);
  if ( (a2 & 1) != 0 )
    bdMemory::deallocate(this);
  return this;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdecckey.cpp:0x9D1510
bdMallocMemory::bdMemoryChainElement *__cdecl bdMallocMemory::recordMemory(
        bdMallocMemory::bdMemoryChainElement *link,
        const unsigned int size,
        const bool aligned)
{
  if ( !link )
    return 0;
  bdMutex::lock(&bdMallocMemory::m_mutex);
  link->m_magic = -16963;
  link->m_size = size;
  link->m_aligned = aligned;
  link->m_next = bdMallocMemory::m_memoryChain;
  link->m_prev = 0;
  if ( bdMallocMemory::m_memoryChain )
    bdMallocMemory::m_memoryChain->m_prev = link;
  bdMallocMemory::m_allocatedBytes += size;
  ++bdMallocMemory::m_numAllocations;
  bdMallocMemory::m_memoryChain = link;
  bdMutex::unlock(&bdMallocMemory::m_mutex);
  return link + 1;
}

#endif // __UNIMPLEMENTED__
