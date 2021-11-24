// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdmatchmaking.cpp:0x929320
void __usercall Demo_PreviewSegment(double a1@<st0>, LocalClientNum_t localClientNum, int segmentIndex)
{
  clientActive_t *LocalClientGlobals; // edi
  demoPlayback *playback; // eax
  int clipBufferIndex; // ecx
  cg_t *cgameGlob; // [esp+18h] [ebp+Ch]

  if ( segmentIndex < -1
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
          5763,
          0,
          "(segmentIndex >= -1)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  demo.playback->clipPreviewSegmentNumber = segmentIndex;
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
  Demo_Printf(1024, "Clip: Starting clip previewing\n");
  Dvar_SetBool(demo_pause, 0);
  demo.playback->clipPausedState = 0;
  playback = demo.playback;
  if ( !demo.playback->previewAllSegments )
  {
    demo.playback->completed = 0;
    playback = demo.playback;
  }
  if ( segmentIndex == -1 )
    clipBufferIndex = playback->segments[playback->segmentCount].clipBufferIndex;
  else
    clipBufferIndex = playback->segments[segmentIndex].clipBufferIndex;
  playback->clipPreviewBufferIndex = clipBufferIndex;
  if ( demo.playbackInited )
    demo.playback->clipState = DEMO_CLIP_PREVIEW;
  if ( demo.playback->clipRecordBufIndex == demo.playback->clipPreviewBufferIndex
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
          5792,
          0,
          "(demo.playback->clipRecordBufIndex != demo.playback->clipPreviewBufferIndex)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  Demo_Load();
  Demo_ResetSnapshotData();
  Demo_ReadDemoMessage(localClientNum);
  Demo_ResetTimeValues(localClientNum, LocalClientGlobals->snap.serverTime);
  Demo_ResetSequenceNumbers(localClientNum, LocalClientGlobals->snap.messageNum - 1);
  Demo_ResetWorldInformation(a1, localClientNum, LocalClientGlobals->snap.serverTime);
  cgameGlob->latestSnapshotNum = LocalClientGlobals->snap.messageNum;
  LocalClientGlobals->serverTimeDelta = LocalClientGlobals->snap.serverTime - cls.realtime;
  if ( !demo.playback->previewAllSegments && Demo_IsPlaying() && demo.playbackInited )
  {
    demo.playback->informationScreenType = DEMO_INFORMATION_SCREEN_TRANSITION;
    demo.playback->informationScreenActivateTime = Sys_Milliseconds();
    demo.playback->informationScreenActive = 1;
  }
  BG_EvalVehicleName();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdmatchmaking.cpp:0x929540
void __cdecl Demo_WriteDemoPreviewPoint(LocalClientNum_t localClientNum, demoRestorePoint restorePoint)
{
  clientActive_t *LocalClientGlobals; // ebx
  bool v3; // al
  demoRestorePoint v4; // esi
  msg_t previewMsg; // [esp+Ch] [ebp-60h] BYREF
  msg_t msg; // [esp+3Ch] [ebp-30h] BYREF
  int savedregs; // [esp+6Ch] [ebp+0h] BYREF

  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
  CL_GetLocalClientConnection(localClientNum);
  if ( demo.playbackInited )
    v3 = !demo.shutdownInProgress && demo.playback->completed;
  else
    v3 = 0;
  demo.playback->demoCompleteStateForRestorationPoint[restorePoint] = v3;
  PIXBeginNamedEvent(-1, "Preview Keyframe - Generation");
  MSG_Init(&msg, demo.msgBuf1, 0x10000);
  demo.playback->forceWriteClipCommands = 1;
  Demo_WriteClipCommandsInternal(localClientNum, &msg, 0);
  Demo_GenerateUncompressedSnapshot((int)&savedregs, localClientNum, &msg, &demo.snapshot, 1);
  MSG_Init(&previewMsg, demo.playback->demoPreviewBuf[restorePoint], 0x10000);
  MSG_Embed(&previewMsg, &msg);
  v4 = restorePoint;
  demo.playback->demoPreview[v4].demoFileMemoryBlockStart = -8 - demo.memBlock.compressedSize + demo.totalSize;
  demo.playback->demoPreview[v4].keyframeBufferStart = 0;
  demo.playback->demoPreview[restorePoint].keyframeSnapshotTime = LocalClientGlobals->serverTime;
  demo.playback->demoPreview[v4].firstCmdSequence = demo.playback->lastProcessedCmd;
  demo.playback->demoPreview[v4].size = previewMsg.cursize;
  MSG_SetBookmark(&demo.msg, &demo.playback->demoPreview[restorePoint].msgBookmark);
  if ( (_S2_15 & 1) == 0 )
  {
    _S2_15 |= 1u;
    _hwm_id_27 = BB_RegisterHighWaterMark("demo_restore_point");
  }
  BB_SetHighWaterMark(_hwm_id_27, previewMsg.cursize);
  if ( demo.playback->demoPreview[restorePoint].size > 0x10000u
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
          5855,
          0,
          "(demo.playback->demoPreview[restorePoint].size <= sizeof( demo.playback->demoPreviewBuf[restorePoint] ))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
}

#endif // __UNIMPLEMENTED__
