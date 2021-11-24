// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdremotetask.cpp:0x92A270
void __cdecl Demo_HandleHoldInput(LocalClientNum_t localClientNum, int key, bool holdResult)
{
  bool IsPauseMenuOpen; // bl
  BOOL IsScoreboardDisplayed; // edi
  bool v5; // al
  const char *v6; // eax
  bool isErrorDialogOpen; // [esp+Dh] [ebp-3h]
  bool isDollyCamMarkerDialogOpen; // [esp+Eh] [ebp-2h]
  bool isSaveDialogOpen; // [esp+Fh] [ebp-1h]

  IsPauseMenuOpen = Demo_IsPauseMenuOpen(localClientNum);
  IsScoreboardDisplayed = CG_IsScoreboardDisplayed(localClientNum);
  isSaveDialogOpen = Demo_IsSaveDialogOpen(localClientNum);
  isDollyCamMarkerDialogOpen = Demo_IsDollyCamMarkerDialogOpen(localClientNum);
  isErrorDialogOpen = Demo_IsErrorDialogOpen(localClientNum);
  v5 = Demo_IsPlaying() && demo.playbackInited && demo.playback->informationScreenActive;
  if ( !IsPauseMenuOpen
    && !IsScoreboardDisplayed
    && !isSaveDialogOpen
    && !isDollyCamMarkerDialogOpen
    && !isErrorDialogOpen
    && !v5 )
  {
    if ( key != 3 && key != 114 )
    {
      v6 = va("Unhandled Hold Button Input %d\n", key);
      if ( !Assert_MyHandler("c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp", 9062, 0, (const char *)&pBlock, v6) )
      {
        __debugbreak();
        demo.playback->holdCmd.active = 0;
        return;
      }
      goto LABEL_25;
    }
    if ( holdResult )
    {
      if ( Demo_IsStereo3D() || Demo_IsDollyCamera() )
        goto LABEL_25;
      if ( !Demo_IsPaused() )
        Demo_Pause();
      demo.playback->requestedForScreenshotCapture = 1;
      Cbuf_AddText(localClientNum, "demo_screenshot\n");
    }
    else if ( !(unsigned __int8)Demo_IsHighlightReelMode() )
    {
      if ( !Demo_CanStartClipRecord(localClientNum) )
      {
LABEL_25:
        demo.playback->holdCmd.active = 0;
        return;
      }
      demo.playback->requestedForScreenshotCapture = 1;
      Cbuf_AddText(localClientNum, "demo_startcliprecord\n");
    }
    demo.playback->buttonPressTime[1] = Sys_Milliseconds();
    goto LABEL_25;
  }
  demo.playback->holdCmd.active = 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdremotetask.cpp:0x92A3D0
BOOL __cdecl Demo_IsTimeStopped()
{
  if ( Demo_IsPlaying() )
  {
    if ( demo.playback )
    {
      if ( Dvar_GetBool(demo_pause) && !demo.playback->overridePause )
        return 1;
    }
    else if ( Dvar_GetBool(demo_pause) )
    {
      return 1;
    }
  }
  return demo.playbackInited && !demo.shutdownInProgress && demo.playback->completed
      || Demo_GetClipPausedState()
      || demo.playbackInited
      && !demo.shutdownInProgress
      && demo.playback->waitingForDownloadData
      && !Demo_HaveWeDownloadedNextFileSegmentData();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdremotetask.cpp:0x92A470
void __cdecl Demo_SwitchPlayer(LocalClientNum_t localClientNum, bool anticlockwise, int clientNum)
{
  char v3; // bl
  int Int; // eax

  if ( Dvar_GetInt(net_profile) || !Demo_IsAnyFreeMoveCamera() )
  {
    if ( demo.playbackInited && !demo.shutdownInProgress && demo.playback->completed )
    {
      Com_PrintError(25, "We cannot switch players when the demo is completed.\n");
    }
    else if ( !Demo_IsPlaying() || !demo.header.isDemoClip )
    {
      if ( Demo_IsPlaying() && demo.playbackInited && demo.playback->clipState == DEMO_CLIP_PREVIEW )
      {
        Com_PrintError(25, "We cannot switch players in a demo that is being previewed\n");
      }
      else
      {
        v3 = Demo_SwitchPlayerInternal(clientNum, localClientNum, anticlockwise, 0);
        if ( Demo_IsPaused() )
        {
          if ( v3 )
          {
            Int = Dvar_GetInt(demo_client);
            Demo_UpdateCurrentSnapshot(localClientNum, &demo.snapshot.ps[Int]);
          }
        }
      }
    }
  }
  else
  {
    Com_PrintError(25, "We cannot switch players when in free camera.\n");
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdremotetask.cpp:0x92A570
void __usercall Demo_GenerateKeyFrameSnapshot(LocalClientNum_t localClientNum@<esi>)
{
  msg_t msg; // [esp+0h] [ebp-30h] BYREF
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  PIXBeginNamedEvent(-1, "Keyframe - Generation");
  MSG_Init(&msg, demo.msgBuf1, 0x10000);
  if ( Demo_IsPlaying() && demo.header.isDemoClip )
  {
    demo.playback->forceWriteClipCommands = 1;
    Demo_WriteClipCommandsInternal(localClientNum, &msg, 0);
  }
  Demo_GenerateUncompressedSnapshot((int)&savedregs, localClientNum, &msg, &demo.snapshot, 1);
  MSG_Init(&demo.playback->keyframeMsg, demo.memBlock.compressedMsgBuf, 0x10000);
  MSG_Embed(&demo.playback->keyframeMsg, &msg);
  demo.playback->keyframeGenerated = 1;
  demo.playback->forceKeyframe = 0;
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdremotetask.cpp:0x92A640
char __cdecl Demo_StartClipRecord(LocalClientNum_t localClientNum)
{
  demoPlayback *playback; // eax
  const char *v3; // eax
  int v4; // [esp-4h] [ebp-8h]
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( !Demo_CanStartClipRecord(localClientNum) )
    return 0;
  if ( !Demo_IsPlaying() || !demo.playbackInited || (playback = demo.playback, !demo.playback->creatingHighlightReel) )
  {
    if ( !Demo_CaptureThumbnailForSegment() )
      return 0;
    playback = demo.playback;
  }
  playback->prevClipRecordBufIndex = playback->clipRecordBufIndex;
  demo.playback->prevClipTime = demo.playback->clipTime;
  CL_GetLocalClientGlobals(localClientNum);
  Demo_InitClipRecord(localClientNum, demo.playback->clipRecordBufIndex == 0);
  demo.playback->segments[demo.playback->segmentCount].clipBufferIndex = demo.playback->clipRecordBufIndex;
  v4 = demo.playback->segmentCount + 1;
  v3 = UI_SafeTranslateString("MENU_SEGMENT");
  Com_sprintf(demo.playback->segments[demo.playback->segmentCount].name, 48, "%s%02d", v3, v4);
  demo.playback->segments[demo.playback->segmentCount].transition = DEMO_CLIP_TRANSITION_FIRST;
  if ( Demo_IsPlaying() && demo.playbackInited )
  {
    demo.playback->informationScreenType = DEMO_INFORMATION_SCREEN_TRANSITION;
    demo.playback->informationScreenActivateTime = Sys_Milliseconds();
    demo.playback->informationScreenActive = 1;
  }
  Demo_WriteDemoPreviewPoint(localClientNum, DEMO_RESTORE_POINT_START);
  demo.playback->pendingSegmentSave = 1;
  Demo_WriteUncompressedClipSnapshot(localClientNum, (int)&savedregs);
  if ( demo.playbackInited )
    demo.playback->clipState = DEMO_CLIP_RECORD_CONTINUOUS;
  Demo_Printf(1024, "Clip: Starting clip Recording\n");
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdremotetask.cpp:0x92A7D0
void __cdecl Demo_PauseClipRecord(LocalClientNum_t localClientNum)
{
  demoClipState clipState; // ecx
  int ControllerIndex; // eax
  const char *v3; // [esp-Ch] [ebp-Ch]

  if ( demo.playbackInited
    && ((clipState = demo.playback->clipState, clipState == DEMO_CLIP_RECORD_UNCOMPRESSED_SNAPHOT)
     || clipState == DEMO_CLIP_RECORD_CONTINUOUS) )
  {
    demo.playback->clipState = DEMO_CLIP_PAUSED;
    MSG_WriteBits(&demo.playback->clipRecordingMsg, 0, 2);
    Demo_SaveClipRecordMessageToMainMemory(
      localClientNum,
      demo.playback->clipRecordingMsg.data,
      demo.playback->clipRecordingMsg.cursize,
      0);
    Demo_WriteDemoPreviewPoint(localClientNum, DEMO_RESTORE_POINT_END);
    if ( Demo_IsPlaying() && demo.playbackInited && demo.playback->creatingHighlightReel )
    {
      if ( demo.playback->cancelHighlightReelCreation )
        v3 = "demo_savesegment 1";
      else
        v3 = "demo_savesegment 0";
      ControllerIndex = Com_LocalClient_GetControllerIndex(localClientNum);
      Cmd_ExecuteSingleCommand(localClientNum, (ControllerIndex_t)ControllerIndex, v3, 0);
    }
    else
    {
      Demo_OpenSavePopUp(localClientNum, DEMO_SAVE_POPUP_CLIP);
      Dvar_SetBool(demo_pause, 1);
    }
    Demo_Printf(1024, "Clip: Paused clip Recording\n");
  }
  else
  {
    Com_PrintError(25, "The clip system is not recording.\n");
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdremotetask.cpp:0x92A8C0
void __cdecl Demo_WriteClipCommandsWhenPaused(LocalClientNum_t localClientNum)
{
  demoClipState clipState; // eax
  msg_t *p_clipRecordingMsg; // esi
  msg_t *v3; // esi

  if ( demo.playback->clipRecordBufIndex < 983040 )
  {
    p_clipRecordingMsg = &demo.playback->clipRecordingMsg;
    if ( demo.playback->clipRecordingMsg.cursize >= 60416 )
    {
      MSG_WriteBits(&demo.playback->clipRecordingMsg, 0, 2);
      Demo_SaveClipRecordMessageToMainMemory(localClientNum, p_clipRecordingMsg->data, p_clipRecordingMsg->cursize, 0);
    }
    Demo_WriteClipCommandsInternal(localClientNum, p_clipRecordingMsg, 1);
    v3 = &demo.playback->clipRecordingMsg;
    MSG_WriteBits(&demo.playback->clipRecordingMsg, 2, 2);
    MSG_WriteByte(v3, 12);
  }
  else
  {
    if ( !demo.playbackInited
      || (clipState = demo.playback->clipState, clipState != DEMO_CLIP_RECORD_CONTINUOUS)
      && clipState != DEMO_CLIP_RECORD_UNCOMPRESSED_SNAPHOT )
    {
      if ( !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
              5431,
              0,
              "(Demo_IsClipRecording())",
              (const char *)&pBlock) )
        __debugbreak();
    }
    Demo_PauseClipRecord(localClientNum);
    if ( Demo_IsPlaying() && demo.playbackInited && demo.playback->creatingHighlightReel )
      Demo_CancelHighlightReelCreation();
  }
}

#endif // __UNIMPLEMENTED__
