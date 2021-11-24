// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bddtlserror.cpp:0x958090
bool __usercall PM_MeleeChargeIsValid@<al>(pmove_t *pm@<edi>, pml_t *pml)
{
  playerState_s *ps; // esi
  int pm_flags; // eax

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6382, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !pml
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6383, 0, "(pml)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6386, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  pm_flags = ps->pm_flags;
  return (pm_flags & 0x20000) == 0
      && pm->cmd.meleeChargeEnt != 1023
      && !ps->pm_type
      && (ps->eFlags & 0x300) == 0
      && (pm_flags & 0xC) == 0
      && !PM_IsInAir(pm, pml);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlserror.cpp:0x958150
void __cdecl PM_MeleeChargeStart(pmove_t *pm, pml_t *pml)
{
  playerState_s *ps; // esi

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6414, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !pml
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6415, 0, "(pml)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6418, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( PM_MeleeChargeIsValid(pm, pml) )
  {
    ps->pm_flags |= 0x20000u;
    ps->meleeChargeTime = 0;
    ps->meleeChargeEnt = pm->cmd.meleeChargeEnt;
    ps->meleeChargeDist = pm->cmd.meleeChargeDist;
  }
  else
  {
    PM_MeleeChargeClear(ps);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlserror.cpp:0x958210
bool __usercall PM_IsValidCharge@<al>(pmove_t *pm@<eax>)
{
  playerState_s *ps; // edi
  int pm_flags; // eax
  bool v4; // bl
  float speed; // xmm0_4

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6445, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6448, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  pm_flags = ps->pm_flags;
  v4 = (pm_flags & 0x20000) != 0 && !ps->pm_type && (ps->eFlags & 0x300) == 0 && (pm_flags & 0xC) == 0;
  if ( !Dvar_GetBool(tu7_clampMeleeChargeJumping)
    || !v4
    || ps->groundEntityNum != 1023
    || ps->velocity.z <= Dvar_GetFloat(tu7_clampMeleeChargeJumpingMaxZVel) )
  {
    return v4;
  }
  if ( Dvar_GetBool(tu7_clampMeleeChargeHorzLaunch)
    && (float)((float)((float)(ps->velocity.x * ps->velocity.x) + (float)(ps->velocity.y * ps->velocity.y))
             + (float)(ps->velocity.z * ps->velocity.z)) > (float)((float)ps->speed * (float)ps->speed) )
  {
    Vec3Normalize(&ps->velocity);
    speed = (float)ps->speed;
    ps->velocity.x = ps->velocity.x * speed;
    ps->velocity.y = ps->velocity.y * speed;
    ps->velocity.z = ps->velocity.z * speed;
  }
  return 0;
}

#endif // __UNIMPLEMENTED__
