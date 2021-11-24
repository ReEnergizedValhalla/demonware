// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdauthservice.cpp:0x934130
void __cdecl Dog_CreateAnims(void *(__cdecl *xanimAlloc)(int))
{
  signed int i; // esi
  int j; // esi
  int k; // esi
  int m; // esi
  int n; // esi
  int ii; // esi
  int jj; // esi

  if ( !s_dogAnims )
  {
    s_dogAnims = XAnimCreateAnims("DOG_ANIMS", 63, xanimAlloc);
    if ( !s_dogAnims
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_actor_dog_animations_mp.cpp",
            661,
            0,
            "(s_dogAnims)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    XAnimBlend(s_dogAnims, 0, s_dogAnimNames[0], 1u, 0x2Cu, 0);
    for ( i = 1; i < 38; ++i )
      BG_CreateXAnim(s_dogAnims, i, s_dogAnimNames[i]);
    XAnimBlend(s_dogAnims, 0x26u, s_dogAnimNamesRunStartKnob[0], 0x2Du, 1u, 2u);
    BG_CreateXAnim(s_dogAnims, 0x2Du, s_dogAnimNamesRunStartKnob[1]);
    XAnimBlend(s_dogAnims, 0x27u, s_dogAnimNamesRunKnob[0], 0x2Eu, 6u, 1u);
    for ( j = 1; j < 7; ++j )
      BG_CreateXAnim(s_dogAnims, j + 45, s_dogAnimNamesRunKnob[j]);
    XAnimBlend(s_dogAnims, 0x28u, s_dogAnimNamesAttackIdleKnob[0], 0x34u, 3u, 0);
    for ( k = 1; k < 4; ++k )
      BG_CreateXAnim(s_dogAnims, k + 51, s_dogAnimNamesAttackIdleKnob[k]);
    XAnimBlend(s_dogAnims, 0x29u, s_dogAnimNamesLookDown[0], 0x37u, 2u, 0x10u);
    for ( m = 1; m < 3; ++m )
      BG_CreateXAnim(s_dogAnims, m + 54, s_dogAnimNamesLookDown[m]);
    XAnimBlend(s_dogAnims, 0x2Au, s_dogAnimNamesLookUp[0], 0x39u, 2u, 0x10u);
    for ( n = 1; n < 3; ++n )
      BG_CreateXAnim(s_dogAnims, n + 56, s_dogAnimNamesLookUp[n]);
    XAnimBlend(s_dogAnims, 0x2Bu, s_dogAnimNamesLookRight[0], 0x3Bu, 2u, 0x10u);
    for ( ii = 1; ii < 3; ++ii )
      BG_CreateXAnim(s_dogAnims, ii + 58, s_dogAnimNamesLookRight[ii]);
    XAnimBlend(s_dogAnims, 0x2Cu, s_dogAnimNamesLookLeft[0], 0x3Du, 2u, 0x10u);
    for ( jj = 1; jj < 3; ++jj )
      BG_CreateXAnim(s_dogAnims, jj + 60, s_dogAnimNamesLookLeft[jj]);
    XAnimSetupSyncNodes(s_dogAnims);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdauthservice.cpp:0x934130
void __cdecl Dog_CreateAnims(void *(__cdecl *xanimAlloc)(int))
{
  signed int i; // esi
  int j; // esi
  int k; // esi
  int m; // esi
  int n; // esi
  int ii; // esi
  int jj; // esi

  if ( !s_dogAnims )
  {
    s_dogAnims = XAnimCreateAnims("DOG_ANIMS", 63, xanimAlloc);
    if ( !s_dogAnims
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_actor_dog_animations_mp.cpp",
            661,
            0,
            "(s_dogAnims)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    XAnimBlend(s_dogAnims, 0, s_dogAnimNames[0], 1u, 0x2Cu, 0);
    for ( i = 1; i < 38; ++i )
      BG_CreateXAnim(s_dogAnims, i, s_dogAnimNames[i]);
    XAnimBlend(s_dogAnims, 0x26u, s_dogAnimNamesRunStartKnob[0], 0x2Du, 1u, 2u);
    BG_CreateXAnim(s_dogAnims, 0x2Du, s_dogAnimNamesRunStartKnob[1]);
    XAnimBlend(s_dogAnims, 0x27u, s_dogAnimNamesRunKnob[0], 0x2Eu, 6u, 1u);
    for ( j = 1; j < 7; ++j )
      BG_CreateXAnim(s_dogAnims, j + 45, s_dogAnimNamesRunKnob[j]);
    XAnimBlend(s_dogAnims, 0x28u, s_dogAnimNamesAttackIdleKnob[0], 0x34u, 3u, 0);
    for ( k = 1; k < 4; ++k )
      BG_CreateXAnim(s_dogAnims, k + 51, s_dogAnimNamesAttackIdleKnob[k]);
    XAnimBlend(s_dogAnims, 0x29u, s_dogAnimNamesLookDown[0], 0x37u, 2u, 0x10u);
    for ( m = 1; m < 3; ++m )
      BG_CreateXAnim(s_dogAnims, m + 54, s_dogAnimNamesLookDown[m]);
    XAnimBlend(s_dogAnims, 0x2Au, s_dogAnimNamesLookUp[0], 0x39u, 2u, 0x10u);
    for ( n = 1; n < 3; ++n )
      BG_CreateXAnim(s_dogAnims, n + 56, s_dogAnimNamesLookUp[n]);
    XAnimBlend(s_dogAnims, 0x2Bu, s_dogAnimNamesLookRight[0], 0x3Bu, 2u, 0x10u);
    for ( ii = 1; ii < 3; ++ii )
      BG_CreateXAnim(s_dogAnims, ii + 58, s_dogAnimNamesLookRight[ii]);
    XAnimBlend(s_dogAnims, 0x2Cu, s_dogAnimNamesLookLeft[0], 0x3Du, 2u, 0x10u);
    for ( jj = 1; jj < 3; ++jj )
      BG_CreateXAnim(s_dogAnims, jj + 60, s_dogAnimNamesLookLeft[jj]);
    XAnimSetupSyncNodes(s_dogAnims);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdauthservice.cpp:0x9343D0
void __cdecl Dog_ShutdownAnims()
{
  s_dogAnims = 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdauthservice.cpp:0x9343E0
void __usercall BG_Dog_GetRunAnimWeights(float *left@<edi>, float *right@<esi>, float leanAmount, float *center)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4

  v4 = leanAmount;
  if ( (LODWORD(leanAmount) & 0x7F800000) == 2139095040 )
  {
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_actor_dog_animations_mp.cpp",
            723,
            0,
            "(!IS_NAN(leanAmount))",
            (const char *)&pBlock) )
      __debugbreak();
    v4 = leanAmount;
  }
  if ( v4 <= 0.0 )
  {
    if ( v4 < 0.0 && v4 > -0.94999999 )
    {
      v4 = FLOAT_N0_94999999;
      goto LABEL_18;
    }
  }
  else if ( v4 < 0.94999999 )
  {
    v4 = FLOAT_0_94999999;
    goto LABEL_12;
  }
  if ( v4 > 0.0 )
  {
LABEL_12:
    v5 = (float)(1.0 - v4) * 20.0;
    *left = 0.0;
    *right = v5;
    if ( v5 <= 1.0 )
    {
      if ( v5 < 0.0 )
        *right = 0.0;
      *center = 1.0 - *right;
    }
    else
    {
      *(_DWORD *)right = FLOAT_1_0;
      *center = 1.0 - 1.0;
    }
    return;
  }
  if ( v4 >= 0.0 )
  {
    *left = 0.0;
    *right = 0.0;
    *(_DWORD *)center = FLOAT_1_0;
    return;
  }
LABEL_18:
  v6 = (float)(v4 + 1.0) * 20.0;
  *right = 0.0;
  *left = v6;
  if ( v6 <= 1.0 )
  {
    if ( v6 < 0.0 )
      *left = 0.0;
    *center = 1.0 - *left;
  }
  else
  {
    *(_DWORD *)left = FLOAT_1_0;
    *center = 1.0 - 1.0;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdauthservice.cpp:0x934510
void __cdecl BG_Dog_Look_At(LocalClientNum_t localClientNum, const entityState_s *es)
{
  DObj *v2; // eax
  DObj *v3; // esi
  float fAimUpDown; // xmm1_4
  float goalWeight; // xmm2_4
  float fAimLeftRight; // xmm1_4
  float rightWeight; // [esp+24h] [ebp-Ch]
  float leftWeight; // [esp+28h] [ebp-8h]
  float downWeight; // [esp+2Ch] [ebp-4h]

  v2 = (DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                       + _tls_index)
                                                                     + 14960)
                                                         + 120))(
                 es->number,
                 localClientNum);
  v3 = v2;
  if ( v2 )
  {
    fAimUpDown = es->un2.animState.fAimUpDown;
    goalWeight = 0.0;
    downWeight = 0.0;
    leftWeight = 0.0;
    rightWeight = 0.0;
    if ( fAimUpDown <= 0.0 )
      downWeight = fAimUpDown * -1.0;
    else
      goalWeight = es->un2.animState.fAimUpDown;
    fAimLeftRight = es->un2.animState.fAimLeftRight;
    if ( fAimLeftRight <= 0.0 )
      rightWeight = fAimLeftRight * -1.0;
    else
      leftWeight = es->un2.animState.fAimLeftRight;
    XAnimSetGoalWeight(v2, 0x2Au, goalWeight, 0.050000001, s_animRate, 0, 0, 0, -1);
    XAnimSetGoalWeight(v3, 0x29u, downWeight, 0.050000001, s_animRate, 0, 0, 0, -1);
    XAnimSetGoalWeight(v3, 0x2Cu, leftWeight, 0.050000001, s_animRate, 0, 0, 0, -1);
    XAnimSetGoalWeight(v3, 0x2Bu, rightWeight, 0.050000001, s_animRate, 0, 0, 0, -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdauthservice.cpp:0x934870
void __usercall BG_Dog_Init_Attack_Look_At(const entityState_s *es@<edi>, LocalClientNum_t localClientNum)
{
  DObj *v2; // esi

  v2 = (DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                       + _tls_index)
                                                                     + 14960)
                                                         + 120))(
                 es->number,
                 localClientNum);
  if ( v2 )
  {
    BG_Dog_Clear_Look_At(localClientNum, es);
    XAnimSetGoalWeight(v2, 0x3Au, 1.0, 0.0, s_animRate, 0, 0, 0, -1);
    XAnimSetGoalWeight(v2, 0x38u, 1.0, 0.0, s_animRate, 0, 0, 0, -1);
    XAnimSetGoalWeight(v2, 0x3Eu, 1.0, 0.0, s_animRate, 0, 0, 0, -1);
    XAnimSetGoalWeight(v2, 0x3Cu, 1.0, 0.0, s_animRate, 0, 0, 0, -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdauthservice.cpp:0x9349A0
void __cdecl BG_Dog_Move_Start(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax

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
    v6 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v6, 3u, 0.0, -1);
    XAnimSetCompleteGoalWeight(v4, 0x2Du, 1.0, 0.2, 1.0, 0, 0, 1, -1);
    XAnimSetCompleteGoalWeightKnob(
      v4,
      0x26u,
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

// bdauthservice.cpp:0x934AB0
void __cdecl BG_Dog_Move_Stop(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax

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
    XAnimClearTreeGoalWeights(Tree, 0x2Du, 0.0, -1);
    v6 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v6, 0x27u, 0.2, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      3u,
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

// bdauthservice.cpp:0x934B90
void __cdecl BG_Dog_Move_Run_Think(LocalClientNum_t localClientNum, const entityState_s *es)
{
  DObj *v2; // ebx
  XAnimTree_s *Tree; // eax
  float right; // [esp+24h] [ebp-Ch] BYREF
  float left; // [esp+28h] [ebp-8h] BYREF
  float center; // [esp+2Ch] [ebp-4h] BYREF

  v2 = (DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                       + _tls_index)
                                                                     + 14960)
                                                         + 120))(
                 es->number,
                 localClientNum);
  if ( v2 )
  {
    center = 0.0;
    left = 0.0;
    right = 0.0;
    BG_Dog_GetRunAnimWeights(&left, &right, es->un2.animState.fLeanAmount, &center);
    Tree = DObjGetTree(v2);
    XAnimClearTreeGoalWeights(Tree, 2u, 0.30000001, -1);
    if ( Com_SessionMode_IsZombiesGame() || !Dvar_GetBool(bg_dog_swim_enabled) )
    {
      XAnimSetCompleteGoalWeight(v2, 0x2Eu, center, 0.2, 1.0, 0, 0, 0, -1);
      XAnimSetCompleteGoalWeight(v2, 0x2Fu, left, 0.2, 1.0, 0, 0, 0, -1);
      XAnimSetCompleteGoalWeight(v2, 0x30u, right, 0.2, 1.0, 0, 0, 0, -1);
    }
    XAnimSetCompleteGoalWeightKnob(
      v2,
      0x27u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960) + 602012),
      2u,
      0,
      -1);
    BG_Dog_Clear_Look_At(localClientNum, es);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdauthservice.cpp:0x934D70
void __cdecl BG_Dog_Move_Walk_Think(LocalClientNum_t localClientNum, const entityState_s *es)
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
    XAnimClearTreeGoalWeights(Tree, 0x27u, 0.30000001, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      2u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960) + 602012),
      2u,
      0,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdauthservice.cpp:0x934E20
void __usercall BG_Dog_Clear_All_Turns(DObj *obj@<esi>)
{
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v2; // eax
  XAnimTree_s *v3; // eax
  XAnimTree_s *v4; // eax
  XAnimTree_s *v5; // eax
  XAnimTree_s *v6; // eax
  XAnimTree_s *v7; // eax
  XAnimTree_s *v8; // eax

  Tree = DObjGetTree(obj);
  XAnimClearTreeGoalWeights(Tree, 8u, 0.0, -1);
  v2 = DObjGetTree(obj);
  XAnimClearTreeGoalWeights(v2, 9u, 0.0, -1);
  v3 = DObjGetTree(obj);
  XAnimClearTreeGoalWeights(v3, 6u, 0.0, -1);
  v4 = DObjGetTree(obj);
  XAnimClearTreeGoalWeights(v4, 7u, 0.0, -1);
  v5 = DObjGetTree(obj);
  XAnimClearTreeGoalWeights(v5, 0xCu, 0.0, -1);
  v6 = DObjGetTree(obj);
  XAnimClearTreeGoalWeights(v6, 0xDu, 0.0, -1);
  v7 = DObjGetTree(obj);
  XAnimClearTreeGoalWeights(v7, 0xAu, 0.0, -1);
  v8 = DObjGetTree(obj);
  XAnimClearTreeGoalWeights(v8, 0xBu, 0.0, -1);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdauthservice.cpp:0x934F20
void __cdecl BG_Dog_Move_Turn_Left(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax

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
    v6 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v6, 3u, 0.2, -1);
    BG_Dog_Clear_All_Turns(v4);
    XAnimSetCompleteGoalWeight(
      v4,
      8u,
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

// bdauthservice.cpp:0x935000
void __cdecl BG_Dog_Move_Turn_Right(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax

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
    v6 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v6, 3u, 0.2, -1);
    BG_Dog_Clear_All_Turns(v4);
    XAnimSetCompleteGoalWeight(
      v4,
      9u,
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

// bdauthservice.cpp:0x9350E0
void __cdecl BG_Dog_Move_Run_Turn_Left(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax

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
    v6 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v6, 3u, 0.2, -1);
    BG_Dog_Clear_All_Turns(v4);
    XAnimSetCompleteGoalWeight(
      v4,
      6u,
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

// bdauthservice.cpp:0x9351C0
void __cdecl BG_Dog_Move_Run_Turn_Right(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax

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
    v6 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v6, 3u, 0.2, -1);
    BG_Dog_Clear_All_Turns(v4);
    XAnimSetCompleteGoalWeight(
      v4,
      7u,
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

// bdauthservice.cpp:0x9352A0
void __cdecl BG_Dog_Move_Turn_Around_Left(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax

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
    v6 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v6, 3u, 0.2, -1);
    BG_Dog_Clear_All_Turns(v4);
    XAnimSetCompleteGoalWeight(
      v4,
      0xCu,
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

// bdauthservice.cpp:0x935380
void __cdecl BG_Dog_Move_Turn_Around_Right(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax

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
    v6 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v6, 3u, 0.2, -1);
    BG_Dog_Clear_All_Turns(v4);
    XAnimSetCompleteGoalWeight(
      v4,
      0xDu,
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

// bdauthservice.cpp:0x935460
void __cdecl BG_Dog_Move_Run_Turn_Around_Left(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax

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
    v6 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v6, 3u, 0.2, -1);
    BG_Dog_Clear_All_Turns(v4);
    XAnimSetCompleteGoalWeight(
      v4,
      0xAu,
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

// bdauthservice.cpp:0x935540
void __cdecl BG_Dog_Move_Run_Turn_Around_Right(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax

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
    v6 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v6, 3u, 0.2, -1);
    BG_Dog_Clear_All_Turns(v4);
    XAnimSetCompleteGoalWeight(
      v4,
      0xBu,
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

// bdauthservice.cpp:0x935620
void __usercall BG_Dog_Stop_Init(const entityState_s *es@<eax>, LocalClientNum_t localClientNum)
{
  const DObj *v3; // eax
  const DObj *v4; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax
  XAnimTree_s *v7; // eax

  v3 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v4 = v3;
  if ( v3 )
  {
    Tree = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(Tree, 0, 0.2, -1);
    v6 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v6, 1u, 0.2, -1);
    v7 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v7, 0x28u, 0.2, -1);
    BG_Dog_Init_Attack_Look_At(es, localClientNum);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdauthservice.cpp:0x9356D0
void __cdecl BG_Dog_Stop_Idle(LocalClientNum_t localClientNum, const entityState_s *es, ActorAnimStates prevState)
{
  unsigned int v3; // edi
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax

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
    XAnimClearTreeGoalWeights(Tree, 0x28u, 0.2, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      1u,
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
