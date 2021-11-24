// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdplatformstring.inl:0x925AF0
void __usercall Demo_ReadMatchState(LocalClientNum_t localClientNum@<eax>, msg_t *msg@<ecx>, int time)
{
  MatchState *v4; // ebx
  clientActive_t *LocalClientGlobals; // [esp+Ch] [ebp-4h]
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
  v4 = &LocalClientGlobals->parseMatchStatesBuf[LocalClientGlobals->parseMatchStateIndex
                                              % LocalClientGlobals->numParseMatchStates];
  Demo_Printf(9, "DEMO: r Type: MatchState\n");
  MSG_ClearLastReferencedEntity(msg);
  MSG_ReadDeltaMatchState((int)&savedregs, msg, time, &demo.snapshot.matchState, v4);
  if ( demo.playbackInited && demo.playback->clipState == DEMO_CLIP_RECORD_CONTINUOUS )
  {
    MSG_ClearLastReferencedEntity(&demo.playback->clipRecordingMsg);
    MSG_WriteDeltaMatchState(
      (int)&savedregs,
      &demo_defaultSnapInfo,
      &demo.playback->clipRecordingMsg,
      time,
      &demo.snapshot.matchState,
      v4);
  }
  qmemcpy(&demo.snapshot.matchState, v4, sizeof(demo.snapshot.matchState));
  if ( Demo_IsPlaying() && demo.header.isDemoClip )
    Demo_AdjustTimeForMatchState(demo.playback->clipServerTime, time, v4);
  ++LocalClientGlobals->parseMatchStateIndex;
}

#endif // __UNIMPLEMENTED__
