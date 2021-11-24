// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdgroup.cpp:0x939E70
Weapon __cdecl BG_GetPlayerStateWeapon(const pmove_t *pm)
{
  playerState_s *ps; // ecx
  Weapon v2; // ebx

  ps = pm->ps;
  if ( (pm->ps->weapFlags & 2) != 0 )
  {
    v2.0 = ($190F2CF944EC18EE3AF27F473C4F9DBE)ps->offHandWeapon;
    if ( (!v2.weaponData || !*(_BYTE *)&v2.0)
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
            3734,
            0,
            "(!isWeaponNone( weapon ))",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    return v2;
  }
  else
  {
    return ps->weapon;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdgroup.cpp:0x939ED0
Weapon __cdecl BG_GetNextPlayerStateWeapon(const pmove_t *pm)
{
  Weapon result; // eax

  if ( (pm->ps->weapFlags & 2) == 0 )
    return pm->cmd.weapon;
  result.0 = ($190F2CF944EC18EE3AF27F473C4F9DBE)pm->cmd.offHandWeapon;
  if ( !result.weaponData || !*(_BYTE *)&result.0 )
    return pm->cmd.weapon;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdgroup.cpp:0x939F00
void __cdecl BG_AnimUpdatePlayerStateConditions(pmove_t *pmove)
{
  void (__cdecl **v1)(pmove_t *); // esi

  v1 = localClientConditionUpdateFunc;
  do
    (*v1++)(pmove);
  while ( (int)v1 < (int)&unk_10DEBFC );
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdgroup.cpp:0x939F30
int __cdecl BG_IsCrouchingAnim(const clientInfo_t *ci, int animNum)
{
  unsigned int v2; // edi

  v2 = _tls_index;
  if ( (animNum & 0xFFFFFBFF) >= *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                           + _tls_index)
                                                         + 14960)
                                           + 122880) )
    Com_Error(ERR_DROP, &byte_CE1128);
  return (unsigned __int8)(*(_BYTE *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960)
                                    + 120 * (animNum & 0xFFFFFBFF)
                                    + 104) & 2) >> 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdgroup.cpp:0x939F90
int __cdecl BG_IsProneAnim(const clientInfo_t *ci, int animNum)
{
  unsigned int v2; // edi

  v2 = _tls_index;
  if ( (animNum & 0xFFFFFBFF) >= *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                           + _tls_index)
                                                         + 14960)
                                           + 122880) )
    Com_Error(ERR_DROP, &byte_CE1128);
  return (unsigned __int8)(*(_BYTE *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960)
                                    + 120 * (animNum & 0xFFFFFBFF)
                                    + 104) & 4) >> 2;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdgroup.cpp:0x939FF0
int __cdecl BG_IsKnifeMeleeAnim(const clientInfo_t *ci, int animNum)
{
  unsigned int v2; // edi

  v2 = _tls_index;
  if ( (animNum & 0xFFFFFBFF) >= *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                           + _tls_index)
                                                         + 14960)
                                           + 122880) )
    Com_Error(ERR_DROP, &byte_CE1128);
  return (*(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960)
                    + 120 * (animNum & 0xFFFFFBFF)
                    + 92) >> 10) & 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdgroup.cpp:0x93A050
BOOL __cdecl BG_IsSliding(const clientInfo_t *ci)
{
  return LODWORD(ci->moveType) == 26;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdgroup.cpp:0x93A070
void __usercall BG_SetNewAnimation(
        lerpFrame_t *lf@<ecx>,
        int newAnimation@<eax>,
        int a3@<edi>,
        LocalClientNum_t localClientNum,
        clientInfo_t *ci,
        const entityState_s *es)
{
  unsigned int v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // edi
  int v11; // ecx
  int initialLerp; // ecx
  int v13; // eax
  int *p_animationTime; // ebx
  BOOL v15; // eax
  int v16; // edx
  unsigned int v17; // esi
  int v18; // ecx
  float v19; // xmm0_4
  int v20; // esi
  float goalTime; // xmm1_4
  int bNew; // [esp+28h] [ebp-34h]
  int crouchMatch; // [esp+2Ch] [ebp-30h]
  int IsCrouchingAnim; // [esp+30h] [ebp-2Ch]
  int IsProneAnim; // [esp+30h] [ebp-2Ch]
  float fStartTime; // [esp+34h] [ebp-28h]
  animation_s *animation; // [esp+38h] [ebp-24h]
  int firstAnim; // [esp+3Ch] [ebp-20h]
  int oldAnimNum; // [esp+40h] [ebp-1Ch]
  XAnim_s *pXAnims; // [esp+44h] [ebp-18h]
  DObj *obj; // [esp+48h] [ebp-14h]
  XAnimTree_s *pAnimTree; // [esp+4Ch] [ebp-10h]
  int bLegsAnim; // [esp+50h] [ebp-Ch]
  int transitionMin; // [esp+54h] [ebp-8h]
  animation_s *anim; // [esp+58h] [ebp-4h]

  transitionMin = -1;
  firstAnim = 0;
  fStartTime = 0.0;
  BG_CheckThread();
  v8 = _tls_index;
  if ( !*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp", 3926, 0, "(bgs)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  obj = (DObj *)(*(int (__stdcall **)(int, LocalClientNum_t, int))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                               + v8)
                                                                             + 14960)
                                                                 + 120))(
                  es->number,
                  localClientNum,
                  a3);
  if ( obj )
  {
    oldAnimNum = lf->animationNumber;
    bNew = ((unsigned int)es->lerp.eFlags >> 4) & 1;
    animation = lf->animation;
    bLegsAnim = lf == &ci->legs;
    if ( !animation )
      firstAnim = 1;
    lf->animationNumber = newAnimation;
    v9 = *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960) + 122880);
    v10 = newAnimation & 0xFFFFFBFF;
    if ( v10 >= v9 )
      Com_Error(ERR_DROP, &byte_CE1178, v9, v10);
    pAnimTree = ci->pXAnimTree;
    v11 = **(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960);
    pXAnims = *(XAnim_s **)(v11 + 601960);
    if ( v10 )
    {
      anim = (animation_s *)(120 * v10 + v11);
      lf->animation = anim;
      initialLerp = anim->initialLerp;
      if ( initialLerp >= 0
        || (v13 = *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960)
                            + 120 * v10
                            + 68),
            v13 < 0) )
      {
        p_animationTime = &lf->animationTime;
        lf->animationTime = initialLerp;
      }
      else
      {
        p_animationTime = &lf->animationTime;
        lf->animationTime = v13;
      }
      if ( Dvar_GetInt(bg_blendTimeOverride) >= 0 )
        *p_animationTime = Dvar_GetInt(bg_blendTimeOverride);
      IsCrouchingAnim = BG_IsCrouchingAnim(ci, oldAnimNum);
      crouchMatch = BG_IsCrouchingAnim(ci, v10) == IsCrouchingAnim;
      IsProneAnim = BG_IsProneAnim(ci, oldAnimNum);
      v15 = BG_IsProneAnim(ci, v10) == IsProneAnim;
      if ( lf == &ci->legs && (!crouchMatch || !v15) )
        ci->stanceTransitionTime = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                           + _tls_index)
                                                         + 14960)
                                             + 16)
                                 + 400;
    }
    else
    {
      p_animationTime = &lf->animationTime;
      anim = 0;
      lf->animation = 0;
      lf->animationTime = 200;
    }
    if ( firstAnim && lf == &ci->legs || Demo_IsPaused() )
    {
      *p_animationTime = 0;
LABEL_45:
      if ( anim && anim->moveSpeed != 0.0 && XAnimIsLooped(pXAnims, v10) )
      {
        v17 = oldAnimNum & 0xFFFFFBFF;
        if ( animation && animation->moveSpeed != 0.0 && XAnimIsLooped(pXAnims, oldAnimNum & 0xFFFFFBFF) )
        {
          fStartTime = XAnimGetTime(pAnimTree, v17);
        }
        else if ( firstAnim )
        {
          if ( XAnimIsPrimitive(pXAnims, v17) )
            v18 = XAnimGetLengthMsec(pXAnims, v17) + 200;
          else
            v18 = 1000;
          v19 = (float)((float)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                        + _tls_index)
                                                      + 14960)
                                          + 16)
                              % v18)
                      / (float)v18)
              + (float)((float)ci->clientNum * 0.36000001);
          fStartTime = v19 - (float)(int)v19;
        }
      }
      v20 = 0;
      if ( animation )
        XAnimClearTreeGoalWeights(pAnimTree, oldAnimNum & 0xFFFFFBFF, (float)*p_animationTime * 0.001, -1);
      if ( v10 )
      {
        if ( !bLegsAnim && ci->leftHandGun )
        {
          ci->leftHandGun = 0;
          ci->dobjDirty = 1;
        }
        if ( (anim->flags & 0x100) != 0 )
        {
          if ( XAnimIsLooped(pXAnims, v10) )
            Com_Error(ERR_DROP, "death animation '%s' is looping", anim->name);
          if ( bNew || Com_SessionMode_IsZombiesGame() )
          {
            XAnimSetCompleteGoalWeight(obj, v10, 1.0, (float)*p_animationTime * 0.001, 1.0, 0, 0, 0, -1);
          }
          else
          {
            XAnimSetGoalWeightKnobAll(obj, v10, 0, 1.0, 0.0, 1.0, 0, 0, 0, -1);
            XAnimSetTime(pAnimTree, v10, 1.0, -1);
          }
        }
        else
        {
          if ( anim->moveSpeed != 0.0 && XAnimGetWeight(pAnimTree, v10) == 0.0 || firstAnim )
            v20 = 1;
          goalTime = (float)*p_animationTime * 0.001;
          if ( localClientNum >= LOCAL_CLIENT_FIRST )
            XAnimSetCompleteGoalWeight(obj, v10, 1.0, goalTime, 1.0, 0, anim->noteType | 2, bLegsAnim == 0, -1);
          else
            XAnimSetCompleteGoalWeight(obj, v10, 1.0, goalTime, 1.0, 0, anim->noteType, bLegsAnim == 0, -1);
          if ( Demo_IsPaused() && (anim->flags & 0x400) != 0 )
          {
            XAnimSetTime(pAnimTree, v10, 0.1, -1);
          }
          else if ( v20 )
          {
            XAnimSetTime(pAnimTree, v10, fStartTime, -1);
          }
        }
        if ( !bLegsAnim )
        {
          XAnimSetCompleteGoalWeight(
            obj,
            *(unsigned __int16 *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index)
                                              + 14960)
                                + 601968),
            1.0,
            (float)*p_animationTime * 0.001,
            1.0,
            0,
            anim->noteType,
            0,
            -1);
          XAnimSetCompleteGoalWeight(
            obj,
            *(unsigned __int16 *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index)
                                              + 14960)
                                + 601970),
            0.0099999998,
            (float)*p_animationTime * 0.001,
            1.0,
            0,
            anim->noteType,
            0,
            -1);
        }
      }
      else if ( !bLegsAnim )
      {
        XAnimSetCompleteGoalWeight(
          obj,
          *(unsigned __int16 *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
                              + 601968),
          0.0,
          (float)*p_animationTime * 0.001,
          1.0,
          0,
          0,
          0,
          -1);
        XAnimSetCompleteGoalWeight(
          obj,
          *(unsigned __int16 *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
                              + 601970),
          1.0,
          (float)*p_animationTime * 0.001,
          1.0,
          0,
          0,
          0,
          -1);
      }
      return;
    }
    if ( anim )
    {
      if ( *p_animationTime >= 0 )
      {
LABEL_41:
        v16 = *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960);
        if ( ci->stanceTransitionTime - *(_DWORD *)(v16 + 16) > transitionMin )
          transitionMin = ci->stanceTransitionTime - *(_DWORD *)(v16 + 16);
        if ( *p_animationTime < transitionMin )
          *p_animationTime = transitionMin;
        goto LABEL_45;
      }
      if ( (anim->flags & 4) != 0 )
      {
        transitionMin = 0;
        goto LABEL_41;
      }
    }
    if ( animation && ((unsigned int)&g_npPool[24648] & animation->flags) != 0 )
    {
      if ( !anim )
        goto LABEL_38;
      if ( anim->moveSpeed != 0.0 || anim->rotSpeed != 0.0 )
      {
        transitionMin = 267;
        goto LABEL_41;
      }
    }
    if ( anim && anim->moveSpeed != 0.0 )
    {
      transitionMin = 133;
      goto LABEL_41;
    }
LABEL_38:
    if ( !animation || (transitionMin = 267, animation->moveSpeed == 0.0) )
      transitionMin = 167;
    goto LABEL_41;
  }
}

#endif // __UNIMPLEMENTED__
