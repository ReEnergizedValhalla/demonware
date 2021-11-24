// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdhashmap.h:0x948820
void __cdecl Mantle_Move(pmove_t *pm, playerState_s *ps, pml_t *pml)
{
  const dvar_t *v3; // eax
  int UpLength; // ebx
  int OverLength; // eax
  int timer; // ecx
  int v7; // ebx
  int v8; // eax
  int v9; // ebx
  int Anim; // eax
  unsigned int v11; // xmm0_4
  unsigned int v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  const dvar_t *v15; // eax
  int mantleLength; // [esp+Ch] [ebp-28h]
  vec3_t prevTrans; // [esp+18h] [ebp-1Ch] BYREF
  vec3_t trans; // [esp+24h] [ebp-10h] BYREF

  if ( (ps->pm_flags & 4) == 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
          1324,
          0,
          "(ps->pm_flags & (1<<2))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( pml->msec < 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
          1325,
          0,
          "((pml->msec >= 0))",
          "(pml->msec) = %i",
          pml->msec) )
  {
    __debugbreak();
  }
  v3 = mantle_enable;
  ps->mantleState.flags &= ~0x10u;
  if ( Dvar_GetBool(v3) )
  {
    ps->moverTimestamp = pm->cmd.serverTime;
    if ( (ps->mantleState.flags & 4) != 0 )
      BG_AddPredictableEventToPlayerstate(9, 0, ps);
    UpLength = Mantle_GetUpLength(&ps->mantleState);
    OverLength = Mantle_GetOverLength(&ps->mantleState);
    timer = ps->mantleState.timer;
    v7 = OverLength + UpLength;
    v8 = timer + pml->msec;
    mantleLength = v7;
    ps->mantleState.timer = v8;
    if ( v8 > v7 )
      ps->mantleState.timer = v7;
    v9 = ps->mantleState.timer - timer;
    Mantle_GetAnimDelta(&ps->mantleState, &prevTrans);
    Mantle_GetAnimDelta(&ps->mantleState, &trans);
    Anim = Mantle_GetAnim(&ps->mantleState);
    BG_AnimScriptAnimation(pm, AISTATE_COMBAT, (scriptAnimMoveTypes_t)(Anim + 8), 1);
    *(float *)&v11 = trans.x - prevTrans.x;
    *(float *)&v12 = trans.y - prevTrans.y;
    v13 = trans.z - prevTrans.z;
    ps->origin.x = ps->origin.x + (float)(trans.x - prevTrans.x);
    ps->origin.y = ps->origin.y + *(float *)&v12;
    ps->origin.z = ps->origin.z + v13;
    v14 = 1.0 / (float)((float)v9 * 0.001);
    *(_QWORD *)&trans.x = __PAIR64__(v12, v11);
    trans.z = v13;
    ps->velocity.x = *(float *)&v11 * v14;
    ps->velocity.y = *(float *)&v12 * v14;
    ps->velocity.z = v13 * v14;
    if ( ps->mantleState.timer == mantleLength )
    {
      if ( (ps->pm_flags & 4) == 0
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
              1370,
              0,
              "(( ps->pm_flags & (1<<2) ))",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v15 = mantle_adjustment_tu;
      ps->pm_flags &= ~4u;
      if ( Dvar_GetBool(v15) && (ps->mantleState.flags & 2) != 0 )
      {
        *(_QWORD *)&ps->velocity.x = 0i64;
        ps->velocity.z = 0.0;
      }
      pm->mantleStarted = 0;
      if ( (ps->mantleState.flags & 1) != 0 )
        BG_AnimScriptEvent(pm, ANIM_ET_JUMP, 0, 1, &pml->holdrand);
      if ( (ps->mantleState.flags & 8) != 0 )
      {
        BG_AddPredictableEventToPlayerstate(8, 0, ps);
        ps->eFlags &= ~0x8000u;
      }
      ps->mantleState.flags |= 0x100u;
    }
  }
  else
  {
    ps->pm_flags &= ~4u;
    ps->eFlags &= ~0x8000u;
    pm->mantleStarted = 0;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhashmap.h:0x94F390
bool __usercall BG_ValidateOrigin@<al>(
        const vec3_t *pos@<edi>,
        unsigned int xyBits@<ecx>,
        const vec3_t *mapCenter@<esi>,
        unsigned int zBits)
{
  int v4; // edx
  float v5; // xmm1_4
  int z; // eax
  int x; // eax
  float v8; // xmm1_4
  int y; // eax
  bool result; // al

  v4 = 1 << (xyBits - 1);
  v5 = (float)(1 << (zBits - 1));
  z = (int)pos->z;
  result = 0;
  if ( z <= (int)(float)(mapCenter->z + v5) && z >= (int)(float)(mapCenter->z - v5) )
  {
    x = (int)pos->x;
    v8 = (float)v4;
    if ( x <= (int)(float)(mapCenter->x + (float)v4) && x >= (int)(float)(mapCenter->x - v8) )
    {
      y = (int)pos->y;
      if ( y <= (int)(float)(mapCenter->y + v8) && y >= (int)(float)(mapCenter->y - v8) )
        return 1;
    }
  }
  return result;
}

#endif // __UNIMPLEMENTED__
