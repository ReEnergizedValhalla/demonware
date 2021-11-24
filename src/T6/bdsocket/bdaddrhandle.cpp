// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdaddrhandle.cpp:0x954A20
float __usercall PM_CmdScale@<xmm0>(playerState_s *ps@<eax>, usercmd_s *cmd@<esi>)
{
  int v3; // ecx
  int v4; // eax
  float v5; // xmm1_4
  float result; // xmm0_4
  float v7; // xmm2_4
  int pm_flags; // ecx
  int pm_type; // edi
  float scale; // [esp+4h] [ebp-4h]

  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 1466, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = abs8(cmd->forwardmove);
  v4 = abs8(cmd->rightmove);
  if ( v4 > v3 )
    v3 = v4;
  v5 = fsqrt((float)(cmd->rightmove * cmd->rightmove + cmd->forwardmove * cmd->forwardmove));
  if ( !v3 )
    return 0.0;
  v7 = (float)v3;
  pm_flags = ps->pm_flags;
  result = (float)((float)ps->speed * v7) / (float)(v5 * 127.0);
  scale = result;
  if ( (pm_flags & 0x40) != 0 || ps->leanf != 0.0 || (pm_flags & 0x200000) != 0 )
  {
    result = result * 0.40000001;
    scale = result;
  }
  pm_type = ps->pm_type;
  if ( pm_type == 2 )
  {
    result = result * 3.0;
    scale = result;
  }
  if ( pm_type == 3 )
  {
    result = result * 6.0;
    scale = result;
  }
  if ( pm_type == 5 )
    return Dvar_GetFloat(player_spectateSpeedScale) * scale;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdaddrhandle.cpp:0x954B30
double __cdecl PM_DamageScale_Walk(int damage_timer)
{
  double Float; // st7
  float timer_max; // [esp+0h] [ebp-4h]

  if ( !damage_timer )
    return 1.0;
  Float = Dvar_GetFloat(player_dmgtimer_maxTime);
  if ( Float == 0.0 )
    return 1.0;
  timer_max = Float;
  return Dvar_GetFloat(player_dmgtimer_minScale) * (-1.0 / timer_max) * (double)damage_timer + 1.0;
}

#endif // __UNIMPLEMENTED__
