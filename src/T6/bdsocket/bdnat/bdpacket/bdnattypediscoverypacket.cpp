// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdnattypediscoverypacket.cpp:0x959350
void __usercall PM_CmdScaleForStance(const pmove_t *pm@<edi>)
{
  float v1; // xmm0_4
  playerState_s *ps; // esi
  int viewHeightLerpTime; // eax
  float v4; // xmm1_4
  int viewHeightLerpDown; // eax
  int viewHeightLerpTarget; // ecx
  int v7; // eax
  float v8; // xmm1_4

  v1 = *(float *)&FLOAT_1_0;
  ps = pm->ps;
  if ( (pm->ps->pm_flags & 0x200000) != 0 )
    return;
  viewHeightLerpTime = ps->viewHeightLerpTime;
  if ( viewHeightLerpTime )
  {
    if ( ps->viewHeightLerpTarget == 11 )
    {
      v4 = (float)(pm->cmd.serverTime - viewHeightLerpTime) * 0.0016666667;
      if ( v4 >= 0.0 && (v4 > 1.0 || v4 != 0.0) )
        return;
    }
  }
  if ( ps->viewHeightLerpTime && ps->viewHeightLerpTarget == 40 )
  {
    viewHeightLerpDown = ps->viewHeightLerpDown;
    if ( !viewHeightLerpDown )
      goto LABEL_13;
    if ( Dvar_GetInt(player_standingViewHeight) == 11 )
    {
      viewHeightLerpDown = ps->viewHeightLerpDown;
      if ( viewHeightLerpDown )
      {
        v1 = *(float *)&FLOAT_1_0;
LABEL_13:
        viewHeightLerpTarget = ps->viewHeightLerpTarget;
        if ( viewHeightLerpTarget == 11 )
        {
          v7 = 600;
        }
        else if ( viewHeightLerpTarget == 40 )
        {
          v7 = viewHeightLerpDown != 0 ? 200 : 400;
        }
        else
        {
          v7 = 200;
        }
        v8 = (float)(pm->cmd.serverTime - ps->viewHeightLerpTime) / (float)v7;
        if ( v8 >= 0.0 && (v8 > v1 || v8 != 0.0) )
          return;
      }
    }
  }
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 818, 0, "(pm->ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  PM_GetEffectiveStance(pm->ps);
}

#endif // __UNIMPLEMENTED__
