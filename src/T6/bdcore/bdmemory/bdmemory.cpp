// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdmemory.cpp:0x925E10
int __cdecl Demo_ReadPacketEntities(LocalClientNum_t localClientNum, msg_t *msg, int time, int deltaNum)
{
  int Bits; // edi
  clientActive_t *LocalClientGlobals; // ebx
  int prevNumParsedEntities; // esi
  int v7; // edx
  int number; // esi
  int EntityIndex; // eax
  int v10; // edi
  bool v11; // zf
  const entityState_s *v12; // edi
  int v13; // ecx
  entityState_s *v14; // edi
  int v15; // eax
  int v16; // esi
  int v17; // eax
  msg_t *p_clipRecordingMsg; // [esp-4h] [ebp-38h]
  entityState_s *newState; // [esp+Ch] [ebp-28h]
  ClientNum_t clientNum; // [esp+10h] [ebp-24h]
  int entityClientMaskBit; // [esp+14h] [ebp-20h]
  int oldframeEntityCount; // [esp+18h] [ebp-1Ch]
  int entityReadResult; // [esp+1Ch] [ebp-18h]
  int oldframeEntityBase; // [esp+20h] [ebp-14h]
  int oldindex; // [esp+24h] [ebp-10h]
  int numVisibleEntities; // [esp+28h] [ebp-Ch]
  int newnum; // [esp+2Ch] [ebp-8h]
  int oldnum; // [esp+30h] [ebp-4h]
  int msga; // [esp+40h] [ebp+Ch]
  int isEntityVisible; // [esp+48h] [ebp+14h]
  int isEntityVisiblea; // [esp+48h] [ebp+14h]

  oldindex = 0;
  numVisibleEntities = 0;
  Bits = MSG_ReadBits(msg, 11);
  Demo_Printf(33, "DEMO: r Type: PacketEntities NumEntities: %d FirstEntity: 0\n", Bits);
  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
  clientNum = Dvar_GetInt(demo_client);
  prevNumParsedEntities = demo.prevNumParsedEntities;
  v7 = (LocalClientGlobals->parseEntitiesIndex - demo.prevNumParsedEntities) % LocalClientGlobals->numParseEntities;
  oldframeEntityBase = demo.prevNumParsedEntities;
  demo.prevNumParsedEntities = LocalClientGlobals->parseEntitiesIndex;
  demo.snapshot.prevNumEntities = Bits;
  oldframeEntityCount = v7;
  if ( deltaNum >= 0 )
  {
    oldnum = LocalClientGlobals->parseEntitiesBuf[prevNumParsedEntities % LocalClientGlobals->numParseEntities].number;
    number = oldnum;
  }
  else
  {
    number = 9999;
    oldnum = 9999;
  }
  MSG_ClearLastReferencedEntity(msg);
  if ( demo.playbackInited && demo.playback->clipState == DEMO_CLIP_RECORD_CONTINUOUS )
  {
    MSG_WriteBits(&demo.playback->clipRecordingMsg, Bits, 11);
    MSG_ClearLastReferencedEntity(&demo.playback->clipRecordingMsg);
  }
  for ( ; !msg->overflowed; number = oldnum )
  {
    EntityIndex = MSG_ReadEntityIndex(msg, 10);
    v10 = EntityIndex;
    newnum = EntityIndex;
    if ( (EntityIndex < 0 || EntityIndex >= 1024)
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
            6798,
            0,
            "((newnum >= 0 && newnum < (1<<10)))",
            "(newnum) = %i",
            EntityIndex) )
    {
      __debugbreak();
    }
    if ( v10 == 1023 )
      break;
    v11 = number == v10;
    if ( number < v10 )
    {
      isEntityVisible = oldindex + oldframeEntityBase;
      do
      {
        Demo_Printf(32, "EntityState: NewNum (%d) > OldNum (%d) - Copying old data\n", v10, number);
        qmemcpy(
          &LocalClientGlobals->parseEntitiesBuf[LocalClientGlobals->parseEntitiesIndex
                                              % LocalClientGlobals->numParseEntities],
          &LocalClientGlobals->parseEntitiesBuf[isEntityVisible % LocalClientGlobals->numParseEntities],
          sizeof(LocalClientGlobals->parseEntitiesBuf[LocalClientGlobals->parseEntitiesIndex % LocalClientGlobals->numParseEntities]));
        ++numVisibleEntities;
        ++LocalClientGlobals->parseEntitiesIndex;
        ++isEntityVisible;
        if ( ++oldindex < oldframeEntityCount )
          oldnum = LocalClientGlobals->parseEntitiesBuf[isEntityVisible % LocalClientGlobals->numParseEntities].number;
        else
          oldnum = 9999;
        v10 = newnum;
        number = oldnum;
      }
      while ( oldnum < newnum );
      v11 = oldnum == newnum;
    }
    if ( v11 )
    {
      Demo_Printf(32, "EntityState: NewNum (%d) == OldNum (%d) - Reading delta\n", v10, number);
      if ( Demo_IsPlaying() && demo.header.isDemoClip )
        v12 = &demo.snapshot.ent[v10];
      else
        v12 = &LocalClientGlobals->parseEntitiesBuf[(oldindex + oldframeEntityBase)
                                                  % LocalClientGlobals->numParseEntities];
    }
    else
    {
      Demo_Printf(32, "EntityState: NewNum (%d) < OldNum (%d) - Reading from baselines\n", v10, number);
      v12 = &LocalClientGlobals->entityBaselines[v10];
      if ( Demo_GetClipState() == DEMO_CLIP_RECORD_CONTINUOUS )
        demo_defaultSnapInfo.fromBaseline = 1;
    }
    newState = &LocalClientGlobals->parseEntitiesBuf[LocalClientGlobals->parseEntitiesIndex
                                                   % LocalClientGlobals->numParseEntities];
    entityReadResult = MSG_ReadDeltaEntity(msg, time, v12, newState, newnum, clientNum);
    entityClientMaskBit = MSG_ReadBit(msg);
    if ( Demo_GetClipState() == DEMO_CLIP_RECORD_CONTINUOUS )
    {
      if ( v13 )
        MSG_WriteEntity(&demo_defaultSnapInfo, &demo.playback->clipRecordingMsg, 0, 0, time, v12, 0, DELTA_FLAGS_FORCE);
      else
        MSG_WriteEntity(
          &demo_defaultSnapInfo,
          &demo.playback->clipRecordingMsg,
          0,
          0,
          time,
          v12,
          newState,
          DELTA_FLAGS_FORCE);
      v13 = entityReadResult;
      demo_defaultSnapInfo.fromBaseline = 0;
    }
    v14 = &demo.snapshot.ent[newnum];
    if ( v13 )
    {
      qmemcpy(v14, &demo_defaultEntityState, sizeof(entityState_s));
    }
    else
    {
      qmemcpy(v14, newState, sizeof(entityState_s));
      if ( Demo_IsPlaying() && demo.header.isDemoClip )
        Demo_AdjustTimeForEntityState(time, demo.playback->clipServerTime, newState);
    }
    if ( entityClientMaskBit )
    {
      v15 = MSG_ReadBits(msg, 18);
      v16 = newnum;
      demo.snapshot.entClientMask[newnum][0] = v15;
      Demo_Printf(32, "ClientMask for EntNum: %d is %d.\n", newnum, v15);
    }
    else
    {
      if ( entityReadResult )
      {
        demo.snapshot.entClientMask[newnum][0] = 0;
        Demo_Printf(32, "ClientMask for EntNum: %d is set back to 0.\n", newnum);
      }
      v16 = newnum;
    }
    if ( Demo_GetClipState() == DEMO_CLIP_RECORD_CONTINUOUS )
    {
      p_clipRecordingMsg = &demo.playback->clipRecordingMsg;
      if ( entityClientMaskBit )
      {
        MSG_WriteBit1(p_clipRecordingMsg);
        MSG_WriteBits(&demo.playback->clipRecordingMsg, demo.snapshot.entClientMask[v16][0], 18);
      }
      else
      {
        MSG_WriteBit0(p_clipRecordingMsg);
      }
    }
    if ( !entityReadResult )
    {
      ++numVisibleEntities;
      ++LocalClientGlobals->parseEntitiesIndex;
    }
    if ( oldnum == v16 )
    {
      v17 = oldindex + 1;
      oldindex = v17;
      if ( v17 < oldframeEntityCount )
        oldnum = LocalClientGlobals->parseEntitiesBuf[(oldframeEntityBase + v17) % LocalClientGlobals->numParseEntities].number;
      else
        oldnum = 9999;
    }
  }
  if ( demo.playbackInited && demo.playback->clipState == DEMO_CLIP_RECORD_CONTINUOUS )
    MSG_WriteEntityIndex(&demo_defaultSnapInfo, &demo.playback->clipRecordingMsg, 1023, 10);
  if ( number != 9999 )
  {
    isEntityVisiblea = oldindex;
    for ( msga = oldindex + oldframeEntityBase;
          ;
          number = LocalClientGlobals->parseEntitiesBuf[msga % LocalClientGlobals->numParseEntities].number )
    {
      Demo_Printf(32, "EntityState: OldNum (%d) != DEMO_LARGE_INVALID_STATE_NUMBER - Copying old data\n", number);
      qmemcpy(
        &LocalClientGlobals->parseEntitiesBuf[LocalClientGlobals->parseEntitiesIndex
                                            % LocalClientGlobals->numParseEntities],
        &LocalClientGlobals->parseEntitiesBuf[msga % LocalClientGlobals->numParseEntities],
        sizeof(LocalClientGlobals->parseEntitiesBuf[LocalClientGlobals->parseEntitiesIndex % LocalClientGlobals->numParseEntities]));
      ++numVisibleEntities;
      ++msga;
      ++LocalClientGlobals->parseEntitiesIndex;
      if ( ++isEntityVisiblea >= oldframeEntityCount
        || LocalClientGlobals->parseEntitiesBuf[msga % LocalClientGlobals->numParseEntities].number == 9999 )
      {
        break;
      }
    }
  }
  return numVisibleEntities;
}

#endif // __UNIMPLEMENTED__
