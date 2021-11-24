// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdplatformsocket-win32.cpp:0x947AD0
int __usercall Mantle_FindTransition@<eax>(float a1@<xmm2>, float curHeight)
{
  float v3; // xmm2_4
  float v4; // xmm1_4
  int v5; // ebx
  int v6; // esi
  float *v7; // edi
  float bestDiff; // [esp+8h] [ebp-4h]
  float height; // [esp+14h] [ebp+8h]

  v3 = a1 - curHeight;
  height = v3;
  if ( v3 <= 0.0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
          377,
          0,
          "(((height > 0)))",
          "(height) = %g",
          v3) )
  {
    __debugbreak();
  }
  LODWORD(v4) = COERCE_UNSIGNED_INT(s_mantleTrans[0].height - v3) & _mask__AbsFloat_;
  v5 = 0;
  bestDiff = v4;
  v6 = 1;
  v7 = (float *)(s_mantleTrans + 20);
  do
  {
    if ( v6 < 0 || v6 > 7 )
    {
      if ( !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
              254,
              0,
              "(0) <= (transIndex) && (transIndex) <= (MANTLE_UP_COUNT)",
              "transIndex not in [0, MANTLE_UP_COUNT]\n\t%i not in [%i, %i]",
              v6,
              0,
              7) )
        __debugbreak();
      v3 = height;
      v4 = bestDiff;
    }
    if ( v4 > COERCE_FLOAT(COERCE_UNSIGNED_INT(*v7 - v3) & _mask__AbsFloat_) )
    {
      LODWORD(v4) = COERCE_UNSIGNED_INT(*v7 - v3) & _mask__AbsFloat_;
      v5 = v6;
      bestDiff = v4;
    }
    v7 += 3;
    ++v6;
  }
  while ( (int)v7 < (int)&dropTraceWidth );
  return v5;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformsocket-win32.cpp:0x947BC0
void __usercall Mantle_SetHaveWeapon(const playerState_s *ps@<eax>, MantleState *mstate)
{
  int transIndex; // eax

  BG_GetWeaponDef(ps->weapon);
  transIndex = mstate->transIndex;
  if ( (transIndex < 0 || transIndex > 7)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
          254,
          0,
          "(0) <= (transIndex) && (transIndex) <= (MANTLE_UP_COUNT)",
          "transIndex not in [0, MANTLE_UP_COUNT]\n\t%i not in [%i, %i]",
          transIndex,
          0,
          7) )
  {
    __debugbreak();
  }
  Dvar_GetFloat(mantle_weapon_height);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformsocket-win32.cpp:0x947C20
void __usercall Mantle_Start(playerState_s *ps@<esi>, pmove_t *pm, MantleResults *mresults)
{
  int Transition; // eax
  Weapon v4; // eax
  int entityNum; // eax
  int mantleTimea; // [esp+10h] [ebp-14h]
  int mantleTime; // [esp+10h] [ebp-14h]
  vec3_t trans; // [esp+14h] [ebp-10h] BYREF

  ps->mantleState.yaw = vectoyaw((const vec2_t *)mresults);
  Transition = 0;
  ps->mantleState.timer = 0;
  if ( (mresults->flags & 0x1000) == 0 )
    Transition = Mantle_FindTransition(mresults->ledgePos.z, mresults->startPos.z);
  ps->mantleState.transIndex = Transition;
  ps->mantleState.flags = mresults->flags;
  if ( Com_BitCheckAssert(ps->perks, 18, 0xFFFFFFF) > 0
    || (v4.0 = BG_GetViewmodelWeaponIndex(ps).0, BG_WeaponHasPerk(v4, 0x12u)) )
  {
    ps->mantleState.flags |= 0x2000u;
  }
  mantleTimea = Mantle_GetUpLength(&ps->mantleState);
  mantleTime = Mantle_GetOverLength(&ps->mantleState) + mantleTimea;
  Mantle_GetAnimDelta(&ps->mantleState, &trans);
  ps->origin.x = mresults->endPos.x - trans.x;
  ps->origin.y = mresults->endPos.y - trans.y;
  ps->origin.z = mresults->endPos.z - trans.z;
  if ( (ps->pm_flags & 4) != 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
          551,
          0,
          "(!( ps->pm_flags & (1<<2) ))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps->pm_flags |= 4u;
  entityNum = mresults->entityNum;
  if ( entityNum > 0 && entityNum != 1022 )
    ps->moverEntityNum = entityNum;
  Mantle_SetHaveWeapon(ps, &ps->mantleState);
  BG_AddPredictableEventToPlayerstate(135, 0, ps);
  ps->eFlags |= 0x8000u;
  pm->mantleEndPos = mresults->endPos;
  pm->mantleDuration = mantleTime;
  pm->mantleStarted = 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformsocket-win32.cpp:0x947DB0
char __usercall Hatch_FindHatchSurface@<al>(
        trace_t *trace@<edi>,
        vec3_t *mantleEnd@<ecx>,
        pmove_t *pm,
        pml_t *pml,
        vec3_t *mantleDir,
        const float distance)
{
  playerState_s *ps; // esi
  float z; // xmm0_4
  float x; // xmm0_4
  float y; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float fraction; // xmm0_4
  float check_radius; // [esp+10h] [ebp-38h]
  vec3_t maxs; // [esp+14h] [ebp-34h] BYREF
  vec3_t mins; // [esp+20h] [ebp-28h] BYREF
  vec3_t start; // [esp+2Ch] [ebp-1Ch] BYREF
  vec3_t end; // [esp+38h] [ebp-10h] BYREF

  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp", 955, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  check_radius = Dvar_GetFloat(mantle_check_radius);
  maxs.x = check_radius;
  maxs.y = check_radius;
  LODWORD(mins.y) = LODWORD(check_radius) ^ _mask__NegFloat_;
  LODWORD(mins.x) = LODWORD(check_radius) ^ _mask__NegFloat_;
  mins.z = (float)(distance * 2.0) + 0.0;
  z = playerMaxs.z;
  maxs.z = playerMaxs.z;
  if ( (float)(70.0 - 0.0) < (float)(check_radius - COERCE_FLOAT(LODWORD(check_radius) ^ _mask__NegFloat_)) )
  {
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
            965,
            0,
            "((maxs[0] - mins[0]) <= (playerMaxs[2] - playerMins[2]))",
            (const char *)&pBlock) )
      __debugbreak();
    z = playerMaxs.z;
  }
  if ( (float)(z - 0.0) < (float)(maxs.y - mins.y)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
          966,
          0,
          "((maxs[1] - mins[1]) <= (playerMaxs[2] - playerMins[2]))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  x = pml->up.x;
  y = pml->up.y;
  v10 = pml->up.z;
  v11 = fsqrt((float)((float)(y * y) + (float)(x * x)) + (float)(v10 * v10));
  if ( COERCE_FLOAT(LODWORD(v11) ^ _mask__NegFloat_) >= 0.0 )
    v11 = *(float *)&FLOAT_1_0;
  v12 = x * (float)(1.0 / v11);
  v13 = y * (float)(1.0 / v11);
  v14 = v10 * (float)(1.0 / v11);
  start.x = ps->origin.x - (float)(v12 * 10.0);
  start.y = ps->origin.y - (float)(v13 * 10.0);
  start.z = ps->origin.z - (float)(v14 * 10.0);
  end.x = (float)(v12 * distance) + ps->origin.x;
  end.y = (float)(v13 * distance) + ps->origin.y;
  end.z = (float)(v14 * distance) + ps->origin.z;
  PM_trace(pm, trace, &start, &mins, &maxs, &end, ps->clientNum, (int)&g_sd.voiceDecodeBuffer[774848]);
  if ( trace->startsolid || trace->allsolid )
  {
    if ( Dvar_GetBool(mantle_debug) )
      Com_Printf(27, "%s\n", "Hatch Mantle Failed: Mantle brush is too thick");
    return 0;
  }
  else if ( trace->fraction == 1.0 )
  {
    Mantle_DebugPrint("Hatch Mantle Failed: No mantle surface found");
    return 0;
  }
  else if ( (trace->sflags & 0x1C000000) != 0 )
  {
    LODWORD(mantleDir->x) = trace->normal.vec.m128_i32[0] ^ _mask__NegFloat_;
    LODWORD(mantleDir->y) = trace->normal.vec.m128_i32[1] ^ _mask__NegFloat_;
    LODWORD(mantleDir->z) = trace->normal.vec.m128_i32[2] ^ _mask__NegFloat_;
    Vec3Normalize(mantleDir);
    fraction = trace->fraction;
    mantleEnd->x = (float)((float)(end.x - start.x) * fraction) + start.x;
    mantleEnd->y = (float)((float)(end.y - start.y) * fraction) + start.y;
    mantleEnd->z = (float)((float)(end.z - start.z) * fraction) + start.z;
    return 1;
  }
  else
  {
    Mantle_DebugPrint("Hatch Mantle Failed: No mantle surface with MANTLE_ON, MANTLE_OVER or MOUNT found");
    return 0;
  }
}

#endif // __UNIMPLEMENTED__
