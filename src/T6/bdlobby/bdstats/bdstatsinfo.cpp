// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdstatsinfo.cpp:0x937A30
int __cdecl BG_StringHashValue(const char *fname)
{
  const char *v1; // esi
  char v2; // al
  int v3; // ebx
  int v4; // ecx
  int v5; // ecx

  v1 = fname;
  v2 = *fname;
  v3 = 0;
  if ( !*fname )
    return v3;
  do
  {
    v4 = (char)tolower(v2);
    v2 = v1[1];
    v5 = (_DWORD)&(v1++)[119 - (_DWORD)fname] * v4;
    v3 += v5;
  }
  while ( v2 );
  if ( v3 == -1 )
    return 0;
  else
    return v3;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdstatsinfo.cpp:0x937A90
void BG_AnimParseError(const char *msg, ...)
{
  const char *PlayerAnimScriptFileName; // eax
  int v2; // [esp-4h] [ebp-408h]
  char text[1024]; // [esp+0h] [ebp-404h] BYREF
  va_list ap; // [esp+410h] [ebp+Ch] BYREF

  va_start(ap, msg);
  _vsnprintf(text, 0x400u, msg, ap);
  if ( BG_GetPlayerAnimScriptFileName() )
  {
    v2 = Com_GetCurrentParseLine() + 1;
    PlayerAnimScriptFileName = BG_GetPlayerAnimScriptFileName();
    Com_Error(ERR_DROP, &byte_CE03D4, text, PlayerAnimScriptFileName, v2);
  }
  else
  {
    Com_Error(ERR_DROP, off_C80780, text);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdstatsinfo.cpp:0x937B20
unsigned int __cdecl BG_AnimationIndexForString(const char *string)
{
  unsigned int v1; // edi
  int *v2; // edx
  int v3; // esi
  unsigned int v4; // ebx
  int v5; // edi
  unsigned int *v7; // eax
  unsigned int v8; // esi
  char *szAnimName; // edi
  loadAnim_t *v10; // esi
  bool v11; // zf
  const char *v12; // eax
  unsigned int *v13; // eax
  int hash; // [esp+Ch] [ebp-4h]
  int hasha; // [esp+Ch] [ebp-4h]

  BG_CheckThread();
  v1 = _tls_index;
  if ( !*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp", 719, 0, "(bgs)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( g_pLoadAnims )
  {
    hasha = BG_StringHashValue(string);
    v7 = g_piNumLoadAnims;
    v8 = 0;
    if ( *g_piNumLoadAnims )
    {
      szAnimName = g_pLoadAnims->szAnimName;
      while ( 1 )
      {
        if ( hasha == *((_DWORD *)szAnimName - 1) )
        {
          if ( !I_stricmp(string, szAnimName) )
            return v8;
          v7 = g_piNumLoadAnims;
        }
        ++v8;
        szAnimName += 72;
        if ( v8 >= *v7 )
        {
          v1 = _tls_index;
          break;
        }
      }
    }
    v10 = &g_pLoadAnims[*v7];
    v11 = !Com_SessionMode_IsZombiesGame();
    v12 = globalZombiesAnimTreeFileName;
    if ( v11 )
      v12 = globalMultiplayerAnimTreeFileName;
    Scr_FindAnim(
      SCRIPTINSTANCE_SERVER,
      v12,
      string,
      &v10->anim,
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v1) + 14960) + 28));
    strcpy(v10->szAnimName, string);
    v10->iNameHash = hasha;
    v13 = g_piNumLoadAnims;
    ++*g_piNumLoadAnims;
    return *v13 - 1;
  }
  else
  {
    hash = BG_StringHashValue(string);
    v2 = *(int **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v1) + 14960);
    v3 = *v2;
    v4 = 0;
    v5 = *v2;
    if ( *(_DWORD *)(*v2 + 122880) )
    {
      while ( hash != *(_DWORD *)(v5 + 88) || I_stricmp(string, (const char *)v5) )
      {
        ++v4;
        v5 += 120;
        if ( v4 >= *(_DWORD *)(v3 + 122880) )
          goto LABEL_9;
      }
      return v4;
    }
    else
    {
LABEL_9:
      BG_AnimParseError("BG_AnimationIndexForString: unknown player animation '%s'", string);
      return -1;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdstatsinfo.cpp:0x937CB0
int __cdecl BG_IndexForString(const char *token, animStringItem_t *strings, int allowFail)
{
  const char *v3; // esi
  animStringItem_t *v4; // edi
  const char *string; // esi
  char v6; // al
  int v7; // ebx
  int v8; // edi
  int v9; // ecx
  int v10; // ecx
  int hash; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v3 = token;
  v4 = strings;
  hash = BG_StringHashValue(token);
  i = 0;
  if ( strings->string )
  {
    while ( 1 )
    {
      if ( v4->hash == -1 )
      {
        string = v4->string;
        v6 = *v4->string;
        v7 = 0;
        if ( v6 )
        {
          v8 = 119 - (_DWORD)string;
          do
          {
            v9 = (char)tolower(v6);
            v6 = string[1];
            v10 = (_DWORD)&(string++)[v8] * v9;
            v7 += v10;
          }
          while ( v6 );
          v4 = strings;
          if ( v7 == -1 )
            v7 = 0;
        }
        v3 = token;
        v4->hash = v7;
      }
      if ( hash == v4->hash && !I_stricmp(v3, v4->string) )
        return i;
      ++i;
      strings = ++v4;
      if ( !v4->string )
        goto LABEL_12;
    }
  }
  else
  {
LABEL_12:
    if ( !allowFail )
      BG_AnimParseError("BG_IndexForString: unknown token '%s'", v3);
    return -1;
  }
}

#endif // __UNIMPLEMENTED__
