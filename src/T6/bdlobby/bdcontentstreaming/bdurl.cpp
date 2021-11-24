// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdurl.cpp:0x941890
void __cdecl Dtp_AirMove(playerState_s *ps, const pmove_t *pm)
{
  float z; // xmm0_4

  if ( (ps->pm_flags & 0x200000) == 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_dtp.cpp",
          201,
          0,
          "(ps->pm_flags & (1<<21))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( Dvar_GetBool(dtp_debug) && !pm->handler )
  {
    if ( Dvar_GetBool(dtp_new_trajectory) )
      CG_DebugStar(&ps->origin, &colorRed, 1500);
    else
      CG_DebugStar(&ps->origin, &colorYellow, 1500);
  }
  if ( Dvar_GetBool(dtp_new_trajectory) && ps->origin.z >= Jump_GetHeight() + ps->jumpOriginZ )
  {
    if ( pm->cmd.serverTime - ps->jumpTime >= Dvar_GetInt(dtp_max_apex_duration) )
    {
      z = ps->velocity.z;
      if ( COERCE_FLOAT(LODWORD(z) ^ _mask__NegFloat_) < 0.0 )
        z = 0.0;
      ps->velocity.z = z;
    }
    else
    {
      ps->velocity.z = 0.0;
    }
  }
}

#endif // __UNIMPLEMENTED__
