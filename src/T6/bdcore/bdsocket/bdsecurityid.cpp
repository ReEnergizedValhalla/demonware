// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdsecurityid.cpp:0x924D40
void __thiscall Demo_WriteClipGameState(LocalClientNum_t localClientNum)
{
  int *LocalClientConnection; // ebx
  int GfxWorldChecksum; // eax
  int Checksum; // eax
  int v5; // edi
  const entityState_s *entityBaselines; // esi
  int v7; // eax
  clientActive_t *LocalClientGlobals; // [esp+8h] [ebp-134h]
  int oldSvsHeaderValid; // [esp+Ch] [ebp-130h]
  msg_t msg; // [esp+10h] [ebp-12Ch] BYREF
  entityState_s nullstate; // [esp+40h] [ebp-FCh] BYREF

  LocalClientConnection = (int *)CL_GetLocalClientConnection(localClientNum);
  memset(demo.msgBuf1, 0, sizeof(demo.msgBuf1));
  MSG_Init(&msg, demo.msgBuf1, 0x10000);
  MSG_WriteLong(&msg, LocalClientConnection[77]);
  MSG_ClearLastReferencedEntity(&msg);
  MSG_WriteByte(&msg, 1);
  MSG_WriteLong(&msg, LocalClientConnection[4305]);
  MSG_WriteString(&msg, demo.footer.info.mapName);
  MSG_WriteString(&msg, demo.footer.info.gameType);
  MSG_WriteLong(&msg, 0);
  MSG_WriteLong(&msg, 0);
  MSG_WriteLong(&msg, 0);
  if ( Demo_IsVersionAtLeast(8) )
  {
    GfxWorldChecksum = DB_GetGfxWorldChecksum();
    MSG_WriteLong(&msg, GfxWorldChecksum);
  }
  MSG_WriteLong(&msg, cls.gameState.clientfield_hash);
  MSG_WriteLong(&msg, cls.gameState.server_highest_clientfield_version);
  Checksum = CCS_GetChecksum();
  MSG_WriteLong(&msg, Checksum);
  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
  Demo_WriteConfigStrings(&msg, localClientNum);
  svsHeader.mapCenter = cls.mapCenter;
  oldSvsHeaderValid = svsHeaderValid;
  svsHeaderValid = 1;
  memset((unsigned __int8 *)&nullstate, 0, sizeof(nullstate));
  v5 = 0;
  entityBaselines = LocalClientGlobals->entityBaselines;
  do
  {
    if ( entityBaselines->number || !v5 )
    {
      MSG_WriteByte(&msg, 4);
      demo_defaultSnapInfo.fromBaseline = 1;
      MSG_WriteEntity(&demo_defaultSnapInfo, &msg, 0, 0, 0, &nullstate, entityBaselines, DELTA_FLAGS_FORCE);
      demo_defaultSnapInfo.fromBaseline = 0;
    }
    ++v5;
    ++entityBaselines;
  }
  while ( v5 < 1024 );
  MSG_WriteByte(&msg, 3);
  MSG_WriteLong(&msg, cls.gameState.matchUIVisibilityFlags);
  svsHeaderValid = oldSvsHeaderValid;
  MSG_WriteByte(&msg, 14);
  MSG_WriteLong(&msg, LocalClientConnection[1]);
  MSG_WriteLong(&msg, LocalClientConnection[76]);
  MSG_WriteByte(&msg, 6);
  DynEnt_WriteGameState(&msg);
  MSG_WriteByte(&msg, 7);
  MSG_WriteShort(&msg, 1023);
  MSG_WriteByte(&msg, 8);
  Rope_WriteGameState(&msg);
  MSG_WriteByte(&msg, 9);
  GlassCl_WriteDemoSnapshot(&msg);
  MSG_WriteInt64(&msg, 0i64);
  Com_GametypeSettings_Write(&msg);
  v7 = LUI_CoD_GetChecksum();
  MSG_WriteLong(&msg, v7);
  MSG_WriteByte(&msg, 14);
  if ( msg.cursize < 4
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
          4799,
          0,
          "(msg.cursize >= 4)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  MSG_Embed(&demo.playback->clipRecordingMsg, &msg);
  Demo_Printf(
    1024,
    "DEMO: Clip Gamestate Type: %d Client: %d Size: %d msgSeq: 0\n",
    3,
    LocalClientConnection[1],
    msg.cursize);
}

#endif // __UNIMPLEMENTED__
