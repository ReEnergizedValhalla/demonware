// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x946080
char __cdecl BG_VehicleHelicopterVerticalMove(pmove_t *pm, const pml_t *pml, VehicleState *vehicleState)
{
  float v4; // xmm0_4
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  float verticalMove; // [esp+14h] [ebp+8h]

  if ( (pm->ps->vehicleState.flags & 2) != 0 )
    return BG_VehicleHeliLockHeight(vehicleState);
  v4 = 0.0;
  if ( (pm->cmd.button_bits.array[1] & 0x8000000) != 0 )
    v4 = *(float *)&FLOAT_1_0;
  if ( (pm->cmd.button_bits.array[1] & 0x4000000) != 0 )
    v4 = v4 - 1.0;
  if ( v4 == 0.0 )
  {
    verticalMove = BG_HeliMaintainHeight_CalcAccel((int)&savedregs, pm, pml, vehicleState);
    v4 = verticalMove;
  }
  return (int)((float)(v4 * 127.0) + 9.313225746154785e-10);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x946120
// local variable allocation has failed, the output may be wrong!
void __usercall BG_VehicleHelicopterMove(unsigned int a1@<ebp>, pmove_t *pm, const pml_t *pml)
{
  playerState_s *v3; // eax
  char rightmove; // dl
  playerState_s *v5; // esi
  const pml_t *v6; // edi
  __m128 frametime_low; // xmm0
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  float v13; // xmm2_4
  float dt; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  int commandTime; // eax
  playerState_s *v18; // [esp+14h] [ebp-17Ch]
  char v19[4]; // [esp+1Ch] [ebp-174h] BYREF
  playerState_s *ps; // [esp+20h] [ebp-170h]
  _BYTE v21[97]; // [esp+24h] [ebp-16Ch] OVERLAPPED BYREF
  vec4_t moveRequest; // [esp+90h] [ebp-100h] BYREF
  vec3_t bodyAccel; // [esp+A0h] [ebp-F0h] BYREF
  vec3_t rotAccel; // [esp+ACh] [ebp-E4h] BYREF
  VehicleState vehicleState; // [esp+B8h] [ebp-D8h] BYREF
  vec3_t yawAngles; // [esp+150h] [ebp-40h] BYREF
  vec3_t axis[4]; // [esp+15Ch] [ebp-34h] BYREF
  unsigned int retaddr; // [esp+190h] [ebp+0h]

  *(_QWORD *)&axis[3].v[1] = __PAIR64__(retaddr, a1);
  ps = (playerState_s *)pm;
  *(_OWORD *)v21 = 0i64;
  v19[3] = 0;
  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp", 1009, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !pm->ps
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          1010,
          0,
          "(pm->ps)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = pm->ps;
  LODWORD(rotAccel.x) = pm->ps->vehicleState.entity;
  LODWORD(vehicleState.maxs.z) = &g_hunklow_track[62090].name[25];
  *(_QWORD *)&vehicleState.maxs.x = *(_QWORD *)&v3->vehicleState.targetHeightDelta;
  *(_QWORD *)&rotAccel.v[1] = *(_QWORD *)&v3->vehicleState.origin.x;
  vehicleState.entity = LODWORD(v3->vehicleState.origin.z);
  vehicleState.angVelocity = v3->vehicleState.origin;
  vehicleState.origin = v3->vehicleState.angles;
  vehicleState.previousOrigin = v3->vehicleState.angles;
  vehicleState.angles = v3->vehicleState.velocity;
  vehicleState.velocity = v3->vehicleState.angVelocity;
  *(vec2_t *)&vehicleState.bodyVelocity.x = v3->vehicleState.tilt;
  *(vec2_t *)&vehicleState.bodyVelocity.v[2] = v3->vehicleState.tiltVelocity;
  v18 = v3;
  BG_GetVehicleBounds(pm, (vec3_t *)&vehicleState.tilt.y, &vehicleState.mins);
  rightmove = pm->cmd.rightmove;
  v19[0] = pm->cmd.forwardmove;
  v19[1] = rightmove;
  v19[2] = BG_VehicleHelicopterVerticalMove(pm, pml, (VehicleState *)&rotAccel);
  vehicleState.groundNormal.x = 0.0;
  *(_QWORD *)&vehicleState.groundNormal.v[1] = LODWORD(vehicleState.previousOrigin.y);
  AngleVectors(&vehicleState.groundNormal, &yawAngles, axis, &axis[1]);
  memset(&axis[2], 0, sizeof(vec3_t));
  MatrixTransposeTransformVector43(&vehicleState.angles, &yawAngles, &vehicleState.previousAngles);
  BG_HeliCmdScale(v19, (vec4_t *)&v21[96], 1);
  if ( test_1 )
  {
    v5 = ps;
    v6 = pml;
    BG_HeliCalcAccelFromTilt(
      (vec3_t *)&moveRequest.g,
      &bodyAccel,
      (const pmove_t *)ps,
      pml,
      (VehicleState *)&rotAccel,
      (vec4_t *)&v21[96]);
  }
  else
  {
    BG_HeliCalcAccel(
      (vec3_t *)&moveRequest.g,
      &bodyAccel,
      (const pmove_t *)ps,
      pml,
      (VehicleState *)&rotAccel,
      (vec4_t *)&v21[96]);
    v6 = pml;
    v5 = ps;
  }
  frametime_low = (__m128)LODWORD(v6->frametime);
  v8.m128_f32[0] = FLOAT_8388608_0;
  frametime_low.m128_f32[0] = (float)((float)(frametime_low.m128_f32[0]
                                            * (float)((float)(v6->frametime * bodyAccel.y) + vehicleState.velocity.y))
                                    + vehicleState.previousOrigin.y)
                            * 0.0027777778;
  vehicleState.velocity.y = (float)(v6->frametime * bodyAccel.y) + vehicleState.velocity.y;
  v9 = frametime_low;
  v9.m128_f32[0] = frametime_low.m128_f32[0] + 0.5;
  v10 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v9);
  v8.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v9, v10), v8).m128_u32[0] | v10.m128_i32[0];
  v11 = v9;
  v11.m128_f32[0] = (float)((float)(frametime_low.m128_f32[0] + 0.5) + v8.m128_f32[0]) - v8.m128_f32[0];
  v12 = v11;
  v12.m128_f32[0] = v11.m128_f32[0] - (float)(frametime_low.m128_f32[0] + 0.5);
  v13 = (float)(frametime_low.m128_f32[0]
              - (float)(v11.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v12, v10).m128_u32[0] & FLOAT_1_0)))
      * 360.0;
  ps = (playerState_s *)LODWORD(bodyAccel.x);
  *(_QWORD *)&vehicleState.origin.x = __PAIR64__(LODWORD(v13), LODWORD(bodyAccel.x));
  vehicleState.origin.z = bodyAccel.z;
  if ( (LODWORD(bodyAccel.x) & 0x7F800000) == 2139095040
    || (ps = (playerState_s *)LODWORD(v13), (LODWORD(v13) & 0x7F800000) == 2139095040)
    || (ps = (playerState_s *)LODWORD(bodyAccel.z), (LODWORD(bodyAccel.z) & 0x7F800000) == 2139095040) )
  {
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
            1060,
            0,
            "(!IS_NAN((vehicleState.angles)[0]) && !IS_NAN((vehicleState.angles)[1]) && !IS_NAN((vehicleState.angles)[2]))",
            (const char *)&pBlock) )
      __debugbreak();
  }
  vehicleState.groundNormal.x = 0.0;
  *(_QWORD *)&vehicleState.groundNormal.v[1] = LODWORD(vehicleState.origin.y);
  AngleVectors(&vehicleState.groundNormal, &yawAngles, axis, &axis[1]);
  memset(&axis[2], 0, sizeof(vec3_t));
  dt = v6->frametime;
  v15 = (float)((float)((float)((float)(axis[0].y * moveRequest.v[2]) + (float)(yawAngles.y * moveRequest.v[1]))
                      + (float)(axis[1].y * moveRequest.v[3]))
              * dt)
      + vehicleState.angles.y;
  v16 = (float)((float)((float)((float)(axis[0].z * moveRequest.v[2]) + (float)(yawAngles.z * moveRequest.v[1]))
                      + (float)(axis[1].z * moveRequest.v[3]))
              * dt)
      + vehicleState.angles.z;
  vehicleState.angles.x = (float)((float)((float)((float)(axis[0].x * moveRequest.v[2])
                                                + (float)(yawAngles.x * moveRequest.v[1]))
                                        + (float)(axis[1].x * moveRequest.v[3]))
                                * dt)
                        + vehicleState.angles.x;
  vehicleState.angles.y = v15;
  vehicleState.angles.z = v16;
  if ( vehicleState.angles.x != 0.0 || v15 != 0.0 || v16 != 0.0 )
  {
    *(_DWORD *)&v21[80] = 0;
    BG_VehicleGroundTrace((pmove_t *)v5, (VehicleState *)&rotAccel, (GroundTrace *)v21, dt);
    vehicleState.targetHeightDelta = *(float *)v21;
    vehicleState.lastGroundHeight = *(float *)&v21[4];
    vehicleState.clipmask = *(_DWORD *)&v21[8];
    BG_VehicleSlideMove((pmove_t *)v5, (VehicleState *)&rotAccel, (const GroundTrace *)v21, 0, v6->frametime);
    BG_HeliMaintainHeight_UpdateHeight((pmove_t *)v5, v6, (VehicleState *)&rotAccel);
  }
  commandTime = v5->commandTime;
  *(_QWORD *)(commandTime + 260) = *(_QWORD *)&rotAccel.v[1];
  *(_DWORD *)(commandTime + 268) = vehicleState.entity;
  *(vec3_t *)(v5->commandTime + 272) = vehicleState.origin;
  *(vec3_t *)(v5->commandTime + 284) = vehicleState.angles;
  *(vec3_t *)(v5->commandTime + 296) = vehicleState.velocity;
  *(vec3_t *)v18->vehicleState.tilt.v = vehicleState.bodyVelocity;
  v18->vehicleState.tiltVelocity.v[1] = vehicleState.tilt.v[0];
  *(_QWORD *)&v18->vehicleState.targetHeightDelta = *(_QWORD *)&vehicleState.maxs.x;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x946870
void __usercall Jump_RegisterDvars(double a1@<st0>)
{
  bool IsZombiesGame; // al

  jump_height = _Dvar_RegisterFloat(
                  a1,
                  "jump_height",
                  39.0,
                  0.0,
                  1000.0,
                  0x180u,
                  "The maximum height of a player's jump");
  jump_stepSize = _Dvar_RegisterFloat(
                    a1,
                    "jump_stepSize",
                    18.0,
                    0.0,
                    64.0,
                    0x180u,
                    "The maximum step up to the top of a jump arc");
  IsZombiesGame = Com_SessionMode_IsZombiesGame();
  jump_slowdownEnable = _Dvar_RegisterBool(
                          a1,
                          "jump_slowdownEnable",
                          !IsZombiesGame,
                          0x180u,
                          "Slow player movement after jumping");
  jump_ladderPushVel = _Dvar_RegisterFloat(
                         a1,
                         "jump_ladderPushVel",
                         128.0,
                         0.0,
                         1024.0,
                         0x180u,
                         "The velocity of a jump off of a ladder");
  jump_spreadAdd = _Dvar_RegisterFloat(
                     a1,
                     "jump_spreadAdd",
                     64.0,
                     0.0,
                     512.0,
                     0x180u,
                     "The amount of spread scale to add as a side effect of jumping");
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x9469B0
double __cdecl Jump_GetHeight()
{
  return Dvar_GetFloat(jump_height);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x9469C0
void __cdecl Jump_ClearState(playerState_s *ps)
{
  ps->pm_flags &= ~0x4000u;
  ps->jumpOriginZ = 0.0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x9469E0
char __cdecl Jump_GetStepHeight(playerState_s *ps, const vec3_t *origin, float *stepSize)
{
  if ( (ps->pm_flags & 0x4000) == 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_jump.cpp",
          85,
          0,
          "(ps->pm_flags & (1<<14))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !stepSize
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_jump.cpp", 86, 0, "(stepSize)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( Dvar_GetFloat(jump_height) + ps->jumpOriginZ <= origin->z )
    return 0;
  *stepSize = Dvar_GetFloat(jump_stepSize);
  if ( *stepSize + origin->z > Dvar_GetFloat(jump_height) + ps->jumpOriginZ )
    *stepSize = Dvar_GetFloat(jump_height) + ps->jumpOriginZ - origin->z;
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x946AC0
BOOL __cdecl Jump_IsPlayerAboveMax(playerState_s *ps)
{
  if ( (ps->pm_flags & 0x4000) == 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_jump.cpp",
          104,
          0,
          "(ps->pm_flags & (1<<14))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  return ps->origin.z >= Dvar_GetFloat(jump_height) + ps->jumpOriginZ;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x946B20
void __cdecl Jump_ActivateSlowdown(playerState_s *ps)
{
  if ( !ps->pm_time )
  {
    ps->pm_flags |= 0x4000u;
    ps->pm_time = 1800;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x946B40
void __cdecl Jump_ApplySlowdown(playerState_s *ps)
{
  int pm_time; // eax
  float v3; // xmm0_4
  float scale; // [esp+Ch] [ebp+8h]

  if ( (ps->pm_flags & 0x4000) == 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_jump.cpp",
          122,
          0,
          "(ps->pm_flags & (1<<14))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  pm_time = ps->pm_time;
  scale = *(float *)&FLOAT_1_0;
  if ( pm_time <= 1800 )
  {
    if ( pm_time )
      goto LABEL_11;
    if ( (float)(ps->jumpOriginZ + 18.0) <= ps->origin.z )
    {
      v3 = FLOAT_0_5;
      ps->pm_time = 1200;
    }
    else
    {
      v3 = FLOAT_0_64999998;
      ps->pm_time = 1800;
    }
  }
  else
  {
    ps->pm_flags &= ~0x4000u;
    ps->jumpOriginZ = 0.0;
    v3 = FLOAT_0_64999998;
  }
  scale = v3;
LABEL_11:
  if ( Dvar_GetBool(jump_slowdownEnable) )
  {
    ps->velocity.x = ps->velocity.x * scale;
    ps->velocity.y = ps->velocity.y * scale;
    ps->velocity.z = ps->velocity.z * scale;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x946C30
float __usercall Jump_GetSlowdownFriction@<xmm0>(playerState_s *ps@<esi>)
{
  int pm_time; // eax

  if ( (ps->pm_flags & 0x4000) == 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_jump.cpp",
          151,
          0,
          "(ps->pm_flags & (1<<14))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( ps->pm_time > 1800
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_jump.cpp",
          152,
          0,
          "(ps->pm_time <= 1800)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !Dvar_GetBool(jump_slowdownEnable) )
    return *(float *)&FLOAT_1_0;
  pm_time = ps->pm_time;
  if ( pm_time < 1700 )
    return (float)((float)((float)pm_time * 1.5) * 0.00058823527) + 1.0;
  else
    return FLOAT_2_5;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x946CE0
double __cdecl Jump_ReduceFriction(playerState_s *ps)
{
  if ( (ps->pm_flags & 0x4000) == 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_jump.cpp",
          167,
          0,
          "(ps->pm_flags & (1<<14))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( ps->pm_time <= 1800 )
    return Jump_GetSlowdownFriction(ps);
  ps->pm_flags &= ~0x4000u;
  ps->jumpOriginZ = 0.0;
  return 1.0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x946D60
void __cdecl Jump_ClampVelocity(playerState_s *ps, const vec3_t *origin)
{
  float v3; // xmm0_4
  float v4; // xmm0_4
  float psa; // [esp+Ch] [ebp+8h]

  if ( (ps->pm_flags & 0x4000) == 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_jump.cpp",
          187,
          0,
          "(ps->pm_flags & (1<<14))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (float)(ps->origin.z - origin->z) > 0.0 )
  {
    psa = Dvar_GetFloat(jump_height);
    v3 = (float)(ps->jumpOriginZ + psa) - ps->origin.z;
    if ( v3 >= 0.1 )
    {
      v4 = fsqrt((float)ps->gravity * (float)(v3 * 2.0));
      if ( ps->velocity.z > v4 )
        ps->velocity.z = v4;
    }
    else
    {
      ps->velocity.z = 0.0;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x946E20
float __usercall Jump_GetLandFactor@<xmm0>(playerState_s *ps@<esi>)
{
  int pm_time; // eax

  if ( (ps->pm_flags & 0x4000) == 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_jump.cpp",
          209,
          0,
          "(ps->pm_flags & (1<<14))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( ps->pm_time > 1800
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_jump.cpp",
          210,
          0,
          "(ps->pm_time <= 1800)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !Dvar_GetBool(jump_slowdownEnable) )
    return *(float *)&FLOAT_1_0;
  pm_time = ps->pm_time;
  if ( pm_time < 1700 )
    return (float)((float)((float)pm_time * 1.5) * 0.00058823527) + 1.0;
  else
    return FLOAT_2_5;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x946ED0
void __cdecl Jump_Start(pmove_t *pm, pml_t *pml, float height)
{
  playerState_s *ps; // esi
  float v5; // xmm0_4
  const dvar_t *v6; // ecx
  double v7; // st7
  float velocitySqrd; // [esp+18h] [ebp+Ch]
  float factor; // [esp+1Ch] [ebp+10h]

  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_jump.cpp", 228, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v5 = (float)ps->gravity * (float)(height * 2.0);
  velocitySqrd = v5;
  if ( (ps->pm_flags & 0x4000) != 0 && ps->pm_time <= 1800 )
  {
    factor = Jump_GetLandFactor(ps);
    if ( factor == 0.0
      && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_jump.cpp", 237, 0, "(factor)", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v5 = velocitySqrd / factor;
  }
  pml->groundPlane = 0;
  pml->almostGroundPlane = 0;
  pml->walking = 0;
  ps->groundEntityNum = 1023;
  v6 = jump_spreadAdd;
  ps->jumpTime = pm->cmd.serverTime;
  ps->jumpOriginZ = ps->origin.z;
  ps->velocity.z = fsqrt(v5);
  ps->pm_flags = ps->pm_flags & 0xFFFFBE7F | 0x4000;
  ps->pm_time = 0;
  ps->sprintState.sprintButtonUpRequired = 0;
  v7 = Dvar_GetFloat(v6) + ps->aimSpreadScale;
  ps->aimSpreadScale = v7;
  if ( v7 > 255.0 )
    ps->aimSpreadScale = FLOAT_255_0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x947010
void __usercall Jump_PushOffLadder(playerState_s *ps@<esi>, pml_t *pml@<edi>)
{
  float x; // xmm1_4
  float y; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm0_4
  float z; // xmm3_4
  float v7; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  double Float; // st7
  float pushOffDir; // [esp+0h] [ebp-1Ch]
  float pushOffDir_4; // [esp+4h] [ebp-18h]
  float flatForward_4; // [esp+10h] [ebp-Ch]
  float flatForward_8; // [esp+14h] [ebp-8h]

  if ( (ps->pm_flags & 8) == 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_jump.cpp",
          272,
          0,
          "(ps->pm_flags & (1<<3))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps->velocity.z = ps->velocity.z * 0.75;
  x = pml->forward.x;
  y = pml->forward.y;
  v4 = fsqrt((float)(y * y) + (float)(x * x));
  if ( COERCE_FLOAT(LODWORD(v4) ^ _mask__NegFloat_) >= 0.0 )
    v4 = *(float *)&FLOAT_1_0;
  v5 = 1.0 / v4;
  z = ps->vLadderVec.z;
  flatForward_8 = v5 * 0.0;
  v7 = x * v5;
  v8 = ps->vLadderVec.x;
  flatForward_4 = y * v5;
  v9 = ps->vLadderVec.y;
  if ( (float)((float)((float)(v8 * pml->forward.x) + (float)(v9 * pml->forward.y)) + (float)(pml->forward.z * z)) >= 0.0 )
  {
    pushOffDir = v7;
    pushOffDir_4 = flatForward_4;
  }
  else
  {
    v10 = (float)((float)((float)(v8 * v7) + (float)(flatForward_4 * v9)) + (float)(flatForward_8 * z)) * -2.0;
    v11 = (float)(v9 * v10) + flatForward_4;
    v12 = (float)(v8 * v10) + v7;
    v13 = fsqrt(
            (float)((float)(v11 * v11) + (float)(v12 * v12))
          + (float)((float)((float)(z * v10) + flatForward_8) * (float)((float)(z * v10) + flatForward_8)));
    if ( COERCE_FLOAT(LODWORD(v13) ^ _mask__NegFloat_) >= 0.0 )
      v13 = *(float *)&FLOAT_1_0;
    pushOffDir = v12 * (float)(1.0 / v13);
    pushOffDir_4 = v11 * (float)(1.0 / v13);
  }
  Float = Dvar_GetFloat(jump_ladderPushVel);
  ps->velocity.x = pushOffDir * Float;
  ps->velocity.y = Float * pushOffDir_4;
  ps->pm_flags &= ~8u;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x9471D0
void __usercall Jump_AddSurfaceEvent(playerState_s *ps@<esi>, pml_t *pml)
{
  unsigned int v2; // eax

  if ( (ps->pm_flags & 8) != 0 )
  {
    BG_AddPredictableEventToPlayerstate(136, 0x15u, ps);
  }
  else
  {
    v2 = PM_GroundSurfaceType(ps, pml);
    if ( v2 )
      BG_AddPredictableEventToPlayerstate(136, v2, ps);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x947210
char __cdecl Jump_Check(pmove_t *pm, pml_t *pml)
{
  playerState_s *ps; // esi
  int pm_flags; // eax
  float height; // [esp+0h] [ebp-10h]

  if ( !pm && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_jump.cpp", 328, 0, "(pm)", (const char *)&pBlock) )
    __debugbreak();
  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_jump.cpp", 331, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  pm_flags = ps->pm_flags;
  if ( (pm_flags & 0x80000) != 0
    || pm->cmd.serverTime - ps->jumpTime < 500
    || (pm_flags & 0x400) != 0
    || (pm_flags & 4) != 0
    || ps->pm_type >= 10
    || PM_GetEffectiveStance(ps) && ps->groundEntityNum != 1023
    || (pm->cmd.button_bits.array[0] & 0x200000) == 0 )
  {
    return 0;
  }
  if ( (pm->oldcmd.button_bits.array[0] & 0x200000) != 0 )
  {
    pm->cmd.button_bits.array[0] &= ~0x200000u;
    return 0;
  }
  if ( (pml->groundTrace.sflags & 2) != 0
    || ps->groundEntityNum != 1023 && !funcs_947302[9 * pm->handler](pm->localClientNum, ps->groundEntityNum) )
  {
    return 0;
  }
  height = Dvar_GetFloat(jump_height);
  Jump_Start(pm, pml, height);
  Jump_AddSurfaceEvent(ps, pml);
  if ( (ps->pm_flags & 8) != 0 )
    Jump_PushOffLadder(ps, pml);
  BG_AnimScriptEvent(pm, ANIM_ET_JUMP, 0, 1, &pml->holdrand);
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpdevice.cpp:0x947360
void __usercall Mantle_RegisterDvars(double a1@<st0>)
{
  bool IsZombiesGame; // al

  mantle_enable = _Dvar_RegisterBool(a1, "mantle_enable", 1, 0x1180u, "Enable player mantling");
  mantle_debug = _Dvar_RegisterBool(a1, "mantle_debug", 0, 0x80u, "Show debug information for mantling");
  mantle_check_range = _Dvar_RegisterFloat(
                         a1,
                         "mantle_check_range",
                         20.0,
                         0.0,
                         128.0,
                         0x180u,
                         "The minimum distance from a player to a mantle surface to allow a mantle");
  IsZombiesGame = Com_SessionMode_IsZombiesGame();
  mantle_adjustment_tu = _Dvar_RegisterBool(
                           a1,
                           "mantle_adjustment_tu",
                           !IsZombiesGame,
                           0x180u,
                           "Enable the mantle adjustments for the cylindrical player collision");
  mantle_check_range_tu = _Dvar_RegisterFloat(
                            a1,
                            "mantle_check_range_mp",
                            10.0,
                            0.0,
                            128.0,
                            0x180u,
                            "The minimum distance from a player to a mantle surface to allow a mantle");
  mantle_check_radius = _Dvar_RegisterFloat(
                          a1,
                          "mantle_check_radius",
                          0.1,
                          0.0,
                          15.0,
                          0x180u,
                          "The player radius to test against while mantling");
  mantle_check_angle = _Dvar_RegisterFloat(
                         a1,
                         "mantle_check_angle",
                         60.0,
                         0.0,
                         180.0,
                         0x180u,
                         "The minimum angle from the player to a mantle surface to allow a mantle");
  mantle_check_glass_extra_range = _Dvar_RegisterFloat(
                                     a1,
                                     "mantle_check_glass_extra_range",
                                     10.0,
                                     0.0,
                                     32.0,
                                     0x180u,
                                     "The extra distance to test if glass is ");
  mantle_view_yawcap = _Dvar_RegisterFloat(
                         a1,
                         "mantle_view_yawcap",
                         60.0,
                         0.0,
                         180.0,
                         0x180u,
                         "The angle at which to restrict a sideways turn while mantling");
  mantle_weapon_height = _Dvar_RegisterFloat(
                           a1,
                           "mantle_weapon_height",
                           39.0,
                           0.0,
                           s_mantleTrans[0].height,
                           0x180u,
                           "If the player is mantling at this height or lower, his weapon will remain equipped.");
  mantle_weapon_anim_height = _Dvar_RegisterFloat(
                                a1,
                                "mantle_weapon_anim_height",
                                32.0,
                                0.0,
                                s_mantleTrans[0].height,
                                0x180u,
                                "If the player is mantling at this height or higher, the mantle animation will play.");
  vehicle_push_during_mantle = _Dvar_RegisterBool(a1, "vehicle_push_during_mantle", 1, 0x180u, "Enable player mantling");
  prone_bipod_enable = _Dvar_RegisterBool(a1, "prone_bipod_enable", 1, 0x180u, "Enable bipods whilst prone");
  hatch_mantle_up = _Dvar_RegisterFloat(a1, "hatch_mantle_up", 10.0, -256.0, 256.0, 0x180u, "hatch_mantle_up");
  hatch_mantle_fwd = _Dvar_RegisterFloat(a1, "hatch_mantle_fwd", 44.0, -256.0, 256.0, 0x180u, "hatch_mantle_fwd");
}

#endif // __UNIMPLEMENTED__
