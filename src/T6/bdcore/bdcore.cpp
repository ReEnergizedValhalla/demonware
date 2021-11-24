// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdcore.cpp:0x927960
unsigned int __cdecl Demo_GetCurrentControllerConfig()
{
  int Primary; // eax

  if ( Dvar_GetInt(net_showprofile) )
    return 0;
  if ( Demo_IsPlaying() && (demo.playbackMode & 4) != 0 )
    return 3;
  Primary = Com_ControllerIndexes_GetPrimary();
  return GamerProfile_GetInt(PROFILE_DEMO_CONTROLLER_CONFIG, (ControllerIndex_t)Primary);
}

#endif // __UNIMPLEMENTED__
