// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdsummarymetahandler.cpp:0x941500
BOOL __cdecl Dtp_IsSliding(const playerState_s *ps)
{
  return Dvar_GetBool(dtp) && (ps->pm_flags & 0x200000) != 0 && ps->jumpTime < 0;
}

#endif // __UNIMPLEMENTED__
