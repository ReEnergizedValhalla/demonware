// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdcommonaddr.cpp:0x9250D0
char __cdecl Demo_CaptureThumbnailForSegment()
{
  char v0; // bl
  bool Bool; // al
  bool v2; // al
  char v3; // al
  bool v5; // al

  if ( Demo_IsPlaying() )
  {
    if ( demo.playback )
      Bool = Dvar_GetBool(demo_pause) && !demo.playback->overridePause;
    else
      Bool = Dvar_GetBool(demo_pause);
    v0 = Bool;
  }
  else
  {
    v0 = 0;
  }
  if ( !Demo_IsPlaying() )
    goto LABEL_16;
  if ( !demo.playback )
  {
    if ( Dvar_GetBool(demo_pause) )
      goto LABEL_19;
    goto LABEL_16;
  }
  if ( !Dvar_GetBool(demo_pause) || demo.playback->overridePause )
  {
LABEL_16:
    if ( Demo_IsHostControlsEnabled() )
    {
      v2 = Dvar_GetBool(demo_pause);
      Dvar_SetBool(demo_pause, !v2);
    }
    else
    {
      Com_PrintError(25, "Host controls are not enabled. So, cant execute pause.\n");
    }
  }
LABEL_19:
  if ( !Demo_IsPlaying() )
  {
LABEL_20:
    v3 = 0;
    goto LABEL_26;
  }
  if ( demo.playback )
  {
    if ( !Dvar_GetBool(demo_pause) || demo.playback->overridePause )
      goto LABEL_20;
    v3 = 1;
  }
  else
  {
    v3 = Dvar_GetBool(demo_pause);
  }
LABEL_26:
  if ( v0 != v3 )
  {
    if ( !Demo_IsHostControlsEnabled() )
    {
      Com_PrintError(25, "Host controls are not enabled. So, cant execute pause.\n");
      return 1;
    }
    v5 = Dvar_GetBool(demo_pause);
    Dvar_SetBool(demo_pause, !v5);
  }
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcommonaddr.cpp:0x925230
unsigned int __cdecl Demo_WriteTransitionClipCommandBlockToBuffer(
        int transition,
        unsigned __int8 *buffer,
        int maxBufferSize)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  int cursize; // edx
  msg_t msg; // [esp+8h] [ebp-234h] BYREF
  unsigned __int8 msgBuf[256]; // [esp+38h] [ebp-204h] BYREF
  unsigned __int8 tempMsgBuf[256]; // [esp+138h] [ebp-104h] BYREF

  memset(msgBuf, 0, sizeof(msgBuf));
  memset(tempMsgBuf, 0, sizeof(tempMsgBuf));
  MSG_Init(&msg, msgBuf, 256);
  MSG_WriteBits(&msg, 2, 2);
  MSG_WriteByte(&msg, 11);
  MSG_WriteByte(&msg, transition);
  MSG_WriteBits(&msg, 2, 2);
  MSG_WriteByte(&msg, 12);
  MSG_WriteBits(&msg, 0, 2);
  v3 = Com_CompressWithZLib(msg.data, msg.cursize, tempMsgBuf, 256);
  v4 = v3 + 8;
  if ( (int)(v3 + 8) >= maxBufferSize )
    return 0;
  cursize = msg.cursize;
  *(_DWORD *)buffer = v3;
  *((_DWORD *)buffer + 1) = cursize;
  memcpy(buffer + 8, tempMsgBuf, v3);
  return v4;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcommonaddr.cpp:0x925360
void __cdecl Demo_SaveClipRecordMessageToMainMemory(
        LocalClientNum_t localClientNum,
        unsigned __int8 *data,
        int size,
        bool forceWrite)
{
  unsigned int v4; // esi
  msg_t compressedMsg; // [esp+8h] [ebp-30h] BYREF

  memset(demo.msgBuf1, 0, sizeof(demo.msgBuf1));
  MSG_Init(&compressedMsg, demo.msgBuf1, 0x10000);
  v4 = Com_CompressWithZLib(data, size, demo.msgBuf1, 0x10000);
  if ( (!v4 || !size)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
          5731,
          0,
          "(compressedSize != 0 && size != 0)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  *(_DWORD *)&demo.playback->mainClipRecordingBuf[demo.playback->clipRecordBufIndex] = v4;
  demo.playback->clipRecordBufIndex += 4;
  *(_DWORD *)&demo.playback->mainClipRecordingBuf[demo.playback->clipRecordBufIndex] = size;
  demo.playback->clipRecordBufIndex += 4;
  memcpy(&demo.playback->mainClipRecordingBuf[demo.playback->clipRecordBufIndex], demo.msgBuf1, v4);
  demo.playback->clipRecordBufIndex += v4;
  if ( forceWrite )
    Demo_WriteRecordedClipToContentServer(localClientNum, 1);
  MSG_Init(&demo.playback->clipRecordingMsg, demo.playback->subClipRecordingBuf, 0x10000);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcommonaddr.cpp:0x925610
void __usercall Demo_SetDefaultVisionSet(LocalClientNum_t localClientNum@<eax>)
{
  clientConnection_t *LocalClientConnection; // esi
  int v2; // edi
  const char *String; // eax

  LocalClientConnection = CL_GetLocalClientConnection(localClientNum);
  v2 = ++LocalClientConnection->serverCommandSequence & 0x7F;
  String = (const char *)Dvar_GetString(sv_mapname);
  Com_sprintf(LocalClientConnection->serverCommands[v2], 1024, "%c %i \"%s\" 0", 50, 1060, String);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcommonaddr.cpp:0x925660
void __cdecl Demo_InitPlaybackData(LocalClientNum_t localClientNum)
{
  demoPlayback *playback; // ecx
  int i; // eax

  demo.playback->keyframeBuf = s_keyframeBuf;
  demo.playback->screenshotBuf = s_screenshotBuf;
  demo.playback->mainClipRecordingBuf = s_mainClipRecordingBuf;
  demo.playback->clipMergeBuf = s_clipMergeBuf;
  demo.playback->dollyCamKeyframeBuf = s_dollyCamKeyframeBuf;
  demo.playback->keyframeIndex = -1;
  demo.playback->lastJumpedKeyframe = -1;
  demo.playback->informationScreenType = DEMO_INFORMATION_SCREEN_NONE;
  demo.playback->informationScreenActivateTime = -1;
  demo.playback->highlightedDollyCamMarker = -1;
  demo.playback->freeCameraLockedEntity = -1;
  demo.playback->freeCameraHighlightedEntityForLockOn = -1;
  LODWORD(demo.playback->timeScale) = FLOAT_1_0;
  demo.playback->fov = CG_GetDefaultFovForView(localClientNum);
  playback = demo.playback;
  demo.playback->actorCorpseOutOfSyncUseCount[0] = -1;
  playback->actorCorpseOutOfSyncUseCount[1] = -1;
  playback->actorCorpseOutOfSyncUseCount[2] = -1;
  playback->actorCorpseOutOfSyncUseCount[3] = -1;
  playback->actorCorpseOutOfSyncUseCount[4] = -1;
  playback->actorCorpseOutOfSyncUseCount[5] = -1;
  playback->actorCorpseOutOfSyncUseCount[6] = -1;
  playback->actorCorpseOutOfSyncUseCount[7] = -1;
  for ( i = 406696; i < 406824; i += 4 )
    *(float *)(&demo.playback->overridePause + i) = FLOAT_N1_0;
  demo.playback->actorCorpseAnimTimeAtJump[0] = FLOAT_N1_0;
  demo.playback->actorCorpseAnimTimeAtJump[1] = FLOAT_N1_0;
  demo.playback->actorCorpseAnimTimeAtJump[2] = FLOAT_N1_0;
  demo.playback->actorCorpseAnimTimeAtJump[3] = FLOAT_N1_0;
  demo.playback->actorCorpseAnimTimeAtJump[4] = FLOAT_N1_0;
  demo.playback->actorCorpseAnimTimeAtJump[5] = FLOAT_N1_0;
  demo.playback->actorCorpseAnimTimeAtJump[6] = FLOAT_N1_0;
  demo.playback->actorCorpseAnimTimeAtJump[7] = FLOAT_N1_0;
  Demo_InitializeHighlightReelSystem();
  demo.playbackInited = 1;
  if ( Demo_IsPlaying() && demo.header.isDemoClip )
    FX_BeginMarks(localClientNum);
  if ( Com_GameMode_IsMode(GAMEMODE_THEATER)
    && Party_InParty(&g_lobbyData)
    && PartyClient_CountMembers(&g_lobbyData) > 1 )
  {
    if ( (unsigned __int8)Party_AreWeHost(&g_lobbyData) )
      LiveTracker_WriteForAllLocalUsers(TRACKER_THEATRE_PARTY_COUNT, 1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcommonaddr.cpp:0x925880
void __cdecl Demo_RestorePreDemoSettings()
{
  Demo_Printf(3, "DEMO: Restoring the pre-demo settings\n");
  Dvar_SetInt(demo_client, 0);
  LODWORD(sharedUiInfo.visibilityBits[0]) &= 0xFF87FFFF;
  Dvar_SetBool(demo_pause, 0);
  Dvar_SetFloat(demo_freeCameraLockOnOrbitRadius, -100.0);
  Dvar_SetInt(demo_highlightReelPlayerFilter, 0);
  Dvar_SetInt(demo_highlightReelTransitionFilter, 0);
  Dvar_SetInt(demo_highlightReelStylesFilter, 0);
  Dvar_SetInt(demo_highlightReelNumberOfSegments, 20);
  Dvar_SetInt(demo_highlightReelMinimumStarsFilter, 1);
  Dvar_SetInt(demo_highlightReelGameResultFilter, 0);
  Com_SetTimeScale(1.0);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcommonaddr.cpp:0x925950
void __cdecl Demo_ParseServerCommands(LocalClientNum_t localClientNum)
{
  msg_t *msg; // ecx
  msg_t *v2; // esi
  int Long; // edi
  const char *String; // ebx
  int v5; // edx
  int v6; // eax
  clientConnection_t *LocalClientConnection; // esi
  int v8; // edi
  char *v9; // ebx
  int cmdMask[2]; // [esp+Ch] [ebp-414h]
  LocalClientNum_t v11; // [esp+14h] [ebp-40Ch]
  ClientNum_t clientNum; // [esp+18h] [ebp-408h] BYREF
  char strBuf[1024]; // [esp+1Ch] [ebp-404h] BYREF

  v2 = msg;
  v11 = localClientNum;
  clientNum = Dvar_GetInt(demo_client);
  cmdMask[1] = 0;
  Long = MSG_ReadLong(v2);
  cmdMask[0] = Long;
  String = MSG_ReadString(v2, strBuf, 0x400u);
  Demo_Printf(4, "DEMO: r ServerCommands MaskCmdNum: %i %i CmdString: %s\n", Long, 0, String);
  if ( demo.playbackInited && demo.playback->clipState == DEMO_CLIP_RECORD_CONTINUOUS )
  {
    MSG_WriteByte(&demo.playback->clipRecordingMsg, 10);
    MSG_WriteLong(&demo.playback->clipRecordingMsg, Long);
    MSG_WriteString(&demo.playback->clipRecordingMsg, String);
  }
  v5 = 1 << (clientNum & 0x1F);
  v6 = cmdMask[clientNum >> 5];
  if ( (v6 & v5) != 0 )
  {
    if ( v5 != v6
      || !Demo_IsAnyFreeMoveCamera()
      || (clientNum = (ClientNum_t)va("%s", String), Com_Parse((const char **)&clientNum)->token[0] != 66) )
    {
      LocalClientConnection = CL_GetLocalClientConnection(v11);
      v8 = ++LocalClientConnection->serverCommandSequence & 0x7F;
      v9 = Demo_AdjustTimeForReliableCommand(String);
      I_strncpyz(LocalClientConnection->serverCommands[v8], v9, 1024);
      if ( !I_strncmp(v9, "2 13 ", 5) )
        sscanf(v9 + 5, "%f %f %f", &cls.mapCenter, &cls.mapCenter.v[1], &cls.mapCenter.v[2]);
    }
  }
}

#endif // __UNIMPLEMENTED__
