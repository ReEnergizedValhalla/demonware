// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdvoterank.cpp:0x937000
void __cdecl BG_Dog_Traverse_Window(LocalClientNum_t localClientNum, const entityState_s *es)
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
      0x24u,
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

// bdvoterank.cpp:0x9370B0
void __cdecl BG_Dog_Traverse_Through_Hole_42(LocalClientNum_t localClientNum, const entityState_s *es)
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
    XAnimSetCompleteGoalWeight(v4, 0x2Eu, 1.0, 0.2, 1.0, 0, 0, 0, -1);
    XAnimSetCompleteGoalWeightKnob(
      v4,
      0x27u,
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

// bdvoterank.cpp:0x9371A0
void __cdecl BG_Dog_Move_Run(LocalClientNum_t localClientNum, const entityState_s *es, ActorAnimStates prevState)
{
  const DObj *v3; // eax
  DObj *v4; // ebx
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax
  XAnimTree_s *v7; // eax
  XAnimTree_s *v8; // eax
  XAnimTree_s *v9; // eax
  double Float; // st7
  const entityState_s *v11; // esi
  double WaterHeight; // st7
  float goalWeight; // xmm1_4
  float rightSwim; // [esp+2Ch] [ebp-1Ch]
  float leftSwim; // [esp+30h] [ebp-18h]
  float endHeight; // [esp+34h] [ebp-14h]
  float right; // [esp+38h] [ebp-10h] BYREF
  float left; // [esp+3Ch] [ebp-Ch] BYREF
  float center; // [esp+40h] [ebp-8h] BYREF
  float startHeight; // [esp+44h] [ebp-4h]
  int savedregs; // [esp+48h] [ebp+0h] BYREF

  v3 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v4 = (DObj *)v3;
  if ( v3 )
  {
    if ( prevState != ACTOR_ANIMATION_MOVE_WALK )
    {
      Tree = DObjGetTree(v3);
      XAnimClearTreeGoalWeights(Tree, 0x2Du, 0.0, -1);
      v6 = DObjGetTree(v4);
      XAnimClearTreeGoalWeights(v6, 3u, 0.0, -1);
      v7 = DObjGetTree(v4);
      XAnimClearTreeGoalWeights(v7, 0xAu, 0.2, -1);
      v8 = DObjGetTree(v4);
      XAnimClearTreeGoalWeights(v8, 0xBu, 0.2, -1);
      BG_Dog_Clear_Traverse_Anims(prevState, localClientNum, es);
      BG_Dog_Init_Normal_Look_At(es, localClientNum);
    }
    center = 0.0;
    left = 0.0;
    right = 0.0;
    BG_Dog_GetRunAnimWeights(&left, &right, es->un2.animState.fLeanAmount, &center);
    v9 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v9, 2u, 0.30000001, -1);
    if ( Com_SessionMode_IsZombiesGame() || !Dvar_GetBool(bg_dog_swim_enabled) )
      goto LABEL_14;
    leftSwim = 0.0;
    rightSwim = 0.0;
    startHeight = Dvar_GetFloat(bg_dog_swim_water_min);
    Float = Dvar_GetFloat(bg_dog_swim_water_max);
    endHeight = Float;
    if ( Float > startHeight )
      goto LABEL_10;
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_actor_dog_animations_mp.cpp",
            906,
            0,
            "(startHeight < endHeight)",
            (const char *)&pBlock) )
      __debugbreak();
    if ( endHeight <= startHeight )
    {
LABEL_14:
      v11 = es;
    }
    else
    {
LABEL_10:
      v11 = es;
      WaterHeight = CM_GetWaterHeight((unsigned int)&savedregs, &es->lerp.pos.trBase, endHeight, startHeight);
      if ( WaterHeight <= es->lerp.pos.trBase.z + startHeight )
      {
        goalWeight = 0.0;
      }
      else
      {
        goalWeight = center;
        leftSwim = left;
        rightSwim = right;
        center = 0.0;
        left = 0.0;
        right = 0.0;
      }
      XAnimSetCompleteGoalWeight(v4, 0x31u, goalWeight, 0.2, 1.0, 0, 0, 0, -1);
      XAnimSetCompleteGoalWeight(v4, 0x32u, leftSwim, 0.2, 1.0, 0, 0, 0, -1);
      XAnimSetCompleteGoalWeight(v4, 0x33u, rightSwim, 0.2, 1.0, 0, 0, 0, -1);
    }
    XAnimSetCompleteGoalWeight(v4, 0x2Eu, center, 0.2, 1.0, 0, 0, 0, -1);
    XAnimSetCompleteGoalWeight(v4, 0x2Fu, left, 0.2, 1.0, 0, 0, 0, -1);
    XAnimSetCompleteGoalWeight(v4, 0x30u, right, 0.2, 1.0, 0, 0, 0, -1);
    XAnimSetCompleteGoalWeightKnob(
      v4,
      0x27u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960) + 602012),
      2u,
      0,
      -1);
    BG_Dog_Look_At(localClientNum, v11);
  }
}

#endif // __UNIMPLEMENTED__
