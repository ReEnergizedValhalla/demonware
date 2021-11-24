// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdbase64.cpp:0x9279B0
int __cdecl Demo_GetKeyFrameForJumpBack(LocalClientNum_t localClientNum, int newServerTime)
{
  clientActive_t *LocalClientGlobals; // edi
  demoPlayback *playback; // ebx
  int v4; // ecx
  int DefaultClient; // eax
  int v6; // ecx
  int keyframeSnapshotTime; // eax
  int result; // eax
  int v9; // edx
  int v10; // esi
  int *p_keyframeSnapshotTime; // ecx
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi
  int v17; // ecx
  int v18; // eax
  int disconnectTime; // [esp+Ch] [ebp-1Ch] BYREF
  int curKeyframeIndex; // [esp+10h] [ebp-18h]
  int v21; // [esp+14h] [ebp-14h]
  int client; // [esp+18h] [ebp-10h]
  int numAttempts; // [esp+1Ch] [ebp-Ch]
  int connectTime; // [esp+20h] [ebp-8h] BYREF
  bool checkForPlayerConnectTime; // [esp+26h] [ebp-2h]
  bool checkForFirstKeyframe; // [esp+27h] [ebp-1h]

  numAttempts = -1;
  connectTime = -1;
  disconnectTime = -1;
  checkForPlayerConnectTime = 0;
  checkForFirstKeyframe = 0;
  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
  client = demo.playback->keyframeIndex;
  if ( !Demo_IsPlaying() || !demo.header.isDemoClip )
  {
    checkForPlayerConnectTime = 1;
    Demo_GetConnectionTimeInfoForPlayer(localClientNum, &connectTime, &disconnectTime);
    if ( Demo_IsPlaying() )
    {
      if ( demo.playback )
      {
        if ( Dvar_GetBool(demo_pause) )
        {
          playback = demo.playback;
          if ( !demo.playback->overridePause )
            goto LABEL_12;
        }
      }
      else if ( Dvar_GetBool(demo_pause) )
      {
LABEL_11:
        playback = demo.playback;
LABEL_12:
        v4 = 1;
LABEL_13:
        if ( newServerTime < 0 )
        {
          newServerTime = LocalClientGlobals->snap.serverTime - 800 * v4;
          goto LABEL_26;
        }
        if ( newServerTime <= connectTime )
        {
          if ( !newServerTime )
            checkForFirstKeyframe = 1;
          DefaultClient = Demo_GetDefaultClient();
          Demo_SwitchPlayerInternal(DefaultClient, localClientNum, 0, 1);
LABEL_25:
          playback = demo.playback;
          goto LABEL_26;
        }
        goto LABEL_26;
      }
    }
    if ( Com_GetTimeScale() > 2.0 )
    {
      playback = demo.playback;
      v4 = 3;
      goto LABEL_13;
    }
    goto LABEL_11;
  }
  if ( newServerTime >= 0 )
  {
    if ( !newServerTime )
      checkForFirstKeyframe = 1;
    goto LABEL_25;
  }
  playback = demo.playback;
  if ( demo.playbackInited )
    newServerTime = demo.playback->clipTime - 800;
  else
    newServerTime = -800;
LABEL_26:
  v6 = client;
  v21 = 48 * client;
  keyframeSnapshotTime = playback->keyFrame[client].keyframeSnapshotTime;
  if ( keyframeSnapshotTime > newServerTime )
  {
    if ( !checkForFirstKeyframe )
    {
      curKeyframeIndex = client;
      client = Dvar_GetInt(demo_client);
      while ( numAttempts < 250 )
      {
        ++numAttempts;
        if ( curKeyframeIndex )
          v16 = (curKeyframeIndex - 1) % 250;
        else
          v16 = 249;
        v17 = demo.playback->keyFrame[v16].keyframeSnapshotTime;
        curKeyframeIndex = v16;
        if ( v17 / 1000 < newServerTime / 1000 && v17 >= 0 )
        {
          v18 = *(int *)((char *)&demo.playback->keyFrame[0].keyframeSnapshotTime + v21);
          if ( (v17 < v18 || v18 <= 0)
            && (!checkForPlayerConnectTime
             || !v16 && client == Demo_GetDefaultClient()
             || demo.playback->keyFrame[v16].keyframeSnapshotTime / 1000 >= connectTime / 1000) )
          {
            client = v16;
            return v16;
          }
        }
      }
      return -1;
    }
    client = -394632 - (_DWORD)playback;
    numAttempts = -394584 - (_DWORD)playback;
    v21 = -394536 - (_DWORD)playback;
    curKeyframeIndex = -394488 - (_DWORD)playback;
    result = -1;
    v9 = -48;
    v10 = 2;
    p_keyframeSnapshotTime = &playback->keyFrame[1].keyframeSnapshotTime;
    do
    {
      v12 = *(p_keyframeSnapshotTime - 12);
      if ( v12 >= 0 && (result < 0 || *(int *)((char *)&playback->keyFrame[0].keyframeSnapshotTime + v9) > v12) )
      {
        v9 = (int)p_keyframeSnapshotTime - 394680 - (_DWORD)playback;
        result = v10 - 2;
      }
      if ( *p_keyframeSnapshotTime >= 0
        && (result < 0 || *(int *)((char *)&playback->keyFrame[0].keyframeSnapshotTime + v9) > *p_keyframeSnapshotTime) )
      {
        v9 = (int)p_keyframeSnapshotTime + client;
        result = v10 - 1;
      }
      v13 = p_keyframeSnapshotTime[12];
      if ( v13 >= 0 && (result < 0 || *(int *)((char *)&playback->keyFrame[0].keyframeSnapshotTime + v9) > v13) )
      {
        v9 = (int)p_keyframeSnapshotTime + numAttempts;
        result = v10;
      }
      v14 = p_keyframeSnapshotTime[24];
      if ( v14 >= 0 && (result < 0 || *(int *)((char *)&playback->keyFrame[0].keyframeSnapshotTime + v9) > v14) )
      {
        v9 = (int)p_keyframeSnapshotTime + v21;
        result = v10 + 1;
      }
      v15 = p_keyframeSnapshotTime[36];
      if ( v15 >= 0 && (result < 0 || *(int *)((char *)&playback->keyFrame[0].keyframeSnapshotTime + v9) > v15) )
      {
        v9 = (int)p_keyframeSnapshotTime + curKeyframeIndex;
        result = v10 + 2;
      }
      v10 += 5;
      p_keyframeSnapshotTime += 60;
    }
    while ( v10 - 2 < 250 );
  }
  else
  {
    if ( checkForPlayerConnectTime && keyframeSnapshotTime <= connectTime )
      return -1;
    return v6;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
