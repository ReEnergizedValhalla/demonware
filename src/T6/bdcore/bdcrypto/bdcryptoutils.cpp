// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdcryptoutils.cpp:0x927630
void __cdecl Demo_SetDefaultClient(LocalClientNum_t localClientNum, ClientNum_t defaultClient)
{
  int ControllerIndex; // ebx
  int v3; // esi
  unsigned __int64 *p_xuid; // edi
  const char *String; // eax
  unsigned __int64 v6; // rax
  int v7; // esi
  int v8; // ecx
  int serverTime; // edi
  int *p_connectTime; // edx
  int v11; // eax
  int v12; // edi
  int v13; // [esp+Ch] [ebp-Ch]
  clientActive_t *LocalClientGlobals; // [esp+10h] [ebp-8h]
  ClientNum_t clientNum; // [esp+14h] [ebp-4h]

  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
  ControllerIndex = Com_LocalClient_GetControllerIndex(localClientNum);
  if ( !Demo_IsPlaying() || !demo.header.isDemoClip )
  {
    if ( Live_IsSignedInToLive((ControllerIndex_t)ControllerIndex) && (v3 = 0, demo.footer.numConnectedPlayers > 0) )
    {
      p_xuid = &demo.footer.connectedPlayers[0].xuid;
      while ( 1 )
      {
        String = (const char *)Dvar_GetString(demo_playbackClientXUID);
        if ( String && *String )
          v6 = I_atoi64(String);
        else
          v6 = Live_IsSignedInToLive((ControllerIndex_t)ControllerIndex) ? Live_GetXuid((ControllerIndex_t)ControllerIndex) : 0i64;
        if ( *p_xuid == v6 )
          break;
        ++v3;
        p_xuid += 6;
        if ( v3 >= demo.footer.numConnectedPlayers )
          goto LABEL_15;
      }
      v12 = demo.footer.connectedPlayers[v3].clientNum;
      clientNum = v12;
    }
    else
    {
LABEL_15:
      v12 = Demo_GetDefaultClient();
      clientNum = v12;
    }
    if ( defaultClient >= CLIENT_INDEX_FIRST )
    {
      v12 = defaultClient;
      clientNum = defaultClient;
    }
    v7 = -1;
    if ( v12 == -1 )
      goto LABEL_46;
    if ( LocalClientGlobals->snap.serverTime < demo.footer.connectedPlayers[Demo_GetPlayerIndexForClientNum(
                                                                              (ClientNum_t)v12,
                                                                              -1)].connectTime )
    {
      v12 = Demo_GetDefaultClient();
      clientNum = v12;
    }
    if ( v12 == -1 )
    {
LABEL_46:
      if ( (!Demo_IsPlaying() || !demo.header.settings.isDedicatedServer)
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
              809,
              0,
              "(Demo_IsDedicatedServer())",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v8 = 0;
      v13 = -1;
      if ( demo.footer.numConnectedPlayers > 0 )
      {
        serverTime = LocalClientGlobals->snap.serverTime;
        p_connectTime = &demo.footer.connectedPlayers[0].connectTime;
        while ( serverTime <= *p_connectTime || serverTime >= p_connectTime[1] )
        {
          if ( *((_QWORD *)p_connectTime - 1) )
          {
            v11 = *p_connectTime - serverTime;
            if ( v11 >= 0 && (v7 == -1 || v11 < v13) )
            {
              v7 = v8;
              v13 = *p_connectTime - serverTime;
            }
          }
          ++v8;
          p_connectTime += 12;
          if ( v8 >= demo.footer.numConnectedPlayers )
          {
            v12 = clientNum;
            goto LABEL_38;
          }
        }
        v12 = demo.footer.connectedPlayers[v8].clientNum;
      }
LABEL_38:
      if ( v12 == -1 )
      {
        if ( v7 == -1 || (v12 = demo.footer.connectedPlayers[v7].clientNum, v12 == -1) )
        {
          if ( !Assert_MyHandler(
                  "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
                  847,
                  0,
                  "(clientNum != INVALID_CLIENT_INDEX)",
                  (const char *)&pBlock) )
            __debugbreak();
        }
      }
    }
    Dvar_SetInt(demo_client, v12);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcryptoutils.cpp:0x927830
bool __cdecl Demo_IsCompleted()
{
  return demo.playbackInited && !demo.shutdownInProgress && demo.playback->completed;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcryptoutils.cpp:0x9278E0
char __cdecl Demo_IsClipRecording()
{
  char result; // al
  demoClipState clipState; // ecx

  result = 0;
  if ( demo.playbackInited )
  {
    clipState = demo.playback->clipState;
    if ( clipState == DEMO_CLIP_RECORD_CONTINUOUS || clipState == DEMO_CLIP_RECORD_UNCOMPRESSED_SNAPHOT )
      return 1;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcryptoutils.cpp:0x927910
bool __cdecl Demo_GetClipPausedState()
{
  return demo.playbackInited
      && (Demo_IsPlaying() && demo.header.isDemoClip
       || Demo_IsPlaying() && demo.playbackInited && demo.playback->clipState == DEMO_CLIP_PREVIEW)
      && demo.playback->clipPausedState;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdcryptoutils.cpp:0x927910
bool __cdecl Demo_GetClipPausedState()
{
  return demo.playbackInited
      && (Demo_IsPlaying() && demo.header.isDemoClip
       || Demo_IsPlaying() && demo.playbackInited && demo.playback->clipState == DEMO_CLIP_PREVIEW)
      && demo.playback->clipPausedState;
}

#endif // __UNIMPLEMENTED__
