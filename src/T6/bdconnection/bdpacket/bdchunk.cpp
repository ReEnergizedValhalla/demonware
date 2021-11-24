// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdchunk.cpp:0x9CFC80
void __cdecl bdCryptoUtils::encrypt(
        const void *key,
        const void *initialVector,
        const void *source,
        void *dest,
        const unsigned int size)
{
  bdCypher3Des v5; // [esp+14h] [ebp-10E4h] BYREF
  int v6; // [esp+10F4h] [ebp-4h]

  bdCypher3Des::bdCypher3Des(&v5);
  v6 = 0;
  bdCypher3Des::init(&v5, (const unsigned __int8 *)key, 0x18u);
  bdCypher3Des::encrypt(
    &v5,
    (const unsigned __int8 *)initialVector,
    (const unsigned __int8 *)source,
    (unsigned __int8 *)dest,
    size);
  v6 = -1;
  bdCypher3Des::~bdCypher3Des(&v5);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdchunk.cpp:0x9CFD30
void __cdecl bdCryptoUtils::decrypt(
        const void *key,
        const void *initialVector,
        const void *source,
        void *dest,
        const unsigned int size)
{
  bdCypher3Des v5; // [esp+14h] [ebp-10E4h] BYREF
  int v6; // [esp+10F4h] [ebp-4h]

  bdCypher3Des::bdCypher3Des(&v5);
  v6 = 0;
  bdCypher3Des::init(&v5, (const unsigned __int8 *)key, 0x18u);
  bdCypher3Des::decrypt(
    &v5,
    (const unsigned __int8 *)initialVector,
    (const unsigned __int8 *)source,
    (unsigned __int8 *)dest,
    size);
  v6 = -1;
  bdCypher3Des::~bdCypher3Des(&v5);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdchunk.cpp:0x9CFDE0
bool __cdecl bdCryptoUtils::decryptAES(
        const void *key,
        const void *initialVector,
        const void *source,
        void *dest,
        unsigned int size)
{
  bool v5; // bl
  bdCypherAES v7; // [esp+14h] [ebp-10E4h] BYREF
  int v8; // [esp+10F4h] [ebp-4h]

  if ( (size & 0xF) != 0 )
  {
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "bdCryptoUtils",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdCryptoUtils.cpp",
      "bdCryptoUtils::decryptAES",
      0x6Cu,
      "Source data length must be a multiple of 16 for AES");
    return 0;
  }
  else
  {
    bdCypherAES::bdCypherAES(&v7);
    v8 = 0;
    bdCypherAES::init(&v7, (const unsigned __int8 *)key, 0x18u);
    v5 = bdCypherAES::decrypt(
           &v7,
           (const unsigned __int8 *)initialVector,
           (const unsigned __int8 *)source,
           (unsigned __int8 *)dest,
           size);
    v8 = -1;
    bdCypherAES::~bdCypherAES(&v7);
    return v5;
  }
}

#endif // __UNIMPLEMENTED__
