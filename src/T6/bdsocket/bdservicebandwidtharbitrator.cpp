// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdservicebandwidtharbitrator.cpp:0x958A50
bool __usercall PM_MeleeChargeMove_IsActive@<al>(pmove_t *pm@<eax>)
{
  int v2; // eax
  playerState_s *ps; // esi

  if ( Dvar_GetBool(player_meleeCOD4ChargeMovement) )
  {
    LOBYTE(v2) = 0;
  }
  else
  {
    if ( !pm
      && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6713, 0, "(pm)", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    ps = pm->ps;
    if ( !ps
      && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6716, 0, "(ps)", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    return ((unsigned int)ps->pm_flags >> 17) & 1;
  }
  return v2;
}

#endif // __UNIMPLEMENTED__
