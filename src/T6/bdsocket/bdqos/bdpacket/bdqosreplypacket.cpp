// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdqosreplypacket.cpp:0x958AD0
void __cdecl PM_MeleeChargeMove(pml_t *pml)
{
  pmove_t *pm; // ecx
  pmove_t *v2; // edi
  playerState_s *ps; // esi
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm2_4
  float v10; // xmm5_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float newSpeed; // [esp+Ch] [ebp-20h]
  float dir; // [esp+10h] [ebp-1Ch]
  float dir_4; // [esp+14h] [ebp-18h]
  float y; // [esp+20h] [ebp-Ch]

  v2 = pm;
  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6729, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !pml
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6730, 0, "(pml)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = v2->ps;
  if ( !v2->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6733, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( ps->meleeChargeTime <= 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp",
          6735,
          0,
          "(ps->meleeChargeTime > 0)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v4 = fsqrt(
         (float)((float)(ps->velocity.x * ps->velocity.x) + (float)(ps->velocity.y * ps->velocity.y))
       + (float)(ps->velocity.z * ps->velocity.z));
  if ( COERCE_FLOAT(LODWORD(v4) ^ _mask__NegFloat_) < 0.0 )
    v5 = v4;
  else
    v5 = *(float *)&FLOAT_1_0;
  v6 = 1.0 / v5;
  v7 = ps->velocity.x * (float)(1.0 / v5);
  v8 = ps->velocity.y * (float)(1.0 / v5);
  v9 = ps->velocity.z * (float)(1.0 / v5);
  v10 = v4;
  dir = ps->velocity.x * v6;
  dir_4 = ps->velocity.y * v6;
  newSpeed = v4;
  if ( v4 > 0.0 )
  {
    v10 = v4 - (float)((float)(v4 / (float)((float)ps->meleeChargeTime * 0.001)) * pml->frametime);
    newSpeed = v10;
    if ( v10 < 0.0 )
    {
      v10 = 0.0;
      newSpeed = 0.0;
    }
    v11 = (float)(v4 + v10) * 0.5;
    ps->velocity.x = v7 * v11;
    ps->velocity.y = v8 * v11;
    ps->velocity.z = v9 * v11;
  }
  v12 = (float)(ps->velocity.x * ps->velocity.x) + (float)(ps->velocity.y * ps->velocity.y);
  if ( COERCE_FLOAT(pml->groundTrace.normal.vec.m128_i32[2] & _mask__AbsFloat_) < 0.001 || v12 == 0.0 )
  {
    ps->velocity.x = ps->velocity.x;
    ps->velocity.y = ps->velocity.y;
    ps->velocity.z = ps->velocity.z;
  }
  else
  {
    LODWORD(v13) = COERCE_UNSIGNED_INT(
                     (float)((float)(pml->groundTrace.normal.vec.m128_f32[1] * ps->velocity.y)
                           + (float)(ps->velocity.x * pml->groundTrace.normal.vec.m128_f32[0]))
                   / pml->groundTrace.normal.vec.m128_f32[2]) ^ _mask__NegFloat_;
    y = ps->velocity.y;
    v14 = fsqrt((float)((float)(ps->velocity.z * ps->velocity.z) + v12) / (float)((float)(v13 * v13) + v12));
    if ( v14 < 1.0 || v13 < 0.0 || ps->velocity.z > 0.0 )
    {
      ps->velocity.x = ps->velocity.x * v14;
      ps->velocity.y = y * v14;
      ps->velocity.z = v14 * v13;
    }
  }
  if ( ps->velocity.x != 0.0 || ps->velocity.y != 0.0 )
  {
    PM_StepSlideMove(v2, pml, 0);
    v8 = dir_4;
    v7 = dir;
    v10 = newSpeed;
  }
  ps->velocity.x = v7 * v10;
  ps->velocity.y = v8 * v10;
  ps->velocity.z = v9 * v10;
  ps->meleeChargeTime -= pml->msec;
  if ( ps->meleeChargeTime <= 0 )
  {
    ps->velocity.x = 0.0;
    ps->velocity.y = 0.0;
    PM_MeleeChargeClear(ps);
  }
  PM_SetMovementDir(v2, pml);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosreplypacket.cpp:0x958E10
void __usercall ClearPlayerVelocity(playerState_s *ps@<esi>)
{
  float z; // xmm0_4

  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6817, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( Dvar_GetBool(tu11_player_keepZVelocity) )
  {
    z = ps->velocity.z;
    *(_QWORD *)&ps->velocity.x = 0i64;
    ps->velocity.z = z;
  }
  else
  {
    *(_QWORD *)&ps->velocity.x = 0i64;
    ps->velocity.z = 0.0;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosreplypacket.cpp:0x958E80
void __usercall PM_UpdatePush(pmove_t *pm@<esi>, pml_t *pml)
{
  playerState_s *ps; // edi
  float PushAmount; // [esp+18h] [ebp-28h]
  gjkcc_input_t gjkcc_in; // [esp+1Ch] [ebp-24h] BYREF

  PushAmount = Dvar_GetFloat(playerPushAmount);
  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6865, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( PushAmount != 0.0 )
  {
    setup_gjkcc_input(pm, &gjkcc_in);
    gjk_sentient_push(
      pm,
      pml,
      &ps->origin,
      &pm->mins,
      &pm->maxs,
      pm->tracemask,
      ps->clientNum,
      &gjkcc_in,
      PushAmount,
      pml->frametime,
      &ps->velocity,
      &ps->origin);
  }
}

#endif // __UNIMPLEMENTED__
