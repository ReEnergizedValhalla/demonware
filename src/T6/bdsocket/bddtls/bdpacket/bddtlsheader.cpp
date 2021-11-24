// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bddtlsheader.cpp:0x959CA0
void __cdecl PM_NoclipMove(pml_t *pml)
{
  pmove_t *pm; // ecx
  pmove_t *v2; // edi
  playerState_s *ps; // esi
  float z; // xmm0_4
  double Float; // st7
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  unsigned int v11; // eax
  float v12; // xmm0_4
  int v13; // edi
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm6_4
  float frametime; // xmm0_4
  float stopspeed_valuea; // [esp+18h] [ebp-1Ch]
  float stopspeed_value; // [esp+18h] [ebp-1Ch]
  float smove; // [esp+1Ch] [ebp-18h]
  float smovea; // [esp+1Ch] [ebp-18h]
  float umove; // [esp+20h] [ebp-14h]
  float umovea; // [esp+20h] [ebp-14h]
  vec3_t wishdir; // [esp+24h] [ebp-10h] BYREF

  v2 = pm;
  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 2234, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = v2->ps;
  if ( !v2->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 2237, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps->viewHeightTarget = Dvar_GetInt(player_standingViewHeight);
  umove = fsqrt(
            (float)((float)(ps->velocity.x * ps->velocity.x) + (float)(ps->velocity.y * ps->velocity.y))
          + (float)(ps->velocity.z * ps->velocity.z));
  if ( umove >= 1.0 )
  {
    smove = BG_GetFriction() * 1.5;
    Float = Dvar_GetFloat(stopspeed);
    if ( Float <= umove )
    {
      v6 = umove;
    }
    else
    {
      stopspeed_valuea = Float;
      v6 = stopspeed_valuea;
    }
    v7 = umove - (float)((float)(v6 * smove) * pml->frametime);
    if ( v7 < 0.0 )
      v7 = 0.0;
    v8 = v7 / umove;
    ps->velocity.x = v8 * ps->velocity.x;
    ps->velocity.y = v8 * ps->velocity.y;
    z = v8 * ps->velocity.z;
  }
  else
  {
    *(_QWORD *)&ps->velocity.x = *(_QWORD *)&vec3_origin.x;
    z = vec3_origin.z;
  }
  ps->velocity.z = z;
  stopspeed_value = (float)v2->cmd.forwardmove;
  smovea = (float)v2->cmd.rightmove;
  umovea = 0.0;
  if ( Com_GetClientPlatform() || !v2->cmd.lastInput )
  {
    v9 = FLOAT_127_0;
    if ( v2->cmd.button_bits.array[0] >= 0 )
    {
      v10 = 0.0;
    }
    else
    {
      v10 = FLOAT_127_0;
      umovea = FLOAT_127_0;
    }
    v11 = (unsigned int)v2->cmd.button_bits.array[0] >> 7;
  }
  else
  {
    v9 = FLOAT_127_0;
    if ( (v2->cmd.button_bits.array[0] & 0x1000000) != 0 )
    {
      v10 = FLOAT_127_0;
      umovea = FLOAT_127_0;
    }
    else
    {
      v10 = 0.0;
    }
    v11 = (unsigned int)v2->cmd.button_bits.array[0] >> 25;
  }
  if ( (v11 & 1) != 0 )
  {
    v10 = v10 - v9;
    umovea = v10;
  }
  v12 = PM_MoveScale(ps, stopspeed_value, smovea, v10);
  v13 = v2->cmd.button_bits.array[0];
  if ( (v13 & 0x20000000) != 0 || (v13 & 0x40000000) != 0 )
    v12 = v12 * 15.0;
  v14 = (float)((float)(pml->right.x * smovea) + (float)(pml->forward.x * stopspeed_value))
      + (float)(pml->up.x * umovea);
  v15 = (float)((float)(pml->right.y * smovea) + (float)(pml->forward.y * stopspeed_value))
      + (float)(pml->up.y * umovea);
  v16 = (float)((float)(pml->right.z * smovea) + (float)(pml->forward.z * stopspeed_value))
      + (float)(pml->up.z * umovea);
  v17 = fsqrt((float)((float)(v15 * v15) + (float)(v14 * v14)) + (float)(v16 * v16));
  if ( COERCE_FLOAT(LODWORD(v17) ^ _mask__NegFloat_) < 0.0 )
    v18 = v17;
  else
    v18 = *(float *)&FLOAT_1_0;
  wishdir.x = v14 * (float)(1.0 / v18);
  wishdir.y = v15 * (float)(1.0 / v18);
  wishdir.z = v16 * (float)(1.0 / v18);
  PM_Accelerate(ps, &wishdir, pml, v17 * v12, 9.0);
  frametime = pml->frametime;
  ps->origin.x = (float)(frametime * ps->velocity.x) + ps->origin.x;
  ps->origin.y = (float)(frametime * ps->velocity.y) + ps->origin.y;
  ps->origin.z = (float)(frametime * ps->velocity.z) + ps->origin.z;
}

#endif // __UNIMPLEMENTED__
