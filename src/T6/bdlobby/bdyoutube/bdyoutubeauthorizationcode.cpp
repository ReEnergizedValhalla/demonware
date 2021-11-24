// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdyoutubeauthorizationcode.cpp:0x939B30
void __cdecl BG_SetConditionBit(ClientNum_t client, int condition, int value)
{
  int v3; // edi
  __int32 v4; // esi
  const char *ConditionString; // eax
  unsigned int v6; // eax

  BG_CheckThread();
  if ( !*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp", 3635, 0, "(bgs)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( animConditionsTable[condition].type
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          3637,
          0,
          "(animConditionsTable[condition].type == ANIM_CONDTYPE_BITFLAGS)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (unsigned int)client >= CLIENT_INDEX_18
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          3639,
          0,
          "(unsigned)(client) < (unsigned)(18)",
          "client doesn't index MAX_CLIENTS\n\t%i not in [0, %i)",
          client,
          18) )
  {
    __debugbreak();
  }
  v3 = value;
  if ( value >= 32
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          3640,
          0,
          "(value < 32)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (unsigned int)client >= CLIENT_INDEX_18
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          3643,
          0,
          "(unsigned)(client) < (unsigned)(18)",
          "client doesn't index MAX_CLIENTS\n\t%i not in [0, %i)",
          client,
          18) )
  {
    __debugbreak();
  }
  v4 = 4 * (condition + 514 * client) + 1524;
  if ( !Com_BitCheckAssert(
          (const unsigned int *)(v4
                               + *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)),
          value,
          0xFFFFFFF)
    && G_IsServerGameSystem(client) )
  {
    ConditionString = BG_GetConditionString(condition, value);
    Com_Printf(18, "condition: %s: %s\n", animConditionsStr[condition].string, ConditionString);
    v3 = value;
  }
  if ( (unsigned int)client >= CLIENT_INDEX_18
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          3654,
          0,
          "(unsigned)(client) < (unsigned)(18)",
          "client doesn't index MAX_CLIENTS\n\t%i not in [0, %i)",
          client,
          18) )
  {
    __debugbreak();
  }
  v6 = _tls_index;
  *(_DWORD *)(v4 + *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)) = 0;
  Com_BitSetAssert(
    (unsigned int *)(v4 + *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v6) + 14960)),
    v3,
    0xFFFFFFF);
}

#endif // __UNIMPLEMENTED__
