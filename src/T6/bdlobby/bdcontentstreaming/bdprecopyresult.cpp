// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdprecopyresult.cpp:0x941730
void __cdecl Dtp_Interrupt(pmove_t *pm)
{
  playerState_s *ps; // eax
  playerState_s *v2; // eax

  pm->ps->pm_flags &= ~0x200000u;
  pm->ps->jumpTime = 0;
  ps = pm->ps;
  ps->velocity.x = 0.0;
  ps->velocity.y = 0.0;
  ps->velocity.z = 0.0;
  pm->ps->lastDtpEnd = pm->cmd.serverTime - (int)Dvar_GetFloat(dtp_post_move_pause) - 1;
  v2 = pm->ps;
  if ( pm->ps->lastDtpEnd >= 0 )
  {
    v2->sprintState.sprintButtonUpRequired = 0;
  }
  else
  {
    v2->lastDtpEnd = 0;
    pm->ps->sprintState.sprintButtonUpRequired = 0;
  }
}

#endif // __UNIMPLEMENTED__
