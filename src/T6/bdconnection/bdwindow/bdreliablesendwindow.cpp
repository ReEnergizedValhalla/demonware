// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.cpp:0x9CC010
int __cdecl speex_inband_handler(SpeexBits *bits, SpeexCallback *callback_list, void *state)
{
  int v3; // eax
  SpeexCallback *v4; // ecx
  int (__cdecl *func)(SpeexBits *, void *, void *); // edx

  v3 = speex_bits_unpack_unsigned(bits, 4);
  v4 = &callback_list[v3];
  func = v4->func;
  if ( func )
    return func(bits, state, v4->data);
  if ( v3 >= 2 )
  {
    if ( v3 >= 8 )
    {
      if ( v3 >= 10 )
      {
        if ( v3 >= 12 )
          speex_bits_advance(bits, v3 >= 14 ? 64 : 32);
        else
          speex_bits_advance(bits, 16);
        return 0;
      }
      else
      {
        speex_bits_advance(bits, 8);
        return 0;
      }
    }
    else
    {
      speex_bits_advance(bits, 4);
      return 0;
    }
  }
  else
  {
    speex_bits_advance(bits, 1);
    return 0;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.cpp:0x9CC0D0
int __cdecl speex_std_mode_request_handler(SpeexBits *bits, void *state, void *data)
{
  int m; // [esp+0h] [ebp-4h] BYREF

  m = speex_bits_unpack_unsigned(bits, 4);
  speex_encoder_ctl(data, 6, &m);
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.cpp:0x9CC100
int __cdecl speex_std_low_mode_request_handler(SpeexBits *bits, void *state, void *data)
{
  int m; // [esp+0h] [ebp-4h] BYREF

  m = speex_bits_unpack_unsigned(bits, 4);
  speex_encoder_ctl(data, 8, &m);
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.cpp:0x9CC130
int __cdecl speex_std_high_mode_request_handler(SpeexBits *bits, void *state, void *data)
{
  int m; // [esp+0h] [ebp-4h] BYREF

  m = speex_bits_unpack_unsigned(bits, 4);
  speex_encoder_ctl(data, 10, &m);
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.cpp:0x9CC160
int __cdecl speex_std_vbr_request_handler(SpeexBits *bits, void *state, void *data)
{
  int vbr; // [esp+0h] [ebp-4h] BYREF

  vbr = speex_bits_unpack_unsigned(bits, 1);
  speex_encoder_ctl(data, 12, &vbr);
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.cpp:0x9CC190
int __cdecl speex_std_enh_request_handler(SpeexBits *bits, void *state, void *data)
{
  int enh; // [esp+0h] [ebp-4h] BYREF

  enh = speex_bits_unpack_unsigned(bits, 1);
  speex_decoder_ctl(data, 0, &enh);
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.cpp:0x9CC1C0
int __cdecl speex_std_vbr_quality_request_handler(SpeexBits *bits, void *state, void *data)
{
  int qual; // [esp+0h] [ebp-4h] BYREF

  qual = speex_bits_unpack_unsigned(bits, 4);
  speex_encoder_ctl(data, 14, &qual);
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.cpp:0x9CC1F0
int __cdecl speex_std_char_handler(SpeexBits *bits, void *state, void *data)
{
  unsigned __int8 v3; // al

  v3 = speex_bits_unpack_unsigned(bits, 8);
  _speex_putc(v3, data);
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.cpp:0x9CC220
int __cdecl speex_default_user_handler(SpeexBits *bits)
{
  unsigned int v1; // eax

  v1 = speex_bits_unpack_unsigned(bits, 4);
  speex_bits_advance(bits, 8 * v1 + 5);
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.cpp:0x9CC250
void __cdecl FLAC__lpc_compute_autocorrelation_asm_ia32(int a1, int a2, int a3, void *a4)
{
  int v4; // edx

  memset(a4, 0, 4 * a3);
  v4 = -11 * a3 + 10273803;
  if ( a3 == 33 )
    v4 = 10273431;
  __asm { jmp     edx }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.cpp:0x9CC5B0
unsigned int *__cdecl FLAC__lpc_compute_autocorrelation_asm_ia32_sse_lag_4(
        unsigned int *a1,
        int a2,
        int a3,
        __m128 *a4)
{
  unsigned int *result; // eax
  __m128 v5; // xmm2
  __m128 v6; // xmm5
  int v7; // edx
  __m128 v8; // xmm0
  __m128 v9; // xmm0

  result = a1 + 1;
  v5 = (__m128)*a1;
  v6 = _mm_add_ps((__m128)0i64, _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), v5));
  v7 = a2 - 1;
  if ( a2 != 1 )
  {
    do
    {
      v8 = (__m128)*result++;
      v9 = _mm_shuffle_ps(v8, v8, 0);
      v5 = _mm_shuffle_ps(v5, v5, 147);
      v5.m128_f32[0] = v9.m128_f32[0];
      v6 = _mm_add_ps(v6, _mm_mul_ps(v9, v5));
      --v7;
    }
    while ( v7 );
  }
  *a4 = v6;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.cpp:0x9CC610
unsigned int *__cdecl FLAC__lpc_compute_autocorrelation_asm_ia32_sse_lag_8(
        unsigned int *a1,
        int a2,
        int a3,
        __m128 *a4)
{
  unsigned int *result; // eax
  __m128 v5; // xmm2
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  int v10; // edx
  __m128 v11; // xmm0
  __m128 v12; // xmm0

  result = a1 + 1;
  v5 = (__m128)*a1;
  v6 = _mm_shuffle_ps(v5, v5, 0);
  v7 = 0i64;
  v8 = _mm_add_ps((__m128)0i64, _mm_mul_ps(v6, v5));
  v9 = _mm_add_ps((__m128)0i64, _mm_mul_ps(v6, (__m128)0i64));
  v10 = a2 - 1;
  if ( a2 != 1 )
  {
    do
    {
      v11 = (__m128)*result;
      v5 = _mm_shuffle_ps(v5, v5, 147);
      ++result;
      v7 = _mm_shuffle_ps(v7, v7, 147);
      v12 = _mm_shuffle_ps(v11, v11, 0);
      v7.m128_f32[0] = v5.m128_f32[0];
      v5.m128_f32[0] = v12.m128_f32[0];
      v9 = _mm_add_ps(v9, _mm_mul_ps(v12, v7));
      v8 = _mm_add_ps(v8, _mm_mul_ps(v12, v5));
      --v10;
    }
    while ( v10 );
  }
  *a4 = v8;
  a4[1] = v9;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.cpp:0x9CC690
unsigned int *__cdecl FLAC__lpc_compute_autocorrelation_asm_ia32_sse_lag_12(
        unsigned int *a1,
        int a2,
        int a3,
        __m128 *a4)
{
  unsigned int *result; // eax
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  __m128 v7; // xmm3
  __m128 v8; // xmm4
  __m128 v9; // xmm5
  __m128 v10; // xmm6
  __m128 v11; // xmm7
  int v12; // edx
  __m128 v13; // xmm0
  __m128 v14; // xmm0

  result = a1 + 1;
  v5 = (__m128)*a1;
  v6 = _mm_shuffle_ps(v5, v5, 0);
  v7 = 0i64;
  v8 = 0i64;
  v9 = _mm_add_ps((__m128)0i64, _mm_mul_ps(v6, v5));
  v10 = _mm_add_ps((__m128)0i64, _mm_mul_ps(v6, (__m128)0i64));
  v11 = v10;
  v12 = a2 - 1;
  if ( a2 != 1 )
  {
    do
    {
      v13 = (__m128)*result++;
      v14 = _mm_shuffle_ps(v13, v13, 0);
      v5 = _mm_shuffle_ps(v5, v5, 147);
      v7 = _mm_shuffle_ps(v7, v7, 147);
      v8 = _mm_shuffle_ps(v8, v8, 147);
      v8.m128_f32[0] = v7.m128_f32[0];
      v7.m128_f32[0] = v5.m128_f32[0];
      v5.m128_f32[0] = v14.m128_f32[0];
      v9 = _mm_add_ps(v9, _mm_mul_ps(v14, v5));
      v10 = _mm_add_ps(v10, _mm_mul_ps(v14, v7));
      v11 = _mm_add_ps(v11, _mm_mul_ps(v14, v8));
      --v12;
    }
    while ( v12 );
  }
  *a4 = v9;
  a4[1] = v10;
  a4[2] = v11;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.cpp:0x9CC730
int __cdecl FLAC__lpc_compute_autocorrelation_asm_ia32_3dnow(unsigned int *a1, int a2, int a3, int a4)
{
  unsigned int v4; // ecx
  unsigned int v5; // ecx
  unsigned int *v6; // eax
  __m64 v7; // mm0
  __m64 v8; // mm2
  __m64 v9; // mm4
  __m64 v10; // mm6
  signed int v11; // ebx
  __m64 v12; // mm0
  __m64 v13; // mm2
  __m64 v14; // mm4
  __m64 v15; // mm6
  bool v16; // cc
  __m64 v17; // mm3
  __m64 v18; // mm5
  __m64 v19; // mm7
  unsigned int *v20; // ebx
  unsigned int v21; // eax
  unsigned int *v22; // esi
  __m64 v23; // mm0
  unsigned int v24; // ebx
  int v25; // edx
  int result; // eax
  __int64 vars0[2]; // [esp+0h] [ebp+0h]

  v4 = (a3 + 1) & 0xFFFFFFFE;
  do
  {
    --v4;
    *((_DWORD *)vars0 + v4) = 0;
  }
  while ( v4 );
  v5 = (unsigned int)&a1[a2 - ((a3 + 1) & 0xFFFFFFFE) - 3];
  v6 = a1;
  if ( (unsigned int)a1 <= v5 )
  {
    do
    {
      v7 = _mm_cvtsi32_si64(*v6);
      v8 = _mm_cvtsi32_si64(v6[1]);
      v9 = _mm_cvtsi32_si64(v6[2]);
      v10 = _mm_cvtsi32_si64(v6[3]);
      v11 = (a3 + 1) & 0xFFFFFFFE;
      v12 = _m_punpckldq(v7, v7);
      v13 = _m_punpckldq(v8, v8);
      v14 = _m_punpckldq(v9, v9);
      v15 = _m_punpckldq(v10, v10);
      do
      {
        v16 = v11 <= 2;
        v11 -= 2;
        v17 = _mm_cvtsi32_si64(v6[v11 + 1]);
        v18 = _mm_cvtsi32_si64(v6[v11 + 2]);
        v19 = _mm_cvtsi32_si64(v6[v11 + 3]);
        *(__int64 *)((char *)vars0 + 4 * v11) = (__int64)_m_pfadd(
                                                           *(__m64 *)((char *)vars0 + 4 * v11),
                                                           _m_pfadd(
                                                             _m_pfadd(
                                                               _m_pfmul(
                                                                 _m_punpckldq(_mm_cvtsi32_si64(v6[v11]), v17),
                                                                 v12),
                                                               _m_pfmul(_m_punpckldq(v17, v18), v13)),
                                                             _m_pfadd(
                                                               _m_pfmul(_m_punpckldq(v18, v19), v14),
                                                               _m_pfmul(_m_punpckldq(v19, (__m64)v6[v11 + 4]), v15))));
      }
      while ( !v16 );
      v6 += 4;
    }
    while ( (unsigned int)v6 < v5 );
  }
  v20 = v6;
  v21 = (unsigned int)((char *)v6 - (char *)a1) >> 2;
  v22 = v20;
  do
  {
    v23 = _mm_cvtsi32_si64(*v22);
    v24 = a2 - v21;
    if ( a2 - v21 > ((a3 + 1) & 0xFFFFFFFE) )
      v24 = (a3 + 1) & 0xFFFFFFFE;
    do
    {
      --v24;
      *((_DWORD *)vars0 + v24) = _mm_cvtsi64_si32(
                                   _m_pfadd(
                                     _m_pfmul(_mm_cvtsi32_si64(v22[v24]), v23),
                                     _mm_cvtsi32_si64(*((_DWORD *)vars0 + v24))));
    }
    while ( v24 );
    ++v22;
    ++v21;
  }
  while ( v22 != &a1[a2] );
  v25 = a3;
  do
  {
    --v25;
    result = *((_DWORD *)vars0 + v25);
    *(_DWORD *)(a4 + 4 * v25) = result;
  }
  while ( v25 );
  _m_femms();
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.cpp:0x9CC840
int __cdecl FLAC__lpc_compute_residual_from_qlp_coefficients_asm_ia32(
        int *a1,
        int a2,
        int *a3,
        int a4,
        char a5,
        _DWORD *a6)
{
  int *v6; // esi
  int result; // eax
  int v9; // ebx
  int v10; // edx
  int v11; // ebp
  int *v12; // edx
  int v13; // ecx

  v6 = a1;
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
          result = v6[v13] * *--v12;
          v11 += result;
          ++v13;
        }
        while ( v13 );
        *a6++ = *v6++ - (v11 >> a5);
        --v9;
      }
      while ( v9 );
    }
    else
    {
      v10 = *a3;
      result = *(a1 - 1);
      do
      {
        *a6 = *v6 - ((v10 * result) >> a5);
        result = *v6;
        ++a6;
        ++v6;
        --v9;
      }
      while ( v9 );
    }
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.cpp:0x9CCA30
unsigned int __cdecl FLAC__lpc_compute_residual_from_qlp_coefficients_asm_ia32_mmx(
        unsigned int *a1,
        int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        _DWORD *a6)
{
  unsigned int *v6; // esi
  unsigned int result; // eax
  int v9; // ebx
  __m64 v10; // mm6
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  __m64 v14; // mm5
  __m64 v15; // mm4
  __m64 v16; // mm3
  __m64 v17; // mm1
  __m64 v18; // mm2
  __m64 v19; // mm4
  __m64 v20; // mm2
  __m64 v21; // mm0
  __m64 v22; // mm1
  bool v23; // cc
  int v24; // eax
  __m64 v25; // mm1
  __m64 v26; // mm3
  __m64 v27; // mm2
  __m64 v28; // mm4
  __m64 v29; // mm3
  __m64 v30; // mm2
  unsigned int *v31; // ecx
  __m64 *v32; // edx
  __m64 v33; // mm7
  __m64 v34; // mm1
  _WORD v36[10]; // [esp+8h] [ebp-14h] BYREF

  v6 = a1;
  result = a4;
  if ( a2 )
  {
    v9 = a2 - 1;
    if ( a2 != 1 )
    {
      v10 = _mm_cvtsi32_si64(a5);
      v11 = 0;
      do
        v36[1] = *(_WORD *)(a3 + 4 * v11++);
      while ( v11 != a4 );
      v12 = v11 & 3;
      if ( v12 )
      {
        v13 = v12 - 4;
        do
        {
          v36[0] = 0;
          ++result;
          ++v13;
        }
        while ( v13 );
      }
      v14.m64_u64 = *(_QWORD *)&v36[result - 4];
      v15 = _m_packssdw(
              _m_punpckldq(_mm_cvtsi32_si64(*(a1 - 4)), (__m64)*(a1 - 3)),
              _m_punpckldq(_mm_cvtsi32_si64(*(a1 - 2)), (__m64)*(a1 - 1)));
      if ( result > 4 )
      {
        v24 = -4 * result + 16;
        do
        {
          v25 = _m_punpckldq(_mm_cvtsi32_si64(*v6), (__m64)v6[1]);
          v26 = v15;
          v27 = _m_por(_m_psrlqi(v15, 0x10u), _m_psllqi(v25, 0x30u));
          v28 = _m_psrlqi(v27, 0x10u);
          v29 = _m_pmaddwd(v26, v14);
          v30 = _m_pmaddwd(v27, v14);
          v15 = _m_por(v28, _m_psllqi(_m_punpckhdq(0i64, v25), 0x10u));
          v31 = (unsigned int *)((char *)v6 + v24);
          v32 = (__m64 *)v36;
          do
          {
            v33 = _m_punpckldq(_mm_cvtsi32_si64(*(v31 - 2)), (__m64)*(v31 - 1));
            v29 = _m_paddd(
                    v29,
                    _m_pmaddwd(
                      _m_packssdw(_m_punpckldq(_mm_cvtsi32_si64(*(v31 - 4)), (__m64)*(v31 - 3)), v33),
                      (__m64)v32->m64_u64));
            v30 = _m_paddd(
                    v30,
                    _m_pmaddwd(
                      _m_packssdw(
                        _m_punpckldq(_mm_cvtsi32_si64(*(v31 - 3)), (__m64)*(v31 - 2)),
                        _m_punpckldq(_m_punpckhdq(v33, v33), (__m64)*v31)),
                      (__m64)v32->m64_u64));
            ++v32;
            v31 += 4;
          }
          while ( v31 != v6 );
          v34 = _m_psubd(v25, _m_psrad(_m_paddd(_m_punpckldq(v29, v30), _m_punpckhdq(v29, v30)), v10));
          *a6 = _mm_cvtsi64_si32(v34);
          a6[1] = _mm_cvtsi64_si32(_m_punpckhdq(v34, v34));
          a6 += 2;
          v6 += 2;
          v23 = v9 <= 2;
          v9 -= 2;
        }
        while ( !v23 );
      }
      else
      {
        do
        {
          v16 = v15;
          v17 = _m_punpckldq(_mm_cvtsi32_si64(*v6), (__m64)v6[1]);
          v18 = _m_por(_m_psrlqi(v15, 0x10u), _m_psllqi(v17, 0x30u));
          v19 = _m_psrlqi(v18, 0x10u);
          v20 = _m_pmaddwd(v18, v14);
          v15 = _m_por(v19, _m_psllqi(_m_punpckhdq(0i64, v17), 0x10u));
          v21 = _m_pmaddwd(v16, v14);
          v22 = _m_psubd(v17, _m_psrad(_m_paddd(_m_punpckldq(v21, v20), _m_punpckhdq(v21, v20)), v10));
          *a6 = _mm_cvtsi64_si32(v22);
          a6[1] = _mm_cvtsi64_si32(_m_punpckhdq(v22, v22));
          a6 += 2;
          v6 += 2;
          v23 = v9 <= 2;
          v9 -= 2;
        }
        while ( !v23 );
      }
      _m_empty();
    }
    result = a3;
    if ( v9 != -1 )
      JUMPOUT(0x9CC85C);
  }
  return result;
}

#endif // __UNIMPLEMENTED__
