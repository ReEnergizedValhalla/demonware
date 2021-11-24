// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdunreliablesendwindow.cpp:0x9CCBE0
int __cdecl FLAC__lpc_restore_signal_asm_ia32(_DWORD *a1, int a2, int *a3, int a4, char a5, int *a6)
{
  int *v7; // edi
  int result; // eax
  int v9; // ebx
  int v10; // edx
  int v11; // ebp
  int *v12; // edx
  int v13; // ecx

  v7 = a6;
  result = a4;
  v9 = a2;
  if ( a2 )
  {
    if ( a4 > 1 )
    {
      if ( (unsigned int)a4 <= 0x20 )
        __asm { jmp     edx }
      do
      {
        v11 = 0;
        v12 = &a3[a4];
        v13 = -a4;
        do
        {
          result = v7[v13] * *--v12;
          v11 += result;
          ++v13;
        }
        while ( v13 );
        *v7++ = *a1++ + (v11 >> a5);
        --v9;
      }
      while ( v9 );
    }
    else
    {
      v10 = *a3;
      result = *(a6 - 1);
      do
      {
        result = *a1 + ((v10 * result) >> a5);
        *v7 = result;
        ++a1;
        ++v7;
        --v9;
      }
      while ( v9 );
    }
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunreliablesendwindow.cpp:0x9CCDD0
unsigned int __cdecl FLAC__lpc_restore_signal_asm_ia32_mmx(
        unsigned int *a1,
        int a2,
        int a3,
        unsigned int a4,
        unsigned int a5,
        _DWORD *a6)
{
  _DWORD *v7; // edi
  unsigned int result; // eax
  int v9; // ebx
  __m64 v10; // mm6
  int i; // ecx
  int v12; // ecx
  int v13; // ecx
  __m64 v14; // mm5
  __m64 v15; // mm4
  __m64 v16; // mm0
  __m64 v17; // mm7
  _DWORD *v18; // ecx
  __m64 *v19; // edx
  __m64 v20; // mm7
  __m64 v21; // mm7
  _WORD v23[10]; // [esp+8h] [ebp-14h] BYREF

  v7 = a6;
  result = a4;
  v9 = a2;
  if ( a2 )
  {
    if ( a4 < 4 )
      JUMPOUT(0x9CCBFC);
    v10 = _mm_cvtsi32_si64(a5);
    for ( i = 0; i != a4; ++i )
      v23[1] = *(_WORD *)(a3 + 4 * i);
    v12 = i & 3;
    if ( v12 )
    {
      v13 = v12 - 4;
      do
      {
        v23[0] = 0;
        ++result;
        ++v13;
      }
      while ( v13 );
    }
    v14.m64_u64 = *(_QWORD *)&v23[result - 4];
    v15 = _m_packssdw(
            _m_punpckldq(_mm_cvtsi32_si64(*(a6 - 4)), (__m64)(unsigned int)*(a6 - 3)),
            _m_punpckldq(_mm_cvtsi32_si64(*(a6 - 2)), (__m64)(unsigned int)*(a6 - 1)));
    if ( result > 4 )
    {
      result = -4 * result + 16;
      do
      {
        v18 = (_DWORD *)((char *)v7 + result);
        v19 = (__m64 *)v23;
        v20 = _m_pmaddwd(v15, v14);
        do
        {
          v20 = _m_paddd(
                  v20,
                  _m_pmaddwd(
                    _m_packssdw(
                      _m_punpckldq(_mm_cvtsi32_si64(*(v18 - 4)), (__m64)(unsigned int)*(v18 - 3)),
                      _m_punpckldq(_mm_cvtsi32_si64(*(v18 - 2)), (__m64)(unsigned int)*(v18 - 1))),
                    (__m64)v19->m64_u64));
          ++v19;
          v18 += 4;
        }
        while ( v18 != v7 );
        v21 = _m_paddd(_m_psrad(_m_paddd(_m_punpckhdq(v20, v20), v20), v10), _mm_cvtsi32_si64(*a1));
        *v7 = _mm_cvtsi64_si32(v21);
        v15 = _m_por(_m_psrlqi(v15, 0x10u), _m_psllqi(v21, 0x30u));
        ++a1;
        ++v7;
        --v9;
      }
      while ( v9 );
    }
    else
    {
      do
      {
        v16 = _m_pmaddwd(v15, v14);
        v17 = _m_paddd(_m_psrad(_m_paddd(_m_punpckhdq(v16, v16), v16), v10), _mm_cvtsi32_si64(*a1));
        *v7 = _mm_cvtsi64_si32(v17);
        v15 = _m_por(_m_psrlqi(v15, 0x10u), _m_psllqi(v17, 0x30u));
        ++a1;
        ++v7;
        --v9;
      }
      while ( v9 );
    }
    _m_empty();
  }
  return result;
}

#endif // __UNIMPLEMENTED__
