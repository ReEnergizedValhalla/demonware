// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdmallocmemory.cpp:0x929060
void __usercall Demo_WriteClipCommands(
        LocalClientNum_t localClientNum@<edi>,
        msg_t *msg@<esi>,
        bool setClipRecordParams)
{
  if ( demo.playback->clipRecordingMsg.cursize >= 60416 )
  {
    MSG_WriteBits(msg, 0, 2);
    Demo_SaveClipRecordMessageToMainMemory(localClientNum, msg->data, msg->cursize, 0);
  }
  Demo_WriteClipCommandsInternal(localClientNum, msg, setClipRecordParams);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdmallocmemory.cpp:0x9290B0
void __usercall Demo_WriteUncompressedClipSnapshot(LocalClientNum_t localClientNum@<edi>, int a2@<ebp>)
{
  cg_t *v2; // eax
  msg_t *p_clipRecordingMsg; // esi
  int Int; // eax
  LocalClientNum_t v5; // [esp+0h] [ebp-4h]

  CL_GetLocalClientGlobals(v5);
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
    v2 = cgArray;
  }
  else
  {
    v2 = 0;
  }
  if ( v2->nextSnap->serverTime != demo.snapshot.serverTime
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
          5211,
          0,
          "(cgameGlob->nextSnap->serverTime == demo.snapshot.serverTime)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  demo.playback->forceWriteClipCommands = 1;
  p_clipRecordingMsg = &demo.playback->clipRecordingMsg;
  if ( demo.playback->clipRecordingMsg.cursize >= 60416 )
  {
    MSG_WriteBits(&demo.playback->clipRecordingMsg, 0, 2);
    Demo_SaveClipRecordMessageToMainMemory(localClientNum, p_clipRecordingMsg->data, p_clipRecordingMsg->cursize, 0);
  }
  Demo_WriteClipCommandsInternal(localClientNum, p_clipRecordingMsg, 1);
  Demo_GenerateUncompressedSnapshot(a2, localClientNum, &demo.playback->clipRecordingMsg, &demo.snapshot, 0);
  Int = Dvar_GetInt(demo_client);
  memcpy(
    (unsigned __int8 *)&demo.playback->clipRecordPS,
    (unsigned __int8 *)&demo.snapshot.ps[Int],
    sizeof(demo.playback->clipRecordPS));
}

#endif // __UNIMPLEMENTED__
