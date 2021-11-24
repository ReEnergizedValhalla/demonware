// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdremotetaskmanager.cpp:0x9360D0
void __cdecl BG_Dog_Death_Front(LocalClientNum_t localClientNum, const entityState_s *es)
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
      0x16u,
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

// bdremotetaskmanager.cpp:0x936180
void __cdecl BG_Dog_Death_Back(LocalClientNum_t localClientNum, const entityState_s *es)
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
      0x17u,
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

// bdremotetaskmanager.cpp:0x936230
void __cdecl BG_Dog_Death_Left(LocalClientNum_t localClientNum, const entityState_s *es)
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
      0x18u,
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

// bdremotetaskmanager.cpp:0x9362E0
void __cdecl BG_Dog_Death_Right(LocalClientNum_t localClientNum, const entityState_s *es)
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
      0x19u,
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

// bdremotetaskmanager.cpp:0x936390
void __cdecl BG_Dog_Death_Fast_Forward_Front(
        LocalClientNum_t localClientNum,
        const entityState_s *es,
        actorInfo_t *actorInfo)
{
  const XAnim_s *Anims; // esi

  Anims = XAnimGetAnims(actorInfo->pXAnimTree);
  if ( !XAnimIsLooped(Anims, 0x16u) && !XAnimGetNumChildren(Anims, 0x16u) )
    XAnimSetTime(actorInfo->pXAnimTree, 0x16u, 1.0, -1);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdremotetaskmanager.cpp:0x9363F0
void __cdecl BG_Dog_Death_Fast_Forward_Back(
        LocalClientNum_t localClientNum,
        const entityState_s *es,
        actorInfo_t *actorInfo)
{
  const XAnim_s *Anims; // esi

  Anims = XAnimGetAnims(actorInfo->pXAnimTree);
  if ( !XAnimIsLooped(Anims, 0x17u) && !XAnimGetNumChildren(Anims, 0x17u) )
    XAnimSetTime(actorInfo->pXAnimTree, 0x17u, 1.0, -1);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdremotetaskmanager.cpp:0x936450
void __cdecl BG_Dog_Death_Fast_Forward_Left(
        LocalClientNum_t localClientNum,
        const entityState_s *es,
        actorInfo_t *actorInfo)
{
  const XAnim_s *Anims; // esi

  Anims = XAnimGetAnims(actorInfo->pXAnimTree);
  if ( !XAnimIsLooped(Anims, 0x18u) && !XAnimGetNumChildren(Anims, 0x18u) )
    XAnimSetTime(actorInfo->pXAnimTree, 0x18u, 1.0, -1);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdremotetaskmanager.cpp:0x9364B0
void __cdecl BG_Dog_Death_Fast_Forward_Right(
        LocalClientNum_t localClientNum,
        const entityState_s *es,
        actorInfo_t *actorInfo)
{
  const XAnim_s *Anims; // esi

  Anims = XAnimGetAnims(actorInfo->pXAnimTree);
  if ( !XAnimIsLooped(Anims, 0x19u) && !XAnimGetNumChildren(Anims, 0x19u) )
    XAnimSetTime(actorInfo->pXAnimTree, 0x19u, 1.0, -1);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdremotetaskmanager.cpp:0x936510
void __cdecl BG_Dog_Flashed(LocalClientNum_t localClientNum, const entityState_s *es)
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
      0x1Au,
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

// bdremotetaskmanager.cpp:0x9365C0
void __cdecl BG_Dog_Combat_AttackIdle(LocalClientNum_t localClientNum, const entityState_s *es)
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
      0x34u,
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

// bdremotetaskmanager.cpp:0x936670
void __cdecl BG_Dog_Combat_AttackIdle_Bark(LocalClientNum_t localClientNum, const entityState_s *es)
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
      0x35u,
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

// bdremotetaskmanager.cpp:0x936720
void __cdecl BG_Dog_Combat_AttackIdle_Growl(LocalClientNum_t localClientNum, const entityState_s *es)
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
      0x36u,
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

// bdremotetaskmanager.cpp:0x9367D0
void __cdecl BG_Dog_Combat_Attack_Run(LocalClientNum_t localClientNum, const entityState_s *es)
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
      5u,
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

// bdremotetaskmanager.cpp:0x936880
void __cdecl BG_Dog_Combat_Attack_Player_Close_Range(LocalClientNum_t localClientNum, const entityState_s *es)
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
    XAnimClearTreeGoalWeights(Tree, 0, 0.1, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0x1Eu,
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

// bdremotetaskmanager.cpp:0x936930
void __cdecl BG_Dog_Combat_Attack_Miss(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // ebx
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
    XAnimClearTreeGoalWeights(Tree, 0, 0.1, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0x1Bu,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960) + 602012),
      2u,
      1,
      -1);
    BG_Dog_Init_Normal_Look_At(es, localClientNum);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdremotetaskmanager.cpp:0x9369F0
void __cdecl BG_Dog_Combat_Attack_Miss_Left(LocalClientNum_t localClientNum, const entityState_s *es)
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
    XAnimClearTreeGoalWeights(Tree, 0, 0.1, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0x1Cu,
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

// bdremotetaskmanager.cpp:0x936AA0
void __cdecl BG_Dog_Combat_Attack_Miss_Right(LocalClientNum_t localClientNum, const entityState_s *es)
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
    XAnimClearTreeGoalWeights(Tree, 0, 0.1, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0x1Du,
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

// bdremotetaskmanager.cpp:0x936B50
void __usercall BG_Dog_Clear_Traverse_Anims(
        ActorAnimStates prevState@<edi>,
        LocalClientNum_t localClientNum,
        const entityState_s *es)
{
  const DObj *v3; // eax
  const DObj *v4; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax
  XAnimTree_s *v7; // eax
  XAnimTree_s *v8; // eax
  XAnimTree_s *v9; // eax
  XAnimTree_s *v10; // eax

  v3 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v4 = v3;
  if ( v3
    && (prevState == ACTOR_ANIMATION_TRAVERSE_JUMP_UP_40
     || prevState == ACTOR_ANIMATION_TRAVERSE_JUMP_UP_80
     || prevState == ACTOR_ANIMATION_TRAVERSE_JUMP_DOWN_40
     || prevState == ACTOR_ANIMATION_TRAVERSE_JUMP_DOWN_80
     || prevState == ACTOR_ANIMATION_TRAVERSE_WALLHOP
     || prevState == ACTOR_ANIMATION_TRAVERSE_WINDOW
     || prevState == ACTOR_ANIMATION_TRAVERSE_THROUGH_HOLE_42) )
  {
    Tree = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(Tree, 0x1Fu, 0.30000001, -1);
    v6 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v6, 0x20u, 0.30000001, -1);
    v7 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v7, 0x21u, 0.30000001, -1);
    v8 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v8, 0x22u, 0.30000001, -1);
    v9 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v9, 0x23u, 0.30000001, -1);
    v10 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v10, 0x24u, 0.30000001, -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdremotetaskmanager.cpp:0x936C90
void __cdecl BG_Dog_Traverse_Jump_Up_40(LocalClientNum_t localClientNum, const entityState_s *es)
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
      0x1Fu,
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

// bdremotetaskmanager.cpp:0x936D40
void __cdecl BG_Dog_Traverse_Jump_Up_80(LocalClientNum_t localClientNum, const entityState_s *es)
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
      0x20u,
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
