// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdsocketrouter.cpp:0x948460
void __cdecl Mantle_ShutdownAnims()
{
  s_mantleAnims = 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocketrouter.cpp:0x948470
char __usercall Mantle_FindMantleSurface@<al>(trace_t *trace@<edi>, pmove_t *pm, pml_t *pml, vec3_t *mantleDir)
{
  playerState_s *ps; // esi
  float z; // xmm0_4
  double Float; // st7
  float x; // xmm1_4
  float y; // xmm2_4
  float v9; // xmm3_4
  unsigned int v10; // xmm1_4
  unsigned int v11; // xmm2_4
  float v12; // xmm0_4
  float v; // [esp+8h] [ebp-4Ch]
  float traceDist; // [esp+Ch] [ebp-48h]
  float innerDist; // [esp+10h] [ebp-44h]
  float innerDista; // [esp+10h] [ebp-44h]
  vec3_t end; // [esp+14h] [ebp-40h] BYREF
  vec3_t start; // [esp+20h] [ebp-34h] BYREF
  vec3_t mins; // [esp+2Ch] [ebp-28h] BYREF
  vec3_t maxs; // [esp+38h] [ebp-1Ch] BYREF
  vec3_t traceDir; // [esp+44h] [ebp-10h]

  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp", 1149, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  innerDist = Dvar_GetFloat(mantle_check_radius);
  maxs.x = innerDist;
  maxs.y = innerDist;
  LODWORD(mins.x) = LODWORD(innerDist) ^ _mask__NegFloat_;
  LODWORD(mins.y) = LODWORD(innerDist) ^ _mask__NegFloat_;
  z = playerMaxs.z;
  mins.z = playerMins.z;
  maxs.z = playerMaxs.z;
  if ( (float)(70.0 - 0.0) < (float)(innerDist - COERCE_FLOAT(LODWORD(innerDist) ^ _mask__NegFloat_)) )
  {
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
            1158,
            0,
            "((maxs[0] - mins[0]) <= (playerMaxs[2] - playerMins[2]))",
            (const char *)&pBlock) )
      __debugbreak();
    z = playerMaxs.z;
  }
  if ( (float)(z - 0.0) < (float)(maxs.y - mins.y)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
          1159,
          0,
          "((maxs[1] - mins[1]) <= (playerMaxs[2] - playerMins[2]))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  innerDista = 15.0 - innerDist;
  if ( Dvar_GetBool(mantle_adjustment_tu) )
    Float = Dvar_GetFloat(mantle_check_range_tu);
  else
    Float = Dvar_GetFloat(mantle_check_range);
  x = pml->forward.x;
  y = pml->forward.y;
  traceDist = Float + innerDista;
  v9 = fsqrt((float)(y * y) + (float)(x * x));
  if ( COERCE_FLOAT(LODWORD(v9) ^ _mask__NegFloat_) >= 0.0 )
    v9 = *(float *)&FLOAT_1_0;
  *(float *)&v10 = x * (float)(1.0 / v9);
  *(float *)&v11 = y * (float)(1.0 / v9);
  v12 = (float)(1.0 / v9) * 0.0;
  start.x = (float)(*(float *)&v10 * COERCE_FLOAT(LODWORD(innerDista) ^ _mask__NegFloat_)) + ps->origin.x;
  start.y = (float)(*(float *)&v11 * COERCE_FLOAT(LODWORD(innerDista) ^ _mask__NegFloat_)) + ps->origin.y;
  start.z = (float)(v12 * COERCE_FLOAT(LODWORD(innerDista) ^ _mask__NegFloat_)) + ps->origin.z;
  *(_QWORD *)&traceDir.x = __PAIR64__(v11, v10);
  end.x = (float)(*(float *)&v10 * traceDist) + ps->origin.x;
  traceDir.z = v12;
  end.y = (float)(*(float *)&v11 * traceDist) + ps->origin.y;
  end.z = (float)(v12 * traceDist) + ps->origin.z;
  PM_trace(pm, trace, &start, &mins, &maxs, &end, ps->clientNum, (int)&g_sd.voiceDecodeBuffer[774848]);
  if ( trace->startsolid || trace->allsolid )
  {
    if ( Dvar_GetBool(mantle_debug) )
      Com_Printf(27, "%s\n", "Mantle Failed: Mantle brush is too thick");
    return 0;
  }
  else if ( trace->fraction == 1.0 )
  {
    Mantle_DebugPrint("Mantle Failed: No mantle surface found");
    return 0;
  }
  else if ( (trace->sflags & 0x1C000000) != 0 )
  {
    LODWORD(mantleDir->x) = trace->normal.vec.m128_i32[0] ^ _mask__NegFloat_;
    *(_QWORD *)&mantleDir->v[1] = trace->normal.vec.m128_i32[1] ^ (unsigned int)_mask__NegFloat_;
    if ( Vec3Normalize(mantleDir) >= 0.000099999997 )
    {
      v = acos(mantleDir->y * traceDir.y + mantleDir->x * traceDir.x + mantleDir->z * traceDir.z) * 57.295776;
      if ( v <= Dvar_GetFloat(mantle_check_angle) )
      {
        return 1;
      }
      else
      {
        Mantle_DebugPrint("Mantle Failed: Player is not facing mantle surface");
        return 0;
      }
    }
    else
    {
      Mantle_DebugPrint("Mantle Failed: Mantle surface has vertical normal");
      return 0;
    }
  }
  else
  {
    Mantle_DebugPrint("Mantle Failed: No mantle surface with MANTLE_ON, MANTLE_OVER or MOUNT found");
    return 0;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocketrouter.cpp:0x948AB0
void __cdecl Mantle_CapView(playerState_s *ps)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  float v4; // xmm2_4
  float delta; // [esp+Ch] [ebp-4h]
  float view_yawcap; // [esp+18h] [ebp+8h]

  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp", 1415, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (ps->pm_flags & 4) == 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
          1416,
          0,
          "(ps->pm_flags & (1<<2))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( Dvar_GetBool(mantle_enable) )
  {
    delta = AngleDelta(ps->mantleState.yaw, ps->viewangles.y);
    view_yawcap = Dvar_GetFloat(mantle_view_yawcap);
    v2 = view_yawcap;
    v3 = delta;
    LODWORD(v4) = LODWORD(view_yawcap) ^ _mask__NegFloat_;
    if ( delta < COERCE_FLOAT(LODWORD(view_yawcap) ^ _mask__NegFloat_) || view_yawcap < delta )
    {
      if ( v4 > delta )
      {
        do
          v3 = v3 + view_yawcap;
        while ( v4 > v3 );
      }
      for ( ; v3 > view_yawcap; v3 = v3 - view_yawcap )
        ;
      if ( v3 > 0.0 )
        LODWORD(v2) = LODWORD(view_yawcap) ^ _mask__NegFloat_;
      ps->delta_angles.y = v3 + ps->delta_angles.y;
      ps->viewangles.y = AngleNormalize360(v2 + ps->mantleState.yaw);
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocketrouter.cpp:0x948BE0
void __cdecl Mantle_ClearHint(playerState_s *ps)
{
  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp", 1446, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps->mantleState.flags &= 0xFFFFFF6F;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocketrouter.cpp:0x948C20
bool __cdecl Mantle_IsWeaponInactive(const playerState_s *ps)
{
  return Dvar_GetBool(mantle_enable) && (ps->pm_flags & 4) != 0 && (ps->mantleState.flags & 0x40) == 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocketrouter.cpp:0x948C60
BOOL __cdecl Mantle_IsWeaponEquipped(const playerState_s *ps)
{
  return (ps->pm_flags & 4) != 0
      && (!Dvar_GetBool(mantle_enable) || (ps->pm_flags & 4) == 0 || (ps->mantleState.flags & 0x40) != 0);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocketrouter.cpp:0x948CA0
BOOL __cdecl Mantle_DoAnim(const playerState_s *ps)
{
  int transIndex; // esi
  float psa; // [esp+Ch] [ebp+8h]

  transIndex = ps->mantleState.transIndex;
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
  psa = s_mantleTrans[transIndex].height;
  return psa > Dvar_GetFloat(mantle_weapon_anim_height);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocketrouter.cpp:0x948D10
int __cdecl Mantle_GetDuration(const playerState_s *ps)
{
  int UpLength; // esi

  UpLength = Mantle_GetUpLength(&ps->mantleState);
  return UpLength + Mantle_GetOverLength(&ps->mantleState);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocketrouter.cpp:0x948D40
double __cdecl Mantle_GetMantleFrac(const playerState_s *ps)
{
  int UpLength; // esi
  int v2; // esi

  UpLength = Mantle_GetUpLength(&ps->mantleState);
  v2 = Mantle_GetOverLength(&ps->mantleState) + UpLength;
  if ( v2 <= 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
          1511,
          0,
          "((mantleLength > 0))",
          "(mantleLength) = %i",
          v2) )
  {
    __debugbreak();
  }
  return (double)ps->mantleState.timer / (double)v2;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocketrouter.cpp:0x948DA0
bool __cdecl Mount_CanPlayerDeployTurret(playerState_s *ps)
{
  int weaponstate; // eax
  int pm_flags; // eax

  weaponstate = ps->weaponstate;
  if ( weaponstate == 11
    || weaponstate == 13
    || weaponstate == 14
    || weaponstate == 16
    || weaponstate == 15
    || weaponstate == 12
    || weaponstate == 17
    || weaponstate == 18
    || weaponstate == 19
    || weaponstate == 20
    || weaponstate == 21
    || weaponstate == 1
    || weaponstate == 2
    || weaponstate == 3
    || weaponstate == 4
    || weaponstate == 5
    || weaponstate >= 36 && weaponstate <= 38
    || weaponstate == 44
    || weaponstate == 45
    || weaponstate == 46
    || weaponstate >= 22 && weaponstate <= 29
    || weaponstate >= 30 && weaponstate <= 34
    || (ps->eFlags & 0x300) != 0
    || BG_GetAmmoInClip(ps, ps->weapon) <= 0 )
  {
    return 0;
  }
  pm_flags = ps->pm_flags;
  if ( (pm_flags & 1) != 0 )
    pm_flags &= ~0x4000u;
  return (pm_flags & 0x2E00C) == 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocketrouter.cpp:0x948E90
// local variable allocation has failed, the output may be wrong!
void __usercall Mantle_CalcEndPos(pmove_t *pm@<edi>, MantleResults *mresults@<esi>, unsigned int a3@<ebp>)
{
  playerState_s *ps; // eax
  float x; // xmm1_4
  float v5; // xmm4_4
  float y; // xmm2_4
  float z; // xmm3_4
  int tracemask; // eax
  float v9; // xmm4_4
  float v10; // xmm1_4
  int v11; // edx
  float v12; // xmm2_4
  playerState_s *v13; // [esp-Ch] [ebp-90h]
  _BYTE v14[44]; // [esp-8h] [ebp-8Ch] OVERLAPPED BYREF
  vec3_t v15; // [esp+44h] [ebp-40h] BYREF
  vec3_t mins; // [esp+50h] [ebp-34h] BYREF
  vec3_t maxs; // [esp+5Ch] [ebp-28h] BYREF
  vec3_t start; // [esp+68h] [ebp-1Ch] BYREF
  vec3_t end; // [esp+74h] [ebp-10h]
  unsigned int retaddr; // [esp+84h] [ebp+0h]

  *(_QWORD *)&end.v[1] = __PAIR64__(retaddr, a3);
  ps = pm->ps;
  *(_OWORD *)v14 = 0i64;
  v13 = ps;
  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp", 422, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (mresults->flags & 1) != 0 )
  {
    x = mresults->ledgePos.x;
    v5 = mresults->dir.x;
    y = mresults->ledgePos.y;
    z = mresults->ledgePos.z;
    tracemask = pm->tracemask;
    v15 = playerMins;
    *(_QWORD *)&mins.x = *(_QWORD *)&playerMaxs.x;
    *(_QWORD *)&maxs.x = __PAIR64__(LODWORD(y), LODWORD(x));
    mins.z = FLOAT_50_0;
    v9 = (float)(v5 * 31.0) + x;
    start.y = (float)(mresults->dir.y * 31.0) + y;
    v10 = (float)(mresults->dir.z * 31.0) + z;
    maxs.z = z;
    start.x = v9;
    start.z = v10;
    PM_trace(pm, (trace_t *)v14, &maxs, &v15, &mins, &start, v13->clientNum, tracemask);
    if ( !v14[43] && *(float *)&v14[16] >= 1.0 )
    {
      v11 = pm->tracemask;
      maxs = start;
      start.z = start.z - 18.0;
      PM_trace(pm, (trace_t *)v14, &maxs, &v15, &mins, &start, v13->clientNum, v11);
      if ( !v14[43] )
      {
        v12 = *(float *)&v14[16];
        if ( *(float *)&v14[16] >= 1.0 )
        {
          *(_QWORD *)&mresults->endPos.x = *(_QWORD *)&start.x;
          mresults->endPos.z = (float)((float)(start.z - maxs.z) * v12) + maxs.z;
          return;
        }
      }
    }
    mresults->flags &= 0xFFFFFFFC;
  }
  mresults->endPos = mresults->ledgePos;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocketrouter.cpp:0x9497C0
// local variable allocation has failed, the output may be wrong!
char __usercall Mantle_CheckLedge@<al>(
        MantleResults *mresults@<ecx>,
        unsigned int a2@<ebp>,
        float a3@<xmm0>,
        pmove_t *a4)
{
  float v4; // esi
  float x; // xmm2_4
  float v7; // xmm4_4
  float y; // xmm3_4
  int tracemask; // eax
  float v10; // xmm4_4
  float z; // xmm2_4
  vec3_t *p_ledgePos; // eax
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  int v17; // [esp+4h] [ebp-C0h]
  const char *v18; // [esp+28h] [ebp-9Ch]
  int v19; // [esp+28h] [ebp-9Ch]
  float psa; // [esp+2Ch] [ebp-98h]
  _BYTE v22[45]; // [esp+38h] [ebp-8Ch] OVERLAPPED BYREF
  vec3_t v23; // [esp+84h] [ebp-40h] BYREF
  vec3_t mins; // [esp+90h] [ebp-34h] BYREF
  vec3_t maxs; // [esp+9Ch] [ebp-28h] BYREF
  vec3_t start; // [esp+A8h] [ebp-1Ch] BYREF
  vec3_t end; // [esp+B4h] [ebp-10h] BYREF
  unsigned int retaddr; // [esp+C4h] [ebp+0h]

  *(_QWORD *)&end.v[1] = __PAIR64__(retaddr, a2);
  v4 = *(float *)&a4->ps;
  *(_OWORD *)v22 = 0i64;
  if ( v4 == 0.0
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp", 762, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v18 = va("Checking for ledge at %f units", a3);
  if ( !v18
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp", 216, 0, "(msg)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( Dvar_GetBool(mantle_debug) )
    Com_Printf(27, "%s\n", v18);
  x = mresults->startPos.x;
  v7 = mresults->dir.x;
  y = mresults->startPos.y;
  tracemask = a4->tracemask;
  LODWORD(v23.x) = LODWORD(playerMaxs.x) ^ _mask__NegFloat_;
  *(_QWORD *)&v23.v[1] = LODWORD(playerMaxs.x) ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
  *(_QWORD *)&maxs.x = __PAIR64__(LODWORD(y), LODWORD(x));
  mins.x = playerMaxs.x;
  mins.y = playerMaxs.x;
  v10 = (float)(v7 * 16.0) + x;
  start.y = (float)(mresults->dir.y * 16.0) + y;
  z = mresults->dir.z;
  mins.z = 15.0 * 2.0;
  maxs.z = mresults->startPos.z + a3;
  start.x = v10;
  start.z = (float)(z * 16.0) + maxs.z;
  v19 = tracemask & 0xFDFF7FFF;
  PM_trace(a4, (trace_t *)v22, &maxs, &v23, &mins, &start, *(_DWORD *)(LODWORD(v4) + 416), tracemask & 0xFDFF7FFF);
  if ( v22[43] || *(float *)&v22[16] < 1.0 )
  {
    if ( Dvar_GetBool(mantle_debug) )
      Com_Printf(27, "%s\n", "Mantle Failed: Forward movement is blocked");
    return 0;
  }
  maxs = start;
  start.z = mresults->startPos.z + 18.0;
  PM_trace(a4, (trace_t *)v22, &maxs, &v23, &mins, &start, *(_DWORD *)(LODWORD(v4) + 416), v19);
  if ( v22[43] || *(float *)&v22[16] == 1.0 )
  {
    Mantle_DebugPrint("Mantle Failed: Can't find ledge");
    return 0;
  }
  if ( !v22[44] )
  {
    Mantle_DebugPrint("Mantle Failed: Ledge is too steep");
    return 0;
  }
  if ( *(_DWORD *)&v22[28] == 1 )
    mresults->entityNum = (unsigned __int16)Trace_GetEntityHitId((const trace_t *)v22);
  else
    mresults->entityNum = 1022;
  mresults->ledgePos.x = start.x;
  p_ledgePos = &mresults->ledgePos;
  mresults->ledgePos.y = start.y;
  v13 = start.z;
  mresults->ledgePos.z = start.z;
  v14 = (float)((float)(v13 - maxs.z) * *(float *)&v22[16]) + maxs.z;
  mresults->ledgePos.z = v14;
  v15 = v14 - mresults->startPos.z;
  if ( v15 <= 0.0 )
  {
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
            814,
            0,
            "((((mresults->ledgePos[2] - mresults->startPos[2]) > 0.0f)))",
            "((mresults->ledgePos[2] - mresults->startPos[2])) = %g",
            v15) )
      __debugbreak();
    p_ledgePos = &mresults->ledgePos;
  }
  v17 = a4->tracemask;
  mins.z = FLOAT_50_0;
  PM_trace(a4, (trace_t *)v22, p_ledgePos, &v23, &mins, p_ledgePos, *(_DWORD *)(LODWORD(v4) + 416), v17);
  if ( v22[43] )
  {
    Mantle_DebugPrint("Mantle Failed: Player can't fit crouched on ledge");
    return 0;
  }
  *(_QWORD *)&maxs.x = *(_QWORD *)&mresults->startPos.x;
  maxs.z = mresults->startPos.z + a3;
  psa = Dvar_GetFloat(mantle_check_glass_extra_range) + 16.0;
  start.x = (float)(psa * mresults->dir.x) + maxs.x;
  start.y = (float)(psa * mresults->dir.y) + maxs.y;
  start.z = (float)(mresults->dir.z * psa) + maxs.z;
  mins.z = 15.0 * 2.0;
  PM_trace(a4, (trace_t *)v22, &maxs, &v23, &mins, &start, *(_DWORD *)(LODWORD(v4) + 416), v19);
  if ( v22[43] || *(float *)&v22[16] < 1.0 && *(_DWORD *)&v22[28] == 4 )
  {
    Mantle_DebugPrint("Mantle Failed: Glass is no the way");
    return 0;
  }
  if ( (*(_DWORD *)(LODWORD(v4) + 1308) & 0x200) == 0 )
    Mount_CheckLedge(mresults, (unsigned int)&end.y, v4, a4);
  if ( (mresults->flags & 3) == 0 )
    return 0;
  *(_DWORD *)(LODWORD(v4) + 1308) |= 0x10u;
  mresults->flags |= 0x10u;
  Mantle_DebugPrint("Mantle available!");
  Mantle_CalcEndPos(a4, mresults, (unsigned int)&end.y);
  if ( (a4->cmd.button_bits.array[0] & 0x200000) != 0 )
  {
    if ( (*(_BYTE *)(LODWORD(v4) + 252) & 4) == 0 )
    {
      PM_trace(
        a4,
        (trace_t *)v22,
        &mresults->ledgePos,
        &playerMins,
        &playerMaxs,
        &mresults->ledgePos,
        *(_DWORD *)(LODWORD(v4) + 416),
        a4->tracemask);
      if ( v22[43] )
        mresults->flags |= 4u;
      PM_trace(
        a4,
        (trace_t *)v22,
        &mresults->endPos,
        &playerMins,
        &playerMaxs,
        &mresults->endPos,
        *(_DWORD *)(LODWORD(v4) + 416),
        a4->tracemask);
      if ( !v22[43] )
        mresults->flags |= 8u;
    }
    Mantle_Start((playerState_s *)LODWORD(v4), a4, mresults);
  }
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocketrouter.cpp:0x949D60
char __cdecl Hatch_CheckHatch(pmove_t *pm, pml_t *pml)
{
  playerState_s *ps; // edi
  const char *v3; // esi

  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp", 901, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = va("Checking for hatch");
  if ( !v3
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp", 216, 0, "(msg)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( Dvar_GetBool(mantle_debug) )
    Com_Printf(27, "%s\n", v3);
  if ( (ps->pm_flags & 4) != 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
          907,
          0,
          "(!( ps->pm_flags & (1<<2) ))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (pml->groundPlane & 0x1000) == 0 )
    return 0;
  if ( (pm->cmd.button_bits.array[0] & 0x200000) == 0 )
  {
    ps->mantleState.flags |= 0x1800u;
    pml->groundPlane |= 0x800u;
  }
  if ( (ps->mantleState.flags & 0x800) == 0 )
    return 0;
  Mantle_DebugPrint("Hatch Mantle available!");
  if ( (pm->cmd.button_bits.array[0] & 0x200000) == 0 )
    return 0;
  pml->groundPlane |= 0xAu;
  Mantle_Start(ps, pm, (MantleResults *)pml);
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocketrouter.cpp:0x949E80
// local variable allocation has failed, the output may be wrong!
char __usercall Hatch_Check@<al>(unsigned int a1@<ebp>, pmove_t *pm, pml_t *pml)
{
  playerState_s *ps; // esi
  float x; // xmm1_4
  float y; // xmm2_4
  float v6; // xmm7_4
  float Float; // [esp+14h] [ebp-BCh]
  float hatch_fwd; // [esp+20h] [ebp-B0h]
  _BYTE v10[144]; // [esp+24h] [ebp-ACh] OVERLAPPED BYREF
  vec3_t mantleEnd; // [esp+B4h] [ebp-1Ch] BYREF
  vec3_t mantleDir; // [esp+C0h] [ebp-10h]
  unsigned int retaddr; // [esp+D0h] [ebp+0h]

  *(_QWORD *)&mantleDir.v[1] = __PAIR64__(retaddr, a1);
  ps = pm->ps;
  *(_OWORD *)v10 = 0i64;
  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp", 1020, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !Com_SessionMode_IsMode(SESSIONMODE_ZOMBIES) )
    return 0;
  if ( Dvar_GetBool(mantle_debug) )
    Com_Printf(27, "%s\n", "====== Hatch Mantle Debug ======");
  hatch_fwd = Dvar_GetFloat(hatch_mantle_up);
  Float = Dvar_GetFloat(hatch_mantle_fwd);
  if ( !Hatch_FindHatchSurface((trace_t *)v10, (vec3_t *)&v10[132], pm, pml, &mantleEnd, hatch_fwd) )
  {
    ps->mantleState.flags &= ~0x800u;
    return 0;
  }
  memset(&v10[72], 0, 0x3Cu);
  *(_DWORD *)&v10[120] |= 0x1000u;
  x = pml->forward.x;
  y = pml->forward.y;
  *(vec3_t *)&v10[72] = mantleEnd;
  *(_QWORD *)&v10[84] = *(_QWORD *)&ps->origin.x;
  *(float *)&v10[92] = ps->origin.z;
  v6 = fsqrt((float)(y * y) + (float)(x * x));
  if ( COERCE_FLOAT(LODWORD(v6) ^ _mask__NegFloat_) >= 0.0 )
    v6 = *(float *)&FLOAT_1_0;
  *(float *)&v10[72] = x * (float)(1.0 / v6);
  *(float *)&v10[76] = y * (float)(1.0 / v6);
  *(float *)&v10[80] = (float)(1.0 / v6) * 0.0;
  *(float *)&v10[108] = (float)(*(float *)&v10[72] * Float) + *(float *)&v10[132];
  *(float *)&v10[112] = (float)(*(float *)&v10[76] * Float) + *(float *)&v10[136];
  *(float *)&v10[116] = (float)(*(float *)&v10[80] * Float) + (float)(*(float *)&v10[140] + (float)(hatch_fwd + 77.0));
  *(float *)&v10[96] = *(float *)&v10[108];
  *(float *)&v10[100] = *(float *)&v10[112];
  *(float *)&v10[104] = *(float *)&v10[116];
  Hatch_CheckHatch(pm, (pml_t *)&v10[72]);
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocketrouter.cpp:0x94A0E0
// local variable allocation has failed, the output may be wrong!
void __usercall Mantle_Check(unsigned int a1@<ebp>, pmove_t *pm, pml_t *pml)
{
  playerState_s *ps; // esi
  int eFlags; // eax
  const dvar_t *v5; // [esp-20h] [ebp-B0h]
  _BYTE v6[140]; // [esp-Ch] [ebp-9Ch] OVERLAPPED BYREF
  vec3_t mantleDir; // [esp+80h] [ebp-10h] BYREF
  unsigned int retaddr; // [esp+90h] [ebp+0h]

  *(_QWORD *)&mantleDir.v[1] = __PAIR64__(retaddr, a1);
  *(_OWORD *)v6 = 0i64;
  if ( Dvar_GetBool(mantle_debug) )
    Com_Printf(27, "%s\n", "====== Mantle Debug ======");
  pm->ps->mantleState.flags &= ~0x100u;
  v5 = mantle_enable;
  pm->ps->mountAvailable = 0;
  if ( Dvar_GetBool(v5) )
  {
    ps = pm->ps;
    if ( !pm->ps )
    {
      if ( !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp", 1245, 0, "(ps)", (const char *)&pBlock) )
        __debugbreak();
      if ( !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp", 1446, 0, "(ps)", (const char *)&pBlock) )
        __debugbreak();
    }
    ps->mantleState.flags &= 0xFFFFFF6F;
    if ( ps->pm_type < 10 )
    {
      if ( (ps->pm_flags & 4) != 0 )
      {
        Mantle_DebugPrint("Mantle Failed: Player already mantling");
      }
      else
      {
        eFlags = ps->eFlags;
        if ( (eFlags & 0xC) != 0 )
        {
          if ( (eFlags & 8) != 0 && Dvar_GetBool(prone_bipod_enable) )
            Mount_CheckProne(pm, (unsigned int)&mantleDir.y);
          Mantle_DebugPrint("Mantle Failed: Player not standing");
        }
        else if ( !Hatch_Check((unsigned int)&mantleDir.y, pm, pml)
               && Mantle_FindMantleSurface((trace_t *)v6, pm, pml, (vec3_t *)&v6[128]) )
        {
          memset(&v6[68], 0, 0x3Cu);
          *(_DWORD *)&v6[68] = *(_DWORD *)&v6[128];
          *(_DWORD *)&v6[72] = *(_DWORD *)&v6[132];
          *(_DWORD *)&v6[76] = *(_DWORD *)&v6[136];
          *(_QWORD *)&v6[80] = *(_QWORD *)&ps->origin.x;
          *(float *)&v6[88] = ps->origin.z;
          if ( ((unsigned int)&g_npPool[24648] & *(_DWORD *)&v6[20]) != 0 )
          {
            *(_DWORD *)&v6[116] |= 1u;
          }
          else if ( ((unsigned int)&g_hunk_track[160413].name[112] & *(_DWORD *)&v6[20]) != 0 )
          {
            *(_DWORD *)&v6[116] |= 2u;
          }
          if ( (*(_DWORD *)&v6[20] & 0x10000000) != 0 )
            *(_DWORD *)&v6[116] |= 0x20u;
          if ( !Mantle_CheckLedge((MantleResults *)&v6[68], (unsigned int)&mantleDir.y, 60.0, pm)
            && !Mantle_CheckLedge((MantleResults *)&v6[68], (unsigned int)&mantleDir.y, 40.0, pm) )
          {
            Mantle_CheckLedge((MantleResults *)&v6[68], (unsigned int)&mantleDir.y, 20.0, pm);
          }
        }
      }
    }
    else
    {
      Mantle_DebugPrint("Mantle Failed: Player is dead");
    }
  }
  else if ( Dvar_GetBool(mantle_debug) )
  {
    Com_Printf(27, "%s\n", "Mantle Failed: Not enabled");
  }
}

#endif // __UNIMPLEMENTED__
