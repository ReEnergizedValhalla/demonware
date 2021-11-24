// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdupnpconfig.cpp:0x945C50
void __cdecl BG_PlayerStateToVehicleStateHelicopter(
        LocalClientNum_t localClientNum,
        const playerState_s *ps,
        entityState_s *s,
        const VehicleDef *vehDef)
{
  if ( vehDef->vehHelicopterQuadRotor )
    BG_CalculateRotorArms(
      vehDef,
      &ps->vehicleState.velocity,
      &ps->vehicleState.angles,
      &ps->vehicleState.angVelocity,
      s,
      1.0);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdupnpconfig.cpp:0x945CA0
// local variable allocation has failed, the output may be wrong!
double __usercall BG_HeliMaintainHeight_CalcAccel@<st0>(
        int a1@<ebp>,
        pmove_t *pm,
        const pml_t *pml,
        VehicleState *vehicleState)
{
  const VehicleDef *VehicleDef; // edi
  float v5; // xmm6_4
  float v6; // xmm0_4
  float vehHelicopterMaintainHeightLimit; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float vehHelicopterMaintainHeightMinimum; // xmm0_4
  float vehHelicopterMaintainCeilingMinimum; // xmm0_4
  float targetHeightDelta; // xmm2_4
  float v15; // xmm5_4
  float z; // xmm0_4
  char v17; // al
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  float dt; // [esp+10h] [ebp-F4h]
  char v26; // [esp+33h] [ebp-D1h]
  float v27; // [esp+34h] [ebp-D0h]
  _BYTE moveStrength[176]; // [esp+38h] [ebp-CCh] OVERLAPPED BYREF
  int v30; // [esp+F8h] [ebp-Ch]
  int v31; // [esp+FCh] [ebp-8h]
  int retaddr; // [esp+104h] [ebp+0h]

  v30 = a1;
  v31 = retaddr;
  VehicleDef = BG_GetVehicleDef(pm);
  *(_OWORD *)&moveStrength[160] = 0i64;
  *(_OWORD *)&moveStrength[64] = 0i64;
  *(_DWORD *)&moveStrength[144] = 0;
  v26 = 0;
  BG_HelicopterGroundTrace(
    pm,
    vehicleState,
    (GroundTrace *)&moveStrength[64],
    pml->frametime,
    VehicleDef->vehHelicopterMaintainHeightMaximum);
  v5 = *(float *)&moveStrength[136];
  if ( VehicleDef->vehHelicopterMaintainHeight && *(_DWORD *)&moveStrength[144] )
  {
    if ( vehicleState->lastGroundHeight == 0.0 && vehicleState->targetHeightDelta == 0.0 )
      vehicleState->lastGroundHeight = *(float *)&moveStrength[136];
    v6 = v5 - vehicleState->lastGroundHeight;
    if ( VehicleDef->vehHelicopterMaintainHeightLimit == 0.0 )
    {
      v11 = vehicleState->targetHeightDelta - v6;
    }
    else
    {
      vehHelicopterMaintainHeightLimit = VehicleDef->vehHelicopterMaintainHeightLimit;
      LODWORD(v8) = LODWORD(vehHelicopterMaintainHeightLimit) ^ _mask__NegFloat_;
      if ( (float)(v6 - vehHelicopterMaintainHeightLimit) < 0.0 )
        vehHelicopterMaintainHeightLimit = v5;
      if ( (float)(v8 - v6) < 0.0 )
        v8 = vehHelicopterMaintainHeightLimit;
      v9 = VehicleDef->vehHelicopterMaintainHeightLimit;
      v10 = vehicleState->targetHeightDelta - v8;
      LODWORD(v11) = LODWORD(v9) ^ _mask__NegFloat_;
      if ( (float)(v10 - v9) < 0.0 )
        v9 = v10;
      if ( (float)(v11 - v10) < 0.0 )
        v11 = v9;
    }
    vehicleState->targetHeightDelta = v11;
    vehHelicopterMaintainHeightMinimum = VehicleDef->vehHelicopterMaintainHeightMinimum;
    if ( vehHelicopterMaintainHeightMinimum > 0.001
      && vehHelicopterMaintainHeightMinimum > v11
      && vehHelicopterMaintainHeightMinimum > (float)(vehicleState->origin.z - v5) )
    {
      v26 = 1;
    }
  }
  vehHelicopterMaintainCeilingMinimum = VehicleDef->vehHelicopterMaintainCeilingMinimum;
  targetHeightDelta = vehicleState->targetHeightDelta;
  v15 = *(float *)&FLOAT_1_0;
  v27 = targetHeightDelta;
  if ( vehHelicopterMaintainCeilingMinimum <= 0.001 )
  {
    z = vehicleState->origin.z;
  }
  else
  {
    dt = pml->frametime;
    *(_OWORD *)moveStrength = *(_OWORD *)&moveStrength[160];
    BG_HelicopterHeightTrace(
      pm,
      vehicleState,
      (trace_t *)moveStrength,
      (vec3_t *)&moveStrength[164],
      dt,
      vehHelicopterMaintainCeilingMinimum);
    v15 = *(float *)&FLOAT_1_0;
    v5 = *(float *)&moveStrength[136];
    z = *(float *)&moveStrength[172];
    if ( *(float *)&moveStrength[16] < 1.0 )
    {
      v17 = 1;
      goto LABEL_25;
    }
  }
  v17 = 0;
LABEL_25:
  if ( !v26 )
  {
    if ( !v17 )
      goto LABEL_33;
    v19 = z - vehicleState->origin.z;
    v18 = VehicleDef->vehHelicopterMaintainCeilingMinimum;
    goto LABEL_31;
  }
  v18 = vehicleState->origin.z;
  if ( v17 )
  {
    v19 = (float)((float)((float)(z + v5) + VehicleDef->vehHelicopterMaintainHeightMinimum)
                - VehicleDef->vehHelicopterMaintainCeilingMinimum)
        * 0.5;
LABEL_31:
    targetHeightDelta = v18 - v19;
    goto LABEL_32;
  }
  targetHeightDelta = (float)(v18 - v5) - VehicleDef->vehHelicopterMaintainHeightMinimum;
LABEL_32:
  v27 = targetHeightDelta;
LABEL_33:
  LODWORD(v20) = LODWORD(targetHeightDelta) & _mask__AbsFloat_;
  v21 = v15;
  if ( inputFallOffRange_1 > COERCE_FLOAT(LODWORD(targetHeightDelta) & _mask__AbsFloat_) )
  {
    if ( stopInputRange_0 <= v20 )
    {
      v22 = v20 / inputFallOffRange_1;
      v21 = v22;
      if ( v22 < 0.0 || v15 < v22 )
      {
        if ( !Assert_MyHandler(
                "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
                885,
                0,
                "(0.0f) <= (moveStrength) && (moveStrength) <= (1.0f)",
                "moveStrength not in [0.0f, 1.0f]\n\t%g not in [%g, %g]",
                v22,
                0.0,
                DOUBLE_1_0) )
          __debugbreak();
        v15 = *(float *)&FLOAT_1_0;
        targetHeightDelta = v27;
        v21 = v22;
        v5 = *(float *)&moveStrength[136];
      }
    }
    else
    {
      v21 = 0.0;
    }
  }
  if ( targetHeightDelta >= 0.0 )
  {
    if ( vehicleState->velocity.z > 4.0 )
      v21 = v15;
    LODWORD(v21) ^= _mask__NegFloat_;
  }
  else if ( vehicleState->velocity.z < -4.0 )
  {
    v21 = v15;
  }
  vehicleState->lastGroundHeight = v5;
  if ( (float)(v21 - v15) < 0.0 )
    v23 = v21;
  else
    v23 = v15;
  if ( (float)(-1.0 - v21) < 0.0 )
    return v23;
  else
    return FLOAT_N1_0;
}

#endif // __UNIMPLEMENTED__
