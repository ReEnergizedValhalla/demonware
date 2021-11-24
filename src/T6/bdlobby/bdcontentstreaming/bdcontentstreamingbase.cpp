// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x931660
void __cdecl Demo_BuildDemoSnapshot()
{
  float totalSize; // [esp+0h] [ebp-4h]

  if ( Demo_IsEnabled() && demo.msg.cursize >= 5120 )
    Demo_StartSaveProcess(0);
  totalSize = (float)demo.totalSize;
  if ( totalSize < Dvar_GetFloat(demo_filesizeLimit) * 1024.0 * 1024.0 )
  {
    if ( demo.lastProcessedTime == -1 )
    {
      demo.footer.startTime = svs.time;
      demo.lastProcessedMsgNum = demo.gameStateMessageSequence + 1;
    }
    else
    {
      ++demo.lastProcessedMsgNum;
    }
    Demo_BuildDemoSnapshotInternal(&demo.msg, 0);
    demo.lastProcessedTime = svsHeader.time;
    Demo_SetUploadFileID();
  }
  else
  {
    Demo_End();
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x931710
const char *__cdecl Demo_GetKeyboardTitle()
{
  const char *result; // eax

  result = demo.keyboard.title;
  if ( !demo.keyboard.title )
    return (const char *)&pBlock;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x931720
const char *__cdecl Demo_GetKeyboardDefaultText()
{
  const char *result; // eax

  result = demo.keyboard.defaultText;
  if ( !demo.keyboard.defaultText )
    return (const char *)&pBlock;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x931730
int __cdecl Demo_GetKeyboardTextSize()
{
  return demo.keyboard.textSize <= 0 ? 0 : demo.keyboard.textSize;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x931740
void __cdecl Demo_GetStartAndEndTime(int *startTime, int *endTime)
{
  *startTime = demo.footer.startTime;
  *endTime = demo.footer.endTime;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x931760
void __cdecl Demo_GetDuration(char *outputText, int duration)
{
  sprintf(outputText, "%02i:%02i", duration / 60000, duration % 60000 / 1000);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x9317B0
char *__cdecl Demo_GetAuthor()
{
  return demo.footer.info.authorName;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x9317C0
char *__cdecl Demo_GetTitleName()
{
  return demo.footer.info.name;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x9317D0
char *__cdecl Demo_GetTitleDescription()
{
  return demo.footer.info.description;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x9317E0
char *__cdecl Demo_GetTimeInfo()
{
  const char *MonthAbbrev; // eax
  const char *v1; // eax
  qtime_s qtime; // [esp+0h] [ebp-28h] BYREF

  Com_GetQTime(demo.footer.info.createTime, &qtime, 1);
  MonthAbbrev = UI_GetMonthAbbrev(qtime.tm_mon);
  v1 = UI_SafeTranslateString(MonthAbbrev);
  return va("%s %d, %d  %02d:%02d", v1, qtime.tm_mday, qtime.tm_year + 1900, qtime.tm_hour, qtime.tm_min);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x931850
char *__cdecl Demo_GetDuration()
{
  return va(
           "%02i:%02i",
           (demo.footer.endTime - demo.footer.startTime) / 60000,
           (demo.footer.endTime - demo.footer.startTime) % 60000 / 1000);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x9318A0
char *__cdecl Demo_GetSaveScreenName(const char *type)
{
  if ( !Demo_IsPlaybackInited() )
    return (char *)&pBlock;
  if ( !I_stricmp(type, "clip") )
    return demo.playback->clipRecordInfo.name;
  if ( I_stricmp(type, "screenshot") )
    return (char *)&pBlock;
  return demo.playback->screenshotInfo.name;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x931900
char *__cdecl Demo_GetSaveScreenDescription(const char *type)
{
  if ( !Demo_IsPlaybackInited() )
    return (char *)&pBlock;
  if ( !I_stricmp(type, "clip") )
    return demo.playback->clipRecordInfo.description;
  if ( I_stricmp(type, "screenshot") )
    return (char *)&pBlock;
  return demo.playback->screenshotInfo.description;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x931960
void __cdecl Demo_GetConnectionTimeInfoForPlayer(
        LocalClientNum_t localClientNum,
        int *connectTime,
        int *disconnectTime)
{
  int Int; // edi
  int serverTime; // esi
  int v5; // eax
  int *i; // ecx
  int v7; // eax

  Int = Dvar_GetInt(demo_client);
  serverTime = CL_GetLocalClientGlobals(localClientNum)->snap.serverTime;
  v5 = 0;
  if ( demo.footer.numConnectedPlayers > 0 )
  {
    for ( i = &demo.footer.connectedPlayers[0].connectTime; *(i - 3) != Int || *i > serverTime || i[1] < serverTime; i += 12 )
    {
      if ( ++v5 >= demo.footer.numConnectedPlayers )
        return;
    }
    v7 = v5;
    *connectTime = demo.footer.connectedPlayers[v7].connectTime;
    *disconnectTime = demo.footer.connectedPlayers[v7].disconnectTime;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x9319D0
int __cdecl Demo_GetPlayerIndexForClientNum(ClientNum_t clientNum, int serverTime)
{
  int result; // eax
  int *i; // ecx

  result = 0;
  if ( demo.footer.numConnectedPlayers <= 0 )
    return -1;
  for ( i = &demo.footer.connectedPlayers[0].connectTime;
        *(i - 3) != clientNum || (*i > serverTime || i[1] < serverTime) && serverTime >= 0;
        i += 12 )
  {
    if ( ++result >= demo.footer.numConnectedPlayers )
      return -1;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x931A20
int __cdecl Demo_GetNextDefaultBookmarkForPlayer(int playerIndex, ClientNum_t clientNum, int index)
{
  int result; // eax
  demoDefaultBookmark *i; // edi
  unsigned int v5; // ecx
  int v6; // edx
  int time; // esi

  result = index + 1;
  if ( index + 1 >= demo.footer.numDefaultBookmarks )
    return -1;
  for ( i = &demo.footer.defaultBookmarks[result]; ; ++i )
  {
    v5 = *(_DWORD *)i;
    v6 = *(_DWORD *)i & 0x7F;
    if ( v6 == 9 )
      break;
    if ( v6 == 10 )
      break;
    if ( playerIndex >= 0 )
    {
      time = i->time;
      if ( demo.footer.connectedPlayers[playerIndex].connectTime <= time
        && demo.footer.connectedPlayers[playerIndex].disconnectTime >= time
        && (((v5 >> 17) & 0x1F) == clientNum || ((v5 >> 22) & 0x1F) == clientNum) )
      {
        break;
      }
    }
    if ( ++result >= demo.footer.numDefaultBookmarks )
      return -1;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x931AA0
int __cdecl Demo_GetNextDefaultBookmarkForPlayer(
        LocalClientNum_t localClientNum,
        int index,
        int *type,
        int *time,
        vec4_t *color,
        bool *useBottomHalfColor,
        vec4_t *bottomHalfColor)
{
  clientActive_t *LocalClientGlobals; // eax
  int PlayerIndexForClientNum; // ecx
  demoDefaultBookmark *v9; // edx
  int v10; // eax
  int v11; // ebx
  int v12; // edx
  int v13; // ecx
  float v14; // xmm0_4
  const char *v16; // eax
  int playerIndex; // [esp+10h] [ebp-20h]
  ClientNum_t bookmarkClient2; // [esp+18h] [ebp-18h]
  demoDefaultBookmark *v19; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  ClientNum_t clientNum; // [esp+28h] [ebp-8h]

  *useBottomHalfColor = 0;
  clientNum = Dvar_GetInt(demo_client);
  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
  PlayerIndexForClientNum = Demo_GetPlayerIndexForClientNum(clientNum, LocalClientGlobals->snap.serverTime);
  playerIndex = PlayerIndexForClientNum;
  i = index + 1;
  if ( index + 1 >= demo.footer.numDefaultBookmarks )
    return -1;
  v9 = &demo.footer.defaultBookmarks[index + 1];
  v19 = v9;
  while ( 2 )
  {
    v10 = (*(_DWORD *)v9 >> 22) & 0x1F;
    v11 = (*(_DWORD *)v9 >> 17) & 0x1F;
    bookmarkClient2 = v10;
    if ( PlayerIndexForClientNum < 0 )
      goto $LN60_5;
    v12 = v9->time;
    v13 = PlayerIndexForClientNum;
    if ( demo.footer.connectedPlayers[v13].connectTime > v12 || demo.footer.connectedPlayers[v13].disconnectTime < v12 )
      goto $LN60_5;
    switch ( *(_DWORD *)v19 & 0x7F )
    {
      case 0:
        if ( Dvar_GetBool(spawnsystem_debug) )
          goto LABEL_54;
        if ( bookmarkClient2 == clientNum && bookmarkClient2 != v11 )
        {
          *color = colorGreen;
          goto LABEL_54;
        }
        if ( v11 == clientNum )
        {
$LN661:
          *color = colorRed;
          goto LABEL_54;
        }
        goto $LN60_5;
      case 1:
        if ( v11 != clientNum )
          goto $LN60_5;
        *color = colorBlue;
        goto LABEL_54;
      case 2:
        goto $LN661;
      case 3:
        if ( v11 != clientNum )
          goto $LN60_5;
        LODWORD(color->v[0]) = FLOAT_1_0;
        LODWORD(color->v[1]) = FLOAT_1_0;
        *(_QWORD *)&color->b = (unsigned int)FLOAT_1_0;
        *useBottomHalfColor = 1;
        *bottomHalfColor = colorLtRed;
        goto LABEL_54;
      case 4:
        if ( v11 != clientNum && v10 != clientNum )
          goto $LN60_5;
        *(_QWORD *)color->v = *(_QWORD *)colorMdCyan.v;
        color->v[2] = colorMdCyan.v[2];
        v14 = colorMdCyan.v[3];
        goto LABEL_27;
      case 5:
        if ( v11 != clientNum )
          goto $LN60_5;
        LODWORD(color->v[0]) = FLOAT_1_0;
        LODWORD(color->v[1]) = FLOAT_1_0;
        *(_QWORD *)&color->b = (unsigned int)FLOAT_1_0;
        *useBottomHalfColor = 1;
        *bottomHalfColor = colorMdRed;
        goto LABEL_54;
      case 6:
      case 9:
      case 0xA:
      case 0xB:
      case 0x11:
      case 0x12:
      case 0x14:
        goto $LN663;
      case 7:
      case 8:
        if ( v11 != clientNum )
          goto $LN60_5;
$LN663:
        LODWORD(color->v[0]) = FLOAT_1_0;
        LODWORD(color->v[1]) = FLOAT_1_0;
        *(_QWORD *)&color->b = (unsigned int)FLOAT_1_0;
        goto LABEL_54;
      case 0xC:
        if ( v11 != clientNum )
          goto $LN60_5;
        *(_QWORD *)color->v = *(_QWORD *)colorYellow.v;
        color->v[2] = colorYellow.v[2];
        v14 = colorYellow.v[3];
        goto LABEL_27;
      case 0xD:
        if ( v11 != clientNum )
          goto $LN60_5;
        *color = colorMdOrange;
        *useBottomHalfColor = 1;
        goto LABEL_28;
      case 0xE:
        *(_QWORD *)color->v = *(_QWORD *)colorBlue.v;
        color->v[2] = colorBlue.v[2];
        v14 = colorBlue.v[3];
        goto LABEL_27;
      case 0xF:
      case 0x10:
        if ( v11 != clientNum )
          goto $LN60_5;
        *color = colorBlue;
        *useBottomHalfColor = 1;
        goto LABEL_28;
      case 0x13:
      case 0x18:
        if ( v11 != clientNum )
          goto $LN60_5;
        *color = colorMdGrey;
        *useBottomHalfColor = 1;
        goto LABEL_28;
      case 0x15:
        if ( v10 != clientNum || v10 == v11 )
        {
          if ( v11 == clientNum )
          {
            LODWORD(color->v[0]) = FLOAT_1_0;
            LODWORD(color->v[1]) = FLOAT_1_0;
            *(_QWORD *)&color->b = (unsigned int)FLOAT_1_0;
            *useBottomHalfColor = 1;
            *bottomHalfColor = colorMdYellow;
            goto LABEL_54;
          }
$LN60_5:
          v9 = v19 + 1;
          ++i;
          ++v19;
          if ( i >= demo.footer.numDefaultBookmarks )
            return -1;
          PlayerIndexForClientNum = playerIndex;
          continue;
        }
        *(_QWORD *)color->v = *(_QWORD *)colorMdYellow.v;
        color->v[2] = colorMdYellow.v[2];
        v14 = colorMdYellow.v[3];
LABEL_27:
        color->v[3] = v14;
        *useBottomHalfColor = 1;
LABEL_28:
        LODWORD(bottomHalfColor->v[0]) = FLOAT_1_0;
        LODWORD(bottomHalfColor->v[1]) = FLOAT_1_0;
        *(_QWORD *)&bottomHalfColor->b = (unsigned int)FLOAT_1_0;
LABEL_54:
        *type = *(_DWORD *)&demo.footer.defaultBookmarks[i] & 0x7F;
        *time = demo.footer.defaultBookmarks[i].time;
        return i;
      case 0x16:
        if ( v11 != clientNum )
          goto $LN60_5;
        *color = colorMdPurple;
        *useBottomHalfColor = 1;
        goto LABEL_28;
      case 0x17:
        if ( v11 != clientNum )
          goto $LN60_5;
        *color = colorMagenta;
        *useBottomHalfColor = 1;
        goto LABEL_28;
      case 0x19:
        goto $LN60_5;
      case 0x1A:
        if ( !Dvar_GetInt(com_developer) )
          goto $LN60_5;
        *color = colorMagenta;
        goto LABEL_54;
      case 0x1B:
        if ( !Dvar_GetInt(com_developer) || Dvar_GetBool(spawnsystem_debug) )
          goto $LN60_5;
        *color = colorOrange;
        goto LABEL_54;
      default:
        v16 = va("Unknown bookmark type %d\n", *(_DWORD *)&demo.footer.defaultBookmarks[i] & 0x7F);
        if ( !Assert_MyHandler("c:\\t6\\code\\src_noserver\\demo\\demo_ui.cpp", 835, 0, (const char *)&pBlock, v16) )
          __debugbreak();
        goto LABEL_54;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x9321F0
const char *__cdecl Demo_GetDebugNameForBookmarkType(demoBookmarkType type)
{
  return s_demoBookmarkTypeDebugNames[type];
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x932200
const char *__cdecl Demo_GetFreeCamModeName()
{
  demoFreeCameraMode CurrentFreeCameraMode; // eax
  __int32 v1; // eax

  CurrentFreeCameraMode = Demo_GetCurrentFreeCameraMode();
  if ( CurrentFreeCameraMode == DEMO_FREECAM_MODE_FIRST )
    return UI_SafeTranslateString("MENU_DEMO_FREE_ROAM_MODE");
  v1 = CurrentFreeCameraMode - 1;
  if ( !v1 )
    return UI_SafeTranslateString("MENU_DEMO_EDIT_CAMERA_MODE");
  if ( v1 == 1 )
    return UI_SafeTranslateString("MENU_DEMO_DOLLY_CAMERA_MODE");
  if ( !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_ui.cpp",
          917,
          0,
          (const char *)&pBlock,
          "Unknown free cam mode type.") )
    __debugbreak();
  return (const char *)&pBlock;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x932270
int __cdecl Demo_GetNextDollyCamMarker(LocalClientNum_t localClientNum, int index, int *time, vec4_t *color)
{
  int v4; // esi

  v4 = index + 1;
  if ( index + 1 >= demo.playback->dollyCamMarkerCount )
    return -1;
  if ( v4 < 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_ui.cpp",
          937,
          0,
          "(0) <= (newIndex) && (newIndex) <= (demo.playback->dollyCamMarkerCount)",
          "newIndex not in [0, demo.playback->dollyCamMarkerCount]\n\t%i not in [%i, %i]",
          index + 1,
          0,
          demo.playback->dollyCamMarkerCount) )
  {
    __debugbreak();
  }
  *time = demo.playback->dollyCamMarkers[v4].time;
  *color = colorYellow;
  return index + 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x932310
const char *__cdecl Demo_GetTimeScaleModeNameForDollyCamMarker(int marker)
{
  demoDollyCameraTimeScaleMode TimeScaleModeForDollyCamMarker; // eax
  __int32 v2; // eax

  if ( !Demo_IsPlaybackInited() )
    return (const char *)&pBlock;
  TimeScaleModeForDollyCamMarker = Demo_GetTimeScaleModeForDollyCamMarker(marker);
  if ( TimeScaleModeForDollyCamMarker == DEMO_DOLLYCAM_TIMESCALE_MODE_MANUAL )
    return UI_SafeTranslateString("MENU_DEMO_DOLLYCAM_SPEED_SETTING_MANUAL");
  v2 = TimeScaleModeForDollyCamMarker - 1;
  if ( !v2 )
    return UI_SafeTranslateString("MENU_DEMO_DOLLYCAM_SPEED_SETTING_LINEAR");
  if ( v2 != 1 )
  {
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\demo\\demo_ui.cpp",
            969,
            0,
            (const char *)&pBlock,
            "Unknown timescale mode type.") )
      __debugbreak();
    return (const char *)&pBlock;
  }
  return UI_SafeTranslateString("MENU_DEMO_DOLLYCAM_SPEED_SETTING_FIXED");
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x932390
void __cdecl Demo_OpenDollyCamMarkerPopUp(LocalClientNum_t localClientNum)
{
  UiContext *Info; // edi

  Info = UI_GetInfo(localClientNum);
  Key_SetCatcher(localClientNum, 8);
  Menus_OpenByName(localClientNum, Info, "demo_dollycam_marker_options");
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x9323C0
bool __cdecl Demo_IsDollyCamMarkerDialogOpen(LocalClientNum_t localClientNum)
{
  return Menu_IsMenuOpenAndVisible(localClientNum, "demo_dollycam_marker_options")
      || Menu_IsMenuOpenAndVisible(localClientNum, "remove_all_markers_confirmation");
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x932400
void __cdecl Demo_GetActivatedColorForButton(demoControlsButton demoControlButtonType, vec4_t *color)
{
  *color = colorWhite;
  if ( Demo_IsPlaybackInited()
    && demo.playback->buttonPressTime[demoControlButtonType]
    && (int)(Sys_Milliseconds() - demo.playback->buttonPressTime[demoControlButtonType]) <= 100 )
  {
    *color = colorYellow;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x9324A0
void __cdecl Demo_DrawVerticalLine(
        const ScreenPlacement *scrPlace,
        float x,
        float y,
        float w,
        float h,
        int horzAlign,
        int vertAlign,
        float s1,
        float t1,
        float s2,
        float t2,
        const vec4_t *color,
        Material *material)
{
  float originalWidth; // [esp+30h] [ebp-8h]

  originalWidth = w;
  ScrPlace_ApplyRect(scrPlace, &x, &y, &w, &h, horzAlign, vertAlign);
  w = originalWidth;
  x = (float)(int)(x + 9.313225746154785e-10);
  CL_DrawStretchPicPhysicalInternal(x, y, originalWidth, h, s1, t1, s2, t2, color, material);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x932570
const GfxViewParms *__usercall Demo_GetSegmentTransition@<eax>(int index@<eax>)
{
  const char *v3; // eax

  if ( !Demo_IsPlaybackInited() )
    return &pBlock;
  if ( index == demo.playback->segmentCount - 1 )
    v3 = UI_SafeTranslateString("MENU_NONE");
  else
    v3 = UI_SafeTranslateString(demo_transition_enum_string_8[demo.playback->segments[index].transition]);
  return (const GfxViewParms *)va("%s", v3);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x9325D0
clipSegment *__cdecl Demo_GetSegmentInformation(int index, const char *s)
{
  demoPlayback *v3; // eax
  int v4; // ebx
  int v5; // edx
  int v6; // esi
  int v7; // edi
  int *v8; // eax
  unsigned int v9; // ecx
  demoPlayback *playback; // eax
  int segmentCount; // ebx
  int v12; // edx
  int v13; // esi
  int v14; // edi
  int *p_duration; // eax
  unsigned int v16; // ecx
  int duration; // eax
  const cpose_t *v18; // eax
  double HighlightReelStarsForPriority; // st7
  int total; // [esp+14h] [ebp-48h]
  char output[64]; // [esp+18h] [ebp-44h] BYREF

  memset(output, 0, sizeof(output));
  total = 0;
  if ( !Demo_IsPlaybackInited() )
    return (clipSegment *)&pBlock;
  if ( !I_stricmp(s, "name") )
  {
    if ( Demo_IsPlaybackInited() )
      return &demo.playback->segments[index];
    return (clipSegment *)&pBlock;
  }
  if ( !I_stricmp(s, "duration") )
    return (clipSegment *)va("%d", demo.playback->segments[index].duration);
  if ( !I_stricmp(s, "durationTimeDisplay") )
  {
    Demo_GetDuration(output, demo.playback->segments[index].duration);
    return (clipSegment *)va("%s", output);
  }
  if ( !I_stricmp(s, "durationLocString") )
  {
    UI_SecondsAsTimeDisplay(demo.playback->segments[index].duration / 1000, output, 64);
    return (clipSegment *)va("%s", output);
  }
  if ( !I_stricmp(s, "transition") )
    return (clipSegment *)Demo_GetSegmentTransition(index);
  if ( !I_stricmp(s, "transitionValue") )
    return (clipSegment *)va("%d", demo.playback->segments[index].transition);
  if ( I_stricmp(s, "totalClipDurationTimeDisplay") )
  {
    if ( I_stricmp(s, "totalClipDuration") )
    {
      if ( !I_stricmp(s, "score") )
      {
        v18 = Ragdoll_HandleBody((const cpose_t *)demo.playback->segments[index].highlightReelPriority);
        return (clipSegment *)va("%d", v18);
      }
      if ( !I_stricmp(s, "stars") )
      {
        HighlightReelStarsForPriority = Demo_GetHighlightReelStarsForPriority(demo.playback->segments[index].highlightReelPriority);
        return (clipSegment *)va("%0.1f", HighlightReelStarsForPriority);
      }
      return (clipSegment *)&pBlock;
    }
    playback = demo.playback;
    segmentCount = demo.playback->segmentCount;
    v12 = 0;
    v13 = 0;
    v14 = 0;
    if ( segmentCount >= 2 )
    {
      p_duration = &demo.playback->segments[1].duration;
      v16 = ((unsigned int)(segmentCount - 2) >> 1) + 1;
      v14 = 2 * v16;
      do
      {
        v12 += *(p_duration - 16512);
        v13 += *p_duration;
        p_duration += 33024;
        --v16;
      }
      while ( v16 );
      playback = demo.playback;
    }
    if ( v14 >= segmentCount )
      duration = 0;
    else
      duration = playback->segments[v14].duration;
    return (clipSegment *)va("%d", duration + v12 + v13);
  }
  else
  {
    v3 = demo.playback;
    v4 = demo.playback->segmentCount;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    if ( v4 >= 2 )
    {
      v8 = &demo.playback->segments[1].duration;
      v9 = ((unsigned int)(v4 - 2) >> 1) + 1;
      v7 = 2 * v9;
      do
      {
        v5 += *(v8 - 16512);
        v6 += *v8;
        v8 += 33024;
        --v9;
      }
      while ( v9 );
      v3 = demo.playback;
    }
    if ( v7 < v4 )
      total = v3->segments[v7].duration;
    Demo_GetDuration(output, total + v5 + v6);
    return (clipSegment *)va("%s", output);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x932980
char __cdecl Demo_IsPauseMenuOpen(LocalClientNum_t localClientNum)
{
  int v1; // esi
  const char *v2; // eax
  char *ingameMenuNames[11]; // [esp+8h] [ebp-2Ch]

  ingameMenuNames[1] = "demo_manage_segments";
  ingameMenuNames[2] = "demo_button_layout";
  ingameMenuNames[3] = "ingameoptions";
  ingameMenuNames[4] = "ingameoptions_sensitivity";
  ingameMenuNames[5] = "ingameoptions_team_indicator";
  ingameMenuNames[6] = "ingameoptions_volume";
  ingameMenuNames[7] = "ingameoptions_brightness";
  ingameMenuNames[8] = "options_new_pc";
  ingameMenuNames[9] = "options_controls_new_pc";
  ingameMenuNames[10] = 0;
  if ( !Key_IsCatcherActive(localClientNum, 8) )
    return 0;
  v1 = 0;
  v2 = "demo_ingame";
  while ( !Menu_IsMenuOpenAndVisible(localClientNum, v2) )
  {
    v2 = ingameMenuNames[++v1];
    if ( !v2 )
      return 0;
  }
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x932A20
void __cdecl Demo_OpenSavePopUp(LocalClientNum_t localClientNum, demoSavePopup type)
{
  UiContext *Info; // edi

  Info = UI_GetInfo(localClientNum);
  Key_SetCatcher(localClientNum, 8);
  if ( type )
  {
    if ( type == DEMO_SAVE_POPUP_SCREENSHOT )
      Menus_OpenByName(localClientNum, Info, "demo_save_screenshot");
  }
  else
  {
    Menus_OpenByName(localClientNum, Info, "demo_save_clip");
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x932A70
bool __cdecl Demo_IsSaveDialogOpen(LocalClientNum_t localClientNum)
{
  return Menu_IsMenuOpenAndVisible(localClientNum, "demo_save_clip")
      || Menu_IsMenuOpenAndVisible(localClientNum, "demo_save_screenshot")
      || Menu_IsMenuOpenAndVisible(localClientNum, "screenshot_save_screen")
      || Menu_IsMenuOpenAndVisible(localClientNum, "fileshare_slotselection_scr");
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x932AD0
void __cdecl Demo_Error(LocalClientNum_t localClientNum, const char *errorTitle, const char *errorMessage)
{
  const char *v3; // eax
  const char *v4; // eax
  UiContext *Info; // edi

  v3 = UI_SafeTranslateString(errorTitle);
  Dvar_SetString(demo_errortitle, v3);
  v4 = UI_SafeTranslateString(errorMessage);
  Dvar_SetString(demo_errormessage, v4);
  if ( !Demo_IsPaused() )
    Dvar_SetBool(demo_pause, 1);
  Info = UI_GetInfo(localClientNum);
  Key_SetCatcher(localClientNum, 8);
  Menus_OpenByName(localClientNum, Info, "demo_error");
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x932B50
bool __cdecl Demo_IsErrorDialogOpen(LocalClientNum_t localClientNum)
{
  return Menu_IsMenuOpenAndVisible(localClientNum, "demo_error");
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x932B70
bool __cdecl Demo_ShouldDrawDemoControlsHUD(LocalClientNum_t localClientNum)
{
  return !Menu_IsMenuOpenAndVisible(localClientNum, "demo_save_clip")
      && !Menu_IsMenuOpenAndVisible(localClientNum, "demo_save_screenshot")
      && !Menu_IsMenuOpenAndVisible(localClientNum, "screenshot_save_screen")
      && !Menu_IsMenuOpenAndVisible(localClientNum, "fileshare_slotselection_scr")
      && !Menu_IsMenuOpenAndVisible(localClientNum, "demo_dollycam_marker_options")
      && !Menu_IsMenuOpenAndVisible(localClientNum, "remove_all_markers_confirmation")
      && !Menu_IsMenuOpenAndVisible(localClientNum, "demo_error")
      && !Demo_IsPauseMenuOpen(localClientNum)
      && !CG_IsScoreboardDisplayed(localClientNum)
      && !UI_CheckUIVisibilityBit(localClientNum, 22)
      && !UI_CheckUIVisibilityBit(localClientNum, 34)
      && !UI_CheckUIVisibilityBit(localClientNum, 26);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreamingbase.cpp:0x932C50
void __cdecl Demo_KeyboardComplete(
        LocalClientNum_t localClientNum,
        char *string,
        bool errorReported,
        const char *errorString)
{
  int ControllerIndex; // eax

  if ( errorReported )
  {
    if ( (unsigned int)(demo.keyboard.mode - 1) > 4 )
    {
      Com_SetErrorMessage(errorString);
      UI_OpenErrorPopup();
    }
    else
    {
      Demo_Error(localClientNum, "MENU_ERROR", errorString);
    }
  }
  else
  {
    switch ( demo.keyboard.mode )
    {
      case 1:
        I_strncpyz(
          demo.playback->segments[demo.keyboard.currentProcessingSegmentIndex].name,
          string,
          demo.keyboard.textSize);
        if ( Menu_IsMenuOpenAndVisible(localClientNum, "demo_save_clip") )
        {
          ControllerIndex = Com_LocalClient_GetControllerIndex(localClientNum);
          Cmd_ExecuteSingleCommand(localClientNum, (ControllerIndex_t)ControllerIndex, "demo_savesegment 0", 0);
          Key_RemoveCatcher(localClientNum, -9);
          UI_CloseMenu(localClientNum, "demo_save_clip");
        }
        break;
      case 2:
        I_strncpyz(demo.playback->clipRecordInfo.name, string, 22);
        demo.playback->clipRecordInfo.isModifiedName = 1;
        break;
      case 3:
        I_strncpyz(demo.playback->clipRecordInfo.description, string, 64);
        demo.playback->clipRecordInfo.isModifiedDescription = 1;
        break;
      case 4:
        I_strncpyz(demo.playback->screenshotInfo.name, string, 22);
        demo.playback->screenshotInfo.isModifiedName = 1;
        break;
      case 5:
        I_strncpyz(demo.playback->screenshotInfo.description, string, 64);
        demo.playback->screenshotInfo.isModifiedDescription = 1;
        break;
      case 6:
        LiveFileshare_SetCopyFileName(string);
        break;
      case 7:
        LiveFileshare_SetCopyFileDescription(string);
        break;
      case 8:
        Com_GametypeSettings_SetName(string);
        break;
      case 9:
        Com_GametypeSettings_SetDescription(string);
        break;
      case 0xA:
        UI_EmblemSetName(string);
        break;
      case 0xB:
        UI_EmblemSetDescription(string);
        break;
      default:
        break;
    }
  }
  demo.keyboard.mode = 0;
  demo.keyboard.title = (const char *)&pBlock;
  demo.keyboard.defaultText = (const char *)&pBlock;
  demo.keyboard.textSize = 0;
  demo.keyboard.ignoreProfanityCheck = 0;
}

#endif // __UNIMPLEMENTED__
