// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdtitleutilities.cpp:0x92E620
void __cdecl Demo_SetIntermissionPoint(vec3_t *origin, vec3_t *angles)
{
  demo.intermissionPointOrigin = *origin;
  demo.intermissionPointAngles = *angles;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdtitleutilities.cpp:0x92E680
void __cdecl Demo_RecordPlayerSessionState(ClientNum_t clientNum, int state)
{
  demo.playerSessionState[clientNum] = state;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdtitleutilities.cpp:0x92E6A0
bool __cdecl Demo_IsInFinalKillcam()
{
  int v0; // ecx
  bool result; // al
  client_t *i; // edx

  v0 = 0;
  result = 1;
  if ( demo.header.maxClients > 0 )
  {
    for ( i = svs.clients; i->header.state < 5 || i->gentity->client->sess.forceSpectatorClient >= CLIENT_INDEX_FIRST; ++i )
    {
      if ( ++v0 >= demo.header.maxClients )
        return result;
    }
    return 0;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdtitleutilities.cpp:0x92E6F0
void __cdecl Demo_ClientConnected(ClientNum_t clientNum)
{
  demo.lastReliableCommandRecorded[clientNum] = 0;
}

#endif // __UNIMPLEMENTED__
