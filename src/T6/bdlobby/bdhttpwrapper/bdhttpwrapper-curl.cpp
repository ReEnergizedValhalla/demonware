// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940110
void __cdecl BG_PostLoadAnim(const char *levelName)
{
  Scr_EndLoadAnimTrees(SCRIPTINSTANCE_SERVER);
  BG_FinalizePlayerAnims(levelName);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940130
void __cdecl BG_LocalEvalPlayerAnimType(pmove_t *pm)
{
  playerState_s *ps; // edi
  Weapon v2; // eax
  const WeaponDef *WeaponDef; // esi
  int PlayerAnimTypeIndex; // eax

  ps = pm->ps;
  v2.0 = BG_GetPlayerStateWeapon(pm).0;
  WeaponDef = BG_GetWeaponDef(v2);
  if ( !WeaponDef
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animconditions.cpp",
          70,
          0,
          "(weaponDef)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( ps->pm_type != 8 || (PlayerAnimTypeIndex = BG_GetPlayerAnimTypeIndex(0), PlayerAnimTypeIndex == -1) )
    BG_SetConditionBit(ps->clientNum, 0, WeaponDef->playerAnimType);
  else
    BG_SetConditionBit(ps->clientNum, 0, PlayerAnimTypeIndex);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x9401D0
void __cdecl BG_EvalPlayerAnimType(const entityState_s *es)
{
  const WeaponDef *WeaponDef; // esi

  WeaponDef = BG_GetWeaponDef(es->weapon);
  if ( !WeaponDef
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animconditions.cpp",
          92,
          0,
          "(weaponDef)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  BG_SetConditionBit((ClientNum_t)es->clientNum, 0, WeaponDef->playerAnimType);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940230
void __cdecl BG_LocalEvalNextPlayerAnimType(pmove_t *pm)
{
  Weapon v1; // eax
  const WeaponDef *WeaponDef; // esi

  v1.0 = BG_GetNextPlayerStateWeapon(pm).0;
  WeaponDef = BG_GetWeaponDef(v1);
  if ( !WeaponDef
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animconditions.cpp",
          102,
          0,
          "(weaponDef)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  BG_SetConditionBit(pm->ps->clientNum, 2, WeaponDef->playerAnimType);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940290
void __cdecl BG_LocalEvalWeaponClass(pmove_t *pm)
{
  playerState_s *ps; // esi
  Weapon v2; // eax
  const WeaponDef *WeaponDef; // eax

  ps = pm->ps;
  v2.0 = BG_GetPlayerStateWeapon(pm).0;
  WeaponDef = BG_GetWeaponDef(v2);
  BG_SetConditionBit(ps->clientNum, 1, WeaponDef->weapClass);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x9402C0
void __cdecl BG_EvalWeaponClass(const entityState_s *es)
{
  const WeaponDef *WeaponDef; // esi

  WeaponDef = BG_GetWeaponDef(es->weapon);
  if ( !WeaponDef
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animconditions.cpp",
          123,
          0,
          "(weaponDef)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  BG_SetConditionBit((ClientNum_t)es->clientNum, 1, WeaponDef->weapClass);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940320
void __cdecl BG_LocalEvalNextWeaponClass(pmove_t *pm)
{
  Weapon v1; // eax
  const WeaponDef *WeaponDef; // eax

  v1.0 = BG_GetNextPlayerStateWeapon(pm).0;
  WeaponDef = BG_GetWeaponDef(v1);
  BG_SetConditionBit(pm->ps->clientNum, 3, WeaponDef->weapClass);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940350
void __cdecl BG_LocalEvalMounted(pmove_t *pm)
{
  playerState_s *ps; // eax

  ps = pm->ps;
  if ( (pm->ps->eFlags & 0x300) == 0 || (ps->eFlags2 & 0x10000000) != 0 )
    BG_SetConditionValue(ps->clientNum, 4, 0i64);
  else
    BG_SetConditionValue(ps->clientNum, 4, 1ui64);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x9403A0
void __cdecl BG_EvalMounted(const entityState_s *es)
{
  int eFlags; // ecx
  unsigned __int8 vehicleSeat; // cl

  eFlags = es->lerp.eFlags;
  if ( (eFlags & 0x300) != 0 && (es->lerp.eFlags2 & 0x10000000) == 0
    || (eFlags & 0x4000) != 0 && (vehicleSeat = es->lerp.u.player.vehicleSeat) != 0 && vehicleSeat <= 4u )
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 4, 1ui64);
  }
  else
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 4, 0i64);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940420
void __cdecl BG_LocalEvalMoveStatus(pmove_t *pm)
{
  playerState_s *ps; // eax
  float moveThreshhold; // [esp+0h] [ebp-Ch]
  float runThreshhold; // [esp+4h] [ebp-8h]
  float knockbackThreshhold; // [esp+8h] [ebp-4h]

  runThreshhold = Dvar_GetFloat(player_runThreshhold);
  moveThreshhold = Dvar_GetFloat(player_moveThreshhold);
  knockbackThreshhold = Dvar_GetFloat(player_knockbackMoveThreshhold);
  ps = pm->ps;
  if ( (pm->ps->pm_flags & 0x100) != 0
    && (float)(knockbackThreshhold * knockbackThreshhold) > (float)((float)(ps->velocity.x * ps->velocity.x)
                                                                  + (float)(ps->velocity.y * ps->velocity.y)) )
  {
    goto LABEL_7;
  }
  if ( (float)((float)(ps->velocity.x * ps->velocity.x) + (float)(ps->velocity.y * ps->velocity.y)) > (float)(runThreshhold * runThreshhold) )
  {
    BG_SetConditionBit(ps->clientNum, 5, 2);
    return;
  }
  if ( (float)((float)(ps->velocity.x * ps->velocity.x) + (float)(ps->velocity.y * ps->velocity.y)) <= (float)(moveThreshhold * moveThreshhold) )
LABEL_7:
    BG_SetConditionBit(ps->clientNum, 5, 0);
  else
    BG_SetConditionBit(ps->clientNum, 5, 1);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940520
void __cdecl BG_EvalMoveStatus(const entityState_s *es)
{
  int v1; // eax

  v1 = *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
                 + 120 * (es->un2.anim.legsAnim & 0xFFFFFBFF)
                 + 92);
  if ( ((unsigned int)&g_hunk_track[160413].name[112] & v1) != 0 )
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 5, 2ui64);
  }
  else if ( ((unsigned int)&g_hunklow_track[6894].name[40] & v1) != 0 )
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 5, 1ui64);
  }
  else
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 5, 0i64);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x9405B0
void __cdecl BG_LocalEvalPrevDirection(pmove_t *pm)
{
  signed int ConditionValue; // eax

  ConditionValue = BG_GetConditionValue(
                     (const clientInfo_t *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                        + _tls_index)
                                                      + 14960)
                                          + 2056 * pm->ps->clientNum
                                          + 152),
                     7);
  if ( ConditionValue )
    BG_SetConditionValue(pm->ps->clientNum, 6, ConditionValue);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940610
void __cdecl BG_LocalEvalDirection(pmove_t *pm)
{
  float rightmove; // xmm0_4
  float forwardmove; // xmm1_4
  float v3; // xmm3_4
  float v4; // xmm1_4
  int v5; // eax
  float strafeAnimCosAngle; // [esp+4h] [ebp-10h]
  float moveVec; // [esp+8h] [ebp-Ch]

  rightmove = (float)pm->cmd.rightmove;
  forwardmove = (float)pm->cmd.forwardmove;
  v3 = fsqrt((float)(rightmove * rightmove) + (float)(forwardmove * forwardmove));
  if ( COERCE_FLOAT(LODWORD(v3) ^ _mask__NegFloat_) >= 0.0 )
    v3 = *(float *)&FLOAT_1_0;
  moveVec = rightmove * (float)(1.0 / v3);
  strafeAnimCosAngle = Dvar_GetFloat(player_strafeAnimCosAngle);
  v4 = forwardmove * (float)(1.0 / v3);
  if ( v4 <= strafeAnimCosAngle )
  {
    if ( COERCE_FLOAT(LODWORD(strafeAnimCosAngle) ^ _mask__NegFloat_) <= v4 )
    {
      if ( moveVec <= 0.0 )
      {
        if ( moveVec >= 0.0 )
          v5 = 0;
        else
          v5 = 3;
      }
      else
      {
        v5 = 4;
      }
    }
    else
    {
      v5 = 2;
    }
  }
  else
  {
    v5 = 1;
  }
  BG_SetConditionValue(pm->ps->clientNum, 7, v5);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940610
void __cdecl BG_LocalEvalDirection(pmove_t *pm)
{
  float rightmove; // xmm0_4
  float forwardmove; // xmm1_4
  float v3; // xmm3_4
  float v4; // xmm1_4
  int v5; // eax
  float strafeAnimCosAngle; // [esp+4h] [ebp-10h]
  float moveVec; // [esp+8h] [ebp-Ch]

  rightmove = (float)pm->cmd.rightmove;
  forwardmove = (float)pm->cmd.forwardmove;
  v3 = fsqrt((float)(rightmove * rightmove) + (float)(forwardmove * forwardmove));
  if ( COERCE_FLOAT(LODWORD(v3) ^ _mask__NegFloat_) >= 0.0 )
    v3 = *(float *)&FLOAT_1_0;
  moveVec = rightmove * (float)(1.0 / v3);
  strafeAnimCosAngle = Dvar_GetFloat(player_strafeAnimCosAngle);
  v4 = forwardmove * (float)(1.0 / v3);
  if ( v4 <= strafeAnimCosAngle )
  {
    if ( COERCE_FLOAT(LODWORD(strafeAnimCosAngle) ^ _mask__NegFloat_) <= v4 )
    {
      if ( moveVec <= 0.0 )
      {
        if ( moveVec >= 0.0 )
          v5 = 0;
        else
          v5 = 3;
      }
      else
      {
        v5 = 4;
      }
    }
    else
    {
      v5 = 2;
    }
  }
  else
  {
    v5 = 1;
  }
  BG_SetConditionValue(pm->ps->clientNum, 7, v5);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940710
void __cdecl BG_EvalDirection(const entityState_s *es)
{
  int v1; // eax

  v1 = *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
                 + 120 * (es->un2.anim.legsAnim & 0xFFFFFBFF)
                 + 92);
  if ( (v1 & 0x10) != 0 )
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 7, 3ui64);
  }
  else if ( (v1 & 0x20) != 0 )
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 7, 4ui64);
  }
  else if ( (v1 & 0x40) != 0 )
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 7, 2ui64);
  }
  else if ( (v1 & 0x80u) == 0 )
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 7, 0i64);
  }
  else
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 7, 1ui64);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x9407D0
void __cdecl BG_LocalEvalDmgDirection(pmove_t *pm)
{
  playerState_s *ps; // eax
  int dmgDirection; // ecx

  ps = pm->ps;
  dmgDirection = pm->ps->dmgDirection;
  switch ( dmgDirection )
  {
    case 3:
      BG_SetConditionValue(ps->clientNum, 8, 3ui64);
      break;
    case 4:
      BG_SetConditionValue(ps->clientNum, 8, 4ui64);
      break;
    case 2:
      BG_SetConditionValue(ps->clientNum, 8, 2ui64);
      break;
    case 1:
      BG_SetConditionValue(ps->clientNum, 8, 1ui64);
      break;
    default:
      BG_SetConditionValue(ps->clientNum, 8, 0i64);
      break;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940860
void __cdecl BG_EvalDmgDirection(const entityState_s *es)
{
  int v1; // eax

  v1 = *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
                 + 120 * (es->un2.anim.legsAnim & 0xFFFFFBFF)
                 + 92);
  if ( (v1 & 0x80000) != 0 )
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 8, 3ui64);
  }
  else if ( (v1 & 0x100000) != 0 )
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 8, 4ui64);
  }
  else if ( (v1 & 0x200000) != 0 )
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 8, 2ui64);
  }
  else if ( (v1 & 0x400000) != 0 )
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 8, 1ui64);
  }
  else
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 8, 0i64);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940930
void __cdecl BG_LocalEvalDmgType(pmove_t *pm)
{
  playerState_s *ps; // ecx
  int dmgType; // eax

  ps = pm->ps;
  dmgType = pm->ps->dmgType;
  switch ( dmgType )
  {
    case 2:
      BG_SetConditionValue(ps->clientNum, 9, 6ui64);
      break;
    case 5:
      BG_SetConditionValue(ps->clientNum, 9, 2ui64);
      break;
    case 4:
      BG_SetConditionValue(ps->clientNum, 9, 5ui64);
      break;
    case 3:
      BG_SetConditionValue(ps->clientNum, 9, 3ui64);
      break;
    case 7:
      BG_SetConditionValue(ps->clientNum, 9, 4ui64);
      break;
    case 6:
      BG_SetConditionValue(ps->clientNum, 9, 7ui64);
      break;
    case 1:
      BG_SetConditionValue(ps->clientNum, 9, 1ui64);
      break;
    case 8:
      BG_SetConditionValue(ps->clientNum, 9, 9ui64);
      break;
    default:
      BG_SetConditionValue(ps->clientNum, 9, 0i64);
      break;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940A30
void __cdecl BG_LocalEvalStance(pmove_t *pm)
{
  int EffectiveStance; // eax
  playerState_s *ps; // ecx

  EffectiveStance = PM_GetEffectiveStance(pm->ps);
  if ( EffectiveStance == 1 || (ps = pm->ps, (pm->ps->pm_flags & 0x200000) != 0) )
  {
    BG_SetConditionValue(pm->ps->clientNum, 10, 2ui64);
  }
  else if ( EffectiveStance == 2 )
  {
    BG_SetConditionValue(ps->clientNum, 10, 1ui64);
  }
  else
  {
    BG_SetConditionValue(ps->clientNum, 10, 0i64);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940AA0
void __cdecl BG_EvalStance(const entityState_s *es)
{
  int v1; // eax

  v1 = *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
                 + 120 * (es->un2.anim.legsAnim & 0xFFFFFBFF)
                 + 92);
  if ( ((unsigned int)&g_sd.voiceDecodeBuffer[774848] & v1) != 0 )
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 10, 2ui64);
  }
  else if ( (((unsigned int)&loc_7FFFFF + 1) & v1) != 0 )
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 10, 1ui64);
  }
  else
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 10, 0i64);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940B30
void __cdecl BG_LocalEvalUnderhand(pmove_t *pm)
{
  BG_SetConditionValue(pm->ps->clientNum, 11, pm->ps->viewangles.x > 0.0);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940B80
void __cdecl BG_EvalUnderhand(const entityState_s *es, const clientInfo_t *ci)
{
  BG_SetConditionValue((ClientNum_t)es->clientNum, 11, ci->playerAngles.x > 0.0);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940BD0
void __cdecl BG_EvalFiring(const entityState_s *es)
{
  if ( (es->lerp.eFlags & 0x40) != 0 )
    BG_SetConditionValue((ClientNum_t)es->clientNum, 12, 1ui64);
  else
    BG_SetConditionValue((ClientNum_t)es->clientNum, 12, 0i64);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940C10
void __cdecl BG_LocalEvalWeaponPosition(pmove_t *pm)
{
  playerState_s *ps; // eax

  ps = pm->ps;
  if ( (pm->ps->pm_flags & 0x10) != 0 )
  {
    BG_SetConditionValue(ps->clientNum, 13, 1ui64);
  }
  else if ( ps->weaponstate == 32 )
  {
    BG_SetConditionValue(ps->clientNum, 13, 2ui64);
  }
  else
  {
    BG_SetConditionValue(ps->clientNum, 13, 0i64);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940C70
void __cdecl BG_EvalWeaponPosition(const entityState_s *es)
{
  if ( (es->lerp.eFlags & 0x80000) != 0 )
    BG_SetConditionValue((ClientNum_t)es->clientNum, 13, 1ui64);
  else
    BG_SetConditionValue((ClientNum_t)es->clientNum, 13, 0i64);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940CB0
void __cdecl BG_LocalEvalSlope(pmove_t *pm)
{
  float averagePitch; // xmm1_4
  int v2; // eax
  float slopeAnimAngle; // [esp+0h] [ebp-4h]

  slopeAnimAngle = Dvar_GetFloat(player_slopeAnimAngle);
  if ( !Dvar_GetBool(player_useSlopeAnims) )
    goto LABEL_6;
  averagePitch = pm->averagePitch;
  if ( averagePitch <= slopeAnimAngle )
  {
    if ( COERCE_FLOAT(LODWORD(slopeAnimAngle) ^ _mask__NegFloat_) > averagePitch )
    {
      v2 = 2;
      goto LABEL_7;
    }
LABEL_6:
    v2 = 0;
    goto LABEL_7;
  }
  v2 = 1;
LABEL_7:
  BG_SetConditionValue(pm->ps->clientNum, 14, v2);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940D20
void __cdecl BG_EvalSlope(const entityState_s *es)
{
  int v1; // eax

  v1 = *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
                 + 120 * (es->un2.anim.legsAnim & 0xFFFFFBFF)
                 + 92);
  if ( (v1 & 0x20000) != 0 )
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 14, 1ui64);
  }
  else if ( (v1 & 0x40000) != 0 )
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 14, 2ui64);
  }
  else
  {
    BG_SetConditionValue((ClientNum_t)es->clientNum, 14, 0i64);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940DB0
void __cdecl BG_LocalEvalPerk(pmove_t *pm)
{
  playerState_s *ps; // esi
  int pm_type; // eax
  Weapon v3; // eax
  Weapon v4; // eax
  Weapon v5; // eax
  Weapon v6; // eax

  ps = pm->ps;
  pm_type = pm->ps->pm_type;
  if ( pm_type == 7 || pm_type == 8 )
  {
    BG_SetConditionBit(ps->clientNum, 15, 1);
  }
  else if ( Com_BitCheckAssert(ps->perks, 18, 0xFFFFFFF) > 0
         || (v3.0 = BG_GetViewmodelWeaponIndex(ps).0, BG_WeaponHasPerk(v3, 0x12u)) )
  {
    BG_SetConditionBit(ps->clientNum, 15, 3);
  }
  else if ( Com_SessionMode_IsZombiesGame()
         && (Com_BitCheckAssert(ps->perks, 42, 0xFFFFFFF) > 0
          || (v4.0 = BG_GetViewmodelWeaponIndex(ps).0, BG_WeaponHasPerk(v4, 0x2Au))) )
  {
    BG_SetConditionBit(ps->clientNum, 15, 4);
  }
  else if ( Com_SessionMode_IsZombiesGame()
         && (Com_BitCheckAssert(ps->perks, 19, 0xFFFFFFF) > 0
          || (v5.0 = BG_GetViewmodelWeaponIndex(ps).0, BG_WeaponHasPerk(v5, 0x13u))) )
  {
    BG_SetConditionBit(ps->clientNum, 15, 6);
  }
  else if ( Com_SessionMode_IsZombiesGame()
         && (Com_BitCheckAssert(ps->perks, 27, 0xFFFFFFF) > 0
          || (v6.0 = BG_GetViewmodelWeaponIndex(ps).0, BG_WeaponHasPerk(v6, 0x1Bu))) )
  {
    BG_SetConditionBit(ps->clientNum, 15, 5);
  }
  else
  {
    BG_SetConditionBit(ps->clientNum, 15, 0);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940F10
void __cdecl BG_LocalEvalAttachment(pmove_t *pm)
{
  playerState_s *ps; // edi
  Weapon v2; // eax
  const WeaponDef *WeaponDef; // esi

  ps = pm->ps;
  v2.0 = BG_GetPlayerStateWeapon(pm).0;
  WeaponDef = BG_GetWeaponDef(v2);
  if ( !WeaponDef
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animconditions.cpp",
          499,
          0,
          "(weaponDef)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( WeaponDef->bHasBayonet )
    BG_SetConditionValue(ps->clientNum, 16, 1ui64);
  else
    BG_SetConditionValue(ps->clientNum, 16, 0i64);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940F90
void __cdecl BG_LocalEvalRiotShieldNext(pmove_t *pm)
{
  BG_SetConditionValue(pm->ps->clientNum, 17, (pm->ps->weapFlags & 0x400000) != 0);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapper-curl.cpp:0x940FE0
void __cdecl BG_LocalEvalVehicleName(pmove_t *pm)
{
  playerState_s *ps; // esi
  int eFlags; // ecx
  int (__cdecl *v3)(ClientNum_t, int, VehicleDef **); // edx
  unsigned __int16 v4; // ax
  int VehicleAnimSetIndex; // eax
  ClientNum_t clientNum; // [esp-Ch] [ebp-10h]
  int viewlocked_entNum; // [esp-8h] [ebp-Ch]

  ps = pm->ps;
  eFlags = pm->ps->eFlags;
  if ( (eFlags & 0x4000) == 0
    || (eFlags & 0x10000) != 0
    || (ps->eFlags2 & 0x10000000) != 0
    || (viewlocked_entNum = ps->viewlocked_entNum,
        v3 = (int (__cdecl *)(ClientNum_t, int, VehicleDef **))*(&funcs_94103E + 9 * pm->handler),
        clientNum = ps->clientNum,
        pm = 0,
        (v4 = v3(clientNum, viewlocked_entNum, (VehicleDef **)&pm)) == 0) )
  {
    BG_SetConditionValue(ps->clientNum, 18, 0xFFui64);
  }
  else
  {
    VehicleAnimSetIndex = BG_GetVehicleAnimSetIndex(v4);
    if ( VehicleAnimSetIndex >= 0 )
      BG_SetConditionValue(ps->clientNum, 18, VehicleAnimSetIndex);
  }
}

#endif // __UNIMPLEMENTED__
