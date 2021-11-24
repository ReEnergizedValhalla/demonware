// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x954DC0
unsigned int __cdecl PM_GroundSurfaceType(playerState_s *ps, pml_t *pml)
{
  int sflags; // eax
  unsigned int v4; // esi

  if ( !pml
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 1730, 0, "(pml)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  sflags = pml->groundTrace.sflags;
  if ( (sflags & 0x2000) != 0 )
    return 0;
  v4 = (sflags >> 20) & 0x3F;
  if ( v4 >= 0x20
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp",
          1736,
          0,
          "(iSurfType >= 0 && iSurfType < 32)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( ps )
  {
    if ( ps->waterlevel )
      return 20;
  }
  return v4;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x954E50
void __usercall PM_DeadMove(playerState_s *ps@<esi>, pml_t *pml)
{
  float v2; // xmm3_4
  float v3; // xmm1_4

  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 2186, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( pml->walking )
  {
    v2 = fsqrt(
           (float)((float)(ps->velocity.x * ps->velocity.x) + (float)(ps->velocity.y * ps->velocity.y))
         + (float)(ps->velocity.z * ps->velocity.z));
    if ( (ps->pm_flags & 0x400000) == 0 )
      v2 = v2 - 20.0;
    if ( v2 > 0.0 )
    {
      v3 = fsqrt(
             (float)((float)(ps->velocity.x * ps->velocity.x) + (float)(ps->velocity.y * ps->velocity.y))
           + (float)(ps->velocity.z * ps->velocity.z));
      if ( COERCE_FLOAT(LODWORD(v3) ^ _mask__NegFloat_) >= 0.0 )
        v3 = *(float *)&FLOAT_1_0;
      ps->velocity.x = (float)(1.0 / v3) * ps->velocity.x;
      ps->velocity.y = ps->velocity.y * (float)(1.0 / v3);
      ps->velocity.z = ps->velocity.z * (float)(1.0 / v3);
      ps->velocity.x = ps->velocity.x * v2;
      ps->velocity.y = ps->velocity.y * v2;
      ps->velocity.z = ps->velocity.z * v2;
    }
    else
    {
      *(_QWORD *)&ps->velocity.x = 0i64;
      ps->velocity.z = 0.0;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x954F80
int __usercall PM_FootstepType@<eax>(pmove_t *pm@<esi>)
{
  playerState_s *ps; // eax
  int pm_flags; // ecx
  int result; // eax
  float runThreshhold; // [esp+0h] [ebp-4h]

  runThreshhold = Dvar_GetFloat(player_runThreshhold);
  ps = pm->ps;
  pm_flags = pm->ps->pm_flags;
  if ( (pm_flags & 1) != 0 )
    return 133;
  if ( (pm_flags & 2) != 0 )
  {
    if ( (pm_flags & 0x40) != 0 || ps->leanf != 0.0 || runThreshhold > pm->xyspeed )
      return 132;
    else
      return 131;
  }
  else
  {
    if ( (pm_flags & 0x40) != 0 || ps->leanf != 0.0 )
      return 130;
    if ( (pm_flags & 0x8000) != 0 )
      return 128;
    result = 129;
    if ( runThreshhold > pm->xyspeed )
      return 130;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x955030
unsigned int __usercall PM_DamageLandingForSurface@<eax>(playerState_s *ps@<eax>, pml_t *pml@<esi>)
{
  unsigned int v2; // edi
  pml_t *v4; // [esp+14h] [ebp-8h]

  v2 = PM_GroundSurfaceType(ps, v4);
  if ( !v2 )
    Com_PrintError(
      1,
      "PM_DamageLandingForSurface has been called with a ground surface of type 'NONE' near (%.2f %.2f %.2f). \n"
      "This means a player has landed on a surface that wasn't properly setup to be used as a ground surface. \n"
      "Use a different material which has a surface type set.\n",
      pml->previous_origin.x,
      pml->previous_origin.y,
      pml->previous_origin.z);
  return v2 + 169;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x955090
void __cdecl PM_CrashLand(pmove_t *pm, pml_t *pml)
{
  playerState_s *ps; // edi
  float z; // xmm4_4
  float gravity; // xmm3_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  int v7; // eax
  Weapon v8; // eax
  Weapon v9; // eax
  signed int v10; // esi
  unsigned int v11; // eax
  int pm_flags; // eax
  int v13; // ecx
  float v14; // xmm0_4
  int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  int v18; // [esp-4h] [ebp-24h]
  float v19; // [esp+10h] [ebp-10h]
  float FallDamageMinHeight; // [esp+14h] [ebp-Ch]
  float FallDamageMaxHeight; // [esp+14h] [ebp-Ch]
  float fallHeight; // [esp+18h] [ebp-8h]
  int damage; // [esp+1Ch] [ebp-4h] BYREF

  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 2617, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( ps->waterlevel != 4 )
  {
    z = pml->previous_velocity.z;
    gravity = (float)ps->gravity;
    v5 = (float)(z * z)
       - (float)((float)(pml->previous_origin.z - ps->origin.z)
               * (float)((float)(COERCE_FLOAT(LODWORD(gravity) ^ _mask__NegFloat_) * 0.5) * 4.0));
    if ( v5 >= 0.0 )
    {
      v6 = (float)((float)((float)((float)(COERCE_FLOAT(LODWORD(z) ^ _mask__NegFloat_) - fsqrt(v5))
                                 / (float)((float)(COERCE_FLOAT(LODWORD(gravity) ^ _mask__NegFloat_) * 0.5) * 2.0))
                         * COERCE_FLOAT(LODWORD(gravity) ^ _mask__NegFloat_))
                 + z)
         * -1.0;
      fallHeight = (float)(v6 * v6) / (float)(gravity * 2.0);
      if ( BG_GetFallDamageMinHeight() <= 0.0
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp",
              2641,
              0,
              "(BG_GetFallDamageMinHeight() > 0)",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      FallDamageMinHeight = BG_GetFallDamageMinHeight();
      if ( BG_GetFallDamageMaxHeight() <= FallDamageMinHeight
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp",
              2642,
              0,
              "(BG_GetFallDamageMinHeight() < BG_GetFallDamageMaxHeight())",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      if ( BG_GetFallDamageMinHeight() >= fallHeight )
      {
        damage = 0;
        goto LABEL_20;
      }
      if ( fallHeight >= BG_GetFallDamageMaxHeight() )
      {
        damage = 100;
        goto LABEL_20;
      }
      v19 = fallHeight - BG_GetFallDamageMinHeight();
      FallDamageMaxHeight = BG_GetFallDamageMaxHeight();
      v7 = (int)(v19 / (FallDamageMaxHeight - BG_GetFallDamageMinHeight()) * 100.0);
      if ( v7 < 100 )
      {
        damage = 0;
        if ( v7 <= 0 )
          goto LABEL_20;
      }
      else
      {
        v7 = 100;
      }
      damage = v7;
LABEL_20:
      Dtp_AdjustDamage(ps, fallHeight, &damage);
      if ( Com_SessionMode_IsZombiesGame() && ps->gravity < (int)Dvar_GetFloat(bg_gravity) )
        damage = 0;
      if ( Com_BitCheckAssert(ps->perks, 14, 0xFFFFFFF) > 0
        || (v8.0 = BG_GetViewmodelWeaponIndex(ps).0, BG_WeaponHasPerk(v8, 0xEu)) )
      {
        damage = 0;
      }
      if ( Com_SessionMode_IsMode(SESSIONMODE_ZOMBIES) )
      {
        if ( Com_BitCheckAssert(ps->perks, 25, 0xFFFFFFF) > 0
          || (v9.0 = BG_GetViewmodelWeaponIndex(ps).0, BG_WeaponHasPerk(v9, 0x19u)) )
        {
          if ( damage > 0 )
            damage = 1;
        }
      }
      if ( (pml->groundTrace.sflags & 1) != 0 || ps->pm_type >= 10 )
        damage = 0;
      if ( ps->waterlevel >= 2 )
        damage = (int)(float)((float)damage * 0.5);
      if ( fallHeight > 12.0 )
      {
        v10 = (int)(float)((float)((float)((float)(fallHeight - 12.0) * 0.03846154) + 1.0) * 4.0);
        if ( v10 > 24 )
          v10 = 24;
        if ( (ps->pm_flags & 0x200000) == 0 )
          BG_AnimScriptEvent(pm, ANIM_ET_LAND, 0, 1, &pml->holdrand);
      }
      else
      {
        v10 = 0;
      }
      v11 = PM_GroundSurfaceType(ps, pml);
      if ( damage )
      {
        if ( damage >= 100
          || (pm_flags = ps->pm_flags, (pm_flags & 0x40000000) != 0)
          || (pml->groundTrace.sflags & 2) != 0 )
        {
          v14 = FLOAT_0_67000002;
        }
        else
        {
          v13 = 35 * damage + 500;
          if ( v13 <= 2000 )
          {
            if ( v13 > 500 )
            {
              if ( v13 < 1500 )
              {
                v15 = pm_flags | 0x80;
                v14 = 0.5 - (float)((float)((float)((float)v13 - 500.0) * 0.001) * 0.30000001);
              }
              else
              {
                v14 = FLOAT_0_2;
                v15 = pm_flags | 0x80;
              }
              ps->pm_time = v13;
              ps->pm_flags = v15;
            }
            else
            {
              v14 = FLOAT_0_5;
              ps->pm_time = v13;
              ps->pm_flags = pm_flags | 0x80;
            }
          }
          else
          {
            v14 = FLOAT_0_2;
            ps->pm_time = 2000;
            ps->pm_flags = pm_flags | 0x80;
          }
        }
        ps->velocity.x = ps->velocity.x * v14;
        ps->velocity.y = ps->velocity.y * v14;
        ps->velocity.z = ps->velocity.z * v14;
        v18 = damage;
        v16 = PM_DamageLandingForSurface(ps, pml);
        BG_AddPredictableEventToPlayerstate(v16, v18, ps);
      }
      else if ( fallHeight > 4.0 )
      {
        if ( fallHeight >= 8.0 )
        {
          if ( fallHeight >= 12.0 )
          {
            ps->velocity.x = ps->velocity.x * 0.67000002;
            ps->velocity.y = ps->velocity.y * 0.67000002;
            ps->velocity.z = ps->velocity.z * 0.67000002;
            v17 = PM_GroundSurfaceType(ps, pml);
            BG_AddPredictableEventToPlayerstate(v17 + 137, v10, ps);
          }
          else
          {
            BG_AddPredictableEventToPlayerstate(129, v11, ps);
          }
        }
        else
        {
          BG_AddPredictableEventToPlayerstate(130, v11, ps);
        }
      }
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x955570
int __cdecl PM_GetWaterLevel(const playerState_s *ps, float waterHeight)
{
  float standingViewHeight; // [esp+0h] [ebp-4h]
  float waterDepth; // [esp+Ch] [ebp+8h]
  float shallowWaterHeight; // [esp+10h] [ebp+Ch]

  waterDepth = waterHeight - ps->origin.z;
  standingViewHeight = (float)Dvar_GetInt(player_standingViewHeight);
  shallowWaterHeight = standingViewHeight * 0.050000001;
  if ( Dvar_GetFloat(tu6_player_shallowWaterHeight) > 0.0 )
    shallowWaterHeight = Dvar_GetFloat(tu6_player_shallowWaterHeight);
  if ( waterDepth >= standingViewHeight )
    return 6;
  if ( waterDepth >= (float)(standingViewHeight * 0.89999998) )
    return 5;
  if ( waterDepth >= (float)(standingViewHeight * 0.75) )
    return 4;
  if ( waterDepth >= 38.0 )
    return 3;
  if ( waterDepth < (float)(standingViewHeight * 0.40000001) )
    return waterDepth >= shallowWaterHeight;
  return 2;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x955660
void __usercall PM_SetWaterLevel(pmove_t *pm@<esi>)
{
  float waterHeight; // [esp+8h] [ebp-4h]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 3129, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 3130, 0, "(pm->ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  waterHeight = CM_GetWaterHeight((unsigned int)&savedregs, &pm->ps->origin, 200.0, -200.0);
  pm->ps->waterlevel = PM_GetWaterLevel(pm->ps, waterHeight);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x955710
int __cdecl PM_GetViewHeightLerpTime(const playerState_s *ps, int iTarget, int bDown)
{
  if ( iTarget == 11 )
    return 600;
  if ( iTarget == 40 )
    return bDown != 0 ? 200 : 400;
  return 200;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x955750
float __usercall PM_ViewHeightTableLerp@<xmm0>(int highVal@<eax>, int iFrac, viewLerpWaypoint_s *pTable, int lowVal)
{
  viewLerpWaypoint_s *v7; // edx
  int v8; // ecx
  viewLerpWaypoint_s *v9; // esi
  int v10; // edi
  viewLerpWaypoint_s *v11; // eax
  float fViewPercent; // xmm0_4
  float diff; // [esp+Ch] [ebp-4h]
  float actualPercent; // [esp+18h] [ebp+8h]

  if ( highVal <= lowVal
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp",
          3181,
          0,
          "(highVal > lowVal)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !iFrac )
    return (float)lowVal;
  diff = (float)(highVal - lowVal);
  actualPercent = 0.0;
  if ( iFrac >= 100
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp",
          3193,
          0,
          "(iFrac < 100)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v7 = pTable;
  v8 = pTable[1].iFrac;
  v9 = pTable + 1;
  v10 = 1;
  v11 = pTable + 1;
  while ( 1 )
  {
    if ( v8 == iFrac )
    {
      fViewPercent = v9->fViewPercent;
      goto LABEL_20;
    }
    if ( v8 > iFrac )
      break;
    v8 = v11[1].iFrac;
    ++v11;
    ++v10;
    v9 = v11;
    if ( v8 == -1 )
      goto LABEL_21;
  }
  if ( v9->iFrac - pTable[v10 - 1].iFrac <= 0 )
  {
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp",
            3213,
            0,
            "((pCurr->iFrac - pPrev->iFrac) > 0)",
            (const char *)&pBlock) )
      __debugbreak();
    v7 = pTable;
  }
  fViewPercent = (float)((float)((float)(iFrac - v7[v10 - 1].iFrac) / (float)(v9->iFrac - v7[v10 - 1].iFrac))
                       * (float)(v9->fViewPercent - v7[v10 - 1].fViewPercent))
               + v7[v10 - 1].fViewPercent;
LABEL_20:
  actualPercent = fViewPercent;
  if ( fViewPercent != 0.0 )
    return (float)(fViewPercent * diff) + (float)lowVal;
LABEL_21:
  if ( !va("No encapsulating table entries found for fraction %i", iFrac)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp",
          3228,
          0,
          "(va( \"No encapsulating table entries found for fraction %i\", iFrac ))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  fViewPercent = actualPercent;
  return (float)(fViewPercent * diff) + (float)lowVal;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x9558D0
void __cdecl PM_ViewHeightAdjust(pmove_t *pm, pml_t *pml)
{
  playerState_s *ps; // esi
  int viewHeightTarget; // ecx
  float viewHeightCurrent; // xmm0_4
  int v5; // ebx
  int v6; // eax
  int v7; // edi
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  int viewHeightLerpTarget; // edi
  int ViewHeightLerpTime; // eax
  int v14; // ecx
  float v15; // xmm0_4
  int Int; // eax
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  bool v20; // cc
  int viewHeightLerpDown; // eax
  int v22; // edi
  int v23; // eax
  int v24; // ebx
  int v25; // edx
  int v26; // ecx
  int v27; // eax
  int v28; // eax
  float v29; // xmm1_4
  int v30; // edi
  const char *v31; // eax

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 3291, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 3294, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  viewHeightTarget = ps->viewHeightTarget;
  if ( !viewHeightTarget || (viewHeightCurrent = ps->viewHeightCurrent, viewHeightCurrent == 0.0) )
  {
    if ( ps->pm_type == 5 )
      ps->viewHeightCurrent = 0.0;
    else
      ps->viewHeightCurrent = (float)viewHeightTarget;
    return;
  }
  if ( viewHeightCurrent == (float)viewHeightTarget && !ps->viewHeightLerpTime )
    return;
  v5 = 0;
  if ( Dvar_GetBool(bg_ads) && ps->viewHeightCurrent > (float)ps->viewHeightTarget )
    ps->aimSpreadScale = FLOAT_255_0;
  v6 = ps->viewHeightTarget;
  if ( v6 != 11 && v6 != 40 )
  {
    v7 = ps->viewHeightTarget;
    if ( v6 != Dvar_GetInt(player_standingViewHeight) )
    {
      v8 = ps->viewHeightCurrent;
      v9 = (float)v7;
      ps->viewHeightLerpTime = 0;
      if ( (float)v7 <= v8 )
      {
        v11 = v8 - (float)(pml->frametime * 180.0);
        ps->viewHeightCurrent = v11;
        if ( v9 >= v11 )
          ps->viewHeightCurrent = v9;
      }
      else
      {
        v10 = (float)(pml->frametime * 180.0) + v8;
        ps->viewHeightCurrent = v10;
        if ( v10 >= v9 )
          ps->viewHeightCurrent = v9;
      }
      return;
    }
  }
  if ( ps->viewHeightLerpTime )
  {
    viewHeightLerpTarget = ps->viewHeightLerpTarget;
    ViewHeightLerpTime = PM_GetViewHeightLerpTime(ps, viewHeightLerpTarget, ps->viewHeightLerpDown);
    v5 = 100 * (pm->cmd.serverTime - v14) / ViewHeightLerpTime;
    if ( v5 < 0 )
    {
      v5 = 0;
      goto LABEL_25;
    }
    if ( v5 <= 100 )
    {
      if ( v5 != 100 )
      {
LABEL_25:
        if ( viewHeightLerpTarget == 11 )
        {
          v15 = PM_ViewHeightTableLerp(40, v5, viewLerp_CrouchProne, 11);
        }
        else if ( viewHeightLerpTarget == 40 )
        {
          if ( ps->viewHeightLerpDown )
          {
            Int = Dvar_GetInt(player_standingViewHeight);
            v15 = PM_ViewHeightTableLerp(Int, v5, viewLerp_StandCrouch, 40);
          }
          else
          {
            v15 = PM_ViewHeightTableLerp(40, v5, viewLerp_ProneCrouch, 11);
          }
        }
        else
        {
          v17 = Dvar_GetInt(player_standingViewHeight);
          v15 = PM_ViewHeightTableLerp(v17, v5, viewLerp_CrouchStand, 40);
        }
LABEL_38:
        ps->viewHeightCurrent = v15;
        goto LABEL_39;
      }
    }
    else
    {
      v5 = 100;
    }
    if ( ps->pm_type == 9 )
      ps->pm_type = 0;
    v15 = (float)viewHeightLerpTarget;
    ps->viewHeightLerpTime = 0;
    goto LABEL_38;
  }
LABEL_39:
  v18 = ps->viewHeightTarget;
  if ( ps->viewHeightLerpTime )
  {
    v19 = ps->viewHeightLerpTarget;
    v20 = v18 <= v19;
    if ( v18 == v19 )
      return;
    if ( v18 < v19 )
    {
      viewHeightLerpDown = ps->viewHeightLerpDown;
      if ( !viewHeightLerpDown )
      {
LABEL_46:
        v22 = 100 - v5;
        v23 = viewHeightLerpDown ^ 1;
        ps->viewHeightLerpDown = v23;
        if ( v23 )
        {
          v24 = ps->viewHeightLerpTarget;
          if ( v24 == Dvar_GetInt(player_standingViewHeight) )
          {
            ps->viewHeightLerpTarget = 40;
          }
          else if ( v24 == 40 )
          {
            ps->viewHeightLerpTarget = 11;
          }
        }
        else if ( v19 == 11 )
        {
          ps->viewHeightLerpTarget = 40;
        }
        else if ( v19 == 40 )
        {
          ps->viewHeightLerpTarget = Dvar_GetInt(player_standingViewHeight);
        }
        if ( v22 == 100 )
        {
          *(_QWORD *)&ps->viewHeightCurrent = COERCE_UNSIGNED_INT((float)ps->viewHeightLerpTarget);
        }
        else
        {
          ps->viewHeightLerpTime = pm->cmd.serverTime
                                 - (int)(float)((float)PM_GetViewHeightLerpTime(
                                                         ps,
                                                         ps->viewHeightLerpTarget,
                                                         ps->viewHeightLerpDown)
                                              * (float)((float)v22 * 0.0099999998));
          if ( v26 == 11 )
          {
            PM_ViewHeightTableLerp(40, v22, viewLerp_CrouchProne, 11);
          }
          else if ( v26 == 40 )
          {
            if ( v25 )
            {
              v27 = Dvar_GetInt(player_standingViewHeight);
              PM_ViewHeightTableLerp(v27, v22, viewLerp_StandCrouch, 40);
            }
            else
            {
              PM_ViewHeightTableLerp(40, v22, viewLerp_ProneCrouch, 11);
            }
          }
          else
          {
            v28 = Dvar_GetInt(player_standingViewHeight);
            PM_ViewHeightTableLerp(v28, v22, viewLerp_CrouchStand, 40);
          }
        }
        return;
      }
      v20 = v18 <= v19;
    }
    if ( v20 )
      return;
    viewHeightLerpDown = ps->viewHeightLerpDown;
    if ( !viewHeightLerpDown )
      return;
    goto LABEL_46;
  }
  v29 = ps->viewHeightCurrent;
  if ( v29 == (float)v18 )
    return;
  ps->viewHeightLerpTime = pm->cmd.serverTime;
  if ( v18 == 11 )
  {
    ps->viewHeightLerpDown = 1;
    if ( v29 <= 40.0 )
    {
      ps->viewHeightLerpTarget = 11;
      return;
    }
    goto LABEL_73;
  }
  if ( v18 == 40 )
  {
    if ( ps->viewHeightCurrent > (float)40 )
    {
      ps->viewHeightLerpDown = 1;
      ps->viewHeightLerpTarget = 40;
      return;
    }
    ps->viewHeightLerpDown = 0;
    goto LABEL_73;
  }
  v30 = ps->viewHeightTarget;
  if ( v30 == Dvar_GetInt(player_standingViewHeight) )
  {
    v20 = ps->viewHeightCurrent >= 40.0;
    ps->viewHeightLerpDown = 0;
    if ( v20 )
    {
      ps->viewHeightLerpTarget = Dvar_GetInt(player_standingViewHeight);
      return;
    }
LABEL_73:
    ps->viewHeightLerpTarget = 40;
    return;
  }
  v31 = va("View height lerp to %i reached bad place\n", v30);
  if ( !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 3476, 0, (const char *)&pBlock, v31) )
    __debugbreak();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x955E00
bool __cdecl PlayerProneAllowed(pmove_t *pm)
{
  playerState_s *ps; // esi
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 3488, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 3490, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  return !BG_WeaponBlocksProne(pm->ps->weapon)
      && ((ps->pm_flags & 1) != 0
       || ps->groundEntityNum != 1023
       && pm->ps->waterlevel < 1
       && BG_CheckProne(
            (unsigned int)&savedregs,
            ps,
            ps->clientNum,
            &ps->origin,
            pm->maxs.x,
            30.0,
            ps->viewangles.y,
            &ps->fTorsoPitch,
            &ps->fWaistPitch,
            0,
            1,
            1,
            pm->handler,
            PCT_CLIENT,
            50.0));
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x955F10
bool __thiscall PM_IsPlayerFrozenByWeapon(const playerState_s *ps)
{
  int weaponstate; // eax

  weaponstate = ps->weaponstate;
  return (weaponstate == 6
       || weaponstate == 7
       || weaponstate == 8
       || weaponstate == 40
       || weaponstate == 19
       || weaponstate == 20
       || weaponstate == 21)
      && *(_BYTE *)&ps->weapon.0
      && BG_GetWeaponDef(ps->weapon)->freezeMovementWhenFiring;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x955F60
bool __usercall PM_ShouldLeaveStanceAlone@<al>(const playerState_s *ps@<esi>)
{
  return (ps->pm_flags & 0xC00) != 0
      || (ps->otherFlags & 0x400) != 0
      || PM_IsPlayerFrozenByWeapon(ps)
      || ps->weaponstate == 44
      || ps->vehicleState.entity != 1023;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x956060
BOOL __cdecl PM_ShouldMakeFootsteps(pmove_t *pm)
{
  return (pm->ps->bobCycle & 0x7Fu) >= 0x40
      && pm->ps->waterlevel < 5
      && pm->xyspeed >= Dvar_GetFloat(player_footstepsThreshhold);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x9560B0
int __usercall PM_Footsteps_TurnAnim@<eax>(clientInfo_t *ci@<esi>, pmove_t *pm)
{
  bool Bool; // bl
  int turnAnimEndTime; // eax
  __m128 v4; // xmm3
  __m128 v5; // xmm0
  __m128 v6; // xmm1
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  float v10; // xmm0_4
  int result; // eax
  unsigned int v12; // ecx

  Bool = Dvar_GetBool(xanim_debug);
  if ( ci->turnAnimType )
  {
    turnAnimEndTime = ci->turnAnimEndTime;
    if ( turnAnimEndTime )
    {
      if ( Bool )
        Com_DPrintf(
          27,
          "turn anim end time is %i, time is %i\n",
          turnAnimEndTime,
          *(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960) + 16));
    }
  }
  if ( ci->legs.yawing )
  {
    v4.m128_f32[0] = FLOAT_8388608_0;
    v5 = (__m128)COERCE_UNSIGNED_INT((float)pm->oldcmd.angles[1]);
    v5.m128_f32[0] = (float)((float)(v5.m128_f32[0] * 0.0054931641) - (float)((float)pm->cmd.angles[1] * 0.0054931641))
                   * 0.0027777778;
    v6 = v5;
    v6.m128_f32[0] = v5.m128_f32[0] + 0.5;
    v7 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v6);
    v4.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v6, v7), v4).m128_u32[0] | v7.m128_i32[0];
    v8 = v6;
    v8.m128_f32[0] = (float)((float)(v5.m128_f32[0] + 0.5) + v4.m128_f32[0]) - v4.m128_f32[0];
    v9 = v8;
    v9.m128_f32[0] = v8.m128_f32[0] - (float)(v5.m128_f32[0] + 0.5);
    v10 = (float)(v5.m128_f32[0] - (float)(v8.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v9, v7).m128_u32[0] & FLOAT_1_0)))
        * 360.0;
    if ( v10 <= 0.0 )
    {
      result = 2;
      if ( v10 >= 0.0 )
        result = ci->turnAnimType;
    }
    else
    {
      result = 1;
    }
    v12 = _tls_index;
    ci->turnAnimType = result;
    ci->turnAnimEndTime = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v12) + 14960)
                                    + 16)
                        + 100;
  }
  else
  {
    if ( ci->turnAnimEndTime )
    {
      ci->turnAnimEndTime = 0;
      if ( Bool )
        Com_Printf(
          27,
          "[%i] playing idle anim after turn anim\n",
          *(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960) + 16));
    }
    return 0;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x956240
BOOL __usercall PM_ShouldFlinch@<eax>(playerState_s *ps@<esi>)
{
  int v1; // ecx

  if ( (float)ps->viewHeightTarget != ps->viewHeightCurrent
    || BG_GetWeaponDef(ps->weapon)->weapType == WEAPTYPE_RIOTSHIELD
    || (ps->weapFlags & 0x400000) != 0 )
  {
    return 0;
  }
  v1 = ps->damageDuration - Dvar_GetInt(player_dmgtimer_flinchTime);
  if ( v1 < 0 )
    v1 = 0;
  return ps->damageTimer > v1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x9562B0
char __usercall PM_Footstep_LadderMove@<al>(pmove_t *pm@<edi>, pml_t *pml)
{
  playerState_s *ps; // esi
  int pm_flags; // eax
  float z; // xmm1_4
  float v5; // xmm0_4
  int bobCycle; // ecx
  float v7; // xmm0_4

  ps = pm->ps;
  pm_flags = pm->ps->pm_flags;
  if ( (pm_flags & 8) == 0 )
    return 0;
  if ( pm->cmd.serverTime - ps->jumpTime >= 300 )
  {
    z = ps->velocity.z;
    if ( (pm_flags & 0x40) != 0 || ps->leanf != 0.0 )
      v5 = (float)(z * 0.026246719) * 0.34999999;
    else
      v5 = (float)(z * 0.010498688) * 0.44999999;
    if ( z < 0.0 )
      BG_AnimScriptAnimation(pm, AISTATE_COMBAT, ANIM_MT_CLIMBDOWN, 0);
    else
      BG_AnimScriptAnimation(pm, AISTATE_COMBAT, ANIM_MT_CLIMBUP, 1);
    bobCycle = ps->bobCycle;
    v7 = (float)((float)pml->msec * v5) + (float)bobCycle;
    ps->bobCycle = (unsigned __int8)(int)v7;
    if ( (pm->ps->bobCycle & 0x7Fu) < 0x40 )
    {
      PM_FootstepEvent(pm, pml, bobCycle, (unsigned __int8)(int)v7, 0);
      return 1;
    }
    PM_FootstepEvent(pm, pml, bobCycle, (unsigned __int8)(int)v7, pm->ps->waterlevel < 5);
  }
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x9563C0
void __cdecl PM_Footsteps_NotMoving(pmove_t *pm, pml_t *pml, int stance)
{
  playerState_s *ps; // edi
  int clientNum; // esi
  clientInfo_t *v6; // esi
  int v7; // eax
  scriptAnimMoveTypes_t v8; // ecx
  int v9; // esi
  bool v10; // sf
  int v11; // eax
  scriptAnimMoveTypes_t anim; // [esp+0h] [ebp-4h]
  clientInfo_t *ci; // [esp+Ch] [ebp+8h]

  ps = pm->ps;
  if ( pm->xyspeed < 1.0 && !BG_WeaponUsedOnVehicle(ps->eFlags) && ps->waterlevel < 4 )
    ps->bobCycle = 0;
  clientNum = ps->clientNum;
  if ( clientNum >= Dvar_GetInt((const dvar_t *)com_maxclients.inaddr) )
  {
    ci = 0;
  }
  else
  {
    v6 = (clientInfo_t *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
                        + 2056 * clientNum
                        + 152);
    ci = v6;
    if ( v6 && Dvar_GetBool(player_turnAnims) && (ps->pm_flags & 4) == 0 )
    {
      v7 = PM_Footsteps_TurnAnim(v6, pm);
      goto LABEL_12;
    }
  }
  v7 = 0;
LABEL_12:
  v8 = movetype[v7];
  anim = v8;
  if ( ps->waterlevel >= 4 )
  {
    BG_AnimScriptAnimation(pm, AISTATE_COMBAT, ANIM_MT_SWIM, 0);
    return;
  }
  if ( v7 )
  {
    v9 = BG_AnimScriptAnimation(pm, AISTATE_COMBAT, v8, 0);
    v10 = v9 < 0;
    if ( v9 <= 0 )
      goto LABEL_28;
    if ( !ci->turnAnimEndTime )
    {
      if ( ps->legsAnimDuration <= 0
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp",
              4417,
              0,
              "(ps->legsAnimDuration > 0)",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      ci->turnAnimEndTime = ps->legsAnimDuration
                          + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index)
                                                  + 14960)
                                      + 16);
      if ( Dvar_GetBool(xanim_debug) )
      {
        v11 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960) + 16);
        Com_Printf(27, "[%i] turn anim should end at %i\n", v11, v11 + ps->legsAnimDuration);
      }
    }
  }
  else
  {
    if ( (_BYTE)stance )
    {
      if ( PM_ShouldFlinch(ps) )
      {
        BG_AnimScriptEvent(pm, ANIM_ET_FLINCH, 1, 0, &pml->holdrand);
        return;
      }
      v8 = anim;
    }
    v9 = BG_AnimScriptAnimation(pm, AISTATE_COMBAT, v8, 0);
  }
  v10 = v9 < 0;
LABEL_28:
  if ( v10 )
  {
    if ( (_BYTE)stance && PM_ShouldFlinch(ps) )
      BG_AnimScriptEvent(pm, ANIM_ET_FLINCH, 1, 1, &pml->holdrand);
    else
      BG_AnimScriptAnimation(pm, AISTATE_COMBAT, ANIM_MT_IDLE, 0);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x9565F0
int __usercall PM_GetMoveAnim@<eax>(
        playerState_s *ps@<edi>,
        PmStanceFrontBack stance@<esi>,
        pml_t *pml,
        int walking,
        int sprinting)
{
  int v5; // ecx
  BOOL v6; // ecx
  int result; // eax

  v5 = ps->damageDuration - Dvar_GetInt(player_dmgtimer_stumbleTime);
  if ( v5 < 0 )
    v5 = 0;
  v6 = ps->damageTimer > v5;
  result = moveAnimTable[0][2 * stance][2 * stance + 2 * walking + v6];
  if ( stance == PM_STANCE_STAND && sprinting )
    result = v6 ? 23 : 7;
  if ( (ps->pm_flags & 0x200000) != 0 )
    result = 25;
  if ( (pml->groundTrace.sflags & 2) != 0 )
    result = 26;
  if ( ps->waterlevel >= 4 )
    return 24;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x956670
void __usercall PM_Footstep_NotTryingToMove(pmove_t *pm@<edi>, pml_t *pml)
{
  playerState_s *ps; // esi

  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 4654, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( pm->xyspeed <= 120.0 )
  {
    if ( ps->waterlevel < 4 )
    {
      if ( PM_ShouldFlinch(ps) )
        BG_AnimScriptEvent(pm, ANIM_ET_FLINCH, 1, 0, &pml->holdrand);
      else
        BG_AnimScriptAnimation(pm, AISTATE_COMBAT, ANIM_MT_IDLE, 0);
    }
    else
    {
      BG_AnimScriptAnimation(pm, AISTATE_COMBAT, ANIM_MT_SWIM, 0);
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x956700
void __usercall PM_VehicleDrive(pmove_t *pm@<esi>)
{
  playerState_s *ps; // edi

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 4687, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = pm->ps;
  if ( (pm->ps->eFlags & 0x4000) != 0 && ps->viewlocked_entNum != 1023 && !ps->vehiclePos )
  {
    if ( !*(&funcs_9567A0 + 9 * pm->handler)
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp",
            4692,
            0,
            "(pmoveHandlers[pm->handler].setVehDriverInputs)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    (*(&funcs_9567A0 + 9 * pm->handler))((const LocalClientNum_t)pm->localClientNum, ps, &pm->cmd);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x9567B0
int __usercall BG_CalcBob@<eax>(pmove_t *pm@<eax>, pml_t *pml@<edi>, int old@<esi>, float bobmove)
{
  playerState_s *ps; // ecx
  int pm_flags; // eax
  float v6; // xmm0_4
  int v7; // eax

  ps = pm->ps;
  pm_flags = pm->ps->pm_flags;
  if ( (pm_flags & 0x200000) != 0 )
  {
    v6 = (float)((float)pml->msec * bobmove) * BG_GetWeaponDef(ps->weapon)->fDtpCycleScale;
  }
  else
  {
    v7 = pm_flags & 0x8000;
    if ( v7 && ps->viewHeightTarget == 40 )
    {
      v6 = (float)((float)pml->msec * bobmove) * BG_GetWeaponDef(ps->weapon)->fDuckedSprintCycleScale;
    }
    else if ( (!v7 || ((unsigned int)&g_sd.voiceDecodeBuffer[774848] & ps->weapFlags) != 0) && ps->waterlevel < 4 )
    {
      v6 = (float)pml->msec * bobmove;
    }
    else
    {
      v6 = (float)((float)pml->msec * bobmove) * BG_GetWeaponDef(ps->weapon)->fSprintCycleScale;
    }
  }
  return (unsigned __int8)(int)(float)(v6 + (float)old);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x956890
void __usercall PM_ApplyMovementAnimations(
        PmStanceFrontBack stanceFrontBack@<esi>,
        pmove_t *pm,
        pml_t *pml,
        int walking,
        int sprinting)
{
  playerState_s *ps; // edi
  int MoveAnim; // eax
  int v7; // eax

  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 4715, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  MoveAnim = PM_GetMoveAnim(ps, stanceFrontBack, pml, walking, sprinting);
  if ( sprinting )
    v7 = BG_AnimScriptAnimation(pm, AISTATE_COMBAT, (scriptAnimMoveTypes_t)MoveAnim, 1);
  else
    v7 = BG_AnimScriptAnimation(pm, AISTATE_COMBAT, (scriptAnimMoveTypes_t)MoveAnim, 0);
  if ( v7 < 0 )
    BG_AnimScriptAnimation(pm, AISTATE_COMBAT, ANIM_MT_IDLE, 0);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x956910
void __usercall PM_ApplyLegAnimations(pmove_t *pm@<eax>, pml_t *pml, int iStance)
{
  playerState_s *ps; // edi

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 4742, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 4745, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( pml->almostGroundPlane && !pml->walking && (ps->pm_flags & 4) == 0 && !ps->pm_type )
  {
    if ( Dvar_GetFloat(player_moveThreshhold) <= pm->xyspeed )
      PM_ApplyMovementAnimations((PmStanceFrontBack)iStance, pm, pml, 1, 0);
    else
      PM_Footsteps_NotMoving(pm, pml, 0);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x9569D0
float __usercall PM_CalcPlayerPitch@<xmm0>(pml_t *pml@<esi>, playerState_s *ps)
{
  long double v3; // st7
  __m128 v4; // xmm0
  __m128 x_low; // xmm0
  __m128 v6; // xmm3
  __m128 v7; // xmm1
  __m128 v8; // xmm4
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  float yawTrans; // [esp+8h] [ebp-24h]
  float diff; // [esp+Ch] [ebp-20h]
  float diffa; // [esp+Ch] [ebp-20h]
  vec3_t groundTrace; // [esp+10h] [ebp-1Ch] BYREF
  vec3_t groundNormAngles; // [esp+1Ch] [ebp-10h] BYREF

  diff = AngleNormalize360(ps->viewangles.y);
  if ( !pml->groundPlane )
    return 0.0;
  *(_QWORD *)&groundTrace.x = pml->groundTrace.normal.vec.m128_u64[0];
  LODWORD(groundTrace.z) = pml->groundTrace.normal.vec.m128_i32[2];
  vectoangles(&groundTrace, &groundNormAngles);
  yawTrans = AngleNormalize360(groundNormAngles.y);
  v3 = fabs(AngleDelta(diff, yawTrans));
  if ( v3 >= 35.0 )
  {
    diffa = v3;
    if ( diffa <= 145.0 )
    {
      x_low = 0i64;
    }
    else
    {
      x_low = (__m128)LODWORD(groundNormAngles.x);
      x_low.m128_f32[0] = groundNormAngles.x + 90.0;
    }
  }
  else
  {
    v4 = (__m128)LODWORD(groundNormAngles.x);
    v4.m128_f32[0] = groundNormAngles.x + 90.0;
    x_low = _mm_xor_ps(v4, (__m128)_mask__NegFloat_);
  }
  x_low.m128_f32[0] = x_low.m128_f32[0] * 0.0027777778;
  v6.m128_f32[0] = FLOAT_8388608_0;
  v7 = x_low;
  v7.m128_f32[0] = x_low.m128_f32[0] + 0.5;
  v8 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v7);
  v6.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v7, v8), v6).m128_u32[0] | v8.m128_i32[0];
  v9 = v7;
  v9.m128_f32[0] = (float)((float)(x_low.m128_f32[0] + 0.5) + v6.m128_f32[0]) - v6.m128_f32[0];
  v10 = v9;
  v10.m128_f32[0] = v9.m128_f32[0] - (float)(x_low.m128_f32[0] + 0.5);
  return (float)(x_low.m128_f32[0]
               - (float)(v9.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v10, v8).m128_u32[0] & FLOAT_1_0)))
       * 360.0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x956B40
bool __usercall PM_IsInAir@<al>(pmove_t *pm@<eax>, pml_t *pml)
{
  playerState_s *ps; // esi
  bool result; // al
  int pm_type; // esi

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 4817, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = pm->ps;
  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 4819, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  result = ps->groundEntityNum == 1023
        && (pm_type = ps->pm_type, pm_type != 1)
        && pm_type != 7
        && pml->almostGroundPlane == 0;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x956BC0
void __usercall PM_DropTimers(playerState_s *ps@<esi>, pml_t *pml@<edi>)
{
  int pm_flags; // eax
  int msec; // ecx
  int pm_time; // eax
  int legsTimer; // eax
  int v6; // eax
  int torsoTimer; // eax
  int v8; // eax
  ClientNum_t clientNum; // [esp-4h] [ebp-8h]
  ClientNum_t v10; // [esp-4h] [ebp-8h]

  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 5073, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( ps->pm_time )
  {
    pm_flags = ps->pm_flags;
    if ( ((unsigned int)&g_npPool[24648] & pm_flags) != 0 && ps->groundEntityNum == 1022 )
    {
      ps->pm_flags = pm_flags & 0xF7FFFFFF;
      ps->pm_time = 0;
    }
    msec = pml->msec;
    pm_time = ps->pm_time;
    if ( msec < pm_time )
    {
      ps->pm_time = pm_time - msec;
    }
    else
    {
      if ( (ps->pm_flags & 0x4000) != 0 )
        Jump_ClearState(ps);
      ps->pm_flags &= 0xF7FFBE7F;
      ps->pm_time = 0;
    }
  }
  legsTimer = ps->legsTimer;
  if ( legsTimer > 0 )
  {
    v6 = legsTimer - pml->msec;
    ps->legsTimer = v6;
    if ( v6 < 0 )
    {
      clientNum = ps->clientNum;
      ps->legsTimer = 0;
      if ( G_IsServerGameSystem(clientNum) )
        Com_Printf(18, "end legs\n");
    }
  }
  torsoTimer = ps->torsoTimer;
  if ( torsoTimer > 0 )
  {
    v8 = torsoTimer - pml->msec;
    ps->torsoTimer = v8;
    if ( v8 < 0 )
    {
      v10 = ps->clientNum;
      ps->torsoTimer = 0;
      if ( G_IsServerGameSystem(v10) )
        Com_Printf(18, "end torso\n");
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x956CC0
int __usercall BG_CheckProneTurned@<eax>(playerState_s *ps@<esi>, float newProneYaw, unsigned __int8 handler)
{
  float fraction; // [esp+2Ch] [ebp-8h]
  float delta; // [esp+30h] [ebp-4h]
  int savedregs; // [esp+34h] [ebp+0h] BYREF
  float testYaw; // [esp+3Ch] [ebp+8h]

  delta = AngleDelta(newProneYaw, ps->viewangles.y);
  fraction = COERCE_FLOAT(LODWORD(delta) & _mask__AbsFloat_) * 0.0041666669;
  testYaw = AngleNormalize360(newProneYaw - (float)((float)(1.0 - fraction) * delta));
  return (unsigned __int8)BG_CheckProne(
                            (unsigned int)&savedregs,
                            ps,
                            ps->clientNum,
                            &ps->origin,
                            15.0,
                            30.0,
                            testYaw,
                            &ps->fTorsoPitch,
                            &ps->fWaistPitch,
                            1,
                            ps->groundEntityNum != 1023,
                            1,
                            handler,
                            PCT_CLIENT,
                            (float)((float)(1.0 - fraction) * 50.0) + (float)(PRONE_FEET_DIST_TURNED * fraction));
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x956DD0
void __cdecl PM_UpdateViewLockedEnt(LocalClientNum_t localClientNum, usercmd_s *cmd)
{
  playerState_s *ps; // ecx
  playerState_s *v3; // esi
  int Int; // edi
  float v5; // xmm0_4
  float v6; // xmm3_4
  int v7; // edi
  const float *p_x; // esi
  double v9; // st7
  vec3_t angles; // [esp+14h] [ebp-34h] BYREF
  vec3_t lookAngles; // [esp+20h] [ebp-28h] BYREF
  vec3_t origin; // [esp+2Ch] [ebp-1Ch] BYREF
  vec3_t dir; // [esp+38h] [ebp-10h] BYREF

  v3 = ps;
  Int = Dvar_GetInt(player_viewLockEnt);
  if ( !v3
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 5307, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( Int )
  {
    (*(&funcs_953EF4 + 9 * (unsigned __int8)cmd))(localClientNum, Int, &origin, &angles);
    v5 = v3->viewHeightCurrent + v3->origin.z;
    v6 = origin.x - v3->origin.x;
    dir.y = origin.y - v3->origin.y;
    dir.x = v6;
    dir.z = origin.z - v5;
    vectoangles(&dir, &lookAngles);
    v7 = 0;
    p_x = &v3->viewangles.x;
    do
    {
      v9 = AngleDelta(*((const float *)&lookAngles.x + v7++), *p_x);
      *((float *)p_x - 88) = v9 + *(p_x - 88);
      *((float *)++p_x - 1) = *(&angles.z + v7);
    }
    while ( v7 < 2 );
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x956EE0
void __usercall PM_UpdateViewAngles_Clamp(playerState_s *ps@<esi>, usercmd_s *cmd@<edi>)
{
  int i; // eax
  __m128 v3; // xmm3
  __m128 v4; // xmm1
  __m128 v5; // xmm4
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  float v11; // xmm1_4
  __m128 v12; // xmm4
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  float minPitch; // [esp+0h] [ebp-8h]
  float maxPitch; // [esp+4h] [ebp-4h]

  minPitch = Dvar_GetFloat(player_view_pitch_up);
  maxPitch = Dvar_GetFloat(player_view_pitch_down);
  for ( i = 0; i < 2; ++i )
  {
    v3.m128_f32[0] = FLOAT_8388608_0;
    v8 = (__m128)COERCE_UNSIGNED_INT((float)cmd->angles[i]);
    v8.m128_f32[0] = (float)((float)(v8.m128_f32[0] * 0.0054931641) + *(&ps->delta_angles.x + i)) * 0.0027777778;
    v4 = v8;
    v4.m128_f32[0] = v8.m128_f32[0] + 0.5;
    v5 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v4);
    v3.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v4, v5), v3).m128_u32[0] | v5.m128_i32[0];
    v6 = v4;
    v6.m128_f32[0] = (float)((float)(v8.m128_f32[0] + 0.5) + v3.m128_f32[0]) - v3.m128_f32[0];
    v7 = v6;
    v7.m128_f32[0] = v6.m128_f32[0] - (float)(v8.m128_f32[0] + 0.5);
    v8.m128_f32[0] = (float)(v8.m128_f32[0]
                           - (float)(v6.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v7, v5).m128_u32[0] & FLOAT_1_0)))
                   * 360.0;
    if ( !i )
    {
      v9 = (__m128)LODWORD(maxPitch);
      if ( v8.m128_f32[0] > maxPitch
        || (v9 = _mm_xor_ps((__m128)LODWORD(minPitch), (__m128)_mask__NegFloat_), v9.m128_f32[0] > v8.m128_f32[0]) )
      {
        v8 = v9;
        ps->delta_angles.x = v9.m128_f32[0] - (float)((float)cmd->angles[0] * 0.0054931641);
      }
    }
    v10.m128_f32[0] = FLOAT_8388608_0;
    v11 = v8.m128_f32[0] * 0.0027777778;
    v8.m128_f32[0] = (float)(v8.m128_f32[0] * 0.0027777778) + 0.5;
    v12 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v8);
    v10.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v8, v12), v10).m128_u32[0] | v12.m128_i32[0];
    v13 = v8;
    v13.m128_f32[0] = (float)(v8.m128_f32[0] + v10.m128_f32[0]) - v10.m128_f32[0];
    v14 = v13;
    v14.m128_f32[0] = v13.m128_f32[0] - v8.m128_f32[0];
    *(&ps->viewangles.x + i) = (float)(v11
                                     - (float)(v13.m128_f32[0]
                                             - COERCE_FLOAT(_mm_cmpgt_ss(v14, v12).m128_u32[0] & FLOAT_1_0)))
                             * 360.0;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x957060
void __cdecl PM_UpdateViewAngles_RangeLimited(playerState_s *ps)
{
  float delta; // [esp+10h] [ebp-8h]
  float deltaa; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    if ( ps->viewAngleClampRange.v[i] < 180.0 )
    {
      delta = AngleDelta(ps->viewAngleClampBase.v[i], *((const float *)&ps->viewangles.x + i));
      if ( delta > ps->viewAngleClampRange.v[i]
        || COERCE_FLOAT(LODWORD(ps->viewAngleClampRange.v[i]) ^ _mask__NegFloat_) > delta )
      {
        if ( delta <= ps->viewAngleClampRange.v[i] )
          deltaa = delta + ps->viewAngleClampRange.v[i];
        else
          deltaa = delta - ps->viewAngleClampRange.v[i];
        *(&ps->delta_angles.x + i) = *(&ps->delta_angles.x + i) + deltaa;
        if ( deltaa <= 0.0 )
          *(&ps->viewangles.x + i) = AngleNormalize360(ps->viewAngleClampBase.v[i] + ps->viewAngleClampRange.v[i]);
        else
          *(&ps->viewangles.x + i) = AngleNormalize360(ps->viewAngleClampBase.v[i] - ps->viewAngleClampRange.v[i]);
      }
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x957200
void __usercall PM_UpdateViewAngles_LadderClamp(playerState_s *ps@<esi>)
{
  double v1; // st7
  float v2; // xmm0_4
  float v3; // xmm0_4
  float ladderFacing; // [esp+8h] [ebp-Ch]
  float ladder_yawcap; // [esp+Ch] [ebp-8h]
  float delta; // [esp+10h] [ebp-4h]

  ladder_yawcap = Dvar_GetFloat(bg_ladder_yawcap);
  ladderFacing = vectoyaw((const vec2_t *)&ps->vLadderVec) + 180.0;
  v1 = AngleDelta(ladderFacing, ps->viewangles.y);
  delta = v1;
  if ( v1 > ladder_yawcap )
    goto LABEL_4;
  if ( COERCE_FLOAT(LODWORD(ladder_yawcap) ^ _mask__NegFloat_) <= delta )
    return;
  if ( delta <= ladder_yawcap )
    v2 = delta + ladder_yawcap;
  else
LABEL_4:
    v2 = delta - ladder_yawcap;
  ps->delta_angles.y = ps->delta_angles.y + v2;
  if ( v2 <= 0.0 )
    v3 = ladderFacing + ladder_yawcap;
  else
    v3 = ladderFacing - ladder_yawcap;
  ps->viewangles.y = AngleNormalize360(v3);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlsassociation.cpp:0x9572D0
void __usercall PM_UpdateViewAngles_ProneYawClamp(
        playerState_s *ps@<esi>,
        float delta,
        int proneBlocked,
        float oldViewYaw,
        float newViewYaw)
{
  double Float; // st7
  float v6; // xmm1_4
  float proneDirection; // xmm0_4
  float angle; // xmm0_4
  double v9; // st7
  float prone_yawcap; // [esp+8h] [ebp-4h]
  float deltaYaw1; // [esp+10h] [ebp+4h]

  Float = Dvar_GetFloat(bg_prone_yawcap);
  prone_yawcap = Float;
  if ( delta > Float )
    goto LABEL_4;
  if ( COERCE_FLOAT(LODWORD(prone_yawcap) ^ _mask__NegFloat_) <= delta )
    goto LABEL_10;
  if ( delta <= prone_yawcap )
    v6 = prone_yawcap + delta;
  else
LABEL_4:
    v6 = delta - prone_yawcap;
  ps->delta_angles.y = ps->delta_angles.y + v6;
  proneDirection = ps->proneDirection;
  if ( v6 <= 0.0 )
    angle = proneDirection + prone_yawcap;
  else
    angle = proneDirection - prone_yawcap;
  ps->viewangles.y = AngleNormalize360(angle);
LABEL_10:
  if ( proneBlocked )
  {
    ps->pm_flags |= 0x1000u;
    if ( ps->pm_type != 7 )
      BG_AddPredictableEventToPlayerstate(234, 3u, ps);
    v9 = AngleDelta(oldViewYaw, ps->viewangles.y);
    deltaYaw1 = v9;
    if ( fabs(v9) <= 1.0 && AngleDelta(newViewYaw, ps->viewangles.y) * deltaYaw1 > 0.0 )
    {
      ps->viewangles.y = AngleNormalize360(ps->viewangles.y + (float)(deltaYaw1 * 0.98000002));
      ps->delta_angles.y = ps->delta_angles.y + (float)(deltaYaw1 * 0.98000002);
    }
  }
}

#endif // __UNIMPLEMENTED__
