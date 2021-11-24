// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdlobbyservice.cpp:0x92B450
void __cdecl Demo_ParseSnapshot(LocalClientNum_t localClientNum)
{
  msg_t *msg; // ecx
  LocalClientNum_t v2; // edi
  msg_t *v3; // esi
  clientActive_t *LocalClientGlobals; // ebx
  int Byte; // eax
  int v6; // eax
  int v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int TotalSize; // eax
  int Bit; // eax
  int packetBackupCount; // ecx
  int v16; // eax
  int v17; // ecx
  unsigned __int8 *v18; // [esp-18h] [ebp-543Ch]
  int v19; // [esp-4h] [ebp-5428h]
  playerState_s result; // [esp+Ch] [ebp-5418h] BYREF
  unsigned __int8 dst[10760]; // [esp+2A14h] [ebp-2A10h] BYREF
  bool v22; // [esp+541Fh] [ebp-5h]
  int c; // [esp+5420h] [ebp-4h]

  v2 = localClientNum;
  v3 = msg;
  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
  c = (int)CL_GetLocalClientConnection(localClientNum);
  if ( !Demo_IsPlaying() || !demo.playbackInited || demo.playback->clipState != DEMO_CLIP_PREVIEW )
    memcpy(
      (unsigned __int8 *)&demo.playback->prevSnapshot,
      (unsigned __int8 *)&demo.snapshot,
      sizeof(demo.playback->prevSnapshot));
  Demo_Printf(512, "Begin Demo Snapshot Read\n");
  svs.mapCenter = cls.mapCenter;
  SV_SetServerStaticHeader();
  memset((unsigned __int8 *)&newSnap_0, 0, sizeof(newSnap_0));
  newSnap_0.serverCommandNum = *(_DWORD *)(c + 17220);
  newSnap_0.serverTime = MSG_ReadLong(v3);
  newSnap_0.physicsTime = MSG_ReadLong(v3);
  newSnap_0.messageNum = *(_DWORD *)(c + 17216);
  Byte = MSG_ReadByte(v3);
  c = Byte;
  if ( Byte )
    newSnap_0.deltaNum = newSnap_0.messageNum - Byte;
  else
    newSnap_0.deltaNum = -1;
  v6 = MSG_ReadByte(v3);
  demo.snapshot.messageNum = newSnap_0.messageNum;
  demo.snapshot.serverCommandNum = newSnap_0.serverCommandNum;
  newSnap_0.snapFlags = v6;
  demo.snapshot.serverTime = newSnap_0.serverTime;
  demo.snapshot.physicsTime = newSnap_0.physicsTime;
  demo.snapshot.snapFlags = v6;
  if ( Demo_IsPlaying() && demo.header.isDemoClip )
  {
    demo.playback->originalFilmTime = newSnap_0.serverTime;
    demo.playback->clipServerTime += 100;
  }
  if ( demo.playbackInited && demo.playback->clipState == DEMO_CLIP_RECORD_CONTINUOUS )
  {
    MSG_WriteByte(&demo.playback->clipRecordingMsg, 12);
    MSG_WriteLong(&demo.playback->clipRecordingMsg, newSnap_0.serverTime);
    MSG_WriteLong(&demo.playback->clipRecordingMsg, newSnap_0.physicsTime);
    MSG_WriteByte(&demo.playback->clipRecordingMsg, c);
    MSG_WriteByte(&demo.playback->clipRecordingMsg, newSnap_0.snapFlags);
  }
  newSnap_0.valid = 1;
  c = MSG_GetNumBitsRead(v3);
  Demo_ReadMatchState(localClientNum, v3, newSnap_0.serverTime);
  newSnap_0.parseMatchStateIndex = LocalClientGlobals->parseMatchStateIndex - 1;
  v7 = MSG_GetNumBitsRead(v3);
  Demo_RecordProfileData(DEMO_PROFILE_MATCHSTATES, (v7 - c) / 8);
  c = MSG_GetNumBitsRead(v3);
  v8 = (unsigned __int8 *)Demo_ReadPlayerStates(&result, localClientNum, v3, newSnap_0.serverTime);
  memcpy(dst, v8, sizeof(dst));
  memcpy((unsigned __int8 *)&newSnap_0.ps, dst, sizeof(newSnap_0.ps));
  v9 = MSG_GetNumBitsRead(v3);
  Demo_RecordProfileData(DEMO_PROFILE_PLAYERSTATES, (v9 - c) / 8);
  c = MSG_GetNumBitsRead(v3);
  newSnap_0.numEntities = Demo_ReadPacketEntities(localClientNum, v3, newSnap_0.serverTime, newSnap_0.deltaNum);
  newSnap_0.parseEntitiesIndex = LocalClientGlobals->parseEntitiesIndex - newSnap_0.numEntities;
  v10 = MSG_GetNumBitsRead(v3);
  Demo_RecordProfileData(DEMO_PROFILE_ENTITIES, (v10 - c) / 8);
  c = MSG_GetNumBitsRead(v3);
  newSnap_0.numClients = Demo_ReadPacketClients(localClientNum, v3, newSnap_0.serverTime, newSnap_0.deltaNum);
  newSnap_0.parseClientsIndex = LocalClientGlobals->parseClientsIndex - newSnap_0.numClients;
  v11 = MSG_GetNumBitsRead(v3);
  Demo_RecordProfileData(DEMO_PROFILE_CLIENTS, (v11 - c) / 8);
  newSnap_0.numActors = Demo_ReadPacketActors(localClientNum, v3, newSnap_0.serverTime, newSnap_0.deltaNum);
  newSnap_0.parseActorsIndex = LocalClientGlobals->parseActorsIndex - newSnap_0.numActors;
  GlassCl_ParseSnapshot(localClientNum, v3);
  if ( demo.header.hasExtraNetworkProfileData )
  {
    c = MSG_GetNumBitsRead(v3);
    if ( MSG_ReadBit(v3) )
    {
      MSG_ReadLong(v3);
      MSG_ReadLong(v3);
    }
    if ( MSG_ReadBit(v3) )
      MSG_ReadLong(v3);
    while ( MSG_ReadBit(v3) )
    {
      MSG_ReadBits(v3, 5);
      MSG_ReadLong(v3);
    }
    while ( MSG_ReadBit(v3) )
    {
      MSG_ReadBits(v3, 5);
      MSG_ReadShort(v3);
    }
    Demo_ParseClientPackets(v3);
    Demo_ParseReliableCmdSizes(v3);
    v12 = MSG_GetNumBitsRead(v3);
    totalNetworkProfileData += v12 - c;
    c = totalNetworkProfileData / 8;
    v19 = 100 * (totalNetworkProfileData / 8) / Demo_GetTotalSize();
    TotalSize = Demo_GetTotalSize();
    printf(
      "Demo network profile data: %i bits (%i bytes, %i kbytes), %i kbytes total (%i%%)\n",
      totalNetworkProfileData,
      c,
      c / 1024,
      TotalSize / 1024,
      v19);
  }
  if ( MSG_ReadBit(v3) )
  {
    demo.spawnDebugBufferPos = MSG_ReadShort(v3);
    MSG_ReadData(v3, demo.spawnDebugBuffer, demo.spawnDebugBufferPos);
    if ( MSG_ReadBit(v3) )
      Com_Error(ERR_DROP, "End of spawn debug buffer not found. This is terminal.");
  }
  else
  {
    demo.spawnDebugBufferPos = 0;
  }
  Bit = MSG_ReadBit(v3);
  v22 = Bit != 0;
  if ( Bit )
  {
    if ( v3->overflowed
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
            7828,
            0,
            "(!msg->overflowed)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    Demo_ReadCustomSnapshotInformation(localClientNum, v3);
  }
  if ( demo.playbackInited && demo.playback->clipState == DEMO_CLIP_RECORD_CONTINUOUS )
  {
    GlassCl_WriteDemoSnapshot(&demo.playback->clipRecordingMsg);
    if ( demo.header.hasExtraNetworkProfileData )
    {
      MSG_WriteBit0(&demo.playback->clipRecordingMsg);
      MSG_WriteBit0(&demo.playback->clipRecordingMsg);
      MSG_WriteBit0(&demo.playback->clipRecordingMsg);
      MSG_WriteBit0(&demo.playback->clipRecordingMsg);
      MSG_WriteBit0(&demo.playback->clipRecordingMsg);
      MSG_WriteBit0(&demo.playback->clipRecordingMsg);
    }
    MSG_WriteBit0(&demo.playback->clipRecordingMsg);
    if ( v22 )
    {
      MSG_WriteBit1(&demo.playback->clipRecordingMsg);
      Demo_WriteCustomSnapshotInformation(&demo.playback->clipRecordingMsg, localClientNum);
      v2 = localClientNum;
    }
    else
    {
      MSG_WriteBit0(&demo.playback->clipRecordingMsg);
    }
    MSG_WriteByte(&demo.playback->clipRecordingMsg, 14);
  }
  SV_GetServerStaticHeader();
  if ( v3->overflowed
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
          7870,
          0,
          "(!msg->overflowed)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( Demo_IsPlaying() && demo.header.isDemoClip )
  {
    newSnap_0.serverTime = demo.playback->clipServerTime;
    newSnap_0.physicsTime = demo.playback->clipServerTime;
  }
  if ( (!Demo_IsPlaying() || !demo.header.isDemoClip) && Demo_ShouldGenerateKeyFrameSnapshot(newSnap_0.serverTime, v2) )
    Demo_GenerateKeyFrameSnapshot(v2);
  Demo_SetupPlaybackForClient(&newSnap_0.ps, v2);
  Demo_Printf(512, "End Demo Snapshot Read\n");
  packetBackupCount = LocalClientGlobals->packetBackupCount;
  v16 = LocalClientGlobals->snap.messageNum + 1;
  if ( newSnap_0.messageNum - v16 >= packetBackupCount )
    v16 = newSnap_0.messageNum - packetBackupCount + 1;
  for ( ; v16 < newSnap_0.messageNum; LocalClientGlobals->snapshots[v17].valid = 0 )
    v17 = v16++ & LocalClientGlobals->packetBackupMask;
  memcpy((unsigned __int8 *)&LocalClientGlobals->snap, (unsigned __int8 *)&newSnap_0, sizeof(LocalClientGlobals->snap));
  v18 = (unsigned __int8 *)&LocalClientGlobals->snapshots[LocalClientGlobals->snap.messageNum & LocalClientGlobals->packetBackupMask];
  LocalClientGlobals->snap.ping = 999;
  memcpy(v18, (unsigned __int8 *)&LocalClientGlobals->snap, 0x2A48u);
  LocalClientGlobals->newSnapshots = 1;
  LocalClientGlobals->snapServerTime = newSnap_0.serverTime;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyservice.cpp:0x92BBE0
void __cdecl Demo_ParseServerMessage(LocalClientNum_t localClientNum, msg_t *msg, int msgType, int msgSequence)
{
  clientConnection_t *LocalClientConnection; // esi
  int v5; // eax
  int Long; // eax
  int sequence; // eax
  int Byte; // esi
  clientActive_t *LocalClientGlobals; // esi
  const char *v10; // eax
  int acknowledge; // [esp-Ch] [ebp-38h]
  msg_bookmark_t msgBookmark; // [esp+10h] [ebp-1Ch] BYREF

  LocalClientConnection = CL_GetLocalClientConnection(localClientNum);
  v5 = LittleLong(msgSequence);
  acknowledge = LocalClientConnection->reliableCommands.acknowledge;
  LocalClientConnection->serverMessageSequence = v5;
  LocalClientConnection->lastPacketTime = cls.realtime;
  Demo_Printf(
    1,
    "Demo_ParseServerMessage() - msgType: %d msgSeq: %d ClientCmd: %d\n",
    msgType,
    msgSequence,
    acknowledge);
  Long = MSG_ReadLong(msg);
  LocalClientConnection->reliableCommands.acknowledge = Long;
  if ( demo.playbackInited && demo.playback->clipState == DEMO_CLIP_RECORD_CONTINUOUS )
    MSG_WriteLong(&demo.playback->clipRecordingMsg, Long);
  sequence = LocalClientConnection->reliableCommands.sequence;
  if ( LocalClientConnection->reliableCommands.acknowledge >= sequence - 128 )
  {
    MSG_SetBookmark(msg, &msgBookmark);
    if ( !msg )
      MSG_GotoBookmark(0, &msgBookmark);
    if ( !msg->overflowed )
    {
      while ( 2 )
      {
        Byte = MSG_ReadByte(msg);
        if ( Byte != 14 )
        {
          if ( msg->overflowed
            && !Assert_MyHandler(
                  "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
                  7970,
                  0,
                  "(!msg->overflowed)",
                  (const char *)&pBlock) )
          {
            __debugbreak();
          }
          switch ( Byte )
          {
            case 0:
              goto $LN9_118;
            case 1:
              CL_ParseGamestate(localClientNum, msg);
              goto $LN9_118;
            case 2:
              Demo_ReadConfigStrings(msg, localClientNum);
              Demo_UpdateConfigStrings(localClientNum);
              goto $LN9_118;
            case 10:
              Demo_ParseServerCommands(localClientNum);
              goto $LN9_118;
            case 12:
              Demo_ParseSnapshot(localClientNum);
$LN9_118:
              if ( msg->overflowed )
                break;
              continue;
            default:
              v10 = va("CL_ParseDemoServerMessage: Illegible server message %d\n", Byte);
              if ( !Assert_MyHandler(
                      "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
                      7977,
                      0,
                      (const char *)&pBlock,
                      v10) )
                __debugbreak();
              return;
          }
        }
        break;
      }
    }
    if ( (!Demo_IsPlaying() || !demo.header.isDemoClip) && demo.playbackInited && demo.playback->keyframeGenerated )
      Demo_WriteKeyFrameInformation(localClientNum);
    if ( msg->overflowed
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
            8005,
            0,
            "(!msg->overflowed)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( demo.playback->forceResetTimeValues )
    {
      LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
      Demo_ResetTimeValues(localClientNum, LocalClientGlobals->snap.serverTime);
      LocalClientGlobals->serverTimeDelta = LocalClientGlobals->snap.serverTime - cls.realtime;
      demo.playback->forceResetTimeValues = 0;
    }
  }
  else
  {
    LocalClientConnection->reliableCommands.acknowledge = sequence;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyservice.cpp:0x92BE70
void __usercall Demo_HandleInput(
        double a1@<st0>,
        LocalClientNum_t localClientNum,
        ControllerIndex_t controllerIndex,
        int key,
        int pressed)
{
  DWORD v5; // eax
  bool IsPauseMenuOpen; // bl
  bool IsClipPlaying; // bl
  bool IsClipAndScreenshotsEnabled; // al
  clientActive_t *LocalClientGlobals; // esi
  float val; // [esp+0h] [ebp-20h]
  float vala; // [esp+0h] [ebp-20h]
  BOOL timeScale; // [esp+18h] [ebp-8h]
  float timeScalea; // [esp+18h] [ebp-8h]
  float timeScaleb; // [esp+18h] [ebp-8h]
  float timeScalec; // [esp+18h] [ebp-8h]
  float timeScaled; // [esp+18h] [ebp-8h]
  bool isClipRecording; // [esp+1Ch] [ebp-4h]
  char isClipRecordinga; // [esp+1Ch] [ebp-4h]
  bool isDollyCamMarkerDialogOpen; // [esp+1Dh] [ebp-3h]
  bool isSaveDialogOpen; // [esp+1Eh] [ebp-2h]
  bool enableHostControls; // [esp+1Fh] [ebp-1h]
  bool enableHostControlsa; // [esp+1Fh] [ebp-1h]

  if ( Demo_IsPlaying() )
  {
    if ( demo.playbackInited
      && cgArray
      && localClientNum
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\cgame\\../cgame_mp/cg_local_mp.h",
            2171,
            0,
            "((localClientNum == 0))",
            "(localClientNum) = %i",
            localClientNum) )
    {
      __debugbreak();
    }
    if ( Demo_IsPlaying() && (demo.playbackMode & 1) != 0 )
    {
      if ( pressed )
      {
        if ( key == 2 )
          Cbuf_AddText(localClientNum, "demo_stop 1\n");
      }
    }
    else
    {
      if ( !Demo_IsPlaying() || !demo.playbackInited || !demo.playback->creatingHighlightReel )
        goto LABEL_103;
      if ( key == 2 || key == 27 )
      {
        Demo_CancelHighlightReelCreation();
        return;
      }
      if ( key == 16 || key == 170 )
      {
LABEL_103:
        if ( Demo_IsClipPreviewRunning() )
        {
          if ( key == 2 )
            Demo_CancelPreview();
        }
        else if ( Demo_IsRepositioningDollyCamMarker() )
        {
          if ( key == 17 || key == 102 )
          {
            Demo_ApplyNewDollyCamMarkerPosition(localClientNum, 0);
            Demo_OpenDollyCamMarkerPopUp(localClientNum);
          }
          else if ( key == 2 || key == 27 )
          {
            Demo_ApplyNewDollyCamMarkerPosition(localClientNum, 1);
            demo.playback->cancelRepositioning = 1;
          }
        }
        else if ( demo.playback && demo.playback->holdCmd.active && demo.playback->holdCmd.key == key )
        {
          v5 = Sys_Milliseconds();
          Demo_HandleHoldInput(
            localClientNum,
            demo.playback->holdCmd.key,
            (int)(v5 - demo.playback->holdCmd.activatedTime) >= 250);
        }
        else
        {
          IsPauseMenuOpen = Demo_IsPauseMenuOpen(localClientNum);
          timeScale = CG_IsScoreboardDisplayed(localClientNum);
          isSaveDialogOpen = Demo_IsSaveDialogOpen(localClientNum);
          isDollyCamMarkerDialogOpen = Demo_IsDollyCamMarkerDialogOpen(localClientNum);
          isClipRecording = Demo_IsErrorDialogOpen(localClientNum);
          if ( !Demo_IsInformationScreenActive()
            || (enableHostControls = 1,
                demo.playback->informationScreenType == DEMO_INFORMATION_SCREEN_WAITING_FOR_DOWNLOAD) )
          {
            enableHostControls = 0;
          }
          if ( CL_GetLocalClientConnectionState(localClientNum) == CA_ACTIVE
            && !IsPauseMenuOpen
            && !timeScale
            && !isSaveDialogOpen
            && !isDollyCamMarkerDialogOpen
            && !isClipRecording
            && !enableHostControls )
          {
            isClipRecordinga = Demo_IsClipRecording();
            IsClipPlaying = Demo_IsClipPlaying();
            enableHostControlsa = Demo_IsHostControlsEnabled();
            IsClipAndScreenshotsEnabled = Demo_IsClipAndScreenshotsEnabled();
            switch ( key )
            {
              case 1:
              case 32:
                if ( pressed && enableHostControlsa )
                {
                  Demo_Pause();
                  demo.playback->buttonPressTime[0] = Sys_Milliseconds();
                }
                break;
              case 2:
              case 168:
                if ( !IsClipPlaying && !(unsigned __int8)Demo_IsShoutcastMode() && pressed )
                {
                  if ( !Demo_IsPlaying() || !demo.header.isDemoClip )
                    demo.playback->hideGameHud = !demo.playback->hideGameHud;
                  demo.playback->buttonPressTime[4] = Sys_Milliseconds();
                }
                break;
              case 3:
              case 114:
                if ( IsClipAndScreenshotsEnabled && pressed )
                {
                  if ( isClipRecordinga )
                  {
                    if ( !(unsigned __int8)Demo_IsHighlightReelMode() )
                    {
                      Demo_PauseClipRecord(localClientNum);
                      demo.playback->buttonPressTime[1] = Sys_Milliseconds();
                    }
                  }
                  else
                  {
                    Demo_ActivateHoldInput((LocalClientNum_t)key);
                  }
                }
                break;
              case 4:
              case 169:
                if ( !IsClipPlaying && pressed )
                {
                  Demo_SwitchCamera(a1, localClientNum);
                  demo.playback->buttonPressTime[3] = Sys_Milliseconds();
                }
                break;
              case 5:
              case 200:
                if ( pressed )
                {
                  if ( !Demo_IsAnyFreeMoveCamera()
                    || Dvar_GetInt(net_showprofile)
                    || (unsigned __int8)Demo_IsShoutcastMode()
                    || Demo_IsWatchingWithParty() )
                  {
                    Demo_SwitchPlayer(localClientNum, 1, -1);
                    demo.playback->buttonPressTime[2] = Sys_Milliseconds();
                  }
                  else
                  {
                    Demo_SwitchFreeCamMode(localClientNum, 1);
                    demo.playback->buttonPressTime[2] = Sys_Milliseconds();
                  }
                }
                break;
              case 6:
              case 201:
                if ( pressed )
                {
                  if ( !Demo_IsAnyFreeMoveCamera()
                    || Dvar_GetInt(net_showprofile)
                    || (unsigned __int8)Demo_IsShoutcastMode()
                    || Demo_IsWatchingWithParty() )
                  {
                    Demo_SwitchPlayer(localClientNum, 0, -1);
                    demo.playback->buttonPressTime[2] = Sys_Milliseconds();
                  }
                  else
                  {
                    Demo_SwitchFreeCamMode(localClientNum, 0);
                    demo.playback->buttonPressTime[2] = Sys_Milliseconds();
                  }
                }
                break;
              case 16:
              case 170:
                if ( pressed )
                {
                  demo.playback->hideDemoHud = !demo.playback->hideDemoHud;
                  demo.playback->buttonPressTime[5] = Sys_Milliseconds();
                }
                break;
              case 17:
              case 102:
                if ( pressed )
                {
                  if ( Demo_IsCameraEditMode() )
                  {
                    if ( Demo_GetHighlightedDollyCamMarker() == -1 )
                      Cbuf_AddText(localClientNum, "demo_adddollycammarker\n");
                    else
                      Cbuf_AddText(localClientNum, "demo_switchdollycammarker -1\n");
                  }
                  else if ( Demo_IsMovieCamera() )
                  {
                    if ( Demo_IsFreeCameraLockedOnEntity() )
                    {
                      Dvar_SetFloat(demo_freeCameraLockOnOrbitRadius, -100.0);
                      demo.playback->freeCameraLockedEntity = -1;
                      demo.playback->freeCameraLockedOnEntityActive = 0;
                      LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
                      AxisToAngles(demo.playback->refdef.viewaxis, &LocalClientGlobals->viewangles);
                      LocalClientGlobals->viewangles.z = 0.0;
                    }
                    else if ( Demo_IsFreeCameraEntityLockOnAllowed()
                           && Demo_GetHighlightedFreeCameraLockOnEntity() != -1
                           && !demo.playback->freeCameraLockedOnEntityActive )
                    {
                      demo.playback->freeCameraLockedEntity = Demo_GetHighlightedFreeCameraLockOnEntity();
                      demo.playback->freeCameraLockedOnEntityActive = 1;
                      demo.playback->initialEntityAngles = CG_GetEntity(
                                                             localClientNum,
                                                             demo.playback->freeCameraLockedEntity)->pose.angles;
                    }
                  }
                }
                break;
              case 154:
                if ( !IsClipPlaying && enableHostControlsa && pressed )
                {
                  timeScalea = Dvar_GetFloat(demo_maxTimeScale);
                  val = Com_GetTimeScale() + 0.2;
                  timeScaleb = I_fclamp(val, 0.2, timeScalea);
                  Demo_SetTimeScale(timeScaleb);
                  demo.playback->buttonPressTime[9] = Sys_Milliseconds();
                }
                break;
              case 155:
                if ( !IsClipPlaying && enableHostControlsa && pressed )
                {
                  timeScalec = Dvar_GetFloat(demo_maxTimeScale);
                  vala = Com_GetTimeScale() - 0.2;
                  timeScaled = I_fclamp(vala, 0.2, timeScalec);
                  Demo_SetTimeScale(timeScaled);
                  demo.playback->buttonPressTime[8] = Sys_Milliseconds();
                }
                break;
              default:
                Demo_HandleInputForControllerConfig(key, localClientNum, controllerIndex, pressed);
                break;
            }
          }
        }
      }
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyservice.cpp:0x92C660
void __usercall Demo_ProcessKeyFrameJump(int keyframeIndex@<eax>, double a2@<st0>, LocalClientNum_t localClientNum)
{
  int v4; // edi
  int v5; // eax
  clientActive_t *v6; // edi
  LocalClientNum_t PrimaryDefault; // eax
  msg_t keyframeMsg; // [esp+8h] [ebp-3Ch] BYREF
  int preparse; // [esp+38h] [ebp-Ch]
  clientActive_t *LocalClientGlobals; // [esp+3Ch] [ebp-8h]

  if ( demo.playback->keyFrame[keyframeIndex].keyframeSnapshotTime < 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
          2289,
          0,
          "(demo.playback->keyFrame[keyframeIndex].keyframeSnapshotTime >= 0)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
  Demo_Printf(
    128,
    "Demo_ProcessKeyFrameJump - newKeyframeIndex: %d currKeyframeIndex: %d\n",
    keyframeIndex,
    demo.playback->keyframeIndex);
  Demo_Printf(
    128,
    "Demo_ProcessKeyFrameJump - We need to seeking file to %d block\n",
    demo.playback->keyFrame[keyframeIndex].demoFileMemoryBlockStart);
  Demo_Printf(
    128,
    "Demo_ProcessKeyFrameJump - Block's servertime is %d seq is %d\n",
    demo.playback->keyFrame[keyframeIndex].keyframeSnapshotTime,
    demo.playback->keyFrame[keyframeIndex].firstCmdSequence);
  preparse = Sys_Milliseconds();
  PIXBeginNamedEvent(-16711681, "Demo_ProcessKeyFrameJump - File Seek");
  _InterlockedExchange(&demo.totalSize, demo.playback->keyFrame[keyframeIndex].demoFileMemoryBlockStart);
  Demo_SeekFile(demo.demoFileHandle, demo.playback->keyFrame[keyframeIndex].demoFileMemoryBlockStart, 2);
  Demo_Load();
  MSG_GotoBookmark(&demo.msg, &demo.playback->keyFrame[keyframeIndex].msgBookmark);
  demo.playback->lastJumpedKeyframe = keyframeIndex;
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
  MSG_Init(&keyframeMsg, demo.msgBuf1, 0x10000);
  memcpy(
    demo.msgBuf1,
    &demo.playback->keyframeBuf[demo.playback->keyFrame[keyframeIndex].keyframeBufferStart],
    demo.playback->keyFrame[keyframeIndex].size);
  keyframeMsg.cursize = demo.playback->keyFrame[keyframeIndex].size;
  Demo_Printf(128, "Keyframe r - Time: %d\n", demo.playback->keyFrame[keyframeIndex].keyframeSnapshotTime);
  Demo_Printf(
    128,
    "Keyframe r - File Related: FileStart: %d\n",
    demo.playback->keyFrame[keyframeIndex].demoFileMemoryBlockStart);
  Demo_Printf(
    128,
    "Keyframe r - Demo Msg: Size: %d 1stByte: %d LastByte: %d\n",
    demo.msg.cursize,
    *demo.msg.data,
    demo.msg.data[demo.msg.cursize - 1]);
  Demo_Printf(
    128,
    "Keyframe r - BookMark: ReadCount: %d Msg: %d\n",
    demo.msg.readcount,
    demo.msg.data[demo.msg.readcount]);
  Demo_Printf(128, "Keyframe r - BookMark: Bit: %d Msg:%d\n", demo.msg.bit, demo.msg.data[demo.msg.bit >> 3]);
  Demo_Printf(
    128,
    "Keyframe r - KeyframeMsg: Index: %d BufIndex: %d Time: %d Size: %d 1stByte: %d LastByte: %d\n",
    keyframeIndex,
    demo.playback->keyFrame[keyframeIndex].keyframeBufferStart,
    demo.playback->keyFrame[keyframeIndex].keyframeSnapshotTime,
    keyframeMsg.cursize,
    *keyframeMsg.data,
    keyframeMsg.data[keyframeMsg.cursize - 1]);
  demo.playback->completed = 0;
  if ( Demo_IsPlaying() && demo.header.isDemoClip )
  {
    demo.playback->clipTime = demo.playback->keyFrame[keyframeIndex].keyframeSnapshotTime;
    demo.playback->clipServerTime = demo.playback->keyFrame[keyframeIndex].keyframeClipServerTime - 100;
  }
  PIXBeginNamedEvent(-16711681, "Demo_ProcessKeyFrameJump - Process Keyframe");
  MSG_UnEmbed(&keyframeMsg);
  v4 = MSG_ReadBits(&keyframeMsg, 2);
  Demo_ResetSnapshotData();
  for ( ; v4 == 2; v4 = MSG_ReadBits(&keyframeMsg, 2) )
    Demo_ParseClipCommand(a2, localClientNum, &keyframeMsg, 1);
  v5 = MSG_ReadLong(&keyframeMsg);
  Demo_ParseServerMessage(localClientNum, &keyframeMsg, v4, v5);
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
  PIXBeginNamedEvent(-16711681, "Demo_ProcessKeyFrameJump - Resetting World");
  v6 = LocalClientGlobals;
  Demo_ResetTimeValues(localClientNum, LocalClientGlobals->snap.serverTime);
  Demo_ResetSequenceNumbers(localClientNum, v6->snap.messageNum - 1);
  Demo_ResetWorldInformation(a2, localClientNum, v6->snap.serverTime);
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
  PIXBeginNamedEvent(-16711681, "Demo_ProcessKeyFrameJump - Reading Messages");
  if ( Demo_IsPlaying() && (demo.playbackMode & 1) != 0 )
    v6->serverTimeDelta = 0;
  else
    v6->serverTimeDelta = preparse + v6->snap.serverTime - cls.realtime - Sys_Milliseconds();
  if ( demo.playbackInited )
    demo.playback->jumpTimeFlag = 1;
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
  Con_Close(localClientNum);
  SND_StopSounds(SND_STOP_ALL);
  demo.playback->overridePause = 1;
  CL_SetCGameTime(localClientNum);
  demo.playback->overridePause = 0;
  PrimaryDefault = Com_LocalClients_GetPrimaryDefault();
  CScr_NotifyLevel(PrimaryDefault, "snd_clear_script_duck");
  ++demo.playback->keyframeJumpCount;
  if ( Demo_IsCameraEditMode() )
    Demo_RefreshAllDollyCamFX(localClientNum);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyservice.cpp:0x92CA80
void __usercall Demo_JumpForward(double a1@<st0>, LocalClientNum_t localClientNum, int serverTime)
{
  int KeyFrameForJumpForward; // eax

  if ( demo.playbackInited && !demo.shutdownInProgress && demo.playback->completed )
  {
    Com_PrintError(25, "We cannot forward a demo that is completed\n");
  }
  else if ( Demo_IsPlaying() && demo.playbackInited && demo.playback->clipState == DEMO_CLIP_PREVIEW )
  {
    Com_PrintError(25, "We cannot forward a demo that is being previewed\n");
  }
  else
  {
    KeyFrameForJumpForward = Demo_GetKeyFrameForJumpForward(localClientNum, serverTime);
    if ( KeyFrameForJumpForward >= 0 )
      Demo_ProcessKeyFrameJump(KeyFrameForJumpForward, a1, localClientNum);
    else
      Demo_Printf(128, "DemoForward - We couldnt find a suitable rewind keyframe.\n");
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyservice.cpp:0x92CB30
void __usercall Demo_JumpBack(double a1@<st0>, LocalClientNum_t localClientNum, int serverTime)
{
  int KeyFrameForJumpBack; // eax

  if ( Demo_IsPlaying() && demo.playbackInited && demo.playback->clipState == DEMO_CLIP_PREVIEW )
  {
    Com_PrintError(25, "We cannot rewind a demo that is being previewed\n");
  }
  else
  {
    KeyFrameForJumpBack = Demo_GetKeyFrameForJumpBack(localClientNum, serverTime);
    if ( KeyFrameForJumpBack >= 0 )
      Demo_ProcessKeyFrameJump(KeyFrameForJumpBack, a1, localClientNum);
    else
      Demo_Printf(128, "DemoBack - Unable to find a proper previous keyframe.\n");
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyservice.cpp:0x92CBA0
void __usercall Demo_RestoreDemoPreviewPoint(
        double a1@<st0>,
        LocalClientNum_t localClientNum,
        demoRestorePoint restorePoint)
{
  int i; // esi
  int v5; // eax
  clientActive_t *v6; // esi
  msg_t previewMsg; // [esp+8h] [ebp-34h] BYREF
  clientActive_t *LocalClientGlobals; // [esp+38h] [ebp-4h]
  cg_t *cgameGlob; // [esp+44h] [ebp+8h]

  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
  CL_GetLocalClientConnection(localClientNum);
  if ( localClientNum
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\cgame\\../cgame_mp/cg_local_mp.h",
          2195,
          0,
          "((localClientNum == 0))",
          "(localClientNum) = %i",
          localClientNum) )
  {
    __debugbreak();
  }
  if ( cgArray )
  {
    if ( localClientNum
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\cgame\\../cgame_mp/cg_local_mp.h",
            2171,
            0,
            "((localClientNum == 0))",
            "(localClientNum) = %i",
            localClientNum) )
    {
      __debugbreak();
    }
    cgameGlob = cgArray;
  }
  else
  {
    cgameGlob = 0;
  }
  if ( demo.playback->demoCompleteStateForRestorationPoint[restorePoint] )
  {
    demo.playback->completed = 1;
  }
  else
  {
    _InterlockedExchange(&demo.totalSize, demo.playback->demoPreview[restorePoint].demoFileMemoryBlockStart);
    Demo_SeekFile(demo.demoFileHandle, demo.playback->demoPreview[restorePoint].demoFileMemoryBlockStart, 2);
    Demo_Load();
    MSG_GotoBookmark(&demo.msg, &demo.playback->demoPreview[restorePoint].msgBookmark);
    MSG_Init(&previewMsg, demo.msgBuf1, 0x10000);
    memcpy(demo.msgBuf1, demo.playback->demoPreviewBuf[restorePoint], demo.playback->demoPreview[restorePoint].size);
    previewMsg.cursize = demo.playback->demoPreview[restorePoint].size;
    demo.playback->completed = 0;
    MSG_UnEmbed(&previewMsg);
    Demo_ResetSnapshotData();
    for ( i = MSG_ReadBits(&previewMsg, 2); i == 2; i = MSG_ReadBits(&previewMsg, 2) )
      Demo_ParseClipCommand(a1, localClientNum, &previewMsg, 0);
    v5 = MSG_ReadLong(&previewMsg);
    Demo_ParseServerMessage(localClientNum, &previewMsg, i, v5);
    v6 = LocalClientGlobals;
    Demo_ResetTimeValues(localClientNum, LocalClientGlobals->snap.serverTime);
    Demo_ResetSequenceNumbers(localClientNum, v6->snap.messageNum - 1);
    Demo_ResetWorldInformation(a1, localClientNum, v6->snap.serverTime);
    cgameGlob->latestSnapshotNum = v6->snap.messageNum;
    v6->serverTimeDelta = v6->snap.serverTime - cls.realtime;
    SND_StopSounds(SND_STOP_ALL);
    demo.playback->overridePause = 1;
    CL_SetCGameTime(localClientNum);
    demo.playback->overridePause = 0;
    if ( Demo_IsCameraEditMode() )
      Demo_RefreshAllDollyCamFX(localClientNum);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyservice.cpp:0x92CDB0
void __usercall Demo_RestoreUIStateAfterPreview(LocalClientNum_t localClientNum@<esi>, double a2@<st0>)
{
  if ( demo.playbackInited )
    demo.playback->clipState = DEMO_CLIP_PAUSED;
  Dvar_SetBool(demo_pause, 1);
  if ( demo.playback->pendingSegmentSave )
  {
    Demo_RestoreDemoPreviewPoint(a2, localClientNum, DEMO_RESTORE_POINT_END);
    Demo_OpenSavePopUp(localClientNum, DEMO_SAVE_POPUP_CLIP);
    BG_EvalVehicleName();
  }
  else
  {
    if ( demo.playback->previewAllSegments )
    {
      Demo_RestoreDemoPreviewPoint(a2, localClientNum, DEMO_RESTORE_POINT_START);
      CG_CloseScoreboard(localClientNum);
      Key_SetCatcher(localClientNum, 8);
      UI_OpenMenu(localClientNum, "demo_manage_segments");
      demo.playback->previewAllSegments = 0;
    }
    else
    {
      Demo_RestoreDemoPreviewPoint(a2, localClientNum, DEMO_RESTORE_POINT_START);
      CG_CloseScoreboard(localClientNum);
      Key_SetCatcher(localClientNum, 8);
      UI_OpenMenu(localClientNum, "demo_manage_segments");
    }
    BG_EvalVehicleName();
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyservice.cpp:0x92CE70
void __cdecl Demo_ReadGamestate(LocalClientNum_t localClientNum)
{
  int Bits; // esi
  int Long; // edi
  int v3; // eax

  Bits = MSG_ReadBits(&demo.msg, 2);
  Long = MSG_ReadLong(&demo.msg);
  MSG_UnEmbed(&demo.msg);
  Demo_ParseServerMessage(localClientNum, &demo.msg, Bits, Long);
  v3 = MSG_GetNumBitsRead(&demo.msg);
  Demo_RecordProfileData(DEMO_PROFILE_GAMESTATE, v3 / 8);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyservice.cpp:0x92CED0
void __cdecl Demo_ProcessPlayback(ControllerIndex_t controllerIndex)
{
  LocalClientNum_t LocalClientNum; // esi
  clientConnection_t *LocalClientConnection; // ebx
  int totalSize; // edi
  ClientNum_t DefaultClient; // eax
  msg_bookmark_t bookmark; // [esp+Ch] [ebp-1Ch] BYREF

  CL_SetupClientsForIngame();
  LocalClientNum = Com_ControllerIndex_GetLocalClientNum(controllerIndex);
  Com_UnloadFrontEnd();
  CL_AllocatePerLocalClientMemory(0, 0);
  if ( LocalClientNum
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\client_mp\\../client/client.h",
          701,
          0,
          "((localClientNum == 0))",
          "(localClientNum) = %i",
          LocalClientNum) )
  {
    __debugbreak();
  }
  LocalClientConnection = CL_GetLocalClientConnection(LocalClientNum);
  if ( LocalClientNum
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\client_mp\\../client/client.h",
          644,
          0,
          "((localClientNum == 0))",
          "(localClientNum) = %i",
          LocalClientNum) )
  {
    __debugbreak();
  }
  Con_Close(LocalClientNum);
  Demo_SeekFile(demo.demoFileHandle, 0, 2);
  Demo_Load();
  Demo_ReadHeader();
  MSG_SetBookmark(&demo.msg, &bookmark);
  totalSize = demo.totalSize;
  if ( Demo_ReadFooter(demo.demoName, demo.demoFileHandle) )
  {
    if ( demo.header.isZombie )
    {
      Dvar_SetString(ui_zm_gamemodegroup, demo.footer.info.zmGameModeGroup);
      Dvar_SetString(ui_zm_mapstartlocation, demo.footer.info.zmMapStartLoc);
    }
    MSG_GotoBookmark(&demo.msg, &bookmark);
    Demo_SeekFile(demo.demoFileHandle, totalSize, 2);
    CL_LocalClient_SetActive(LocalClientNum, 1);
    keyCatchers &= 1u;
    *(_DWORD *)&cancelAll = 6;
    I_strncpyz(cls.servername, demo.demoName, 256);
    NET_SetNetAdrLoopbackIP(&LocalClientConnection->serverAddress);
    Demo_ReadGamestate(LocalClientNum);
    DefaultClient = Demo_GetDefaultClient();
    Demo_SetDefaultClient(LocalClientNum, DefaultClient);
    Demo_SetDefaultVisionSet(LocalClientNum);
    Demo_RegisterDollyCameraFX();
    demo.playbackInited = 0;
  }
  else
  {
    Com_PrintError(0, "ERROR: Error Reading footer\n");
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyservice.cpp:0x92D090
char __usercall Demo_ReadDemoMessage@<al>(double a1@<st0>, LocalClientNum_t localClientNum)
{
  demoPlayback *playback; // eax
  demoCameraMode clipCameraMode; // ecx
  demoPlayback *v4; // eax
  int clipTime; // eax
  demoClipState clipState; // eax
  int Bits; // ebx
  demoPlayback *v9; // eax
  int v10; // eax
  demoClipState v11; // eax
  int Long; // esi
  __int64 movieCamAngles; // [esp+18h] [ebp-1Ch]
  float movieCamAngles_8; // [esp+20h] [ebp-14h]
  __int64 movieCamOrigin; // [esp+24h] [ebp-10h]
  float movieCamOrigin_8; // [esp+2Ch] [ebp-8h]

  if ( demo.playbackInited
    && !demo.shutdownInProgress
    && demo.playback->completed
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
          6332,
          0,
          "(!Demo_IsCompleted())",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  CL_GetLocalClientGlobals(localClientNum);
  if ( !CL_GetLocalClientConnection(localClientNum)->areTexturesLoaded
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
          6335,
          0,
          "(CL_GetLocalClientConnection( localClientNum )->areTexturesLoaded)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( demo.lastProcessedMsgNum == -1 )
    GlassCl_WaitUpdate();
  if ( Demo_IsPlaying() && demo.header.isDemoClip )
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
    playback = demo.playback;
    if ( (clientUIActives[localClientNum].flags & 0x20) != 0 )
    {
      clipCameraMode = demo.playback->clipCameraMode;
      if ( clipCameraMode != demo.playback->cameraMode )
      {
        movieCamOrigin = *(_QWORD *)&demo.playback->clipCameraOrigin.x;
        movieCamOrigin_8 = demo.playback->clipCameraOrigin.z;
        movieCamAngles = *(_QWORD *)&demo.playback->clipCameraAngles.x;
        movieCamAngles_8 = demo.playback->clipCameraAngles.z;
        Demo_SwitchCameraMode(a1, localClientNum, clipCameraMode);
        playback = demo.playback;
        if ( demo.playback->clipCameraMode != demo.playback->cameraMode )
        {
          if ( !Assert_MyHandler(
                  "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
                  6350,
                  0,
                  "(demo.playback->clipCameraMode == demo.playback->cameraMode)",
                  (const char *)&pBlock) )
            __debugbreak();
          playback = demo.playback;
        }
        if ( playback->cameraMode == DEMO_CAMERA_MODE_FREECAM )
        {
          *(_QWORD *)&playback->prevClipCameraOrigin.x = movieCamOrigin;
          playback->prevClipCameraOrigin.z = movieCamOrigin_8;
          v4 = demo.playback;
          *(_QWORD *)&demo.playback->prevClipCameraAngles.x = movieCamAngles;
          v4->prevClipCameraAngles.z = movieCamAngles_8;
          playback = demo.playback;
        }
      }
    }
    if ( demo.playbackInited )
      clipTime = playback->clipTime;
    else
      clipTime = 0;
    if ( Demo_ShouldGenerateKeyFrameSnapshot(clipTime, localClientNum) )
    {
      Demo_GenerateKeyFrameSnapshot(localClientNum);
      if ( demo.playbackInited && demo.playback->keyframeGenerated )
        Demo_WriteKeyFrameInformation(localClientNum);
    }
  }
  if ( !Demo_IsPlaying() )
  {
LABEL_37:
    if ( demo.playbackInited )
    {
      clipState = demo.playback->clipState;
      if ( (clipState == DEMO_CLIP_RECORD_CONTINUOUS || clipState == DEMO_CLIP_RECORD_UNCOMPRESSED_SNAPHOT)
        && demo.playback->clipRecordBufIndex >= 983040 )
      {
        Demo_PauseClipRecord(localClientNum);
        if ( Demo_IsPlaying() && demo.playbackInited && demo.playback->creatingHighlightReel )
          Demo_CancelHighlightReelCreation();
        return 0;
      }
      if ( clipState == DEMO_CLIP_PREVIEW )
        goto LABEL_52;
    }
    goto LABEL_47;
  }
  if ( demo.playbackInited )
  {
    if ( demo.playback->clipState == DEMO_CLIP_PREVIEW && demo.playback->cancelPreview )
    {
      Demo_RestoreUIStateAfterPreview(localClientNum, a1);
      demo.playback->cancelPreview = 0;
      return 0;
    }
    goto LABEL_37;
  }
LABEL_47:
  if ( !Demo_HaveWeDownloadedNextFileSegmentData() )
  {
    demo.playback->waitingForDownloadData = 1;
    if ( Demo_IsPlaying() && demo.playbackInited )
    {
      demo.playback->informationScreenType = DEMO_INFORMATION_SCREEN_WAITING_FOR_DOWNLOAD;
      demo.playback->informationScreenActivateTime = Sys_Milliseconds();
      demo.playback->informationScreenActive = 1;
    }
    return 0;
  }
LABEL_52:
  Bits = MSG_ReadBits(&demo.msg, 2);
  if ( demo.msg.overflowed
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
          6399,
          0,
          "(!demo.msg.overflowed)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !Bits )
  {
    if ( demo.playbackInited )
    {
      v9 = demo.playback;
      if ( demo.playback->clipState == DEMO_CLIP_PREVIEW )
      {
        if ( demo.playback->pendingSegmentSave )
        {
          if ( demo.playback->clipPreviewSegmentNumber != -1 )
          {
            if ( !Assert_MyHandler(
                    "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
                    6408,
                    0,
                    "(demo.playback->clipPreviewSegmentNumber == -1)",
                    (const char *)&pBlock) )
              __debugbreak();
            v9 = demo.playback;
          }
          if ( v9->clipRecordBufIndex == v9->clipPreviewBufferIndex )
            goto LABEL_64;
        }
        else if ( demo.playback->previewAllSegments )
        {
          if ( demo.playback->clipPreviewBufferIndex == demo.playback->segments[demo.playback->clipPreviewSegmentNumber].clipBufferIndex
                                                      + demo.playback->segments[demo.playback->clipPreviewSegmentNumber].size )
          {
            v10 = ++demo.playback->clipPreviewSegmentNumber;
            if ( v10 == demo.playback->segmentCount )
            {
LABEL_64:
              Demo_RestoreUIStateAfterPreview(localClientNum, a1);
              return 0;
            }
            Demo_ActivateTransitionScreen(
              localClientNum,
              *(_DWORD *)&demo.playback->subClipRecordingBuf[66048 * v10 + 11648]);
            Demo_PreviewSegment(a1, localClientNum, demo.playback->clipPreviewSegmentNumber);
            goto LABEL_80;
          }
        }
        else
        {
          if ( demo.playback->clipPreviewSegmentNumber == -1 )
          {
            if ( !Assert_MyHandler(
                    "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
                    6442,
                    0,
                    "(demo.playback->clipPreviewSegmentNumber != -1)",
                    (const char *)&pBlock) )
              __debugbreak();
            v9 = demo.playback;
          }
          if ( v9->clipPreviewBufferIndex == v9->segments[v9->clipPreviewSegmentNumber].clipBufferIndex
                                           + v9->segments[v9->clipPreviewSegmentNumber].size )
            goto LABEL_64;
        }
      }
      else if ( !demo.shutdownInProgress
             && demo.playback->waitingForDownloadData
             && !Assert_MyHandler(
                   "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
                   6458,
                   0,
                   "(!Demo_IsWaitingForDownloadData())",
                   (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    Demo_Load();
LABEL_80:
    Bits = MSG_ReadBits(&demo.msg, 2);
  }
  if ( Bits == 1 )
  {
    if ( demo.playbackInited )
    {
      v11 = demo.playback->clipState;
      if ( v11 == DEMO_CLIP_RECORD_CONTINUOUS || v11 == DEMO_CLIP_RECORD_UNCOMPRESSED_SNAPHOT )
        Demo_PauseClipRecord(localClientNum);
    }
    if ( Demo_IsPlaying() && (demo.playbackMode & 1) != 0 && demo.renderingAudioPass )
      Cbuf_AddText(localClientNum, "demo_jumptostart\n");
    demo.playback->completed = 1;
    Com_SetTimeScale(1.0);
    return 0;
  }
  if ( Bits == 2 )
  {
    while ( Demo_ParseClipCommand(a1, localClientNum, &demo.msg, 1) != DEMO_CLIP_CMD_END_OF_FRAME )
    {
      Bits = MSG_ReadBits(&demo.msg, 2);
      if ( Bits != 2 )
        goto LABEL_95;
    }
    return 0;
  }
LABEL_95:
  Long = MSG_ReadLong(&demo.msg);
  if ( demo.playbackInited && demo.playback->clipState == DEMO_CLIP_RECORD_CONTINUOUS )
  {
    Demo_WriteClipCommands(localClientNum, &demo.playback->clipRecordingMsg, 1);
    MSG_WriteBits(&demo.playback->clipRecordingMsg, Bits, 2);
    MSG_WriteLong(&demo.playback->clipRecordingMsg, Long);
  }
  Demo_ParseServerMessage(localClientNum, &demo.msg, Bits, Long);
  demo.lastProcessedMsgNum = Long;
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlobbyservice.cpp:0x92D750
bool __cdecl Demo_GetAnalyzePrintDataType(int fieldBit)
{
  bool result; // al

  switch ( fieldBit )
  {
    case -107:
    case -106:
    case -105:
    case -104:
    case -103:
    case -102:
    case -101:
    case -100:
    case -99:
    case -92:
    case -91:
    case -90:
    case -89:
    case -88:
    case -87:
    case -86:
    case -81:
    case -80:
    case -77:
    case -76:
    case -75:
    case -74:
    case -73:
    case -72:
    case -66:
    case -65:
    case -64:
    case -63:
    case -62:
    case -61:
    case 0:
      result = 0;
      break;
    default:
      result = 1;
      break;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
