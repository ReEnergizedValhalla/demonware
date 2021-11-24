// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdbytepacker.cpp:0x927D20
int __cdecl Demo_GetKeyFrameForJumpForward(LocalClientNum_t localClientNum, int currentTime)
{
  clientActive_t *LocalClientGlobals; // edi
  int keyframeIndex; // ebx
  int DefaultClient; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // esi
  int *p_keyframeSnapshotTime; // eax
  int v10; // edx
  int v11; // edx
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int connectTime; // [esp+Ch] [ebp-Ch] BYREF
  int disconnectTime; // [esp+10h] [ebp-8h] BYREF
  bool checkForPlayerConnectTime; // [esp+17h] [ebp-1h]

  connectTime = -1;
  disconnectTime = -1;
  checkForPlayerConnectTime = 0;
  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
  keyframeIndex = demo.playback->keyframeIndex;
  if ( Demo_IsPlaying() && demo.header.isDemoClip )
  {
    if ( currentTime < 0 )
    {
      if ( demo.playbackInited )
        currentTime = demo.playback->clipTime;
      else
        currentTime = 0;
    }
  }
  else
  {
    checkForPlayerConnectTime = 1;
    Demo_GetConnectionTimeInfoForPlayer(localClientNum, &connectTime, &disconnectTime);
    if ( currentTime >= 0 )
    {
      if ( currentTime >= disconnectTime )
      {
        DefaultClient = Demo_GetDefaultClient();
        Demo_SwitchPlayerInternal(DefaultClient, localClientNum, 0, 1);
      }
    }
    else
    {
      currentTime = LocalClientGlobals->snap.serverTime;
    }
  }
  if ( demo.playback->keyFrame[keyframeIndex].keyframeSnapshotTime < currentTime )
    return -1;
  if ( Demo_IsPlaying() )
  {
    if ( demo.playback )
    {
      if ( !Dvar_GetBool(demo_pause) || demo.playback->overridePause )
        goto LABEL_20;
    }
    else if ( !Dvar_GetBool(demo_pause) )
    {
      goto LABEL_20;
    }
    currentTime += pausedBuffer;
  }
LABEL_20:
  v6 = -1;
  v7 = -1;
  v8 = 2;
  p_keyframeSnapshotTime = &demo.playback->keyFrame[1].keyframeSnapshotTime;
  do
  {
    v10 = *(p_keyframeSnapshotTime - 12);
    if ( v10 >= 0 && v10 > currentTime && (!checkForPlayerConnectTime || v10 < disconnectTime) && (v6 < 0 || v10 < v6) )
    {
      v6 = *(p_keyframeSnapshotTime - 12);
      v7 = v8 - 2;
    }
    v11 = *p_keyframeSnapshotTime;
    if ( *p_keyframeSnapshotTime >= 0
      && v11 > currentTime
      && (!checkForPlayerConnectTime || v11 < disconnectTime)
      && (v6 < 0 || v11 < v6) )
    {
      v6 = *p_keyframeSnapshotTime;
      v7 = v8 - 1;
    }
    v12 = p_keyframeSnapshotTime[12];
    if ( v12 >= 0 && v12 > currentTime && (!checkForPlayerConnectTime || v12 < disconnectTime) && (v6 < 0 || v12 < v6) )
    {
      v6 = p_keyframeSnapshotTime[12];
      v7 = v8;
    }
    v13 = p_keyframeSnapshotTime[24];
    if ( v13 >= 0 && v13 > currentTime && (!checkForPlayerConnectTime || v13 < disconnectTime) && (v6 < 0 || v13 < v6) )
    {
      v6 = p_keyframeSnapshotTime[24];
      v7 = v8 + 1;
    }
    v14 = p_keyframeSnapshotTime[36];
    if ( v14 >= 0 && v14 > currentTime && (!checkForPlayerConnectTime || v14 < disconnectTime) && (v6 < 0 || v14 < v6) )
    {
      v6 = p_keyframeSnapshotTime[36];
      v7 = v8 + 2;
    }
    v8 += 5;
    p_keyframeSnapshotTime += 60;
  }
  while ( v8 - 2 < 250 );
  return v7;
}

#endif // __UNIMPLEMENTED__
