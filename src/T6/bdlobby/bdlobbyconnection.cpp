// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdlobbyconnection.cpp:0x93E210
const char *__cdecl BG_GetCurrentMoveStatus(playerState_s *ps)
{
  return animMoveStatusStr[GetValueForBitfield(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                       + _tls_index)
                                                                     + 14960)
                                                         + 2056 * ps->clientNum
                                                         + 1544))].string;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyconnection.cpp:0x93E250
int __cdecl BG_PlayAnim(
        playerState_s *ps,
        int animNum,
        animBodyPart_t bodyPart,
        int forceDuration,
        int setTimer,
        int isContinue,
        int force)
{
  int v7; // ebx
  unsigned int v8; // edi
  float v9; // xmm0_4
  int Int; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  bgs_t *v17; // ecx
  const char *v18; // eax
  const char *CurrentMoveStatus; // eax
  Weapon v20; // eax
  const WeaponVariantDef *WeaponVariantDef; // eax
  Weapon v22; // eax
  const WeaponDef *WeaponDef; // eax
  Weapon v24; // eax
  const WeaponDef *v25; // eax
  const char *PlayerAnimTypeName; // eax
  int v27; // ecx
  int v28; // eax
  bgs_t *v29; // ecx
  const char *v30; // eax
  const char *v31; // eax
  Weapon v32; // eax
  const WeaponVariantDef *v33; // eax
  Weapon v34; // eax
  const WeaponDef *v35; // eax
  Weapon v36; // eax
  const WeaponDef *v37; // eax
  const char *v38; // eax
  int wasSet; // [esp+14h] [ebp-Ch]
  int v41; // [esp+1Ch] [ebp-4h]
  int duration; // [esp+2Ch] [ebp+Ch]
  const char *bodyParta; // [esp+30h] [ebp+10h]
  const char *forceDurationa; // [esp+34h] [ebp+14h]

  v7 = animNum;
  v8 = _tls_index;
  v9 = *(float *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
                + 120 * animNum
                + 72);
  wasSet = 0;
  v41 = 120 * animNum;
  if ( v9 <= 0.0 )
    v9 = *(float *)&FLOAT_1_0;
  if ( Dvar_GetInt(bg_forceDurationOverride) <= 0 )
    Int = forceDuration;
  else
    Int = Dvar_GetInt(bg_forceDurationOverride);
  if ( Int )
    v11 = (int)(float)((float)Int / v9);
  else
    v11 = (int)(float)((float)*(int *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960)
                                     + 120 * animNum
                                     + 84)
                     / v9)
        + 50;
  duration = v11;
  if ( bodyPart != ANIM_BP_LEGS )
  {
    if ( bodyPart == ANIM_BP_TORSO )
      goto LABEL_60;
    if ( bodyPart != ANIM_BP_BOTH )
      return -1;
  }
  if ( !force && (ps->legsAnim & 0xFFFFFBFF) != v7 )
  {
    if ( Dvar_GetBool(bg_forceAnimOverrideTimerCheck) && ps->legsTimer >= 50 )
      goto LABEL_31;
    if ( ps->legsAnim < 0
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
            3186,
            0,
            "((ps->legsAnim & ~(1<<(11-1))) >= 0)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( (ps->legsAnim & 0xFFFFFBFF) >= *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                  + v8)
                                                                + 14960)
                                                  + 122880)
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
            3187,
            0,
            "((uint)(ps->legsAnim & ~(1<<(11-1))) < bgs->animData->animScriptData.numAnimations)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v12 = **(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960);
    if ( ((unsigned int)&g_npPool[24648] & *(_DWORD *)(v12 + 120 * (ps->legsAnim & 0xFFFFFBFF) + 92)) != 0
      && (*(float *)(v12 + v41 + 76) != 0.0 || *(float *)(v12 + v41 + 80) != 0.0) )
    {
      v13 = Dvar_GetInt(bg_playerAnimStanceAllowMovementInteruptTime);
      if ( !v13 )
        goto LABEL_29;
      v14 = ps->legsAnimDuration - v13;
      if ( v14 < 50 )
        v14 = 50;
      if ( ps->legsTimer < v14 )
LABEL_29:
        force = 1;
    }
  }
  if ( ps->legsTimer < 50 )
  {
LABEL_32:
    if ( isContinue && (ps->legsAnim & 0xFFFFFBFF) == v7 )
    {
      if ( setTimer
        && (*(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960) + v41 + 92) & 0x200) != 0 )
      {
        ps->legsTimer = duration;
      }
      else if ( Dvar_GetBool(xanim_debug) && (ps->legsAnim & 0xFFFFFBFF) != v7 )
      {
        Com_Printf(18, "anim failed because");
        if ( (ps->legsAnim & 0xFFFFFBFF) == v7 )
        {
          Com_Printf(18, ", isContinue is true");
          v15 = **(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960);
          Com_Printf(
            18,
            ", legsAnim is %s, asking to play %s",
            (const char *)(v15 + 120 * ps->legsAnim),
            (const char *)(v15 + v41));
        }
        if ( setTimer )
        {
          if ( (*(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960) + v41 + 92) & 0x200) == 0 )
            Com_Printf(18, ", on a non-looped anim");
        }
        else
        {
          Com_Printf(18, ", setTimer is false");
        }
        Com_Printf(18, "\n");
      }
    }
    else
    {
      ps->legsAnimDuration = duration;
      wasSet = 1;
      v16 = v7 | ~ps->legsAnim & 0x400;
      ps->legsAnim = v16;
      if ( (__int16)v16 != v16
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\../universal/q_shared.h",
              329,
              0,
              "((int) dest == src)",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      if ( setTimer )
        ps->legsTimer = duration;
      if ( Dvar_GetBool(xanim_debug) )
      {
        if ( bodyPart == ANIM_BP_BOTH )
          forceDurationa = "body";
        else
          forceDurationa = "legs";
        v17 = *(bgs_t **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960);
        v18 = "SV";
        if ( v17 != &level_bgs )
          v18 = "CL";
        Com_Printf(
          18,
          "\n[%s]%i: Playing (client %i) %s on %s (animNum=%d, isContinue=%i, force=%i, setTimer=%i, legsTimer=%i)\n",
          v18,
          ps->commandTime,
          ps->clientNum,
          (const char *)v17->animData + v41,
          forceDurationa,
          v7,
          isContinue,
          force,
          setTimer,
          ps->legsTimer);
        CurrentMoveStatus = BG_GetCurrentMoveStatus(ps);
        Com_Printf(18, "     MoveStatus: %s\n", CurrentMoveStatus);
        v20.0 = BG_GetViewmodelWeaponIndex(ps).0;
        WeaponVariantDef = BG_GetWeaponVariantDef(v20);
        Com_Printf(18, "     WeaponName: %s\n", WeaponVariantDef->szInternalName);
        v22.0 = BG_GetViewmodelWeaponIndex(ps).0;
        WeaponDef = BG_GetWeaponDef(v22);
        Com_Printf(18, "     WeaponClass: %s\n", animWeaponClassStr[WeaponDef->weapClass].string);
        v24.0 = BG_GetViewmodelWeaponIndex(ps).0;
        v25 = BG_GetWeaponDef(v24);
        PlayerAnimTypeName = BG_GetPlayerAnimTypeName(v25->playerAnimType);
        Com_Printf(18, "     PlayerAnimType: %s\n", PlayerAnimTypeName);
        Com_Printf(
          18,
          "     Stance: %s\n",
          animStanceStr[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960)
                                  + 2056 * ps->clientNum
                                  + 1564)].string);
        Com_Printf(
          18,
          "     Prev Direction: %s\n",
          animPrevDirectionStr[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8)
                                                     + 14960)
                                         + 2056 * ps->clientNum
                                         + 1548)].string);
        Com_Printf(
          18,
          "     Direction: %s\n",
          animDirectionStr[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960)
                                     + 2056 * ps->clientNum
                                     + 1552)].string);
        Com_Printf(
          18,
          "     DmgDirection: %s\n",
          animDmgDirectionStr[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960)
                                        + 2056 * ps->clientNum
                                        + 1556)].string);
        Com_Printf(
          18,
          "     DmgType: %s\n",
          animDmgTypeStr[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960)
                                   + 2056 * ps->clientNum
                                   + 1560)].string);
        Com_Printf(
          18,
          "     Slope: %s\n",
          animSlopeStateStr[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960)
                                      + 2056 * ps->clientNum
                                      + 1580)].string);
        Com_Printf(18, "     Playback Rate: %.2f\n", v9);
      }
    }
    goto LABEL_58;
  }
LABEL_31:
  if ( force )
    goto LABEL_32;
LABEL_58:
  if ( bodyPart != ANIM_BP_BOTH )
    goto LABEL_93;
  v7 = 0;
LABEL_60:
  if ( !force && (ps->torsoAnim & 0xFFFFFBFF) != v7 )
  {
    if ( Dvar_GetBool(bg_forceAnimOverrideTimerCheck) && ps->torsoTimer >= 50 )
    {
LABEL_75:
      if ( !force )
        goto LABEL_93;
      goto LABEL_76;
    }
    if ( ps->torsoAnim < 0
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
            3275,
            0,
            "((ps->torsoAnim & ~(1<<(11-1))) >= 0)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( (ps->torsoAnim & 0xFFFFFBFF) >= *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                   + v8)
                                                                 + 14960)
                                                   + 122880)
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
            3276,
            0,
            "((uint)(ps->torsoAnim & ~(1<<(11-1))) < bgs->animData->animScriptData.numAnimations)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( bodyPart == ANIM_BP_TORSO )
    {
      v27 = **(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960);
      if ( (*(_DWORD *)(v27 + 120 * (ps->torsoAnim & 0xFFFFFBFF) + 92) & 0x10000000) != 0
        && (*(_DWORD *)(v27 + 120 * v7 + 92) & 0x20000000) != 0 )
      {
        force = 1;
      }
    }
  }
  if ( ps->torsoTimer >= 50 )
    goto LABEL_75;
LABEL_76:
  if ( isContinue && (ps->torsoAnim & 0xFFFFFBFF) == v7 )
  {
    if ( setTimer )
    {
      if ( (*(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960)
                      + 120 * v7
                      + 92) & 0x200) != 0 )
        ps->torsoTimer = duration;
    }
  }
  else
  {
    v28 = v7 | ~ps->torsoAnim & 0x400;
    ps->torsoAnim = v28;
    if ( (__int16)v28 != v28
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\../universal/q_shared.h",
            329,
            0,
            "((int) dest == src)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( setTimer )
      ps->torsoTimer = duration;
    ps->torsoAnimDuration = duration;
    if ( Dvar_GetBool(xanim_debug) )
    {
      if ( bodyPart == ANIM_BP_BOTH )
        bodyParta = "body";
      else
        bodyParta = "torso";
      v29 = *(bgs_t **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960);
      v30 = "SV";
      if ( v29 != &level_bgs )
        v30 = "CL";
      Com_Printf(
        18,
        "\n[%s]%i: Playing (client %i) %s on %s (animNum=%d, isContinue=%i, force=%i, setTimer=%i, torsoTimer=%i)\n",
        v30,
        ps->commandTime,
        ps->clientNum,
        v29->animData->animScriptData.animations[v7].name,
        bodyParta,
        v7,
        isContinue,
        force,
        setTimer,
        ps->torsoTimer);
      v31 = BG_GetCurrentMoveStatus(ps);
      Com_Printf(18, "     MoveStatus: %s\n", v31);
      v32.0 = BG_GetViewmodelWeaponIndex(ps).0;
      v33 = BG_GetWeaponVariantDef(v32);
      Com_Printf(18, "     WeaponName: %s\n", v33->szInternalName);
      v34.0 = BG_GetViewmodelWeaponIndex(ps).0;
      v35 = BG_GetWeaponDef(v34);
      Com_Printf(18, "     WeaponClass: %s\n", animWeaponClassStr[v35->weapClass].string);
      v36.0 = BG_GetViewmodelWeaponIndex(ps).0;
      v37 = BG_GetWeaponDef(v36);
      v38 = BG_GetPlayerAnimTypeName(v37->playerAnimType);
      Com_Printf(18, "     PlayerAnimType: %s\n", v38);
      Com_Printf(
        18,
        "     Stance: %s\n",
        animStanceStr[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960)
                                + 2056 * ps->clientNum
                                + 1564)].string);
      Com_Printf(
        18,
        "     Direction: %s\n",
        animDirectionStr[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960)
                                   + 2056 * ps->clientNum
                                   + 1552)].string);
      Com_Printf(
        18,
        "     DmgDirection: %s\n",
        animDmgDirectionStr[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960)
                                      + 2056 * ps->clientNum
                                      + 1556)].string);
      Com_Printf(
        18,
        "     DmgType: %s\n",
        animDmgTypeStr[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960)
                                 + 2056 * ps->clientNum
                                 + 1560)].string);
      Com_Printf(
        18,
        "     Slope: %s\n",
        animSlopeStateStr[*(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960)
                                    + 2056 * ps->clientNum
                                    + 1580)].string);
      Com_Printf(18, "     Playback Rate: %.2f\n", v9);
    }
  }
LABEL_93:
  if ( !wasSet )
    return -1;
  return duration;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyconnection.cpp:0x93ECB0
int __cdecl BG_ExecuteCommand(
        playerState_s *ps,
        animScriptCommand_t *scriptCommand,
        int setTimer,
        int isContinue,
        int force)
{
  int v5; // esi
  __int16 v6; // ax
  int v7; // ecx
  int v8; // edx
  bool v9; // zf
  int v10; // edx
  int v11; // esi
  __int16 v12; // cx
  _DWORD *v13; // edx
  int v14; // esi
  SndAliasList *soundAlias; // edi
  int playedLegsAnim; // [esp+4h] [ebp-4h]

  v5 = -1;
  playedLegsAnim = 0;
  if ( Demo_IsPlaying() )
    return -1;
  v6 = scriptCommand->bodyPart[0];
  if ( scriptCommand->bodyPart[0] )
  {
    v7 = scriptCommand->animIndex[0];
    v8 = **(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960);
    v9 = (*(_DWORD *)(v8 + 120 * v7 + 92) & 0x1000) == 0;
    v10 = v8 + 120 * v7;
    if ( v9 )
      v11 = scriptCommand->animDuration[0];
    else
      v11 = *(_DWORD *)(v10 + 84);
    v5 = v11 + 50;
    if ( v6 == 1 || v6 == 3 )
      playedLegsAnim = BG_PlayAnim(ps, v7, (animBodyPart_t)v6, v5, setTimer, isContinue, force) > -1;
    else
      BG_PlayAnim(ps, v7, (animBodyPart_t)v6, v5, setTimer, isContinue, force);
  }
  v12 = scriptCommand->bodyPart[1];
  if ( v12 )
  {
    v13 = *(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960);
    if ( (*(_DWORD *)(*v13 + 120 * scriptCommand->animIndex[0] + 92) & 0x1000) != 0 )
      v14 = *(_DWORD *)(*v13 + 120 * scriptCommand->animIndex[0] + 84);
    else
      v14 = scriptCommand->animDuration[0];
    v5 = v14 + 50;
    if ( scriptCommand->bodyPart[0] == 1 || scriptCommand->bodyPart[0] == 3 )
      playedLegsAnim = BG_PlayAnim(
                         ps,
                         scriptCommand->animIndex[1],
                         (animBodyPart_t)v12,
                         v5,
                         setTimer,
                         isContinue,
                         force) > -1;
    else
      BG_PlayAnim(ps, scriptCommand->animIndex[1], (animBodyPart_t)v12, v5, setTimer, isContinue, force);
  }
  soundAlias = scriptCommand->soundAlias;
  if ( soundAlias )
    (*(void (__cdecl **)(ClientNum_t, SndAliasList *))(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                     + _tls_index)
                                                                   + 14960)
                                                     + 601980))(
      ps->clientNum,
      soundAlias);
  if ( !playedLegsAnim )
    return -1;
  else
    return v5;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyconnection.cpp:0x93EE60
int __cdecl BG_AnimScriptAnimation(pmove_t *pm, aistateEnum_t state, scriptAnimMoveTypes_t movetype, int force)
{
  playerState_s *v5; // esi
  unsigned int clientNum; // eax
  void (__cdecl **v7)(pmove_t *); // esi
  aistateEnum_t v8; // ebx
  animScript_t *i; // esi
  animScriptItem_t *ValidItem; // eax
  animScriptItem_t *v11; // edi
  unsigned int v13; // eax
  playerState_s *ps; // [esp+14h] [ebp+8h]

  v5 = pm->ps;
  ps = pm->ps;
  BG_CheckThread();
  if ( !*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp", 3422, 0, "(bgs)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( movetype < ANIM_MT_UNUSED
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          3424,
          0,
          "(movetype >= 0)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( movetype >= NUM_ANIM_MOVETYPES
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          3425,
          0,
          "(movetype < NUM_ANIM_MOVETYPES)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  clientNum = v5->clientNum;
  if ( clientNum >= 0x12
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          3427,
          0,
          "(unsigned)(ps->clientNum) < (unsigned)(18)",
          "ps->clientNum doesn't index MAX_CLIENTS\n\t%i not in [0, %i)",
          clientNum,
          18) )
  {
    __debugbreak();
  }
  v7 = localClientConditionUpdateFunc;
  do
    (*v7++)(pm);
  while ( (int)v7 < (int)&unk_10DEBFC );
  if ( ps->pm_type >= 10 )
    return -1;
  v8 = state;
  for ( i = (animScript_t *)(516 * (movetype + 27 * state)
                           + **(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
                           + 122884); ; i -= 27 )
  {
    while ( 1 )
    {
      if ( v8 < AISTATE_COMBAT )
      {
        if ( Dvar_GetBool(xanim_debug) )
          Com_Printf(18, "Failed playing animation, finding new animation\n");
        return -1;
      }
      if ( i->numItems )
        break;
      --v8;
      i -= 27;
    }
    ValidItem = BG_FirstValidItem(ps->clientNum, i);
    v11 = ValidItem;
    if ( ValidItem )
      break;
    --v8;
  }
  if ( ValidItem->numCommands )
  {
    ps->moveType = movetype;
    v13 = ps->clientNum;
    if ( v13 >= 0x12
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
            3475,
            0,
            "(unsigned)(ps->clientNum) < (unsigned)(18)",
            "ps->clientNum doesn't index MAX_CLIENTS\n\t%i not in [0, %i)",
            v13,
            18) )
    {
      __debugbreak();
    }
    if ( !v11->numCommands
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
            3478,
            0,
            "(scriptItem->numCommands)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    return BG_ExecuteCommand(ps, &v11->commands[ps->clientNum % v11->numCommands], 0, 1, force) != -1;
  }
  else
  {
    if ( !Dvar_GetBool(xanim_debug) )
      return -1;
    Com_Printf(18, "Animation has no commands associated, finding new animation\n");
    return -1;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyconnection.cpp:0x93F0B0
int __cdecl BG_AnimScriptEvent(
        pmove_t *pm,
        scriptAnimEventTypes_t event,
        int isContinue,
        int force,
        unsigned int *holdrand)
{
  playerState_s *v5; // ebx
  void (__cdecl **v6)(pmove_t *); // esi
  animScriptCommand_t *Command; // eax
  unsigned int v8; // edi
  animScriptCommand_t *v9; // ebx
  __int16 *animIndex; // esi
  int v11; // eax
  int v12; // ecx
  float v13; // xmm0_4
  double v14; // st7
  _DWORD *v15; // ecx
  int v17; // [esp+Ch] [ebp-10h]
  float v18; // [esp+10h] [ebp-Ch]
  float v19; // [esp+10h] [ebp-Ch]
  float v20; // [esp+10h] [ebp-Ch]
  float v21; // [esp+10h] [ebp-Ch]
  playerState_s *ps; // [esp+14h] [ebp-8h]
  float forcedAnimRate; // [esp+18h] [ebp-4h]

  v5 = pm->ps;
  ps = pm->ps;
  v6 = localClientConditionUpdateFunc;
  do
    (*v6++)(pm);
  while ( (int)v6 < (int)&unk_10DEBFC );
  Command = BG_AnimScriptEventGetCommand(v5, event, holdrand);
  v8 = _tls_index;
  v9 = Command;
  animIndex = Command->animIndex;
  v17 = 2;
  do
  {
    if ( !v9 )
      goto LABEL_20;
    v11 = **(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960) + 120 * *animIndex;
    v12 = *(_DWORD *)(v11 + 92);
    if ( (v12 & 0x4000) != 0 )
    {
      forcedAnimRate = (float)*(int *)(v11 + 84) / (float)ps->weaponTime;
      v18 = fabs((float)(forcedAnimRate - 1.0));
      if ( v18 > Dvar_GetFloat(bg_maxWeaponAnimScale) )
      {
        if ( (float)(forcedAnimRate - 1.0) <= 0.0 )
          v19 = 1.0 - Dvar_GetFloat(bg_maxWeaponAnimScale);
        else
          v19 = Dvar_GetFloat(bg_maxWeaponAnimScale) + 1.0;
        v13 = v19;
        goto LABEL_18;
      }
    }
    else
    {
      if ( (v12 & 0x8000) == 0 )
        goto LABEL_20;
      forcedAnimRate = (float)*(int *)(v11 + 84) / (float)ps->weaponDelay;
      v20 = fabs((float)(forcedAnimRate - 1.0));
      if ( v20 > Dvar_GetFloat(bg_maxWeaponAnimScale) )
      {
        if ( (float)(forcedAnimRate - 1.0) <= 0.0 )
          v14 = 1.0 - Dvar_GetFloat(bg_maxWeaponAnimScale);
        else
          v14 = Dvar_GetFloat(bg_maxWeaponAnimScale) + 1.0;
        v21 = v14;
        v15 = *(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960);
        v13 = v21;
        goto LABEL_19;
      }
    }
    v13 = forcedAnimRate;
LABEL_18:
    v15 = *(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v8) + 14960);
LABEL_19:
    *(float *)(*v15 + 120 * *animIndex + 72) = v13;
LABEL_20:
    ++animIndex;
    --v17;
  }
  while ( v17 );
  if ( v9 )
    return BG_ExecuteCommand(ps, v9, 1, isContinue, force);
  else
    return -1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyconnection.cpp:0x93F2E0
void __cdecl BG_SetConditionValue(ClientNum_t client, int condition, unsigned __int64 value)
{
  unsigned int v3; // ebx
  __int32 v4; // eax
  int ConditionBit; // esi
  const char *ConditionString; // eax

  BG_CheckThread();
  v3 = _tls_index;
  if ( !*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp", 3605, 0, "(bgs)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (condition >= 25 || condition < 0)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          3606,
          0,
          "((condition < NUM_ANIM_CONDITIONS && condition >= 0))",
          "(condition) = %i",
          condition) )
  {
    __debugbreak();
  }
  if ( (unsigned int)client >= CLIENT_INDEX_18
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          3608,
          0,
          "(unsigned)(client) < (unsigned)(18)",
          "client doesn't index MAX_CLIENTS\n\t%i not in [0, %i)",
          client,
          18) )
  {
    __debugbreak();
  }
  v4 = 4 * (condition + 514 * client) + 1524;
  *(_DWORD *)(v4 + *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v3) + 14960)) = value;
  if ( *(_DWORD *)(v4 + *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v3) + 14960)) != (_DWORD)value
    && G_IsServerGameSystem(client) )
  {
    if ( (unsigned int)client >= CLIENT_INDEX_18
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
            3617,
            0,
            "(unsigned)(client) < (unsigned)(18)",
            "client doesn't index MAX_CLIENTS\n\t%i not in [0, %i)",
            client,
            18) )
    {
      __debugbreak();
    }
    ConditionBit = BG_GetConditionBit(
                     condition,
                     (const clientInfo_t *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v3)
                                                      + 14960)
                                          + 2056 * client
                                          + 152));
    ConditionString = BG_GetConditionString(condition, ConditionBit);
    Com_Printf(18, "condition: %s: %s\n", animConditionsStr[condition].string, ConditionString);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyconnection.cpp:0x93F440
unsigned __int16 __cdecl BG_AddWorldModelWeaponAttachments(
        Weapon weapon,
        DObjModel_s *dobjModels,
        int numModels,
        unsigned __int16 boneIndex,
        WeaponDobjInfo *weaponDobjInfo,
        unsigned __int16 parentModel,
        bool hideClip)
{
  const WeaponVariantDef *WeaponVariantDef; // edi
  int i; // ebx
  bool IsBaseWeaponClipAttachmentDisabled; // al
  const char **attachWorldModelTag; // ecx
  unsigned __int16 String; // ax
  char v12; // di
  DObjModel_s *v13; // esi
  const WeaponVariantDef *v14; // eax
  XModel *v15; // edx
  __int16 lastAddedModel; // dx
  double v17; // st7
  const WeaponVariantDef *v18; // eax
  eAttachment v19; // eax
  int v20; // eax
  WeaponAttachmentUnique *v21; // eax
  unsigned int AttachmentOverrideChildIndex; // eax
  unsigned int v23; // esi
  const WeaponAttachmentUnique *v24; // esi
  const char *v25; // eax
  DObjModel_s *v26; // edi
  const char *worldModelTag; // eax
  unsigned __int16 v28; // ax
  XModel *worldModelAdditional; // ecx
  unsigned __int16 boneName; // cx
  DObjModel_s *v31; // eax
  WeaponAttachmentUnique *attachmentList[3]; // [esp+Ch] [ebp-14h] BYREF
  int attachmentModels; // [esp+18h] [ebp-8h]
  const WeaponVariantDef *weapVariantDef; // [esp+1Ch] [ebp-4h]

  WeaponVariantDef = BG_GetWeaponVariantDef(weapon);
  weapVariantDef = WeaponVariantDef;
  for ( i = 0; i < 8; ++i )
  {
    if ( !WeaponVariantDef->attachWorldModel[i] )
      continue;
    if ( i )
    {
      if ( i != 6 )
        goto LABEL_9;
      if ( hideClip )
        continue;
      IsBaseWeaponClipAttachmentDisabled = BG_IsBaseWeaponClipAttachmentDisabled(weapon);
    }
    else
    {
      IsBaseWeaponClipAttachmentDisabled = BG_IsBaseWeaponAttachmentDisabled(weapon);
    }
    if ( IsBaseWeaponClipAttachmentDisabled )
      continue;
LABEL_9:
    attachWorldModelTag = WeaponVariantDef->attachWorldModelTag;
    if ( attachWorldModelTag[i]
      && *attachWorldModelTag[i]
      && ((String = SL_FindString(attachWorldModelTag[i])) != 0
       || (String = SL_GetString(WeaponVariantDef->attachWorldModelTag[i], 1u)) != 0) )
    {
      v12 = numModels;
      v13 = &dobjModels[(unsigned __int16)numModels];
      v13->boneName = String;
    }
    else
    {
      v12 = numModels;
      v13 = &dobjModels[(unsigned __int16)numModels];
      v13->boneName = boneIndex;
    }
    if ( (unsigned __int16)numModels >= 0x20u
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
            5184,
            0,
            "(numModels < 32)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v14 = weapVariantDef;
    v15 = weapVariantDef->attachWorldModel[i];
    v13->parentModel = parentModel;
    v13->model = v15;
    v13->ignoreCollision = 1;
    if ( weaponDobjInfo )
    {
      lastAddedModel = weaponDobjInfo->lastAddedModel;
      if ( lastAddedModel >= 0 )
      {
        attachmentModels = 1;
        weaponDobjInfo->modelMasks[lastAddedModel].dobjModelMask |= 1 << v12;
      }
    }
    v17 = v14->attachWorldModelRotations[3 * i];
    v18 = (const WeaponVariantDef *)((char *)v14 + 12 * i);
    v13->rot.x = v17;
    v13->rot.y = v18->attachWorldModelRotations[1];
    v13->rot.z = v18->attachWorldModelRotations[2];
    if ( i )
      goto LABEL_25;
    v19 = BG_IsOverridingBaseWeaponAttachmentOffsets(weapon);
    if ( v19 == ATTACHMENT_NONE )
    {
      v18 = weapVariantDef;
LABEL_25:
      v13->trans.x = v18->attachWorldModelOffsets[0];
      v13->trans.y = v18->attachWorldModelOffsets[1];
      v13->trans.z = v18->attachWorldModelOffsets[2];
      goto LABEL_26;
    }
    BG_GetWorldAttachmentOffsetsOverride(weapon, v19, &v13->trans);
LABEL_26:
    ++numModels;
    WeaponVariantDef = weapVariantDef;
  }
  BG_GetWeaponAttachmentUniques(weapon, (WeaponAttachmentUnique *(*)[3])attachmentList);
  v20 = 0;
  attachmentModels = 0;
  do
  {
    v21 = attachmentList[v20];
    if ( v21 && v21->worldModel && (!v21->disableBaseWeaponClip || !hideClip) )
    {
      AttachmentOverrideChildIndex = BG_GetAttachmentOverrideChildIndex(weapon, WeaponVariantDef, v21->attachmentType);
      v23 = AttachmentOverrideChildIndex;
      if ( AttachmentOverrideChildIndex >= 0x5F
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
              5230,
              0,
              "(unsigned)(attachmentIndex) < (unsigned)((63 + 32))",
              "attachmentIndex doesn't index MAX_ATTACHMENT_UNIQUES\n\t%i not in [0, %i)",
              AttachmentOverrideChildIndex,
              95) )
      {
        __debugbreak();
      }
      v24 = WeaponVariantDef->attachmentUniques[v23];
      if ( !v24
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
              5232,
              0,
              "(attachmentUnique)",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      if ( v24->worldModel )
        goto LABEL_61;
      v25 = va(
              "Missing model for weapon %s with attachment %s\n",
              WeaponVariantDef->szInternalName,
              v24->szInternalName);
      if ( !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
              5234,
              0,
              "(attachmentUnique->worldModel)",
              "%s",
              v25) )
        __debugbreak();
      if ( v24->worldModel )
      {
LABEL_61:
        if ( (unsigned __int16)numModels >= 0x20u
          && !Assert_MyHandler(
                "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
                5238,
                0,
                "(numModels < 32)",
                (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v26 = &dobjModels[(unsigned __int16)numModels];
        v26->model = v24->worldModel;
        v26->parentModel = parentModel;
        v26->ignoreCollision = 1;
        worldModelTag = v24->worldModelTag;
        if ( worldModelTag
          && *worldModelTag
          && ((v28 = SL_FindString(v24->worldModelTag)) != 0 || (v28 = SL_GetString(v24->worldModelTag, 1u)) != 0) )
        {
          v26->boneName = v28;
        }
        else
        {
          v26->boneName = boneIndex;
        }
        v26->trans.x = v24->worldModelOffsets.x;
        v26->trans.y = v24->worldModelOffsets.y;
        v26->trans.z = v24->worldModelOffsets.z;
        v26->rot.x = v24->worldModelRotations.x;
        v26->rot.y = v24->worldModelRotations.y;
        v26->rot.z = v24->worldModelRotations.z;
        if ( weaponDobjInfo )
          WeaponDobjInfo::Add(weaponDobjInfo, v24, (2 * (v24->worldModelAdditional != 0) + 1) << numModels);
        worldModelAdditional = v24->worldModelAdditional;
        ++numModels;
        if ( worldModelAdditional )
        {
          dobjModels[(unsigned __int16)numModels].model = worldModelAdditional;
          boneName = dobjModels[(unsigned __int16)numModels - 1].boneName;
          v31 = &dobjModels[(unsigned __int16)numModels];
          v31->ignoreCollision = 1;
          v31->boneName = boneName;
          ++numModels;
          v31->trans.x = v24->worldModelAddOffsets.x;
          v31->trans.y = v24->worldModelAddOffsets.y;
          v31->trans.z = v24->worldModelAddOffsets.z;
          v31->rot.x = v24->worldModelAddRotations.x;
          v31->rot.y = v24->worldModelAddRotations.y;
          v31->rot.z = v24->worldModelAddRotations.z;
        }
        WeaponVariantDef = weapVariantDef;
      }
    }
    v20 = attachmentModels + 1;
    attachmentModels = v20;
  }
  while ( v20 < 3 );
  return numModels;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyconnection.cpp:0xA47E40
BOOL __cdecl R_SortSurfacesOnAxis_PosX(const GfxSurface *surf0, const GfxSurface *surf1)
{
  return (float)((float)(surf1->bounds[1].x + surf1->bounds[0].x) * 0.5) > (float)((float)(surf0->bounds[1].x
                                                                                         + surf0->bounds[0].x)
                                                                                 * 0.5);
}

#endif // __UNIMPLEMENTED__
