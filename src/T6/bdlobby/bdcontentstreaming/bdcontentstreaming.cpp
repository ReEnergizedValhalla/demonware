// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x92E710
ClientNum_t __cdecl Demo_GetDefaultClient()
{
  return demo.header.defaultClient;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x92E720
bool __cdecl Demo_IsGameStateWritten()
{
  return demo.gameStateWritten;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x92E730
void __cdecl Demo_WriteHeader(msg_t *msg, bool isDemoClip)
{
  MSG_WriteByte(msg, demo.header.version);
  MSG_WriteByte(msg, demo.header.maxClients);
  MSG_WriteLong(msg, demo.header.defaultClient);
  if ( isDemoClip )
    MSG_WriteBit1(msg);
  else
    MSG_WriteBit0(msg);
  if ( demo.header.hasExtraNetworkProfileData )
    MSG_WriteBit1(msg);
  else
    MSG_WriteBit0(msg);
  if ( demo.header.isZombie )
    MSG_WriteBit1(msg);
  else
    MSG_WriteBit0(msg);
  if ( demo.header.settings.onlinegame )
    MSG_WriteBit1(msg);
  else
    MSG_WriteBit0(msg);
  if ( demo.header.settings.xblive_privatematch )
    MSG_WriteBit1(msg);
  else
    MSG_WriteBit0(msg);
  if ( demo.header.settings.xblive_wagermatch )
    MSG_WriteBit1(msg);
  else
    MSG_WriteBit0(msg);
  if ( demo.header.settings.systemlink )
    MSG_WriteBit1(msg);
  else
    MSG_WriteBit0(msg);
  if ( demo.header.settings.isClientConsole )
    MSG_WriteBit1(msg);
  else
    MSG_WriteBit0(msg);
  if ( demo.header.settings.isDedicatedServer )
    MSG_WriteBit1(msg);
  else
    MSG_WriteBit0(msg);
  Com_GametypeSettings_Write(msg);
  Demo_Printf(3, "DEMO Header: Version: %d\n", demo.header.version);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x92E860
bool __usercall Demo_ShouldFilterServerCommand@<al>(ClientNum_t clientNum@<eax>, const char *cmd)
{
  parseInfo_t *v3; // eax
  parseInfo_t *v5; // edi
  int v6; // eax
  int v7; // ecx
  int v8; // eax

  v3 = Com_Parse(&cmd);
  switch ( v3->token[0] )
  {
    case '#':
    case '@':
    case 'M':
    case 'N':
    case '_':
    case 'e':
    case 'f':
    case 'm':
    case 'n':
      Demo_Printf(4, "DEMO: w ServerCommands Filtering %s since it has commandType %s\n", cmd, v3->token);
      return 1;
    case '2':
      v5 = Com_Parse(&cmd);
      v6 = atoi(v5->token);
      v7 = demo.playerSessionState[clientNum];
      if ( v7 != 2 && v7 != 3 && demo.snapshot.ps[clientNum].pm_type < 10 )
      {
        if ( v6 == 14 || v6 > 1059 && v6 <= 1061 )
        {
          Demo_Printf(4, "DEMO: w ServerCommands Filtering %s since its a configstring of key %s\n", cmd, v5->token);
          return 1;
        }
        return 0;
      }
      if ( v6 >= 1786 && v6 <= 2041
        || v6 >= 2625 && v6 <= 2688
        || v6 >= 1078 && v6 <= 1589
        || v6 >= 323 && v6 <= 340
        || v6 >= 342 && v6 <= 359 )
      {
        return 0;
      }
      return v6 != 12;
    case 'V':
      return 0;
    default:
      v8 = demo.playerSessionState[clientNum];
      return v8 == 2 || v8 == 3 || demo.snapshot.ps[clientNum].pm_type >= 10;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x92EA00
void __cdecl Demo_WriteServerCommands(msg_t *msg, bool liveStreamNoDelta)
{
  int v2; // edi
  int v3; // esi
  int v4; // ecx
  _DWORD *v5; // ecx
  int v6; // ebx
  int v7; // eax
  int v8; // ebx
  int i; // esi
  client_t *v10; // ebx
  int v11; // eax
  int v12; // [esp+Ch] [ebp-901Ch]
  const char **v13; // [esp+10h] [ebp-9018h]
  int v14; // [esp+10h] [ebp-9018h]
  _DWORD *v15; // [esp+14h] [ebp-9014h]
  int v16; // [esp+1Ch] [ebp-900Ch]
  char v17; // [esp+23h] [ebp-9005h]
  int v18[4608]; // [esp+24h] [ebp-9004h]
  _DWORD dst[4608]; // [esp+4824h] [ebp-4804h] BYREF

  v2 = 0;
  v17 = 0;
  PIXBeginNamedEvent(-16711681, "Demo Recording - Writing Server Commands");
  memset((unsigned __int8 *)dst, 0, sizeof(dst));
  v3 = 0;
  if ( demo.header.maxClients > 0 )
  {
    v4 = 0;
    v12 = 0;
    do
    {
      v5 = (int *)((char *)&svs.clients->header.state + v4);
      v15 = v5;
      if ( *v5 == 5 )
      {
        v6 = demo.lastReliableCommandRecorded[v3] + 1;
        v16 = v6;
        if ( v6 <= v5[5197] )
        {
          do
          {
            v13 = (const char **)&v5[3 * (v6 & 0x7F) + 4813];
            if ( !Demo_ShouldFilterServerCommand((ClientNum_t)v3, *v13) )
            {
              if ( v17 )
              {
                v8 = 0;
                if ( v2 > 0 )
                {
                  while ( I_stricmp(*v13, svs.clients[v18[v8 + 2304]].reliableCommandInfo[v18[v8] & 0x7F].cmd) )
                  {
                    if ( ++v8 >= v2 )
                      goto LABEL_11;
                  }
                  v11 = (v3 >> 5) + 2 * v8;
                  v6 = v16;
                  dst[v11] |= 1 << (v3 & 0x1F);
                  goto LABEL_13;
                }
LABEL_11:
                v6 = v16;
                v18[v2] = v16;
                v7 = (v3 >> 5) + 2 * v2;
              }
              else
              {
                v18[v2] = v6;
                v7 = (v3 >> 5) + 2 * v2;
              }
              v18[v2 + 2304] = v3;
              dst[v7] |= 1 << (v3 & 0x1F);
              ++v2;
            }
LABEL_13:
            v16 = ++v6;
            v5 = v15;
          }
          while ( v6 <= v15[5197] );
        }
        v17 = 1;
        if ( !liveStreamNoDelta )
          demo.lastReliableCommandRecorded[v3] = v5[5197];
      }
      ++v3;
      v4 = v12 + 319872;
      v12 += 319872;
    }
    while ( v3 < demo.header.maxClients );
    if ( v2 > 2304
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\demo\\demo_recording.cpp",
            900,
            0,
            "(numCmds <= 18 * 128)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
  for ( i = 0; i < v2; ++i )
  {
    v10 = &svs.clients[v18[i + 2304]];
    v14 = v18[i];
    MSG_WriteByte(msg, 10);
    MSG_WriteLong(msg, dst[2 * i]);
    MSG_WriteString(msg, v10->reliableCommandInfo[v14 & 0x7F].cmd);
    Demo_Printf(
      4,
      "DEMO: w ServerCommands MaskCmdNum: %i %i CmdString: %s\n",
      dst[2 * i],
      dst[2 * i + 1],
      v10->reliableCommandInfo[v14 & 0x7F].cmd);
  }
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x92ECE0
void __usercall Demo_WriteSnapshotStartData(
        msg_t *msg@<esi>,
        int msgSequence,
        int cmdSequence,
        int serverTime,
        int physicsTime,
        int lastFrame,
        int snapFlags,
        bool liveStreamNoDelta)
{
  MSG_WriteBits(msg, 3, 2);
  MSG_ClearLastReferencedEntity(msg);
  MSG_WriteLong(msg, msgSequence);
  MSG_WriteLong(msg, cmdSequence);
  Demo_WriteServerCommands(msg, liveStreamNoDelta);
  MSG_WriteByte(msg, 12);
  MSG_WriteLong(msg, serverTime);
  MSG_WriteLong(msg, physicsTime);
  MSG_WriteByte(msg, lastFrame);
  MSG_WriteByte(msg, snapFlags);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x92ED50
void __cdecl Demo_WriteMatchState(msg_t *msg, bool liveStreamNoDelta)
{
  int v2; // esi
  int bitsStart; // [esp+8h] [ebp-4h]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  PIXBeginNamedEvent(-16711681, "Demo Recording - Writing MatchState");
  MSG_ClearLastReferencedEntity(msg);
  bitsStart = MSG_GetUsedBitCount(msg);
  if ( liveStreamNoDelta )
  {
    MSG_WriteDeltaMatchState(
      (int)&savedregs,
      &demo_defaultSnapInfo,
      msg,
      svsHeader.time,
      &demo_defaultMatchState,
      svsHeader.matchState);
  }
  else
  {
    MSG_WriteDeltaMatchState(
      (int)&savedregs,
      &demo_defaultSnapInfo,
      msg,
      svsHeader.time,
      &demo.snapshot.matchState,
      svsHeader.matchState);
    qmemcpy(&demo.snapshot.matchState, svsHeader.matchState, sizeof(demo.snapshot.matchState));
  }
  v2 = (MSG_GetUsedBitCount(msg) - bitsStart) / 8;
  Demo_Printf(9, "DEMO: w Type: MatchState Size: %d bytes\n", v2);
  Demo_RecordProfileData(DEMO_PROFILE_MATCHSTATES, v2);
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x92EE20
void __cdecl Demo_WritePlayerStates(msg_t *msg, bool liveStreamNoDelta)
{
  int v2; // ebx
  playerState_s *ps; // edi
  client_t *v4; // esi
  int v5; // eax
  unsigned __int8 *PlayerState; // eax
  int v7; // eax
  int v8; // esi
  int v9; // eax
  unsigned __int8 *v10; // eax
  int UsedBitCount; // [esp+4h] [ebp-5428h]
  playerState_s *v12; // [esp+8h] [ebp-5424h]
  int v13; // [esp+Ch] [ebp-5420h]
  bool v14; // [esp+17h] [ebp-5415h]
  playerState_s dst; // [esp+18h] [ebp-5414h] BYREF
  playerState_s to; // [esp+2A20h] [ebp-2A0Ch] BYREF

  PIXBeginNamedEvent(-16711681, "Demo Recording - Writing PlayerStates");
  v2 = 0;
  v14 = Demo_IsInFinalKillcam();
  if ( demo.header.maxClients > 0 )
  {
    ps = demo.snapshot.ps;
    v13 = 0;
    v12 = demo.snapshot.ps;
    do
    {
      v4 = &svs.clients[v13];
      if ( svs.clients[v13].header.state == 5 && G_GetPlayerState((ClientNum_t)v2) )
      {
        if ( liveStreamNoDelta )
          memcpy((unsigned __int8 *)&dst, (unsigned __int8 *)&demo_defaultPlayerState, sizeof(dst));
        else
          memcpy((unsigned __int8 *)&dst, (unsigned __int8 *)ps, sizeof(dst));
        UsedBitCount = MSG_GetUsedBitCount(msg);
        MSG_WriteBit1(msg);
        v5 = demo.playerSessionState[v2];
        if ( (v5 == 2 || v5 == 3) && ps->pm_type >= 10 || v14 )
        {
          memcpy((unsigned __int8 *)&to, (unsigned __int8 *)ps, sizeof(to));
          to.eFlags |= 2u;
          to.stats[3] = 12;
          if ( v4->gentity->client->sess.archiveTime <= 0 && !v14 )
          {
            qmemcpy(&to.hud, &G_GetPlayerState((ClientNum_t)v2)->ps.hud, 0xF04u);
            ps = v12;
          }
        }
        else
        {
          PlayerState = (unsigned __int8 *)G_GetPlayerState((ClientNum_t)v2);
          memcpy((unsigned __int8 *)&to, PlayerState, sizeof(to));
          v7 = demo.playerSessionState[v2];
          if ( v7 == 2 || v7 == 3 )
          {
            memcpy((unsigned __int8 *)&to, (unsigned __int8 *)&demo_defaultPlayerState, sizeof(to));
            to.origin = demo.intermissionPointOrigin;
            to.viewangles = demo.intermissionPointAngles;
            to.eFlags |= 2u;
            to.clientNum = v2;
            to.pm_type = 5;
            to.stats[3] = 13;
          }
          else
          {
            to.stats[3] = 2 * (ps->pm_type < 10) + 12;
          }
        }
        MSG_WriteDeltaPlayerstate(&demo_defaultSnapInfo, msg, svsHeader.time, &dst, &to);
        v8 = (MSG_GetUsedBitCount(msg) - UsedBitCount) / 8;
        Demo_Printf(17, "DEMO: w Type: PlayerState Client: %d Size: %d bytes\n", v2, v8);
        Demo_RecordProfileData(DEMO_PROFILE_PLAYERSTATES, v8);
        if ( !liveStreamNoDelta )
        {
          v9 = demo.playerSessionState[v2];
          if ( v9 == 2 || v9 == 3 || ps->pm_type >= 10 )
          {
            memcpy((unsigned __int8 *)ps, (unsigned __int8 *)&to, sizeof(playerState_s));
          }
          else
          {
            v10 = (unsigned __int8 *)G_GetPlayerState((ClientNum_t)v2);
            memcpy((unsigned __int8 *)ps, v10, sizeof(playerState_s));
          }
        }
      }
      else
      {
        MSG_WriteBit0(msg);
      }
      ++v13;
      ++v2;
      v12 = ++ps;
    }
    while ( v2 < demo.header.maxClients );
  }
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x92F180
void __cdecl Demo_WritePacketEntities(bool liveStreamNoDelta)
{
  msg_t *msg; // ecx
  int v2; // edi
  msg_t *v3; // esi
  int num_entities; // ebx
  int v5; // ecx
  gentity_t *gentities; // edx
  int number; // eax
  int v8; // esi
  const entityState_s *v9; // esi
  int v10; // edi
  int v11; // eax
  const entityState_s *v12; // edi
  DeltaFlags v13; // ebx
  msg_t *v14; // esi
  unsigned __int8 trType; // al
  const msg_t *v16; // esi
  entityState_s *v17; // edx
  trajectory_t *p_pos; // eax
  char *v19; // ebx
  unsigned __int8 v20; // al
  int time; // edx
  int v22; // eax
  int v23; // eax
  int v24; // [esp+Ch] [ebp-1234h]
  int UsedBitCount; // [esp+10h] [ebp-1230h]
  int v26; // [esp+14h] [ebp-122Ch]
  int value; // [esp+18h] [ebp-1228h]
  int v28; // [esp+20h] [ebp-1220h]
  msg_t *v29; // [esp+28h] [ebp-1218h]
  const entityState_s *v30; // [esp+2Ch] [ebp-1214h]
  int v31; // [esp+30h] [ebp-1210h]
  int v32; // [esp+34h] [ebp-120Ch]
  entityState_s *ent; // [esp+38h] [ebp-1208h]
  int v34; // [esp+3Ch] [ebp-1204h]
  entityState_s *from; // [esp+40h] [ebp-1200h]
  entityState_s *froma; // [esp+40h] [ebp-1200h]
  int v37; // [esp+44h] [ebp-11FCh]
  int v38; // [esp+48h] [ebp-11F8h]
  trajectory_t *i; // [esp+48h] [ebp-11F8h]
  unsigned __int8 dst[248]; // [esp+4Ch] [ebp-11F4h] BYREF
  entityState_s to; // [esp+144h] [ebp-10FCh] BYREF
  int v42[1024]; // [esp+23Ch] [ebp-1004h]

  v2 = 0;
  v3 = msg;
  v29 = msg;
  v32 = 0;
  v37 = 0;
  v34 = 0;
  PIXBeginNamedEvent(-16711681, "Demo Recording - Writing EntityStates");
  memset(dst, 0, sizeof(dst));
  num_entities = sv.num_entities;
  v5 = 0;
  if ( sv.num_entities > 0 )
  {
    gentities = sv.gentities;
    do
    {
      if ( gentities->r.linked && (gentities->r.broadcastTime || (gentities->r.svFlags & 1) == 0) )
      {
        number = gentities->s.number;
        if ( gentities->s.number >= 18
          || (v8 = demo.playerSessionState[number], v8 != 2) && v8 != 3 && demo.snapshot.ps[number].pm_type < 10 )
        {
          v42[v2++] = v5;
        }
      }
      gentities = (gentity_t *)((char *)gentities + sv.gentitySize);
      ++v5;
    }
    while ( v5 < num_entities );
    v3 = v29;
    v32 = v2;
  }
  v24 = liveStreamNoDelta ? 0 : demo.snapshot.prevNumEntities;
  UsedBitCount = MSG_GetUsedBitCount(v3);
  MSG_ClearLastReferencedEntity(v3);
  MSG_WriteBits(v3, v2, 11);
  ent = demo.snapshot.ent;
  while ( v37 < v24 || v34 < v2 )
  {
    v9 = (entityState_s *)((char *)&sv.gentities->s + sv.gentitySize * v42[v34]);
    if ( v34 < v2 )
    {
      v38 = v9->number;
      v10 = v9->number;
    }
    else
    {
      v10 = 9999;
      v38 = 9999;
    }
    if ( v37 < v24 )
    {
      v31 = ent->number;
      v11 = ent->number;
    }
    else
    {
      v11 = 9999;
      v31 = 9999;
    }
    if ( v10 == v11 )
    {
      from = ent;
      v12 = (entityState_s *)((char *)&sv.gentities->s + sv.gentitySize * v42[v34]);
      v30 = v12;
      v13 = DELTA_FLAGS_NONE;
      v28 = demo.snapshot.entClientMask[v37][0];
      value = v9->clientMask[0];
      Demo_Printf(32, "EntityState: OldNum = NewNum = %d\n", v11);
    }
    else
    {
      if ( v10 >= v11 )
      {
        from = ent;
        v13 = DELTA_FLAGS_FORCE;
        v30 = 0;
        v28 = demo.snapshot.entClientMask[v37][0];
        value = 0;
        Demo_Printf(32, "EntityState: NewNum (%d) > OldNum (%d). Entity is removed\n", v10, v11);
        v12 = 0;
        goto LABEL_26;
      }
      *(_DWORD *)dst = v10;
      from = (entityState_s *)dst;
      v30 = v9;
      if ( v10 != v9->number )
      {
        if ( !Assert_MyHandler(
                "c:\\t6\\code\\src_noserver\\demo\\demo_recording.cpp",
                1207,
                0,
                "(newEntNum == newEnt->number)",
                (const char *)&pBlock) )
          __debugbreak();
        v11 = v31;
      }
      demo_defaultSnapInfo.fromBaseline = 1;
      v13 = DELTA_FLAGS_FORCE;
      v28 = 0;
      value = v9->clientMask[0];
      Demo_Printf(32, "EntityState: NewNum (%d) < OldNum (%d). Writing with baselines\n", v10, v11);
      v12 = v9;
    }
    if ( v28 != value )
      v13 = DELTA_FLAGS_FORCE;
LABEL_26:
    v14 = v29;
    v26 = MSG_GetUsedBitCount(v29);
    if ( !v12
      || (trType = v12->lerp.pos.trType) == 0
      || trType == 1
      || trType == 14
      || trType == 10
      || !Dvar_GetBool(demo_recordStaticEntityPositions) )
    {
      MSG_WriteEntity(&demo_defaultSnapInfo, v29, 0, 0, svsHeader.time, from, v12, v13);
    }
    else
    {
      qmemcpy(&to, v12, sizeof(to));
      BG_EvaluateTrajectory(&v30->lerp.pos, svsHeader.time, &to.lerp.pos.trBase);
      to.lerp.pos.trTime = svsHeader.time;
      to.lerp.pos.trType = 1;
      memset(&to.lerp.pos.trDelta, 0, sizeof(to.lerp.pos.trDelta));
      MSG_WriteEntity(&demo_defaultSnapInfo, v29, 0, 0, svsHeader.time, from, &to, v13);
      v12 = v30;
      v14 = v29;
    }
    demo_defaultSnapInfo.fromBaseline = 0;
    if ( MSG_GetUsedBitCount(v14) != v26 )
    {
      if ( v12 )
      {
        if ( v28 == value )
        {
          MSG_WriteBit0(v14);
          Demo_Printf(32, "OldClientMask: (%d) == NewClientMask: (%d). So, writing clientMask bit 0.\n", v28, value);
        }
        else
        {
          MSG_WriteBit1(v14);
          MSG_WriteBits(v14, value, 18);
          Demo_Printf(32, "Writing ClientMask (%d) for entity %d\n", value, v38);
        }
      }
      else
      {
        MSG_WriteBit0(v14);
        demo.snapshot.entClientMask[v37][0] = 0;
        demo.snapshot.entClientMask[v37][1] = 0;
        Demo_Printf(32, "Entity %d is removed. So, writing clientMask bit 0.\n", v31);
      }
    }
    v2 = v32;
    if ( v38 == v31 )
    {
      ++ent;
      ++v37;
      ++v34;
    }
    else if ( v38 >= v31 )
    {
      ++v37;
      ++ent;
    }
    else
    {
      ++v34;
    }
  }
  v16 = v29;
  MSG_WriteEntityIndex(&demo_defaultSnapInfo, v29, 1023, 10);
  if ( !liveStreamNoDelta )
  {
    v17 = 0;
    froma = 0;
    if ( v2 > 0 )
    {
      p_pos = &demo.snapshot.ent[0].lerp.pos;
      for ( i = &demo.snapshot.ent[0].lerp.pos; ; p_pos = i )
      {
        v19 = (char *)sv.gentities + sv.gentitySize * v42[(_DWORD)v17];
        qmemcpy(&p_pos[-1].trDelta, v19, 0xF8u);
        demo.snapshot.entClientMask[(_DWORD)v17][0] = *((_DWORD *)v19 + 47);
        v20 = p_pos->trType;
        if ( v20 && v20 != 1 && v20 != 14 && v20 != 10 )
        {
          if ( Dvar_GetBool(demo_recordStaticEntityPositions) )
          {
            BG_EvaluateTrajectory((const trajectory_t *)(v19 + 12), svsHeader.time, &i->trBase);
            time = svsHeader.time;
            i->trType = 1;
            i->trDelta.x = 0.0;
            i->trDelta.y = 0.0;
            i->trDelta.z = 0.0;
            i->trTime = time;
          }
          v17 = froma;
        }
        i = (trajectory_t *)((char *)i + 248);
        v17 = (entityState_s *)((char *)v17 + 1);
        froma = v17;
        if ( (int)v17 >= v32 )
          break;
      }
      v2 = v32;
    }
    v16 = v29;
    demo.snapshot.prevNumEntities = v2;
  }
  v22 = MSG_GetUsedBitCount(v16);
  Demo_Printf(33, "DEMO: w Type: PacketEntities NumEntities: %d FirstEntity: 0 Size: %d bits\n", v2, v22 - UsedBitCount);
  v23 = MSG_GetUsedBitCount(v16);
  Demo_RecordProfileData(DEMO_PROFILE_ENTITIES, (v23 - UsedBitCount) / 8);
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x92F780
void __usercall Demo_InfoPlayerConnected(ClientNum_t clientNum@<edi>)
{
  clientState_s *ClientState; // eax
  int v2; // ecx
  clientState_s *v3; // ebx
  int v4; // esi
  int time; // eax
  bool v6; // zf
  unsigned __int64 v7; // [esp-14h] [ebp-18h]
  int index; // [esp+0h] [ebp-4h]

  index = demo.footer.numConnectedPlayers;
  if ( demo.footer.numConnectedPlayers < 50 )
  {
    ClientState = G_GetClientState(clientNum);
    v2 = svs.xuids[clientNum];
    v3 = ClientState;
    v4 = index;
    HIDWORD(v7) = HIDWORD(svs.xuids[clientNum]);
    demo.footer.connectedPlayers[v4].playerIndex = index;
    time = svs.time;
    LODWORD(v7) = v2;
    demo.footer.connectedPlayers[v4].clientNum = clientNum;
    demo.footer.connectedPlayers[v4].connectTime = time;
    LODWORD(demo.footer.connectedPlayers[v4].xuid) = v2;
    HIDWORD(demo.footer.connectedPlayers[v4].xuid) = HIDWORD(v7);
    demo.footer.connectedPlayers[v4].assignedTeam = Party_GetAssignedTeam(&g_lobbyData, v7);
    demo.footer.connectedPlayers[v4].assignedFFATeam = TEAM_FFA_NONE;
    LODWORD(demo.footer.connectedPlayers[v4].leagueTeamID) = v3->leagueTeamID64.low;
    HIDWORD(demo.footer.connectedPlayers[v4].leagueTeamID) = v3->leagueTeamID64.high;
    LODWORD(demo.footer.connectedPlayers[v4].leagueSubdivisionID) = v3->leagueSubdivisionID64.low;
    v6 = demo.footer.connectedPlayers[index].clientNum == clientNum;
    HIDWORD(demo.footer.connectedPlayers[v4].leagueSubdivisionID) = v3->leagueSubdivisionID64.high;
    if ( !v6
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\demo\\demo_recording.cpp",
            1415,
            0,
            "(demo.footer.connectedPlayers[index].clientNum == clientNum)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    Demo_Printf(256, "DEMO Info: Player Index: %d ClientNum: %d Connect Time: %d\n", index, clientNum, svs.time);
    ++demo.footer.numConnectedPlayers;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x92F880
void __cdecl Demo_UpdatePlayerDisconnectInformation(ClientNum_t clientNum, int playerIndex)
{
  int time; // ebx
  team_t team; // edx
  ffa_team_t ffaTeam; // ecx

  if ( playerIndex == -1
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_recording.cpp",
          1431,
          0,
          "(playerIndex != -1)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  time = svs.time;
  demo.footer.connectedPlayers[playerIndex].disconnectTime = svs.time;
  team = demo.snapshot.client[clientNum].team;
  if ( demo.footer.connectedPlayers[playerIndex].assignedTeam != team && team != TEAM_NUM_PLAYING_TEAMS )
    demo.footer.connectedPlayers[playerIndex].assignedTeam = team;
  ffaTeam = demo.snapshot.client[clientNum].ffaTeam;
  if ( demo.footer.connectedPlayers[playerIndex].assignedFFATeam != ffaTeam )
    demo.footer.connectedPlayers[playerIndex].assignedFFATeam = ffaTeam;
  Demo_Printf(256, "DEMO Info: Player Index: %d ClientNum: %d Disconnected Time: %d\n", playerIndex, clientNum, time);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x92F920
void __usercall Demo_InfoPlayerDisconnected(ClientNum_t clientNum@<edi>)
{
  int numConnectedPlayers; // ecx
  int v2; // esi
  int time; // ebx
  int *p_connectTime; // eax
  team_t team; // edx
  ffa_team_t ffaTeam; // ecx

  numConnectedPlayers = demo.footer.numConnectedPlayers;
  v2 = -1;
  if ( demo.footer.numConnectedPlayers <= 0 )
    goto LABEL_20;
  time = svs.time;
  p_connectTime = &demo.footer.connectedPlayers[0].connectTime;
  do
  {
    if ( *(p_connectTime - 3) == clientNum && *p_connectTime < svs.time && !p_connectTime[1] )
      v2 = *((unsigned __int8 *)p_connectTime - 16);
    p_connectTime += 12;
    --numConnectedPlayers;
  }
  while ( numConnectedPlayers );
  if ( v2 == -1 )
  {
LABEL_20:
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\demo\\demo_recording.cpp",
            1431,
            0,
            "(playerIndex != -1)",
            (const char *)&pBlock) )
      __debugbreak();
    time = svs.time;
  }
  demo.footer.connectedPlayers[v2].disconnectTime = time;
  team = demo.snapshot.client[clientNum].team;
  if ( demo.footer.connectedPlayers[v2].assignedTeam != team && team != TEAM_NUM_PLAYING_TEAMS )
    demo.footer.connectedPlayers[v2].assignedTeam = team;
  ffaTeam = demo.snapshot.client[clientNum].ffaTeam;
  if ( demo.footer.connectedPlayers[v2].assignedFFATeam != ffaTeam )
    demo.footer.connectedPlayers[v2].assignedFFATeam = ffaTeam;
  Demo_Printf(256, "DEMO Info: Player Index: %d ClientNum: %d Disconnected Time: %d\n", v2, clientNum, time);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x92F9E0
void __cdecl Demo_WritePacketClients(bool liveStreamNoDelta)
{
  msg_t *msg; // ecx
  int v2; // esi
  msg_t *v3; // edi
  int maxClients; // ecx
  ClientNum_t v5; // eax
  client_t *clients; // edx
  clientState_s *client; // edi
  ClientNum_t v8; // ebx
  ClientNum_t clientIndex; // esi
  bool v10; // zf
  bool v11; // cc
  int v12; // ebx
  clientState_s *ClientState; // eax
  clientState_s *v14; // edi
  int UsedBitCount; // eax
  int v16; // eax
  int initBitsUsed; // [esp+Ch] [ebp-74h]
  int prevNumClients; // [esp+10h] [ebp-70h]
  msg_t *v19; // [esp+14h] [ebp-6Ch]
  int forceWrite; // [esp+18h] [ebp-68h]
  clientState_s *newClient; // [esp+1Ch] [ebp-64h]
  clientState_s *v22; // [esp+20h] [ebp-60h]
  ClientNum_t oldIndex; // [esp+24h] [ebp-5Ch]
  int numClients; // [esp+28h] [ebp-58h]
  clientState_s *oldClient; // [esp+2Ch] [ebp-54h]
  clientState_s *oldClienta; // [esp+2Ch] [ebp-54h]
  ClientNum_t newIndex; // [esp+30h] [ebp-50h]
  ClientNum_t clientNums[18]; // [esp+34h] [ebp-4Ch]

  v2 = 0;
  v3 = msg;
  v19 = msg;
  numClients = 0;
  oldIndex = CLIENT_INDEX_FIRST;
  newIndex = CLIENT_INDEX_FIRST;
  PIXBeginNamedEvent(-16711681, "Demo Recording - Writing ClientStates");
  maxClients = demo.header.maxClients;
  v5 = CLIENT_INDEX_FIRST;
  if ( demo.header.maxClients > 0 )
  {
    clients = svs.clients;
    do
    {
      if ( clients->header.state >= 5 )
        clientNums[v2++] = v5;
      ++v5;
      ++clients;
    }
    while ( v5 < maxClients );
    numClients = v2;
  }
  prevNumClients = liveStreamNoDelta ? 0 : demo.snapshot.prevNumClients;
  initBitsUsed = MSG_GetUsedBitCount(v3);
  MSG_ClearLastReferencedEntity(v3);
  MSG_WriteBits(v3, v2, 5);
  client = demo.snapshot.client;
LABEL_8:
  v22 = client;
  while ( oldIndex < prevNumClients )
  {
    if ( newIndex < v2 )
      goto LABEL_11;
    v8 = 9999;
LABEL_12:
    clientIndex = 9999;
    if ( oldIndex < prevNumClients )
      clientIndex = client->clientIndex;
    if ( v8 == clientIndex )
    {
      oldClient = client;
      newClient = G_GetClientState(clientNums[newIndex]);
      forceWrite = 0;
      Demo_Printf(64, "ClientState: OldNum = NewNum = %d\n", clientIndex);
    }
    else
    {
      if ( v8 >= clientIndex )
      {
        oldClient = client;
        newClient = 0;
        forceWrite = 1;
        Demo_InfoPlayerDisconnected(clientIndex);
        Demo_Printf(64, "ClientState: NewNum (%d) > OldNum (%d). Client is removed\n", v8, clientIndex);
      }
      else
      {
        oldClient = 0;
        newClient = G_GetClientState(clientNums[newIndex]);
        forceWrite = 1;
        Demo_InfoPlayerConnected(v8);
        Demo_Printf(64, "ClientState: NewNum (%d) < OldNum (%d). Writing with baselines\n", v8, clientIndex);
      }
      client = v22;
    }
    MSG_WriteDeltaClient(&demo_defaultSnapInfo, v19, svsHeader.time, oldClient, newClient, forceWrite);
    v10 = v8 == clientIndex;
    v11 = v8 < clientIndex;
    v2 = numClients;
    if ( v10 )
    {
      ++oldIndex;
      ++client;
      ++newIndex;
      goto LABEL_8;
    }
    if ( !v11 )
    {
      ++oldIndex;
      ++client;
      goto LABEL_8;
    }
    ++newIndex;
  }
  if ( newIndex < v2 )
  {
LABEL_11:
    v8 = G_GetClientState(clientNums[newIndex])->clientIndex;
    goto LABEL_12;
  }
  MSG_WriteBit0(v19);
  if ( !liveStreamNoDelta )
  {
    v12 = 0;
    if ( v2 > 0 )
    {
      oldClienta = demo.snapshot.client;
      do
      {
        ClientState = G_GetClientState(clientNums[v12]);
        v14 = oldClienta++;
        ++v12;
        qmemcpy(v14, ClientState, sizeof(clientState_s));
      }
      while ( v12 < numClients );
      v2 = numClients;
    }
    demo.snapshot.prevNumClients = v2;
  }
  UsedBitCount = MSG_GetUsedBitCount(v19);
  Demo_Printf(
    65,
    "DEMO: w Type: PacketClients NumClients: %d FirstClient: 0 Size: %d bits\n",
    v2,
    UsedBitCount - initBitsUsed);
  v16 = MSG_GetUsedBitCount(v19);
  Demo_RecordProfileData(DEMO_PROFILE_CLIENTS, (v16 - initBitsUsed) / 8);
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x92FC50
void __cdecl Demo_WritePacketActors(bool liveStreamNoDelta)
{
  msg_t *msg; // ecx
  msg_t *v2; // edi
  int v3; // ebx
  int v4; // esi
  actor_t *gameActors; // ecx
  int i; // eax
  int v7; // edi
  int actorIndex; // esi
  actorState_s *ActorState; // ebx
  int v10; // edi
  bool v11; // zf
  bool v12; // cc
  const msg_t *v13; // edi
  int v14; // ebx
  actorState_s *v15; // eax
  actorState_s *v16; // edi
  int UsedBitCount; // eax
  int v18; // eax
  const char *v19; // [esp-Ch] [ebp-C0h]
  int v20; // [esp-8h] [ebp-BCh]
  int v21; // [esp-4h] [ebp-B8h]
  int initBitsUsed; // [esp+Ch] [ebp-A8h]
  int prevNumActors; // [esp+10h] [ebp-A4h]
  msg_t *v24; // [esp+14h] [ebp-A0h]
  int newActorNum; // [esp+18h] [ebp-9Ch]
  int numActors; // [esp+1Ch] [ebp-98h]
  int oldIndex; // [esp+20h] [ebp-94h]
  actorState_s *actor; // [esp+24h] [ebp-90h]
  int newIndex; // [esp+28h] [ebp-8Ch]
  actorState_s *oldActor; // [esp+2Ch] [ebp-88h]
  actorState_s *oldActora; // [esp+2Ch] [ebp-88h]
  int actors[32]; // [esp+30h] [ebp-84h]

  v2 = msg;
  v3 = 0;
  v24 = msg;
  v4 = 0;
  oldIndex = 0;
  newIndex = 0;
  PIXBeginNamedEvent(-16711681, "Demo Recording - Writing ActorStates");
  gameActors = sv.gameActors;
  for ( i = 0; i < 32; ++i )
  {
    if ( (*(_BYTE *)&gameActors->flags.0 & 1) != 0 )
      actors[v4++] = i;
    ++gameActors;
  }
  numActors = v4;
  prevNumActors = liveStreamNoDelta ? 0 : demo.snapshot.prevNumActors;
  initBitsUsed = MSG_GetUsedBitCount(v2);
  MSG_ClearLastReferencedEntity(v2);
  MSG_WriteLong(v2, v4);
  actor = demo.snapshot.actor;
  while ( oldIndex < prevNumActors )
  {
    if ( v3 < v4 )
      goto LABEL_8;
    v7 = 9999;
    newActorNum = 9999;
LABEL_9:
    actorIndex = 9999;
    if ( oldIndex < prevNumActors )
      actorIndex = actor->actorIndex;
    if ( v7 == actorIndex )
    {
      oldActor = actor;
      ActorState = G_GetActorState(actors[v3]);
      v10 = 0;
      Demo_Printf(2048, "ActorState: OldNum = NewNum = %d\n", actorIndex);
    }
    else
    {
      if ( v7 >= actorIndex )
      {
        v21 = actorIndex;
        v20 = newActorNum;
        oldActor = actor;
        ActorState = 0;
        v19 = "ActorState: NewNum (%d) > OldNum (%d). Actor is removed\n";
      }
      else
      {
        oldActor = 0;
        ActorState = G_GetActorState(actors[v3]);
        if ( v7 != ActorState->actorIndex
          && !Assert_MyHandler(
                "c:\\t6\\code\\src_noserver\\demo\\demo_recording.cpp",
                1674,
                0,
                "(newActorNum == newActor->actorIndex)",
                (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v21 = actorIndex;
        v20 = newActorNum;
        demo_defaultSnapInfo.fromBaseline = 1;
        v19 = "ActorState: NewNum (%d) < OldNum (%d). Writing with baselines\n";
      }
      v10 = 1;
      Demo_Printf(2048, v19, v20, v21);
    }
    MSG_GetUsedBitCount(v24);
    MSG_WriteDeltaActor(&demo_defaultSnapInfo, v24, svsHeader.time, oldActor, ActorState, v10);
    v11 = newActorNum == actorIndex;
    v12 = newActorNum < actorIndex;
    v4 = numActors;
    demo_defaultSnapInfo.fromBaseline = 0;
    if ( v11 )
    {
      ++actor;
      ++oldIndex;
      v3 = ++newIndex;
    }
    else
    {
      if ( v12 )
      {
        ++newIndex;
      }
      else
      {
        ++oldIndex;
        ++actor;
      }
      v3 = newIndex;
    }
  }
  if ( v3 < v4 )
  {
LABEL_8:
    newActorNum = G_GetActorState(actors[v3])->actorIndex;
    v7 = newActorNum;
    goto LABEL_9;
  }
  v13 = v24;
  MSG_WriteBit0(v24);
  if ( !liveStreamNoDelta )
  {
    v14 = 0;
    if ( v4 > 0 )
    {
      oldActora = demo.snapshot.actor;
      do
      {
        v15 = G_GetActorState(actors[v14]);
        v16 = oldActora++;
        ++v14;
        qmemcpy(v16, v15, sizeof(actorState_s));
      }
      while ( v14 < numActors );
      v4 = numActors;
    }
    v13 = v24;
    demo.snapshot.prevNumActors = v4;
  }
  UsedBitCount = MSG_GetUsedBitCount(v13);
  Demo_Printf(
    2049,
    "DEMO: w Type: PacketActors NumActors: %d FirstActor: 0 Size: %d\n",
    v4,
    UsedBitCount - initBitsUsed);
  v18 = MSG_GetUsedBitCount(v13);
  Demo_RecordProfileData(DEMO_PROFILE_ACTORS, (v18 - initBitsUsed) / 8);
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x92FF50
void __usercall Demo_WriteSpawnDebugBuffer(msg_t *msg@<esi>, bool liveStreamNoDelta)
{
  PIXBeginNamedEvent(-16711681, "Demo Recording - Writing Spawn Debug Buffer");
  if ( !liveStreamNoDelta && demo.spawnDebugBufferPos > 0 )
  {
    MSG_WriteBit1(msg);
    MSG_WriteShort(msg, demo.spawnDebugBufferPos);
    MSG_WriteData(msg, demo.spawnDebugBuffer, demo.spawnDebugBufferPos);
    demo.spawnDebugBufferPos = 0;
  }
  MSG_WriteBit0(msg);
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x92FFC0
void __cdecl Demo_LogClientPacket(netchan_t *pChan, int iSize, int bFragment)
{
  int v3; // edi
  int v4; // esi
  int v5; // eax
  int demoPacketCount; // ecx
  int v7; // ecx

  if ( Demo_IsRecording() && demo.header.hasExtraNetworkProfileData && svs.clients )
  {
    v3 = 0;
    v4 = 0;
    while ( !IsTheSameAddr(pChan->remoteAddress, svs.clients[v4 / 0x4E180u].header.netchan.remoteAddress) )
    {
      v4 += 319872;
      ++v3;
      if ( v4 >= (int)&off_57DB00 )
        return;
    }
    v5 = v3;
    demoPacketCount = svs.clients[v3].demoPacketCount;
    if ( demoPacketCount >= 8 )
    {
      svs.clients[v5].demoPacketSizes[7] += iSize;
    }
    else
    {
      v7 = 79968 * v3 + demoPacketCount;
      svs.clients->demoPacketSizes[v7] = iSize;
      svs.clients->demoPacketIsFragment[v7] = bFragment;
      ++svs.clients[v5].demoPacketCount;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x9300D0
void __cdecl Demo_LogReliableCmd(ClientNum_t cl, int iSize, char cmdChar)
{
  ClientNum_t v3; // eax
  client_t *clients; // edi
  int v5; // ecx
  int *v6; // edi
  int demoReliableCmdCount; // edx
  int *v8; // ecx

  if ( Demo_IsRecording() && demo.header.hasExtraNetworkProfileData && svs.clients )
  {
    v3 = cl;
    svs.clients[cl].demoReliableCmdSize += iSize;
    clients = svs.clients;
    v5 = 0;
    if ( svs.clients[cl].demoReliableCmdCount > 0 )
    {
      while ( svs.clients[v3].demoReliableCmdItemChars[v5] != cmdChar )
      {
        if ( ++v5 >= svs.clients[v3].demoReliableCmdCount )
          goto LABEL_9;
      }
      v6 = &svs.clients[cl].demoReliableCmdItemSize[v5];
      *v6 += iSize;
      clients = svs.clients;
    }
LABEL_9:
    demoReliableCmdCount = clients[v3].demoReliableCmdCount;
    if ( v5 == demoReliableCmdCount && demoReliableCmdCount < 16 )
    {
      clients[v3].demoReliableCmdItemChars[demoReliableCmdCount] = cmdChar;
      v8 = &svs.clients[cl].demoReliableCmdItemSize[svs.clients[v3].demoReliableCmdCount];
      *v8 += iSize;
      ++svs.clients[v3].demoReliableCmdCount;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x9301B0
void __cdecl Demo_WriteExtraNetworkProfileData(msg_t *msg)
{
  msg_t *v1; // esi
  int VOIPWrittenBits; // eax
  int VOIPReadBits; // eax
  int DemoUploadBits; // eax
  int k; // edi
  int ClientUploadBits; // eax
  int v7; // edi
  int v8; // ebx
  int v9; // ebx
  int v10; // edi
  int v11; // ebx
  int *demoPacketSizes; // eax
  int *demoPacketIsFragment; // eax
  int v14; // ebx
  int v15; // edi
  client_t *clients; // eax
  int v17; // ebx
  char *demoReliableCmdItemChars; // eax
  int i; // [esp+Ch] [ebp-8h]
  int ia; // [esp+Ch] [ebp-8h]
  int j; // [esp+10h] [ebp-4h]
  int ja; // [esp+10h] [ebp-4h]

  if ( SV_PacketAnalyze_GetVOIPWrittenBits() || SV_PacketAnalyze_GetVOIPReadBits() )
  {
    v1 = msg;
    MSG_WriteBit1(msg);
    VOIPWrittenBits = SV_PacketAnalyze_GetVOIPWrittenBits();
    MSG_WriteLong(msg, VOIPWrittenBits);
    VOIPReadBits = SV_PacketAnalyze_GetVOIPReadBits();
    MSG_WriteLong(msg, VOIPReadBits);
    SV_PacketAnalyze_ClearVoipBits();
  }
  else
  {
    v1 = msg;
    MSG_WriteBit0(msg);
  }
  if ( SV_PacketAnalyze_GetDemoUploadBits() )
  {
    MSG_WriteBit1(v1);
    DemoUploadBits = SV_PacketAnalyze_GetDemoUploadBits();
    MSG_WriteLong(v1, DemoUploadBits);
    SV_PacketAnalyze_ClearDemoUploadBits();
  }
  else
  {
    MSG_WriteBit0(v1);
  }
  for ( k = 0; k < 18; ++k )
  {
    if ( SV_PacketAnalyze_GetClientUploadBits((ClientNum_t)k) )
    {
      MSG_WriteBit1(v1);
      MSG_WriteBits(v1, k, 5);
      ClientUploadBits = SV_PacketAnalyze_GetClientUploadBits((ClientNum_t)k);
      MSG_WriteLong(v1, ClientUploadBits);
    }
  }
  SV_PacketAnalyze_ClearClientUploadBits();
  MSG_WriteBit0(v1);
  if ( svs.clients )
  {
    v7 = 0;
    if ( demo.header.maxClients > 0 )
    {
      v8 = 0;
      do
      {
        if ( svs.clients[v8].header.state == 5 )
        {
          MSG_WriteBit1(v1);
          MSG_WriteBits(v1, v7, 5);
          MSG_WriteShort(v1, svs.clients[v8].ping);
        }
        ++v7;
        ++v8;
      }
      while ( v7 < demo.header.maxClients );
    }
  }
  MSG_WriteBit0(v1);
  if ( svs.clients )
  {
    v9 = 0;
    i = 0;
    if ( demo.header.maxClients > 0 )
    {
      v10 = 0;
      do
      {
        if ( svs.clients[v10].demoPacketCount > 0 )
        {
          MSG_WriteBit1(v1);
          MSG_WriteBits(v1, v9, 5);
          j = 0;
          if ( svs.clients[v10].demoPacketCount > 0 )
          {
            v11 = v10 * 319872 + 319652;
            do
            {
              MSG_WriteBit1(v1);
              MSG_WriteLong(v1, *(_DWORD *)((char *)svs.clients + v11 - 32));
              if ( *(int *)((char *)&svs.clients->header.state + v11) )
                MSG_WriteBit1(v1);
              else
                MSG_WriteBit0(v1);
              v11 += 4;
              ++j;
            }
            while ( j < svs.clients[v10].demoPacketCount );
            v9 = i;
          }
          MSG_WriteBit0(v1);
          demoPacketSizes = svs.clients[v10].demoPacketSizes;
          *(_QWORD *)demoPacketSizes = 0i64;
          *((_QWORD *)demoPacketSizes + 1) = 0i64;
          *((_QWORD *)demoPacketSizes + 2) = 0i64;
          *((_QWORD *)demoPacketSizes + 3) = 0i64;
          demoPacketIsFragment = svs.clients[v10].demoPacketIsFragment;
          *(_QWORD *)demoPacketIsFragment = 0i64;
          *((_QWORD *)demoPacketIsFragment + 1) = 0i64;
          *((_QWORD *)demoPacketIsFragment + 2) = 0i64;
          *((_QWORD *)demoPacketIsFragment + 3) = 0i64;
          svs.clients[v10].demoPacketCount = 0;
        }
        ++v9;
        ++v10;
        i = v9;
      }
      while ( v9 < demo.header.maxClients );
    }
  }
  MSG_WriteBit0(v1);
  if ( svs.clients )
  {
    v14 = 0;
    ia = 0;
    if ( demo.header.maxClients > 0 )
    {
      v15 = 0;
      do
      {
        if ( svs.clients[v15].demoReliableCmdSize > 0 )
        {
          MSG_WriteBit1(v1);
          MSG_WriteBits(v1, v14, 5);
          MSG_WriteLong(v1, svs.clients[v15].demoReliableCmdSize);
          MSG_WriteShort(v1, svs.clients[v15].demoReliableCmdCount);
          clients = svs.clients;
          v17 = 0;
          if ( svs.clients[v15].demoReliableCmdCount > 0 )
          {
            ja = v15 * 319872 + 319704;
            do
            {
              MSG_WriteByte(v1, clients[v15].demoReliableCmdItemChars[v17]);
              MSG_WriteShort(v1, *(int *)((char *)&svs.clients->header.state + ja));
              clients = svs.clients;
              ja += 4;
              ++v17;
            }
            while ( v17 < svs.clients[v15].demoReliableCmdCount );
          }
          clients[v15].demoReliableCmdSize = 0;
          svs.clients[v15].demoReliableCmdCount = 0;
          demoReliableCmdItemChars = svs.clients[v15].demoReliableCmdItemChars;
          *(_QWORD *)demoReliableCmdItemChars = 0i64;
          *((_QWORD *)demoReliableCmdItemChars + 1) = 0i64;
          memset(
            (unsigned __int8 *)svs.clients[v15].demoReliableCmdItemSize,
            0,
            sizeof(svs.clients[v15].demoReliableCmdItemSize));
          v14 = ia;
        }
        ++v14;
        ++v15;
        ia = v14;
      }
      while ( v14 < demo.header.maxClients );
    }
  }
  MSG_WriteBit0(v1);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x930560
void __cdecl Demo_BuildDemoSnapshotInternal(msg_t *msg, bool liveStreamNoDelta)
{
  int lastProcessedMsgNum; // edi
  int v3; // ebx
  int UsedBitCount; // eax
  int v6; // edi
  int initBitsUsed; // [esp+14h] [ebp+8h]

  if ( demo.lastProcessedTime == -1 )
  {
    lastProcessedMsgNum = demo.gameStateMessageSequence + 1;
    v3 = demo.gameStateMessageSequence - demo.lastProcessedMsgNum + 1;
  }
  else
  {
    lastProcessedMsgNum = demo.lastProcessedMsgNum;
    v3 = 1;
  }
  initBitsUsed = MSG_GetUsedBitCount(msg);
  Demo_Printf(1, "Demo_BuildDemoSnapshotInternal() - msgType: %d msgSeq: %d lastFrame:%d\n", 3, lastProcessedMsgNum, v3);
  demo_defaultSnapInfo.snapshotDeltaTime = svsHeader.time;
  Demo_WriteSnapshotStartData(
    msg,
    demo.lastProcessedMsgNum,
    0,
    svsHeader.time,
    svsHeader.physicsTime,
    v3,
    svsHeader.snapFlagServerBit,
    liveStreamNoDelta);
  UsedBitCount = MSG_GetUsedBitCount(msg);
  Demo_RecordProfileData(DEMO_PROFILE_SNAPSHOT, (UsedBitCount - initBitsUsed) / 8);
  Demo_WriteMatchState(msg, liveStreamNoDelta);
  Demo_WritePlayerStates(msg, liveStreamNoDelta);
  Demo_WritePacketEntities(liveStreamNoDelta);
  Demo_WritePacketClients(liveStreamNoDelta);
  Demo_WritePacketActors(liveStreamNoDelta);
  GlassSv_WriteSnapshotToClient(msg, demo.lastProcessedTime);
  if ( demo.header.hasExtraNetworkProfileData )
    Demo_WriteExtraNetworkProfileData(msg);
  Demo_WriteSpawnDebugBuffer(msg, liveStreamNoDelta);
  MSG_WriteBit0(msg);
  MSG_WriteByte(msg, 14);
  v6 = (MSG_GetUsedBitCount(msg) - initBitsUsed) / 8;
  if ( (_S1_29 & 1) == 0 )
  {
    _S1_29 |= 1u;
    _hwm_id_28 = BB_RegisterHighWaterMark("demo_snapshot_bytes");
  }
  BB_SetHighWaterMark(_hwm_id_28, v6);
  if ( v6 < msg->maxsize )
  {
    if ( msg->overflowed )
      Com_PrintError(0, "ERROR !!!! Demo_BuildDemoSnapshotInternal() - msg->overflowed. Inform Bat !!\n");
  }
  else
  {
    Com_PrintError(
      0,
      "ERROR !!!! Demo_BuildDemoSnapshotInternal() - SnapshotBytes (%d) > MaxSize (%d). Inform Bat !!\n",
      v6,
      msg->maxsize);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x9306D0
void __usercall Demo_WriteFooterInternal(msg_t *msg@<esi>, demoFooter *footer, bool isClip)
{
  int v4; // edi
  int v5; // edi
  ClientNum_t *p_clientNum; // edi
  int v7; // edi
  demoDefaultBookmark *defaultBookmarks; // edi
  int numHeliPatches; // ecx
  int v10; // edx
  bool *p_excludeFromDemo; // eax
  demoHeliPatches *heliPatches; // edi
  int v13; // edi
  vec3_t *p_origin; // ebx
  int *bookmarks; // [esp+14h] [ebp+8h]
  int bookmarksa; // [esp+14h] [ebp+8h]
  int bookmarksb; // [esp+14h] [ebp+8h]
  int i; // [esp+18h] [ebp+Ch]

  MSG_WriteLong(msg, footer->version);
  MSG_WriteLong(msg, footer->startTime);
  MSG_WriteLong(msg, footer->endTime);
  MSG_WriteLong(msg, footer->info.taggedPlayers.count);
  v4 = 0;
  if ( footer->info.taggedPlayers.count > 0 )
  {
    bookmarks = footer->info.taggedPlayers.playerIndex;
    do
    {
      MSG_WriteLong(msg, *bookmarks++);
      ++v4;
    }
    while ( v4 < footer->info.taggedPlayers.count );
  }
  MSG_WriteString(msg, footer->info.gameType);
  MSG_WriteString(msg, footer->info.mapName);
  MSG_WriteString(msg, footer->info.zmGameModeGroup);
  MSG_WriteString(msg, footer->info.zmMapStartLoc);
  MSG_WriteString(msg, footer->info.authorName);
  MSG_WriteString(msg, footer->info.name);
  if ( footer->info.isModifiedName )
    MSG_WriteBit1(msg);
  else
    MSG_WriteBit0(msg);
  MSG_WriteString(msg, footer->info.description);
  if ( footer->info.isModifiedDescription )
    MSG_WriteBit1(msg);
  else
    MSG_WriteBit0(msg);
  MSG_WriteLong(msg, footer->info.createTime);
  if ( isClip )
  {
    v5 = 0;
    bookmarksa = 0;
  }
  else
  {
    bookmarksa = footer->numConnectedPlayers;
    v5 = bookmarksa;
  }
  MSG_WriteLong(msg, v5);
  if ( v5 > 0 )
  {
    p_clientNum = &footer->connectedPlayers[0].clientNum;
    do
    {
      MSG_WriteByte(msg, *((unsigned __int8 *)p_clientNum - 4));
      MSG_WriteByte(msg, *p_clientNum);
      MSG_WriteInt64(msg, *(_QWORD *)(p_clientNum + 1));
      MSG_WriteLong(msg, *((_DWORD *)p_clientNum + 3));
      MSG_WriteLong(msg, *((_DWORD *)p_clientNum + 4));
      MSG_WriteByte(msg, *((_DWORD *)p_clientNum + 5));
      MSG_WriteByte(msg, *((_DWORD *)p_clientNum + 6));
      p_clientNum += 12;
      --bookmarksa;
    }
    while ( bookmarksa );
  }
  if ( isClip )
  {
    v7 = 0;
    bookmarksb = 0;
  }
  else
  {
    bookmarksb = footer->numDefaultBookmarks;
    v7 = bookmarksb;
  }
  MSG_WriteLong(msg, v7);
  if ( v7 > 0 )
  {
    defaultBookmarks = footer->defaultBookmarks;
    do
    {
      MSG_WriteByte(msg, *(_DWORD *)defaultBookmarks & 0x7F);
      MSG_WriteLong(msg, defaultBookmarks->time);
      MSG_WriteByte(msg, (*(_DWORD *)defaultBookmarks >> 17) & 0x1F);
      MSG_WriteByte(msg, (*(_DWORD *)defaultBookmarks >> 22) & 0x1F);
      MSG_WriteLong(msg, (*(_DWORD *)defaultBookmarks >> 7) & 0x3FF);
      MSG_WriteShort(msg, *((_DWORD *)defaultBookmarks + 1) & 0x1F);
      MSG_WriteByte(msg, (unsigned __int8)(*((_DWORD *)defaultBookmarks + 1) >> 5));
      MSG_WriteLong(msg, defaultBookmarks->entBirthTime);
      if ( (*((_DWORD *)defaultBookmarks + 1) & 0x2000) != 0 )
        MSG_WriteBit1(msg);
      else
        MSG_WriteBit0(msg);
      MSG_WriteByte(msg, (*((_DWORD *)defaultBookmarks++ + 1) >> 14) & 0x7F);
      --bookmarksb;
    }
    while ( bookmarksb );
  }
  if ( Dvar_GetBool(tu14_demo_enableHeliHeightLockExcludeFromDemo) )
  {
    numHeliPatches = footer->numHeliPatches;
    v10 = 0;
    if ( numHeliPatches > 0 )
    {
      p_excludeFromDemo = &footer->heliPatches[0].excludeFromDemo;
      do
      {
        if ( !*p_excludeFromDemo )
          ++v10;
        p_excludeFromDemo += 24;
        --numHeliPatches;
      }
      while ( numHeliPatches );
    }
    MSG_WriteLong(msg, isClip ? 0 : v10);
    if ( !isClip )
    {
      i = 0;
      if ( footer->numHeliPatches > 0 )
      {
        heliPatches = footer->heliPatches;
        do
        {
          if ( !heliPatches->excludeFromDemo )
          {
            MSG_WriteLong(msg, heliPatches->brushmodel);
            MSG_WriteFloat(msg, heliPatches->origin.x);
            MSG_WriteFloat(msg, heliPatches->origin.y);
            MSG_WriteFloat(msg, heliPatches->origin.z);
            MSG_WriteShort(msg, heliPatches->targetname);
            if ( heliPatches->enabled )
              MSG_WriteBit1(msg);
            else
              MSG_WriteBit0(msg);
          }
          ++heliPatches;
          ++i;
        }
        while ( i < footer->numHeliPatches );
      }
    }
  }
  else
  {
    if ( isClip )
      v13 = 0;
    else
      v13 = footer->numHeliPatches;
    MSG_WriteLong(msg, v13);
    if ( v13 > 0 )
    {
      p_origin = &footer->heliPatches[0].origin;
      do
      {
        MSG_WriteLong(msg, LODWORD(p_origin[-1].z));
        MSG_WriteFloat(msg, p_origin->x);
        MSG_WriteFloat(msg, p_origin->y);
        MSG_WriteFloat(msg, p_origin->z);
        MSG_WriteShort(msg, LOWORD(p_origin[1].x));
        if ( LODWORD(p_origin[1].y) )
          MSG_WriteBit1(msg);
        else
          MSG_WriteBit0(msg);
        p_origin += 2;
        --v13;
      }
      while ( v13 );
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcontentstreaming.cpp:0x930AC0
unsigned int __cdecl Demo_WriteClipFooterToBuffer(
        demoFooter *footer,
        unsigned __int8 *buffer,
        int maxBufferSize,
        int clipDuration)
{
  int endTime; // edx
  int createTime; // eax
  int v7; // ecx
  unsigned __int8 *data; // eax
  int cursize; // edx
  demoPlayback *playback; // esi
  unsigned int v11; // esi
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // edi
  unsigned int v15; // esi
  unsigned int v17; // eax
  unsigned int v18; // esi
  msg_t msg; // [esp+Ch] [ebp-38h] BYREF
  int origCreateTime; // [esp+3Ch] [ebp-8h]
  int origEndTime; // [esp+40h] [ebp-4h]
  int origStartTimeb; // [esp+4Ch] [ebp+8h]
  int origStartTimec; // [esp+4Ch] [ebp+8h]
  unsigned __int8 *origStartTime; // [esp+4Ch] [ebp+8h]
  unsigned __int8 *origStartTimea; // [esp+4Ch] [ebp+8h]
  const unsigned __int8 *totalWritten; // [esp+58h] [ebp+14h]

  memset(buffer, 0, maxBufferSize);
  MSG_Init(&msg, buffer, maxBufferSize);
  endTime = footer->endTime;
  createTime = footer->info.createTime;
  origStartTimeb = footer->startTime;
  origEndTime = endTime;
  origCreateTime = createTime;
  footer->startTime = 0;
  footer->endTime = clipDuration;
  footer->info.createTime = LiveStorage_GetUTC();
  Demo_WriteFooterInternal(&msg, footer, 1);
  v7 = origCreateTime;
  footer->endTime = origEndTime;
  data = msg.data;
  footer->startTime = origStartTimeb;
  cursize = msg.cursize;
  footer->info.createTime = v7;
  playback = demo.playback;
  totalWritten = data;
  origStartTimec = cursize;
  memset(
    demo.playback->clipRecordMemBlock.compressedMsgBuf,
    0,
    sizeof(demo.playback->clipRecordMemBlock.compressedMsgBuf));
  playback->clipRecordMemBlock.compressedSize = Com_CompressWithZLib(
                                                  totalWritten,
                                                  origStartTimec,
                                                  playback->clipRecordMemBlock.compressedMsgBuf,
                                                  0x10000);
  playback->clipRecordMemBlock.uncompressedSize = origStartTimec;
  v11 = Demo_WriteMemoryBlockDataToBuffer(&demo.playback->clipRecordMemBlock, buffer, maxBufferSize);
  if ( Com_IsClientConsole() )
  {
    v12 = (((v11 << 16) | v11 & 0xFF00) << 8) | ((HIWORD(v11) | (unsigned int)&g_sd.voiceDecodeBuffer[742080] & v11) >> 8);
    v13 = v11 + 4;
    v14 = ((footer->version & 0xFF00 | (footer->version << 16)) << 8) | ((HIWORD(footer->version) | (unsigned int)&g_sd.voiceDecodeBuffer[742080] & footer->version) >> 8);
    if ( (int)(v11 + 4) >= maxBufferSize )
    {
      Com_Error(ERR_DROP, &byte_CDD778);
      v12 = (((v11 << 16) | v11 & 0xFF00) << 8) | ((HIWORD(v11) | (unsigned int)&g_sd.voiceDecodeBuffer[742080] & v11) >> 8);
      v13 = v11 + 4;
    }
    *(_DWORD *)&buffer[v11] = v12;
    v15 = v13 + 4;
    origStartTime = &buffer[v13];
    if ( (int)(v13 + 4) >= maxBufferSize )
      Com_Error(ERR_DROP, &byte_CDD778);
    *(_DWORD *)origStartTime = v14;
    return v15;
  }
  else
  {
    v17 = v11 + 4;
    if ( (int)(v11 + 4) >= maxBufferSize )
    {
      Com_Error(ERR_DROP, &byte_CDD778);
      v17 = v11 + 4;
    }
    *(_DWORD *)&buffer[v11] = v11;
    v18 = v17 + 4;
    origStartTimea = &buffer[v17];
    if ( (int)(v17 + 4) >= maxBufferSize )
      Com_Error(ERR_DROP, &byte_CDD778);
    *(_DWORD *)origStartTimea = footer->version;
    return v18;
  }
}

#endif // __UNIMPLEMENTED__
