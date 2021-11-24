// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdeventlog.cpp:0x92DDB0
void __cdecl Demo_DrawProfile()
{
  LocalClientNum_t Primary; // esi
  ScreenPlacement *View; // esi
  Font_s *FontHandle; // edi
  const char *String; // eax
  const char *v4; // ebx
  demoState DemoState; // eax
  __int32 v6; // eax
  const char *v7; // eax
  const vec4_t *v8; // ecx
  const char *v9; // eax
  const vec4_t *v10; // ecx
  int v11; // eax
  const char *v12; // ebx
  float v13; // xmm0_4
  vec4_t *p_varColor; // eax
  float v15; // xmm1_4
  const char *v16; // eax
  const vec4_t *v17; // ebx
  const char *v18; // eax
  int MaxBufferSize; // [esp+1Ch] [ebp-2Ch]
  float lerp; // [esp+2Ch] [ebp-1Ch]
  float y; // [esp+30h] [ebp-18h]
  float ya; // [esp+30h] [ebp-18h]
  float yb; // [esp+30h] [ebp-18h]
  float yc; // [esp+30h] [ebp-18h]
  float yd; // [esp+30h] [ebp-18h]
  vec4_t varColor; // [esp+34h] [ebp-14h] BYREF

  Primary = Com_LocalClients_GetPrimary();
  if ( Dvar_GetBool(demo_profiling) )
  {
    View = ScrPlace_GetView(Primary);
    FontHandle = UI_GetFontHandle(View, 3, 0.33333334);
    if ( FontHandle )
    {
      String = (const char *)Dvar_GetString(party_hostname);
      v4 = va("P-host : %s", String);
      CL_DrawText(View, v4, 0x7FFFFFFF, FontHandle, x, 65.0, 3, 1, xScale, yScale, &colorWhite, 0);
      DemoState = Demo_GetDemoState();
      if ( DemoState )
      {
        v6 = DemoState - 1;
        if ( v6 )
        {
          if ( v6 == 1 )
            v4 = "Demo State: Playing";
        }
        else
        {
          v4 = "Demo State: Recording";
        }
      }
      else
      {
        v4 = "Demo State: Idle";
      }
      y = ySpacing + 65.0;
      CL_DrawText(View, v4, 0x7FFFFFFF, FontHandle, x, ySpacing + 65.0, 3, 1, xScale, yScale, &colorWhite, 0);
      if ( Demo_IsStreamingActive() )
      {
        v7 = "Streaming: ACTIVE";
        v8 = &colorGreen;
      }
      else
      {
        v7 = "Streaming: NOT ACTIVE";
        v8 = &colorWhite;
      }
      ya = ySpacing + y;
      CL_DrawText(View, v7, 0x7FFFFFFF, FontHandle, x, ya, 3, 1, xScale, yScale, v8, 0);
      if ( Demo_IsStreamingOverflowed() )
      {
        v9 = "Streaming: OVERFLOWED";
        v10 = &colorRed;
      }
      else
      {
        v9 = "Streaming: NOT OVERFLOWED";
        v10 = &colorWhite;
      }
      yb = ySpacing + ya;
      CL_DrawText(View, v9, 0x7FFFFFFF, FontHandle, x, yb, 3, 1, xScale, yScale, v10, 0);
      if ( Demo_IsStreamingFinished() )
      {
        v12 = "Streaming: Finished";
        p_varColor = &colorWhite;
      }
      else
      {
        MaxBufferSize = Demo_GetMaxBufferSize();
        v11 = Demo_CurrAvailableBuffer();
        v12 = va("Streaming: %d / %d", v11, MaxBufferSize);
        lerp = (float)Demo_CurrAvailableBuffer();
        v13 = 1.0 - (float)(lerp / (float)Demo_GetMaxBufferSize());
        varColor.v[0] = (float)((float)(1.0 - 1.0) * v13) + 1.0;
        varColor.v[1] = (float)((float)(0.0 - 1.0) * v13) + 1.0;
        varColor.v[2] = varColor.v[1];
        varColor.v[3] = varColor.v[0];
        p_varColor = &varColor;
      }
      yc = ySpacing + yb;
      CL_DrawText(View, v12, 0x7FFFFFFF, FontHandle, x, yc, 3, 1, xScale, yScale, p_varColor, 0);
      if ( demo.svTotalBytesSent <= demo.svMaxBytesPerFrame )
        v15 = 1.0 - (float)((float)(demo.svMaxBytesPerFrame - demo.svTotalBytesSent) / (float)demo.svMaxBytesPerFrame);
      else
        v15 = *(float *)&FLOAT_1_0;
      v16 = va(
              "Avail. Bandwidth: %.2f (%d/%d)",
              (float)((float)(1.0 - v15) * 100.0),
              demo.svTotalBytesSent,
              demo.svMaxBytesPerFrame);
      varColor.v[0] = (float)((float)(1.0 - 1.0) * v15) + 1.0;
      varColor.v[1] = (float)((float)(0.0 - 1.0) * v15) + 1.0;
      varColor.v[2] = varColor.v[1];
      yd = ySpacing + yc;
      varColor.v[3] = varColor.v[0];
      CL_DrawText(View, v16, 0x7FFFFFFF, FontHandle, x, yd, 3, 1, xScale, yScale, &varColor, 0);
      if ( demo.streamingThrottleState == DEMO_STREAMING_THROTTLE_CLOSED_MIN_INTERVAL )
      {
        v17 = &colorRed;
        v18 = va("SV BW Throttle: MIN INTERVAL (%d ms)", demo.streamingThrottleTime);
      }
      else if ( demo.streamingThrottleState == DEMO_STREAMING_THROTTLE_CLOSED_BANDWIDTH_LIMIT )
      {
        v17 = &colorRed;
        v18 = va("SV BW Throttle: B/W LIMIT (%d ms)", demo.streamingThrottleTime);
      }
      else
      {
        v17 = &colorWhite;
        if ( Demo_IsStreamingFinished() )
          v18 = "SV BW Throttle: OPEN";
        else
          v18 = va("SV BW Throttle: OPEN (%d ms)", demo.streamingThrottleTime);
      }
      CL_DrawText(View, v18, 0x7FFFFFFF, FontHandle, x, ySpacing + yd, 3, 1, xScale, yScale, v17, 0);
    }
  }
}

#endif // __UNIMPLEMENTED__
