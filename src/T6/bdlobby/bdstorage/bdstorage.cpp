// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdstorage.cpp:0x930DD0
void __cdecl Demo_AddBookmark(
        int type,
        int time,
        int clientNum1,
        int clientNum2,
        int scoreEventPriority,
        int entityNumber,
        int eType,
        int birthTime,
        int overrideEntityCamera,
        int actorNum)
{
  int numDefaultBookmarks; // esi
  unsigned int v11; // eax
  int v12; // edx
  int roundsPlayed; // ecx
  unsigned int v14; // eax

  if ( demo.footer.numDefaultBookmarks < 2500 && (type != 8 && type != 7 || scoreEventPriority > 0) )
  {
    if ( clientNum1 > 18 )
      clientNum1 = 0;
    if ( clientNum2 > 18 )
      clientNum2 = clientNum1;
    numDefaultBookmarks = demo.footer.numDefaultBookmarks;
    demo.footer.defaultBookmarks[numDefaultBookmarks].time = time;
    v11 = type & 0x7F | *(_DWORD *)&demo.footer.defaultBookmarks[numDefaultBookmarks] & 0xF801FF80 | ((clientNum1 & 0x1F | (32 * (clientNum2 & 0x1F))) << 17);
    *(_DWORD *)&demo.footer.defaultBookmarks[numDefaultBookmarks] = v11;
    if ( ((type & 0x7F) != type || ((v11 >> 17) & 0x1F) != clientNum1 || ((v11 >> 22) & 0x1F) != clientNum2)
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\demo\\demo_recording.cpp",
            2486,
            0,
            "((int) demo.footer.defaultBookmarks[index].type == type && (int)demo.footer.defaultBookmarks[index].clientNu"
            "m1 == clientNum1 && (int)demo.footer.defaultBookmarks[index].clientNum2 == clientNum2)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v12 = *((_DWORD *)&demo.footer.defaultBookmarks[numDefaultBookmarks] + 1);
    *(_DWORD *)&demo.footer.defaultBookmarks[numDefaultBookmarks] ^= (*(_DWORD *)&demo.footer.defaultBookmarks[numDefaultBookmarks] ^ (entityNumber << 7)) & 0x1FF80;
    v12 &= 0xFFE03FE0;
    *((_DWORD *)&demo.footer.defaultBookmarks[numDefaultBookmarks] + 1) = v12 | ((scoreEventPriority & 0x7F) << 14) | eType & 0x1F;
    if ( (v12 & 0x1F | eType & 0x1F) != eType
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\demo\\demo_recording.cpp",
            2491,
            0,
            "((int) demo.footer.defaultBookmarks[index].eType == eType)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    roundsPlayed = level.matchState.archivedState.roundsPlayed;
    v14 = *((_DWORD *)&demo.footer.defaultBookmarks[numDefaultBookmarks] + 1) & 0xFFFFE01F | (32
                                                                                            * LOBYTE(level.matchState.archivedState.roundsPlayed));
    *((_DWORD *)&demo.footer.defaultBookmarks[numDefaultBookmarks] + 1) = v14;
    if ( (unsigned __int8)(v14 >> 5) != roundsPlayed
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\demo\\demo_recording.cpp",
            2493,
            0,
            "((int) demo.footer.defaultBookmarks[index].roundNumber == level.matchState.archivedState.roundsPlayed)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    demo.footer.defaultBookmarks[numDefaultBookmarks].entBirthTime = birthTime;
    if ( overrideEntityCamera )
      *((_DWORD *)&demo.footer.defaultBookmarks[numDefaultBookmarks] + 1) |= 0x2000u;
    else
      *((_DWORD *)&demo.footer.defaultBookmarks[numDefaultBookmarks] + 1) &= ~0x2000u;
    *(_DWORD *)&demo.footer.defaultBookmarks[numDefaultBookmarks] = (actorNum << 27) | (unsigned int)&g_npPool[24647] & *(_DWORD *)&demo.footer.defaultBookmarks[numDefaultBookmarks];
    if ( birthTime > time )
      Com_PrintError(25, "Birthtime is greater than current time for entity %d. Inform Bat about this.\n", entityNumber);
    Demo_Printf(
      256,
      "DEMO Info: Bookmark - Type: %d Time: %d ClientNum1: %d ClientNum2: %d\n",
      type,
      time,
      clientNum1,
      clientNum2);
    ++demo.footer.numDefaultBookmarks;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdstorage.cpp:0x930FD0
void __cdecl Demo_SetLagFlag(demoLagFlag_e flag)
{
  if ( flag == DEMO_LAGFLAG_NONE || flag > demo.lagFlag )
    demo.lagFlag = flag;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdstorage.cpp:0x930FF0
demoLagFlag_e __cdecl Demo_GetLagFlag()
{
  return demo.lagFlag;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdstorage.cpp:0x931000
void __cdecl Demo_StartRecord()
{
  int UTC; // eax
  const char *v1; // eax
  int Int; // eax
  client_t *clients; // ecx
  int i; // eax
  const char *String; // [esp-18h] [ebp-40h]
  int v6; // [esp-14h] [ebp-3Ch]
  int tm_mday; // [esp-10h] [ebp-38h]
  int v8; // [esp-Ch] [ebp-34h]
  int tm_hour; // [esp-8h] [ebp-30h]
  int tm_min; // [esp-4h] [ebp-2Ch]
  qtime_s systemTime; // [esp+0h] [ebp-28h] BYREF

  if ( Demo_IsIdle() )
  {
    if ( !Dvar_GetBool(demo_usefilesystem)
      && (LiveStorage_FileShare_ReadFileIsInProgress(CONTROLLER_INDEX_FIRST)
       || LiveStorage_FileShare_WriteFileIsInProgress(CONTROLLER_INDEX_FIRST)) )
    {
      Com_Printf(0, "You cant record a demo file when there are still tasks in progress for the previous one.");
    }
    else
    {
      Demo_Init();
      UTC = LiveStorage_GetUTC();
      Com_GetQTime(UTC, &systemTime, 1);
      tm_min = systemTime.tm_min;
      tm_hour = systemTime.tm_hour;
      v8 = systemTime.tm_year + 1900;
      tm_mday = systemTime.tm_mday;
      v6 = systemTime.tm_mon + 1;
      String = (const char *)Dvar_GetString(sv_mapname);
      v1 = (const char *)Dvar_GetString(g_gametype);
      Com_sprintf(demo.demoName, 128, "%s_%s_%d_%d_%d_%d_%d", v1, String, v6, tm_mday, v8, tm_hour, tm_min);
      if ( Demo_InitWrite() )
      {
        Demo_PopulateStaticFooterInformation(&demo.footer);
        demo.header.version = 13;
        demo.header.isDemoClip = 0;
        demo.header.maxClients = Dvar_GetInt((const dvar_t *)com_maxclients.inaddr);
        demo.header.hasExtraNetworkProfileData = Dvar_GetBool(demo_extraNetworkProfileData);
        demo.header.isZombie = Com_SessionMode_IsZombiesGame();
        demo.lagFlag = DEMO_LAGFLAG_NONE;
        demo.header.defaultClient = INVALID_CLIENT_INDEX;
        demo.header.settings.onlinegame = Com_SessionMode_IsOnlineGame();
        demo.header.settings.xblive_privatematch = Com_GameMode_IsMode(GAMEMODE_PRIVATE_MATCH);
        demo.header.settings.xblive_wagermatch = Com_GameMode_IsMode(GAMEMODE_WAGER_MATCH);
        demo.header.settings.systemlink = Com_SessionMode_IsMode(SESSIONMODE_SYSTEMLINK);
        demo.header.settings.isClientConsole = Com_IsClientConsole();
        demo.header.settings.isDedicatedServer = 1;
        Int = Dvar_GetInt(demo_streamingSendSocketBuffSizeForRecording);
        Demo_SetupDWStreamingSocketParams(Int);
        Demo_SetupStreamingForRecording(CONTROLLER_INDEX_FIRST, demo.demoName);
        LiveAntiCheat_ClearGameReport();
        Demo_WriteHeader(&demo.msg, 0);
        Demo_SetDemoState(DEMO_STATE_RECORDING);
        clients = svs.clients;
        if ( svs.clients )
        {
          for ( i = 0; i < demo.header.maxClients; ++clients )
          {
            if ( clients->header.state == 5 )
              demo.lastReliableCommandRecorded[i] = clients->reliableAcknowledge;
            ++i;
          }
        }
      }
      else
      {
        Com_Printf(0, "Demo Initialization Failed!!. Couldn't start demo recording.");
      }
    }
  }
  else
  {
    Com_Printf(0, "You cant record a demo file when it is recording/playing back.");
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdstorage.cpp:0x931230
void __usercall Demo_SaveInternal(int size@<esi>, unsigned __int8 *data, bool writeFooter, bool gameState)
{
  int v4; // eax
  unsigned int v5; // eax

  PIXBeginNamedEvent(-16711681, "Demo Recording - Demo_SaveInternal()");
  memset(demo.memBlock.compressedMsgBuf, 0, sizeof(demo.memBlock.compressedMsgBuf));
  v4 = Com_CompressWithZLib(data, size, demo.memBlock.compressedMsgBuf, 0x10000);
  demo.memBlock.compressedSize = v4;
  demo.memBlock.uncompressedSize = size;
  if ( gameState )
    Demo_Printf(
      2,
      "DEMO Live Stream - Gamestate Data Size: %d. Compressed Size: %d UncompressedSize: %d Data 1stByte: %d Data LastByte: %d\n",
      v4 + 8,
      v4,
      size,
      demo.memBlock.compressedMsgBuf[0],
      *(unsigned __int8 *)(v4 + 135645567));
  v5 = Demo_WriteMemoryBlockDataToFile();
  _InterlockedExchangeAdd(&demo.totalSize, v5);
  Demo_Printf(
    2,
    "DEMO: CurSize: %d CompressedSize: %d. Written %d bytes to demo file %s.demo\n",
    size,
    demo.memBlock.compressedSize,
    v5,
    demo.demoName);
  if ( writeFooter )
  {
    demo.footer.numHeliPatches = num_heli_height_lock_patches;
    memcpy(
      (unsigned __int8 *)demo.footer.heliPatches,
      (unsigned __int8 *)heli_height_lock_patches,
      24 * num_heli_height_lock_patches);
    Demo_WriteFooter(demo.demoFileHandle, &demo.footer);
  }
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdstorage.cpp:0x931320
void __cdecl Demo_Save(unsigned __int8 *data, int size, bool writeFooter, bool gameState)
{
  demoSaveCmd cmd; // [esp+0h] [ebp-Ch] BYREF

  if ( Dvar_GetBool(demo_save_smp) )
  {
    cmd.size = size;
    cmd.data = data;
    cmd.writeFooter = writeFooter;
    cmd.gameState = gameState;
    Sys_AddWorkerCmdInternal(&Demo_SaveWorkerCmd, &cmd, 0);
  }
  else
  {
    Demo_SaveInternal(size, data, writeFooter, gameState);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdstorage.cpp:0x931390
bool __cdecl Demo_ShouldBuildDemoSnapshot()
{
  int v0; // eax
  client_t *i; // ecx

  if ( !Demo_IsEnabled() )
    return 0;
  if ( !demo.gameStateWritten )
    return 0;
  v0 = 0;
  if ( demo.header.maxClients <= 0 )
    return 0;
  for ( i = svs.clients; i->header.state != 5; ++i )
  {
    if ( ++v0 >= demo.header.maxClients )
      return 0;
  }
  if ( Dvar_GetBool(tu10_demo_skipBuildingDemoSnapshotDuringCinematicPlayback) && R_Cinematic_IsAnyPlaying() )
    return 0;
  if ( demo.lastProcessedTime == -1 )
    return 1;
  return svsHeader.time - demo.lastProcessedTime >= Dvar_GetInt(demo_recordingrate);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdstorage.cpp:0x931410
void __cdecl Demo_StartSaveProcess(bool gameState)
{
  unsigned __int8 *msgBuf1; // edi
  int cursize; // esi
  unsigned __int8 *msgBuf0; // eax
  int data[2]; // [esp+Ch] [ebp-Ch] BYREF
  char v5; // [esp+14h] [ebp-4h]
  bool v6; // [esp+15h] [ebp-3h]

  PIXBeginNamedEvent(-1, "wait & assist Demo_Save");
  Sys_AssistAndWaitWorkerCmdInternal(&Demo_SaveWorkerCmd);
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
  MSG_WriteBits(&demo.msg, 0, 2);
  msgBuf1 = demo.msgBuf1;
  if ( !demo.msgBufFlag )
    msgBuf1 = demo.msgBuf0;
  cursize = demo.msg.cursize;
  if ( Dvar_GetBool(demo_save_smp) )
  {
    data[0] = (int)msgBuf1;
    data[1] = cursize;
    v5 = 0;
    v6 = gameState;
    Sys_AddWorkerCmdInternal(&Demo_SaveWorkerCmd, data, 0);
  }
  else
  {
    Demo_SaveInternal(cursize, msgBuf1, 0, gameState);
  }
  msgBuf0 = demo.msgBuf0;
  if ( !demo.msgBufFlag )
    msgBuf0 = demo.msgBuf1;
  demo.msgBufFlag = !demo.msgBufFlag;
  MSG_Init(&demo.msg, msgBuf0, 0x10000);
  Demo_Printf(3, "DEMO: Switching to buffer %d\n", demo.msgBufFlag);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdstorage.cpp:0x931500
int __cdecl Demo_SaveCallback(jqBatch *batch)
{
  unsigned int *v1; // edi

  v1 = jqCallbackPre(batch, "Demo_Save");
  PIXBeginNamedEvent(-1, "Demo_SaveCmd");
  Demo_SaveInternal(v1[1], (unsigned __int8 *)*v1, *((_BYTE *)v1 + 8), *((_BYTE *)v1 + 9));
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
  jqCallbackPost(batch, v1, 1);
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdstorage.cpp:0x931560
void __cdecl Demo_WriteGamestateToBuffer(ClientNum_t clientNum, msg_t *msg, int msgSequence)
{
  const char *MapName; // eax
  const char *v4; // eax
  const char *GameTypeName; // eax
  char name[256]; // [esp+4h] [ebp-104h] BYREF

  if ( Demo_IsEnabled() )
  {
    MSG_WriteBits(&demo.msg, 3, 2);
    MSG_WriteLong(&demo.msg, msgSequence);
    demo.gameStateMessageSequence = msgSequence;
    MSG_Embed(&demo.msg, msg);
    Demo_RecordProfileData(DEMO_PROFILE_GAMESTATE, msg->cursize);
    Demo_StartSaveProcess(1);
    MapName = UI_GetMapName(demo.footer.info.mapName, 1);
    Com_sprintf(name, 256, "%s_CAPS", MapName);
    v4 = UI_SafeTranslateString(name);
    Com_sprintf(demo.footer.info.name, 22, "%s", v4);
    GameTypeName = UI_GetGameTypeName(demo.footer.info.gameType, 0, demo.footer.info.mapName);
    Com_sprintf(demo.footer.info.description, 64, "%s", GameTypeName);
    demo.gameStateWritten = 1;
    Demo_Printf(1, "DEMO: w Type: %d Client: %d Size: %d msgSeq: %d\n", 3, clientNum, msg->cursize, msgSequence);
  }
}

#endif // __UNIMPLEMENTED__
