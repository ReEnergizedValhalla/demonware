// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bddtlsdata.cpp:0x95A020
void __cdecl PM_UFOMove(pml_t *pml)
{
  pmove_t *pm; // ecx
  pmove_t *v2; // edi
  playerState_s *ps; // esi
  float v4; // xmm3_4
  float v5; // xmm0_4
  float z; // xmm0_4
  double Float; // st7
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  int v12; // edi
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm5_4
  float frametime; // xmm0_4
  float stopspeed_value; // [esp+18h] [ebp-34h]
  float curFriction; // [esp+1Ch] [ebp-30h]
  float fmove; // [esp+20h] [ebp-2Ch]
  float smove; // [esp+24h] [ebp-28h]
  float scale; // [esp+28h] [ebp-24h]
  float scalea; // [esp+28h] [ebp-24h]
  float umove; // [esp+2Ch] [ebp-20h]
  vec3_t up; // [esp+30h] [ebp-1Ch] BYREF
  vec3_t forward; // [esp+3Ch] [ebp-10h] BYREF

  v2 = pm;
  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 2338, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = v2->ps;
  if ( !v2->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 2341, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps->viewHeightTarget = Dvar_GetInt(player_standingViewHeight);
  fmove = (float)v2->cmd.forwardmove;
  smove = (float)v2->cmd.rightmove;
  umove = 0.0;
  if ( Com_GetClientPlatform() || !v2->cmd.lastInput )
  {
    if ( v2->cmd.button_bits.array[0] >= 0 )
      v5 = 0.0;
    else
      v5 = FLOAT_127_0;
    if ( (v2->cmd.button_bits.array[0] & 0x100000) != 0 )
      v5 = v5 - 127.0;
    v4 = v5 * 0.30000001;
    goto LABEL_20;
  }
  if ( (v2->cmd.button_bits.array[0] & 0x1000000) != 0 )
  {
    v4 = FLOAT_127_0;
    umove = FLOAT_127_0;
  }
  else
  {
    v4 = 0.0;
  }
  if ( (v2->cmd.button_bits.array[0] & 0x2000000) != 0 )
  {
    v4 = v4 - 127.0;
LABEL_20:
    umove = v4;
  }
  if ( fmove == 0.0 && smove == 0.0 && v4 == 0.0
    || (scale = fsqrt(
                  (float)((float)(ps->velocity.x * ps->velocity.x) + (float)(ps->velocity.y * ps->velocity.y))
                + (float)(ps->velocity.z * ps->velocity.z)),
        scale < 1.0) )
  {
    *(_QWORD *)&ps->velocity.x = *(_QWORD *)&vec3_origin.x;
    z = vec3_origin.z;
  }
  else
  {
    curFriction = BG_GetFriction() * 1.5;
    Float = Dvar_GetFloat(stopspeed);
    if ( Float <= scale )
    {
      v8 = scale;
    }
    else
    {
      stopspeed_value = Float;
      v8 = stopspeed_value;
    }
    v9 = scale - (float)((float)(v8 * curFriction) * pml->frametime);
    if ( v9 < 0.0 )
      v9 = 0.0;
    v4 = umove;
    v10 = v9 / scale;
    ps->velocity.x = v10 * ps->velocity.x;
    ps->velocity.y = v10 * ps->velocity.y;
    z = v10 * ps->velocity.z;
  }
  ps->velocity.z = z;
  v11 = PM_MoveScale(ps, fmove, smove, v4);
  v12 = v2->cmd.button_bits.array[0];
  scalea = v11;
  if ( (v12 & 0x20000000) != 0 || (v12 & 0x40000000) != 0 )
    scalea = v11 * 15.0;
  *(_QWORD *)&up.x = 0i64;
  LODWORD(up.z) = FLOAT_1_0;
  Vec3Cross(&up, &pml->right, &forward);
  v13 = (float)((float)(forward.x * fmove) + (float)(pml->right.x * smove)) + (float)(umove * 0.0);
  v14 = (float)((float)(pml->right.y * smove) + (float)(forward.y * fmove)) + (float)(umove * 0.0);
  v15 = (float)((float)(pml->right.z * smove) + (float)(forward.z * fmove)) + umove;
  v16 = fsqrt((float)((float)(v14 * v14) + (float)(v13 * v13)) + (float)(v15 * v15));
  if ( COERCE_FLOAT(LODWORD(v16) ^ _mask__NegFloat_) < 0.0 )
    v17 = v16;
  else
    v17 = *(float *)&FLOAT_1_0;
  forward.x = v13 * (float)(1.0 / v17);
  forward.y = v14 * (float)(1.0 / v17);
  forward.z = v15 * (float)(1.0 / v17);
  PM_Accelerate(ps, &forward, pml, v16 * scalea, 9.0);
  frametime = pml->frametime;
  ps->origin.x = (float)(frametime * ps->velocity.x) + ps->origin.x;
  ps->origin.y = (float)(frametime * ps->velocity.y) + ps->origin.y;
  ps->origin.z = (float)(frametime * ps->velocity.z) + ps->origin.z;
}

#endif // __UNIMPLEMENTED__
