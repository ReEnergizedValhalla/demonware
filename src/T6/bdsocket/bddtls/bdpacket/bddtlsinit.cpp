// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bddtlsinit.cpp:0x958880
void __thiscall PM_MeleeChargeCheck(pmove_t *pm)
{
  playerState_s *ps; // esi
  Weapon v3; // edi
  const WeaponDef *WeaponDef; // eax
  int meleeChargeDelay; // ebx
  int iMeleeDelay; // ebp
  double Float; // st7
  float meleeChargeDist; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float chargeTime; // [esp+10h] [ebp-18h]
  float meleeChargeYawa; // [esp+14h] [ebp-14h]
  float chargeVel; // [esp+18h] [ebp-10h]
  vec2_t chargeDir; // [esp+1Ch] [ebp-Ch] BYREF

  if ( !Dvar_GetBool(player_meleeCOD4ChargeMovement) )
  {
    if ( !pm
      && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6652, 0, "(pm)", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    ps = pm->ps;
    if ( !ps
      && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6655, 0, "(ps)", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( (ps->pm_flags & 0x20000) == 0 )
      goto LABEL_9;
    if ( !ps->meleeChargeTime )
    {
      if ( BG_IsUseAsMeleeWeapon(ps->weapon) )
        v3.0 = ($190F2CF944EC18EE3AF27F473C4F9DBE)ps->weapon;
      else
        v3.0 = ($190F2CF944EC18EE3AF27F473C4F9DBE)ps->meleeWeapon;
      WeaponDef = BG_GetWeaponDef(v3);
      meleeChargeDelay = WeaponDef->meleeChargeDelay;
      iMeleeDelay = WeaponDef->iMeleeDelay;
      if ( BG_IsBayonetWeapon(v3) )
        Float = Dvar_GetFloat(player_bayonetRange);
      else
        Float = Dvar_GetFloat(player_meleeRange);
      chargeTime = Float;
      meleeChargeDist = (float)ps->meleeChargeDist;
      if ( meleeChargeDist <= chargeTime )
        v9 = (float)iMeleeDelay;
      else
        v9 = (float)meleeChargeDelay;
      v10 = v9 * 0.001;
      if ( v10 <= 0.0 )
      {
LABEL_9:
        PM_MeleeChargeClear(ps);
        return;
      }
      chargeVel = (float)(meleeChargeDist / v10) * 2.0;
      PM_GetMeleeChargeYaw(pm);
      meleeChargeYawa = Float;
      YawVectors2D(meleeChargeYawa, &chargeDir, 0);
      ps->velocity.x = chargeDir.v[0] * chargeVel;
      ps->velocity.y = chargeDir.v[1] * chargeVel;
      ps->meleeChargeTime = (int)(float)(v10 * 1000.0);
    }
  }
}

#endif // __UNIMPLEMENTED__
