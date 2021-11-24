// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdsocketrouterconfig.cpp:0x950520
bool __cdecl BG_ClipMoveToDobj(const entityState_s *es)
{
  __int16 eType; // ax

  if ( !es
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 3190, 0, "(es)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  eType = es->eType;
  if ( eType == 14 || eType == 15 || es->lerp.u.loopFx.period == 1 )
    return 1;
  return (sd_globals *)es->solid != (sd_globals *)((char *)&g_sd.voiceDecodeBuffer[774847] + 1)
      && eType != 16
      && eType != 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocketrouterconfig.cpp:0x950590
int __cdecl BG_GetFriendlyFireStatus()
{
  return Dvar_GetInt(bg_friendlyFire);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsocketrouterconfig.cpp:0x9505A0
const char *__cdecl BG_DisplayName(const clientInfo_t *ci, int type)
{
  return Com_DisplayName(ci->name, ci->clanAbbrev, type);
}

#endif // __UNIMPLEMENTED__
