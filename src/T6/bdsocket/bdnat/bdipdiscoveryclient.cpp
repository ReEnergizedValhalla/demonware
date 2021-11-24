// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdipdiscoveryclient.cpp:0x9505C0
void __cdecl BG_UpdateClientControlledMissile(vec3_t *angles, const usercmd_s *cmd, int msec)
{
  char v3; // bl
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  int yawmove; // ecx
  __m128 x_low; // xmm0
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm4
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  float v14; // xmm0_4
  float v15; // xmm2_4
  vec3_t deltaAngles; // [esp+Ch] [ebp-A0h] BYREF
  vec3_t invMtx[3]; // [esp+18h] [ebp-94h] BYREF
  vec3_t mtx[3]; // [esp+3Ch] [ebp-70h] BYREF
  vec3_t deltaMtx[3]; // [esp+60h] [ebp-4Ch] BYREF
  vec3_t missileMtx[3]; // [esp+84h] [ebp-28h] BYREF

  v3 = 0;
  if ( Com_GetClientPlatform() == CLIENT_PLATFORM_PC && cmd->lastInput )
    v3 = 1;
  if ( !angles
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 3252, 0, "(&angles)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !cmd
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 3253, 0, "(cmd)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v4 = FLOAT_35_0;
  v5 = (float)msec * 0.001;
  if ( v3 )
    v6 = FLOAT_35_0;
  else
    v6 = FLOAT_15_0;
  yawmove = cmd->yawmove;
  deltaAngles.x = (float)(v6 * v5) * (float)((float)cmd->pitchmove * -0.0078740157);
  if ( !v3 )
    v4 = FLOAT_20_0;
  deltaAngles.y = (float)(v4 * v5) * (float)((float)yawmove * -0.0078740157);
  deltaAngles.z = 0.0;
  AnglesToAxis(&deltaAngles, deltaMtx);
  AnglesToAxis(angles, missileMtx);
  MatrixTranspose(deltaMtx, invMtx);
  MatrixMultiply(invMtx, missileMtx, mtx);
  AxisToAngles(mtx, angles);
  x_low = (__m128)LODWORD(angles->x);
  x_low.m128_f32[0] = x_low.m128_f32[0] * 0.0027777778;
  v9.m128_f32[0] = FLOAT_8388608_0;
  v10 = x_low;
  v10.m128_f32[0] = x_low.m128_f32[0] + 0.5;
  v11 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v10);
  v9.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v10, v11), v9).m128_u32[0] | v11.m128_i32[0];
  v12 = v10;
  v12.m128_f32[0] = (float)((float)(x_low.m128_f32[0] + 0.5) + v9.m128_f32[0]) - v9.m128_f32[0];
  v13 = v12;
  v13.m128_f32[0] = v12.m128_f32[0] - (float)(x_low.m128_f32[0] + 0.5);
  v14 = (float)(x_low.m128_f32[0]
              - (float)(v12.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v13, v11).m128_u32[0] & FLOAT_1_0)))
      * 360.0;
  v15 = PITCH_MAX_RANGE;
  angles->x = v14;
  if ( (float)(v14 - 87.0) < 0.0 )
    v15 = v14;
  if ( (float)(1.0 - v14) < 0.0 )
    angles->x = v15;
  else
    LODWORD(angles->x) = FLOAT_1_0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdipdiscoveryclient.cpp:0x9507E0
unsigned __int8 __cdecl BG_ShieldHitEncode(const vec3_t *hitPos, bool fromTheFront)
{
  float y; // xmm1_4
  float v3; // xmm1_4
  int v4; // ebx
  float z; // xmm1_4
  float v6; // xmm1_4
  int v7; // ecx
  vec2_t shieldHitEncodeHeightWorldVec2; // [esp+Ch] [ebp-14h] BYREF
  vec2_t shieldHitEncodeWidthWorldVec2; // [esp+14h] [ebp-Ch] BYREF

  Dvar_GetVec2(bg_shieldHitEncodeWidthWorld, &shieldHitEncodeWidthWorldVec2);
  Dvar_GetVec2(bg_shieldHitEncodeHeightWorld, &shieldHitEncodeHeightWorldVec2);
  y = shieldHitEncodeWidthWorldVec2.v[1]
    - (float)((float)((float)(shieldHitEncodeWidthWorldVec2.v[1] - shieldHitEncodeWidthWorldVec2.v[0]) * 0.0625) * 0.5);
  if ( (float)(hitPos->y - y) < 0.0 )
    y = hitPos->y;
  if ( (float)(shieldHitEncodeWidthWorldVec2.v[0] - hitPos->y) >= 0.0 )
    y = shieldHitEncodeWidthWorldVec2.v[0];
  v3 = (float)(y - shieldHitEncodeWidthWorldVec2.v[0])
     / (float)((float)(shieldHitEncodeWidthWorldVec2.v[1] - shieldHitEncodeWidthWorldVec2.v[0]) * 0.0625);
  v4 = (int)v3;
  if ( ((int)v3 < 0 || v4 > 16)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          3294,
          0,
          "(0) <= (result) && (result) <= (segmentCount)",
          "result not in [0, segmentCount]\n\t%i not in [%i, %i]",
          (int)v3,
          0,
          16) )
  {
    __debugbreak();
  }
  z = shieldHitEncodeHeightWorldVec2.v[1]
    - (float)((float)((float)(shieldHitEncodeHeightWorldVec2.v[1] - shieldHitEncodeHeightWorldVec2.v[0]) * 0.125) * 0.5);
  if ( (float)(hitPos->z - z) < 0.0 )
    z = hitPos->z;
  if ( (float)(shieldHitEncodeHeightWorldVec2.v[0] - hitPos->z) >= 0.0 )
    z = shieldHitEncodeHeightWorldVec2.v[0];
  v6 = (float)(z - shieldHitEncodeHeightWorldVec2.v[0])
     / (float)((float)(shieldHitEncodeHeightWorldVec2.v[1] - shieldHitEncodeHeightWorldVec2.v[0]) * 0.125);
  v7 = (int)v6;
  if ( (int)v6 < 0 || v7 > 8 )
  {
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            3294,
            0,
            "(0) <= (result) && (result) <= (segmentCount)",
            "result not in [0, segmentCount]\n\t%i not in [%i, %i]",
            (int)v6,
            0,
            8) )
      __debugbreak();
    v7 = (int)v6;
  }
  if ( v4 < 0 || v4 > 15 )
  {
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            3322,
            0,
            "(0) <= (segY) && (segY) <= ((SHIELD_SEGCOUNT_Y - 1))",
            "segY not in [0, (SHIELD_SEGCOUNT_Y - 1)]\n\t%i not in [%i, %i]",
            v4,
            0,
            15) )
      __debugbreak();
    v7 = (int)v6;
  }
  if ( v7 < 0 || v7 > 7 )
  {
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            3323,
            0,
            "(0) <= (segZ) && (segZ) <= ((SHIELD_SEGCOUNT_Z - 1))",
            "segZ not in [0, (SHIELD_SEGCOUNT_Z - 1)]\n\t%i not in [%i, %i]",
            v7,
            0,
            7) )
      __debugbreak();
    v7 = (int)v6;
  }
  return fromTheFront | (2 * (v7 | (8 * v4)));
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdipdiscoveryclient.cpp:0x9509C0
void __cdecl BG_ShieldHitDecode(unsigned int encoded, vec3_t *result, bool *resultHitFront)
{
  signed int v3; // esi
  signed int v4; // edi
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // [esp+Ch] [ebp-20h]
  float v12; // [esp+Ch] [ebp-20h]
  float v13; // [esp+14h] [ebp-18h]
  vec2_t shieldHitEncodeHeightVMVec2; // [esp+18h] [ebp-14h] BYREF
  vec2_t shieldHitEncodeWidthVMVec2; // [esp+20h] [ebp-Ch] BYREF

  Dvar_GetVec2(bg_shieldHitEncodeWidthVM, &shieldHitEncodeWidthVMVec2);
  Dvar_GetVec2(bg_shieldHitEncodeHeightVM, &shieldHitEncodeHeightVMVec2);
  if ( encoded >= 0x100
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          3380,
          0,
          "(encoded < 256)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = (encoded >> 4) & ((unsigned int)MY_MASK_Y >> 4);
  v4 = (encoded >> 1) & ((unsigned int)MY_MASK_Z >> 1);
  if ( (encoded & 1) != 0 )
    v5 = *(float *)&FLOAT_1_0;
  else
    v5 = FLOAT_N1_0;
  result->x = v5;
  v11 = shieldHitEncodeWidthVMVec2.v[0];
  v6 = shieldHitEncodeWidthVMVec2.v[1];
  v13 = shieldHitEncodeWidthVMVec2.v[1];
  if ( v3 < 0 || v3 > 15 )
  {
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            3357,
            0,
            "(0) <= (segment) && (segment) <= (15)",
            "segment not in [0, 15]\n\t%i not in [%i, %i]",
            v3,
            0,
            15) )
      __debugbreak();
    v6 = v13;
  }
  v7 = (float)(v6 - v11) * 0.0625;
  v8 = (float)(v7 * 0.5) + v11;
  v9 = (float)v3 * v7;
  v12 = shieldHitEncodeHeightVMVec2.v[0];
  v10 = shieldHitEncodeHeightVMVec2.v[1];
  result->y = v8 + v9;
  if ( (v4 < 0 || v4 > 15)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          3357,
          0,
          "(0) <= (segment) && (segment) <= (15)",
          "segment not in [0, 15]\n\t%i not in [%i, %i]",
          v4,
          0,
          15) )
  {
    __debugbreak();
  }
  result->z = (float)((float)((float)((float)(v10 - v12) * 0.125) * 0.5) + v12)
            + (float)((float)v4 * (float)((float)(v10 - v12) * 0.125));
  *resultHitFront = encoded & 1;
}

#endif // __UNIMPLEMENTED__
