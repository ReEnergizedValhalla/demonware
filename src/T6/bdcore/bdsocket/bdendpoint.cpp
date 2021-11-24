// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdendpoint.cpp:0x926320
int __cdecl Demo_ReadPacketClients(LocalClientNum_t localClientNum, msg_t *msg, int time, int deltaNum)
{
  int Bits; // esi
  clientActive_t *LocalClientGlobals; // ebx
  int prevNumParsedClients; // edi
  int v7; // edx
  int clientIndex; // edi
  int EntityIndex; // esi
  bool v10; // zf
  const clientState_s *v11; // edi
  int v12; // ecx
  int v13; // eax
  ClientNum_t clientNum; // [esp+Ch] [ebp-20h]
  int clientReadResult; // [esp+10h] [ebp-1Ch]
  int oldframeClientCount; // [esp+14h] [ebp-18h]
  int numClients; // [esp+18h] [ebp-14h]
  int oldframeClientBase; // [esp+1Ch] [ebp-10h]
  int newnum; // [esp+20h] [ebp-Ch]
  int newState; // [esp+24h] [ebp-8h]
  clientState_s *newStatea; // [esp+24h] [ebp-8h]
  int oldindex; // [esp+28h] [ebp-4h]
  int msga; // [esp+38h] [ebp+Ch]
  int oldnum; // [esp+40h] [ebp+14h]

  oldindex = 0;
  Bits = MSG_ReadBits(msg, 5);
  numClients = Bits;
  Demo_Printf(65, "DEMO: r Type: PacketClients NumClients: %d FirstClient: 0\n", Bits);
  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
  clientNum = Dvar_GetInt(demo_client);
  prevNumParsedClients = demo.prevNumParsedClients;
  v7 = (LocalClientGlobals->parseClientsIndex - demo.prevNumParsedClients) % LocalClientGlobals->numParseClients;
  oldframeClientBase = demo.prevNumParsedClients;
  demo.prevNumParsedClients = LocalClientGlobals->parseClientsIndex;
  demo.snapshot.prevNumClients = Bits;
  oldframeClientCount = v7;
  if ( deltaNum >= 0 )
  {
    oldnum = LocalClientGlobals->parseClientsBuf[prevNumParsedClients % LocalClientGlobals->numParseClients].clientIndex;
    clientIndex = oldnum;
  }
  else
  {
    clientIndex = 9999;
    oldnum = 9999;
  }
  if ( demo.playbackInited && demo.playback->clipState == DEMO_CLIP_RECORD_CONTINUOUS )
  {
    MSG_WriteBits(&demo.playback->clipRecordingMsg, Bits, 5);
    MSG_ClearLastReferencedEntity(&demo.playback->clipRecordingMsg);
  }
  MSG_ClearLastReferencedEntity(msg);
  while ( !msg->overflowed )
  {
    if ( !MSG_ReadBit(msg) )
      break;
    EntityIndex = MSG_ReadEntityIndex(msg, 5);
    newnum = EntityIndex;
    v10 = clientIndex == EntityIndex;
    if ( clientIndex < EntityIndex )
    {
      newState = oldindex + oldframeClientBase;
      do
      {
        Demo_Printf(64, "ClientState: NewNum (%d) > OldNum (%d) - Copying old data\n", EntityIndex, clientIndex);
        qmemcpy(
          &LocalClientGlobals->parseClientsBuf[LocalClientGlobals->parseClientsIndex++
                                             % LocalClientGlobals->numParseClients],
          &LocalClientGlobals->parseClientsBuf[newState % LocalClientGlobals->numParseClients],
          sizeof(LocalClientGlobals->parseClientsBuf[LocalClientGlobals->parseClientsIndex++ % LocalClientGlobals->numParseClients]));
        ++newState;
        if ( ++oldindex < oldframeClientCount )
          oldnum = LocalClientGlobals->parseClientsBuf[newState % LocalClientGlobals->numParseClients].clientIndex;
        else
          oldnum = 9999;
        EntityIndex = newnum;
        clientIndex = oldnum;
      }
      while ( oldnum < newnum );
      v10 = oldnum == newnum;
    }
    if ( v10 )
    {
      Demo_Printf(64, "ClientState: NewNum (%d) == OldNum (%d) - Reading delta\n", EntityIndex, clientIndex);
      v11 = &LocalClientGlobals->parseClientsBuf[(oldindex + oldframeClientBase) % LocalClientGlobals->numParseClients];
    }
    else
    {
      Demo_Printf(64, "ClientState: NewNum (%d) < OldNum (%d) - Reading from baselines\n", EntityIndex, clientIndex);
      v11 = 0;
    }
    newStatea = &LocalClientGlobals->parseClientsBuf[LocalClientGlobals->parseClientsIndex
                                                   % LocalClientGlobals->numParseClients];
    clientReadResult = MSG_ReadDeltaClient(msg, time, v11, newStatea, EntityIndex);
    if ( Demo_GetClipState() == DEMO_CLIP_RECORD_CONTINUOUS )
    {
      if ( !v12 )
      {
        MSG_WriteDeltaClient(&demo_defaultSnapInfo, &demo.playback->clipRecordingMsg, time, v11, newStatea, 1);
        goto LABEL_24;
      }
      MSG_WriteDeltaClient(&demo_defaultSnapInfo, &demo.playback->clipRecordingMsg, time, v11, 0, 1);
      v12 = clientReadResult;
    }
    if ( v12 )
    {
      if ( (!Demo_IsPlaying() || !demo.header.isDemoClip)
        && (!Demo_IsPlaying() || !demo.playbackInited || demo.playback->clipState != DEMO_CLIP_PREVIEW)
        && clientNum == demo.snapshot.client[EntityIndex].clientIndex
        && !Demo_SwitchPlayerInternal(-1, localClientNum, 0, 1) )
      {
        Demo_SwitchPlayerInternal(-1, localClientNum, 0, 0);
      }
      qmemcpy(&demo.snapshot.client[EntityIndex], &demo_defaultClientState, sizeof(demo.snapshot.client[EntityIndex]));
      goto LABEL_34;
    }
LABEL_24:
    qmemcpy(&demo.snapshot.client[EntityIndex], newStatea, sizeof(demo.snapshot.client[EntityIndex]));
    ++LocalClientGlobals->parseClientsIndex;
LABEL_34:
    if ( oldnum == newnum )
    {
      v13 = oldindex + 1;
      oldindex = v13;
      if ( v13 < oldframeClientCount )
        oldnum = LocalClientGlobals->parseClientsBuf[(oldframeClientBase + v13) % LocalClientGlobals->numParseClients].clientIndex;
      else
        oldnum = 9999;
    }
    Bits = numClients;
    clientIndex = oldnum;
  }
  if ( demo.playbackInited && demo.playback->clipState == DEMO_CLIP_RECORD_CONTINUOUS )
    MSG_WriteBit0(&demo.playback->clipRecordingMsg);
  if ( clientIndex == 9999 )
    return Bits;
  for ( msga = oldindex + oldframeClientBase;
        ;
        clientIndex = LocalClientGlobals->parseClientsBuf[msga % LocalClientGlobals->numParseClients].clientIndex )
  {
    Demo_Printf(64, "ClientState: OldNum (%d) != DEMO_LARGE_INVALID_STATE_NUMBER - Copying old data\n", clientIndex);
    qmemcpy(
      &LocalClientGlobals->parseClientsBuf[LocalClientGlobals->parseClientsIndex++ % LocalClientGlobals->numParseClients],
      &LocalClientGlobals->parseClientsBuf[msga % LocalClientGlobals->numParseClients],
      sizeof(LocalClientGlobals->parseClientsBuf[LocalClientGlobals->parseClientsIndex++ % LocalClientGlobals->numParseClients]));
    ++msga;
    if ( ++oldindex >= oldframeClientCount
      || LocalClientGlobals->parseClientsBuf[msga % LocalClientGlobals->numParseClients].clientIndex == 9999 )
    {
      break;
    }
  }
  return numClients;
}

#endif // __UNIMPLEMENTED__
