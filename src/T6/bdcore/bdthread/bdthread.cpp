// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdthread.cpp:0x9D0FD0
char __thiscall bdCypher3Des::encrypt(
        bdCypher3Des *this,
        const unsigned __int8 *iv,
        const unsigned __int8 *pt,
        unsigned __int8 *ct,
        unsigned int size)
{
  symmetric_CBC *p_m_cbc; // edi
  int v6; // esi
  const char *v7; // eax
  int v9; // esi
  const char *v10; // eax

  p_m_cbc = &this->m_cbc;
  v6 = cbc_setiv(iv, 8u, &this->m_cbc);
  if ( v6 )
  {
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "cypher3DES",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdCypher3Des.cpp",
      "bdCypher3Des::encrypt",
      0x3Cu,
      "Failed to set IV seed");
    v7 = error_to_string(v6);
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "cypher3DES",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdCypher3Des.cpp",
      "bdCypher3Des::encrypt",
      0x3Du,
      "> %s",
      v7);
    return 0;
  }
  else
  {
    v9 = cbc_encrypt(pt, ct, size, p_m_cbc);
    if ( v9 )
    {
      bdLogMessage(
        BD_LOG_ERROR,
        "err/",
        "cypher3DES",
        "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdCypher3Des.cpp",
        "bdCypher3Des::encrypt",
        0x4Au,
        "Error encrypting ");
      v10 = error_to_string(v9);
      bdLogMessage(
        BD_LOG_ERROR,
        "err/",
        "cypher3DES",
        "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdCypher3Des.cpp",
        "bdCypher3Des::encrypt",
        0x4Bu,
        "> %s",
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

// bdthread.cpp:0x9D10C0
char __thiscall bdCypher3Des::decrypt(
        bdCypher3Des *this,
        const unsigned __int8 *iv,
        const unsigned __int8 *ct,
        unsigned __int8 *pt,
        unsigned int size)
{
  symmetric_CBC *p_m_cbc; // edi
  int v6; // esi
  const char *v7; // eax

  p_m_cbc = &this->m_cbc;
  v6 = cbc_setiv(iv, 8u, &this->m_cbc);
  if ( v6 )
  {
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "cypher3DES",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdCypher3Des.cpp",
      "bdCypher3Des::decrypt",
      0x5Cu,
      "Failed to set IV seed");
    v7 = error_to_string(v6);
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "cypher3DES",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdCypher3Des.cpp",
      "bdCypher3Des::decrypt",
      0x5Du,
      "> %s",
      v7);
    return 0;
  }
  else if ( cbc_decrypt(ct, pt, size, p_m_cbc) )
  {
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "cypher3DES",
      "c:\\t6\\code\\DemonWare\\bdCore\\bdCrypto\\bdCypher3Des.cpp",
      "bdCypher3Des::decrypt",
      0x68u,
      "Error decrypting.");
    return 0;
  }
  else
  {
    return 1;
  }
}

#endif // __UNIMPLEMENTED__
