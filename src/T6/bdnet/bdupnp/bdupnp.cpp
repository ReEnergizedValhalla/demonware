// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdupnp.cpp:0x945B80
void __cdecl BG_HeliMaintainHeight_UpdateHeight(pmove_t *pm, const pml_t *pml, VehicleState *vehicleState)
{
  float targetHeightDelta; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm2_4

  if ( (pm->cmd.button_bits.array[1] & 0x8000000) == 0 && (pm->cmd.button_bits.array[1] & 0x4000000) == 0 )
  {
    targetHeightDelta = vehicleState->targetHeightDelta;
    if ( targetHeightDelta > 1.0 || targetHeightDelta < -1.0 )
    {
      v4 = 0.0;
      v5 = (float)(vehicleState->origin.z - vehicleState->previousOrigin.z) + targetHeightDelta;
      if ( targetHeightDelta >= 0.0 )
      {
        v7 = FLOAT_3_4028235e38;
        if ( (float)(v5 - 3.4028235e38) < 0.0 )
          v7 = v5;
        if ( COERCE_FLOAT(LODWORD(v5) ^ _mask__NegFloat_) < 0.0 )
          v4 = v7;
        vehicleState->targetHeightDelta = v4;
      }
      else
      {
        if ( v5 < 0.0 )
          v6 = (float)(vehicleState->origin.z - vehicleState->previousOrigin.z) + targetHeightDelta;
        else
          v6 = 0.0;
        if ( (float)(-3.4028235e38 - v5) < 0.0 )
          vehicleState->targetHeightDelta = v6;
        else
          vehicleState->targetHeightDelta = FLOAT_N3_4028235e38;
      }
    }
  }
}

#endif // __UNIMPLEMENTED__
