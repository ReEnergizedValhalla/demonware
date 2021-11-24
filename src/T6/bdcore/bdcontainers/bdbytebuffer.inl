// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdbytebuffer.inl:0x92A9B0
demoClipCommand __usercall Demo_ParseClipCommand@<eax>(
        double a1@<st0>,
        LocalClientNum_t localClientNum,
        msg_t *msg,
        bool setClipPlaybackParams)
{
  int Int; // edi
  unsigned __int8 *v5; // edi
  demoClipCommand result; // eax
  double TimeScale; // st7
  int Bit; // eax
  demoPlayback *v9; // ecx
  demoPlayback *v10; // ecx
  demoPlayback *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  demoPlayback *v14; // ecx
  demoPlayback *playback; // ecx
  float *p_x; // edi
  demoPlayback *v17; // eax
  demoPlayback *v18; // ecx
  demoPlayback *v19; // ecx
  float *v20; // edi
  demoPlayback *v21; // eax
  demoPlayback *v22; // ecx
  int v23; // esi
  int Byte; // eax
  const char *v25; // eax
  double v26; // [esp+10h] [ebp-44h]
  double v27; // [esp+18h] [ebp-3Ch]
  demoCameraMode cameraMode; // [esp+1Ch] [ebp-38h]
  double v29; // [esp+20h] [ebp-34h]
  double x; // [esp+20h] [ebp-34h]
  double z; // [esp+28h] [ebp-2Ch]
  double y; // [esp+28h] [ebp-2Ch]
  double end; // [esp+30h] [ebp-24h]
  double enda; // [esp+30h] [ebp-24h]
  int newClient; // [esp+44h] [ebp-10h]
  float newClienta; // [esp+44h] [ebp-10h]
  demoClipCommand cmdType; // [esp+48h] [ebp-Ch]
  clientActive_t *LocalClientGlobals; // [esp+4Ch] [ebp-8h]
  cg_t *cgameGlob; // [esp+50h] [ebp-4h]
  unsigned __int8 *cgameGloba; // [esp+50h] [ebp-4h]

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
  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
  cmdType = MSG_ReadByte(msg);
  Int = Dvar_GetInt(demo_client);
  switch ( cmdType )
  {
    case DEMO_CLIP_CMD_SET_CLIENT:
      newClient = MSG_ReadByte(msg);
      v5 = (unsigned __int8 *)&demo.snapshot.ps[Int];
      cgameGloba = (unsigned __int8 *)&demo.snapshot.ps[newClient];
      memcpy(cgameGloba, v5, 0x2A08u);
      memcpy(v5, (unsigned __int8 *)&demo_defaultPlayerState, 0x2A08u);
      if ( MSG_ReadBit(msg) )
      {
        Demo_EnableSnapshotProcessing();
        MSG_ReadDeltaPlayerstate(localClientNum, msg, 0, (const playerState_s *)cgameGloba, (playerState_s *)v5, 0);
        SV_GetServerStaticHeader();
        if ( Demo_IsClipPlaying() )
          Demo_AdjustTimeForPlayerState(
            LocalClientGlobals->snap.serverTime,
            demo.playback->clipServerTime,
            (playerState_s *)v5);
        Demo_UpdateCurrentSnapshot(localClientNum, (playerState_s *)v5);
        memcpy(v5, (unsigned __int8 *)&demo_defaultPlayerState, 0x2A08u);
      }
      Dvar_SetInt(demo_client, newClient);
      Demo_Printf(1024, "DEMO: r Clip Cmd: DEMO_CLIP_CMD_SET_CLIENT client: %d\n", newClient);
      result = cmdType;
      break;
    case DEMO_CLIP_CMD_SET_TIMESCALE:
      newClienta = MSG_ReadRangedFloatBits(msg, 0.0, 4.0, 16);
      Demo_SetTimeScale(newClienta);
      TimeScale = Com_GetTimeScale();
      Demo_Printf(1024, "DEMO: r Clip Cmd: DEMO_CLIP_CMD_SET_TIMESCALE Value: %f\n", TimeScale);
      result = cmdType;
      break;
    case DEMO_CLIP_CMD_SET_FOV:
      demo.playback->fov = MSG_ReadFloat(msg);
      Demo_Printf(1024, "DEMO: r Clip Cmd: DEMO_CLIP_CMD_SET_FOV Value: %f\n", demo.playback->fov);
      result = cmdType;
      break;
    case DEMO_CLIP_CMD_SET_CAMERA_MODE:
      demo.playback->clipCameraMode = MSG_ReadByte(msg);
      Demo_Printf(1024, "DEMO: r Clip Cmd: DEMO_CLIP_CMD_SET_CAMERA_MODE Mode: %d\n", demo.playback->cameraMode);
      if ( (unsigned __int8)CL_LocalClient_IsCGameInitialized(localClientNum) )
        Demo_SwitchCameraMode(a1, localClientNum, demo.playback->clipCameraMode);
      if ( (!Demo_IsPlaying() || !demo.header.isDemoClip) && !Demo_IsClipPreviewRunning() )
        goto LABEL_60;
      demo.playback->forceTeleportClipCamera = 1;
      result = cmdType;
      break;
    case DEMO_CLIP_CMD_SET_CAMERA_ORIGIN:
      if ( MSG_ReadBit(msg) )
      {
        if ( setClipPlaybackParams )
        {
          playback = demo.playback;
          demo.playback->prevClipCameraOrigin.x = demo.playback->clipCameraOrigin.x;
          playback->prevClipCameraOrigin.y = playback->clipCameraOrigin.y;
          playback->prevClipCameraOrigin.z = playback->clipCameraOrigin.z;
          MSG_ReadData(msg, &demo.playback->clipCameraOrigin, 12);
          enda = demo.playback->clipCameraOrigin.z;
          y = demo.playback->clipCameraOrigin.y;
          x = demo.playback->clipCameraOrigin.x;
          cameraMode = demo.playback->cameraMode;
        }
        else
        {
          p_x = &cgameGlob->refdef.vieworg.x;
          MSG_ReadData(msg, &cgameGlob->refdef.vieworg, 12);
          v17 = demo.playback;
          if ( demo.playback->clipCameraMode == DEMO_CAMERA_MODE_FREECAM )
          {
            demo.playback->freeCameraOrigin.x = *p_x;
            v17->freeCameraOrigin.y = cgameGlob->refdef.vieworg.y;
            v17->freeCameraOrigin.z = cgameGlob->refdef.vieworg.z;
            v17 = demo.playback;
          }
          enda = cgameGlob->refdef.vieworg.z;
          y = cgameGlob->refdef.vieworg.y;
          x = *p_x;
          cameraMode = v17->cameraMode;
        }
      }
      else
      {
        v18 = demo.playback;
        demo.playback->prevClipCameraOrigin.x = demo.playback->clipCameraOrigin.x;
        v18->prevClipCameraOrigin.y = v18->clipCameraOrigin.y;
        v18->prevClipCameraOrigin.z = v18->clipCameraOrigin.z;
        enda = demo.playback->clipCameraOrigin.z;
        y = demo.playback->clipCameraOrigin.y;
        x = demo.playback->clipCameraOrigin.x;
        cameraMode = demo.playback->cameraMode;
      }
      Demo_Printf(
        1024,
        "DEMO: r Clip Cmd: DEMO_CLIP_CMD_SET_CAMERA_ORIGIN Value: %d (%f, %f, %f)\n",
        cameraMode,
        x,
        y,
        enda);
      goto LABEL_37;
    case DEMO_CLIP_CMD_SET_CAMERA_ANGLES:
      if ( MSG_ReadBit(msg) )
      {
        if ( setClipPlaybackParams )
        {
          v19 = demo.playback;
          demo.playback->prevClipCameraAngles.x = demo.playback->clipCameraAngles.x;
          v19->prevClipCameraAngles.y = v19->clipCameraAngles.y;
          v19->prevClipCameraAngles.z = v19->clipCameraAngles.z;
          MSG_ReadData(msg, &demo.playback->clipCameraAngles, 12);
          Demo_Printf(
            1024,
            "DEMO: r Clip Cmd: DEMO_CLIP_CMD_SET_CAMERA_ANGLES Value: %d (%f, %f, %f)\n",
            demo.playback->cameraMode,
            demo.playback->clipCameraAngles.x,
            demo.playback->clipCameraAngles.y,
            demo.playback->clipCameraAngles.z);
        }
        else
        {
          v20 = &LocalClientGlobals->viewangles.x;
          MSG_ReadData(msg, &LocalClientGlobals->viewangles, 12);
          v21 = demo.playback;
          if ( demo.playback->clipCameraMode == DEMO_CAMERA_MODE_FREECAM )
          {
            demo.playback->freeCameraAngles.x = *v20;
            v21->freeCameraAngles.y = LocalClientGlobals->viewangles.y;
            v21->freeCameraAngles.z = LocalClientGlobals->viewangles.z;
            v21 = demo.playback;
          }
          Demo_Printf(
            1024,
            "DEMO: r Clip Cmd: DEMO_CLIP_CMD_SET_CAMERA_ANGLES Value: %d (%f, %f, %f)\n",
            v21->cameraMode,
            *v20,
            LocalClientGlobals->viewangles.y,
            LocalClientGlobals->viewangles.z);
        }
LABEL_37:
        result = cmdType;
      }
      else
      {
        v22 = demo.playback;
        demo.playback->prevClipCameraAngles.x = demo.playback->clipCameraAngles.x;
        v22->prevClipCameraAngles.y = v22->clipCameraAngles.y;
        v22->prevClipCameraAngles.z = v22->clipCameraAngles.z;
        Demo_Printf(
          1024,
          "DEMO: r Clip Cmd: DEMO_CLIP_CMD_SET_CAMERA_ANGLES Value: %d (%f, %f, %f)\n",
          demo.playback->cameraMode,
          demo.playback->clipCameraAngles.x,
          demo.playback->clipCameraAngles.y,
          demo.playback->clipCameraAngles.z);
        result = cmdType;
      }
      break;
    case DEMO_CLIP_CMD_SET_CAMERA_TRANSFORM:
      Bit = MSG_ReadBit(msg);
      v9 = demo.playback;
      if ( Bit )
      {
        if ( setClipPlaybackParams )
        {
          demo.playback->prevClipCameraOffsetOrigin.x = demo.playback->clipCameraOffsetOrigin.x;
          v9->prevClipCameraOffsetOrigin.y = v9->clipCameraOffsetOrigin.y;
          v9->prevClipCameraOffsetOrigin.z = v9->clipCameraOffsetOrigin.z;
          v10 = demo.playback;
          demo.playback->prevClipCameraOffsetAngles.x = demo.playback->clipCameraOffsetAngles.x;
          v10->prevClipCameraOffsetAngles.y = v10->clipCameraOffsetAngles.y;
          v10->prevClipCameraOffsetAngles.z = v10->clipCameraOffsetAngles.z;
          MSG_ReadData(msg, &demo.playback->clipCameraOffsetOrigin, 12);
          MSG_ReadData(msg, &demo.playback->clipCameraOffsetAngles, 12);
          v11 = demo.playback;
          v12 = demo.playback->clipCameraOffsetOrigin.x;
          end = v12;
          z = demo.playback->clipCameraOffsetAngles.z;
          v29 = demo.playback->clipCameraOffsetAngles.y;
          v27 = demo.playback->clipCameraOffsetAngles.x;
          v26 = demo.playback->clipCameraOffsetOrigin.z;
          v13 = demo.playback->clipCameraOffsetOrigin.y;
        }
        else
        {
          MSG_ReadData(msg, &demo.playback->freeCameraOffsetOrigin, 12);
          MSG_ReadData(msg, &demo.playback->freeCameraOffsetAngles, 12);
          v11 = demo.playback;
          v12 = demo.playback->freeCameraOffsetOrigin.x;
          end = v12;
          z = demo.playback->freeCameraOffsetAngles.z;
          v29 = demo.playback->freeCameraOffsetAngles.y;
          v27 = demo.playback->freeCameraOffsetAngles.x;
          v26 = demo.playback->freeCameraOffsetOrigin.z;
          v13 = demo.playback->freeCameraOffsetOrigin.y;
        }
        Demo_Printf(
          1024,
          "DEMO: r Clip Cmd: DEMO_CLIP_CMD_SET_CAMERA_TRANSFORM Value: %d (%f, %f, %f) (%f, %f, %f, %f)\n",
          v11->cameraMode,
          v12,
          v13,
          v26,
          v27,
          v29,
          z,
          end);
      }
      else
      {
        demo.playback->prevClipCameraOffsetOrigin.x = demo.playback->clipCameraOffsetOrigin.x;
        v9->prevClipCameraOffsetOrigin.y = v9->clipCameraOffsetOrigin.y;
        v9->prevClipCameraOffsetOrigin.z = v9->clipCameraOffsetOrigin.z;
        v14 = demo.playback;
        demo.playback->prevClipCameraOffsetAngles.x = demo.playback->clipCameraOffsetAngles.x;
        v14->prevClipCameraOffsetAngles.y = v14->clipCameraOffsetAngles.y;
        v14->prevClipCameraOffsetAngles.z = v14->clipCameraOffsetAngles.z;
        Demo_Printf(
          1024,
          "DEMO: r Clip Cmd: DEMO_CLIP_CMD_SET_CAMERA_TRANSFORM Value: %d (%f, %f, %f) (%f, %f, %f, %f)\n",
          demo.playback->cameraMode,
          demo.playback->clipCameraOffsetOrigin.x,
          demo.playback->clipCameraOffsetOrigin.y,
          demo.playback->clipCameraOffsetOrigin.z,
          demo.playback->clipCameraOffsetAngles.x,
          demo.playback->clipCameraOffsetAngles.y,
          demo.playback->clipCameraOffsetAngles.z,
          demo.playback->clipCameraOffsetOrigin.x);
      }
      result = cmdType;
      break;
    case DEMO_CLIP_CMD_SET_CAMERA_OFFSET_ENTITY:
      demo.playback->clipCameraOffsetEntity = MSG_ReadBits(msg, 10);
      Demo_Printf(
        1024,
        "DEMO: r Clip Cmd: DEMO_CLIP_CMD_SET_CAMERA_OFFSET_ENTITY Mode: %d\n",
        demo.playback->clipCameraOffsetEntity);
      result = cmdType;
      break;
    case DEMO_CLIP_CMD_HIDE_GAME_HUD:
      demo.playback->hideGameHud = MSG_ReadBit(msg) != 0;
      Demo_Printf(1024, "DEMO: r Clip Cmd: DEMO_CLIP_CMD_HIDE_GAME_HUD value: %d\n", demo.playback->hideGameHud);
      result = cmdType;
      break;
    case DEMO_CLIP_CMD_RESET_SNAPSHOT_DATA:
      v23 = MSG_ReadLong(msg) - 1;
      Demo_ResetSnapshotData();
      Demo_ResetSequenceNumbers(localClientNum, v23);
      Demo_ResetWorldInformation(a1, localClientNum, 0);
      if ( demo.playbackInited )
        demo.playback->jumpTimeFlag = 1;
      if ( Demo_IsPlaying() && demo.header.isDemoClip )
      {
        demo.playback->clipCameraOffsetEntity = 1023;
        demo.playback->forceTeleportClipCamera = 1;
      }
      else if ( Demo_IsClipPreviewRunning() )
      {
        demo.playback->forceResetTimeValues = 1;
        demo.playback->forceTeleportClipCamera = 1;
        demo.playback->clipCameraOffsetEntity = 1023;
      }
      Demo_Printf(1024, "DEMO: r Clip Cmd: DEMO_CLIP_CMD_RESET_SNAPSHOT_DATA\n");
      result = cmdType;
      break;
    case DEMO_CLIP_CMD_SET_PAUSED_STATE:
      demo.playback->clipPausedState = MSG_ReadBit(msg) != 0;
      Demo_Printf(1024, "DEMO: r Clip Cmd: DEMO_CLIP_CMD_SET_PAUSED_STATE value: %d\n", demo.playback->clipPausedState);
      result = cmdType;
      break;
    case DEMO_CLIP_CMD_TRANSITION:
      Byte = MSG_ReadByte(msg);
      Demo_ActivateTransitionScreen(localClientNum, Byte);
      result = cmdType;
      break;
    case DEMO_CLIP_CMD_END_OF_FRAME:
      Demo_Printf(1024, "DEMO: r Clip Cmd: DEMO_CLIP_CMD_END_OF_FRAME\n");
      result = cmdType;
      break;
    case DEMO_CLIP_CMD_SET_HIGHLIGHT_REEL_PRIORITY:
      demo.playback->highlightReelPriority = MSG_ReadLong(msg);
      Demo_Printf(
        1024,
        "DEMO: r Clip Cmd: DEMO_CLIP_CMD_SET_HIGHLIGHT_REEL_PRIORITY Value: %d\n",
        demo.playback->highlightReelPriority);
      result = cmdType;
      break;
    default:
      v25 = va("Unknown demo cmd type %d\n", cmdType);
      if ( !Assert_MyHandler("c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp", 5691, 0, (const char *)&pBlock, v25) )
        __debugbreak();
LABEL_60:
      result = cmdType;
      break;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
