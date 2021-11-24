// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdgethostbyname.cpp:0x944940
void __cdecl BG_CalculateRotorArms(
        const VehicleDef *vehDef,
        const vec3_t *velocity,
        const vec3_t *angles,
        const vec3_t *angVelocity,
        entityState_s *s,
        const float scale)
{
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm5_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  __m128 maxRotorArmMovementAngle_low; // xmm1
  float v16; // xmm4_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  __m128 v19; // xmm3
  float v20; // xmm4_4
  __m128 v21; // xmm0
  __m128 v22; // xmm2
  __m128 v23; // xmm7
  __m128 v24; // xmm2
  __m128 v25; // xmm3
  __m128 v26; // xmm0
  int v27; // edx
  __m128 v28; // xmm2
  __m128 v29; // xmm4
  __m128 v30; // xmm7
  __m128 v31; // xmm3
  __m128 v32; // xmm4
  int v33; // eax
  __m128 v34; // xmm4
  __m128 v35; // xmm2
  __m128 v36; // xmm3
  int v37; // ecx
  __m128 v38; // xmm3
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  float angle_from_sideways_movement; // [esp+4h] [ebp-24h]
  float angle_from_rotation; // [esp+8h] [ebp-20h]
  LocalClientNum_t angle_from_rotationa; // [esp+8h] [ebp-20h]
  float angle_from_rotationb; // [esp+8h] [ebp-20h]
  vec3_t tgtRight; // [esp+Ch] [ebp-1Ch] BYREF
  vec3_t tgtDir; // [esp+18h] [ebp-10h] BYREF

  AngleVectors(angles, &tgtDir, &tgtRight, 0);
  v6 = (float)(velocity->x * tgtDir.x) + (float)(velocity->y * tgtDir.y);
  v7 = FLOAT_N1_0;
  v8 = (float)((float)(-1.0 / vehDef->rotRate) * angVelocity->y) * rotScalar;
  v9 = (float)(tgtRight.y * (float)((float)(tgtDir.y * COERCE_FLOAT(LODWORD(v6) ^ _mask__NegFloat_)) + velocity->y))
     + (float)(tgtRight.x * (float)((float)(tgtDir.x * COERCE_FLOAT(LODWORD(v6) ^ _mask__NegFloat_)) + velocity->x));
  if ( (float)(v8 - 1.0) < 0.0 )
    v10 = (float)((float)(-1.0 / vehDef->rotRate) * angVelocity->y) * rotScalar;
  else
    v10 = *(float *)&FLOAT_1_0;
  if ( (float)(-1.0 - v8) < 0.0 )
    v11 = v10;
  else
    v11 = FLOAT_N1_0;
  v12 = vehDef->maxRotorArmRotationAngle * v11;
  v13 = 1.0 / vehDef->maxSpeed;
  v14 = (float)(v13 * v6) * moveScalar;
  if ( (float)(v14 - 1.0) < 0.0 )
    angle_from_rotation = (float)(v13 * v6) * moveScalar;
  else
    angle_from_rotation = *(float *)&FLOAT_1_0;
  if ( (float)(-1.0 - v14) < 0.0 )
    v7 = angle_from_rotation;
  maxRotorArmMovementAngle_low = (__m128)LODWORD(vehDef->maxRotorArmMovementAngle);
  maxRotorArmMovementAngle_low.m128_f32[0] = maxRotorArmMovementAngle_low.m128_f32[0] * v7;
  v16 = (float)(v13 * v9) * moveScalar;
  if ( (float)(v16 - 1.0) < 0.0 )
    angle_from_rotationa = LODWORD(v16);
  else
    angle_from_rotationa = FLOAT_1_0;
  v17 = FLOAT_N1_0;
  if ( (float)(-1.0 - v16) < 0.0 )
    v17 = *(float *)&angle_from_rotationa;
  maxRotorArmMovementAngle_low.m128_f32[0] = maxRotorArmMovementAngle_low.m128_f32[0] * scale;
  v18 = vehDef->maxRotorArmMovementAngle * v17;
  v19.m128_f32[0] = FLOAT_8388608_0;
  angle_from_rotationb = v12 * scale;
  angle_from_sideways_movement = v18;
  v20 = v18 * 182.03889;
  v21 = maxRotorArmMovementAngle_low;
  v21.m128_f32[0] = (float)((float)((float)(maxRotorArmMovementAngle_low.m128_f32[0] + (float)(v12 * scale)) * 182.03889)
                          + v20)
                  + 0.5;
  v22 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v21);
  v23.m128_i32[0] = v22.m128_i32[0];
  v19.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v21, v22), v19).m128_u32[0] | v22.m128_i32[0];
  v24 = v21;
  v24.m128_f32[0] = (float)(v21.m128_f32[0] + v19.m128_f32[0]) - v19.m128_f32[0];
  v25 = v24;
  v25.m128_f32[0] = v24.m128_f32[0] - v21.m128_f32[0];
  v26 = (__m128)LODWORD(angle_from_rotationb);
  v27 = (int)(float)(v24.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v25, v23).m128_u32[0] & FLOAT_1_0));
  v26.m128_f32[0] = angle_from_rotationb - maxRotorArmMovementAngle_low.m128_f32[0];
  v28 = v26;
  v28.m128_f32[0] = (float)((float)((float)(angle_from_rotationb - maxRotorArmMovementAngle_low.m128_f32[0]) * 182.03889)
                          + v20)
                  + 0.5;
  v29.m128_f32[0] = FLOAT_8388608_0;
  v30 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v28);
  v29.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v28, v30), v29).m128_u32[0];
  v31 = v28;
  v31.m128_f32[0] = (float)(v28.m128_f32[0] + COERCE_FLOAT(v29.m128_i32[0] | v30.m128_i32[0]))
                  - COERCE_FLOAT(v29.m128_i32[0] | v30.m128_i32[0]);
  v32 = v31;
  v32.m128_f32[0] = v31.m128_f32[0] - v28.m128_f32[0];
  v33 = (int)(float)(v31.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v32, v30).m128_u32[0] & FLOAT_1_0));
  v31.m128_f32[0] = FLOAT_8388608_0;
  maxRotorArmMovementAngle_low.m128_f32[0] = (float)((float)((float)(maxRotorArmMovementAngle_low.m128_f32[0]
                                                                   + angle_from_rotationb)
                                                           - angle_from_sideways_movement)
                                                   * 182.03889)
                                           + 0.5;
  v34 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), maxRotorArmMovementAngle_low);
  v31.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(maxRotorArmMovementAngle_low, v34), v31).m128_u32[0] | v34.m128_i32[0];
  v35 = maxRotorArmMovementAngle_low;
  v35.m128_f32[0] = (float)(maxRotorArmMovementAngle_low.m128_f32[0] + v31.m128_f32[0]) - v31.m128_f32[0];
  v36 = v35;
  v36.m128_f32[0] = v35.m128_f32[0] - maxRotorArmMovementAngle_low.m128_f32[0];
  s->lerp.u.vehicle.gunnerAngles[0].yaw = v27;
  s->lerp.u.vehicle.gunnerAngles[1].yaw = v33;
  v37 = (int)(float)(v35.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v36, v34).m128_u32[0] & FLOAT_1_0));
  v35.m128_f32[0] = FLOAT_8388608_0;
  v26.m128_f32[0] = (float)((float)(v26.m128_f32[0] - angle_from_sideways_movement) * 182.03889) + 0.5;
  v38 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v26);
  v35.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v26, v38), v35).m128_u32[0] | v38.m128_i32[0];
  v39 = v26;
  v39.m128_f32[0] = (float)(v26.m128_f32[0] + v35.m128_f32[0]) - v35.m128_f32[0];
  v40 = v39;
  v40.m128_f32[0] = v39.m128_f32[0] - v26.m128_f32[0];
  s->lerp.u.vehicle.gunnerAngles[2].yaw = v37;
  s->lerp.u.actor.aiType = (int)(float)(v39.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v40, v38).m128_u32[0] & FLOAT_1_0));
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdgethostbyname.cpp:0x944C80
void __usercall BG_HeliCalcAccel(
        vec3_t *bodyAccel@<ecx>,
        vec3_t *rotAccel@<edx>,
        const pmove_t *pm,
        const pml_t *pml,
        VehicleState *vehicleState,
        vec4_t *moveRequest)
{
  const VehicleDef *VehicleDef; // edi
  float maxSpeedVertical; // xmm7_4
  float accelVertical; // xmm5_4
  float accel; // xmm2_4
  bool v10; // zf
  float v11; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm5_4
  float x; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm4_4
  unsigned int v19; // xmm6_4
  int i; // esi
  float frametime; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm5_4
  float v24; // xmm4_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm3_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  bool v33; // cf
  float v34; // xmm1_4
  playerState_s *ps; // eax
  __m128 v36; // xmm0
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  __m128 v39; // xmm4
  __m128 v40; // xmm2
  __m128 v41; // xmm3
  float rotRate; // xmm2_4
  float v43; // xmm0_4
  float tgt; // xmm1_4
  float v45; // xmm1_4
  float v46; // xmm2_4
  float v47; // xmm0_4
  int j; // esi
  float v49; // xmm2_4
  float v50; // xmm7_4
  float vehHelicopterTiltFromControllerAxes; // xmm6_4
  float v52; // xmm4_4
  float v53; // xmm0_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm3_4
  float vehHelicopterTiltFromFwdAndYaw_VelAtMaxTilt; // xmm1_4
  float v58; // xmm0_4
  float v59; // xmm0_4
  float v60; // xmm0_4
  float v61; // xmm1_4
  float vehHelicopterTiltMomentum; // xmm0_4
  float v63; // xmm4_4
  float v64; // xmm0_4
  float v65; // xmm2_4
  float v66; // xmm6_4
  float v67; // xmm0_4
  float v68; // xmm3_4
  float v69; // xmm1_4
  float v70; // xmm6_4
  float v71; // xmm1_4
  float v72; // xmm3_4
  float v73; // xmm2_4
  float v74; // xmm0_4
  bool v75; // cc
  float v76; // xmm0_4
  float v77; // xmm1_4
  bool v78; // cc
  float deltaTime; // [esp+Ch] [ebp-D8h]
  float v80; // [esp+1Ch] [ebp-C8h]
  float cur; // [esp+20h] [ebp-C4h]
  float rate; // [esp+24h] [ebp-C0h]
  float tgtSpeed; // [esp+28h] [ebp-BCh]
  float v86; // [esp+34h] [ebp-B0h]
  float v87; // [esp+34h] [ebp-B0h]
  float speedParallel; // [esp+38h] [ebp-ACh]
  float speedParallela; // [esp+38h] [ebp-ACh]
  float velScale; // [esp+44h] [ebp-A0h]
  float velScalea; // [esp+44h] [ebp-A0h]
  float velScaleb; // [esp+44h] [ebp-A0h]
  float velScalec; // [esp+44h] [ebp-A0h]
  float tgtYawVel; // [esp+48h] [ebp-9Ch]
  float tgtYawVela; // [esp+48h] [ebp-9Ch]
  vec2_t decel; // [esp+4Ch] [ebp-98h]
  vec3_t velParallel; // [esp+54h] [ebp-90h] BYREF
  vec4_t track; // [esp+60h] [ebp-84h]
  vec3_t maxAccel; // [esp+70h] [ebp-74h]
  vec3_t maxSpeed; // [esp+7Ch] [ebp-68h]
  vec2_t newDecel; // [esp+88h] [ebp-5Ch]
  vec3_t tgtVel; // [esp+90h] [ebp-54h]
  vec2_t newAccel; // [esp+9Ch] [ebp-48h]
  vec3_t pitchAngles; // [esp+A4h] [ebp-40h] BYREF
  vec3_t bodyAxis[4]; // [esp+B0h] [ebp-34h] BYREF

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp", 133, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !pm->ps
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          134,
          0,
          "(pm->ps)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  VehicleDef = BG_GetVehicleDef(pm);
  if ( !VehicleDef
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          137,
          0,
          "(vehDef)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  maxSpeedVertical = VehicleDef->maxSpeedVertical;
  accelVertical = VehicleDef->accelVertical;
  accel = VehicleDef->accel;
  maxSpeed.x = VehicleDef->maxSpeed;
  *(_QWORD *)&maxSpeed.v[1] = __PAIR64__(LODWORD(maxSpeedVertical), LODWORD(maxSpeed.x));
  maxAccel.x = accel;
  *(_QWORD *)&maxAccel.v[1] = __PAIR64__(LODWORD(accelVertical), LODWORD(accel));
  if ( maxSpeed.x == 0.0 )
    LODWORD(track.v[0]) = FLOAT_1_0;
  else
    track.v[0] = accel / maxSpeed.x;
  if ( maxSpeed.x == 0.0 )
    LODWORD(track.v[1]) = FLOAT_1_0;
  else
    track.v[1] = accel / maxSpeed.x;
  if ( maxSpeedVertical == 0.0 )
    LODWORD(track.v[2]) = FLOAT_1_0;
  else
    track.v[2] = accelVertical / maxSpeedVertical;
  v10 = VehicleDef->vehHelicopterAccelTwardsView == 0;
  v11 = maxSpeed.x * moveRequest->v[0];
  y = moveRequest->v[1] * maxSpeed.x;
  z = moveRequest->v[2] * maxSpeedVertical;
  tgtVel.x = v11;
  *(_QWORD *)&tgtVel.v[1] = __PAIR64__(LODWORD(z), LODWORD(y));
  if ( !v10 && pm->ps->fWeaponPosFrac < 1.0 && pm->cmd.button_bits.array[0] >= 0 && (!not_backwards || v11 > 0.0) )
  {
    *(_QWORD *)&pitchAngles.x = LODWORD(pm->ps->viewangles.x);
    pitchAngles.z = 0.0;
    AngleVectors(&pitchAngles, bodyAxis, &bodyAxis[1], &bodyAxis[2]);
    y = tgtVel.y;
    maxSpeedVertical = maxSpeed.z;
    v11 = (float)((float)(bodyAxis[1].x * tgtVel.y) + (float)(bodyAxis[0].x * tgtVel.x)) + (float)(bodyAxis[2].x * 0.0);
    z = (float)((float)((float)(bodyAxis[0].z * tgtVel.x) + (float)(bodyAxis[1].z * tgtVel.y))
              + (float)(bodyAxis[2].z * 0.0))
      + tgtVel.z;
    tgtVel.x = v11;
    tgtVel.z = z;
  }
  v14 = (float)(y * y) + (float)(v11 * v11);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(fsqrt(v14)) ^ _mask__NegFloat_) < 0.0 )
    v15 = fsqrt(v14);
  else
    v15 = *(float *)&FLOAT_1_0;
  x = v11 * (float)(1.0 / v15);
  v17 = y * (float)(1.0 / v15);
  *(_QWORD *)&pitchAngles.x = __PAIR64__(LODWORD(v17), LODWORD(x));
  if ( maxSpeedVertical == 0.0 )
  {
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
            205,
            0,
            "(maxSpeed[2])",
            (const char *)&pBlock) )
      __debugbreak();
    maxSpeedVertical = maxSpeed.z;
    z = tgtVel.z;
    x = pitchAngles.x;
    v17 = pitchAngles.y;
  }
  tgtSpeed = fsqrt((float)(z * z) + v14);
  if ( tgtSpeed >= 1.0 )
  {
    LODWORD(v18) = COERCE_UNSIGNED_INT((float)(v17 * vehicleState->bodyVelocity.y) + (float)(x
                                                                                           * vehicleState->bodyVelocity.x)) ^ _mask__NegFloat_;
    *(float *)&v19 = (float)(v17 * v18) + vehicleState->bodyVelocity.y;
    speedParallel = (float)(v17 * vehicleState->bodyVelocity.y) + (float)(x * vehicleState->bodyVelocity.x);
    pitchAngles.x = (float)(x * v18) + vehicleState->bodyVelocity.x;
    *(_QWORD *)&pitchAngles.v[1] = v19;
    velParallel.x = x * speedParallel;
    velParallel.y = v17 * speedParallel;
    velParallel.z = (float)(z / maxSpeedVertical) * tgtVel.z;
  }
  else
  {
    pitchAngles = vehicleState->bodyVelocity;
    tgtSpeed = 0.0;
    speedParallel = 0.0;
    memset(&velParallel, 0, sizeof(velParallel));
  }
  decel = *(vec2_t *)&VehicleDef->vehHelicopterDecelerationFwd;
  newAccel = 0i64;
  newDecel = 0i64;
  for ( i = 0; i < 2; ++i )
  {
    v80 = track.v[i];
    rate = decel.v[i] * v80;
    cur = *(float *)((char *)&pitchAngles.x + i * 4);
    velScale = DiffTrack(0.0, cur, rate, pml->frametime);
    frametime = pml->frametime;
    newDecel.v[i] = (float)(velScale - cur) / frametime;
    v22 = *(float *)((char *)&velParallel.x + i * 4);
    if ( tgtSpeed <= speedParallel )
    {
      velScaleb = DiffTrack(*(float *)((char *)&tgtVel.x + i * 4), v22, rate, frametime);
      newDecel.v[i] = (float)((float)(velScaleb - v22) / pml->frametime) + newDecel.v[i];
    }
    else
    {
      velScalea = DiffTrack(*(float *)((char *)&tgtVel.x + i * 4), v22, v80, frametime);
      newAccel.v[i] = (float)((float)(velScalea - v22) / pml->frametime) + newAccel.v[i];
    }
    v23 = newAccel.v[i];
    v24 = newDecel.v[i];
    v25 = *(float *)((char *)&maxAccel.x + i * 4);
    *(float *)((char *)&bodyAccel->x + i * 4) = v23 + v24;
    LODWORD(v26) = LODWORD(v25) ^ _mask__NegFloat_;
    if ( (float)((float)(v23 + v24) - v25) < 0.0 )
      v86 = v23 + v24;
    else
      v86 = v25;
    if ( (float)(v26 - (float)(v23 + v24)) < 0.0 )
      v27 = v86;
    else
      LODWORD(v27) = LODWORD(v25) ^ _mask__NegFloat_;
    *(float *)((char *)&bodyAccel->x + i * 4) = v27;
    if ( (float)(v24 - v25) < 0.0 )
      v28 = v24;
    else
      v28 = v25;
    if ( (float)(v26 - v24) >= 0.0 )
      LODWORD(v28) = LODWORD(v25) ^ _mask__NegFloat_;
    newDecel.v[i] = v28;
    if ( (float)(v23 - v25) < 0.0 )
      v25 = v23;
    if ( (float)(v26 - v23) < 0.0 )
      v26 = v25;
    newAccel.v[i] = v26;
  }
  v29 = vehicleState->bodyVelocity.z;
  if ( (v29 <= tgtVel.z || v29 <= 0.0) && (tgtVel.z <= v29 || v29 >= 0.0) )
    v30 = track.v[2];
  else
    v30 = VehicleDef->vehHelicopterDecelerationUp * track.v[2];
  velScalec = DiffTrack(tgtVel.z, v29, v30, pml->frametime);
  v31 = (float)(velScalec - vehicleState->bodyVelocity.z) / pml->frametime;
  v32 = maxAccel.z;
  v33 = (float)(v31 - maxAccel.z) < 0.0;
  bodyAccel->z = v31;
  LODWORD(v34) = LODWORD(v32) ^ _mask__NegFloat_;
  if ( v33 )
    v32 = v31;
  if ( (float)(v34 - v31) < 0.0 )
    v34 = v32;
  bodyAccel->z = v34;
  if ( VehicleDef->rotRate <= 0.0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          261,
          0,
          "(vehDef->rotRate > 0.0f)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = pm->ps;
  deltaTime = pml->frametime;
  track.v[3] = VehicleDef->rotAccel / VehicleDef->rotRate;
  tgtYawVel = DiffTrackAngle(ps->viewangles.y, vehicleState->previousAngles.y, track.v[3], deltaTime);
  v36 = (__m128)LODWORD(tgtYawVel);
  v36.m128_f32[0] = (float)(tgtYawVel - vehicleState->previousAngles.y) * 0.0027777778;
  v37.m128_f32[0] = FLOAT_8388608_0;
  v38 = v36;
  v38.m128_f32[0] = v36.m128_f32[0] + 0.5;
  v39 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v38);
  v37.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v38, v39), v37).m128_u32[0] | v39.m128_i32[0];
  v40 = v38;
  v40.m128_f32[0] = (float)((float)(v36.m128_f32[0] + 0.5) + v37.m128_f32[0]) - v37.m128_f32[0];
  v41 = v40;
  v41.m128_f32[0] = v40.m128_f32[0] - (float)(v36.m128_f32[0] + 0.5);
  v36.m128_f32[0] = (float)(v36.m128_f32[0]
                          - (float)(v40.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v41, v39).m128_u32[0] & FLOAT_1_0)))
                  * 360.0;
  rotRate = VehicleDef->rotRate;
  v43 = v36.m128_f32[0] * (float)(1.0 / pml->frametime);
  LODWORD(tgt) = LODWORD(rotRate) ^ _mask__NegFloat_;
  if ( (float)(v43 - rotRate) < 0.0 )
    rotRate = v43;
  if ( (float)(tgt - v43) < 0.0 )
    tgt = rotRate;
  if ( COERCE_FLOAT(LODWORD(tgt) & _mask__AbsFloat_) > COERCE_FLOAT(LODWORD(vehicleState->angVelocity.y) & _mask__AbsFloat_) )
  {
    tgtYawVela = DiffTrack(tgt, vehicleState->angVelocity.y, track.v[3], pml->frametime);
    tgt = tgtYawVela;
  }
  v45 = (float)(tgt - vehicleState->angVelocity.y) / pml->frametime;
  rotAccel->y = v45;
  v46 = VehicleDef->rotAccel;
  LODWORD(v47) = LODWORD(v46) ^ _mask__NegFloat_;
  if ( (float)(v45 - v46) < 0.0 )
    v46 = v45;
  if ( (float)(v47 - v45) < 0.0 )
    v47 = v46;
  rotAccel->y = v47;
  for ( j = 0; j < 8; j += 4 )
  {
    if ( *(float *)((char *)&maxSpeed.x + j) <= 0.0 )
    {
      if ( VehicleDef->maxSpeed <= 0.0
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
              278,
              0,
              "(vehDef->maxSpeed > 0.0f)",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      *(float *)((char *)&maxSpeed.x + j) = VehicleDef->maxSpeed * 17.6;
    }
    if ( *(float *)((char *)&maxAccel.x + j) <= 0.0 )
    {
      if ( VehicleDef->accel <= 0.0
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
              283,
              0,
              "(vehDef->accel > 0.0f)",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      *(float *)((char *)&maxAccel.x + j) = VehicleDef->accel * 17.6;
    }
  }
  v49 = *(float *)&FLOAT_1_0;
  v50 = vehicleState->bodyVelocity.x;
  vehHelicopterTiltFromControllerAxes = VehicleDef->vehHelicopterTiltFromControllerAxes;
  v52 = 1.0 / maxSpeed.x;
  v53 = (float)((float)(newDecel.v[0] * (float)(1.0 / maxAccel.x)) * VehicleDef->tiltFromDeceleration[0])
      + (float)((float)((float)(newAccel.v[0] * (float)(1.0 / maxAccel.x)) * VehicleDef->tiltFromAcceleration[0])
              + (float)((float)((float)((float)(1.0 / maxSpeed.x) * v50) * VehicleDef->tiltFromVelocity[0])
                      + (float)((float)(tgtVel.x * (float)(1.0 / maxSpeed.x)) * vehHelicopterTiltFromControllerAxes)));
  speedParallela = 1.0 / maxSpeed.x;
  if ( (float)(v53 - 1.0) < 0.0 )
    v87 = (float)((float)(newDecel.v[0] * (float)(1.0 / maxAccel.x)) * VehicleDef->tiltFromDeceleration[0])
        + (float)((float)((float)(newAccel.v[0] * (float)(1.0 / maxAccel.x)) * VehicleDef->tiltFromAcceleration[0])
                + (float)((float)((float)((float)(1.0 / maxSpeed.x) * v50) * VehicleDef->tiltFromVelocity[0])
                        + (float)((float)(tgtVel.x * (float)(1.0 / maxSpeed.x)) * vehHelicopterTiltFromControllerAxes)));
  else
    v87 = *(float *)&FLOAT_1_0;
  if ( (float)(-1.0 - v53) < 0.0 )
    pitchAngles.x = v87;
  else
    pitchAngles.x = FLOAT_N1_0;
  v54 = (float)((float)(newDecel.v[1] * (float)(1.0 / maxAccel.y)) * VehicleDef->tiltFromDeceleration[1])
      + (float)((float)((float)(newAccel.v[1] * (float)(1.0 / maxAccel.y)) * VehicleDef->tiltFromAcceleration[1])
              + (float)((float)((float)((float)(1.0 / maxSpeed.y) * tgtVel.y) * vehHelicopterTiltFromControllerAxes)
                      + (float)((float)(vehicleState->bodyVelocity.y * (float)(1.0 / maxSpeed.y))
                              * VehicleDef->tiltFromVelocity[1])));
  if ( (float)(v54 - 1.0) < 0.0 )
    v55 = (float)((float)(newDecel.v[1] * (float)(1.0 / maxAccel.y)) * VehicleDef->tiltFromDeceleration[1])
        + (float)((float)((float)(newAccel.v[1] * (float)(1.0 / maxAccel.y)) * VehicleDef->tiltFromAcceleration[1])
                + (float)((float)((float)((float)(1.0 / maxSpeed.y) * tgtVel.y) * vehHelicopterTiltFromControllerAxes)
                        + (float)((float)(vehicleState->bodyVelocity.y * (float)(1.0 / maxSpeed.y))
                                * VehicleDef->tiltFromVelocity[1])));
  else
    v55 = *(float *)&FLOAT_1_0;
  v56 = FLOAT_N1_0;
  if ( (float)(-1.0 - v54) >= 0.0 )
    v55 = FLOAT_N1_0;
  pitchAngles.y = v55;
  if ( v50 > 0.0 && COERCE_FLOAT(LODWORD(vehicleState->angVelocity.y) & _mask__AbsFloat_) > 0.0 )
  {
    if ( maxSpeed.x <= 0.0 )
    {
      if ( !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
              310,
              0,
              "(maxSpeed[0] > 0)",
              (const char *)&pBlock) )
        __debugbreak();
      v52 = speedParallela;
    }
    vehHelicopterTiltFromFwdAndYaw_VelAtMaxTilt = VehicleDef->vehHelicopterTiltFromFwdAndYaw_VelAtMaxTilt;
    v58 = vehicleState->bodyVelocity.x * v52;
    if ( vehHelicopterTiltFromFwdAndYaw_VelAtMaxTilt <= v58 )
    {
      v59 = *(float *)&FLOAT_1_0;
    }
    else
    {
      if ( vehHelicopterTiltFromFwdAndYaw_VelAtMaxTilt <= 0.0
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
              314,
              1,
              "(vehDef->vehHelicopterTiltFromFwdAndYaw_VelAtMaxTilt > 0)",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v59 = v58 / VehicleDef->vehHelicopterTiltFromFwdAndYaw_VelAtMaxTilt;
    }
    if ( VehicleDef->rotRate <= 0.0
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
            320,
            0,
            "(vehDef->rotRate > 0.0f)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v49 = *(float *)&FLOAT_1_0;
    v56 = FLOAT_N1_0;
    v55 = (float)((float)((float)(-1.0 / VehicleDef->rotRate) * vehicleState->angVelocity.y)
                * (float)(VehicleDef->vehHelicopterTiltFromFwdAndYaw * v59))
        + pitchAngles.y;
  }
  if ( (float)(v55 - v49) < 0.0 )
    v49 = v55;
  if ( (float)(v56 - v55) < 0.0 )
    v60 = v49;
  else
    v60 = v56;
  v61 = pitchAngles.x - vehicleState->tilt.v[0];
  newAccel.v[1] = v60 - vehicleState->tilt.v[1];
  vehHelicopterTiltMomentum = VehicleDef->vehHelicopterTiltMomentum;
  newAccel.v[0] = v61;
  if ( vehHelicopterTiltMomentum == 0.0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          330,
          0,
          "(vehDef->vehHelicopterTiltMomentum)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v63 = vehicleState->tiltVelocity.v[0];
  v64 = 1.0 / VehicleDef->vehHelicopterTiltMomentum;
  v65 = (float)(VehicleDef->tiltSpeed[0] * v64) * newAccel.v[0];
  v66 = v64 * -1.0;
  v67 = (float)(vehicleState->tiltVelocity.v[1] * (float)(v64 * -1.0))
      + (float)((float)(VehicleDef->tiltSpeed[1] * v64) * newAccel.v[1]);
  v68 = vehicleState->tiltVelocity.v[1];
  v69 = v63 * v66;
  v70 = pml->frametime;
  v71 = (float)((float)(v69 + v65) * v70) + v63;
  vehicleState->tiltVelocity.v[0] = v71;
  vehicleState->tiltVelocity.v[1] = (float)(v67 * v70) + vehicleState->tiltVelocity.v[1];
  v72 = v68 + vehicleState->tiltVelocity.v[1];
  v73 = pml->frametime;
  v74 = (float)((float)((float)(v63 + v71) * 0.5) * v73) + vehicleState->tilt.v[0];
  vehicleState->tilt.v[0] = v74;
  vehicleState->tilt.v[1] = (float)((float)(0.5 * v72) * v73) + vehicleState->tilt.v[1];
  if ( v74 <= 1.0 )
  {
    if ( v74 >= -1.0 )
      goto LABEL_131;
    v75 = vehicleState->tiltVelocity.v[0] >= 0.0;
    vehicleState->tilt.v[0] = FLOAT_N1_0;
  }
  else
  {
    LODWORD(vehicleState->tilt.v[0]) = FLOAT_1_0;
    v75 = vehicleState->tiltVelocity.v[0] <= 0.0;
  }
  if ( !v75 )
    vehicleState->tiltVelocity.v[0] = 0.0;
LABEL_131:
  v76 = vehicleState->tilt.v[1];
  v77 = *(float *)&FLOAT_1_0;
  if ( v76 <= 1.0 )
  {
    v77 = FLOAT_N1_0;
    if ( v76 >= -1.0 )
      goto LABEL_137;
    v78 = vehicleState->tiltVelocity.v[1] >= 0.0;
  }
  else
  {
    v78 = vehicleState->tiltVelocity.v[1] <= 0.0;
  }
  vehicleState->tilt.v[1] = v77;
  if ( !v78 )
    vehicleState->tiltVelocity.v[1] = 0.0;
LABEL_137:
  rotAccel->x = VehicleDef->maxBodyPitch * vehicleState->tilt.v[0];
  rotAccel->z = VehicleDef->maxBodyRoll * vehicleState->tilt.v[1];
  if ( ((LODWORD(bodyAccel->x) & 0x7F800000) == 2139095040
     || (LODWORD(bodyAccel->y) & 0x7F800000) == 2139095040
     || (LODWORD(bodyAccel->z) & 0x7F800000) == 2139095040)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          375,
          0,
          "(!IS_NAN((bodyAccel)[0]) && !IS_NAN((bodyAccel)[1]) && !IS_NAN((bodyAccel)[2]))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( ((LODWORD(rotAccel->x) & 0x7F800000) == 2139095040
     || (LODWORD(rotAccel->y) & 0x7F800000) == 2139095040
     || (LODWORD(rotAccel->z) & 0x7F800000) == 2139095040)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          376,
          0,
          "(!IS_NAN((rotAccel)[0]) && !IS_NAN((rotAccel)[1]) && !IS_NAN((rotAccel)[2]))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
}

#endif // __UNIMPLEMENTED__
