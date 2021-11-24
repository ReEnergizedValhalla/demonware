// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdcommonaddrinfo.cpp:0x926750
int __usercall Demo_ReadPacketActors@<eax>(
        LocalClientNum_t localClientNum@<ecx>,
        msg_t *msg@<edx>,
        int time,
        int deltaNum)
{
  msg_t *v4; // edi
  clientActive_t *LocalClientGlobals; // ebx
  int prevNumParsedActors; // esi
  int v8; // edx
  int actorIndex; // esi
  int EntityIndex; // eax
  bool v11; // zf
  actorState_s *p_nullState; // edi
  actorState_s *v13; // esi
  int v14; // ecx
  actorState_s *v15; // edi
  int v16; // eax
  int oldframeActorsCount; // [esp+10h] [ebp-84h]
  int numActors; // [esp+14h] [ebp-80h]
  int actorReadResult; // [esp+18h] [ebp-7Ch]
  int actorReadResulta; // [esp+18h] [ebp-7Ch]
  int newnum; // [esp+1Ch] [ebp-78h]
  int oldframeActorsBase; // [esp+20h] [ebp-74h]
  int oldframeActorsBasea; // [esp+20h] [ebp-74h]
  int oldindex; // [esp+24h] [ebp-70h]
  int oldnum; // [esp+28h] [ebp-6Ch]
  actorState_s nullState; // [esp+2Ch] [ebp-68h] BYREF

  v4 = msg;
  oldindex = 0;
  numActors = MSG_ReadLong(msg);
  Demo_Printf(2049, "DEMO: r Type: PacketActors NumActors: %d FirstActor: 0\n", numActors);
  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
  prevNumParsedActors = demo.prevNumParsedActors;
  v8 = (LocalClientGlobals->parseActorsIndex - demo.prevNumParsedActors) % LocalClientGlobals->numParseActors;
  oldframeActorsBase = demo.prevNumParsedActors;
  demo.prevNumParsedActors = LocalClientGlobals->parseActorsIndex;
  oldframeActorsCount = v8;
  if ( deltaNum >= 0 )
  {
    if ( v8 > 0 )
    {
      oldnum = LocalClientGlobals->parseActorsBuf[prevNumParsedActors % LocalClientGlobals->numParseActors].actorIndex;
      actorIndex = oldnum;
    }
    else
    {
      oldnum = 9999;
      actorIndex = 9999;
    }
  }
  else
  {
    actorIndex = 9999;
    oldnum = 9999;
  }
  demo.snapshot.prevNumActors = numActors;
  MSG_ClearLastReferencedEntity(v4);
  if ( demo.playbackInited && demo.playback->clipState == DEMO_CLIP_RECORD_CONTINUOUS )
  {
    MSG_WriteLong(&demo.playback->clipRecordingMsg, numActors);
    MSG_ClearLastReferencedEntity(&demo.playback->clipRecordingMsg);
  }
  if ( !v4->overflowed )
  {
    while ( MSG_ReadBit(v4) )
    {
      EntityIndex = MSG_ReadEntityIndex(v4, 5);
      newnum = EntityIndex;
      v11 = actorIndex == EntityIndex;
      if ( actorIndex < EntityIndex )
      {
        actorReadResult = oldindex + oldframeActorsBase;
        do
        {
          Demo_Printf(2048, "ActorState: NewNum (%d) > OldNum (%d) - Copying old data\n", EntityIndex, actorIndex);
          qmemcpy(
            &LocalClientGlobals->parseActorsBuf[LocalClientGlobals->parseActorsIndex++
                                              % LocalClientGlobals->numParseActors],
            &LocalClientGlobals->parseActorsBuf[actorReadResult % LocalClientGlobals->numParseActors],
            sizeof(LocalClientGlobals->parseActorsBuf[LocalClientGlobals->parseActorsIndex++ % LocalClientGlobals->numParseActors]));
          ++actorReadResult;
          if ( ++oldindex < oldframeActorsCount )
            oldnum = LocalClientGlobals->parseActorsBuf[actorReadResult % LocalClientGlobals->numParseActors].actorIndex;
          else
            oldnum = 9999;
          EntityIndex = newnum;
          actorIndex = oldnum;
        }
        while ( oldnum < newnum );
        v11 = oldnum == newnum;
      }
      if ( v11 )
      {
        Demo_Printf(2048, "ActorState: NewNum (%d) == OldNum (%d) - Reading delta\n", EntityIndex, actorIndex);
        p_nullState = &LocalClientGlobals->parseActorsBuf[(oldindex + oldframeActorsBase)
                                                        % LocalClientGlobals->numParseActors];
      }
      else
      {
        Demo_Printf(2048, "ActorState: NewNum (%d) < OldNum (%d) - Reading from baselines\n", EntityIndex, actorIndex);
        memset((unsigned __int8 *)&nullState, 0, sizeof(nullState));
        p_nullState = &nullState;
        if ( Demo_GetClipState() == DEMO_CLIP_RECORD_CONTINUOUS )
          demo_defaultSnapInfo.fromBaseline = 1;
      }
      v13 = &LocalClientGlobals->parseActorsBuf[LocalClientGlobals->parseActorsIndex
                                              % LocalClientGlobals->numParseActors];
      actorReadResulta = MSG_ReadDeltaActor(msg, time, p_nullState, v13, newnum);
      if ( Demo_GetClipState() == DEMO_CLIP_RECORD_CONTINUOUS )
      {
        if ( v14 )
          MSG_WriteDeltaActor(&demo_defaultSnapInfo, &demo.playback->clipRecordingMsg, time, p_nullState, 0, 1);
        else
          MSG_WriteDeltaActor(&demo_defaultSnapInfo, &demo.playback->clipRecordingMsg, time, p_nullState, v13, 1);
        v14 = actorReadResulta;
        demo_defaultSnapInfo.fromBaseline = 0;
      }
      v15 = &demo.snapshot.actor[newnum];
      if ( v14 )
      {
        qmemcpy(v15, &demo_defaultActorState, sizeof(actorState_s));
      }
      else
      {
        qmemcpy(v15, v13, sizeof(actorState_s));
        ++LocalClientGlobals->parseActorsIndex;
      }
      if ( oldnum == newnum )
      {
        v16 = oldindex + 1;
        oldindex = v16;
        if ( v16 < oldframeActorsCount )
          oldnum = LocalClientGlobals->parseActorsBuf[(oldframeActorsBase + v16) % LocalClientGlobals->numParseActors].actorIndex;
        else
          oldnum = 9999;
      }
      actorIndex = oldnum;
      if ( msg->overflowed )
        break;
      v4 = msg;
    }
  }
  if ( demo.playbackInited && demo.playback->clipState == DEMO_CLIP_RECORD_CONTINUOUS )
    MSG_WriteBit0(&demo.playback->clipRecordingMsg);
  if ( actorIndex != 9999 )
  {
    for ( oldframeActorsBasea = oldindex + oldframeActorsBase;
          ;
          actorIndex = LocalClientGlobals->parseActorsBuf[oldframeActorsBasea % LocalClientGlobals->numParseActors].actorIndex )
    {
      Demo_Printf(2048, "ActorState: OldNum (%d) != DEMO_LARGE_INVALID_STATE_NUMBER - Copying old data\n", actorIndex);
      qmemcpy(
        &LocalClientGlobals->parseActorsBuf[LocalClientGlobals->parseActorsIndex++ % LocalClientGlobals->numParseActors],
        &LocalClientGlobals->parseActorsBuf[oldframeActorsBasea % LocalClientGlobals->numParseActors],
        sizeof(LocalClientGlobals->parseActorsBuf[LocalClientGlobals->parseActorsIndex++ % LocalClientGlobals->numParseActors]));
      ++oldframeActorsBasea;
      if ( ++oldindex >= oldframeActorsCount
        || LocalClientGlobals->parseActorsBuf[oldframeActorsBasea % LocalClientGlobals->numParseActors].actorIndex == 9999 )
      {
        break;
      }
    }
  }
  return numActors;
}

#endif // __UNIMPLEMENTED__
