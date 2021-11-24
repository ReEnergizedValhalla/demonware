// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bddtlsinitack.cpp:0x957A20
BOOL __cdecl PM_ViewRangeLimited(const playerState_s *ps)
{
  bool v1; // al

  v1 = ps->pm_type == 1 && (ps->linkFlags & 1) == 0 || (ps->linkFlags & 4) != 0;
  return (ps->eFlags & 0x4300) != 0 || v1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsinitack.cpp:0x957A60
void __usercall PM_UpdatePronePitch(unsigned int ebp0@<ebp>, pmove_t *pm, pml_t *pml)
{
  playerState_s *ps; // esi
  bool walkable; // al
  float y; // xmm0_4
  double v6; // st7
  __int128 frametime_low; // xmm0
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  float a1; // xmm0_4
  double v14; // st7
  __int128 proneTorsoPitch_low; // xmm0
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  __m128 v20; // xmm3
  float delta; // [esp+3Ch] [ebp+4h]
  float deltaa; // [esp+3Ch] [ebp+4h]
  float deltac; // [esp+3Ch] [ebp+4h]
  float deltab; // [esp+3Ch] [ebp+4h]

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 5810, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 5813, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (ps->pm_flags & 1) != 0 )
  {
    if ( ps->groundEntityNum == 1023 )
    {
      if ( ps->viewHeightTarget != 22 )
      {
        if ( pml->groundPlane )
          walkable = pml->groundTrace.walkable;
        else
          walkable = 1;
        if ( !BG_CheckProne(
                ebp0,
                ps,
                ps->clientNum,
                &ps->origin,
                15.0,
                30.0,
                ps->proneDirection,
                &ps->fTorsoPitch,
                &ps->fWaistPitch,
                1,
                0,
                walkable,
                pm->handler,
                PCT_CLIENT,
                50.0)
          || ps->waterlevel >= 2 )
        {
          BG_AddPredictableEventToPlayerstate(9, 0, ps);
          ps->pm_flags |= 0x1000u;
        }
        goto LABEL_22;
      }
    }
    else if ( (!pml->groundPlane || pml->groundTrace.walkable)
           && (ps->viewHeightTarget != 22
            || COERCE_FLOAT(LODWORD(ps->fTorsoPitch) & _mask__AbsFloat_) <= 50.0
            && COERCE_FLOAT(LODWORD(ps->fWaistPitch) & _mask__AbsFloat_) <= 50.0) )
    {
LABEL_22:
      if ( pml->groundPlane )
      {
        if ( ps->pm_type == 7 )
          y = ps->viewangles.y;
        else
          y = ps->proneDirection;
        delta = PitchForYawOnNormal(y, (const vec3_t *)&pml->groundTrace);
      }
      else
      {
        delta = 0.0;
      }
      v6 = AngleDelta(delta, ps->proneDirectionPitch);
      deltaa = v6;
      if ( v6 != 0.0 )
      {
        frametime_low = LODWORD(pml->frametime);
        *(float *)&frametime_low = *(float *)&frametime_low * 70.0;
        if ( COERCE_FLOAT(LODWORD(deltaa) & _mask__AbsFloat_) <= *(float *)&frametime_low )
        {
          frametime_low = LODWORD(ps->proneDirectionPitch);
          *(float *)&frametime_low = *(float *)&frametime_low + deltaa;
        }
        else if ( deltaa < 0.0 )
        {
          *(float *)&frametime_low = (float)(*(float *)&frametime_low * -1.0) + ps->proneDirectionPitch;
        }
        else
        {
          *(float *)&frametime_low = (float)(*(float *)&frametime_low * 1.0) + ps->proneDirectionPitch;
        }
        v8.m128_f32[0] = FLOAT_8388608_0;
        LODWORD(ps->proneDirectionPitch) = frametime_low;
        *(float *)&frametime_low = *(float *)&frametime_low * 0.0027777778;
        v9 = (__m128)frametime_low;
        v9.m128_f32[0] = *(float *)&frametime_low + 0.5;
        v10 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v9);
        v8.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v9, v10), v8).m128_u32[0] | v10.m128_i32[0];
        v11 = v9;
        v11.m128_f32[0] = (float)((float)(*(float *)&frametime_low + 0.5) + v8.m128_f32[0]) - v8.m128_f32[0];
        v12 = v11;
        v12.m128_f32[0] = v11.m128_f32[0] - (float)(*(float *)&frametime_low + 0.5);
        ps->proneDirectionPitch = (float)(*(float *)&frametime_low
                                        - (float)(v11.m128_f32[0]
                                                - COERCE_FLOAT(_mm_cmpgt_ss(v12, v10).m128_u32[0] & FLOAT_1_0)))
                                * 360.0;
      }
      if ( pml->groundPlane )
      {
        deltac = PitchForYawOnNormal(ps->viewangles.y, (const vec3_t *)&pml->groundTrace);
        a1 = deltac;
      }
      else
      {
        a1 = 0.0;
      }
      v14 = AngleDelta(a1, ps->proneTorsoPitch);
      deltab = v14;
      if ( v14 != 0.0 )
      {
        proneTorsoPitch_low = LODWORD(pml->frametime);
        *(float *)&proneTorsoPitch_low = *(float *)&proneTorsoPitch_low * 70.0;
        if ( COERCE_FLOAT(LODWORD(deltab) & _mask__AbsFloat_) <= *(float *)&proneTorsoPitch_low )
        {
          proneTorsoPitch_low = LODWORD(ps->proneTorsoPitch);
          *(float *)&proneTorsoPitch_low = *(float *)&proneTorsoPitch_low + deltab;
        }
        else if ( deltab < 0.0 )
        {
          *(float *)&proneTorsoPitch_low = (float)(*(float *)&proneTorsoPitch_low * -1.0) + ps->proneTorsoPitch;
        }
        else
        {
          *(float *)&proneTorsoPitch_low = (float)(*(float *)&proneTorsoPitch_low * 1.0) + ps->proneTorsoPitch;
        }
        v16.m128_f32[0] = FLOAT_8388608_0;
        LODWORD(ps->proneTorsoPitch) = proneTorsoPitch_low;
        *(float *)&proneTorsoPitch_low = *(float *)&proneTorsoPitch_low * 0.0027777778;
        v17 = (__m128)proneTorsoPitch_low;
        v17.m128_f32[0] = *(float *)&proneTorsoPitch_low + 0.5;
        v18 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v17);
        v16.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v17, v18), v16).m128_u32[0] | v18.m128_i32[0];
        v19 = v17;
        v19.m128_f32[0] = (float)((float)(*(float *)&proneTorsoPitch_low + 0.5) + v16.m128_f32[0]) - v16.m128_f32[0];
        v20 = v19;
        v20.m128_f32[0] = v19.m128_f32[0] - (float)(*(float *)&proneTorsoPitch_low + 0.5);
        ps->proneTorsoPitch = (float)(*(float *)&proneTorsoPitch_low
                                    - (float)(v19.m128_f32[0]
                                            - COERCE_FLOAT(_mm_cmpgt_ss(v20, v18).m128_u32[0] & FLOAT_1_0)))
                            * 360.0;
      }
      return;
    }
    BG_AddPredictableEventToPlayerstate(9, 0, ps);
    goto LABEL_22;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsinitack.cpp:0x957E70
void __cdecl PM_SetProneMovementOverride(playerState_s *ps)
{
  int pm_flags; // eax

  pm_flags = ps->pm_flags;
  if ( (pm_flags & 1) != 0 )
    ps->pm_flags = pm_flags | 0x200;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsinitack.cpp:0x957E90
void __thiscall PM_ClearLadderFlag(playerState_s *ps)
{
  int pm_flags; // eax

  pm_flags = ps->pm_flags;
  if ( (pm_flags & 8) != 0 )
    ps->pm_flags = pm_flags & 0xFFFFDFF7 | 0x2000;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsinitack.cpp:0x957EB0
void __usercall PM_MeleeChargeClear(playerState_s *ps@<esi>)
{
  float v1; // xmm0_4
  float Float; // [esp+0h] [ebp-8h]
  float z; // [esp+4h] [ebp-4h]

  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6306, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps->pm_flags &= ~0x20000u;
  ps->meleeChargeDist = 0;
  ps->meleeChargeTime = 0;
  ps->meleeChargeEnt = 1023;
  if ( Dvar_GetBool(player_bayonetLaunchProof) )
  {
    z = ps->velocity.z;
    Float = Dvar_GetFloat(player_bayonetLaunchZCap);
    v1 = z;
    if ( (float)(Float - z) < 0.0 )
      v1 = Float;
    ps->velocity.z = v1;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsinitack.cpp:0x957F60
void __thiscall PM_GetMeleeChargeYaw(pmove_t *pm)
{
  playerState_s *ps; // edi
  char (__cdecl *v3)(LocalClientNum_t, int, vec3_t *, vec3_t *); // eax
  vec3_t vecToTarget; // [esp+8h] [ebp-28h] BYREF
  vec3_t targetOrigin; // [esp+14h] [ebp-1Ch] BYREF
  vec3_t angles; // [esp+20h] [ebp-10h] BYREF

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6351, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6354, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( ps->meleeChargeEnt == 1023
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp",
          6361,
          0,
          "(ps->meleeChargeEnt != ((1<<10)-1))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = (char (__cdecl *)(LocalClientNum_t, int, vec3_t *, vec3_t *))*(&funcs_953EF4 + 9 * pm->handler);
  if ( v3 )
  {
    if ( v3(pm->localClientNum, ps->meleeChargeEnt, &targetOrigin, &angles) )
    {
      vecToTarget.x = targetOrigin.x - ps->origin.x;
      vecToTarget.y = targetOrigin.y - ps->origin.y;
      vecToTarget.z = targetOrigin.z - ps->origin.z;
      vectoyaw((const vec2_t *)&vecToTarget);
    }
  }
}

#endif // __UNIMPLEMENTED__
