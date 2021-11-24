// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdnattraversalpacket.cpp:0x9596B0
float __usercall PM_CmdScale_Walk@<xmm0>(usercmd_s *cmd@<eax>, pmove_t *pm)
{
  playerState_s *ps; // esi
  bool v4; // bl
  char forwardmove; // al
  long double v6; // st7
  float v7; // xmm2_4
  float result; // xmm0_4
  int pm_flags; // ecx
  float v10; // xmm1_4
  int pm_type; // eax
  int waterlevel; // eax
  float v13; // xmm0_4
  Weapon v14; // eax
  double Float; // st7
  Weapon v16; // eax
  const WeaponDef *WeaponDef; // eax
  float total; // [esp+Ch] [ebp-Ch]
  float smove; // [esp+10h] [ebp-8h]
  float scale; // [esp+14h] [ebp-4h]
  float scalea; // [esp+14h] [ebp-4h]
  float scaleb; // [esp+14h] [ebp-4h]

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 1520, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 1522, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v4 = (ps->pm_flags & 1) != 0 && ps->fWeaponPosFrac > 0.0;
  forwardmove = cmd->forwardmove;
  total = fsqrt((float)(cmd->rightmove * cmd->rightmove + forwardmove * forwardmove));
  if ( forwardmove >= 0 )
    LODWORD(scale) = COERCE_UNSIGNED_INT((float)forwardmove) & _mask__AbsFloat_;
  else
    scale = fabs(Dvar_GetFloat(player_backSpeedScale) * (double)cmd->forwardmove);
  v6 = fabs(Dvar_GetFloat(player_strafeSpeedScale) * (double)cmd->rightmove);
  if ( scale - v6 < 0.0 )
  {
    smove = v6;
    v7 = smove;
  }
  else
  {
    v7 = scale;
  }
  result = 0.0;
  if ( v7 != 0.0 )
  {
    pm_flags = ps->pm_flags;
    v10 = (float)((float)ps->speed * v7) / (float)(total * 127.0);
    scalea = v10;
    if ( (pm_flags & 0x40) != 0 || ps->leanf != 0.0 || v4 )
    {
      v10 = v10 * 0.40000001;
      scalea = v10;
    }
    if ( (pm_flags & 0x8000) != 0 )
    {
      if ( ps->viewHeightTarget == Dvar_GetInt(player_standingViewHeight) )
        scalea = BG_GetSprintSpeedScale() * scalea;
      v10 = scalea;
    }
    pm_type = ps->pm_type;
    if ( pm_type == 2 )
    {
      scaleb = v10 * 3.0;
    }
    else if ( pm_type == 3 )
    {
      scaleb = v10 * 6.0;
    }
    else
    {
      PM_CmdScaleForStance(pm);
      waterlevel = ps->waterlevel;
      v13 = 0.0 * scalea;
      scaleb = 0.0 * scalea;
      if ( waterlevel >= 1 )
        scaleb = (float)(1.0 - (float)((float)((float)waterlevel * 0.33333334) * 0.39999998)) * v13;
    }
    if ( Com_BitCheckAssert(ps->perks, 42, 0xFFFFFFF) > 0
      || (v14.0 = BG_GetViewmodelWeaponIndex(ps).0, BG_WeaponHasPerk(v14, 0x2Au)) )
    {
      if ( Com_SessionMode_IsMode(SESSIONMODE_ZOMBIES) )
      {
        if ( (ps->pm_flags & 0x8000) != 0 )
          Float = Dvar_GetFloat(player_zombieSprintSpeedScale);
        else
          Float = Dvar_GetFloat(player_zombieSpeedScale);
        scaleb = Float * scaleb;
      }
    }
    v16.0 = ($190F2CF944EC18EE3AF27F473C4F9DBE)ps->weapon;
    if ( v16.weaponData && *(_BYTE *)&v16.0 )
    {
      WeaponDef = BG_GetWeaponDef(ps->weapon);
      if ( WeaponDef->moveSpeedScale <= 0.0 || (ps->pm_flags & 0x40) != 0 || v4 )
        scaleb = BG_GetADSMoveSpeedScale(ps->weapon) * scaleb;
      else
        scaleb = PM_GetMoveSpeedScale(pm, WeaponDef) * scaleb;
    }
    if ( (ps->pm_flags & 0x10000) != 0 )
      return ps->moveSpeedScaleMultiplier * (float)(BG_GetShellshockParms(ps->shellshockIndex)->movement.scale * scaleb);
    else
      return ps->moveSpeedScaleMultiplier * scaleb;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
