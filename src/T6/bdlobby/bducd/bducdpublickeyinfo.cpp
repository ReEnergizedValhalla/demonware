// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bducdpublickeyinfo.cpp:0x941990
BOOL __cdecl Dtp_CanMove(pmove_t *pm)
{
  int lastDtpEnd; // eax
  BOOL result; // eax
  float timeSinceLastDtp; // [esp+4h] [ebp-4h]

  if ( Dvar_GetBool(dtp)
    && (pm->ps->pm_flags & 0x200000) != 0
    && pm->ps->waterlevel >= 1
    && (!Dvar_GetBool(dtp_new_trajectory) || pm->ps->velocity.z <= 0.0) )
  {
    Dtp_Interrupt(pm);
  }
  result = 1;
  if ( Dvar_GetBool(dtp) && (pm->ps->pm_flags & 0x200000) == 0 )
  {
    lastDtpEnd = pm->ps->lastDtpEnd;
    if ( lastDtpEnd )
    {
      timeSinceLastDtp = (float)(pm->cmd.serverTime - lastDtpEnd);
      if ( Dvar_GetFloat(dtp_post_move_pause) > timeSinceLastDtp )
        return 0;
    }
  }
  return result;
}

#endif // __UNIMPLEMENTED__
