// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdbitbuffer.cpp:0x927F20
void __cdecl Demo_ActivateTransitionScreen(LocalClientNum_t localClientNum, int transition)
{
  if ( transition && Demo_IsPlaying() && demo.playbackInited )
  {
    demo.playback->informationScreenType = DEMO_INFORMATION_SCREEN_TRANSITION;
    demo.playback->informationScreenActivateTime = Sys_Milliseconds();
    demo.playback->informationScreenActive = 1;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbitbuffer.cpp:0x927F70
void __cdecl Demo_UpdateInformationScreen(LocalClientNum_t localClientNum)
{
  int v1; // esi
  signed int v2; // eax

  if ( !demo.playbackInited
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
          2011,
          0,
          "(Demo_IsPlaybackInited())",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( Demo_IsPlaying()
    && demo.playbackInited
    && demo.playback->informationScreenActive
    && demo.playback->informationScreenType )
  {
    if ( Demo_IsPlaying() && (demo.playbackMode & 1) != 0 && demo.renderingFirstJumpBackDone && !demo.renderingAudioPass )
      v1 = 3 * (Com_SessionMode_IsZombiesGame() ? 0xFFFFF448 : 0) + 15000;
    else
      v1 = Com_SessionMode_IsZombiesGame() ? 2000 : 5000;
    v2 = Sys_Milliseconds() - demo.playback->informationScreenActivateTime;
    switch ( demo.playback->informationScreenType )
    {
      case DEMO_INFORMATION_SCREEN_FILM_START_SCREEN_FADE_IN:
        if ( v2 >= v1 )
        {
          Demo_ActivateInformationScreen(localClientNum, DEMO_INFORMATION_SCREEN_FILM_START_SCREEN_FADE_OUT);
          Com_SetTimeScale(1.0);
          Demo_SetDefaultClient(localClientNum, INVALID_CLIENT_INDEX);
        }
        break;
      case DEMO_INFORMATION_SCREEN_FILM_START_SCREEN_FADE_OUT:
      case DEMO_INFORMATION_SCREEN_TRANSITION:
        if ( v2 >= 2000 )
          demo.playback->informationScreenActive = 0;
        break;
      case DEMO_INFORMATION_SCREEN_WAITING_FOR_DOWNLOAD:
        if ( !Demo_IsWaitingForDownloadData() )
        {
          Demo_ActivateInformationScreen(localClientNum, DEMO_INFORMATION_SCREEN_WAITING_FOR_DOWNLOAD);
          demo.playback->informationScreenActive = 0;
        }
        break;
      default:
        return;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbitbuffer.cpp:0x928140
bool __cdecl Demo_IsDemoHudHidden()
{
  if ( !demo.playbackInited )
    return 0;
  if ( Demo_IsPlaying() && (demo.playbackMode & 1) != 0 )
    return 1;
  return demo.playback->hideDemoHud;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbitbuffer.cpp:0x928180
void __cdecl Demo_UpdateClipTime(int msec)
{
  demoClipState clipState; // eax

  if ( demo.playbackInited )
  {
    clipState = demo.playback->clipState;
    if ( clipState == DEMO_CLIP_RECORD_CONTINUOUS
      || clipState == DEMO_CLIP_RECORD_UNCOMPRESSED_SNAPHOT
      || Demo_IsPlaying() && demo.header.isDemoClip )
    {
      if ( !Demo_IsPlaying() || !demo.header.isDemoClip )
        goto LABEL_13;
      if ( Demo_IsPaused() )
        return;
      if ( demo.playbackInited && !demo.shutdownInProgress )
      {
        if ( !demo.playback->completed )
          demo.playback->clipTime += msec;
      }
      else
      {
LABEL_13:
        demo.playback->clipTime += msec;
      }
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbitbuffer.cpp:0x928210
void __cdecl Demo_StoreConfigString(int index, const char *s)
{
  char *v2; // ebx
  unsigned int v3; // esi

  v2 = Demo_AdjustTimeForConfigString(index, s);
  v3 = strlen(v2);
  if ( (int)(cls.gameState.dataCount + v3 + 1) > 0x10000 )
    Com_Error(ERR_DROP, &byte_BD178C);
  cls.gameState.stringOffsets[index] = cls.gameState.dataCount;
  memcpy((unsigned __int8 *)&cls.gameState.stringData[cls.gameState.dataCount], (unsigned __int8 *)v2, v3 + 1);
  cls.gameState.dataCount += v3 + 1;
  cls.gameState.stringChecksums[index] = com_frameNumber;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbitbuffer.cpp:0x928320
void __usercall Demo_InitClipRecord(LocalClientNum_t localClientNum@<eax>, bool newClip)
{
  MSG_Init(&demo.playback->clipRecordingMsg, demo.playback->subClipRecordingBuf, 0x10000);
  if ( newClip )
  {
    Demo_WriteHeader(&demo.playback->clipRecordingMsg, 1);
    MSG_WriteBits(&demo.playback->clipRecordingMsg, 3, 2);
    MSG_WriteLong(&demo.playback->clipRecordingMsg, 0);
    Demo_WriteClipGameState(localClientNum);
    MSG_WriteBits(&demo.playback->clipRecordingMsg, 0, 2);
    Demo_SaveClipRecordMessageToMainMemory(
      localClientNum,
      demo.playback->clipRecordingMsg.data,
      demo.playback->clipRecordingMsg.cursize,
      0);
    demo.playback->segmentGameStateSize = demo.playback->clipRecordBufIndex;
    Demo_PopulateDefaultMetaInformation(
      &demo.playback->clipRecordInfo,
      demo.footer.info.mapName,
      demo.footer.info.zmGameModeGroup,
      demo.footer.info.gameType,
      demo.footer.info.zmMapStartLoc);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbitbuffer.cpp:0x928410
void __cdecl Demo_WriteClipCommandsInternal(LocalClientNum_t localClientNum, msg_t *msg, bool setClipRecordParams)
{
  cg_t *v3; // edi
  int Int; // ebx
  demoClipState clipState; // eax
  float f; // xmm0_4
  bool v7; // bl
  demoPlayback *playback; // eax
  demoCameraMode clipCameraMode; // ebx
  demoPlayback *v10; // ecx
  demoPlayback *v11; // ecx
  demoPlayback *v12; // ecx
  float x; // xmm0_4
  float *p_x; // edi
  demoPlayback *v15; // eax
  demoPlayback *v16; // ecx
  demoPlayback *v17; // eax
  int highlightReelPriority; // edi
  bool Bool; // bl
  clientActive_t *LocalClientGlobals; // [esp+24h] [ebp-10h]
  cg_t *cgameGlob; // [esp+28h] [ebp-Ch]
  float fov; // [esp+2Ch] [ebp-8h]
  bool forceWrite; // [esp+33h] [ebp-1h]

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
    v3 = cgArray;
  }
  else
  {
    v3 = 0;
  }
  cgameGlob = v3;
  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
  forceWrite = demo.playback->forceWriteClipCommands;
  Int = Dvar_GetInt(demo_client);
  if ( demo.playback->clipRecordClient != Int || forceWrite )
  {
    MSG_WriteBits(msg, 2, 2);
    MSG_WriteByte(msg, 0);
    MSG_WriteByte(msg, Int);
    if ( demo.playbackInited
      && ((clipState = demo.playback->clipState, clipState == DEMO_CLIP_RECORD_CONTINUOUS)
       || clipState == DEMO_CLIP_RECORD_UNCOMPRESSED_SNAPHOT)
      && Demo_IsPaused() )
    {
      MSG_WriteBit1(msg);
      svs.mapCenter = cls.mapCenter;
      SV_SetServerStaticHeader();
      MSG_WriteDeltaPlayerstate(&demo_defaultSnapInfo, msg, 0, &demo.playback->clipRecordPS, &demo.snapshot.ps[Int]);
      SV_GetServerStaticHeader();
    }
    else
    {
      MSG_WriteBit0(msg);
    }
    if ( setClipRecordParams )
      demo.playback->clipRecordClient = Int;
    Demo_Printf(1024, "DEMO: w Clip Cmd: DEMO_CLIP_CMD_SET_CLIENT client: %d\n", Int);
  }
  if ( demo.playbackInited )
    f = demo.playback->timeScale;
  else
    f = *(float *)&FLOAT_1_0;
  if ( demo.playback->clipRecordTimescale == f && !forceWrite )
  {
    v7 = setClipRecordParams;
  }
  else
  {
    MSG_WriteBits(msg, 2, 2);
    MSG_WriteByte(msg, 1);
    MSG_WriteRangedFloatBits(msg, f, 0.0, 4.0, 16);
    v7 = setClipRecordParams;
    if ( setClipRecordParams )
      demo.playback->clipRecordTimescale = f;
    Demo_Printf(1024, "DEMO: w Clip Cmd: DEMO_CLIP_CMD_SET_TIMESCALE Value: %f\n", f);
  }
  fov = demo.playback->fov;
  if ( demo.playback->clipRecordFov != fov || forceWrite )
  {
    MSG_WriteBits(msg, 2, 2);
    MSG_WriteByte(msg, 2);
    MSG_WriteFloat(msg, fov);
    if ( v7 )
      demo.playback->clipRecordFov = fov;
    Demo_Printf(1024, "DEMO: w Clip Cmd: DEMO_CLIP_CMD_SET_FOV Value: %f\n", fov);
  }
  if ( demo.playback->clipCameraMode != demo.playback->cameraMode || forceWrite )
  {
    MSG_WriteBits(msg, 2, 2);
    MSG_WriteByte(msg, 3);
    MSG_WriteByte(msg, demo.playback->cameraMode);
    if ( !v7 )
    {
      Demo_Printf(1024, "DEMO: w Clip Cmd: DEMO_CLIP_CMD_SET_CAMERA_MODE Mode: %d\n", demo.playback->cameraMode);
      goto LABEL_42;
    }
    demo.playback->clipCameraMode = demo.playback->cameraMode;
    if ( demo.playback->clipCameraMode != demo.playback->cameraMode
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
            4919,
            0,
            "(demo.playback->clipCameraMode == demo.playback->cameraMode)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    Demo_Printf(1024, "DEMO: w Clip Cmd: DEMO_CLIP_CMD_SET_CAMERA_MODE Mode: %d\n", demo.playback->cameraMode);
  }
  if ( v7 )
  {
    playback = demo.playback;
    clipCameraMode = demo.playback->clipCameraMode;
    goto LABEL_43;
  }
LABEL_42:
  playback = demo.playback;
  clipCameraMode = demo.playback->cameraMode;
LABEL_43:
  if ( clipCameraMode || forceWrite )
  {
    if ( playback->freeCameraOffsetEntity != 1023 )
    {
      MSG_WriteBits(msg, 2, 2);
      MSG_WriteByte(msg, 6);
      if ( demo.playback->freeCameraOffsetOrigin.x == demo.playback->clipCameraOffsetOrigin.x
        && demo.playback->freeCameraOffsetOrigin.y == demo.playback->clipCameraOffsetOrigin.y
        && demo.playback->freeCameraOffsetOrigin.z == demo.playback->clipCameraOffsetOrigin.z
        && demo.playback->freeCameraOffsetAngles.x == demo.playback->clipCameraOffsetAngles.x
        && demo.playback->freeCameraOffsetAngles.y == demo.playback->clipCameraOffsetAngles.y
        && demo.playback->freeCameraOffsetAngles.z == demo.playback->clipCameraOffsetAngles.z
        && !forceWrite )
      {
        MSG_WriteBit0(msg);
      }
      else
      {
        MSG_WriteBit1(msg);
        MSG_WriteData(msg, &demo.playback->freeCameraOffsetOrigin, 12);
        MSG_WriteData(msg, &demo.playback->freeCameraOffsetAngles, 12);
        if ( setClipRecordParams )
        {
          v10 = demo.playback;
          demo.playback->clipCameraOffsetOrigin.x = demo.playback->freeCameraOffsetOrigin.x;
          v10->clipCameraOffsetOrigin.y = v10->freeCameraOffsetOrigin.y;
          v10->clipCameraOffsetOrigin.z = v10->freeCameraOffsetOrigin.z;
          v11 = demo.playback;
          demo.playback->clipCameraOffsetAngles.x = demo.playback->freeCameraOffsetAngles.x;
          v11->clipCameraOffsetAngles.y = v11->freeCameraOffsetAngles.y;
          v11->clipCameraOffsetAngles.z = v11->freeCameraOffsetAngles.z;
        }
      }
    }
    MSG_WriteBits(msg, 2, 2);
    MSG_WriteByte(msg, 4);
    if ( clipCameraMode >= DEMO_CAMERA_MODE_NONE )
    {
      if ( clipCameraMode <= DEMO_CAMERA_MODE_THIRDPERSON )
      {
        x = v3->refdef.vieworg.x;
        p_x = &v3->refdef.vieworg.x;
        if ( x == demo.playback->clipCameraOrigin.x
          && cgameGlob->refdef.vieworg.y == demo.playback->clipCameraOrigin.y
          && cgameGlob->refdef.vieworg.z == demo.playback->clipCameraOrigin.z
          && !forceWrite )
        {
          MSG_WriteBit0(msg);
          v3 = cgameGlob;
        }
        else
        {
          MSG_WriteBit1(msg);
          MSG_WriteData(msg, p_x, 12);
          if ( setClipRecordParams )
          {
            v15 = demo.playback;
            demo.playback->clipCameraOrigin.x = *p_x;
            v15->clipCameraOrigin.y = p_x[1];
            v15->clipCameraOrigin.z = p_x[2];
          }
          Demo_Printf(
            1024,
            "DEMO: w Clip Cmd: DEMO_CLIP_CMD_SET_CAMERA_ORIGIN Value: %d (%f, %f, %f)\n",
            demo.playback->cameraMode,
            demo.playback->clipCameraOrigin.x,
            demo.playback->clipCameraOrigin.y,
            demo.playback->clipCameraOrigin.z);
          v3 = cgameGlob;
        }
      }
      else if ( clipCameraMode == DEMO_CAMERA_MODE_FREECAM )
      {
        if ( demo.playback->freeCameraOrigin.x == demo.playback->clipCameraOrigin.x
          && demo.playback->freeCameraOrigin.y == demo.playback->clipCameraOrigin.y
          && demo.playback->freeCameraOrigin.z == demo.playback->clipCameraOrigin.z
          && !forceWrite )
        {
          MSG_WriteBit0(msg);
        }
        else
        {
          MSG_WriteBit1(msg);
          MSG_WriteData(msg, &demo.playback->freeCameraOrigin, 12);
          if ( setClipRecordParams )
          {
            v12 = demo.playback;
            demo.playback->clipCameraOrigin.x = demo.playback->freeCameraOrigin.x;
            v12->clipCameraOrigin.y = v12->freeCameraOrigin.y;
            v12->clipCameraOrigin.z = v12->freeCameraOrigin.z;
            Demo_Printf(
              1024,
              "DEMO: w Clip Cmd: DEMO_CLIP_CMD_SET_CAMERA_ORIGIN Value: %d (%f, %f, %f)\n",
              demo.playback->cameraMode,
              demo.playback->clipCameraOrigin.x,
              demo.playback->clipCameraOrigin.y,
              demo.playback->clipCameraOrigin.z);
          }
          else
          {
            Demo_Printf(
              1024,
              "DEMO: w Clip Cmd: DEMO_CLIP_CMD_SET_CAMERA_ORIGIN Value: %d (%f, %f, %f)\n",
              demo.playback->clipCameraMode,
              demo.playback->clipCameraOrigin.x,
              demo.playback->clipCameraOrigin.y,
              demo.playback->clipCameraOrigin.z);
          }
        }
      }
    }
    MSG_WriteBits(msg, 2, 2);
    MSG_WriteByte(msg, 5);
    if ( clipCameraMode >= DEMO_CAMERA_MODE_NONE )
    {
      if ( clipCameraMode <= DEMO_CAMERA_MODE_THIRDPERSON )
      {
        if ( v3->refdefViewAngles.x == demo.playback->clipCameraAngles.x
          && v3->refdefViewAngles.y == demo.playback->clipCameraAngles.y
          && v3->refdefViewAngles.z == demo.playback->clipCameraAngles.z
          && !forceWrite )
        {
          goto LABEL_82;
        }
        MSG_WriteBit1(msg);
        if ( !setClipRecordParams )
        {
          MSG_WriteData(msg, &LocalClientGlobals->viewangles, 12);
          Demo_Printf(
            1024,
            "DEMO: w Clip Cmd: DEMO_CLIP_CMD_SET_CAMERA_ANGLES Value: %d (%f, %f, %f)\n",
            demo.playback->clipCameraMode,
            demo.playback->clipCameraAngles.x,
            demo.playback->clipCameraAngles.y,
            demo.playback->clipCameraAngles.z);
          goto LABEL_94;
        }
        MSG_WriteData(msg, &LocalClientGlobals->viewangles, 12);
        v17 = demo.playback;
        demo.playback->clipCameraAngles.x = LocalClientGlobals->viewangles.x;
        v17->clipCameraAngles.y = LocalClientGlobals->viewangles.y;
        v17->clipCameraAngles.z = LocalClientGlobals->viewangles.z;
        goto LABEL_85;
      }
      if ( clipCameraMode == DEMO_CAMERA_MODE_FREECAM )
      {
        if ( demo.playback->freeCameraAngles.x == demo.playback->clipCameraAngles.x
          && demo.playback->freeCameraAngles.y == demo.playback->clipCameraAngles.y
          && demo.playback->freeCameraAngles.z == demo.playback->clipCameraAngles.z
          && !forceWrite )
        {
LABEL_82:
          MSG_WriteBit0(msg);
          goto LABEL_94;
        }
        MSG_WriteBit1(msg);
        if ( !setClipRecordParams )
        {
          MSG_WriteData(msg, &demo.playback->freeCameraAngles, 12);
          Demo_Printf(
            1024,
            "DEMO: w Clip Cmd: DEMO_CLIP_CMD_SET_CAMERA_ANGLES Value: %d (%f, %f, %f)\n",
            demo.playback->clipCameraMode,
            demo.playback->clipCameraAngles.x,
            demo.playback->clipCameraAngles.y,
            demo.playback->clipCameraAngles.z);
          goto LABEL_94;
        }
        MSG_WriteData(msg, &demo.playback->freeCameraAngles, 12);
        v16 = demo.playback;
        demo.playback->clipCameraAngles.x = demo.playback->freeCameraAngles.x;
        v16->clipCameraAngles.y = v16->freeCameraAngles.y;
        v16->clipCameraAngles.z = v16->freeCameraAngles.z;
LABEL_85:
        Demo_Printf(
          1024,
          "DEMO: w Clip Cmd: DEMO_CLIP_CMD_SET_CAMERA_ANGLES Value: %d (%f, %f, %f)\n",
          demo.playback->cameraMode,
          demo.playback->clipCameraAngles.x,
          demo.playback->clipCameraAngles.y,
          demo.playback->clipCameraAngles.z);
      }
    }
  }
LABEL_94:
  if ( demo.playback->clipHudHidden != demo.playback->hideGameHud || forceWrite )
  {
    MSG_WriteBits(msg, 2, 2);
    MSG_WriteByte(msg, 8);
    if ( setClipRecordParams )
    {
      if ( demo.playback->hideGameHud )
        MSG_WriteBit1(msg);
      else
        MSG_WriteBit0(msg);
      demo.playback->clipHudHidden = demo.playback->hideGameHud;
    }
    else if ( demo.playback->hideGameHud )
    {
      MSG_WriteBit1(msg);
    }
    else
    {
      MSG_WriteBit0(msg);
    }
    Demo_Printf(1024, "DEMO: w Clip Cmd: DEMO_CLIP_CMD_HIDE_GAME_HUD value: %d\n", demo.playback->hideGameHud);
  }
  if ( demo.playbackInited )
    highlightReelPriority = demo.playback->highlightReelPriority;
  else
    highlightReelPriority = -1;
  if ( demo.playback->clipRecordHighlightReelPriority != highlightReelPriority || forceWrite )
  {
    MSG_WriteBits(msg, 2, 2);
    MSG_WriteByte(msg, 13);
    MSG_WriteLong(msg, highlightReelPriority);
    if ( setClipRecordParams )
      demo.playback->clipRecordHighlightReelPriority = highlightReelPriority;
    Demo_Printf(1024, "DEMO: w Clip Cmd: DEMO_CLIP_CMD_SET_HIGHLIGHT_REEL_PRIORITY Value: %d\n", highlightReelPriority);
    if ( forceWrite )
    {
      MSG_WriteBits(msg, 2, 2);
      MSG_WriteByte(msg, 9);
      MSG_WriteLong(msg, LocalClientGlobals->snap.messageNum);
      Demo_Printf(1024, "DEMO: w Clip Cmd: DEMO_CLIP_CMD_RESET_SNAPSHOT_DATA\n");
    }
  }
  if ( clipCameraMode || forceWrite )
  {
    MSG_WriteBits(msg, 2, 2);
    MSG_WriteByte(msg, 7);
    if ( clipCameraMode == DEMO_CAMERA_MODE_FREECAM )
      MSG_WriteBits(msg, demo.playback->freeCameraOffsetEntity, 10);
    else
      MSG_WriteBits(msg, 1023, 10);
  }
  Bool = Dvar_GetBool(demo_pause);
  if ( demo.playback->clipPausedState == Bool && !forceWrite )
  {
    demo.playback->forceWriteClipCommands = 0;
  }
  else
  {
    MSG_WriteBits(msg, 2, 2);
    MSG_WriteByte(msg, 10);
    if ( setClipRecordParams )
    {
      if ( Bool )
      {
        MSG_WriteBit1(msg);
        demo.playback->clipPausedState = Bool;
      }
      else
      {
        MSG_WriteBit0(msg);
        demo.playback->clipPausedState = 0;
      }
    }
    else if ( demo.playback->clipPausedState )
    {
      MSG_WriteBit1(msg);
    }
    else
    {
      MSG_WriteBit0(msg);
    }
    Demo_Printf(1024, "DEMO: w Clip Cmd: DEMO_CLIP_CMD_SET_PAUSED_STATE value: %d\n", demo.playback->clipPausedState);
    demo.playback->forceWriteClipCommands = 0;
  }
}

#endif // __UNIMPLEMENTED__
