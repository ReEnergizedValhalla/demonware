// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdlobbyeventhandler.cpp:0x92D7F0
void __cdecl Demo_RecordProfileData(demoProfileData profileDataType, int size)
{
  s_demoProfile.memUsed[profileDataType] += size;
  ++s_demoProfile.count[profileDataType];
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyeventhandler.cpp:0x92D810
void __cdecl Demo_PrintProfileData()
{
  int i; // esi
  int v1; // eax

  Demo_Printf(2, "Total Demo Filesize: %d bytes\n", demo.totalSize);
  Demo_Printf(2, "--------------------Demo Profile--------------------\n");
  for ( i = 0; i < 8; ++i )
  {
    Demo_Printf(2, "%s : Count: %d Size: ", demo_profile_enum_string_6[i], s_demoProfile.count[i]);
    v1 = s_demoProfile.memUsed[i];
    if ( v1 < 1024 )
      Demo_Printf(2, "%d Bytes\n", s_demoProfile.memUsed[i]);
    else
      Demo_Printf(2, "%.2f KB\n", (float)((float)v1 * 0.0009765625));
  }
  Demo_Printf(2, "-----------------End of Demo Profile-----------------\n");
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyeventhandler.cpp:0x92D8C0
void __cdecl Demo_DrawDebugInformation(LocalClientNum_t localClientNum)
{
  int v1; // esi
  int Int; // edi
  cg_t *LocalClientGlobals; // ebx
  float z; // xmm0_4
  __int16 *p_scaleTime; // edi
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  int i; // esi
  const char *v10; // eax
  ScreenPlacement *View; // ebx
  demoPlayback *playback; // eax
  int v13; // edi
  int v14; // esi
  const char *v15; // eax
  int scale; // [esp+14h] [ebp-3Ch]
  int v17; // [esp+18h] [ebp-38h]
  int v18; // [esp+18h] [ebp-38h]
  Font_s *font; // [esp+2Ch] [ebp-24h]
  int y; // [esp+30h] [ebp-20h]
  float ya; // [esp+30h] [ebp-20h]
  __int64 cameraOrigin; // [esp+34h] [ebp-1Ch]
  vec3_t origin; // [esp+40h] [ebp-10h] BYREF

  y = 0;
  v1 = -1;
  if ( Demo_IsPlaying() )
  {
    if ( (localClientNum < LOCAL_CLIENT_FIRST || localClientNum >= LOCAL_CLIENT_COUNT)
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\client_mp\\../client/client.h",
            773,
            0,
            "((localClientNum >= 0 && localClientNum < 1))",
            "(localClientNum) = %i",
            localClientNum) )
    {
      __debugbreak();
    }
    if ( (clientUIActives[localClientNum].flags & 0x20) != 0 )
    {
      Int = Dvar_GetInt(demo_drawdebuginformation);
      LocalClientGlobals = CG_GetLocalClientGlobals(localClientNum);
      if ( Demo_IsAnyFreeMoveCamera() )
      {
        cameraOrigin = *(_QWORD *)&demo.playback->freeCameraOrigin.x;
        z = demo.playback->freeCameraOrigin.z;
      }
      else
      {
        cameraOrigin = *(_QWORD *)&LocalClientGlobals->refdef.vieworg.x;
        z = LocalClientGlobals->refdef.vieworg.z;
      }
      switch ( Int )
      {
        case 1:
          if ( demo.snapshot.prevNumEntities > 0 )
          {
            p_scaleTime = &demo.snapshot.ps[17].hud.archival[30].scaleTime;
            do
            {
              p_scaleTime += 124;
              ++v1;
              if ( *p_scaleTime >= 0 )
              {
                origin = CG_GetEntity(localClientNum, v1)->pose.origin;
                if ( fsqrt(
                       (float)((float)((float)(origin.y - *((float *)&cameraOrigin + 1))
                                     * (float)(origin.y - *((float *)&cameraOrigin + 1)))
                             + (float)((float)(origin.x - *(float *)&cameraOrigin)
                                     * (float)(origin.x - *(float *)&cameraOrigin)))
                     + (float)((float)(origin.z - z) * (float)(origin.z - z))) < 512.0 )
                {
                  CG_DebugStar(&origin, &colorBlue, 1);
                  v17 = demo.snapshot.entClientMask[v1][1];
                  scale = demo.snapshot.entClientMask[v1][0];
                  origin.z = origin.z + 10.0;
                  v6 = va("Ent Mask: %x %x", scale, v17);
                  CL_AddDebugString(&origin, &colorWhite, 0.69999999, v6, 1);
                  v18 = *p_scaleTime;
                  origin.z = origin.z + 10.0;
                  v7 = va("Ent Type: %d", v18);
                  CL_AddDebugString(&origin, &colorWhite, 0.69999999, v7, 1);
                  origin.z = origin.z + 10.0;
                  v8 = va("Ent Num: %d", v1);
                  CL_AddDebugString(&origin, &colorWhite, 0.69999999, v8, 1);
                }
                ++y;
              }
            }
            while ( y < demo.snapshot.prevNumEntities );
          }
          break;
        case 2:
          for ( i = 1024; i < 1792; ++i )
          {
            origin = CG_GetEntity(localClientNum, i)->pose.origin;
            if ( fsqrt(
                   (float)((float)((float)(origin.y - *((float *)&cameraOrigin + 1))
                                 * (float)(origin.y - *((float *)&cameraOrigin + 1)))
                         + (float)((float)(origin.x - *(float *)&cameraOrigin)
                                 * (float)(origin.x - *(float *)&cameraOrigin)))
                 + (float)((float)(origin.z - z) * (float)(origin.z - z))) < 512.0 )
            {
              CG_DebugStar(&origin, &colorBlue, 1);
              origin.z = origin.z + 10.0;
              v10 = va("Ent Num: %d", i);
              CL_AddDebugString(&origin, &colorWhite, 0.69999999, v10, 1);
            }
          }
          break;
        case 3:
          ya = FLOAT_65_0;
          View = ScrPlace_GetView(localClientNum);
          font = UI_GetFontHandle(View, 3, 0.33333334);
          CL_DrawText(
            View,
            "Timeline [idx]: Priority | Info Type | Start Time | End Time | Birth Time | Entity Num | Entity LookAt",
            0x7FFFFFFF,
            font,
            30.0,
            65.0,
            1,
            1,
            0.5,
            0.5,
            &colorWhite,
            0);
          playback = demo.playback;
          v13 = 0;
          if ( demo.playback->highlightReelTimelineInformationCount > 0 )
          {
            v14 = 0;
            do
            {
              ya = ya + 20.0;
              v15 = va(
                      "Timeline [%d]: %d | %d | %d | %d | %d | %d | %d",
                      v13,
                      playback->highlightReelTimeline[v14].priority,
                      playback->highlightReelTimeline[v14].infoType,
                      playback->highlightReelTimeline[v14].startTime,
                      playback->highlightReelTimeline[v14].endTime,
                      playback->highlightReelTimeline[v14].birthTime,
                      playback->highlightReelTimeline[v14].entityNumber,
                      playback->highlightReelTimeline[v14].entityLookAt);
              CL_DrawText(View, v15, 0x7FFFFFFF, font, 30.0, ya, 1, 1, 0.5, 0.5, &colorWhite, 0);
              playback = demo.playback;
              ++v13;
              ++v14;
            }
            while ( v13 < demo.playback->highlightReelTimelineInformationCount );
          }
          break;
      }
    }
  }
}

#endif // __UNIMPLEMENTED__
