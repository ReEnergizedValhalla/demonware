// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdanticheatresponses.cpp:0x93ACC0
void __usercall BG_PlayerAnimation_VerifyAnim(lerpFrame_t *lf@<esi>, XAnimTree_s *pAnimTree)
{
  int animationNumber; // eax

  BG_CheckThread();
  if ( !*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp", 4304, 0, "(bgs)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  animationNumber = lf->animationNumber;
  if ( animationNumber )
  {
    if ( XAnimGetWeight(pAnimTree, animationNumber & 0xFFFFFBFF) == 0.0 )
    {
      lf->animationNumber = 0;
      lf->animation = 0;
      lf->animationTime = 167;
    }
  }
  else if ( lf->animation
         && !Assert_MyHandler(
               "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
               4320,
               0,
               "(!lf->animation)",
               (const char *)&pBlock) )
  {
    __debugbreak();
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdanticheatresponses.cpp:0x93AD70
void __usercall BG_SwingAngles(
        int *swinging@<esi>,
        float destination,
        float swingTolerance,
        float clampTolerance,
        float speed,
        float *angle)
{
  unsigned int v6; // edi
  __m128 v7; // xmm0
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  float v13; // xmm0_4
  __m128 v14; // xmm3
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  bool v23; // cf
  __m128 v24; // xmm3
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm4
  __m128 v28; // xmm2
  __m128 v29; // xmm3
  float v30; // xmm0_4

  BG_CheckThread();
  v6 = _tls_index;
  if ( !*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp", 4348, 0, "(bgs)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !*swinging )
  {
    v7 = (__m128)*(unsigned int *)angle;
    v8.m128_f32[0] = FLOAT_8388608_0;
    v7.m128_f32[0] = (float)(v7.m128_f32[0] - destination) * 0.0027777778;
    v9 = v7;
    v9.m128_f32[0] = v7.m128_f32[0] + 0.5;
    v10 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v9);
    v8.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v9, v10), v8).m128_u32[0] | v10.m128_i32[0];
    v11 = v9;
    v11.m128_f32[0] = (float)((float)(v7.m128_f32[0] + 0.5) + v8.m128_f32[0]) - v8.m128_f32[0];
    v12 = v11;
    v12.m128_f32[0] = v11.m128_f32[0] - (float)(v7.m128_f32[0] + 0.5);
    v13 = (float)(v7.m128_f32[0]
                - (float)(v11.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v12, v10).m128_u32[0] & FLOAT_1_0)))
        * 360.0;
    if ( v13 <= swingTolerance && COERCE_FLOAT(LODWORD(swingTolerance) ^ _mask__NegFloat_) <= v13 )
      return;
    *swinging = 1;
  }
  v14.m128_f32[0] = FLOAT_8388608_0;
  v15 = (__m128)LODWORD(destination);
  v15.m128_f32[0] = (float)(destination - *angle) * 0.0027777778;
  v16 = v15;
  v16.m128_f32[0] = v15.m128_f32[0] + 0.5;
  v17 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v16);
  v14.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v16, v17), v14).m128_u32[0] | v17.m128_i32[0];
  v18 = v16;
  v18.m128_f32[0] = (float)((float)(v15.m128_f32[0] + 0.5) + v14.m128_f32[0]) - v14.m128_f32[0];
  v19 = v18;
  v19.m128_f32[0] = v18.m128_f32[0] - (float)(v15.m128_f32[0] + 0.5);
  v20 = (float)(v15.m128_f32[0] - (float)(v18.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v19, v17).m128_u32[0] & FLOAT_1_0)))
      * 360.0;
  v21 = COERCE_FLOAT(LODWORD(v20) & _mask__AbsFloat_) * 0.050000001;
  if ( v21 < 0.5 )
    v21 = FLOAT_0_5;
  if ( v20 < 0.0 )
  {
    LODWORD(v22) = COERCE_UNSIGNED_INT(
                     (float)((float)*(int *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v6)
                                                       + 14960)
                                           + 24)
                           * v21)
                   * speed) ^ _mask__NegFloat_;
    v23 = v20 < v22;
  }
  else
  {
    v22 = (float)((float)*(int *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v6) + 14960) + 24)
                * v21)
        * speed;
    v23 = v22 < v20;
  }
  if ( v23 )
  {
    *swinging = 1;
  }
  else
  {
    v22 = v20;
    *swinging = 0;
  }
  *angle = AngleNormalize360(*angle + v22);
  v24.m128_f32[0] = FLOAT_8388608_0;
  v25 = (__m128)LODWORD(destination);
  v25.m128_f32[0] = (float)(destination - *angle) * 0.0027777778;
  v26 = v25;
  v26.m128_f32[0] = v25.m128_f32[0] + 0.5;
  v27 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v26);
  v24.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v26, v27), v24).m128_u32[0] | v27.m128_i32[0];
  v28 = v26;
  v28.m128_f32[0] = (float)((float)(v25.m128_f32[0] + 0.5) + v24.m128_f32[0]) - v24.m128_f32[0];
  v29 = v28;
  v29.m128_f32[0] = v28.m128_f32[0] - (float)(v25.m128_f32[0] + 0.5);
  v30 = (float)(v25.m128_f32[0] - (float)(v28.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v29, v27).m128_u32[0] & FLOAT_1_0)))
      * 360.0;
  if ( v30 <= clampTolerance )
  {
    if ( COERCE_FLOAT(LODWORD(clampTolerance) ^ _mask__NegFloat_) > v30 )
      *angle = AngleNormalize360(destination + clampTolerance);
  }
  else
  {
    *angle = AngleNormalize360(destination - clampTolerance);
  }
}

#endif // __UNIMPLEMENTED__
