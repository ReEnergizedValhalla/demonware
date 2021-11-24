// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdbandwidthtest.cpp:0x93CBA0
void BG_FindAnims()
{
  unsigned int v0; // esi
  bool IsZombiesGame; // al
  const char *v2; // ecx
  int v3; // eax
  bool v4; // al
  const char *v5; // ecx
  int v6; // eax
  bool v7; // al
  const char *v8; // ecx
  int v9; // eax

  BG_CheckThread();
  v0 = _tls_index;
  if ( !*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp", 5600, 0, "(bgs)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  IsZombiesGame = Com_SessionMode_IsZombiesGame();
  v2 = globalZombiesAnimTreeFileName;
  if ( !IsZombiesGame )
    v2 = globalMultiplayerAnimTreeFileName;
  v3 = *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v0) + 14960);
  Scr_FindAnim(SCRIPTINSTANCE_SERVER, v2, "main", (scr_anim_s *)(*(_DWORD *)v3 + 601992), *(_DWORD *)(v3 + 28));
  v4 = Com_SessionMode_IsZombiesGame();
  v5 = globalZombiesAnimTreeFileName;
  if ( !v4 )
    v5 = globalMultiplayerAnimTreeFileName;
  v6 = *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v0) + 14960);
  Scr_FindAnim(SCRIPTINSTANCE_SERVER, v5, "torso", (scr_anim_s *)(*(_DWORD *)v6 + 601996), *(_DWORD *)(v6 + 28));
  v7 = Com_SessionMode_IsZombiesGame();
  v8 = globalZombiesAnimTreeFileName;
  if ( !v7 )
    v8 = globalMultiplayerAnimTreeFileName;
  v9 = *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v0) + 14960);
  Scr_FindAnim(SCRIPTINSTANCE_SERVER, v8, "legs", (scr_anim_s *)(*(_DWORD *)v9 + 602000), *(_DWORD *)(v9 + 28));
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbandwidthtest.cpp:0x93CCB0
XAnim_s *__usercall BG_FindAnimTree@<eax>(const char *filename@<eax>, int bEnforceExists)
{
  XAnim_s *anims; // edi

  if ( Com_SessionMode_IsZombiesGame() )
  {
    if ( Demo_IsPlaying() && !I_stricmp(globalZombiesAnimTreeFileName, filename) )
    {
      if ( Demo_GetVersion() > 3 )
      {
        if ( Demo_GetVersion() > 4 )
        {
          if ( Demo_GetVersion() > 8 )
          {
            if ( Demo_GetVersion() <= 10 )
              filename = globalZombiesAnimTreeFileName_v4;
          }
          else
          {
            filename = globalZombiesAnimTreeFileName_v3;
          }
        }
        else
        {
          filename = globalZombiesAnimTreeFileName_v2;
        }
      }
      else
      {
        filename = globalZombiesAnimTreeFileName_v1;
      }
    }
  }
  else if ( Demo_IsPlaying() && !I_stricmp(globalMultiplayerAnimTreeFileName, filename) && Demo_GetVersion() <= 9 )
  {
    filename = globalMultiplayerAnimTreeFileName_v1;
  }
  anims = Scr_FindAnimTree(SCRIPTINSTANCE_SERVER, filename).anims;
  if ( !anims && bEnforceExists )
    Com_Error(ERR_DROP, &byte_CE1238, filename);
  return anims;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbandwidthtest.cpp:0x93CD90
void __cdecl BG_FindAnimTrees()
{
  unsigned int v0; // esi
  bool v1; // zf
  const char *v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // edx

  BG_CheckThread();
  v0 = _tls_index;
  if ( !*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp", 5663, 0, "(bgs)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1 = !Com_SessionMode_IsZombiesGame();
  v2 = globalZombiesAnimTreeFileName;
  if ( v1 )
    v2 = globalMultiplayerAnimTreeFileName;
  *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v0) + 14960) + 601984) = BG_FindAnimTree(v2, 1);
  v3 = **(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v0) + 14960);
  *(_DWORD *)(v3 + 601960) = *(_DWORD *)(v3 + 601984);
  v4 = **(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v0) + 14960);
  *(_WORD *)(v4 + 601966) = *(_WORD *)(v4 + 601992);
  v5 = **(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v0) + 14960);
  *(_WORD *)(v5 + 601968) = *(_WORD *)(v5 + 601996);
  v6 = *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v0) + 14960);
  *(_WORD *)(*(_DWORD *)v6 + 601970) = *(_WORD *)(*(_DWORD *)v6 + 602000);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbandwidthtest.cpp:0x93CE90
void __cdecl BG_ResetAnimSpeeds()
{
  memset32(cg_per_ent_anim_rate, 1065353216, 0x3Eu);
  memset32(g_per_ent_anim_rate, 1065353216, 0x3Eu);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbandwidthtest.cpp:0x93CEB0
void __cdecl BG_SetSAnimSpeed(int handle, float rate)
{
  if ( (unsigned int)handle >= 0x3E
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          5750,
          0,
          "(unsigned)(handle) < (unsigned)(( 18 + 32 + 4 + 8 ))",
          "handle doesn't index ANIM_SPEED_STORAGE_COUNT\n\t%i not in [0, %i)",
          handle,
          62) )
  {
    __debugbreak();
  }
  if ( Com_SessionMode_IsZombiesGame() && (unsigned int)handle < 0x3E )
    g_per_ent_anim_rate[handle] = rate;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbandwidthtest.cpp:0x93CF10
double __cdecl BG_GetSAnimSpeed(int handle)
{
  if ( (unsigned int)handle >= 0x3E
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          5757,
          0,
          "(unsigned)(handle) < (unsigned)(( 18 + 32 + 4 + 8 ))",
          "handle doesn't index ANIM_SPEED_STORAGE_COUNT\n\t%i not in [0, %i)",
          handle,
          62) )
  {
    __debugbreak();
  }
  if ( Com_SessionMode_IsZombiesGame() && (unsigned int)handle < 0x3E )
    return g_per_ent_anim_rate[handle];
  else
    return 1.0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbandwidthtest.cpp:0x93CF60
void __cdecl BG_SetCAnimSpeed(int handle, float rate)
{
  if ( (unsigned int)handle >= 0x3E
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          5765,
          0,
          "(unsigned)(handle) < (unsigned)(( 18 + 32 + 4 + 8 ))",
          "handle doesn't index ANIM_SPEED_STORAGE_COUNT\n\t%i not in [0, %i)",
          handle,
          62) )
  {
    __debugbreak();
  }
  if ( Com_SessionMode_IsZombiesGame() && (unsigned int)handle < 0x3E )
    cg_per_ent_anim_rate[handle] = rate;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbandwidthtest.cpp:0x93CFC0
double __cdecl BG_GetCAnimSpeed(int handle)
{
  if ( (unsigned int)handle >= 0x3E
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          5772,
          0,
          "(unsigned)(handle) < (unsigned)(( 18 + 32 + 4 + 8 ))",
          "handle doesn't index ANIM_SPEED_STORAGE_COUNT\n\t%i not in [0, %i)",
          handle,
          62) )
  {
    __debugbreak();
  }
  if ( Com_SessionMode_IsZombiesGame() && (unsigned int)handle < 0x3E )
    return cg_per_ent_anim_rate[handle];
  else
    return 1.0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdbandwidthtest.cpp:0x93D010
void __usercall BG_AnimParseAnimScript(
        const char *levelName@<ecx>,
        const char *a2@<edi>,
        animScriptData_t *scriptData,
        loadAnim_t *pLoadAnims,
        unsigned int *piNumAnims)
{
  const char *PlayerAnimScriptFileName; // eax
  int v6; // ebx
  parseInfo_t *v7; // esi
  animScriptParseMode_t v8; // edi
  int v9; // ebx
  parseInfo_t *v10; // eax
  const char *v11; // edi
  int v12; // ebx
  int v13; // esi
  parseInfo_t *v14; // eax
  const char *v15; // edi
  const char *v16; // eax
  parseInfo_t *v17; // edi
  parseInfo_t *v18; // eax
  const char *v19; // esi
  parseInfo_t *v20; // eax
  const char *v21; // ebx
  int v22; // edx
  animStringItem_t *v23; // ecx
  const char *string; // eax
  const char *v25; // esi
  parseInfo_t *v26; // eax
  const char *v27; // esi
  char v28; // bl
  parseInfo_t *v29; // eax
  parseInfo_t *v30; // esi
  char *v31; // edi
  parseInfo_t *v32; // eax
  parseInfo_t *v33; // eax
  const char *v34; // esi
  parseInfo_t *v35; // esi
  parseInfo_t *v36; // esi
  int v37; // edi
  parseInfo_t *v38; // esi
  int *p_drivers; // esi
  parseInfo_t *v40; // eax
  int v41; // ebx
  bool v42; // zf
  parseInfo_t *v43; // esi
  parseInfo_t *v44; // eax
  int v45; // eax
  animScript_t *v46; // ecx
  parseInfo_t *v47; // eax
  const char *v48; // esi
  parseInfo_t *v49; // eax
  const char *v50; // esi
  int v51; // esi
  int v52; // edx
  animStringItem_t *v53; // ecx
  const char *v54; // eax
  parseInfo_t *v55; // eax
  int v56; // eax
  bool v57; // cc
  animScriptData_t *v58; // eax
  animScript_t *v59; // ecx
  animScriptItem_t *v60; // edi
  parseInfo_t *v61; // esi
  int v62; // edi
  parseInfo_t *v63; // esi
  animScript_t *v64; // esi
  parseInfo_t *v65; // eax
  parseInfo_t *v66; // eax
  const char *v67; // esi
  int v68; // esi
  int v69; // edx
  animStringItem_t *v70; // ecx
  const char *v71; // eax
  signed int ConditionValue; // eax
  int v73; // esi
  signed int v74; // eax
  bool v75; // bl
  parseInfo_t *i; // eax
  parseInfo_t *v77; // eax
  com_parse_mark_t forAllVehiclesMark; // [esp+0h] [ebp-134h] BYREF
  int gunners; // [esp+14h] [ebp-120h] BYREF
  int drivers; // [esp+18h] [ebp-11Ch] BYREF
  const char *input; // [esp+1Ch] [ebp-118h]
  int passengers; // [esp+20h] [ebp-114h] BYREF
  char *s0; // [esp+24h] [ebp-110h]
  animScriptItem_t *currentScriptItem; // [esp+28h] [ebp-10Ch]
  int inCommentLevel; // [esp+2Ch] [ebp-108h]
  animScriptParseMode_t parseMode; // [esp+30h] [ebp-104h]
  int indentLevel; // [esp+34h] [ebp-100h]
  animScriptData_t *v89; // [esp+38h] [ebp-FCh]
  animScript_t *currentScript; // [esp+3Ch] [ebp-F8h]
  const char *text_p; // [esp+40h] [ebp-F4h] BYREF
  animScriptItem_t tempScriptItem; // [esp+44h] [ebp-F0h] BYREF
  int indexes[3]; // [esp+10Ch] [ebp-28h] BYREF
  char vehName[24]; // [esp+118h] [ebp-1Ch] BYREF

  v89 = scriptData;
  s0 = (char *)levelName;
  currentScriptItem = 0;
  BG_GetPlayerAnimScriptFileName();
  input = Com_LoadRawTextFile();
  if ( !input )
  {
    PlayerAnimScriptFileName = BG_GetPlayerAnimScriptFileName();
    Com_Error(ERR_DROP, &byte_CE18E4, PlayerAnimScriptFileName);
  }
  v6 = 0;
  g_pLoadAnims = pLoadAnims;
  g_piNumLoadAnims = piNumAnims;
  parseMode = PARSEMODE_DEFINES;
  memset((unsigned __int8 *)weaponStrings, 0, sizeof(weaponStrings));
  BG_LoadWeaponStrings();
  memset((unsigned __int8 *)animVehicleNameStr, 0, sizeof(animVehicleNameStr));
  memset((unsigned __int8 *)animVehicleTypes, 0, sizeof(animVehicleTypes));
  memset32(cg_per_ent_anim_rate, 1065353216, 0x3Eu);
  memset32(g_per_ent_anim_rate, 1065353216, 0x3Eu);
  memset((unsigned __int8 *)defineStr, 0, sizeof(defineStr));
  memset((unsigned __int8 *)defineStrings, 0, sizeof(defineStrings));
  memset((unsigned __int8 *)numDefines, 0, sizeof(numDefines));
  defineStringsOffset = 0;
  parseVehicleLoop = 0;
  parseVehicleNameIndex = -1;
  inCommentLevel = 0;
  memset(indexes, 255, sizeof(indexes));
  indentLevel = 0;
  currentScript = 0;
  text_p = input;
  Com_BeginParseSession("BG_AnimParseAnimScript");
  memset((unsigned __int8 *)v89->scriptEvents, 0, sizeof(v89->scriptEvents));
  v7 = Com_Parse(&text_p);
  if ( v7 )
  {
    while ( v7->token[0] )
    {
      if ( inCommentLevel )
      {
        if ( !I_stricmp(v7->token, "*/") && --inCommentLevel < 0 )
          inCommentLevel = 0;
        goto LABEL_232;
      }
      if ( I_stricmp(v7->token, "/*") )
      {
        v8 = BG_IndexForString(v7->token, animParseModesStr, 1);
        if ( v8 >= PARSEMODE_DEFINES )
        {
          if ( v6 )
            BG_AnimParseError("BG_AnimParseAnimScript: unexpected '%s'", v7->token);
          parseMode = v8;
          parseMovetype = ANIM_MT_UNUSED;
          parseEvent = -1;
          goto LABEL_232;
        }
        switch ( parseMode )
        {
          case PARSEMODE_DEFINES:
            if ( !I_stricmp(v7->token, "set") )
            {
              v10 = Com_ParseOnLine(&text_p);
              v11 = (const char *)v10;
              if ( !v10 || !v10->token[0] )
                BG_AnimParseError("BG_AnimParseAnimScript: expected condition type string");
              v12 = BG_IndexForString(v11, animConditionsStr, 0);
              v13 = v12;
              if ( animConditionsTable[v12].type )
                BG_AnimParseError("BG_AnimParseAnimScript: can not make a define of type '%s'", v11);
              v14 = Com_ParseOnLine(&text_p);
              v15 = (const char *)v14;
              if ( !v14 || !v14->token[0] )
                BG_AnimParseError("BG_AnimParseAnimScript: expected condition define string");
              v16 = BG_CopyStringIntoBuffer(v15, defineStrings, 0x2710u, &defineStringsOffset);
              defineStr[v13][numDefines[v12]].string = v16;
              defineStr[v13][numDefines[v12]].hash = BG_StringHashValue(v16);
              v17 = Com_ParseOnLine(&text_p);
              if ( !v17 )
                BG_AnimParseError("BG_AnimParseAnimScript: expected '=', found end of line");
              if ( I_stricmp(v17->token, "=") )
                BG_AnimParseError("BG_AnimParseAnimScript: expected '=', found '%s'", v17->token);
              BG_ParseConditionBits(
                animConditionsTable[v12].values,
                v12,
                (unsigned int *)(4 * (16 * v12 + numDefines[v12]) + 136287200),
                &text_p);
              ++numDefines[v12];
              goto LABEL_232;
            }
            if ( !I_stricmp(v7->token, "#IF") )
            {
              v18 = Com_ParseOnLine(&text_p);
              v19 = (const char *)v18;
              if ( !v18 || !v18->token[0] )
                BG_AnimParseError("BG_AnimParseAnimScript: expected #IF <conditional> <value>");
              if ( I_stricmp(v19, "vehicle_anim_type") )
              {
                if ( I_stricmp(v19, "level_name") )
                {
                  BG_AnimParseError("BG_AnimParseAnimScript: unknown pre-processor conditional (%s)", v19);
                }
                else
                {
                  v28 = 0;
                  v29 = Com_ParseOnLine(&text_p);
                  v30 = v29;
                  if ( !v29 || !v29->token[0] )
                    BG_AnimParseError("BG_AnimParseAnimScript: expected #IF <conditional> <value>");
                  if ( !v30 )
                    goto LABEL_72;
                  do
                  {
                    if ( !v30->token[0] )
                      break;
                    if ( !v28 )
                    {
                      v31 = s0;
                      if ( I_stristr(s0, "mp/") == v31 )
                        v31 += 3;
                      if ( !I_stricmp(v30->token, v31) )
                        v28 = 1;
                    }
                    v30 = Com_ParseOnLine(&text_p);
                  }
                  while ( v30 );
                  if ( !v28 )
                  {
LABEL_72:
                    v32 = Com_Parse(&text_p);
                    if ( I_stricmp(v32->token, "#END_IF") )
                    {
                      do
                      {
                        v33 = Com_Parse(&text_p);
                        v34 = (const char *)v33;
                        if ( !v33 || !v33->token[0] )
                          BG_AnimParseError("BG_AnimParseAnimScript: expected #END_IF, reached end of file");
                      }
                      while ( I_stricmp(v34, "#END_IF") );
                    }
                  }
                }
                goto LABEL_232;
              }
              v20 = Com_ParseOnLine(&text_p);
              v21 = (const char *)v20;
              if ( !v20 || !v20->token[0] )
                BG_AnimParseError("BG_AnimParseAnimScript: expected #IF <conditional> <value>");
              v22 = 0;
              v23 = animVehicleAnimTypeStr;
              if ( animVehicleAnimTypeStr[0].string )
              {
                while ( v22 != animVehicleTypes[parseVehicleNameIndex] )
                {
                  string = v23[1].string;
                  ++v23;
                  ++v22;
                  if ( !string )
                    goto LABEL_49;
                }
                v25 = v23->string;
                if ( !v23->string )
LABEL_51:
                  BG_AnimParseError(
                    "BG_AnimParseAnimScript: unknown vehicle type for %s",
                    animVehicleNameStr[parseVehicleNameIndex].string);
                if ( I_stricmp(v25, v21) && I_stricmp(v21, "#END_IF") )
                {
                  do
                  {
                    v26 = Com_Parse(&text_p);
                    v27 = (const char *)v26;
                    if ( !v26 || !v26->token[0] )
                      BG_AnimParseError("BG_AnimParseAnimScript: expected #END_IF, reached end of file");
                  }
                  while ( I_stricmp(v27, "#END_IF") );
                }
                goto LABEL_232;
              }
LABEL_49:
              v25 = 0;
              goto LABEL_51;
            }
            if ( !I_stricmp(v7->token, "#END_IF") || I_stricmp(v7->token, "#ADD_VEHICLE") )
              goto LABEL_232;
            v35 = Com_ParseOnLine(&text_p);
            if ( !v35 )
              BG_AnimParseError("BG_AnimParseAnimScript: expected #ADD_VEHICLE <vehicle_name> <default/tank>");
            if ( strlen(v35->token) >= 0x18
              && !Assert_MyHandler(
                    "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
                    2314,
                    0,
                    "(strlen( token ) < sizeof(vehName))",
                    (const char *)&pBlock) )
            {
              __debugbreak();
            }
            I_strncpyz(vehName, v35->token, 24);
            v36 = Com_ParseOnLine(&text_p);
            if ( !v36 )
              BG_AnimParseError("BG_AnimParseAnimScript: expected #ADD_VEHICLE <vehicle_name> <default/tank>");
            v37 = BG_IndexForString(v36->token, animVehicleAnimTypeStr, 0);
            drivers = 0;
            gunners = 0;
            passengers = 0;
            v38 = Com_ParseOnLine(&text_p);
            if ( !v38 )
            {
LABEL_102:
              BG_AddVehicleName(vehName, v37, drivers, gunners, passengers);
              goto LABEL_232;
            }
            while ( 2 )
            {
              if ( !v38->token[0] )
                goto LABEL_102;
              if ( !I_stricmp(v38->token, "drivers") )
              {
                p_drivers = &drivers;
                goto LABEL_92;
              }
              if ( !I_stricmp(v38->token, "gunners") )
              {
                p_drivers = &gunners;
                goto LABEL_92;
              }
              if ( I_stricmp(v38->token, "passengers") )
              {
                BG_AnimParseError("BG_AnimParseAnimScript: unknown token (%s) in #ADD_VEHICLE command", v38->token);
              }
              else
              {
                p_drivers = &passengers;
LABEL_92:
                v40 = Com_ParseOnLine(&text_p);
                if ( v40 && v40->token[0] )
                  *p_drivers = atoi(v40->token);
                else
                  BG_AnimParseError("BG_AnimParseAnimScript: missing index for seat type");
              }
              v38 = Com_ParseOnLine(&text_p);
              if ( !v38 )
                goto LABEL_102;
              continue;
            }
          case PARSEMODE_ANIMATION:
          case PARSEMODE_CANNED_ANIMATIONS:
            if ( !I_stricmp(v7->token, "{") )
              goto LABEL_162;
            if ( !I_stricmp(v7->token, "}") )
            {
              v41 = v6 - 1;
              indentLevel = v41;
              if ( v41 < 0 )
                BG_AnimParseError("BG_AnimParseAnimScript: unexpected '%s'", v7->token);
              v42 = v41 == 1;
              goto LABEL_171;
            }
            if ( !v6 )
            {
              if ( indexes[0] >= 0 )
                goto LABEL_228;
              if ( I_stricmp(v7->token, "state") )
                BG_AnimParseError("BG_AnimParseAnimScript: expected 'state'");
              v43 = Com_ParseOnLine(&text_p);
              if ( !v43 )
                BG_AnimParseError("BG_AnimParseAnimScript: expected state type");
              indexes[0] = BG_IndexForString(v43->token, animStateStr, 0);
              v44 = Com_Parse(&text_p);
              if ( !v44 || I_stricmp(v44->token, "{") )
                BG_AnimParseError("BG_AnimParseAnimScript: expected '{'");
              indentLevel = 1;
              goto LABEL_232;
            }
            if ( v6 != 1 )
            {
              if ( v6 != 2 )
              {
                if ( v6 != 3 )
                  goto LABEL_228;
                text_p -= strlen(v7->token);
                if ( I_strncmp(text_p, v7->token, strlen(v7->token)) )
                  BG_AnimParseError("BG_AnimParseAnimScript: internal error");
                goto LABEL_160;
              }
              if ( indexes[2] >= 0 )
                goto LABEL_228;
              text_p -= strlen(v7->token);
              if ( I_strncmp(text_p, v7->token, strlen(v7->token)) )
                BG_AnimParseError("BG_AnimParseAnimScript: internal error");
              if ( I_stricmp(v7->token, "#FOR_ALL_VEHICLES") )
              {
                if ( I_stricmp(v7->token, "#END_FOR_ALL_VEHICLES") )
                {
                  memset((unsigned __int8 *)&tempScriptItem, 0, sizeof(tempScriptItem));
                  v56 = BG_ParseConditions(&text_p, &tempScriptItem);
                  v57 = currentScript->numItems < 128;
                  indexes[2] = v56;
                  if ( !v57 )
                    BG_AnimParseError("BG_AnimParseAnimScript: exceeded maximum items per script (%i)", 128);
                  if ( v89->numScriptItems >= 2158 )
                    BG_AnimParseError("BG_AnimParseAnimScript: exceeded maximum global items (%i)", 2158);
                  goto LABEL_156;
                }
                v51 = parseVehicleNameIndex + 1;
                v52 = 0;
                ++parseVehicleNameIndex;
                v53 = animVehicleNameStr;
                if ( animVehicleNameStr[0].string )
                {
                  while ( v52 != v51 )
                  {
                    v54 = v53[1].string;
                    ++v53;
                    ++v52;
                    if ( !v54 )
                      goto LABEL_147;
                  }
                  if ( v53->string )
                    goto LABEL_151;
                }
LABEL_147:
                v55 = Com_Parse(&text_p);
                if ( !v55 || !v55->token[0] )
                  BG_AnimParseError("BG_AnimParseAnimScript: internal error");
                parseVehicleLoop = 0;
                parseVehicleNameIndex = 0;
              }
              else
              {
                v47 = Com_Parse(&text_p);
                v48 = (const char *)v47;
                if ( !v47 || !v47->token[0] )
                  BG_AnimParseError("BG_AnimParseAnimScript: internal error");
                Com_ParseSetMark(&text_p, &forAllVehiclesMark);
                parseVehicleLoop = 1;
                parseVehicleNameIndex = 0;
                if ( !animVehicleNameStr[0].string )
                {
                  parseVehicleLoop = 0;
                  parseVehicleNameIndex = 0;
                  if ( I_stricmp(v48, "#END_FOR_ALL_VEHICLES") )
                  {
                    do
                    {
                      v49 = Com_Parse(&text_p);
                      v50 = (const char *)v49;
                      if ( !v49 || !v49->token[0] )
                        BG_AnimParseError("BG_AnimParseAnimScript: expected #END_FOR_ALL_VEHICLES, reached end of file");
                    }
                    while ( I_stricmp(v50, "#END_FOR_ALL_VEHICLES") );
                  }
                }
              }
              goto LABEL_232;
            }
            if ( indexes[1] >= 0 )
              goto LABEL_228;
            v45 = BG_IndexForString(v7->token, animMoveTypesStr, 0);
            indexes[1] = v45;
            if ( parseMode == PARSEMODE_ANIMATION )
            {
              v46 = &v89->scriptAnims[indexes[0]][v45];
              parseMovetype = v45;
            }
            else
            {
              if ( parseMode != PARSEMODE_CANNED_ANIMATIONS )
              {
LABEL_125:
                memset((unsigned __int8 *)currentScript, 0, sizeof(animScript_t));
                goto LABEL_232;
              }
              v46 = &v89->scriptCannedAnims[indexes[0]][v45];
            }
            currentScript = v46;
            goto LABEL_125;
          case PARSEMODE_STATECHANGES:
          case PARSEMODE_EVENTS:
            if ( !I_stricmp(v7->token, "{") )
            {
LABEL_162:
              if ( v6 >= 3 )
                BG_AnimParseError("BG_AnimParseAnimScript: unexpected '%s'", v7->token);
              if ( indexes[v6] >= 0 )
                goto LABEL_166;
              goto LABEL_165;
            }
            if ( I_stricmp(v7->token, "}") )
            {
              if ( v6 )
              {
                if ( v6 == 1 )
                {
                  if ( indexes[1] < 0 )
                  {
                    text_p -= strlen(v7->token);
                    if ( I_strncmp(text_p, v7->token, strlen(v7->token)) )
                      BG_AnimParseError("BG_AnimParseAnimScript: internal error");
                    memset((unsigned __int8 *)&tempScriptItem, 0, sizeof(tempScriptItem));
                    indexes[1] = BG_ParseConditions(&text_p, &tempScriptItem);
                    if ( currentScript->numItems >= 128 )
                      BG_AnimParseError("BG_AnimParseAnimScript: exceeded maximum items per script (%i)", 128);
                    if ( v89->numScriptItems >= 2158 )
                      BG_AnimParseError("BG_AnimParseAnimScript: exceeded maximum global items (%i)", 2158);
                    if ( !parseVehicleLoop
                      || ((ConditionValue = BG_AnimGetConditionValue(&tempScriptItem, 20),
                           v73 = parseVehicleNameIndex,
                           ConditionValue <= 0)
                       || (ConditionValue & animVehicleSeats[parseVehicleNameIndex].seats) != 0)
                      && ((v74 = BG_AnimGetConditionValue(&tempScriptItem, 19), v74 <= 0)
                       || (v74 & animVehicleSeats[v73].seats) != 0) )
                    {
LABEL_156:
                      v58 = v89;
                      v59 = currentScript;
                      currentScript->items[currentScript->numItems] = &v89->scriptItems[v89->numScriptItems];
                      ++v58->numScriptItems;
                      v60 = v59->items[v59->numItems++];
                      currentScriptItem = v60;
                      qmemcpy(v60, &tempScriptItem, sizeof(animScriptItem_t));
                      goto LABEL_232;
                    }
                    v75 = 0;
                    for ( i = Com_Parse(&text_p); i; i = Com_Parse(&text_p) )
                    {
                      if ( !i->token[0] )
                        break;
                      if ( v75 )
                      {
                        if ( !I_stricmp(i->token, "}") )
                          break;
                      }
                      else
                      {
                        v75 = I_stricmp(i->token, "{") == 0;
                      }
                    }
                    indexes[1] = -1;
                    goto LABEL_232;
                  }
LABEL_228:
                  BG_AnimParseError("BG_AnimParseAnimScript: unexpected '%s'", v7->token);
                  goto LABEL_232;
                }
                if ( v6 != 2 )
                  goto LABEL_228;
                text_p -= strlen(v7->token);
                if ( I_strncmp(text_p, v7->token, strlen(v7->token)) )
                  BG_AnimParseError("BG_AnimParseAnimScript: internal error");
LABEL_160:
                BG_ParseCommands(&text_p, currentScriptItem, v89);
              }
              else
              {
                if ( indexes[0] >= 0 )
                  goto LABEL_228;
                if ( parseMode == PARSEMODE_STATECHANGES )
                {
                  if ( I_stricmp(v7->token, "statechange") )
                    BG_AnimParseError("BG_AnimParseAnimScript: expected 'statechange', got '%s'", v7->token);
                  v61 = Com_ParseOnLine(&text_p);
                  if ( !v61 )
                    BG_AnimParseError("BG_AnimParseAnimScript: expected <state type>");
                  v62 = BG_IndexForString(v61->token, animStateStr, 0);
                  v63 = Com_ParseOnLine(&text_p);
                  if ( !v63 )
                    BG_AnimParseError("BG_AnimParseAnimScript: expected <state type>");
                  indexes[0] = BG_IndexForString(v63->token, animStateStr, 0);
                  v64 = &v89->scriptStateChange[indexes[0]][v62];
                  currentScript = v64;
                  v65 = Com_Parse(&text_p);
                  if ( !v65 || I_stricmp(v65->token, "{") )
                    BG_AnimParseError("BG_AnimParseAnimScript: expected '{'");
                  indentLevel = 1;
                  memset((unsigned __int8 *)v64, 0, sizeof(animScript_t));
                }
                else if ( I_stricmp(v7->token, "#FOR_ALL_VEHICLES") )
                {
                  if ( I_stricmp(v7->token, "#END_FOR_ALL_VEHICLES") )
                  {
                    indexes[0] = BG_IndexForString(v7->token, animEventTypesStr, 0);
                    currentScript = &v89->scriptEvents[indexes[0]];
                    parseEvent = indexes[0];
                  }
                  else
                  {
                    v68 = parseVehicleNameIndex + 1;
                    v69 = 0;
                    ++parseVehicleNameIndex;
                    v70 = animVehicleNameStr;
                    if ( animVehicleNameStr[0].string )
                    {
                      while ( v69 != v68 )
                      {
                        v71 = v70[1].string;
                        ++v70;
                        ++v69;
                        if ( !v71 )
                        {
                          parseVehicleLoop = 0;
                          parseVehicleNameIndex = 0;
                          goto LABEL_232;
                        }
                      }
                      if ( v70->string )
                      {
LABEL_151:
                        Com_ParseReturnToMark(&text_p, &forAllVehiclesMark);
                        goto LABEL_232;
                      }
                    }
                    parseVehicleLoop = 0;
                    parseVehicleNameIndex = 0;
                  }
                }
                else
                {
                  Com_ParseSetMark(&text_p, &forAllVehiclesMark);
                  parseVehicleLoop = 1;
                  parseVehicleNameIndex = 0;
                  if ( !animVehicleNameStr[0].string )
                  {
                    parseVehicleLoop = 0;
                    parseVehicleNameIndex = 0;
                    if ( I_stricmp(v7->token, "#END_FOR_ALL_VEHICLES") )
                    {
                      do
                      {
                        v66 = Com_Parse(&text_p);
                        v67 = (const char *)v66;
                        if ( !v66 || !v66->token[0] )
                          BG_AnimParseError("BG_AnimParseAnimScript: expected #END_FOR_ALL_VEHICLES, reached end of file");
                      }
                      while ( I_stricmp(v67, "#END_FOR_ALL_VEHICLES") );
                    }
                  }
                }
              }
            }
            else
            {
              v41 = v6 - 1;
              indentLevel = v41;
              if ( v41 < 0 )
                BG_AnimParseError("BG_AnimParseAnimScript: unexpected '%s'", v7->token);
              v42 = v41 == 0;
LABEL_171:
              if ( v42 )
                currentScript = 0;
              indexes[v41] = -1;
            }
            goto LABEL_232;
          case PARSEMODE_FORCELOAD:
            if ( I_stricmp(v7->token, "{") )
            {
              if ( I_stricmp(v7->token, "}") )
              {
                if ( v7->token[0] )
                  BG_AnimationIndexForString(v7->token);
                else
                  BG_AnimParseError("BG_AnimParseAnimScript: expected animation");
              }
              else
              {
                v9 = v6 - 1;
                indentLevel = v9;
                if ( v9 < 0 )
                  BG_AnimParseError("BG_AnimParseAnimScript: unexpected '%s'", v7->token);
                if ( v9 == 1 )
                  currentScript = 0;
              }
            }
            else
            {
              if ( v6 >= 3 )
LABEL_165:
                BG_AnimParseError("BG_AnimParseAnimScript: unexpected '%s'", v7->token);
LABEL_166:
              indentLevel = v6 + 1;
            }
            goto LABEL_232;
          default:
            goto LABEL_232;
        }
      }
      inCommentLevel = 1;
LABEL_232:
      v77 = Com_Parse(&text_p);
      v6 = indentLevel;
      v7 = v77;
      if ( !v77 )
        break;
    }
    if ( v6 )
      BG_AnimParseError("BG_AnimParseAnimScript: unexpected end of file: %s", a2);
  }
  Com_EndParseSession();
  Com_UnloadRawTextFile(input);
}

#endif // __UNIMPLEMENTED__
