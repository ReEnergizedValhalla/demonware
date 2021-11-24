// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdpacketbuffer.cpp:0x957440
void __usercall PM_UpdateViewAngles_PronePitchClamp(playerState_s *ps@<esi>)
{
  double v1; // st7
  float v2; // xmm0_4
  bool v3; // cc
  __m128 v4; // xmm3
  __m128 proneTorsoPitch_low; // xmm0
  __m128 v6; // xmm1
  __m128 v7; // xmm4
  float v8; // xmm3_4
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  float delta; // [esp+8h] [ebp-4h]

  v1 = AngleDelta(ps->proneTorsoPitch, ps->viewangles.x);
  delta = v1;
  if ( v1 > 45.0 )
    goto LABEL_4;
  if ( delta >= -45.0 )
    return;
  if ( delta <= 45.0 )
    v2 = delta + 45.0;
  else
LABEL_4:
    v2 = delta - 45.0;
  v3 = v2 <= 0.0;
  v4.m128_f32[0] = FLOAT_8388608_0;
  ps->delta_angles.x = ps->delta_angles.x + v2;
  proneTorsoPitch_low = (__m128)LODWORD(ps->proneTorsoPitch);
  if ( v3 )
    proneTorsoPitch_low.m128_f32[0] = proneTorsoPitch_low.m128_f32[0] + 45.0;
  else
    proneTorsoPitch_low.m128_f32[0] = proneTorsoPitch_low.m128_f32[0] - 45.0;
  proneTorsoPitch_low.m128_f32[0] = proneTorsoPitch_low.m128_f32[0] * 0.0027777778;
  v6 = proneTorsoPitch_low;
  v6.m128_f32[0] = proneTorsoPitch_low.m128_f32[0] + 0.5;
  v7 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v6);
  LODWORD(v8) = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v6, v7), v4).m128_u32[0] | v7.m128_i32[0];
  v9 = v6;
  v9.m128_f32[0] = (float)((float)(proneTorsoPitch_low.m128_f32[0] + 0.5) + v8) - v8;
  v10 = v9;
  v10.m128_f32[0] = v9.m128_f32[0] - (float)(proneTorsoPitch_low.m128_f32[0] + 0.5);
  ps->viewangles.x = (float)(proneTorsoPitch_low.m128_f32[0]
                           - (float)(v9.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v10, v7).m128_u32[0] & FLOAT_1_0)))
                   * 360.0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpacketbuffer.cpp:0x957550
void __usercall PM_UpdateViewAngles_Prone(
        playerState_s *ps@<ecx>,
        usercmd_s *cmd@<eax>,
        float msec,
        unsigned __int8 handler,
        float oldViewYaw)
{
  BOOL v7; // ecx
  BOOL v8; // eax
  float v9; // xmm0_4
  float y; // xmm1_4
  float proneDirection; // xmm1_4
  int v12; // edi
  double v13; // st7
  float v14; // xmm0_4
  double v15; // st7
  unsigned __int8 v16; // al
  int v17; // edi
  float v18; // xmm0_4
  float newProneYaw; // [esp+3Ch] [ebp-14h]
  float newProneYawa; // [esp+3Ch] [ebp-14h]
  float delta; // [esp+40h] [ebp-10h]
  float deltab; // [esp+40h] [ebp-10h]
  float deltaa; // [esp+40h] [ebp-10h]
  float deltac; // [esp+40h] [ebp-10h]
  int proneBlocked; // [esp+44h] [ebp-Ch]
  int bRetry; // [esp+48h] [ebp-8h]
  int bRetrya; // [esp+48h] [ebp-8h]
  float newViewYaw; // [esp+4Ch] [ebp-4h]

  *(float *)&bRetry = Dvar_GetFloat(bg_prone_yawcap);
  newViewYaw = ps->viewangles.y;
  proneBlocked = 0;
  delta = AngleDelta(ps->proneDirection, newViewYaw);
  v7 = delta > (float)(*(float *)&bRetry - 5.0)
    || COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&bRetry - 5.0) ^ _mask__NegFloat_) > delta;
  v8 = (cmd->forwardmove || cmd->rightmove) && delta != 0.0;
  if ( v7 || v8 )
  {
    v9 = (float)(msec * 55.0) * 0.001;
    if ( v9 <= COERCE_FLOAT(LODWORD(delta) & _mask__AbsFloat_) )
    {
      proneDirection = ps->proneDirection;
      if ( delta <= 0.0 )
        y = proneDirection + v9;
      else
        y = proneDirection - v9;
    }
    else
    {
      y = ps->viewangles.y;
    }
    newProneYaw = y;
    v12 = 1;
    if ( BG_CheckProneTurned(ps, y, handler) )
    {
LABEL_24:
      if ( BG_CheckProne(
             0x3FFu,
             ps,
             ps->clientNum,
             &ps->origin,
             15.0,
             30.0,
             ps->viewangles.y,
             0,
             0,
             1,
             ps->groundEntityNum != 1023,
             1,
             handler,
             PCT_CLIENT,
             PRONE_FEET_DIST_TURNED)
        && BG_CheckProne(
             0x3FFu,
             ps,
             ps->clientNum,
             &ps->origin,
             15.0,
             30.0,
             newProneYaw,
             0,
             0,
             1,
             ps->groundEntityNum != 1023,
             1,
             handler,
             PCT_CLIENT,
             PRONE_FEET_DIST_TURNED) )
      {
        ps->proneDirection = newProneYaw;
      }
      else
      {
        proneBlocked = 1;
      }
    }
    else
    {
      while ( v12 )
      {
        v13 = AngleDelta(ps->proneDirection, newProneYaw);
        if ( fabs(v13) <= 1.0 )
        {
          v14 = v13;
          v12 = 0;
          proneBlocked = 1;
        }
        else
        {
          v12 = 1;
          deltab = v13;
          if ( deltab <= 0.0 )
            v14 = FLOAT_N1_0;
          else
            v14 = *(float *)&FLOAT_1_0;
        }
        newProneYaw = AngleNormalize360(newProneYaw + v14);
        if ( BG_CheckProneTurned(ps, newProneYaw, handler) )
          goto LABEL_24;
      }
    }
  }
  v15 = AngleDelta(ps->proneDirection, ps->viewangles.y);
  deltaa = v15;
  if ( v15 != 0.0 )
  {
    newProneYawa = ps->proneDirection;
    bRetrya = 1;
    while ( 1 )
    {
      v16 = BG_CheckProne(
              (unsigned int)&ps->origin,
              ps,
              ps->clientNum,
              &ps->origin,
              15.0,
              30.0,
              newProneYawa,
              0,
              0,
              1,
              ps->groundEntityNum != 1023,
              1,
              handler,
              PCT_CLIENT,
              PRONE_FEET_DIST_TURNED);
      v17 = v16;
      if ( v16 )
      {
        if ( BG_CheckProneTurned(ps, newProneYawa, handler) )
          break;
      }
      if ( !bRetrya )
        goto LABEL_42;
      v18 = deltaa;
      if ( COERCE_FLOAT(LODWORD(deltaa) & _mask__AbsFloat_) <= 1.0 )
      {
        bRetrya = 0;
      }
      else
      {
        bRetrya = 1;
        if ( deltaa <= 0.0 )
          v18 = FLOAT_N1_0;
        else
          v18 = *(float *)&FLOAT_1_0;
      }
      ps->delta_angles.y = ps->delta_angles.y + v18;
      proneBlocked = 1;
      deltac = AngleNormalize360(v18 + ps->viewangles.y);
      ps->viewangles.y = deltac;
      deltaa = AngleDelta(ps->proneDirection, deltac);
      if ( !v17 )
        newProneYawa = AngleNormalize360(newProneYawa + deltaa);
    }
    ps->proneDirection = newProneYawa;
  }
LABEL_42:
  PM_UpdateViewAngles_ProneYawClamp(ps, deltaa, proneBlocked, oldViewYaw, newViewYaw);
  PM_UpdateViewAngles_PronePitchClamp(ps);
}

#endif // __UNIMPLEMENTED__
