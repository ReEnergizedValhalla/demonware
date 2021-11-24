// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x9357A0
void __cdecl BG_Dog_Stop_AttackIdle(
        LocalClientNum_t localClientNum,
        const entityState_s *es,
        ActorAnimStates prevState)
{
  unsigned int v3; // edi
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax

  v3 = _tls_index;
  v4 = (DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                       + _tls_index)
                                                                     + 14960)
                                                         + 120))(
                 es->number,
                 localClientNum);
  if ( v4 )
  {
    if ( prevState < ACTOR_ANIMATION_STOP_IDLE || prevState > ACTOR_ANIMATION_STOP_ATTACKIDLE_GROWL )
      BG_Dog_Stop_Init(es, localClientNum);
    Tree = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(Tree, 1u, 0.2, -1);
    v6 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v6, 0x28u, 0.1, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0x34u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v3) + 14960) + 602012),
      2u,
      1,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x9358A0
void __cdecl BG_Dog_Stop_AttackIdle_Bark(
        LocalClientNum_t localClientNum,
        const entityState_s *es,
        ActorAnimStates prevState)
{
  unsigned int v3; // edi
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax

  v3 = _tls_index;
  v4 = (DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                       + _tls_index)
                                                                     + 14960)
                                                         + 120))(
                 es->number,
                 localClientNum);
  if ( v4 )
  {
    if ( prevState < ACTOR_ANIMATION_STOP_IDLE || prevState > ACTOR_ANIMATION_STOP_ATTACKIDLE_GROWL )
      BG_Dog_Stop_Init(es, localClientNum);
    Tree = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(Tree, 1u, 0.2, -1);
    v6 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v6, 0x28u, 0.1, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0x35u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v3) + 14960) + 602012),
      2u,
      1,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x935AA0
void __cdecl BG_Dog_Pain_Main(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax

  v2 = _tls_index;
  v3 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v4 = (DObj *)v3;
  if ( v3 )
  {
    Tree = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(Tree, 0, 0.2, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      4u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960) + 602012),
      2u,
      1,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x935B50
void __cdecl BG_Dog_Pain_Front(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax

  v2 = _tls_index;
  v3 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v4 = (DObj *)v3;
  if ( v3 )
  {
    Tree = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(Tree, 0, 0.2, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0x12u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960) + 602012),
      2u,
      1,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x935C00
void __cdecl BG_Dog_Pain_Back(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax

  v2 = _tls_index;
  v3 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v4 = (DObj *)v3;
  if ( v3 )
  {
    Tree = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(Tree, 0, 0.2, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0x13u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960) + 602012),
      2u,
      1,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x935CB0
void __cdecl BG_Dog_Pain_Left(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax

  v2 = _tls_index;
  v3 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v4 = (DObj *)v3;
  if ( v3 )
  {
    Tree = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(Tree, 0, 0.2, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0x14u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960) + 602012),
      2u,
      1,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x935D60
void __cdecl BG_Dog_Pain_Right(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax

  v2 = _tls_index;
  v3 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v4 = (DObj *)v3;
  if ( v3 )
  {
    Tree = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(Tree, 0, 0.2, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0x15u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960) + 602012),
      2u,
      1,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x935E10
void __cdecl BG_Dog_Run_Pain_Front(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax

  v2 = _tls_index;
  v3 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v4 = (DObj *)v3;
  if ( v3 )
  {
    Tree = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(Tree, 0, 0.2, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0xEu,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960) + 602012),
      2u,
      1,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x935EC0
void __cdecl BG_Dog_Run_Pain_Back(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax

  v2 = _tls_index;
  v3 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v4 = (DObj *)v3;
  if ( v3 )
  {
    Tree = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(Tree, 0, 0.2, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0xFu,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960) + 602012),
      2u,
      1,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x935F70
void __cdecl BG_Dog_Run_Pain_Left(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax

  v2 = _tls_index;
  v3 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v4 = (DObj *)v3;
  if ( v3 )
  {
    Tree = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(Tree, 0, 0.2, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0x10u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960) + 602012),
      2u,
      1,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x936020
void __cdecl BG_Dog_Run_Pain_Right(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax

  v2 = _tls_index;
  v3 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v4 = (DObj *)v3;
  if ( v3 )
  {
    Tree = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(Tree, 0, 0.2, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0x11u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960) + 602012),
      2u,
      1,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x9490D0
// local variable allocation has failed, the output may be wrong!
void __usercall Mount_CheckProne(pmove_t *pm@<edi>, unsigned int a2@<ebp>)
{
  playerState_s *ps; // esi
  float proneDirectionPitch; // xmm1_4
  int tracemask; // eax
  int v5; // ecx
  float v6; // xmm0_4
  int v7; // edx
  double y; // st7
  _BYTE v9[76]; // [esp-Ch] [ebp-9Ch] OVERLAPPED BYREF
  int v10; // [esp+40h] [ebp-50h]
  vec3_t lookAngles; // [esp+44h] [ebp-4Ch] BYREF
  vec3_t dropMins; // [esp+50h] [ebp-40h] BYREF
  vec3_t dropMaxs; // [esp+5Ch] [ebp-34h] BYREF
  vec3_t lookVec; // [esp+68h] [ebp-28h] BYREF
  vec3_t traceEnd; // [esp+74h] [ebp-1Ch] BYREF
  vec3_t traceStart; // [esp+80h] [ebp-10h]
  unsigned int retaddr; // [esp+90h] [ebp+0h]

  *(_QWORD *)&traceStart.v[1] = __PAIR64__(retaddr, a2);
  ps = pm->ps;
  *(_OWORD *)v9 = 0i64;
  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp", 593, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( BG_GetWeaponDef(ps->weapon)->mountableWeapon
    && Mount_CanPlayerDeployTurret(ps)
    && turretPronePitchMax > COERCE_FLOAT(LODWORD(ps->proneDirectionPitch) & _mask__AbsFloat_) )
  {
    traceEnd = ps->origin;
    proneDirectionPitch = ps->proneDirectionPitch;
    *(float *)&v9[72] = ps->proneDirection;
    *(float *)&v9[68] = proneDirectionPitch;
    v10 = 0;
    AngleVectors((const vec3_t *)&v9[68], &dropMaxs, 0, 0);
    tracemask = pm->tracemask;
    traceEnd.z = (float)(dropMaxs.z * turretTestDist) + traceEnd.z;
    traceEnd.x = (float)(dropMaxs.x * turretTestDist) + traceEnd.x;
    lookVec.x = traceEnd.x;
    lookVec.z = traceEnd.z - heightTestDist;
    LODWORD(lookAngles.x) = LODWORD(dropTraceWidth) ^ _mask__NegFloat_;
    *(_QWORD *)&lookAngles.v[1] = LODWORD(dropTraceWidth) ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
    dropMins.x = dropTraceWidth;
    dropMins.y = dropTraceWidth;
    traceEnd.y = (float)(dropMaxs.y * turretTestDist) + traceEnd.y;
    lookVec.y = traceEnd.y;
    dropMins.z = dropTraceWidth * 2.0;
    PM_trace(pm, (trace_t *)v9, &traceEnd, &lookAngles, &dropMins, &lookVec, ps->clientNum, tracemask);
    if ( *(float *)&v9[16] < 1.0 )
    {
      v5 = pm->tracemask;
      *(_QWORD *)&traceEnd.x = *(_QWORD *)&ps->origin.x;
      v6 = ps->origin.z + turretTestFeetRaise;
      lookVec.y = (float)(dropMaxs.y * turretTestFeetDist) + traceEnd.y;
      traceEnd.z = v6;
      lookVec.x = (float)(dropMaxs.x * turretTestFeetDist) + traceEnd.x;
      lookVec.z = (float)(dropMaxs.z * turretTestFeetDist) + v6;
      PM_trace(pm, (trace_t *)v9, &traceEnd, &lookAngles, &dropMins, &lookVec, ps->clientNum, v5);
      if ( *(float *)&v9[16] < 1.0
        || (v7 = pm->tracemask,
            traceEnd = lookVec,
            lookVec.z = lookVec.z - (float)(turretTestFeetRaise + turretTestDist),
            PM_trace(pm, (trace_t *)v9, &traceEnd, &lookAngles, &dropMins, &lookVec, ps->clientNum, v7),
            *(float *)&v9[16] < 1.0) )
      {
        ps->mountAvailable = 1;
        ps->cursorHintEntIndex = 1023;
        ps->mountPos.x = ps->origin.x;
        ps->mountPos.y = ps->origin.y;
        ps->mountPos.z = ps->origin.z;
        y = ps->viewangles.y;
        ps->mantleState.flags |= 0x480u;
        ps->mountDir = y;
      }
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x949400
// local variable allocation has failed, the output may be wrong!
void __usercall Mount_CheckLedge(MantleResults *mresults@<edi>, unsigned int a2@<ebp>, float a3@<esi>, pmove_t *a4)
{
  playerState_s *ps; // esi
  float v5; // xmm0_4
  int tracemask; // ecx
  unsigned int v7; // xmm1_4
  float z; // xmm2_4
  unsigned int v9; // edx
  float angle; // [esp+4h] [ebp-D8h]
  float v12; // [esp+14h] [ebp-C8h]
  bool v13; // [esp+1Fh] [ebp-BDh]
  _BYTE v14[73]; // [esp+20h] [ebp-BCh] OVERLAPPED BYREF
  float v15; // [esp+6Ch] [ebp-70h]
  vec3_t ledgeAngles; // [esp+74h] [ebp-68h] BYREF
  vec3_t dropMaxs; // [esp+80h] [ebp-5Ch] BYREF
  vec3_t traceEnd; // [esp+8Ch] [ebp-50h] BYREF
  vec3_t dropMins; // [esp+98h] [ebp-44h] BYREF
  vec3_t ledgeVec; // [esp+A4h] [ebp-38h] BYREF
  vec3_t lookVec; // [esp+B0h] [ebp-2Ch] BYREF
  vec4_t color; // [esp+BCh] [ebp-20h] BYREF
  vec3_t traceStart; // [esp+CCh] [ebp-10h]
  unsigned int retaddr; // [esp+DCh] [ebp+0h]

  *(_QWORD *)&traceStart.v[1] = __PAIR64__(retaddr, a2);
  ps = a4->ps;
  *(_OWORD *)v14 = 0i64;
  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp", 666, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v13 = Dvar_GetInt(cg_debugMounting) > 2;
  if ( (float)((float)((float)(ps->velocity.x * ps->velocity.x) + (float)(ps->velocity.y * ps->velocity.y))
             + (float)(ps->velocity.z * ps->velocity.z)) > 0.0 )
    v13 = 0;
  v12 = mresults->ledgePos.z - ps->origin.z;
  if ( BG_GetWeaponDef(ps->weapon)->mountableWeapon
    && (mresults->flags & 0x20) != 0
    && COERCE_FLOAT(LODWORD(v12) & _mask__AbsFloat_) < 50.0
    && Mount_CanPlayerDeployTurret(ps) )
  {
    ledgeVec.x = 0.0;
    *(_QWORD *)&ledgeVec.v[1] = (unsigned int)FLOAT_1_0;
    angle = AngleNormalize360(ps->viewangles.y);
    YawVectors(angle, &ledgeVec, 0);
    dropMins.x = mresults->ledgePos.x - ps->origin.x;
    dropMins.y = mresults->ledgePos.y - ps->origin.y;
    dropMins.z = 0.0;
    Vec3Normalize(&dropMins);
    v5 = (float)((float)(dropMins.y * ledgeVec.y) + (float)(dropMins.x * ledgeVec.x)) + (float)(dropMins.z * ledgeVec.z);
    __libm_sse2_acosf(a3);
    if ( (float)(v5 * 57.295776) < 30.0 )
    {
      vectoangles(&mresults->dir, (vec3_t *)&v14[72]);
      YawVectors(v15 + 180.0, (vec3_t *)&color.g, 0);
      tracemask = a4->tracemask;
      color.v[1] = (float)(color.v[1] * 36.0) + mresults->ledgePos.x;
      *(float *)&v7 = (float)(color.v[2] * 36.0) + mresults->ledgePos.y;
      color.v[3] = (float)(color.v[3] * 36.0) + mresults->ledgePos.z;
      LODWORD(color.v[2]) = v7;
      z = ps->origin.z;
      *(_QWORD *)&dropMaxs.x = __PAIR64__(v7, LODWORD(color.v[1]));
      dropMaxs.z = z - 6.0;
      traceEnd.x = FLOAT_N2_0;
      *(_QWORD *)&traceEnd.v[1] = LODWORD(FLOAT_N2_0);
      ledgeAngles.x = FLOAT_2_0;
      *(_QWORD *)&ledgeAngles.v[1] = __PAIR64__(LODWORD(FLOAT_4_0), LODWORD(FLOAT_2_0));
      color.v[3] = z + 6.0;
      PM_trace(
        a4,
        (trace_t *)v14,
        (const vec3_t *)&color.g,
        &traceEnd,
        &ledgeAngles,
        &dropMaxs,
        ps->clientNum,
        tracemask);
      if ( *(float *)&v14[16] >= 1.0 )
      {
        if ( !v13 )
          return;
        *(_QWORD *)&lookVec.x = (unsigned int)FLOAT_1_0;
      }
      else
      {
        ps->mountAvailable = 1;
        ps->cursorHintEntIndex = 1023;
        ps->mountPos = mresults->ledgePos;
        v9 = ps->mantleState.flags & 0xFFFFFB7F | 0x80;
        ps->mountDir = v15;
        ps->mantleState.flags = v9;
        mresults->flags |= 0x80u;
        if ( !v13 )
          return;
        lookVec.x = 0.0;
        LODWORD(lookVec.y) = FLOAT_1_0;
      }
      lookVec.z = 0.0;
      LODWORD(color.v[0]) = FLOAT_1_0;
      CG_DebugBox(&dropMaxs, &traceEnd, &ledgeAngles, 0.0, (const vec4_t *)&lookVec, 0, 100);
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x94A3A0
void __usercall BG_RegisterDvars(double a1@<st0>)
{
  bool IsZombiesGame; // al
  bool v2; // al
  bool v3; // al
  bool v4; // al
  bool v5; // al
  float v6; // xmm0_4
  float value; // xmm0_4
  bool v8; // al
  bool v9; // al
  bool v10; // al
  float v11; // xmm0_4
  float v12; // xmm0_4
  bool v13; // al
  bool v14; // al
  bool v15; // al
  unsigned int v16; // [esp+14h] [ebp-10h]
  unsigned int v17; // [esp+14h] [ebp-10h]
  float strafeSpeedScale; // [esp+20h] [ebp-4h]

  bg_viewKickScale = _Dvar_RegisterFloat(
                       a1,
                       "bg_viewKickScale",
                       0.175,
                       0.0,
                       10.0,
                       0x80u,
                       "The scale to apply to the damage done to caluclate damage view kick");
  bg_viewKickMax = _Dvar_RegisterFloat(a1, "bg_viewKickMax", 90.0, 0.0, 90.0, 0x80u, "The maximum view kick");
  bg_viewKickMin = _Dvar_RegisterFloat(a1, "bg_viewKickMin", 0.5, 0.0, 90.0, 0x80u, "The minimum view kick");
  bg_viewKickRandom = _Dvar_RegisterFloat(
                        a1,
                        "bg_viewKickRandom",
                        0.40000001,
                        0.0,
                        1.0,
                        0x80u,
                        "The random direction scale view kick");
  bg_movingPlatformPitchScale = _Dvar_RegisterFloat(
                                  a1,
                                  "bg_movingPlatformPitchScale",
                                  0.0,
                                  0.0,
                                  1.0,
                                  0x1000u,
                                  "The scale to apply to pitch from the moving platform that should be applied to the player's pitch");
  bg_chargeShotAutoDischargeDelay = _Dvar_RegisterInt(
                                      a1,
                                      "bg_chargeShotAutoDischargeDelay",
                                      0,
                                      0,
                                      0x7FFFFFFF,
                                      0x80u,
                                      "If the weapon reaches the max bullet queue and is set to auto discharge, it will d"
                                      "ischarge automatically after these many milliseconds.");
  bg_chargeShotDischargeWhenQueueReachesMax = _Dvar_RegisterBool(
                                                a1,
                                                "bg_chargeShotDischargeWhenQueueReachesMax",
                                                0,
                                                0x80u,
                                                "Whether to discharge the charge shot weapon automatically when it reache"
                                                "s max bullet queue.");
  bg_chargeShotDamageIncreasePerBullet = _Dvar_RegisterFloat(
                                           a1,
                                           "bg_chargeShotDamageIncreasePerBullet",
                                           0.0,
                                           0.0,
                                           3.4028235e38,
                                           0x80u,
                                           "This value will be multiplied to the base damage and added to the base damage"
                                           ", for every extra bullet queued up. Final damage will be (base + n*(this valu"
                                           "e)*base), where n is the number of bullets queued up.");
  bg_chargeShotViewKickIncreasePerBullet = _Dvar_RegisterFloat(
                                             a1,
                                             "bg_chargeShotViewKickIncreasePerBullet",
                                             0.5,
                                             0.0,
                                             3.4028235e38,
                                             0x80u,
                                             "This value will be multiplied to the base view kick and added to the base v"
                                             "iew kick, for every extra bullet queued up.");
  bg_chargeShotQueueTime = _Dvar_RegisterInt(
                             a1,
                             "bg_chargeShotQueueTime",
                             500,
                             0,
                             0x7FFFFFFF,
                             0x80u,
                             "The time it takes in ms for the player to charge up one bullet in charge shot type weapons.");
  bg_chargeShotPenetrationMultiplier = _Dvar_RegisterFloat(
                                         a1,
                                         "bg_chargeShotPenetrationMultiplier",
                                         1.0,
                                         0.0,
                                         30.0,
                                         0x80u,
                                         "Multiplier for extra bullet penetration for charge shot weapons. This stacks ad"
                                         "ditively with the bullet penetration perk.");
  bg_chargeShotMaxBulletsInQueue = _Dvar_RegisterInt(
                                     a1,
                                     "bg_chargeShotMaxBulletsInQueue",
                                     3,
                                     0,
                                     0x7FFFFFFF,
                                     0x80u,
                                     "Maximum number of bullets that can be queued up in charge shot type weapons.");
  bg_chargeShotFireWhenQueueReachesMax = _Dvar_RegisterBool(
                                           a1,
                                           "bg_chargeShotFireWhenQueueReachesMax",
                                           0,
                                           0x80u,
                                           "Whether to fire the charge shot weapon automatically when it reaches max bullet queue.");
  bg_chargeShotUseOneAmmoForMultipleBullets = _Dvar_RegisterBool(
                                                a1,
                                                "bg_chargeShotUseOneAmmoForMultipleBullets",
                                                0,
                                                0x80u,
                                                "If set, the ammo count will be reduced only by one, even though multiple"
                                                " bullets are fired.");
  tu14_bg_chargeShotExponentialAmmoPerChargeLevel = _Dvar_RegisterBool(
                                                      a1,
                                                      "tu14_bg_chargeShotExponentialAmmoPerChargeLevel",
                                                      0,
                                                      0x1000u,
                                                      "If set, the ammo required will be \"charge level -> ammo required\""
                                                      ": 1 -> 1, 2 -> 3, 3 -> 6.");
  bg_chargeShotAutoFireDelay = _Dvar_RegisterInt(
                                 a1,
                                 "bg_chargeShotAutoFireDelay",
                                 0,
                                 0,
                                 0x7FFFFFFF,
                                 0x80u,
                                 "If the weapon reaches the max bullet queue and is set to auto fire, it will fire automa"
                                 "tically after these many milliseconds.");
  bg_chargeShotMaxViewKick = _Dvar_RegisterFloat(
                               a1,
                               "bg_chargeShotMaxViewKick",
                               85.0,
                               0.0,
                               3.4028235e38,
                               0x80u,
                               "The view kick will not go beyond this value no matter how many bullets are queued up.");
  bg_chargeShotCenterSpeedReductionPerBullet = _Dvar_RegisterFloat(
                                                 a1,
                                                 "bg_chargeShotCenterSpeedReductionPerBullet",
                                                 0.075000003,
                                                 0.0,
                                                 3.4028235e38,
                                                 0x80u,
                                                 "This value will be multiplied to the base center speed and subtracted f"
                                                 "rom the base center speed, for every extra bullet queued up.");
  bg_chargeShotMinCenterSpeed = _Dvar_RegisterFloat(
                                  a1,
                                  "bg_chargeShotMinCenterSpeed",
                                  350.0,
                                  0.0,
                                  3.4028235e38,
                                  0x80u,
                                  "The recenter speed will never go below this value no matter how many bullets are queued up.");
  bg_chargeShotMaxBulletQueueOnEMP = _Dvar_RegisterInt(
                                       a1,
                                       "bg_chargeShotMaxBulletQueueOnEMP",
                                       1,
                                       0,
                                       0x7FFFFFFF,
                                       0x80u,
                                       "Max bullets which can be queued if the player is EMPed.");
  player_view_pitch_up = _Dvar_RegisterFloat(
                           a1,
                           "player_view_pitch_up",
                           85.0,
                           -90.0,
                           90.0,
                           0x1180u,
                           "Maximum angle that the player can look up");
  player_view_pitch_down = _Dvar_RegisterFloat(
                             a1,
                             "player_view_pitch_down",
                             85.0,
                             -90.0,
                             90.0,
                             0x1180u,
                             "Maximum angle that the player can look down");
  player_view_pitch_up_ads = _Dvar_RegisterFloat(
                               a1,
                               "player_view_pitch_up_ads",
                               85.0,
                               0.0,
                               90.0,
                               0x180u,
                               "Maximum angle that the player can look up (ADS)");
  player_view_pitch_down_ads = _Dvar_RegisterFloat(
                                 a1,
                                 "player_view_pitch_down_ads",
                                 85.0,
                                 0.0,
                                 90.0,
                                 0x180u,
                                 "Maximum angle that the player can look down (ADS");
  player_lean_shift = _Dvar_RegisterVec2(
                        a1,
                        "player_lean_shift",
                        5.0,
                        2.5,
                        0.0,
                        20.0,
                        0x80u,
                        "Amount to shift the player 3rd person model when leaning(x:left, y:right)");
  player_lean_shift_crouch = _Dvar_RegisterVec2(
                               a1,
                               "player_lean_shift_crouch",
                               12.5,
                               2.5,
                               0.0,
                               20.0,
                               0x80u,
                               "Amount to shift the player 3rd person model when crouch leaning(x:left, y:right)");
  player_lean_rotate = _Dvar_RegisterVec2(
                         a1,
                         "player_lean_rotate",
                         1.25,
                         1.25,
                         0.0,
                         3.0,
                         0x80u,
                         "Amount to rotate the player 3rd person model when leaning(x:left, y:right)");
  player_lean_rotate_crouch = _Dvar_RegisterVec2(
                                a1,
                                "player_lean_rotate_crouch",
                                1.0,
                                1.0,
                                0.0,
                                3.0,
                                0x80u,
                                "Amount to rotate the player 3rd person model when crouch leaning(x:left, y:right)");
  bg_ladder_yawcap = _Dvar_RegisterFloat(
                       a1,
                       "bg_ladder_yawcap",
                       100.0,
                       0.0,
                       360.0,
                       0x180u,
                       "The maximum angle that a player can look around while on a ladder");
  bg_prone_yawcap = _Dvar_RegisterFloat(
                      a1,
                      "bg_prone_yawcap",
                      45.0,
                      0.0,
                      360.0,
                      0x180u,
                      "The maximum angle that a player can look around quickly while prone");
  bg_foliagesnd_minspeed = _Dvar_RegisterFloat(
                             a1,
                             "bg_foliagesnd_minspeed",
                             40.0,
                             0.0,
                             3.4028235e38,
                             0x180u,
                             "The speed that a player must be going to make minimum noise while moving through foliage");
  bg_foliagesnd_maxspeed = _Dvar_RegisterFloat(
                             a1,
                             "bg_foliagesnd_maxspeed",
                             180.0,
                             0.0,
                             3.4028235e38,
                             0x180u,
                             "The speed that a player must be going to make maximum noise while moving through foliage");
  bg_foliagesnd_slowinterval = _Dvar_RegisterInt(
                                 a1,
                                 "bg_foliagesnd_slowinterval",
                                 1500,
                                 0,
                                 0x7FFFFFFF,
                                 0x180u,
                                 "The time between each foliage sound when moving slowly");
  bg_foliagesnd_fastinterval = _Dvar_RegisterInt(
                                 a1,
                                 "bg_foliagesnd_fastinterval",
                                 500,
                                 0,
                                 0x7FFFFFFF,
                                 0x180u,
                                 "The time between each foliage sound when moving quickly");
  bg_foliagesnd_resetinterval = _Dvar_RegisterInt(
                                  a1,
                                  "bg_foliagesnd_resetinterval",
                                  500,
                                  0,
                                  0x7FFFFFFF,
                                  0x180u,
                                  "The time interval before foliage sounds are reset after the player has stopped moving");
  IsZombiesGame = Com_SessionMode_IsZombiesGame();
  bg_friendlyFire = _Dvar_RegisterInt(a1, "scr_team_fftype", IsZombiesGame, 0, 0x7FFFFFFF, 4u, "Friendly fire status");
  bg_fallDamageMinHeight = _Dvar_RegisterFloat(
                             a1,
                             "bg_fallDamageMinHeight",
                             128.0,
                             1.0,
                             3.4028235e38,
                             0x180u,
                             "The height that a player will start to take minimum damage if they fall");
  bg_fallDamageMaxHeight = _Dvar_RegisterFloat(
                             a1,
                             "bg_fallDamageMaxHeight",
                             300.0,
                             1.0,
                             3.4028235e38,
                             0x180u,
                             "The height that a player will take maximum damage when falling");
  friction = _Dvar_RegisterFloat(a1, "friction", 5.5, 0.0, 100.0, 0x180u, "Player friction");
  stopspeed = _Dvar_RegisterFloat(a1, "stopspeed", 100.0, 0.0, 1000.0, 0x180u, "The player deceleration");
  cg_ufo_scaler = _Dvar_RegisterFloat(
                    a1,
                    "cg_ufo_scaler",
                    6.0,
                    0.001,
                    1000.0,
                    0x180u,
                    "The speed at which ufo camera moves");
  bg_swingSpeed = _Dvar_RegisterFloat(
                    a1,
                    "bg_swingSpeed",
                    0.15000001,
                    0.0,
                    5.0,
                    0x80u,
                    "The rate at which the player's legs swing around when strafing(multi-player only)");
  bg_proneSwingSpeed = _Dvar_RegisterFloat(
                         a1,
                         "bg_proneSwingSpeed",
                         0.079999998,
                         0.0,
                         5.0,
                         0x80u,
                         "The rate at which the player's legs swing around when turning and prone");
  bg_legYawTolerance = _Dvar_RegisterFloat(
                         a1,
                         "bg_legYawTolerance",
                         40.0,
                         0.0,
                         180.0,
                         0x80u,
                         "The amount the player's leg yaw can differ from his torso before moving to match");
  bg_legYawCrouchTolerance = _Dvar_RegisterFloat(
                               a1,
                               "bg_legYawCrouchTolerance",
                               10.0,
                               0.0,
                               180.0,
                               0x80u,
                               "The amount the player's leg yaw can differ from his torso before moving to match");
  bg_legYawProneTolerance = _Dvar_RegisterFloat(
                              a1,
                              "bg_legYawProneTolerance",
                              2.0,
                              0.0,
                              180.0,
                              0x80u,
                              "The amount the player's leg yaw can differ from his torso before moving to match while prone");
  bg_viewBobAmplitudeSprinting = _Dvar_RegisterVec2(
                                   a1,
                                   "bg_viewBobAmplitudeSprinting",
                                   0.02,
                                   0.014,
                                   0.0,
                                   1.0,
                                   0x180u,
                                   "The multiplier to apply to the player's speed to get the bob amplitude while sprinting");
  bg_viewBobAmplitudeDtp = _Dvar_RegisterVec2(
                             a1,
                             "bg_viewBobAmplitudeDtp",
                             0.0020000001,
                             0.0020000001,
                             0.0,
                             1.0,
                             0x180u,
                             "The multiplier to apply to the player's speed to get the bob amplitude while diving to prone");
  bg_viewBobAmplitudeSwimming = _Dvar_RegisterVec2(
                                  a1,
                                  "bg_viewBobAmplitudeSwimming",
                                  3.0,
                                  2.0,
                                  0.0,
                                  8.0,
                                  0x4080u,
                                  "The multiplier to apply to the player's speed to get the bob amplitude while swimming");
  bg_viewBobAmplitudeStanding = _Dvar_RegisterVec2(
                                  a1,
                                  "bg_viewBobAmplitudeStanding",
                                  0.0070000002,
                                  0.0070000002,
                                  0.0,
                                  1.0,
                                  0x4080u,
                                  "The multiplier to apply to the player's speed to get the bob amplitude while standing");
  bg_viewBobAmplitudeStandingAds = _Dvar_RegisterVec2(
                                     a1,
                                     "bg_viewBobAmplitudeStandingAds",
                                     0.0070000002,
                                     0.0070000002,
                                     0.0,
                                     1.0,
                                     0x1180u,
                                     "The multiplier to apply to the player's speed to get the view bob amplitude while standing and ADS");
  bg_viewBobAmplitudeDucked = _Dvar_RegisterVec2(
                                a1,
                                "bg_viewBobAmplitudeDucked",
                                0.0074999998,
                                0.0074999998,
                                0.0,
                                1.0,
                                0x180u,
                                "The multiplier to apply to the player's speed to get the bob amplitude while ducking");
  bg_viewBobAmplitudeDuckedAds = _Dvar_RegisterVec2(
                                   a1,
                                   "bg_viewBobAmplitudeDuckedAds",
                                   0.0074999998,
                                   0.0074999998,
                                   0.0,
                                   1.0,
                                   0x180u,
                                   "The multiplier to apply to the player's speed to get the view bob amplitude while ducking ADS");
  bg_viewBobAmplitudeProne = _Dvar_RegisterVec2(
                               a1,
                               "bg_viewBobAmplitudeProne",
                               0.079999998,
                               0.039999999,
                               0.0,
                               1.0,
                               0x180u,
                               "The multiplier to apply to the player's speed to get the bob amplitude while prone");
  bg_viewBobAmplitudeRoll = _Dvar_RegisterFloat(
                              a1,
                              "bg_viewBobAmplitudeRoll",
                              1.5,
                              0.0,
                              90.0,
                              0x180u,
                              "The amplitude applied to the roll for view bobbing");
  bg_viewBobMax = _Dvar_RegisterFloat(a1, "bg_bobMax", 8.0, 0.0, 36.0, 0x180u, "The maximum allowed bob amplitude");
  bg_forceDurationOverride = _Dvar_RegisterInt(
                               a1,
                               "bg_forceDurationOverride",
                               -1,
                               -1,
                               10000,
                               0x80u,
                               "Force all player animations to have this duration");
  bg_blendTimeOverride = _Dvar_RegisterInt(
                           a1,
                           "bg_blendTimeOverride",
                           -1,
                           -1,
                           10000,
                           0x80u,
                           "Force all player animations to have this blendtime");
  bg_weaponBobAmplitudeSprinting = _Dvar_RegisterVec2(
                                     a1,
                                     "bg_weaponBobAmplitudeSprinting",
                                     0.02,
                                     0.014,
                                     0.0,
                                     1.0,
                                     0x180u,
                                     "The multiplier to apply to the player's speed to get the weapon bob amplitude while sprinting");
  bg_weaponBobAmplitudeDtp = _Dvar_RegisterVec2(
                               a1,
                               "bg_weaponBobAmplitudeDtp",
                               0.0020000001,
                               0.0020000001,
                               0.0,
                               1.0,
                               0x180u,
                               "The multiplier to apply to the player's speed to get the weapon bob amplitude while diving to prone");
  bg_weaponBobAmplitudeSwimming = _Dvar_RegisterVec2(
                                    a1,
                                    "bg_weaponBobAmplitudeSwimming",
                                    4.0,
                                    4.0,
                                    0.0,
                                    8.0,
                                    0x4080u,
                                    "The multiplier to apply to the player's speed to get the weapon bob amplitude while swimming");
  bg_weaponBobAmplitudeStanding = _Dvar_RegisterVec2(
                                    a1,
                                    "bg_weaponBobAmplitudeStanding",
                                    0.055,
                                    0.025,
                                    0.0,
                                    1.0,
                                    0x4080u,
                                    "The multiplier to apply to the player's speed to get the weapon bob amplitude while standing");
  bg_weaponBobAmplitudeDucked = _Dvar_RegisterVec2(
                                  a1,
                                  "bg_weaponBobAmplitudeDucked",
                                  0.045000002,
                                  0.025,
                                  0.0,
                                  1.0,
                                  0x180u,
                                  "The multiplier to apply to the player's speed to get the weapon bob amplitude while ducking");
  bg_weaponBobAmplitudeProne = _Dvar_RegisterVec2(
                                 a1,
                                 "bg_weaponBobAmplitudeProne",
                                 0.02,
                                 0.0049999999,
                                 0.0,
                                 1.0,
                                 0x180u,
                                 "The multiplier to apply to the player's speed to get the weapon bob amplitude while prone");
  bg_weaponBobAmplitudeRoll = _Dvar_RegisterFloat(
                                a1,
                                "bg_weaponBobAmplitudeRoll",
                                1.5,
                                0.0,
                                90.0,
                                0x180u,
                                "The amplitude applied to the roll for weapon bobbing");
  bg_weaponBobAmplitudeRiding = _Dvar_RegisterVec2(
                                  a1,
                                  "bg_weaponBobAmplitudeRiding",
                                  0.0027000001,
                                  0.0049999999,
                                  0.0,
                                  1.0,
                                  0x180u,
                                  "The multiplier to apply to the vehicle's speed to get the weapon bob amplitude while riding");
  bg_weaponBobAmplitudeBaseLaser = _Dvar_RegisterFloat(
                                     a1,
                                     "bg_weaponBobAmplitudeBaseLaser",
                                     0.050000001,
                                     0.0,
                                     1.0,
                                     0,
                                     "The base speed-based weapon bob amplitude while holding a laser sight weapon");
  bg_weaponBobAmplitudeRollLaser = _Dvar_RegisterFloat(
                                     a1,
                                     "bg_weaponBobAmplitudeRollLaser",
                                     1.0,
                                     0.0,
                                     90.0,
                                     0x180u,
                                     "The amplitude applied to the roll for weapon bobbing while holding a laser sight weapon");
  bg_weaponBobMax = _Dvar_RegisterFloat(
                      a1,
                      "bg_weaponBobMax",
                      8.0,
                      0.0,
                      36.0,
                      0x180u,
                      "The maximum allowed weapon/viewmodel bob amplitude");
  bg_weaponBobLag = _Dvar_RegisterFloat(
                      a1,
                      "bg_weaponBobLag",
                      0.25,
                      -1.0,
                      1.0,
                      0x180u,
                      "The lag that will be applied the weapon bob cycle");
  bg_weaponBobFrequencySwimming = _Dvar_RegisterFloat(
                                    a1,
                                    "bg_weaponBobFrequencySwimming",
                                    0.1,
                                    0.0,
                                    5.0,
                                    0x4080u,
                                    "Controls the speed of the camera bob while swimming");
  bg_weaponBobHeavyWeaponScalar = _Dvar_RegisterFloat(
                                    a1,
                                    "bg_weaponBobHeavyWeaponScalar",
                                    1.5,
                                    1.0,
                                    1000.0,
                                    0x4080u,
                                    "Scalar applied to bob angles for heavy weapons (minigun)");
  bg_forceExplosiveBullets = _Dvar_RegisterBool(
                               a1,
                               "bg_forceExplosiveBullets",
                               0,
                               0x180u,
                               "When set, all bullet weapons will fire explosive rounds (Simulates Perk)");
  v16 = Com_SessionMode_IsZombiesGame() ? 4096 : 128;
  v2 = Com_SessionMode_IsZombiesGame();
  tu13_bg_enableBulletWeaponBounce = _Dvar_RegisterBool(
                                       a1,
                                       "tu13_bg_enableBulletWeaponBounce",
                                       v2,
                                       v16,
                                       "Safety dvar to disable the bouncing bullets (only enables in zombies and if the w"
                                       "eapon has bForceBounce set)");
  bg_weaponOffscreenReloadScale = _Dvar_RegisterFloat(
                                    a1,
                                    "bg_weaponOffscreenReloadScale",
                                    1.0,
                                    0.0,
                                    1.0,
                                    0x4080u,
                                    "The multiplier to apply to the offscreen reload time");
  bg_aimSpreadMoveSpeedThreshold = _Dvar_RegisterFloat(
                                     a1,
                                     "bg_aimSpreadMoveSpeedThreshold",
                                     11.0,
                                     0.0,
                                     300.0,
                                     0x180u,
                                     "When player is moving faster than this speed, the aim spread will increase");
  bg_maxGrenadeIndicatorSpeed = _Dvar_RegisterFloat(
                                  a1,
                                  "bg_maxGrenadeIndicatorSpeed",
                                  100.0,
                                  0.0,
                                  1000.0,
                                  0x180u,
                                  "Maximum speed of grenade that will show up in indicator and can be thrown back.");
  bg_forceAnimOverrideTimerCheck = _Dvar_RegisterBool(
                                     a1,
                                     "bg_forceAnimOverrideTimerCheck",
                                     0,
                                     0x180u,
                                     "Enables a change that may fix prone animation 'snaking' issues.");
  bg_playerAnimStanceAllowMovementInteruptTime = _Dvar_RegisterInt(
                                                   a1,
                                                   "bg_playerAnimStanceAllowMovementInteruptTime",
                                                   200,
                                                   0,
                                                   1000,
                                                   0x180u,
                                                   "When enabled, will force movement override on all stance transition a"
                                                   "nimations, but only after the given time has elapsed on the transition anim.");
  v17 = Com_SessionMode_IsZombiesGame() ? 4096 : 128;
  v3 = Com_SessionMode_IsZombiesGame();
  disableLookAtEntityLogic = _Dvar_RegisterBool(
                               a1,
                               "disableLookAtEntityLogic",
                               !v3,
                               v17,
                               "Disables the Player_UpdateLookAtEntity logic (expensive)");
  player_breath_hold_time = _Dvar_RegisterFloat(
                              a1,
                              "player_breath_hold_time",
                              4.5,
                              0.0,
                              30.0,
                              0x180u,
                              "The maximum time a player can hold his breath");
  player_breath_gasp_time = _Dvar_RegisterFloat(
                              a1,
                              "player_breath_gasp_time",
                              0.0,
                              0.0,
                              30.0,
                              0x180u,
                              "The amount of time a player will gasp once they can breath again");
  player_breath_fire_delay = _Dvar_RegisterFloat(
                               a1,
                               "player_breath_fire_delay",
                               0.0,
                               0.0,
                               30.0,
                               0x180u,
                               "The amount of time subtracted from the player remaining breath time when a weapon is fired");
  player_breath_gasp_scale = _Dvar_RegisterFloat(
                               a1,
                               "player_breath_gasp_scale",
                               2.5,
                               0.0,
                               50.0,
                               0x180u,
                               "Scale value to apply to the target waver during a gasp");
  player_breath_hold_lerp = _Dvar_RegisterFloat(
                              a1,
                              "player_breath_hold_lerp",
                              1.5,
                              0.0,
                              50.0,
                              0x180u,
                              "The interpolation rate for the target waver amplitude when holding breath");
  player_breath_gasp_lerp = _Dvar_RegisterFloat(
                              a1,
                              "player_breath_gasp_lerp",
                              4.0,
                              0.0,
                              50.0,
                              0x180u,
                              "The interpolation rate for the target waver amplitude when gasping");
  player_breath_snd_lerp = _Dvar_RegisterFloat(
                             a1,
                             "player_breath_snd_lerp",
                             2.0,
                             0.0,
                             100.0,
                             0x180u,
                             "The interpolation rate for the player hold breath sound");
  player_breath_snd_delay = _Dvar_RegisterFloat(
                              a1,
                              "player_breath_snd_delay",
                              1.0,
                              0.0,
                              2.0,
                              0x180u,
                              "The delay before playing the breathe in sound");
  player_scopeExitOnDamage = _Dvar_RegisterBool(
                               a1,
                               "player_scopeExitOnDamage",
                               0,
                               0x180u,
                               "Exit the scope if the player takes damage");
  player_adsExitDelay = _Dvar_RegisterInt(
                          a1,
                          "player_adsExitDelay",
                          0,
                          0,
                          1000,
                          0x180u,
                          "Delay before exiting aim down sight");
  player_move_factor_on_torso = _Dvar_RegisterFloat(
                                  a1,
                                  "player_move_factor_on_torso",
                                  0.0,
                                  0.0,
                                  1.0,
                                  0x80u,
                                  "The contribution movement direction has on player torso direction(multi-player only)");
  player_debugHealth = _Dvar_RegisterBool(
                         a1,
                         "player_debugHealth",
                         0,
                         0x180u,
                         "Turn on debugging info for player health");
  player_debugSprint = _Dvar_RegisterBool(
                         a1,
                         "player_debugSprint",
                         0,
                         0x80u,
                         "Turn on debugging info for player sprint");
  player_sustainAmmo = _Dvar_RegisterBool(
                         a1,
                         "player_sustainAmmo",
                         0,
                         0x80u,
                         "Firing weapon will not decrease clip ammo.");
  player_clipSizeMultiplier = _Dvar_RegisterFloat(
                                a1,
                                "player_clipSizeMultiplier",
                                1.0,
                                0.0,
                                3.4028235e38,
                                0x80u,
                                "Changes the clip size of weapons with more than one bullet in their clip.");
  player_lastStandBleedoutTime = _Dvar_RegisterFloat(
                                   a1,
                                   "player_lastStandBleedoutTime",
                                   30.0,
                                   0.0,
                                   3.4028235e38,
                                   0x4080u,
                                   "The time taken by the player to completely bleedout when in last stand (pro version).");
  player_lastStandBleedoutTimeNoRevive = _Dvar_RegisterFloat(
                                           a1,
                                           "player_lastStandBleedoutTimeNoRevive",
                                           10.0,
                                           0.0,
                                           3.4028235e38,
                                           0x80u,
                                           "The time taken by the player to completely bleedout when in last stand (non-pro version).");
  revive_time_taken = _Dvar_RegisterFloat(
                        a1,
                        "revive_time_taken",
                        1.15,
                        0.0,
                        3.4028235e38,
                        0x80u,
                        "The time it takes to revive a player in last stand.");
  player_lastStandHealthOverlayTime = _Dvar_RegisterFloat(
                                        a1,
                                        "player_lastStandHealthOverlayTime",
                                        8.0,
                                        0.0,
                                        3.4028235e38,
                                        0x80u,
                                        "The time at the end of last stand to apply health (red) overlay");
  player_reviveTriggerRadius = _Dvar_RegisterFloat(
                                 a1,
                                 "player_reviveTriggerRadius",
                                 64.0,
                                 0.0,
                                 256.0,
                                 0x80u,
                                 "The radius for the hint string and revive radius");
  player_revivePlayerListCycleTime = _Dvar_RegisterFloat(
                                       a1,
                                       "player_revivePlayerListCycleTime",
                                       2.0,
                                       0.0,
                                       3.4028235e38,
                                       0x80u,
                                       "The time for cycling through the list of players who are in last stand.");
  bg_vsmode_hud = _Dvar_RegisterBool(a1, "bg_vsmode_hud", 0, 0x180u, "Used to control diferences in vsmode hud.");
  bg_dog_swim_enabled = _Dvar_RegisterBool(
                          a1,
                          "bg_dog_swim_enabled",
                          0,
                          0x100u,
                          "Dogs will play the dog swim anim when in water.");
  bg_dog_swim_water_min = _Dvar_RegisterFloat(
                            a1,
                            "bg_dog_swim_water_min",
                            20.0,
                            0.0,
                            100.0,
                            0x20000u,
                            "Trace for water height starts at this z");
  bg_dog_swim_water_max = _Dvar_RegisterFloat(
                            a1,
                            "bg_dog_swim_water_max",
                            40.0,
                            0.0,
                            100.0,
                            0x20000u,
                            "Trace for water height ends at this z");
  player_enableShuffleAnims = _Dvar_RegisterBool(
                                a1,
                                "player_enableShuffleAnims",
                                0,
                                0x80u,
                                "Whether players should play shuffle anims at low speeds");
  player_animRunThreshhold = _Dvar_RegisterFloat(
                               a1,
                               "player_animRunThreshhold",
                               140.0,
                               0.0,
                               50000.0,
                               0x80u,
                               "The speed at which the player will animate as though they are running");
  player_animWalkThreshhold = _Dvar_RegisterFloat(
                                a1,
                                "player_animWalkThreshhold",
                                30.0,
                                0.0,
                                50000.0,
                                0x80u,
                                "The speed at which the player will animate as though they are walking");
  player_runbkThreshhold = _Dvar_RegisterFloat(
                             a1,
                             "player_runbkThreshhold",
                             60.0,
                             0.0,
                             50000.0,
                             0x180u,
                             "The speed threshold before a player is considered to be running backwards");
  player_moveThreshhold = _Dvar_RegisterFloat(
                            a1,
                            "player_moveThreshhold",
                            2.0,
                            0.0000000099999999,
                            20.0,
                            0x180u,
                            "The speed at which the player is considered to be moving for the purposes of \n"
                            "view model bob and multiplayer model movement");
  player_footstepsThreshhold = _Dvar_RegisterFloat(
                                 a1,
                                 "player_footstepsThreshhold",
                                 10.0,
                                 0.0,
                                 50000.0,
                                 0x180u,
                                 "The minimum speed at which the player makes loud footstep noises");
  player_runThreshhold = _Dvar_RegisterFloat(
                           a1,
                           "player_runThreshhold",
                           110.0,
                           0.0,
                           50000.0,
                           0x180u,
                           "The speed threshold before a player is considered to be running forwards");
  player_knockbackMoveThreshhold = _Dvar_RegisterFloat(
                                     a1,
                                     "player_knockbackMoveThreshhold",
                                     160.0,
                                     0.0,
                                     50000.0,
                                     0x180u,
                                     "The speed threshold before a player is considered to be running forwards after applying knockback");
  player_sprintThreshhold = _Dvar_RegisterFloat(
                              a1,
                              "player_sprintThreshhold",
                              185.0,
                              0.0,
                              50000.0,
                              0x180u,
                              "The speed threshhold before a player is considered to be sprinting");
  player_waterSpeedScale = _Dvar_RegisterFloat(
                             a1,
                             "player_waterSpeedScale",
                             1.3,
                             0.0,
                             20.0,
                             0x4080u,
                             "Water movement speed scalar.  The larger the value, the faster the movement.");
  player_sliding_friction = _Dvar_RegisterFloat(
                              a1,
                              "player_sliding_friction",
                              1.5,
                              0.0,
                              100.0,
                              0x4080u,
                              "Controls the friction during slide.");
  v4 = Com_SessionMode_IsZombiesGame();
  player_sliding_wishspeed = _Dvar_RegisterFloat(
                               a1,
                               "player_sliding_wishspeed",
                               4000.0,
                               0.0,
                               10000.0,
                               (v4 ? 4096 : 128) | 0x4000,
                               "Controls how fast the player will slide.");
  player_slick_wishspeed = _Dvar_RegisterFloat(
                             a1,
                             "player_slick_wishspeed",
                             1000.0,
                             0.0,
                             10000.0,
                             0x4080u,
                             "Controls how fast the player will slide on a flat slick surface.");
  player_slick_invspeed = _Dvar_RegisterFloat(
                            a1,
                            "player_slick_invspeed",
                            150.0,
                            0.0,
                            10000.0,
                            0x4080u,
                            "Controls how much player speed is used in slick surface acceleration.");
  player_slick_accel = _Dvar_RegisterFloat(
                         a1,
                         "player_slick_accel",
                         0.25,
                         0.0,
                         10.0,
                         0x4080u,
                         "Controls how fast the player accelerates on a flat slick surface.");
  v5 = Com_SessionMode_IsZombiesGame();
  player_sliding_velocity_cap = _Dvar_RegisterFloat(
                                  a1,
                                  "player_sliding_velocity_cap",
                                  500.0,
                                  0.0,
                                  10000.0,
                                  (v5 ? 4096 : 128) | 0x4000,
                                  "Velocity threshold for the player slide.");
  if ( Com_IsClientConsole() )
    v6 = *(float *)&FLOAT_1_0;
  else
    v6 = FLOAT_0_80000001;
  strafeSpeedScale = v6;
  if ( Com_IsClientConsole() )
    value = *(float *)&FLOAT_1_0;
  else
    value = FLOAT_0_69999999;
  player_strafeSpeedScale = _Dvar_RegisterFloat(
                              a1,
                              "player_strafeSpeedScale",
                              strafeSpeedScale,
                              0.0,
                              20.0,
                              0x180u,
                              "The scale applied to the player speed when strafing");
  player_backSpeedScale = _Dvar_RegisterFloat(
                            a1,
                            "player_backSpeedScale",
                            value,
                            0.0,
                            20.0,
                            0x180u,
                            "The scale applied to the player speed when moving backwards");
  player_strafeAnimCosAngle = _Dvar_RegisterFloat(
                                a1,
                                "player_strafeAnimCosAngle",
                                0.5,
                                0.0,
                                1.0,
                                0x180u,
                                "Cosine of the angle which player starts using strafe animations");
  player_slopeAnimAngle = _Dvar_RegisterFloat(
                            a1,
                            "player_slopeAnimAngle",
                            30.0,
                            15.0,
                            80.0,
                            0x80u,
                            "Angle at which the player will start animating differently when going up or down slopes");
  player_spectateSpeedScale = _Dvar_RegisterFloat(
                                a1,
                                "player_spectateSpeedScale",
                                1.0,
                                0.0,
                                20.0,
                                0x180u,
                                "The scale applied to the player speed when spectating");
  player_enduranceSpeedScale = _Dvar_RegisterFloat(
                                 a1,
                                 "player_enduranceSpeedScale",
                                 1.7,
                                 1.0,
                                 20.0,
                                 0x180u,
                                 "The scale applied to the player speed when they have endurance perk");
  player_zombieSprintSpeedScale = _Dvar_RegisterFloat(
                                    a1,
                                    "player_zombieSprintSpeedScale",
                                    1.37,
                                    0.1,
                                    20.0,
                                    0x180u,
                                    "The scale applied to the player speed when they are a sprinting player zombie");
  player_zombieSpeedScale = _Dvar_RegisterFloat(
                              a1,
                              "player_zombieSpeedScale",
                              1.21,
                              0.1,
                              20.0,
                              0x180u,
                              "The scale applied to the player speed when they are a walking or running player zombie");
  player_sprintForwardMinimum = _Dvar_RegisterInt(
                                  a1,
                                  "player_sprintForwardMinimum",
                                  105,
                                  0,
                                  255,
                                  0x100u,
                                  "The minimum forward deflection required to maintain a sprint");
  player_sprintSpeedScale = _Dvar_RegisterFloat(
                              a1,
                              "player_sprintSpeedScale",
                              1.5,
                              0.0,
                              5.0,
                              0x180u,
                              "The scale applied to the player speed when sprinting");
  player_sprintUnlimited = _Dvar_RegisterBool(
                             a1,
                             "player_sprintUnlimited",
                             0,
                             0x100u,
                             "Whether players can sprint forever or not");
  player_sprintTime = _Dvar_RegisterFloat(
                        a1,
                        "player_sprintTime",
                        4.0,
                        0.0,
                        12.8,
                        0x100u,
                        "The base length of time a player can sprint");
  player_sprintMinTime = _Dvar_RegisterFloat(
                           a1,
                           "player_sprintMinTime",
                           1.0,
                           0.0,
                           12.8,
                           0x180u,
                           "The minimum sprint time needed in order to start sprinting");
  player_sprintRechargePause = _Dvar_RegisterFloat(
                                 a1,
                                 "player_sprintRechargePause",
                                 0.0,
                                 0.0,
                                 9000.0,
                                 0x180u,
                                 "The length of time the meter will pause before starting to recharge after a player sprints");
  player_sprintStrafeSpeedScale = _Dvar_RegisterFloat(
                                    a1,
                                    "player_sprintStrafeSpeedScale",
                                    0.667,
                                    0.0,
                                    2.0,
                                    0x180u,
                                    "The speed at which you can strafe while sprinting");
  player_sprintCameraBob = _Dvar_RegisterFloat(
                             a1,
                             "player_sprintCameraBob",
                             0.5,
                             0.0,
                             2.0,
                             0x180u,
                             "The speed the camera bobs while you sprint");
  player_turnAnims = _Dvar_RegisterBool(
                       a1,
                       "player_turnAnims",
                       1,
                       0x180u,
                       "Use animations to turn a player's model in multiplayer");
  player_bayonetLaunchProof = _Dvar_RegisterBool(
                                a1,
                                "player_bayonetLaunchProof",
                                1,
                                0x80u,
                                "Adds extra code to check for bayonet launching, preventing related exploits.");
  player_bayonetLaunchDebugging = _Dvar_RegisterBool(
                                    a1,
                                    "player_bayonetLaunchDebugging",
                                    0,
                                    0x80u,
                                    "Simulates bayonet charge without requiring an enemy to do so.");
  player_bayonetLaunchZCap = _Dvar_RegisterFloat(
                               a1,
                               "player_bayonetLaunchZCap",
                               300.0,
                               0.0,
                               500.0,
                               0x80u,
                               "Max Z velocity during bayonet charge.");
  player_standingViewHeight = _Dvar_RegisterInt(
                                a1,
                                "player_standingViewHeight",
                                60,
                                0,
                                70,
                                0x80u,
                                "The height of the camera for the player when standing");
  tu6_player_shallowWaterHeight = _Dvar_RegisterFloat(
                                    a1,
                                    "tu6_player_shallowWaterHeight",
                                    0.0,
                                    0.0,
                                    70.0,
                                    0x4000u,
                                    "If greater than 0, water height considered to be shallow - in which prone will be disallowed.");
  v8 = Com_SessionMode_IsZombiesGame();
  tu11_player_keepZVelocity = _Dvar_RegisterBool(
                                a1,
                                "tu11_player_keepZVelocity",
                                !v8,
                                0x20000u,
                                "Keep the Z component of the player velocity when player is frozen");
  player_disableWeaponsOnVehicle = _Dvar_RegisterBool(
                                     a1,
                                     "player_disableWeaponsOnVehicle",
                                     1,
                                     0x1000u,
                                     "Disable weapons while riding a vehicle");
  player_lookAtEntityAllowChildren = _Dvar_RegisterBool(
                                       a1,
                                       "player_lookAtEntityAllowChildren",
                                       0,
                                       0x1000u,
                                       "Allow's look at entity to detect children during locational trace");
  xanim_debug = _Dvar_RegisterBool(a1, "xanim_debug", 0, 0, "Turn on Xanim Debugging information");
  animscript_debug = _Dvar_RegisterBool(a1, "animscript_debug", 0, 0, "Turn on animscript debugging information");
  anim_debugSpeeds = _Dvar_RegisterBool(a1, "anim_debugSpeeds", 0, 0, "Print out animation speed information");
  animScript_listAnims = _Dvar_RegisterBool(a1, "animScript_listAnims", 0, 0, "Print out animation list");
  bg_debugNotifies = _Dvar_RegisterInt(
                       a1,
                       "bg_debugNotifies",
                       -1,
                       -1,
                       1024,
                       0,
                       "Print out all of the notifies sent to an entity from code");
  player_dmgtimer_timePerPoint = _Dvar_RegisterFloat(
                                   a1,
                                   "player_dmgtimer_timePerPoint",
                                   100.0,
                                   0.0,
                                   3.4028235e38,
                                   0x180u,
                                   "The time in milliseconds that the player is slowed down per point of damage");
  player_dmgtimer_maxTime = _Dvar_RegisterFloat(
                              a1,
                              "player_dmgtimer_maxTime",
                              750.0,
                              0.0,
                              3.4028235e38,
                              0x180u,
                              "The maximum time that the player is slowed due to damage");
  player_dmgtimer_minScale = _Dvar_RegisterFloat(
                               a1,
                               "player_dmgtimer_minScale",
                               0.0,
                               0.0,
                               1.0,
                               0x180u,
                               "The minimum scale value to slow the player by when damaged");
  player_dmgtimer_stumbleTime = _Dvar_RegisterInt(
                                  a1,
                                  "player_dmgtimer_stumbleTime",
                                  500,
                                  0,
                                  2000,
                                  0x180u,
                                  "Maximum time to play stumble animations");
  player_dmgtimer_flinchTime = _Dvar_RegisterInt(
                                 a1,
                                 "player_dmgtimer_flinchTime",
                                 500,
                                 0,
                                 2000,
                                 0x180u,
                                 "Maximum time to play flinch animations");
  bg_shock_soundLoop = _Dvar_RegisterString(a1, "bg_shock_soundLoop", "shellshock_loop", 0x80u, "Shellshock loop alias");
  bg_shock_soundLoopSilent = _Dvar_RegisterString(
                               a1,
                               "bg_shock_soundLoopSilent",
                               "shellshock_loop_silent",
                               0x80u,
                               "The sound that gets blended with the shellshock loop alias");
  bg_shock_soundEnd = _Dvar_RegisterString(
                        a1,
                        "bg_shock_soundEnd",
                        "shellshock_end",
                        0x80u,
                        "Shellshock end sound alias");
  bg_shock_soundEndAbort = _Dvar_RegisterString(
                             a1,
                             "bg_shock_soundEndAbort",
                             "shellshock_end_abort",
                             0x80u,
                             "Shellshock aborted end sound alias");
  bg_shock_screenType = _Dvar_RegisterEnum(
                          a1,
                          "bg_shock_screenType",
                          bg_ShockScreenTypeNames,
                          0,
                          0x80u,
                          "Shell shock screen effect type");
  bg_shock_screenBlurBlendTime = _Dvar_RegisterFloat(
                                   a1,
                                   "bg_shock_screenBlurBlendTime",
                                   0.40000001,
                                   0.001,
                                   10.0,
                                   0x80u,
                                   "The amount of time in seconds for the shellshock effect to blend");
  bg_shock_screenBlurBlendFadeTime = _Dvar_RegisterFloat(
                                       a1,
                                       "bg_shock_screenBlurBlendFadeTime",
                                       1.0,
                                       0.001,
                                       1000.0,
                                       0x80u,
                                       "The amount of time in seconds for the shellshock effect to fade");
  bg_shock_screenFlashWhiteFadeTime = _Dvar_RegisterFloat(
                                        a1,
                                        "bg_shock_screenFlashWhiteFadeTime",
                                        1.0,
                                        0.0,
                                        1000.0,
                                        0x80u,
                                        "In seconds, how soon from the end of the effect to start blending out the whiteout layer.");
  bg_shock_screenFlashShotFadeTime = _Dvar_RegisterFloat(
                                       a1,
                                       "bg_shock_screenFlashShotFadeTime",
                                       1.0,
                                       0.0,
                                       1000.0,
                                       0x80u,
                                       "In seconds, how soon from the end of the effect to start blending out the screengrab layer.");
  bg_shock_viewKickPeriod = _Dvar_RegisterFloat(
                              a1,
                              "bg_shock_viewKickPeriod",
                              0.75,
                              0.001,
                              1000.0,
                              0x80u,
                              "The period of the shellshock view kick effect");
  bg_shock_viewKickRadius = _Dvar_RegisterFloat(
                              a1,
                              "bg_shock_viewKickRadius",
                              0.050000001,
                              0.0,
                              1.0,
                              0x80u,
                              "Shell shock kick radius");
  bg_shock_viewKickFadeTime = _Dvar_RegisterFloat(
                                a1,
                                "bg_shock_viewKickFadeTime",
                                3.0,
                                0.001,
                                1000.0,
                                0x80u,
                                "The time for the shellshock kick effect to fade");
  bg_shock_sound = _Dvar_RegisterBool(a1, "bg_shock_sound", 1, 0x80u, "Play shell shock sound");
  bg_shock_soundFadeInTime = _Dvar_RegisterFloat(
                               a1,
                               "bg_shock_soundFadeInTime",
                               0.25,
                               0.001,
                               1000.0,
                               0x80u,
                               "Shell shock sound fade in time in seconds");
  bg_shock_soundFadeOutTime = _Dvar_RegisterFloat(
                                a1,
                                "bg_shock_soundFadeOutTime",
                                2.5,
                                0.0,
                                1000.0,
                                0x80u,
                                "Shell shock sound fade out time in seconds");
  bg_shock_soundLoopFadeTime = _Dvar_RegisterFloat(
                                 a1,
                                 "bg_shock_soundLoopFadeTime",
                                 1.5,
                                 0.0,
                                 1000.0,
                                 0x80u,
                                 "Shell shock sound loop fade time in seconds");
  bg_shock_soundLoopEndDelay = _Dvar_RegisterFloat(
                                 a1,
                                 "bg_shock_soundLoopEndDelay",
                                 -3.0,
                                 -10.0,
                                 1000.0,
                                 0x80u,
                                 "Sound loop end offset time from the end of the shellshock in seconds");
  bg_shock_soundRoomType = _Dvar_RegisterString(a1, "bg_shock_soundRoomType", "default", 0x80u, "sound room");
  bg_shock_soundDryLevel = _Dvar_RegisterFloat(
                             a1,
                             "bg_shock_soundDryLevel",
                             1.0,
                             0.0,
                             1.0,
                             0x80u,
                             "Shell shock sound dry level");
  bg_shock_soundWetLevel = _Dvar_RegisterFloat(
                             a1,
                             "bg_shock_soundWetLevel",
                             0.5,
                             0.0,
                             1.0,
                             0x80u,
                             "Shell shock sound wet level");
  bg_shock_soundModEndDelay = _Dvar_RegisterFloat(
                                a1,
                                "bg_shock_soundModEndDelay",
                                2.0,
                                -1000.0,
                                1000.0,
                                0x80u,
                                "The delay from the end of the shell shock to the end of the sound modification");
  bg_shock_soundSnapshot = _Dvar_RegisterString(a1, "bg_shock_soundSnapshot", "default", 0x80u, "sound snapshot");
  bg_shock_lookControl = _Dvar_RegisterBool(
                           a1,
                           "bg_shock_lookControl",
                           1,
                           0x80u,
                           "Alter player control during shellshock");
  bg_shock_lookControl_maxpitchspeed = _Dvar_RegisterFloat(
                                         a1,
                                         "bg_shock_lookControl_maxpitchspeed",
                                         90.0,
                                         0.0,
                                         3.4028235e38,
                                         0x80u,
                                         "Maximum pitch movement rate while shellshocked in degrees per second");
  bg_shock_lookControl_maxyawspeed = _Dvar_RegisterFloat(
                                       a1,
                                       "bg_shock_lookControl_maxyawspeed",
                                       90.0,
                                       0.0,
                                       3.4028235e38,
                                       0x80u,
                                       "Maximum yaw movement rate while shell shocked in degrees per second");
  bg_shock_lookControl_mousesensitivityscale = _Dvar_RegisterFloat(
                                                 a1,
                                                 "bg_shock_lookControl_mousesensitivityscale",
                                                 0.5,
                                                 0.0,
                                                 2.0,
                                                 0x80u,
                                                 "Sensitivity scale to apply to a shellshocked player");
  bg_shock_lookControl_fadeTime = _Dvar_RegisterFloat(
                                    a1,
                                    "bg_shock_lookControl_fadeTime",
                                    2.0,
                                    0.001,
                                    1000.0,
                                    0x80u,
                                    "The time for the shellshock player control to fade in seconds");
  bg_shock_movement = _Dvar_RegisterFloat(
                        a1,
                        "bg_shock_movement",
                        1.0,
                        0.0,
                        1.0,
                        0x80u,
                        "Affect player's movement speed during shellshock");
  bg_shock_animation = _Dvar_RegisterBool(
                         a1,
                         "bg_shock_animation",
                         0,
                         0x80u,
                         "Play the 3rd person animation during shellshock");
  bg_shock_visionset_name = _Dvar_RegisterString(
                              a1,
                              "bg_shock_visionset_name",
                              (const char *)&pBlock,
                              0x80u,
                              "Vision set that will be transitioned to when this shellshock plays");
  bg_shock_visionset_inTime = _Dvar_RegisterFloat(
                                a1,
                                "bg_shock_visionset_inTime",
                                0.0,
                                0.0,
                                30.0,
                                0x80u,
                                "Vision set in transition time (in seconds)");
  bg_shock_visionset_outTime = _Dvar_RegisterFloat(
                                 a1,
                                 "bg_shock_visionset_outTime",
                                 0.0,
                                 0.0,
                                 30.0,
                                 0x80u,
                                 "Vision set out transition time (in seconds)");
  player_meleeRange = _Dvar_RegisterFloat(
                        a1,
                        "player_meleeRange",
                        55.0,
                        0.0,
                        1000.0,
                        0,
                        "The maximum range of the player's melee attack");
  player_meleeWidth = _Dvar_RegisterFloat(
                        a1,
                        "player_meleeWidth",
                        10.0,
                        0.0,
                        1000.0,
                        0x80u,
                        "The width of the player's melee attack");
  player_meleeHeight = _Dvar_RegisterFloat(
                         a1,
                         "player_meleeHeight",
                         10.0,
                         0.0,
                         1000.0,
                         0x80u,
                         "The height of the player's melee attack");
  player_meleeInterruptFrac = _Dvar_RegisterFloat(
                                a1,
                                "player_meleeInterruptFrac",
                                1.0,
                                0.0,
                                1.0,
                                0x1000u,
                                "Scaler allowing melee interrupt");
  tu5_uav_ads_fix = _Dvar_RegisterBool(
                      a1,
                      "tu5_uav_ads_fix",
                      1,
                      0x20000u,
                      "This prevents the bit throw from being the fire button for grenades (and mines) with detonators. ");
  tu6_player_jump_blocks_tac_insert = _Dvar_RegisterBool(
                                        a1,
                                        "tu6_player_jump_blocks_tac_insert",
                                        0,
                                        0x20000u,
                                        "If true, the act of the player jumping will cause the tactical insertion plant to fail.");
  tu7_mapbased_killstreaks_fix = _Dvar_RegisterBool(
                                   a1,
                                   "tu7_mapbased_killstreaks_fix",
                                   1,
                                   0x20000u,
                                   "If you cancelled a location based killstreak then tried to call it in again within a "
                                   "second it would not show the map");
  v9 = Com_SessionMode_IsZombiesGame();
  tu12_zm_stop_firing_when_overheated = _Dvar_RegisterBool(
                                          a1,
                                          "tu12_zm_stop_firing_when_overheated",
                                          v9,
                                          0x20000u,
                                          "Force a stop to firing when an overheat weapon is overheated");
  v10 = Com_SessionMode_IsZombiesGame();
  tu12_zm_stack_fire_fix = _Dvar_RegisterBool(
                             a1,
                             "tu12_zm_stack_fire_fix",
                             v10,
                             0x20000u,
                             "For stack fire weapons, use the stack fire count from the weapon data instead of the clip size");
  dlc3_zm_ai_lookAheadAllowBackTrack = _Dvar_RegisterBool(
                                         a1,
                                         "dlc3_zm_ai_lookAheadAllowBackTrack",
                                         0,
                                         0x20000u,
                                         "allow backtrack when doing Path_UpdateLookahead");
  dlc3_zm_ai_lookAheadAllowRestore = _Dvar_RegisterBool(
                                       a1,
                                       "dlc3_zm_ai_lookAheadAllowRestore",
                                       0,
                                       0x20000u,
                                       "allow restore when doing Path_UpdateLookahead");
  if ( Com_SessionMode_IsZombiesGame() )
    v11 = FLOAT_24_0;
  else
    v11 = 0.0;
  tu13_zm_check_traversal_max_z = _Dvar_RegisterFloat(
                                    a1,
                                    "tu13_zm_check_traversal_max_z",
                                    v11,
                                    0.0,
                                    1000.0,
                                    0x20000u,
                                    "Don't allow actors to use traversal nodes without being close vertically");
  tu14_preventStartingChargeShotWhileFiring = _Dvar_RegisterBool(
                                                a1,
                                                "tu14_preventStartingChargeShotWhileFiring",
                                                1,
                                                0x20000u,
                                                "For chargeshot weapons, prevent starting a new chargeshot while the weap"
                                                "on is still firing");
  if ( Com_SessionMode_IsZombiesGame() )
    v12 = FLOAT_600_0;
  else
    v12 = FLOAT_800_0;
  player_meleeChargeMaxSpeed = _Dvar_RegisterFloat(
                                 a1,
                                 "player_meleeChargeMaxSpeed",
                                 v12,
                                 0.0,
                                 2000.0,
                                 0x80u,
                                 "Max speed to clamp when doing a charge melee");
  player_meleeCalcSpeedFromTarget = _Dvar_RegisterBool(
                                      a1,
                                      "player_meleeCalcSpeedFromTarget",
                                      1,
                                      0x80u,
                                      "Whether to calculate speed and friction based on melee target rather than constant"
                                      " aim assist distance");
  player_meleeChargeFriction = _Dvar_RegisterFloat(
                                 a1,
                                 "player_meleeChargeFriction",
                                 1200.0,
                                 1.0,
                                 5000.0,
                                 0x80u,
                                 "Friction used during melee charge");
  v13 = Com_SessionMode_IsZombiesGame();
  tu7_clampMeleeChargeJumping = _Dvar_RegisterBool(
                                  a1,
                                  "tu7_clampMeleeChargeJumping",
                                  !v13,
                                  0x20000u,
                                  "Whether to clamp knife lunge jumping.");
  v14 = Com_SessionMode_IsZombiesGame();
  tu7_clampMeleeChargeHorzLaunch = _Dvar_RegisterBool(
                                     a1,
                                     "tu7_clampMeleeChargeHorzLaunch",
                                     !v14,
                                     0x20000u,
                                     "Whether to clamp knife lunge launching Horizontally.");
  tu7_clampMeleeChargeJumpingMaxZVel = _Dvar_RegisterFloat(
                                         a1,
                                         "tu7_clampMeleeChargeJumpingMaxZVel",
                                         240.0,
                                         0.0,
                                         2000.0,
                                         0x20000u,
                                         "Max speed to clamp on the Z axis if the player is knife lunge jumping.");
  player_zombieMeleeRange = _Dvar_RegisterFloat(
                              a1,
                              "player_zombieMeleeRange",
                              85.0,
                              0.0,
                              1000.0,
                              0,
                              "The maximum range of the player's melee attacks when they are a zombie");
  player_zombieMeleeWidth = _Dvar_RegisterFloat(
                              a1,
                              "player_zombieMeleeWidth",
                              30.0,
                              0.0,
                              1000.0,
                              0x80u,
                              "The width of the player zombie's melee attack");
  player_zombieMeleeHeight = _Dvar_RegisterFloat(
                               a1,
                               "player_zombieMeleeHeight",
                               20.0,
                               0.0,
                               1000.0,
                               0x80u,
                               "The height of the player zombie's melee attack");
  player_bayonetRange = _Dvar_RegisterFloat(
                          a1,
                          "player_bayonetRange",
                          85.0,
                          0.0,
                          1000.0,
                          0x80u,
                          "The maximum range of the player's bayonet attack");
  player_bayonetTargetDist = _Dvar_RegisterInt(
                               a1,
                               "player_bayonetTargetDist",
                               65,
                               0,
                               1000,
                               0x80u,
                               "The distance to the enemy the player's will stop charging");
  bg_gravity = _Dvar_RegisterFloat(
                 a1,
                 "bg_gravity",
                 800.0,
                 1.0,
                 3.4028235e38,
                 0x2000u,
                 "Gravity in inches per second per second");
  bg_lowGravity = _Dvar_RegisterFloat(
                    a1,
                    "bg_lowGravity",
                    400.0,
                    1.0,
                    3.4028235e38,
                    0x2000u,
                    "Low gravity for slow or floaty objects, in inches per second per second");
  bg_moonGravity = _Dvar_RegisterFloat(
                     a1,
                     "bg_moonGravity",
                     136.0,
                     1.0,
                     3.4028235e38,
                     0x2000u,
                     "Gravity on the moon, in inches per second per second");
  player_swimTime = _Dvar_RegisterFloat(
                      a1,
                      "player_swimTime",
                      16.0,
                      0.0,
                      5000.0,
                      0x4080u,
                      "Set the max time the player can swim underwater before taking damage.");
  player_swimDamage = _Dvar_RegisterInt(
                        a1,
                        "player_swimDamage",
                        15,
                        0,
                        5000,
                        0x4080u,
                        "Damage the player will take each interval while out of breath in deep water.");
  player_swimDamagerInterval = _Dvar_RegisterFloat(
                                 a1,
                                 "player_swimDamagerInterval",
                                 1.0,
                                 0.0,
                                 5000.0,
                                 0x4080u,
                                 "Interval in which damage will be dealt while out of breath under water.");
  player_viewLockEnt = _Dvar_RegisterInt(
                         a1,
                         "player_viewLockEnt",
                         0,
                         0,
                         1024,
                         0x1000u,
                         "Set an entity that the player view will be locked too.");
  player_viewRateScale = _Dvar_RegisterFloat(
                           a1,
                           "player_viewRateScale",
                           0.0,
                           0.0,
                           300.0,
                           0x1000u,
                           "Player view rate scale modifier when player doesn't have a weapon.");
  player_forceRedCrosshair = _Dvar_RegisterBool(
                               a1,
                               "player_forceRedCrosshair",
                               0,
                               0x1000u,
                               "Force the player's crosshair to turn red");
  bullet_penetrationMinFxDist = _Dvar_RegisterFloat(
                                  a1,
                                  "bullet_penetrationMinFxDist",
                                  30.0,
                                  0.0,
                                  1024.0,
                                  0x80u,
                                  "Min distance a penetrated bullet must travel before it'll trigger the effects");
  bullet_ricochetBaseChance = _Dvar_RegisterFloat(
                                a1,
                                "bullet_ricochetBaseChance",
                                0.5,
                                0.0,
                                0.94999999,
                                0x80u,
                                "The base chance a bullet has of ricocheting off of a riot shield.");
  cg_cinematicFullscreen = _Dvar_RegisterBool(
                             a1,
                             "cg_cinematicFullscreen",
                             1,
                             0x1000u,
                             "Draw ingame cinematics full screen");
  cg_debugMounting = _Dvar_RegisterInt(
                       a1,
                       "cg_debugMounting",
                       0,
                       0,
                       3,
                       0x80u,
                       "Render debug lines that show where mountable weapons are trying to be placed");
  dog_MeleeDamage = _Dvar_RegisterInt(
                      a1,
                      "dog_MeleeDamage",
                      150,
                      1,
                      10000,
                      0x1000u,
                      "Controls the damage done when dogs attack.");
  dog_turn90_angle = _Dvar_RegisterFloat(
                       a1,
                       "dog_turn90_angle",
                       70.0,
                       0.0,
                       360.0,
                       0x80u,
                       "If the dog needs to turn at this angle or greater, he'll execute the 90-degree turn animation");
  dog_turn180_angle = _Dvar_RegisterFloat(
                        a1,
                        "dog_turn180_angle",
                        135.0,
                        0.0,
                        360.0,
                        0x80u,
                        "If the dog needs to turn at this angle or greater, he'll execute the 180-degree turn animation");
  dog_turn_min_goal_dist = _Dvar_RegisterFloat(
                             a1,
                             "dog_turn_min_goal_dist",
                             40.0,
                             0.0,
                             1024.0,
                             0x80u,
                             "If the dog is at this distance or less to it's goal, it won't execute any turn animations");
  vehLockTurretToPlayerView = _Dvar_RegisterBool(
                                a1,
                                "vehLockTurretToPlayerView",
                                0,
                                0x80u,
                                "Locks the turret angles to the player angles and sets the players rotation speed to the turrets rotRate");
  vehLocationalVehicleSeatEntry = _Dvar_RegisterBool(
                                    a1,
                                    "vehLocationalVehicleSeatEntry",
                                    1,
                                    0x80u,
                                    "Assigns the player seat based on the entry location, NOT first in first available position");
  vehCameraTurretOffset = _Dvar_RegisterVec3(
                            a1,
                            "vehCameraTurretOffset",
                            0.0,
                            0.0,
                            0.0,
                            -300.0,
                            300.0,
                            0x80u,
                            "Vehicle turret camera offset");
  vehCameraTurretOffsetADS = _Dvar_RegisterVec3(
                               a1,
                               "vehCameraTurretOffsetADS",
                               0.0,
                               0.0,
                               0.0,
                               -300.0,
                               300.0,
                               0x80u,
                               "Vehicle turret camera offset ADS");
  v15 = Com_SessionMode_IsZombiesGame();
  vehicle_riding = _Dvar_RegisterBool(
                     a1,
                     "vehicle_riding",
                     v15,
                     0x1000u,
                     "Turning this on enables players to walk around on top of vehicles");
  vehicle_selfCollision = _Dvar_RegisterBool(
                            a1,
                            "vehicle_selfCollision",
                            0,
                            0x1000u,
                            "Enabled the vehicle to shoot itself with it's own turret.");
  g_bDebugRenderPlayerCollision = _Dvar_RegisterBool(
                                    a1,
                                    "debugRenderPlayerCollision",
                                    0,
                                    0,
                                    "Render collision geometry that the player is touching");
  bg_shieldHitEncodeWidthWorld = _Dvar_RegisterVec2(
                                   a1,
                                   "bg_shieldHitEncodeWidthWorld",
                                   -14.0,
                                   14.0,
                                   -3.4028235e38,
                                   3.4028235e38,
                                   0x2080u,
                                   "The encoding range, in width, of a client's world shield.  A hit in this range is enc"
                                   "oded into one of 16 collumns.");
  bg_shieldHitEncodeHeightWorld = _Dvar_RegisterVec2(
                                    a1,
                                    "bg_shieldHitEncodeHeightWorld",
                                    -25.0,
                                    20.0,
                                    -3.4028235e38,
                                    3.4028235e38,
                                    0x2080u,
                                    "The encoding range, in height, of a client's world shield.  A hit in this range is e"
                                    "ncoded into one of 8 rows.");
  bg_shieldHitEncodeWidthVM = _Dvar_RegisterVec2(
                                a1,
                                "bg_shieldHitEncodeWidthVM",
                                -16.0,
                                16.0,
                                -3.4028235e38,
                                3.4028235e38,
                                0x2080u,
                                "The decoding range, in width, of a client's viewmodel shield.");
  bg_shieldHitEncodeHeightVM = _Dvar_RegisterVec2(
                                 a1,
                                 "bg_shieldHitEncodeHeightVM",
                                 -10.0,
                                 10.0,
                                 -3.4028235e38,
                                 3.4028235e38,
                                 0x2080u,
                                 "The decoding range, in height, of a client's viewmodel shield.");
  bg_disableWeaponPlantingInWater = _Dvar_RegisterBool(
                                      a1,
                                      "bg_disableWeaponPlantingInWater",
                                      1,
                                      0x80u,
                                      "Disables being able to plant mines in the water.");
  bg_plantInWaterDepth = _Dvar_RegisterFloat(
                           a1,
                           "bg_plantInWaterDepth",
                           5.0,
                           0.0,
                           1024.0,
                           0x4000u,
                           "Min distance between the water surface and the ground where we can plant");
  bg_gunXOffset = _Dvar_RegisterFloat(
                    a1,
                    "bg_gunXOffset",
                    0.0,
                    -1000.0,
                    1000.0,
                    0x4000u,
                    "This will offset where the bullets come out of the gun");
  bg_slopeFrames = _Dvar_RegisterInt(
                     a1,
                     "bg_slopeFrames",
                     10,
                     0,
                     30,
                     0x80u,
                     "The number of frames to use to determine slope run animations");
  disable_rope = _Dvar_RegisterBool(a1, "disable_rope", 0, 0x1080u, "Disables the rope system");
  debug_rope = _Dvar_RegisterBool(a1, "debug_rope", 0, 0, "Enables the debug rendering for the ropes");
  vehicle_sounds_cutoff = _Dvar_RegisterFloat(
                            a1,
                            "vehicle_sounds_cutoff",
                            3000.0,
                            0.0,
                            300000.0,
                            0x1000u,
                            "Use to turn of the vehicle sounds if the distance between the camera and the vehicle is more"
                            " than this value");
  footstep_sounds_cutoff = _Dvar_RegisterFloat(
                             a1,
                             "footstep_sounds_cutoff",
                             1000.0,
                             0.0,
                             30000.0,
                             0x4000u,
                             "Footstep sounds distance cuttoff");
  bg_teleportAlignTime = _Dvar_RegisterInt(
                           a1,
                           "bg_teleportAlignTime",
                           500,
                           -1,
                           2000,
                           0x80u,
                           "How long to align the player body after teleporting/respawning");
  waterbrush_entity = _Dvar_RegisterInt(
                        a1,
                        "waterbrush_entity",
                        -1,
                        -1,
                        1024,
                        0x80u,
                        "CM_GetWaterHeight function will test against this enitty. Can be used on brushmodels to move the water level");
  playerPushAmount = _Dvar_RegisterFloat(
                       a1,
                       "playerPushAmount",
                       0.0,
                       0.0,
                       1000.0,
                       0x1000u,
                       "If this value is set the player will get pushed away from AIs by the amount specified.");
  scr_player_sprinttime = _Dvar_RegisterFloat(
                            a1,
                            "scr_player_sprinttime",
                            4.0,
                            0.0,
                            3.4028235e38,
                            0,
                            (const char *)&pBlock);
  scr_dynamic_source_loading = _Dvar_RegisterBool(
                                 a1,
                                 "scr_dynamic_source_loading",
                                 1,
                                 0,
                                 "Load and then free source when reporting errors.  If false, keep source loaded.");
  bg_vehicle_ground_min_normal = _Dvar_RegisterFloat(
                                   a1,
                                   "bg_vehicle_ground_min_normal",
                                   0.69999999,
                                   0.0,
                                   1.0,
                                   0x2080u,
                                   "Minimum z-value of the normal of what is considered a drivable ground surface");
  bg_vehicle_ground_max_normal = _Dvar_RegisterFloat(
                                   a1,
                                   "bg_vehicle_ground_max_normal",
                                   0.40000001,
                                   0.0,
                                   1.0,
                                   0x2080u,
                                   "The z-value of the normal for ground surfaces that a vehicle cannot be on");
  bg_vehicle_slide_min_normal = _Dvar_RegisterFloat(
                                  a1,
                                  "bg_vehicle_slide_min_normal",
                                  0.80000001,
                                  0.0,
                                  1.0,
                                  0x2080u,
                                  "Minimum z-value of the normal of the ground at which the vehicle begins to slide with gravity");
  bg_vehicle_pitch_track = _Dvar_RegisterFloat(
                             a1,
                             "bg_vehicle_pitch_track",
                             2.0,
                             0.0,
                             3.4028235e38,
                             0x2080u,
                             "The rate at which the vehicle's plane tracks the ground plane in pitch");
  bg_vehicle_roll_track = _Dvar_RegisterFloat(
                            a1,
                            "bg_vehicle_roll_track",
                            2.0,
                            0.0,
                            3.4028235e38,
                            0x2080u,
                            "The rate at which the vehicle's plane tracks the ground plane in roll");
  bg_vehicle_max_pitch = _Dvar_RegisterFloat(
                           a1,
                           "bg_vehicle_max_pitch",
                           20.0,
                           0.0,
                           3.4028235e38,
                           0x2080u,
                           "The maximum angle of the vehicle's pitch");
  bg_vehicle_max_roll = _Dvar_RegisterFloat(
                          a1,
                          "bg_vehicle_max_roll",
                          20.0,
                          0.0,
                          3.4028235e38,
                          0x2080u,
                          "The maximum angle of the vehicle's roll");
  bg_vehicle_max_body_pitch = _Dvar_RegisterFloat(
                                a1,
                                "bg_vehicle_max_body_pitch",
                                12.0,
                                0.0,
                                3.4028235e38,
                                0x2080u,
                                "The maximum angle of the vehicle's body pitch");
  bg_vehicle_max_body_roll = _Dvar_RegisterFloat(
                               a1,
                               "bg_vehicle_max_body_roll",
                               12.0,
                               0.0,
                               3.4028235e38,
                               0x2080u,
                               "The maximum angle of the vehicle's body roll");
  bg_vehicle_gravity = _Dvar_RegisterFloat(
                         a1,
                         "bg_vehicle_gravity",
                         985.0,
                         0.0,
                         3.4028235e38,
                         0x2080u,
                         "Gravity applied to client predicted vehicles");
  bg_vehicle_trace_offset = _Dvar_RegisterFloat(
                              a1,
                              "bg_vehicle_trace_offset",
                              0.25,
                              0.0,
                              3.4028235e38,
                              0x2080u,
                              "The length, up and down, of the vehicle's capsule trace when finding the ground");
  bg_vehicle_overclip = _Dvar_RegisterFloat(
                          a1,
                          "bg_vehicle_overclip",
                          0.001,
                          0.0,
                          3.4028235e38,
                          0x2080u,
                          "The amount to pull back from the clip plane when moving a vehicle across it");
  bg_vehicle_tangential_clip_vel_scale = _Dvar_RegisterFloat(
                                           a1,
                                           "bg_vehicle_tangential_clip_vel_scale",
                                           3.0,
                                           0.0,
                                           3.4028235e38,
                                           0x2080u,
                                           "The amount by which the tangential velocity is scaled when movement is clipped.");
  bg_vehicle_tangential_clip_max_scale = _Dvar_RegisterFloat(
                                           a1,
                                           "bg_vehicle_tangential_clip_max_scale",
                                           1.0,
                                           0.0,
                                           3.4028235e38,
                                           0x2080u,
                                           "The amount by which the current velocity is scaled when clamping tangential clip velocity.");
  bg_vehicle_stepsize = _Dvar_RegisterFloat(
                          a1,
                          "bg_vehicle_stepsize",
                          12.0,
                          0.0,
                          3.4028235e38,
                          0x2080u,
                          "The height of the step the vehicle makes when trying to move over obstacles");
  bg_vehicle_sphere_bounds_offset_z = _Dvar_RegisterFloat(
                                        a1,
                                        "bg_vehicle_sphere_bounds_offset_z",
                                        -9.0,
                                        -3.4028235e38,
                                        3.4028235e38,
                                        0x2080u,
                                        "Helicopter collision Z offset amount. Move to GDT alongside vehHelicopterBoundsR"
                                        "adius post ship.");
  bg_vehicle_placement_debug = _Dvar_RegisterBool(
                                 a1,
                                 "bg_vehicle_placement_debug",
                                 0,
                                 0x80u,
                                 "Show vehicle placement debug drawing.");
  turret_placement_trace_maxs = _Dvar_RegisterFloat(
                                  a1,
                                  "turret_placement_trace_maxs",
                                  42.0,
                                  0.0,
                                  3.4028235e38,
                                  0x20000u,
                                  "maxs of the bound used for the placement trace");
  turret_placement_trace_mins = _Dvar_RegisterFloat(
                                  a1,
                                  "turret_placement_trace_mins",
                                  -42.0,
                                  -100.0,
                                  3.4028235e38,
                                  0x20000u,
                                  "mins of the bound used for the placement trace");
  microwave_turret_placement_trace_maxs = _Dvar_RegisterFloat(
                                            a1,
                                            "microwave_turret_placement_trace_maxs",
                                            22.0,
                                            0.0,
                                            3.4028235e38,
                                            0x20000u,
                                            "maxs of the bound used for the placement trace");
  microwave_turret_placement_trace_mins = _Dvar_RegisterFloat(
                                            a1,
                                            "microwave_turret_placement_trace_mins",
                                            -22.0,
                                            -100.0,
                                            3.4028235e38,
                                            0x20000u,
                                            "mins of the bound used for the placement trace");
  wallmount_turret_placement_trace_maxs = _Dvar_RegisterVec3(
                                            a1,
                                            "wallmount_turret_placement_trace_maxs",
                                            0.0,
                                            8.0,
                                            8.0,
                                            0.0,
                                            3.4028235e38,
                                            0x20000u,
                                            "maxs of the bound used for the placement trace");
  wallmount_turret_placement_trace_mins = _Dvar_RegisterVec3(
                                            a1,
                                            "wallmount_turret_placement_trace_mins",
                                            0.0,
                                            -8.0,
                                            -8.0,
                                            -1024.0,
                                            3.4028235e38,
                                            0x20000u,
                                            "mins of the bound used for the placement trace");
  turretplacement_useTraceOffset = _Dvar_RegisterBool(
                                     a1,
                                     "turretplacement_useTraceOffset",
                                     1,
                                     0x20000u,
                                     "Use the offset in turret placement");
  turretplacement_traceOffset = _Dvar_RegisterFloat(
                                  a1,
                                  "turretplacement_traceOffset",
                                  12.0,
                                  0.0,
                                  100.0,
                                  0x20000u,
                                  "The amount to offset the trace start used in turret placement.");
  microwave_turretplacement_traceOffset = _Dvar_RegisterFloat(
                                            a1,
                                            "microwave_turretplacement_traceOffset",
                                            -8.0,
                                            -100.0,
                                            100.0,
                                            0x20000u,
                                            "The amount to offset the trace start used in turret placement.");
  tu5_check_unique_attachments_enabled = _Dvar_RegisterBool(
                                           a1,
                                           "tu5_check_unique_attachments_enabled",
                                           1,
                                           0x20000u,
                                           "Use the check for unique attachments function");
  bg_serverDelayDamageKickForPing = _Dvar_RegisterBool(
                                      a1,
                                      "bg_serverDelayDamageKickForPing",
                                      0,
                                      0,
                                      "Turn on delayed damage kick on server to allow for client ping");
  bg_useClientDamageKick = _Dvar_RegisterBool(
                             a1,
                             "bg_useClientDamageKick",
                             1,
                             0,
                             "Turn on to make the server use the damage kick angles from the client usercmd");
  Jump_RegisterDvars(a1);
  Mantle_RegisterDvars(a1);
  Dtp_RegisterDvars(a1);
  Riotshield_RegisterDvars();
  VehAnim_RegisterDvars();
  Perks_RegisterDvars();
  zero_idle_movement = _Dvar_RegisterBool(a1, "zero_idle_movement", 0, 0x80u, "Turn the ADS idle movement off.");
  bg_aqs = _Dvar_RegisterBool(a1, "bg_aqs", 1, 0x80u, (const char *)&pBlock);
  bg_aqsStyle = _Dvar_RegisterInt(a1, "bg_aqsStyle", 2, 0, 2, 0x80u, (const char *)&pBlock);
  bg_ads = _Dvar_RegisterBool(a1, "bg_ads", 1, 0x80u, (const char *)&pBlock);
  adsZeroSpread = _Dvar_RegisterBool(a1, "adsZeroSpread", 1, 0x20000u, "Immediately zero spreadAmount when fully ADS");
  tu_enforceRechamberOnSwitch = _Dvar_RegisterBool(
                                  a1,
                                  "tu_enforceRechamberOnSwitch",
                                  1,
                                  0x20000u,
                                  "Forces a bolt action weapon to rechamber if not enough time has passed between switching weapons");
  tu_isolateDamageFlash = _Dvar_RegisterBool(
                            a1,
                            "tu_isolateDamageFlash",
                            1,
                            0x20000u,
                            "Drive damage flash overlay from isolated variable instead of view kick pitch");
  tu_limitGrenadeImpacts = _Dvar_RegisterBool(
                             a1,
                             "tu_limitGrenadeImpacts",
                             1,
                             0x20000u,
                             "Use missileTargetEnt to limit impact damage to the first impact");
  tu_cleanUpTurretOnDisconnect = _Dvar_RegisterBool(
                                   a1,
                                   "tu_cleanUpTurretOnDisconnect",
                                   1,
                                   0x20000u,
                                   "Tell the turret to stop being used if the player disconnects");
  tu_deferScriptMissileDetonation = _Dvar_RegisterBool(
                                      a1,
                                      "tu_deferScriptMissileDetonation",
                                      1,
                                      0x20000u,
                                      "Defer G_ExplodeMissile() till after origin is updated in G_RunMissile()");
  BG_EvalVehicleName();
  BG_Wind_RegisterDvars();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x94E4D0
Weapon __cdecl G_FindItem(const char *pickupName)
{
  return G_GetWeaponForName(pickupName);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x94E4F0
char __cdecl HaveRoomForAmmo(const playerState_s *ps, const Weapon weapon)
{
  const WeaponVariantDef *WeaponVariantDef; // esi
  int v4; // esi
  PlayerHeldWeapon *i; // edi
  Weapon v6; // ebx
  Weapon ammoWeapon; // [esp+8h] [ebp-4h]

  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 1612, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  WeaponVariantDef = BG_GetWeaponVariantDef(weapon);
  ammoWeapon.0 = BG_GetWeaponForAmmoPool(weapon).0;
  if ( !*WeaponVariantDef->szAmmoName )
    return 1;
  v4 = 0;
  for ( i = ps->heldWeapons; ; ++i )
  {
    v6.0 = ($190F2CF944EC18EE3AF27F473C4F9DBE)i->weapon;
    if ( i->weapon.weaponData && *(_BYTE *)&v6.0 )
    {
      BG_GetWeaponVariantDef(i->weapon);
      if ( BG_GetWeaponForAmmoPool(v6).0 == ammoWeapon.weaponData && BG_GetMaxPickupableAmmo(ps, v6) > 0 )
        break;
      if ( ammoWeapon.0 == (unsigned __int8)BG_GetWeaponForAmmoPool(v6).weaponData
        && BG_GetMaxPickupableAmmo(ps, v6) > 0 )
      {
        break;
      }
    }
    if ( ++v4 >= 15 )
      return 0;
  }
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x94E5C0
bool __cdecl BG_PlayerCanPickUpWeaponType(const WeaponDef *weapDef, const playerState_s *ps)
{
  int pm_type; // eax
  bool result; // al
  OffhandClass offhandClass; // eax

  if ( !weapDef
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 1645, 0, "(weapDef)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 1646, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  pm_type = ps->pm_type;
  result = 0;
  if ( pm_type != 7 && pm_type != 8 || weapDef->weapClass == WEAPCLASS_GRENADE )
  {
    offhandClass = weapDef->offhandClass;
    if ( (offhandClass != OFFHAND_CLASS_FLASH_GRENADE || ps->offhandSecondary == PLAYER_OFFHAND_SECONDARY_FLASH)
      && (offhandClass != OFFHAND_CLASS_SMOKE_GRENADE || ps->offhandSecondary == PLAYER_OFFHAND_SECONDARY_SMOKE) )
    {
      return 1;
    }
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x94E660
bool __usercall WeaponEntCanBeGrabbed@<al>(
        const playerState_s *ps@<esi>,
        const entityState_s *weaponEntState,
        int touched,
        Weapon weapon)
{
  const WeaponDef *WeaponDef; // edi
  bool result; // al
  char v6; // al
  char v7; // bl
  Weapon v8; // eax

  WeaponDef = BG_GetWeaponDef(weapon);
  result = BG_PlayerCanPickUpWeaponType(WeaponDef, ps);
  if ( result )
  {
    if ( weaponEntState->eType == 4 && WeaponDef->bThrowBack && Dvar_GetBool(throwback_enabled) )
      return 1;
    if ( touched )
    {
      v6 = HaveRoomForAmmo(ps, weapon);
      v7 = v6;
      if ( WeaponDef->offhandClass == OFFHAND_CLASS_FRAG_GRENADE && v6
        || (BG_PlayerHasWeapon(ps, weapon) || BG_PlayerHasCompatibleWeapon(ps, weapon)) && v7 )
      {
        return 1;
      }
      if ( (((unsigned int)&loc_7FFFFF + 1) & weaponEntState->lerp.eFlags2) != 0 )
      {
        if ( Com_BitCheckAssert(ps->perks, 53, 0xFFFFFFF) > 0 )
          return 1;
        v8.0 = BG_GetViewmodelWeaponIndex(ps).0;
        if ( BG_WeaponHasPerk(v8, 0x35u) )
          return 1;
      }
    }
    else if ( !BG_PlayerHasWeapon(ps, weapon) )
    {
      return 1;
    }
    return 0;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x94E900
void __usercall BG_EvaluateTrajectoryInternal(float a1@<ebx>, const trajectory_t *tr, int atTime, vec3_t *result)
{
  vec3_t *p_trDelta; // ebx
  float v5; // xmm0_4
  int trDuration; // eax
  int trTime; // edx
  int v8; // eax
  float v9; // xmm0_4
  int v10; // ecx
  int v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  int v15; // ecx
  int v16; // eax
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  const dvar_t *v21; // [esp-8h] [ebp-1Ch]
  float deltaTime; // [esp+8h] [ebp-Ch]
  float deltaTimea; // [esp+8h] [ebp-Ch]
  int phase; // [esp+Ch] [ebp-8h]
  float phaseb; // [esp+Ch] [ebp-8h]
  int phasea; // [esp+Ch] [ebp-8h]
  float phasec; // [esp+Ch] [ebp-8h]

  if ( tr->trType >= 0x10u
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          1772,
          0,
          "((tr->trType < NUM_TRTYPES))",
          "(tr->trType) = %i",
          tr->trType) )
  {
    __debugbreak();
  }
  if ( ((LODWORD(tr->trBase.x) & 0x7F800000) == 2139095040
     || (LODWORD(tr->trBase.y) & 0x7F800000) == 2139095040
     || (LODWORD(tr->trBase.z) & 0x7F800000) == 2139095040)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          1775,
          0,
          "(!IS_NAN((tr->trBase)[0]) && !IS_NAN((tr->trBase)[1]) && !IS_NAN((tr->trBase)[2]))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  p_trDelta = &tr->trDelta;
  if ( ((LODWORD(tr->trDelta.x) & 0x7F800000) == 2139095040
     || (LODWORD(tr->trDelta.y) & 0x7F800000) == 2139095040
     || (LODWORD(tr->trDelta.z) & 0x7F800000) == 2139095040)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          1776,
          0,
          "(!IS_NAN((tr->trDelta)[0]) && !IS_NAN((tr->trDelta)[1]) && !IS_NAN((tr->trDelta)[2]))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  switch ( tr->trType )
  {
    case 3u:
    case 0xBu:
    case 0xCu:
      v5 = (float)(atTime - tr->trTime) * 0.001;
      goto LABEL_16;
    case 4u:
      trTime = tr->trTime;
      v8 = atTime;
      if ( atTime > trTime + tr->trDuration )
        v8 = trTime + tr->trDuration;
      v5 = (float)(v8 - trTime) * 0.001;
      if ( v5 < 0.0 )
        v5 = 0.0;
      goto LABEL_16;
    case 5u:
      if ( !tr->trDuration
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
              1793,
              0,
              "(tr->trDuration != 0)",
              "%s",
              "div by 0") )
      {
        __debugbreak();
      }
      trDuration = tr->trDuration;
      if ( !trDuration )
        goto LABEL_21;
      v5 = (float)((float)((float)(atTime - tr->trTime) / (float)trDuration) * 3.1415927) * 2.0;
      __libm_sse2_sinf(a1);
LABEL_16:
      result->x = (float)(p_trDelta->x * v5) + tr->trBase.x;
      result->y = (float)(tr->trDelta.y * v5) + tr->trBase.y;
      result->z = (float)(tr->trDelta.z * v5) + tr->trBase.z;
      break;
    case 6u:
    case 0xDu:
      v9 = (float)(atTime - tr->trTime) * 0.001;
      result->x = (float)(p_trDelta->x * v9) + tr->trBase.x;
      result->y = (float)(tr->trDelta.y * v9) + tr->trBase.y;
      result->z = (float)(tr->trDelta.z * v9) + tr->trBase.z;
      v21 = bg_gravity;
      goto LABEL_28;
    case 7u:
      v9 = (float)(atTime - tr->trTime) * 0.001;
      result->x = (float)(p_trDelta->x * v9) + tr->trBase.x;
      result->y = (float)(tr->trDelta.y * v9) + tr->trBase.y;
      result->z = (float)(tr->trDelta.z * v9) + tr->trBase.z;
      v21 = bg_lowGravity;
      goto LABEL_28;
    case 8u:
      v10 = tr->trDuration;
      v11 = atTime;
      if ( atTime > v10 + tr->trTime )
        v11 = v10 + tr->trTime;
      deltaTime = (float)(v11 - tr->trTime) * 0.001;
      if ( !v10
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
              1839,
              0,
              "(tr->trDuration != 0)",
              "%s",
              "div by 0") )
      {
        __debugbreak();
      }
      phase = tr->trDuration;
      if ( !phase )
        goto LABEL_21;
      phaseb = Abs(&tr->trDelta) / ((double)phase * 0.001);
      Vec3NormalizeTo(&tr->trDelta, result);
      v12 = (float)((float)(phaseb * 0.5) * deltaTime) * deltaTime;
      result->x = (float)(result->x * v12) + tr->trBase.x;
      v13 = (float)(result->y * v12) + tr->trBase.y;
      v14 = v12 * result->z;
      result->y = v13;
      result->z = v14 + tr->trBase.z;
      break;
    case 9u:
      v15 = tr->trDuration;
      v16 = atTime;
      if ( atTime > v15 + tr->trTime )
        v16 = v15 + tr->trTime;
      deltaTimea = (float)(v16 - tr->trTime) * 0.001;
      if ( !v15
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
              1858,
              0,
              "(tr->trDuration != 0)",
              "%s",
              "div by 0") )
      {
        __debugbreak();
      }
      phasea = tr->trDuration;
      if ( phasea )
      {
        phasec = Abs(&tr->trDelta) / ((double)phasea * 0.001);
        Vec3NormalizeTo(&tr->trDelta, result);
        v17 = (float)((float)(phasec * -0.5) * deltaTimea) * deltaTimea;
        v18 = (float)(result->x * v17) + (float)((float)(p_trDelta->x * deltaTimea) + tr->trBase.x);
        v19 = (float)(result->y * v17) + (float)((float)(tr->trDelta.y * deltaTimea) + tr->trBase.y);
        v20 = (float)(v17 * result->z) + (float)((float)(tr->trDelta.z * deltaTimea) + tr->trBase.z);
        result->x = v18;
        result->y = v19;
        result->z = v20;
      }
      else
      {
LABEL_21:
        *result = tr->trBase;
      }
      break;
    case 0xFu:
      v9 = (float)(atTime - tr->trTime) * 0.001;
      result->x = (float)(p_trDelta->x * v9) + tr->trBase.x;
      result->y = (float)(tr->trDelta.y * v9) + tr->trBase.y;
      result->z = (float)(tr->trDelta.z * v9) + tr->trBase.z;
      v21 = bg_moonGravity;
LABEL_28:
      result->z = result->z - Dvar_GetFloat(v21) * 0.5 * v9 * v9;
      break;
    default:
      Com_Error(ERR_DROP, &byte_CEB6B0, tr->trType);
      break;
  }
  if ( ((LODWORD(tr->trBase.x) & 0x7F800000) == 2139095040
     || (LODWORD(tr->trBase.y) & 0x7F800000) == 2139095040
     || (LODWORD(tr->trBase.z) & 0x7F800000) == 2139095040)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          1878,
          0,
          "(!IS_NAN((tr->trBase)[0]) && !IS_NAN((tr->trBase)[1]) && !IS_NAN((tr->trBase)[2]))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( ((LODWORD(p_trDelta->x) & 0x7F800000) == 2139095040
     || (LODWORD(tr->trDelta.y) & 0x7F800000) == 2139095040
     || (LODWORD(tr->trDelta.z) & 0x7F800000) == 2139095040)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          1879,
          0,
          "(!IS_NAN((tr->trDelta)[0]) && !IS_NAN((tr->trDelta)[1]) && !IS_NAN((tr->trDelta)[2]))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x94F850
void __cdecl BG_GetPlayerViewDirection(const playerState_s *ps, vec3_t *forward, vec3_t *right, vec3_t *up)
{
  AngleVectors(&ps->viewangles, forward, right, up);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x94F880
void __cdecl BG_GetPlayerGunDirection(
        const playerState_s *ps,
        const float gunPitch,
        const float gunYaw,
        vec3_t *forward,
        vec3_t *right,
        vec3_t *up)
{
  vec3_t gunangles; // [esp+0h] [ebp-10h] BYREF

  *(_QWORD *)&gunangles.x = __PAIR64__(LODWORD(gunYaw), LODWORD(gunPitch));
  gunangles.z = 0.0;
  AngleVectors(&gunangles, forward, right, up);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x94F8E0
void __cdecl BG_ApplyLinkAngles(const vec3_t *linkAngles, vec3_t *viewangles)
{
  float kPlayerViewPitchUp; // [esp+4h] [ebp-A4h]
  vec3_t temp; // [esp+8h] [ebp-A0h] BYREF
  vec3_t viewAxis[3]; // [esp+14h] [ebp-94h] BYREF
  vec3_t mtx[3]; // [esp+38h] [ebp-70h] BYREF
  vec3_t linkAxisInv[3]; // [esp+5Ch] [ebp-4Ch] BYREF
  vec3_t linkAxis[3]; // [esp+80h] [ebp-28h] BYREF

  AnglesToAxis(linkAngles, linkAxis);
  MatrixTranspose(linkAxis, linkAxisInv);
  AnglesToAxis(viewangles, viewAxis);
  MatrixMultiply(viewAxis, linkAxisInv, mtx);
  AxisToAngles(mtx, &temp);
  kPlayerViewPitchUp = Dvar_GetFloat(player_view_pitch_up);
  if ( viewangles->x >= -90.0 || kPlayerViewPitchUp <= 85.0 )
    LODWORD(viewangles->z) = LODWORD(temp.z) ^ _mask__NegFloat_;
  else
    viewangles->z = COERCE_FLOAT(LODWORD(temp.z) ^ _mask__NegFloat_) - 180.0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x94FBD0
int __usercall BG_LoadShellShockDvars@<eax>(double a1@<st0>, const char *name)
{
  const char *RawTextFile; // ebx
  int DvarsFromBuffer; // esi
  const char *bg_shock_dvar_names[32]; // [esp+4h] [ebp-C4h] BYREF
  char fullpath[64]; // [esp+84h] [ebp-44h] BYREF

  Com_sprintf(fullpath, 64, "shock/%s.shock", name);
  RawTextFile = Com_LoadRawTextFile();
  if ( RawTextFile
    || (Com_PrintError(27, "couldn't open '%s'.\n", fullpath), (RawTextFile = Com_LoadRawTextFile()) != 0) )
  {
    qmemcpy(bg_shock_dvar_names, bgShockDvarNames, sizeof(bg_shock_dvar_names));
    DvarsFromBuffer = Com_LoadDvarsFromBuffer(a1, bg_shock_dvar_names, 0x20u, RawTextFile, fullpath);
    Com_UnloadRawTextFile(RawTextFile);
    return DvarsFromBuffer;
  }
  else
  {
    Com_PrintError(27, "couldn't open 'shock/default.shock'. This is a default shock file that you should have.\n");
    return 0;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x94FCA0
void __cdecl BG_SetShellShockParmsFromDvars(shellshock_parms_t *parms)
{
  int blurredFadeTime; // eax
  double Float; // st7
  float v4; // xmm1_4
  unsigned __int8 *String; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // eax
  float drylevel; // xmm0_4
  float wetlevel; // xmm0_4
  double v12; // st7
  const char *v13; // eax
  float v14; // [esp+14h] [ebp-4h]
  float v15; // [esp+14h] [ebp-4h]
  float v16; // [esp+14h] [ebp-4h]
  float v17; // [esp+14h] [ebp-4h]
  float v18; // [esp+14h] [ebp-4h]
  float v19; // [esp+14h] [ebp-4h]
  float v20; // [esp+14h] [ebp-4h]
  float v21; // [esp+14h] [ebp-4h]
  float v22; // [esp+14h] [ebp-4h]
  float v23; // [esp+14h] [ebp-4h]
  float parmsa; // [esp+20h] [ebp+8h]

  if ( !parms
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 3019, 0, "(parms)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v14 = Dvar_GetFloat(bg_shock_screenBlurBlendTime) * 1000.0;
  parms->screenBlend.blurredEffectTime = (int)(v14 + 9.313225746154785e-10);
  v15 = Dvar_GetFloat(bg_shock_screenBlurBlendFadeTime) * 1000.0;
  parms->screenBlend.blurredFadeTime = (int)(v15 + 9.313225746154785e-10);
  v16 = Dvar_GetFloat(bg_shock_screenFlashShotFadeTime) * 1000.0;
  parms->screenBlend.flashShotFadeTime = (int)(v16 + 9.313225746154785e-10);
  v17 = Dvar_GetFloat(bg_shock_screenFlashWhiteFadeTime) * 1000.0;
  blurredFadeTime = parms->screenBlend.blurredFadeTime;
  parms->screenBlend.flashWhiteFadeTime = (int)(v17 + 9.313225746154785e-10);
  if ( blurredFadeTime <= 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          3025,
          0,
          "((parms->screenBlend.blurredFadeTime > 0))",
          "(parms->screenBlend.blurredFadeTime) = %i",
          blurredFadeTime) )
  {
    __debugbreak();
  }
  if ( parms->screenBlend.blurredEffectTime <= 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          3026,
          0,
          "((parms->screenBlend.blurredEffectTime > 0))",
          "(parms->screenBlend.blurredEffectTime) = %i",
          parms->screenBlend.blurredEffectTime) )
  {
    __debugbreak();
  }
  parms->screenBlend.type = Dvar_GetInt(bg_shock_screenType);
  parms->view.fadeTime = 3000;
  Float = Dvar_GetFloat(bg_shock_viewKickPeriod);
  if ( 0.001 - Float < 0.0 )
  {
    parmsa = Float;
    v4 = parmsa;
  }
  else
  {
    v4 = FLOAT_0_001;
  }
  parms->view.kickRate = 0.001 / v4;
  parms->view.kickRadius = Dvar_GetFloat(bg_shock_viewKickRadius);
  parms->sound.affect = Dvar_GetBool(bg_shock_sound);
  String = (unsigned __int8 *)Dvar_GetString(bg_shock_soundLoop);
  strncpy((unsigned __int8 *)parms->sound.loop, String, 0x40u);
  v6 = (unsigned __int8 *)Dvar_GetString(bg_shock_soundLoopSilent);
  strncpy((unsigned __int8 *)parms->sound.loopSilent, v6, 0x40u);
  v7 = (unsigned __int8 *)Dvar_GetString(bg_shock_soundEnd);
  strncpy((unsigned __int8 *)parms->sound.end, v7, 0x40u);
  v8 = (unsigned __int8 *)Dvar_GetString(bg_shock_soundEndAbort);
  strncpy((unsigned __int8 *)parms->sound.endAbort, v8, 0x40u);
  v18 = Dvar_GetFloat(bg_shock_soundFadeInTime) * 1000.0;
  parms->sound.fadeInTime = (int)(v18 + 9.313225746154785e-10);
  v19 = Dvar_GetFloat(bg_shock_soundFadeOutTime) * 1000.0;
  parms->sound.fadeOutTime = (int)(v19 + 9.313225746154785e-10);
  v20 = Dvar_GetFloat(bg_shock_soundLoopFadeTime) * 1000.0;
  parms->sound.loopFadeTime = (int)(v20 + 9.313225746154785e-10);
  v21 = Dvar_GetFloat(bg_shock_soundLoopEndDelay) * 1000.0;
  parms->sound.loopEndDelay = (int)(v21 + 9.313225746154785e-10);
  v9 = (unsigned __int8 *)Dvar_GetString(bg_shock_soundRoomType);
  strncpy((unsigned __int8 *)parms->sound.roomtype, v9, 0x40u);
  parms->sound.drylevel = Dvar_GetFloat(bg_shock_soundDryLevel);
  parms->sound.wetlevel = Dvar_GetFloat(bg_shock_soundWetLevel);
  v22 = Dvar_GetFloat(bg_shock_soundModEndDelay) * 1000.0;
  parms->sound.modEndDelay = (int)(v22 + 9.313225746154785e-10);
  if ( parms->sound.fadeInTime < 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          3055,
          0,
          "((parms->sound.fadeInTime >= 0))",
          "(parms->sound.fadeInTime) = %i",
          parms->sound.fadeInTime) )
  {
    __debugbreak();
  }
  if ( parms->sound.fadeOutTime < 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          3056,
          0,
          "((parms->sound.fadeOutTime >= 0))",
          "(parms->sound.fadeOutTime) = %i",
          parms->sound.fadeOutTime) )
  {
    __debugbreak();
  }
  if ( parms->sound.loopFadeTime < 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          3057,
          0,
          "((parms->sound.loopFadeTime >= 0))",
          "(parms->sound.loopFadeTime) = %i",
          parms->sound.loopFadeTime) )
  {
    __debugbreak();
  }
  drylevel = parms->sound.drylevel;
  if ( (drylevel < 0.0 || drylevel > 1.0)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          3058,
          0,
          "((parms->sound.drylevel >= 0 && parms->sound.drylevel <= 1))",
          "(parms->sound.drylevel) = %g",
          drylevel) )
  {
    __debugbreak();
  }
  wetlevel = parms->sound.wetlevel;
  if ( (wetlevel < 0.0 || wetlevel > 1.0)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          3059,
          0,
          "((parms->sound.wetlevel >= 0 && parms->sound.wetlevel <= 1))",
          "(parms->sound.wetlevel) = %g",
          wetlevel) )
  {
    __debugbreak();
  }
  parms->lookControl.affect = Dvar_GetBool(bg_shock_lookControl);
  v23 = Dvar_GetFloat(bg_shock_lookControl_fadeTime) * 1000.0;
  v12 = v23 + 9.313225746154785e-10;
  parms->lookControl.fadeTime = (int)v12;
  if ( (int)v12 <= 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          3063,
          0,
          "((parms->lookControl.fadeTime > 0))",
          "(parms->lookControl.fadeTime) = %i",
          (int)v12) )
  {
    __debugbreak();
  }
  parms->lookControl.maxPitchSpeed = Dvar_GetFloat(bg_shock_lookControl_maxpitchspeed);
  parms->lookControl.maxYawSpeed = Dvar_GetFloat(bg_shock_lookControl_maxyawspeed);
  parms->lookControl.mouseSensitivity = Dvar_GetFloat(bg_shock_lookControl_mousesensitivityscale);
  parms->movement.scale = Dvar_GetFloat(bg_shock_movement);
  parms->animation.affect = Dvar_GetBool(bg_shock_animation);
  v13 = (const char *)Dvar_GetString(bg_shock_visionset_name);
  I_strncpyz(parms->visionSet.name, v13, 32);
  parms->visionSet.inTime = (int)(Dvar_GetFloat(bg_shock_visionset_inTime) * 1000.0);
  parms->visionSet.outTime = (int)(Dvar_GetFloat(bg_shock_visionset_outTime) * 1000.0);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x952AE0
void __cdecl TRACK_bg_misctables()
{
  track_static_alloc_internal(s_vehicleClassNames, 28, "s_vehicleClassNames", 11);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x952B00
void __cdecl Perks_CalculateStringHashes()
{
  unsigned int i; // esi
  int v1; // ebx
  int v2; // edi
  unsigned int j; // esi
  int v4; // [esp+0h] [ebp-4h]

  if ( !bg_perkNamesHashed )
  {
    for ( i = 0; i < 63; ++i )
    {
      if ( I_strncmp(bg_perkNames[i], "specialty_", 10)
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_perks.cpp",
              94,
              0,
              "(0 == I_strncmp(bg_perkNames[i], \"specialty_\", (sizeof(\"specialty_\")-1)))",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      bg_perkNameHashes[i] = BG_StringHashValue(bg_perkNames[i]);
    }
    v1 = 1;
    v2 = 0;
    v4 = 62;
    do
    {
      for ( j = v1; j < 0x3F; ++j )
      {
        if ( bg_perkNameHashes[v2] == bg_perkNameHashes[j] )
          Com_PrintError(1, "Hash collision between %s and %s.\n", bg_perkNames[v2], bg_perkNames[j]);
      }
      ++v1;
      ++v2;
      --v4;
    }
    while ( v4 );
    bg_perkNamesHashed = 1;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x952BE0
unsigned int __cdecl BG_GetPerkIndexForName(const char *perkName)
{
  unsigned int result; // eax
  int v2; // ecx

  if ( !perkName )
    return 63;
  v2 = BG_StringHashValue(perkName);
  result = 0;
  while ( v2 != bg_perkNameHashes[result] )
  {
    if ( v2 == bg_perkNameHashes[result + 1] )
    {
      ++result;
      return result;
    }
    if ( v2 == bg_perkNameHashes[result + 2] )
    {
      result += 2;
      return result;
    }
    result += 3;
    if ( result >= 0x3F )
      return result;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x952C30
const char *__cdecl BG_GetPerkNameForIndex(unsigned int perkIndex)
{
  if ( perkIndex >= 0x3F
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_perks.cpp",
          139,
          0,
          "(unsigned)(perkIndex) < (unsigned)(PERK_COUNT)",
          "perkIndex doesn't index PERK_COUNT\n\t%i not in [0, %i)",
          perkIndex,
          63) )
  {
    __debugbreak();
  }
  return bg_perkNames[perkIndex];
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x952C70
void __usercall Perks_RegisterDvars(double a1@<st0>)
{
  perk_weapSwitchMultiplier = _Dvar_RegisterFloat(
                                a1,
                                "perk_weapSwitchMultiplier",
                                0.5,
                                0.0099999998,
                                1.0,
                                0x80u,
                                "Percentage of weapon switching rate to use");
  perk_weapSpreadMultiplier = _Dvar_RegisterFloat(
                                a1,
                                "perk_weapSpreadMultiplier",
                                0.64999998,
                                0.0,
                                1.0,
                                0x80u,
                                "Percentage of weapon spread to use");
  perk_weapReloadMultiplier = _Dvar_RegisterFloat(
                                a1,
                                "perk_weapReloadMultiplier",
                                0.5,
                                0.0,
                                1.0,
                                0x80u,
                                "Percentage of weapon reload time to use");
  perk_weapRateMultiplier = _Dvar_RegisterFloat(
                              a1,
                              "perk_weapRateMultiplier",
                              0.75,
                              0.0,
                              1.0,
                              0x80u,
                              "Percentage of weapon firing rate to use");
  perk_weapAdsMultiplier = _Dvar_RegisterFloat(
                             a1,
                             "perk_weapAdsMultiplier",
                             0.5,
                             0.0099999998,
                             1.0,
                             0x80u,
                             "Percentage of weapon ADS rate to use");
  perk_weapMeleeMultiplier = _Dvar_RegisterFloat(
                               a1,
                               "perk_weapMeleeMultiplier",
                               0.5,
                               0.0099999998,
                               1.0,
                               0x80u,
                               "Percentage of weapon melee recovery rate to use");
  perk_weapTossMultiplier = _Dvar_RegisterFloat(
                              a1,
                              "perk_weapTossMultiplier",
                              0.5,
                              0.0099999998,
                              1.0,
                              0x80u,
                              "Percentage of grenade toss rate to use");
  perk_weapEquipmentUseMultiplier = _Dvar_RegisterFloat(
                                      a1,
                                      "perk_weapEquipmentUseMultiplier",
                                      0.60000002,
                                      0.0099999998,
                                      1.0,
                                      0x80u,
                                      "Percentage of equipment use rate to use");
  perk_extraBreath = _Dvar_RegisterFloat(
                       a1,
                       "perk_extraBreath",
                       5.0,
                       0.0,
                       3.4028235e38,
                       0x80u,
                       "Number of extra seconds a player can hold his breath");
  perk_bulletPenetrationMultiplier = _Dvar_RegisterFloat(
                                       a1,
                                       "perk_bulletPenetrationMultiplier",
                                       2.0,
                                       0.0,
                                       30.0,
                                       0x80u,
                                       "Multiplier for extra bullet penetration");
  perk_grenadeDeath = _Dvar_RegisterString(
                        a1,
                        "perk_grenadeDeath",
                        "frag_grenade_short_mp",
                        0x80u,
                        "Name of the grenade weapon to drop");
  perk_sprintMultiplier = _Dvar_RegisterFloat(
                            a1,
                            "perk_sprintMultiplier",
                            2.0,
                            0.0,
                            3.0,
                            0x80u,
                            "Multiplier for player_sprinttime");
  perk_grenadeTossBackTimer = _Dvar_RegisterInt(
                                a1,
                                "perk_grenadeTossBackTimer",
                                2500,
                                0,
                                6000,
                                0x80u,
                                "Minimum timer for a grenade.  If the time left is less than this it will be bumped up.  Tossback Perk");
  perk_killstreakReduction = _Dvar_RegisterInt(
                               a1,
                               "perk_killstreakReduction",
                               1,
                               0,
                               5,
                               0x80u,
                               "Reduced number of kills required to obtain a killstreak.");
  perk_killstreakMomentumMultiplier = _Dvar_RegisterFloat(
                                        a1,
                                        "perk_killstreakMomentumMultiplier",
                                        1.2,
                                        1.0,
                                        2.0,
                                        0x80u,
                                        "Multiplies the amount of momentum received by the player");
  perk_killstreakDeathPenaltyMultiplier = _Dvar_RegisterFloat(
                                            a1,
                                            "perk_killstreakDeathPenaltyMultiplier",
                                            0.5,
                                            0.0,
                                            1.0,
                                            0x80u,
                                            "Multiplies the amount of death penalty received by the player");
  perk_delayExplosiveTime = _Dvar_RegisterFloat(
                              a1,
                              "perk_delayExplosiveTime",
                              0.89999998,
                              0.0,
                              10.0,
                              0x80u,
                              "Time in seconds to delay a proximity explosive");
  perk_disarmExplosiveTime = _Dvar_RegisterFloat(
                               a1,
                               "perk_disarmExplosiveTime",
                               2.0,
                               0.0,
                               20.0,
                               0x80u,
                               "Time in seconds to disarm a proximity explosive");
  perk_speedMultiplier = _Dvar_RegisterFloat(
                           a1,
                           "perk_speedMultiplier",
                           1.0700001,
                           0.0,
                           5.0,
                           0x80u,
                           "Player speed multiplier");
  perk_deathStreakCountRequired = _Dvar_RegisterInt(
                                    a1,
                                    "perk_deathStreakCountRequired",
                                    3,
                                    1,
                                    10,
                                    0x80u,
                                    "Number of deaths required to obtain a deathstreak.");
  perk_sprintRecoveryMultiplier = _Dvar_RegisterFloat(
                                    a1,
                                    "perk_sprintRecoveryMultiplier",
                                    0.30000001,
                                    0.0,
                                    1.0,
                                    0x80u,
                                    "Percent of sprint recovery time to use.");
  perk_healthRegenMultiplier = _Dvar_RegisterFloat(
                                 a1,
                                 "perk_healthRegenMultiplier",
                                 1.5,
                                 1.0,
                                 5.0,
                                 0x80u,
                                 "Multiplier to the time which the player starts to regenerate health after damage");
  perk_damageKickReduction = _Dvar_RegisterFloat(
                               a1,
                               "perk_damageKickReduction",
                               0.25,
                               0.0,
                               1.0,
                               0x80u,
                               "The percentage decrease of view kick flinch when the player takes damage");
  perk_shellShockReduction = _Dvar_RegisterFloat(
                               a1,
                               "perk_shellShockReduction",
                               0.5,
                               0.0,
                               1.0,
                               0x80u,
                               "The percentage decrease of shellshock time");
  perk_mantleReduction = _Dvar_RegisterFloat(
                           a1,
                           "perk_mantleReduction",
                           0.40000001,
                           0.0,
                           1.0,
                           0x80u,
                           "The percentage decrease of mantle up time");
  perk_interactSpeedMultiplier = _Dvar_RegisterFloat(
                                   a1,
                                   "perk_interactSpeedMultiplier",
                                   1.15,
                                   0.0,
                                   10.0,
                                   0x80u,
                                   "Multiplier for increasing use timers.");
  perk_throwbackInnerRadius = _Dvar_RegisterFloat(
                                a1,
                                "perk_throwbackInnerRadius",
                                120.0,
                                0.0,
                                3.4028235e38,
                                0x80u,
                                "The radius to a live grenade player must be within initially to do a throwback with the "
                                "toss back perk on");
  perk_flakJacket = _Dvar_RegisterFloat(
                      a1,
                      "perk_flakJacket",
                      35.0,
                      0.0,
                      3.4028235e38,
                      0x80u,
                      "Percent of explosive damage done that will apply to player.");
  perk_flakJacket_hardcore = _Dvar_RegisterFloat(
                               a1,
                               "perk_flakJacket_hardcore",
                               20.0,
                               0.0,
                               3.4028235e38,
                               0x80u,
                               "Percent of explosive damage done that will apply to player in hardcore.");
  perk_fireproof = _Dvar_RegisterFloat(
                     a1,
                     "perk_fireproof",
                     95.0,
                     0.0,
                     3.4028235e38,
                     0x80u,
                     "Percent to reduce flame damage done to the player.");
  perk_armorPiercing = _Dvar_RegisterFloat(
                         a1,
                         "perk_armorPiercing",
                         95.0,
                         0.0,
                         3.4028235e38,
                         0x80u,
                         "Percent bullet damage is increased for helicopters, spy planes, and turrets.");
  perk_dogsAttackGhost = _Dvar_RegisterBool(
                           a1,
                           "perk_dogsAttackGhost",
                           1,
                           0x80u,
                           "Set to true if the dogs should attack players with 'specialty_nottargetedbyai'");
  perk_blackbirdShowsGpsJammer = _Dvar_RegisterBool(
                                   a1,
                                   "perk_blackbirdShowsGpsJammer",
                                   1,
                                   0x80u,
                                   "Set to true if the blackbird should show players with 'specialty_gpsjammer'");
  perk_fastLadderClimbMultiplier = _Dvar_RegisterFloat(
                                     a1,
                                     "perk_fastLadderClimbMultiplier",
                                     1.75,
                                     0.0,
                                     3.4028235e38,
                                     0x80u,
                                     "Multiplier for ladder climbing speed.");
  perk_marksmanEnemyNameFadeIn = _Dvar_RegisterInt(
                                   a1,
                                   "perk_marksmanEnemyNameFadeIn",
                                   5,
                                   0,
                                   0x7FFFFFFF,
                                   0x80u,
                                   "Time in milliseconds to fade in enemy names for the marksman perk.");
  perk_marksmanEnemyNameFadeOut = _Dvar_RegisterInt(
                                    a1,
                                    "perk_marksmanEnemyNameFadeOut",
                                    5,
                                    0,
                                    0x7FFFFFFF,
                                    0x80u,
                                    "Time in milliseconds to fade out enemy names for the marksman perk.");
  perk_gpsjammer_min_speed = _Dvar_RegisterInt(
                               a1,
                               "perk_gpsjammer_min_speed",
                               100,
                               0,
                               300,
                               0x80u,
                               "Minimum speed a player must be moving for gpsjammer to protect them from UAV sweeps.  Bas"
                               "ed on player speed used in g_speed (I believe this is units/sec).  If 0, player will alwa"
                               "ys be protected from UAV sweeps with this specialty.");
  perk_gpsjammer_min_distance = _Dvar_RegisterInt(
                                  a1,
                                  "perk_gpsjammer_min_distance",
                                  100,
                                  0,
                                  10000,
                                  0x80u,
                                  "Minimum distance a player must have moved in a time period for gpsjammer to protect th"
                                  "em from UAV sweeps.  If 0, player will always be protected from UAV sweeps with this specialty.");
  perk_gpsjammer_time_period = _Dvar_RegisterInt(
                                 a1,
                                 "perk_gpsjammer_time_period",
                                 150,
                                 50,
                                 10000,
                                 0x80u,
                                 "Time period inbetween checks, in MSec. Please use multiples of 50 msec as that is the p"
                                 "eriod of server script ");
  perk_gpsjammer_graceperiods = _Dvar_RegisterInt(
                                  a1,
                                  "perk_gpsjammer_graceperiods",
                                  10,
                                  0,
                                  30,
                                  0x80u,
                                  "Number of time period a player can be below the required velocity before removing protection.");
  perk_gpsjammer_alpha = _Dvar_RegisterFloat(
                           a1,
                           "perk_gpsjammer_alpha",
                           0.5,
                           0.0,
                           1.0,
                           0x80u,
                           "The alpha of the player material on the minimap when being protected");
  perk_gpsjammer_fade_time = _Dvar_RegisterInt(
                               a1,
                               "perk_gpsjammer_fade_time",
                               500,
                               0,
                               60000,
                               0x80u,
                               "The time ( in MSec ) for the player indicator to fade when being protected");
  perk_nottargetedbyai_min_speed = _Dvar_RegisterInt(
                                     a1,
                                     "perk_nottargetedbyai_min_speed",
                                     0,
                                     0,
                                     300,
                                     0x80u,
                                     "Minimum speed a player must be moving for nottargetedbyai to protect them from AI c"
                                     "ontrolled killstreaks. If 0, player will always be protected from AI controlled kil"
                                     "lstreaks with this specialty.");
  perk_nottargetedbyai_graceperiod = _Dvar_RegisterInt(
                                       a1,
                                       "perk_nottargetedbyai_graceperiod",
                                       2000,
                                       0,
                                       10000,
                                       0x80u,
                                       "Time after which the player drops below min_gpsjammer_speed that they are still p"
                                       "rotected from ai support targetting.  0-10000 int (in milliseconds), 0 default. ");
  perk_scavenger_clip_multiplier = _Dvar_RegisterFloat(
                                     a1,
                                     "perk_scavenger_clip_multiplier",
                                     1.0,
                                     0.0,
                                     10.0,
                                     0x80u,
                                     "On every scavenger pick up, give the player scavenger_clip_multiplier clips of ammo"
                                     " for every weapon they are carrying - where a \"clip\" equals the ammo count in the"
                                     " weapon's GDT entry \"clipSize\". 0-10 float, 2 default. Support rounding to an int"
                                     "eger bullet count when a float is used.");
  perk_scavenger_lethal_proc = _Dvar_RegisterInt(
                                 a1,
                                 "perk_scavenger_lethal_proc",
                                 1,
                                 0,
                                 10,
                                 0x80u,
                                 "On every (scavenger_lethal_proc) scavenger pickups, the player receives +1 lethal.  I.e"
                                 ". if this were 3, the player would need to pick up 3 scavenger bags to refill 1 frag grenade.");
  perk_scavenger_tactical_proc = _Dvar_RegisterInt(
                                   a1,
                                   "perk_scavenger_tactical_proc",
                                   1,
                                   0,
                                   10,
                                   0x80u,
                                   "- On every (scavenger_tactical_proc) scavenger pickups, the player receives +1 tactic"
                                   "al.  0-10 int, 2 default.");
  Perks_CalculateStringHashes();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x953A20
void __cdecl PM_ClipVelocity(const vec3_t *in, const vec3_t *normal, vec3_t *out)
{
  float v3; // xmm0_4
  float v4; // xmm0_4

  v3 = (float)((float)(normal->x * in->x) + (float)(normal->y * in->y)) + (float)(normal->z * in->z);
  LODWORD(v4) = COERCE_UNSIGNED_INT(v3 - (float)(COERCE_FLOAT(LODWORD(v3) & _mask__AbsFloat_) * 0.001)) ^ _mask__NegFloat_;
  out->x = (float)(normal->x * v4) + in->x;
  out->y = (float)(normal->y * v4) + in->y;
  out->z = (float)(normal->z * v4) + in->z;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.inl:0x9C6870
void __cdecl split_cb_search_shape_sign_N1(
        float *target,
        float *ak,
        float *awk1,
        float *awk2,
        const void *par,
        int p,
        int nsf,
        float *exc,
        float *r,
        SpeexBits *bits,
        char *stack,
        int complexity)
{
  const char *v12; // edx
  int v13; // ecx
  int v14; // esi
  float *v15; // edi
  int v16; // ebx
  int v17; // eax
  int v18; // ebx
  char *v19; // ecx
  char *v20; // ebx
  float *v21; // ecx
  int v22; // eax
  float *v23; // eax
  float *v24; // edx
  int v25; // ecx
  double v26; // st7
  bool v27; // zf
  char *v28; // edx
  float *v29; // eax
  int v30; // ecx
  double v31; // st7
  float *v32; // ecx
  double v33; // st7
  int v34; // eax
  int v35; // eax
  float *v36; // ecx
  int v37; // edi
  double v38; // st5
  float *v39; // eax
  float *v40; // ecx
  unsigned int v41; // edx
  double v42; // st4
  double v43; // st4
  float *v44; // eax
  double v45; // st4
  int v46; // eax
  float *v47; // ecx
  unsigned int v48; // edx
  double v49; // st4
  float *v50; // eax
  double v51; // st4
  double v52; // st4
  int v53; // eax
  double v54; // st4
  char *v55; // ecx
  const char *v56; // edx
  double v57; // st4
  double v58; // st5
  float *v59; // ecx
  const char *v60; // edx
  double v61; // st5
  double v62; // rt0
  int v63; // eax
  double v64; // rt1
  double v65; // st5
  double v66; // st7
  int v67; // edi
  int v68; // edx
  int v69; // ecx
  double v70; // st4
  int v71; // ecx
  float v72; // edi
  unsigned int v73; // eax
  double v74; // st3
  float *v75; // eax
  double v76; // st3
  double v77; // st2
  int v79; // esi
  float *v80; // ecx
  float *v81; // eax
  unsigned int v82; // edx
  int v83; // esi
  double v84; // st7
  float *v85; // eax
  int v86; // edx
  int v87; // ecx
  double v88; // st7
  float *v89; // esi
  int v90; // ecx
  float *v91; // eax
  unsigned int v92; // edx
  float *v93; // ecx
  double v94; // st7
  double v95; // st7
  int v96; // esi
  float *v97; // eax
  int v98; // edi
  double v99; // st7
  char *v100; // [esp-4h] [ebp-64h]
  float ga; // [esp+10h] [ebp-50h]
  int g; // [esp+10h] [ebp-50h]
  char *v103; // [esp+14h] [ebp-4Ch]
  float best_dist; // [esp+18h] [ebp-48h] BYREF
  int nb_subvect; // [esp+1Ch] [ebp-44h]
  float v106; // [esp+20h] [ebp-40h]
  int shape_cb_size; // [esp+24h] [ebp-3Ch]
  int have_sign; // [esp+28h] [ebp-38h]
  int v109; // [esp+2Ch] [ebp-34h]
  int v110; // [esp+30h] [ebp-30h]
  float sign; // [esp+34h] [ebp-2Ch]
  float *res; // [esp+38h] [ebp-28h]
  float *E; // [esp+3Ch] [ebp-24h]
  int i; // [esp+40h] [ebp-20h]
  const char *shape_cb; // [esp+44h] [ebp-1Ch]
  int best_index; // [esp+48h] [ebp-18h] BYREF
  float *resp; // [esp+4Ch] [ebp-14h]
  float *e; // [esp+50h] [ebp-10h]
  char *v119; // [esp+54h] [ebp-Ch]
  int v120; // [esp+58h] [ebp-8h]
  float *v121; // [esp+5Ch] [ebp-4h]
  int j; // [esp+80h] [ebp+20h]
  int ja; // [esp+80h] [ebp+20h]
  float *t; // [esp+90h] [ebp+30h]

  v12 = (const char *)*((_DWORD *)par + 2);
  nb_subvect = *((_DWORD *)par + 1);
  v13 = *((_DWORD *)par + 3);
  v14 = *(_DWORD *)par;
  have_sign = *((_DWORD *)par + 4);
  v15 = (float *)(1 << v13);
  v16 = (int)&stack[4 * v14 * (1 << v13) + (-(int)stack & 3)];
  shape_cb = v12;
  resp = (float *)&stack[-(int)stack & 3];
  v17 = 4 * (1 << v13);
  v18 = v17 + (-v16 & 3) + v16;
  E = (float *)(v18 - v17);
  v19 = (char *)(4 * nsf + (-v18 & 3) + v18);
  v20 = &v19[4 * nsf + (-(int)v19 & 3)];
  v21 = (float *)&v19[-4 * nsf];
  v22 = 0;
  shape_cb_size = (int)v15;
  t = v21;
  e = (float *)&v20[-4 * nsf];
  i = 0;
  if ( nsf >= 4 )
  {
    v23 = v21 + 1;
    v24 = target + 3;
    v119 = (char *)((char *)target - (char *)v21);
    v109 = ((unsigned int)(nsf - 4) >> 2) + 1;
    i = 4 * v109;
    do
    {
      v25 = (int)v119;
      *(v23 - 1) = *(v24 - 3);
      v23 += 4;
      v26 = *(float *)((char *)v23 + v25 - 16);
      v24 += 4;
      v27 = v109-- == 1;
      *(v23 - 4) = v26;
      *(v23 - 3) = *(v24 - 5);
      *(v23 - 2) = *(v24 - 4);
    }
    while ( !v27 );
    v21 = t;
    v22 = i;
  }
  if ( v22 < nsf )
  {
    v28 = (char *)((char *)target - (char *)v21);
    v29 = &v21[v22];
    v30 = nsf - i;
    v119 = v28;
    do
    {
      v31 = *(float *)&v28[(_DWORD)v29++];
      --v30;
      *(v29 - 1) = v31;
    }
    while ( v30 );
  }
  compute_weighted_codebook(shape_cb, v20, r, resp, E, v15, v14);
  if ( nb_subvect > 0 )
  {
    v32 = t;
    v110 = nsf - v14;
    v109 = (int)&t[v14 + 2];
    v120 = 0;
    v119 = (char *)v14;
    v121 = t;
    v103 = (char *)((char *)e - (char *)t);
    while ( 1 )
    {
      if ( have_sign )
        vq_nbest_sign(v32, resp, v14, (int)v15, E, 1, &best_index, &best_dist, v20);
      else
        vq_nbest(v32, resp, v14, (int)v15, E, 1, &best_index, &best_dist, v20);
      speex_bits_pack(bits, best_index, have_sign + *((_DWORD *)par + 3));
      v33 = 1.0;
      v34 = best_index;
      sign = 1.0;
      if ( best_index >= (int)v15 )
      {
        sign = -1.0;
        v34 = best_index - (_DWORD)v15;
      }
      v35 = v14 * v34;
      v36 = &resp[v35];
      i = v35;
      v37 = 0;
      res = v36;
      v38 = sign;
      if ( sign <= 0.0 )
      {
        if ( v14 >= 4 )
        {
          v46 = (int)v121;
          v47 = v36 + 2;
          v48 = ((unsigned int)(v14 - 4) >> 2) + 1;
          v37 = 4 * v48;
          do
          {
            v46 += 16;
            v49 = *(v47 - 2) + *(float *)(v46 - 16);
            v47 += 4;
            --v48;
            *(float *)(v46 - 16) = v49;
            *(float *)(v46 - 12) = *(v47 - 5) + *(float *)(v46 - 12);
            *(float *)(v46 - 8) = *(float *)(v46 - 8) + *(v47 - 4);
            *(float *)(v46 - 4) = *(v47 - 3) + *(float *)(v46 - 4);
          }
          while ( v48 );
          v36 = res;
        }
        if ( v37 < v14 )
        {
          v50 = &t[v37 + v120];
          do
          {
            v51 = v36[v37++];
            v52 = v51 + *v50++;
            *(v50 - 1) = v52;
          }
          while ( v37 < v14 );
        }
      }
      else
      {
        if ( v14 >= 4 )
        {
          v39 = v121;
          v40 = v36 + 2;
          v41 = ((unsigned int)(v14 - 4) >> 2) + 1;
          v37 = 4 * v41;
          do
          {
            v42 = *v39;
            v39 += 4;
            v43 = v42 - *(v40 - 2);
            v40 += 4;
            --v41;
            *(v39 - 4) = v43;
            *(v39 - 3) = *(v39 - 3) - *(v40 - 5);
            *(v39 - 2) = *(v39 - 2) - *(v40 - 4);
            *(v39 - 1) = *(v39 - 1) - *(v40 - 3);
          }
          while ( v41 );
          v36 = res;
        }
        if ( v37 < v14 )
        {
          v44 = &t[v37 + v120];
          do
          {
            v45 = *v44 - v36[v37++];
            *v44++ = v45;
          }
          while ( v37 < v14 );
        }
      }
      v53 = 0;
      if ( v14 < 4 )
      {
        v57 = 0.03125;
      }
      else
      {
        v54 = v38 * 0.03125;
        v55 = &v103[(_DWORD)v121];
        v56 = &shape_cb[i + 1];
        do
        {
          LODWORD(v106) = v56[v53 - 1];
          v53 += 4;
          v55 += 16;
          *((float *)v55 - 4) = (double)SLODWORD(v106) * v54;
          LODWORD(v106) = v56[v53 - 4];
          *((float *)v55 - 3) = (double)SLODWORD(v106) * v54;
          LODWORD(v106) = v56[v53 - 3];
          *((float *)v55 - 2) = (double)SLODWORD(v106) * v54;
          LODWORD(v106) = v56[v53 - 2];
          *((float *)v55 - 1) = (double)SLODWORD(v106) * v54;
        }
        while ( v53 < v14 - 3 );
        v57 = 0.03125;
      }
      if ( v53 < v14 )
      {
        v58 = v38 * v57;
        v59 = &e[v53 + v120];
        v60 = &shape_cb[i];
        do
        {
          LODWORD(v106) = v60[v53++];
          *v59++ = (double)SLODWORD(v106) * v58;
        }
        while ( v53 < v14 );
      }
      v61 = v57;
      res = 0;
      if ( v14 > 0 )
      {
        i = v14;
        LODWORD(sign) = &r[v14 + 2];
        while ( 1 )
        {
          v63 = best_index;
          v64 = v61;
          v65 = v33;
          v66 = v64;
          v106 = v65;
          if ( best_index >= shape_cb_size )
          {
            v63 = best_index - shape_cb_size;
            v106 = -1.0;
          }
          v67 = nsf;
          v68 = (int)v119;
          v69 = i;
          if ( (int)v119 < nsf )
          {
            ga = (double)shape_cb[(_DWORD)res + v14 * v63] * (v106 * v66);
            v70 = ga;
            if ( v110 >= 4 )
            {
              v71 = v109;
              v72 = sign;
              v73 = ((unsigned int)(nsf - (_DWORD)v119 - 4) >> 2) + 1;
              g = i + 4 * v73;
              v68 = (int)&v119[4 * v73];
              do
              {
                v74 = *(float *)(v71 - 8);
                LODWORD(v72) += 16;
                v71 += 16;
                --v73;
                *(float *)(v71 - 24) = v74 - *(float *)(LODWORD(v72) - 24) * v70;
                *(float *)(v71 - 20) = *(float *)(v71 - 20) - *(float *)(LODWORD(v72) - 20) * v70;
                *(float *)(v71 - 16) = *(float *)(v71 - 16) - *(float *)(LODWORD(v72) - 16) * v70;
                *(float *)(v71 - 12) = *(float *)(v71 - 12) - *(float *)(LODWORD(v72) - 12) * v70;
              }
              while ( v73 );
              v69 = g;
              v67 = nsf;
            }
            if ( v68 < v67 )
            {
              v75 = &r[v69];
              do
              {
                v76 = t[v68++];
                v77 = *v75++;
                t[v68 - 1] = v76 - v77 * v70;
              }
              while ( v68 < v67 );
            }
          }
          --i;
          LODWORD(sign) -= 4;
          res = (float *)((char *)res + 1);
          if ( (int)res >= v14 )
            break;
          v62 = v65;
          v61 = v66;
          v33 = v62;
        }
      }
      v120 += v14;
      v110 -= v14;
      v119 += v14;
      v121 += v14;
      v109 += 4 * v14;
      if ( !--nb_subvect )
        break;
      v15 = (float *)shape_cb_size;
      v32 = v121;
    }
  }
  v79 = 0;
  if ( nsf >= 4 )
  {
    v80 = e + 3;
    v81 = exc + 1;
    v82 = ((unsigned int)(nsf - 4) >> 2) + 1;
    j = 4 * v82;
    v83 = (char *)e - (char *)exc;
    do
    {
      v81 += 4;
      v84 = *(v80 - 3) + *(v81 - 5);
      v80 += 4;
      --v82;
      *(v81 - 5) = v84;
      *(v81 - 4) = *(float *)((char *)v81 + v83 - 16) + *(v81 - 4);
      *(v81 - 3) = *(v80 - 5) + *(v81 - 3);
      *(v81 - 2) = *(v80 - 4) + *(v81 - 2);
    }
    while ( v82 );
    v79 = j;
  }
  if ( v79 < nsf )
  {
    v85 = &exc[v79];
    v86 = (char *)e - (char *)exc;
    v87 = nsf - v79;
    do
    {
      v88 = *(float *)((char *)v85++ + v86);
      --v87;
      *(v85 - 1) = v88 + *(v85 - 1);
    }
    while ( v87 );
  }
  if ( complexity )
  {
    v100 = &v20[4 * nsf + (-(int)v20 & 3)];
    v89 = (float *)&v100[-4 * nsf];
    syn_percep_zero(e, ak, awk1, awk2, v89, nsf, p, v100);
    v90 = 0;
    if ( nsf >= 4 )
    {
      v91 = target + 1;
      v92 = ((unsigned int)(nsf - 4) >> 2) + 1;
      ja = 4 * v92;
      v93 = v89 + 3;
      do
      {
        v94 = *(v91 - 1);
        v91 += 4;
        v95 = v94 - *(v93 - 3);
        v93 += 4;
        --v92;
        *(v91 - 5) = v95;
        *(v91 - 4) = *(v91 - 4) - *(float *)((char *)v91 + (char *)v89 - (char *)target - 16);
        *(v91 - 3) = *(v91 - 3) - *(v93 - 5);
        *(v91 - 2) = *(v91 - 2) - *(v93 - 4);
      }
      while ( v92 );
      v90 = ja;
    }
    if ( v90 < nsf )
    {
      v96 = (char *)v89 - (char *)target;
      v97 = &target[v90];
      v98 = nsf - v90;
      do
      {
        v99 = *v97++;
        --v98;
        *(v97 - 1) = v99 - *(float *)((char *)v97 + v96 - 4);
      }
      while ( v98 );
    }
  }
}

#endif // __UNIMPLEMENTED__
