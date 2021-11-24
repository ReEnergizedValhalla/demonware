// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CCF00
int __cdecl FLAC__bitreader_read_rice_signed_block_asm_ia32_bswap(_DWORD *a1, int *a2, int a3, unsigned int a4)
{
  int result; // eax
  unsigned int v5; // esi
  unsigned int v6; // ecx
  int v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // ebx
  int v10; // ebx
  unsigned int v11; // edi
  unsigned __int32 v12; // edx
  int v13; // ecx
  int v14; // eax
  unsigned __int32 v15; // edx
  unsigned __int32 v16; // edx
  unsigned __int32 v17; // edx
  int v18; // ecx
  int v19; // eax
  int v20; // edx
  unsigned int v21; // ebx
  int v22; // edx
  unsigned int v23; // eax
  unsigned int v24; // ebx
  int v25; // ebx
  int v26; // edx
  unsigned int v27; // edx
  char v28; // al
  unsigned int v29; // ecx
  unsigned __int32 v30; // edx
  int v31; // ecx
  int v32; // eax
  unsigned __int32 v33; // edx
  __int64 v34; // rt0
  __int64 v35; // rt0
  unsigned int v36; // [esp-Ch] [ebp-20h]
  int v37; // [esp-4h] [ebp-18h]
  unsigned int v38; // [esp-4h] [ebp-18h]
  unsigned int v39; // [esp-4h] [ebp-18h]
  unsigned int v40; // [esp-4h] [ebp-18h]
  unsigned int v41; // [esp+0h] [ebp-14h]
  unsigned int v42; // [esp+0h] [ebp-14h]

  if ( !a3 )
    return 1;
  v5 = a1[4];
  v6 = a1[5];
  v7 = 0;
  v41 = 8 * (a1[3] + 4 * (a1[2] - v5)) - v6;
  while ( 1 )
  {
    while ( 1 )
    {
      for ( ; v5 < a1[2]; v6 = 0 )
      {
        v8 = *(_DWORD *)(*a1 + 4 * v5);
        if ( v8 << v6 )
        {
          _BitScanReverse(&v9, v8 << v6);
          v10 = ~(_BYTE)v9 & 0x1F;
          v11 = v10 + v7;
          v6 += v10 + 1;
          if ( (v6 & 0xFFFFFFE0) == 0 )
            goto LABEL_29;
          v12 = _byteswap_ulong(v8);
          v13 = a1[7];
          v14 = a1[6];
          if ( !v13 )
          {
            LOBYTE(v12) = BYTE1(v14) ^ v12;
            v14 = FLAC__crc16_table[(unsigned __int8)v12] ^ (v14 << 8);
            goto LABEL_9;
          }
          a1[7] = 0;
          if ( v13 == 8 )
          {
LABEL_9:
            BYTE1(v12) ^= BYTE1(v14);
            v14 = FLAC__crc16_table[BYTE1(v12)] ^ (v14 << 8);
            v15 = HIWORD(v12);
          }
          else
          {
            v15 = HIWORD(v12);
            if ( v13 != 16 )
            {
LABEL_11:
              a1[6] = (unsigned __int16)(FLAC__crc16_table[(unsigned __int8)(BYTE1(v14) ^ BYTE1(v15))] ^ ((_WORD)v14 << 8));
              ++v5;
              v6 = 0;
              goto LABEL_29;
            }
          }
          v14 = FLAC__crc16_table[(unsigned __int8)(BYTE1(v14) ^ v15)] ^ (v14 << 8);
          goto LABEL_11;
        }
        v37 = v7 + 32 - v6;
        v17 = _byteswap_ulong(v8);
        v18 = a1[7];
        v19 = a1[6];
        if ( v18 )
        {
          a1[7] = 0;
          if ( v18 != 8 )
          {
            v16 = HIWORD(v17);
            if ( v18 != 16 )
              goto LABEL_22;
            goto LABEL_21;
          }
        }
        else
        {
          LOBYTE(v17) = BYTE1(v19) ^ v17;
          v19 = FLAC__crc16_table[(unsigned __int8)v17] ^ (v19 << 8);
        }
        BYTE1(v17) ^= BYTE1(v19);
        v19 = FLAC__crc16_table[BYTE1(v17)] ^ (v19 << 8);
        v16 = HIWORD(v17);
LABEL_21:
        v19 = FLAC__crc16_table[(unsigned __int8)(BYTE1(v19) ^ v16)] ^ (v19 << 8);
LABEL_22:
        a1[6] = (unsigned __int16)(FLAC__crc16_table[(unsigned __int8)(BYTE1(v19) ^ BYTE1(v16))] ^ ((_WORD)v19 << 8));
        v7 = v37;
        ++v5;
      }
      v20 = a1[3];
      if ( v20 )
        break;
LABEL_27:
      a1[4] = v5;
      a1[5] = v6;
      v38 = v6;
      result = bitreader_read_from_client_((int)a1);
      v6 = v38;
      v5 = a1[4];
      v41 = v7 + 8 * (a1[3] + 4 * (a1[2] - v5)) - v38;
      if ( !result )
        return result;
    }
    v21 = ~(0xFFFFFFFF >> (8 * v20));
    v22 = 8 * v20;
    v23 = (v21 & *(_DWORD *)(*a1 + 4 * v5)) << v6;
    if ( !v23 )
    {
      v7 = v22 + v7 - v6;
      v6 += v22;
      goto LABEL_27;
    }
    _BitScanReverse(&v24, v23);
    v25 = ~(_BYTE)v24 & 0x1F;
    v11 = v25 + v7;
    v6 += v25 + 1;
LABEL_29:
    v42 = v41 - v11 - 1;
    if ( a4 )
    {
      while ( v42 < a4 )
      {
        a1[4] = v5;
        a1[5] = v6;
        v39 = v6;
        result = bitreader_read_from_client_((int)a1);
        v6 = v39;
        v5 = a1[4];
        v42 = 8 * (a1[3] + 4 * (a1[2] - v5)) - v39;
        if ( !result )
          return result;
      }
      if ( v5 >= a1[2] )
      {
        v11 = __PAIR64__(v11, *(_DWORD *)(*a1 + 4 * v5) << v6) << a4 >> 32;
        v6 += a4;
        goto LABEL_48;
      }
      if ( !v6 )
      {
        v6 = a4;
        HIDWORD(v35) = v11;
        LODWORD(v35) = *(_DWORD *)(*a1 + 4 * v5);
        v11 = (unsigned __int64)(v35 << a4) >> 32;
        goto LABEL_48;
      }
      v26 = *(_DWORD *)(*a1 + 4 * v5);
      if ( a4 < 32 - v6 )
      {
        v11 = __PAIR64__(v11, v26 << v6) << a4 >> 32;
        v6 += a4;
        goto LABEL_48;
      }
      v27 = __ROL4__(v26, v6);
      v28 = v6;
      v29 = 32 - v6;
      v40 = __PAIR64__(v11, v27) << v29 >> 32;
      v36 = v29;
      v30 = _byteswap_ulong(__ROR4__(v27, v28));
      v31 = a1[7];
      v32 = a1[6];
      if ( !v31 )
      {
        LOBYTE(v30) = BYTE1(v32) ^ v30;
        v32 = FLAC__crc16_table[(unsigned __int8)v30] ^ (v32 << 8);
        goto LABEL_39;
      }
      a1[7] = 0;
      if ( v31 == 8 )
      {
LABEL_39:
        BYTE1(v30) ^= BYTE1(v32);
        v32 = FLAC__crc16_table[BYTE1(v30)] ^ (v32 << 8);
        v33 = HIWORD(v30);
      }
      else
      {
        v33 = HIWORD(v30);
        if ( v31 != 16 )
        {
LABEL_41:
          a1[6] = (unsigned __int16)(FLAC__crc16_table[(unsigned __int8)(BYTE1(v32) ^ BYTE1(v33))] ^ ((_WORD)v32 << 8));
          v11 = v40;
          ++v5;
          v6 = a4 - v36;
          if ( a4 != v36 )
          {
            HIDWORD(v34) = v40;
            LODWORD(v34) = *(_DWORD *)(*a1 + 4 * v5);
            v11 = (unsigned __int64)(v34 << v6) >> 32;
          }
          goto LABEL_48;
        }
      }
      v32 = FLAC__crc16_table[(unsigned __int8)(BYTE1(v32) ^ v33)] ^ (v32 << 8);
      goto LABEL_41;
    }
LABEL_48:
    v41 = v42 - a4;
    *a2 = -(v11 & 1) ^ (v11 >> 1);
    if ( !--a3 )
      break;
    v7 = 0;
    ++a2;
  }
  a1[4] = v5;
  a1[5] = v6;
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD260
BOOL FLAC__cpu_have_cpuid_asm_ia32()
{
  unsigned int v0; // kr00_4
  unsigned int v1; // kr04_4

  v0 = __readeflags();
  __writeeflags(v0 ^ 0x200000);
  v1 = __readeflags();
  return v1 != v0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD280
int __cdecl FLAC__cpu_info_asm_ia32(_DWORD *a1, _DWORD *a2)
{
  int result; // eax

  if ( FLAC__cpu_have_cpuid_asm_ia32() )
  {
    _EAX = 1;
    __asm { cpuid }
    *a1 = _EDX;
    *a2 = _ECX;
  }
  else
  {
    result = 0;
    *a1 = 0;
    *a2 = 0;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD2B2
int FLAC__cpu_info_extended_amd_asm_ia32()
{
  if ( !FLAC__cpu_have_cpuid_asm_ia32() )
    return 0;
  _EAX = 0x80000000;
  __asm { cpuid }
  if ( _EAX < 0x80000001 )
    return 0;
  _EAX = -2147483647;
  __asm { cpuid }
  return _EDX;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD2E0
int __cdecl bdMemcmp(const void *const s1, const void *const s2, const unsigned int len)
{
  unsigned int v5; // esi
  int v6; // eax

  v5 = len;
  if ( len < 4 )
  {
LABEL_4:
    if ( !v5 )
      return 0;
  }
  else
  {
    while ( *(_DWORD *)s1 == *(_DWORD *)s2 )
    {
      v5 -= 4;
      s2 = (char *)s2 + 4;
      s1 = (char *)s1 + 4;
      if ( v5 < 4 )
        goto LABEL_4;
    }
  }
  v6 = *(unsigned __int8 *)s1 - *(unsigned __int8 *)s2;
  if ( v6 )
    return (v6 >> 31) | 1;
  if ( v5 <= 1 )
    return 0;
  v6 = *((unsigned __int8 *)s1 + 1) - *((unsigned __int8 *)s2 + 1);
  if ( v6 )
    return (v6 >> 31) | 1;
  if ( v5 <= 2 )
    return 0;
  v6 = *((unsigned __int8 *)s1 + 2) - *((unsigned __int8 *)s2 + 2);
  if ( v6 )
    return (v6 >> 31) | 1;
  if ( v5 > 3 )
  {
    v6 = *((unsigned __int8 *)s1 + 3) - *((unsigned __int8 *)s2 + 3);
    return (v6 >> 31) | 1;
  }
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD360
void __thiscall bdSecurityKey::bdSecurityKey(bdSecurityKey *this)
{
  *(_DWORD *)this->ab = (char *)&g_sd.voiceDecodeBuffer[807744] + 1;
  *(_DWORD *)&this->ab[4] = (char *)&g_sd.voiceDecodeBuffer[807744] + 1;
  *(_DWORD *)&this->ab[8] = (char *)&g_sd.voiceDecodeBuffer[807744] + 1;
  *(_DWORD *)&this->ab[12] = (char *)&g_sd.voiceDecodeBuffer[807744] + 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD380
void __thiscall bdSecurityKey::bdSecurityKey(bdSecurityKey *this, const bdSecurityKey *other)
{
  *this = *other;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD3B0
void __thiscall bdSecurityID::bdSecurityID(bdSecurityID *this)
{
  *(_DWORD *)this->ab = (char *)&g_sd.voiceDecodeBuffer[807744] + 1;
  *(_DWORD *)&this->ab[4] = (char *)&g_sd.voiceDecodeBuffer[807744] + 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD3C0
void __thiscall bdSecurityID::bdSecurityID(bdSecurityID *this, const bdSecurityID *other)
{
  *this = *other;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD3E0
bool __thiscall bdSecurityID::operator==(bdSecurityID *this, const bdSecurityID *other)
{
  unsigned int v3; // esi

  v3 = 8;
  while ( *(_DWORD *)this->ab == *(_DWORD *)other->ab )
  {
    v3 -= 4;
    other = (const bdSecurityID *)((char *)other + 4);
    this = (bdSecurityID *)((char *)this + 4);
    if ( v3 < 4 )
    {
      if ( !v3 )
        return 1;
      break;
    }
  }
  return this->ab[0] == other->ab[0]
      && (v3 <= 1 || this->ab[1] == other->ab[1] && (v3 <= 2 || this->ab[2] == other->ab[2] && v3 <= 3));
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD470
void __thiscall bdAddr::bdAddr(bdAddr *this)
{
  bdInetAddr::bdInetAddr(&this->m_address);
  this->m_port = 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD490
void __thiscall bdAddr::bdAddr(bdAddr *this, const bdAddr *other)
{
  bdInetAddr::bdInetAddr(&this->m_address, &other->m_address);
  this->m_port = other->m_port;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD4B0
void __thiscall bdAddr::bdAddr(bdAddr *this, const bdInetAddr *address, const unsigned __int16 port)
{
  bdInetAddr::bdInetAddr(&this->m_address, address);
  this->m_port = port;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD4D0
void __thiscall bdAddr::set(bdAddr *this, const bdInetAddr *address, const unsigned __int16 port)
{
  bdInetAddr::set(&this->m_address, address);
  this->m_port = port;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD4F0
BOOL __thiscall bdAddr::operator==(bdAddr *this, const bdAddr *other)
{
  return this->m_port == other->m_port && bdSequenceNumber::operator==(&this->m_address, &other->m_address);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD520
void __thiscall bdAddr::setPort(bdAddr *this, const unsigned __int16 port)
{
  this->m_port = port;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD530
unsigned __int16 __thiscall bdAddr::getPort(bdAddr *this)
{
  return this->m_port;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD540
bool __cdecl bdBytePacker::removeBasicType<unsigned short>(
        const void *buffer,
        const unsigned int bufferSize,
        const unsigned int offset,
        unsigned int *newOffset,
        unsigned __int16 *var)
{
  bool result; // al
  unsigned __int16 nvar; // [esp+0h] [ebp-4h] BYREF

  result = bdBytePacker::removeBuffer(buffer, bufferSize, offset, newOffset, &nvar, 2u);
  if ( result )
    *var = nvar;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD580
int bdSnprintf(char *buf, const unsigned int maxlen, const char *format, ...)
{
  int v3; // edi
  va_list ap; // [esp+1Ch] [ebp+14h] BYREF

  va_start(ap, format);
  v3 = _vscprintf(format, ap);
  vsnprintf_s(buf, maxlen, 0xFFFFFFFF, format, ap);
  return v3;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddatachunk.cpp:0x9CD5C0
void __thiscall bdAddr::set(bdAddr *this, const char *socketAddress)
{
  int v3; // eax
  int v4; // ebx
  unsigned int v5; // esi
  unsigned int v6; // eax
  int v7; // eax
  bdInAddr::<unnamed_type_inUn> inUn; // esi
  bdSecurityKeyMapListener **v9; // eax
  bdInAddr v10; // [esp+10h] [ebp-28h] BYREF
  bdInetAddr address; // [esp+14h] [ebp-24h] BYREF
  char strAddr[16]; // [esp+18h] [ebp-20h] BYREF
  int v13; // [esp+34h] [ebp-4h]

  address = (bdInetAddr)this;
  strchr((unsigned __int8 *)socketAddress, 0x3Au);
  v4 = v3;
  if ( v3 )
  {
    v5 = v3 - (_DWORD)socketAddress + 1;
    v6 = 16;
    if ( v5 <= 0x10 )
      v6 = v4 - (_DWORD)socketAddress + 1;
    memcpy((unsigned __int8 *)strAddr, (unsigned __int8 *)socketAddress, v6);
    v7 = 15;
    if ( v5 <= 0x10 )
      v7 = v4 - (_DWORD)socketAddress;
    strAddr[v7] = 0;
    bdInAddr::bdInAddr(&v10, strAddr);
    inUn = address.m_addr.inUn;
    bdInetAddr::set((bdSecurityKeyMap *)address.m_addr.inUn.m_iaddr, *v9);
    *(_WORD *)(inUn.m_iaddr + 4) = strtoul((const char *)(v4 + 1), 0, 10);
  }
  else
  {
    bdInetAddr::bdInetAddr(&address, socketAddress);
    v13 = 0;
    bdAddr::set(this, &address, 0);
    v13 = -1;
    bdInetAddr::~bdInetAddr(&address);
  }
}

#endif // __UNIMPLEMENTED__
