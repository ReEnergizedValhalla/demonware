// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdbytebuffer.cpp:0x926B20
void __usercall Demo_ParseClientPackets(msg_t *msg@<esi>)
{
  msg_t *v1; // [esp+0h] [ebp-4h]

  if ( MSG_ReadBit(v1) )
  {
    do
    {
      MSG_ReadBits(msg, 5);
      while ( MSG_ReadBit(msg) )
      {
        MSG_ReadLong(msg);
        MSG_ReadBit(msg);
      }
    }
    while ( MSG_ReadBit(msg) );
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbytebuffer.cpp:0x926B70
void __usercall Demo_ParseReliableCmdSizes(msg_t *msg@<esi>)
{
  int Short; // eax
  int v2; // edi
  msg_t *v3; // [esp+0h] [ebp-4h]

  if ( MSG_ReadBit(v3) )
  {
    do
    {
      MSG_ReadBits(msg, 5);
      MSG_ReadLong(msg);
      Short = MSG_ReadShort(msg);
      if ( Short > 0 )
      {
        v2 = Short;
        do
        {
          MSG_ReadByte(msg);
          MSG_ReadShort(msg);
          --v2;
        }
        while ( v2 );
      }
    }
    while ( MSG_ReadBit(msg) );
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbytebuffer.cpp:0x926BD0
char __cdecl Demo_ReadFooter(char *name, int handle)
{
  const char *v2; // eax
  int v3; // esi
  int v5; // ebx
  int v6; // ebx
  int v7; // ebx
  int v8; // esi
  int v9; // edi
  ClientNum_t *p_clientNum; // esi
  int v11; // edi
  unsigned int *v12; // esi
  int numHeliPatches; // eax
  int v14; // edi
  vec3_t *p_origin; // esi
  int version_end; // [esp+8h] [ebp-140h] BYREF
  int numBytesToRead; // [esp+Ch] [ebp-13Ch] BYREF
  msg_t msg; // [esp+10h] [ebp-138h] BYREF
  int footerHandle; // [esp+40h] [ebp-108h]
  char ospath[256]; // [esp+44h] [ebp-104h] BYREF

  if ( handle )
  {
    footerHandle = handle;
    v3 = handle;
  }
  else
  {
    Demo_GetDemoPath(ospath);
    v2 = va("%s.demo", name);
    v3 = Demo_OpenFileRead(v2, ospath, 1);
    footerHandle = v3;
    if ( !v3 )
      return 0;
  }
  Demo_SeekFile(v3, -8, 1);
  Demo_Read(&numBytesToRead, 4, v3);
  Demo_Read(&version_end, 4, v3);
  if ( version_end == demo.header.version )
  {
    Demo_SeekFile(v3, -8 - numBytesToRead, 1);
    v5 = Demo_Read(&demo.memBlock, 4, demo.demoFileHandle);
    v6 = Demo_Read(&demo.memBlock.uncompressedSize, 4, demo.demoFileHandle) + v5;
    v7 = Demo_Read(demo.memBlock.compressedMsgBuf, demo.memBlock.compressedSize, demo.demoFileHandle) + v6;
    memset(demo.msgBuf1, 0, sizeof(demo.msgBuf1));
    MSG_Init(&msg, demo.msgBuf1, 0x10000);
    msg.cursize = Com_DecompressWithZLib(
                    demo.memBlock.compressedMsgBuf,
                    demo.memBlock.compressedSize,
                    demo.msgBuf1,
                    demo.memBlock.uncompressedSize);
    msg.data = demo.msgBuf1;
    demo.footer.version = MSG_ReadLong(&msg);
    if ( demo.footer.version == demo.header.version )
    {
      demo.footer.startTime = MSG_ReadLong(&msg);
      demo.footer.endTime = MSG_ReadLong(&msg);
      v8 = 0;
      for ( demo.footer.info.taggedPlayers.count = MSG_ReadLong(&msg); v8 < demo.footer.info.taggedPlayers.count; ++v8 )
        demo.footer.info.taggedPlayers.playerIndex[v8] = MSG_ReadLong(&msg);
      MSG_ReadString(&msg, demo.footer.info.gameType, 0x100u);
      MSG_ReadString(&msg, demo.footer.info.mapName, 0x100u);
      MSG_ReadString(&msg, demo.footer.info.zmGameModeGroup, 0x100u);
      MSG_ReadString(&msg, demo.footer.info.zmMapStartLoc, 0x100u);
      MSG_ReadString(&msg, demo.footer.info.authorName, 0x20u);
      MSG_ReadString(&msg, demo.footer.info.name, 0x16u);
      demo.footer.info.isModifiedName = MSG_ReadBit(&msg) != 0;
      MSG_ReadString(&msg, demo.footer.info.description, 0x40u);
      demo.footer.info.isModifiedDescription = MSG_ReadBit(&msg) != 0;
      demo.footer.info.createTime = MSG_ReadLong(&msg);
      v9 = 0;
      demo.footer.numConnectedPlayers = MSG_ReadLong(&msg);
      if ( demo.footer.numConnectedPlayers > 0 )
      {
        p_clientNum = &demo.footer.connectedPlayers[0].clientNum;
        do
        {
          *((_BYTE *)p_clientNum - 4) = MSG_ReadByte(&msg);
          *p_clientNum = MSG_ReadByte(&msg);
          *(_QWORD *)(p_clientNum + 1) = MSG_ReadInt64(&msg);
          *((_DWORD *)p_clientNum + 3) = MSG_ReadLong(&msg);
          *((_DWORD *)p_clientNum + 4) = MSG_ReadLong(&msg);
          *((_DWORD *)p_clientNum + 5) = MSG_ReadByte(&msg);
          *((_DWORD *)p_clientNum + 6) = MSG_ReadByte(&msg);
          ++v9;
          p_clientNum += 12;
        }
        while ( v9 < demo.footer.numConnectedPlayers );
      }
      v11 = 0;
      demo.footer.numDefaultBookmarks = MSG_ReadLong(&msg);
      if ( demo.footer.numDefaultBookmarks > 0 )
      {
        v12 = (unsigned int *)demo.footer.defaultBookmarks + 1;
        do
        {
          *(v12 - 1) ^= ((unsigned __int8)MSG_ReadByte(&msg) ^ (unsigned __int8)*(v12 - 1)) & 0x7F;
          v12[1] = MSG_ReadLong(&msg);
          *(v12 - 1) ^= (*(v12 - 1) ^ (MSG_ReadByte(&msg) << 17)) & 0x3E0000;
          *(v12 - 1) ^= (unsigned int)&gScrMemTreeServerNodes[4256] & (*(v12 - 1) ^ (MSG_ReadByte(&msg) << 22));
          *(v12 - 1) ^= (*(v12 - 1) ^ (MSG_ReadLong(&msg) << 7)) & 0x1FF80;
          *v12 ^= (*v12 ^ MSG_ReadShort(&msg)) & 0x1F;
          *v12 = *v12 & 0xFFFFE01F | (32 * (unsigned __int8)MSG_ReadByte(&msg));
          v12[2] = MSG_ReadLong(&msg);
          if ( MSG_ReadBit(&msg) )
            *v12 |= 0x2000u;
          else
            *v12 &= ~0x2000u;
          ++v11;
          *v12 ^= (*v12 ^ (MSG_ReadByte(&msg) << 14)) & 0x1FC000;
          v12 += 4;
        }
        while ( v11 < demo.footer.numDefaultBookmarks );
      }
      numHeliPatches = MSG_ReadLong(&msg);
      v14 = 0;
      demo.footer.numHeliPatches = numHeliPatches;
      if ( numHeliPatches > 0 )
      {
        p_origin = &demo.footer.heliPatches[0].origin;
        do
        {
          LODWORD(p_origin[-1].z) = MSG_ReadLong(&msg);
          p_origin->x = MSG_ReadFloat(&msg);
          p_origin->y = MSG_ReadFloat(&msg);
          p_origin->z = MSG_ReadFloat(&msg);
          LOWORD(p_origin[1].x) = MSG_ReadShort(&msg);
          LODWORD(p_origin[1].y) = MSG_ReadBit(&msg) != 0;
          numHeliPatches = demo.footer.numHeliPatches;
          ++v14;
          p_origin += 2;
        }
        while ( v14 < demo.footer.numHeliPatches );
      }
      num_heli_height_lock_patches = numHeliPatches;
      if ( numHeliPatches > 0 )
        qmemcpy(heli_height_lock_patches, demo.footer.heliPatches, 4 * ((unsigned int)(24 * numHeliPatches) >> 2));
      Demo_Printf(258, "DEMO Info: Read %d bytes to demo file %s.info\n", v7, demo.demoName);
      if ( !handle )
        Demo_CloseFile(footerHandle);
      return 1;
    }
    else
    {
      if ( handle )
        Com_Error(ERR_DROP, "EXE_ERR_INVALID_DEMO_FILE");
      else
        Demo_CloseFile(v3);
      return 0;
    }
  }
  else
  {
    if ( handle )
      Com_Error(ERR_DROP, "EXE_ERR_INVALID_DEMO_FILE");
    else
      Demo_CloseFile(v3);
    return 0;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbytebuffer.cpp:0x9271C0
bool __cdecl Demo_ShouldIgnoreScoreboardToggle(LocalClientNum_t localClientNum)
{
  if ( Demo_IsPlaying() && (demo.playbackMode & 1) != 0
    || Demo_IsPlaying() && demo.playbackInited && demo.playback->clipState == DEMO_CLIP_PREVIEW )
  {
    return 1;
  }
  if ( Demo_IsSaveDialogOpen(localClientNum)
    || Demo_IsDollyCamMarkerDialogOpen(localClientNum)
    || Demo_IsInformationScreenActive()
    || Demo_IsCapturingScreenshot(localClientNum) )
  {
    return 1;
  }
  return Demo_IsCreatingHighlightReel();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbytebuffer.cpp:0x927250
void __cdecl Demo_ActivateHoldInput(LocalClientNum_t localClientNum)
{
  if ( demo.playback && demo.playback->holdCmd.active )
  {
    Com_PrintError(10, "Cannot activate hold button when theres already an active hold command.");
  }
  else
  {
    demo.playback->holdCmd.activatedTime = Sys_Milliseconds();
    demo.playback->holdCmd.key = localClientNum;
    demo.playback->holdCmd.active = 1;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbytebuffer.cpp:0x9272A0
void __cdecl Demo_AllocatePlaybackMemory(int location)
{
  if ( Demo_IsPlaying() )
  {
    PMem_BeginAlloc("SnapshotDemoPlaybackBuffer", location, TRACK_MISC);
    demo.playback = (demoPlayback *)_PMem_AllocNamed(
                                      0x26A980u,
                                      4u,
                                      4u,
                                      location,
                                      "SnapshotDemoPlaybackBuffer",
                                      TRACK_MISC);
    PMem_EndAlloc("SnapshotDemoPlaybackBuffer", location);
    memset((unsigned __int8 *)demo.playback, 0, sizeof(demoPlayback));
    if ( Demo_IsPlaying() && (demo.playbackMode & 1) != 0 )
    {
      PMem_BeginAlloc("SnapshotDemoExtraPlaybackBuffers", location, TRACK_MISC);
      s_keyframeBuf = _PMem_AllocNamed(0x10000u, 4u, 4u, location, "SnapshotDemoKeyframeBuffer", TRACK_MISC);
      PMem_EndAlloc("SnapshotDemoExtraPlaybackBuffers", location);
      memset(s_keyframeBuf, 0, 0x10000u);
    }
    else
    {
      PMem_BeginAlloc("SnapshotDemoExtraPlaybackBuffers", location, TRACK_MISC);
      s_keyframeBuf = _PMem_AllocNamed(
                        (unsigned int)&loc_4FFFFC + 4,
                        4u,
                        4u,
                        location,
                        "SnapshotDemoKeyframeBuffer",
                        TRACK_MISC);
      s_screenshotBuf = _PMem_AllocNamed(0x108000u, 4u, 4u, location, "SnapshotDemoScreenshotBuffer", TRACK_MISC);
      s_mainClipRecordingBuf = _PMem_AllocNamed(0x100000u, 4u, 4u, location, "SnapshotDemoClipRecordBuffer", TRACK_MISC);
      s_clipMergeBuf = _PMem_AllocNamed(0x100000u, 4u, 4u, location, "SnapshotDemoClipMergeBuffer", TRACK_MISC);
      s_dollyCamKeyframeBuf = _PMem_AllocNamed(
                                0x320000u,
                                4u,
                                4u,
                                location,
                                "SnapshotDemoDollyCameraKeyframeBuffer",
                                TRACK_MISC);
      PMem_EndAlloc("SnapshotDemoExtraPlaybackBuffers", location);
      memset(s_keyframeBuf, 0, (unsigned int)&loc_4FFFFC + 4);
      memset(s_screenshotBuf, 0, 0x108000u);
      memset(s_mainClipRecordingBuf, 0, 0x100000u);
      memset(s_clipMergeBuf, 0, 0x100000u);
      memset(s_dollyCamKeyframeBuf, 0, 0x320000u);
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbytebuffer.cpp:0x9274C0
void __cdecl Demo_Load()
{
  unsigned int v0; // esi
  unsigned int v1; // esi

  v0 = 0;
  memset(demo.memBlock.compressedMsgBuf, 0, sizeof(demo.memBlock.compressedMsgBuf));
  MSG_Init(&demo.msg, demo.msgBuf0, 0x10000);
  if ( demo.playbackInited && demo.playback->clipState == DEMO_CLIP_PREVIEW )
  {
    demo.memBlock.compressedSize = *(_DWORD *)&demo.playback->mainClipRecordingBuf[demo.playback->clipPreviewBufferIndex];
    demo.playback->clipPreviewBufferIndex += 4;
    demo.memBlock.uncompressedSize = *(_DWORD *)&demo.playback->mainClipRecordingBuf[demo.playback->clipPreviewBufferIndex];
    demo.playback->clipPreviewBufferIndex += 4;
    memcpy(
      demo.memBlock.compressedMsgBuf,
      &demo.playback->mainClipRecordingBuf[demo.playback->clipPreviewBufferIndex],
      demo.memBlock.compressedSize);
    demo.playback->clipPreviewBufferIndex += demo.memBlock.compressedSize;
  }
  else
  {
    do
      v0 += Demo_Read(&demo.memBlock, 4, demo.demoFileHandle);
    while ( !demo.memBlock.compressedSize );
    v1 = Demo_Read(&demo.memBlock.uncompressedSize, 4, demo.demoFileHandle) + v0;
    v0 = Demo_Read(demo.memBlock.compressedMsgBuf, demo.memBlock.compressedSize, demo.demoFileHandle) + v1;
    _InterlockedExchangeAdd(&demo.totalSize, v0);
  }
  demo.msg.cursize = Com_DecompressWithZLib(
                       demo.memBlock.compressedMsgBuf,
                       demo.memBlock.compressedSize,
                       demo.msgBuf0,
                       demo.memBlock.uncompressedSize);
  demo.msg.data = demo.msgBuf0;
  Demo_Printf(
    2,
    "DEMO: CurSize: %d CompressedSize: %d. Read %d bytes to demo file %s\n",
    demo.memBlock.uncompressedSize,
    demo.memBlock.compressedSize,
    v0 + 8,
    demo.demoName);
}

#endif // __UNIMPLEMENTED__
