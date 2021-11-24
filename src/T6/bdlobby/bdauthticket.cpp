// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdauthticket.cpp:0x941A50
// local variable allocation has failed, the output may be wrong!
double __usercall Dtp_ReduceFriction@<st0>(unsigned int a1@<ebp>, pmove_t *pm, const playerState_s *ps)
{
  bool v3; // sf
  float z; // xmm0_4
  float y; // xmm2_4
  double Float; // st7
  double v7; // st5
  playerState_s *v9; // eax
  int clientNum; // [esp-28h] [ebp-94h]
  float v11; // [esp-Ch] [ebp-78h]
  int v12; // [esp-8h] [ebp-74h]
  float v13; // [esp-4h] [ebp-70h]
  _BYTE max_slide_duration[76]; // [esp+0h] [ebp-6Ch] OVERLAPPED BYREF
  float v15; // [esp+4Ch] [ebp-20h]
  vec3_t start; // [esp+50h] [ebp-1Ch] BYREF
  vec3_t point; // [esp+5Ch] [ebp-10h]
  unsigned int retaddr; // [esp+6Ch] [ebp+0h]

  *(_QWORD *)&point.v[1] = __PAIR64__(retaddr, a1);
  if ( (ps->pm_flags & 0x200000) == 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_dtp.cpp",
          164,
          0,
          "(ps->pm_flags & (1<<21))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = ps->jumpTime < 0;
  *(_OWORD *)max_slide_duration = 0i64;
  if ( v3 )
  {
    z = ps->origin.z;
    y = ps->origin.y;
    clientNum = ps->clientNum;
    v12 = pm->cmd.serverTime + pm->ps->jumpTime;
    *(float *)&max_slide_duration[68] = ps->origin.x;
    *(float *)&max_slide_duration[72] = y;
    v15 = z + 1.0;
    *(_QWORD *)&start.x = __PAIR64__(LODWORD(y), *(unsigned int *)&max_slide_duration[68]);
    start.z = z - 1.0;
    PM_trace(
      pm,
      (trace_t *)max_slide_duration,
      (const vec3_t *)&max_slide_duration[68],
      &pm->mins,
      &pm->maxs,
      &start,
      clientNum,
      (int)&g_sd.voiceDecodeBuffer[774848]);
    Float = Dvar_GetFloat(dtp_max_slide_duration);
    v11 = Float;
    if ( *(float *)&max_slide_duration[16] < 1.0 )
    {
      v13 = (float)v12;
      v7 = Dvar_GetFloat(dtp_max_slide_addition) + v11;
      Float = v11;
      if ( v7 > v13 )
        return 0.0;
    }
    if ( v11 > (float)v12 )
      return (float)v12 / Float;
    pm->ps->pm_flags &= ~0x200000u;
    pm->ps->jumpTime = 0;
    v9 = pm->ps;
    v9->velocity.x = 0.0;
    v9->velocity.y = 0.0;
    v9->velocity.z = 0.0;
    pm->ps->lastDtpEnd = pm->cmd.serverTime;
    pm->ps->sprintState.sprintButtonUpRequired = 0;
  }
  return 1.0;
}

#endif // __UNIMPLEMENTED__
