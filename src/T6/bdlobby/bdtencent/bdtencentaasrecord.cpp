// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdtencentaasrecord.cpp:0x93F9D0
void __cdecl BG_LoadAnim(const char *levelName, bool canModifyChecksum)
{
  unsigned __int8 *Buf; // edi
  unsigned int v3; // esi
  int v4; // eax
  LargeLocal playerAnims_large_local; // [esp+8h] [ebp-8h] BYREF
  bool canModifyChecksuma; // [esp+1Ch] [ebp+Ch]

  LargeLocal::LargeLocal(&playerAnims_large_local, 73728);
  Buf = LargeLocal::GetBuf(&playerAnims_large_local);
  BG_CheckThread();
  v3 = _tls_index;
  if ( !*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp", 5708, 0, "(bgs)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  iNumPlayerAnims = 0;
  BG_FindAnims();
  BG_AnimParseAnimScript(
    levelName,
    (const char *)Buf,
    **(animScriptData_t ***)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v3) + 14960),
    (loadAnim_t *)Buf,
    &iNumPlayerAnims);
  canModifyChecksuma = canModifyChecksum
                    && Com_SessionMode_IsOnlineGame()
                    && (!Dvar_GetBool(com_sv_running)
                     || *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v3) + 14960) == (_DWORD)&level_bgs);
  v4 = *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v3) + 14960);
  Scr_PrecacheAnimTrees(
    SCRIPTINSTANCE_SERVER,
    *(void *(__cdecl **)(int))(v4 + 128),
    *(_DWORD *)(v4 + 28),
    canModifyChecksuma);
  BG_FindAnimTrees();
  LargeLocal::~LargeLocal(&playerAnims_large_local);
}

#endif // __UNIMPLEMENTED__
