// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdnetstartparams.cpp:0x944750
int __cdecl BG_VehicleHeliLockHeight(VehicleState *vehicleState)
{
  float v1; // xmm2_4
  LocalClientNum_t v2; // xmm4_4
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float deltaHeight; // [esp+1Ch] [ebp-1Ch]
  float lockHeight; // [esp+24h] [ebp-14h] BYREF
  vec3_t testPoint; // [esp+28h] [ebp-10h] BYREF
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  lockHeight = 0.0;
  if ( !vehicleState
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          737,
          0,
          "(vehicleState)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  testPoint.x = (float)(vehicleState->velocity.x * lookAheadTime) + vehicleState->origin.x;
  testPoint.y = (float)(vehicleState->velocity.y * lookAheadTime) + vehicleState->origin.y;
  testPoint.z = vehicleState->mins.z
              + (float)((float)(vehicleState->velocity.z * lookAheadTime) + vehicleState->origin.z);
  if ( !CM_GetHeliHeight((unsigned int)&savedregs, &testPoint, 200.0, &lockHeight, 0) )
    CM_GetHeliHeight((unsigned int)&savedregs, &testPoint, 3000.0, &lockHeight, 0);
  v1 = testPoint.z - lockHeight;
  v2 = FLOAT_1_0;
  LODWORD(v3) = COERCE_UNSIGNED_INT(testPoint.z - lockHeight) & _mask__AbsFloat_;
  deltaHeight = testPoint.z - lockHeight;
  v4 = *(float *)&FLOAT_1_0;
  if ( inputFallOffRange_0 > v3 )
  {
    if ( stopInputRange <= v3 )
    {
      v5 = v3 / inputFallOffRange_0;
      v4 = v5;
      if ( v5 < 0.0 || v5 > 1.0 )
      {
        if ( !Assert_MyHandler(
                "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
                764,
                0,
                "(0.0f) <= (moveStrength) && (moveStrength) <= (1.0f)",
                "moveStrength not in [0.0f, 1.0f]\n\t%g not in [%g, %g]",
                v5,
                0.0,
                DOUBLE_1_0) )
          __debugbreak();
        v2 = FLOAT_1_0;
        v1 = deltaHeight;
        v4 = v5;
      }
    }
    else
    {
      v4 = 0.0;
    }
  }
  if ( v1 >= 0.0 )
  {
    if ( vehicleState->velocity.z > 4.0 )
      v4 = *(float *)&v2;
    return (int)(float)(v4 * -127.0);
  }
  else
  {
    if ( vehicleState->velocity.z < -4.0 )
      v4 = *(float *)&v2;
    return (int)(float)(v4 * 127.0);
  }
}

#endif // __UNIMPLEMENTED__
