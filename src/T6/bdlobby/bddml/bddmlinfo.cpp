// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bddmlinfo.cpp:0x941C20
BOOL __usercall Dtp_IsDtp@<eax>(const pmove_t *pm@<edi>, const playerState_s *ps@<esi>)
{
  BOOL result; // eax
  float v3; // [esp+0h] [ebp-8h]
  float Float; // [esp+4h] [ebp-4h]

  result = 0;
  if ( Dvar_GetBool(dtp)
    && !BG_WeaponBlocksProne(ps->weapon)
    && ps->sprintState.lastSprintEnd == pm->cmd.serverTime
    && (pm->cmd.button_bits.array[1] & 0x80000) != 0 )
  {
    v3 = (float)(ps->velocity.x * ps->velocity.x) + (float)(ps->velocity.y * ps->velocity.y);
    Float = Dvar_GetFloat(dtp_min_speed);
    if ( Dvar_GetFloat(dtp_min_speed) * Float < v3
      && (!Com_SessionMode_IsZombiesGame() || ((unsigned int)&g_hunklow_track[6894].name[40] & ps->pm_flags) == 0) )
    {
      return 1;
    }
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddmlinfo.cpp:0x941CD0
int __cdecl Dtp_Update(pmove_t *pm, pml_t *pml)
{
  playerState_s *ps; // esi
  int v3; // eax
  int v5; // ebx
  int v6; // eax
  float sprintDuration; // [esp+Ch] [ebp-4h]
  float sprintDurationa; // [esp+Ch] [ebp-4h]

  if ( !Dvar_GetBool(dtp) )
    return 0;
  if ( !pm && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_dtp.cpp", 302, 0, "(pm)", (const char *)&pBlock) )
    __debugbreak();
  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_dtp.cpp", 305, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (ps->pm_flags & 0x200000) == 0 )
  {
    if ( Dtp_IsDtp(pm, ps) )
    {
      v5 = pm->cmd.serverTime - ps->lastDtpEnd;
      sprintDuration = (float)v5;
      if ( sprintDuration > Dvar_GetFloat(dtp_exhaustion_window) || v5 < 0 )
      {
        sprintDurationa = (float)(pm->cmd.serverTime - ps->sprintState.lastSprintStart);
        if ( sprintDurationa > Dvar_GetFloat(dtp_startup_delay) )
        {
          Dtp_Start(pml, pm);
          v6 = PM_GroundSurfaceType(pm->ps, pml);
          BG_AddPredictableEventToPlayerstate(215, Dtp_SurfaceRemapTable[v6], ps);
          return 1;
        }
      }
    }
    return 0;
  }
  if ( ps->jumpTime > 0 )
  {
    v3 = PM_GroundSurfaceType(pm->ps, pml);
    BG_AddPredictableEventToPlayerstate(216, Dtp_SurfaceRemapTable[v3], ps);
    BG_AnimScriptEvent(pm, ANIM_ET_DTP_LAND, 1, 1, &pml->holdrand);
    ps->jumpTime = -pm->cmd.serverTime;
  }
  return 1;
}

#endif // __UNIMPLEMENTED__
