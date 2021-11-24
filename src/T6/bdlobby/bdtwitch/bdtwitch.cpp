// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdtwitch.cpp:0x933E50
void __cdecl BG_Actor_FastForwardAnimState(
        LocalClientNum_t localClientNum,
        const entityState_s *es,
        actorInfo_t *actorInfo)
{
  void (__cdecl *v3)(LocalClientNum_t, const entityState_s *, actorInfo_t *); // eax

  v3 = (void (__cdecl *)(LocalClientNum_t, const entityState_s *, actorInfo_t *))dword_CDF68C[4
                                                                                            * (es->un2.animState.state & 0xFFFFFEFF)];
  if ( v3 )
    v3(localClientNum, es, actorInfo);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdtwitch.cpp:0x933E80
void __cdecl BG_Actor_GetAnimState(entityState_s *es, int *animState, int *animSubState)
{
  if ( !es
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_actor.cpp", 296, 0, "(es)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !animState
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_actor.cpp",
          297,
          0,
          "(animState)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !animSubState
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_actor.cpp",
          298,
          0,
          "(animSubState)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  *animState = es->un2.animState.state & 0xFFFFFEFF;
  *animSubState = es->un2.animState.subState;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdtwitch.cpp:0x933F20
void __cdecl BG_Actor_SetAnimState(entityState_s *es, int animState, int animSubState)
{
  es->un2.animState.state = animState | ~es->un2.animState.state & 0x100;
  es->un2.animState.subState = animSubState;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdtwitch.cpp:0x933F50
bool __cdecl BG_Actor_ApplyNewAnimState(XAnimTree_s *pAnimTree, actorLerpFrame_t *lf, int newAnimationState)
{
  return newAnimationState != lf->animationState
      || (newAnimationState & 0xFFFFFEFF) != 0 && (!lf->bAnimating || pAnimTree && !XAnimTreeHasInfo(pAnimTree));
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdtwitch.cpp:0x933F90
void __cdecl BG_Actor_UpdateAnimationState(
        LocalClientNum_t localClientNum,
        const entityState_s *es,
        actorInfo_t *actorInfo)
{
  if ( BG_AnimStateDef_InUse() )
    BG_AnimStateDef_Update(localClientNum, es, actorInfo);
  else
    BG_Dog_UpdateAnimationState(localClientNum, es, actorInfo);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdtwitch.cpp:0x933FB0
XAnim_s *__cdecl BG_Actor_GetAnims()
{
  if ( Com_SessionMode_IsZombiesGame() )
    return 0;
  else
    return Dog_GetAnims();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdtwitch.cpp:0x933FD0
void __cdecl BG_Actor_CreateAnims(void *(__cdecl *xanimAlloc)(int))
{
  if ( !Com_SessionMode_IsZombiesGame() )
    Dog_CreateAnims(xanimAlloc);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdtwitch.cpp:0x933FF0
void __cdecl BG_Actor_ShutdownAnims()
{
  if ( BG_AnimStateDef_InUse() )
    BG_AnimStateDef_Shutdown();
  else
    Dog_ShutdownAnims();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdtwitch.cpp:0x934010
void __usercall BG_Dog_SetNewAnimationState(
        actorLerpFrame_t *lf@<esi>,
        int newAnimationState@<edi>,
        LocalClientNum_t localClientNum,
        animInfo_t *animInfo)
{
  void (__cdecl *pfnStart)(LocalClientNum_t, const entityState_s *, ActorAnimStates); // eax

  BG_CheckThread();
  if ( !*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_actor_dog.cpp", 26, 0, "(bgs)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  pfnStart = AIDogAnimationFuncTable[newAnimationState & 0xFFFFFEFF].pfnStart;
  if ( pfnStart )
  {
    pfnStart(localClientNum, (const entityState_s *)animInfo, (ActorAnimStates)(lf->animationState & 0xFFFFFEFF));
    lf->bAnimating = 1;
    lf->animationState = newAnimationState;
  }
}

#endif // __UNIMPLEMENTED__
