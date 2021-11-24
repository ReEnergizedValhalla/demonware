// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdaddr.cpp:0x925BD0
playerState_s *__cdecl Demo_ReadPlayerStates(
        playerState_s *result,
        LocalClientNum_t localClientNum,
        msg_t *msg,
        int time)
{
  int v4; // esi
  playerState_s *ps; // edi
  int v6; // eax
  int v8; // [esp+8h] [ebp-2A14h]
  int Int; // [esp+Ch] [ebp-2A10h]
  playerState_s remoteTo; // [esp+10h] [ebp-2A0Ch] BYREF

  v4 = 0;
  Int = Dvar_GetInt(demo_client);
  if ( demo.header.maxClients > 0 )
  {
    ps = demo.snapshot.ps;
    do
    {
      if ( MSG_ReadBit(msg) )
      {
        Demo_Printf(512, "Begin Reading PlayerState\n");
        v8 = MSG_GetNumBitsRead(msg);
        MSG_ReadDeltaPlayerstate(localClientNum, msg, time, ps, &remoteTo, 0);
        v6 = MSG_GetNumBitsRead(msg);
        Demo_Printf(17, "DEMO: r Type: PlayerState Client: %d Size: %d bytes\n", v4, (v6 - v8) / 8);
        if ( Demo_IsPlaying() && demo.header.isDemoClip )
          remoteTo.commandTime = demo.playback->clipServerTime;
        else
          remoteTo.commandTime = time;
        memcpy((unsigned __int8 *)ps, (unsigned __int8 *)&remoteTo, sizeof(playerState_s));
      }
      if ( Demo_GetClipState() == DEMO_CLIP_RECORD_CONTINUOUS )
      {
        if ( v4 == Int )
        {
          Demo_Printf(1024, "DEMO clip: Writing playerstate for client %d\n", v4);
          MSG_WriteBit1(&demo.playback->clipRecordingMsg);
          MSG_WriteDeltaPlayerstate(
            &demo_defaultSnapInfo,
            &demo.playback->clipRecordingMsg,
            time,
            &demo.playback->clipRecordPS,
            ps);
          memcpy(
            (unsigned __int8 *)&demo.playback->clipRecordPS,
            (unsigned __int8 *)ps,
            sizeof(demo.playback->clipRecordPS));
        }
        else
        {
          MSG_WriteBit0(&demo.playback->clipRecordingMsg);
        }
      }
      ++v4;
      ++ps;
    }
    while ( v4 < demo.header.maxClients );
  }
  if ( Demo_IsPlaying() && demo.header.isDemoClip )
  {
    memcpy((unsigned __int8 *)&remoteTo, (unsigned __int8 *)&demo.snapshot.ps[Int], sizeof(remoteTo));
    Demo_AdjustTimeForPlayerState(time, demo.playback->clipServerTime, &remoteTo);
  }
  else
  {
    memcpy((unsigned __int8 *)&remoteTo, (unsigned __int8 *)&demo.snapshot.ps[Int], sizeof(remoteTo));
  }
  memcpy((unsigned __int8 *)result, (unsigned __int8 *)&remoteTo, sizeof(playerState_s));
  return result;
}

#endif // __UNIMPLEMENTED__
