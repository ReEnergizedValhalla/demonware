// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdleaguestatsinfo.cpp:0x938650
void __cdecl BG_ParseCommands(const char **input, animScriptItem_t *scriptItem, animScriptData_t *scriptData)
{
  animScriptData_t *v3; // edi
  animScriptCommand_t *v4; // ebx
  int v5; // esi
  parseInfo_t *v6; // eax
  animScriptItem_t *v7; // ecx
  int numCommands; // eax
  __int16 v9; // ax
  parseInfo_t *v10; // eax
  const char *v11; // esi
  int v12; // edi
  const char *string; // eax
  int v14; // esi
  animStringItem_t *v15; // edx
  const char *v16; // ecx
  int v17; // edx
  animStringItem_t *v18; // ecx
  const char *v19; // eax
  const char *v20; // eax
  const char *v21; // edx
  unsigned int v22; // eax
  char *v23; // edi
  parseInfo_t *v26; // eax
  __int16 v27; // ax
  int duration_low; // ecx
  animation_s *v29; // eax
  int v30; // ecx
  int *p_stance; // eax
  __int64 v32; // rax
  scriptAnimMoveStatusStates_t v33; // eax
  int v34; // ecx
  int v35; // edx
  animation_s *v36; // ecx
  unsigned int *p_value; // ecx
  int v38; // eax
  unsigned int v39; // eax
  int v40; // edx
  int v41; // edx
  int v42; // edx
  int v43; // edx
  int v44; // edx
  int v45; // edx
  unsigned int v46; // eax
  int v47; // edx
  int v48; // edx
  int v49; // edx
  int v50; // edx
  unsigned int v51; // eax
  int v52; // edx
  int v53; // edx
  int v54; // edx
  int v55; // edx
  int v56; // eax
  int v57; // edx
  int v58; // edx
  int v59; // ecx
  int v60; // ecx
  int v61; // ecx
  int v62; // ecx
  int v63; // edx
  int v64; // ecx
  parseInfo_t *v65; // eax
  parseInfo_t *v66; // eax
  int v67; // ecx
  parseInfo_t *v68; // eax
  parseInfo_t *v69; // eax
  parseInfo_t *v70; // eax
  unsigned __int16 v71; // ax
  int v72; // edx
  int v73; // ecx
  int v74; // ecx
  int v75; // edx
  int v76; // edx
  parseInfo_t *v77; // eax
  int v78; // eax
  parseInfo_t *j; // esi
  parseInfo_t *v80; // eax
  unsigned __int8 *v81; // esi
  int v82; // eax
  int partIndex; // [esp+14h] [ebp-54h]
  int i; // [esp+18h] [ebp-50h]
  __int64 *ib; // [esp+18h] [ebp-50h]
  int ia; // [esp+18h] [ebp-50h]
  const char *token; // [esp+20h] [ebp-48h] BYREF
  char animName[64]; // [esp+24h] [ebp-44h] BYREF

  v3 = scriptData;
  v4 = 0;
LABEL_2:
  v5 = 0;
  partIndex = 0;
LABEL_3:
  if ( v5 >= 1 )
    v6 = Com_ParseOnLine(input);
  else
    v6 = Com_Parse(input);
  token = (const char *)v6;
  if ( v6 && v6->token[0] )
  {
    if ( !I_stricmp(v6->token, "}") )
    {
      *input -= strlen(token);
      return;
    }
    if ( !v5 )
    {
      v7 = scriptItem;
      if ( scriptItem->numCommands >= 8 )
      {
        BG_AnimParseError("BG_ParseCommands: exceeded maximum number of animations (%i)", 8);
        v7 = scriptItem;
      }
      numCommands = v7->numCommands;
      v4 = &v7->commands[numCommands];
      v7->numCommands = numCommands + 1;
      *(_DWORD *)v4->bodyPart = 0;
    }
    v9 = BG_IndexForString(token, animBodyPartsStr, 1);
    v4->bodyPart[v5] = v9;
    if ( v9 <= 0 )
    {
      *input -= strlen(token);
      goto LABEL_199;
    }
    animName[0] = 0;
    i = 1;
    while ( 1 )
    {
      v10 = Com_ParseOnLine(input);
      token = (const char *)v10;
      if ( !v10 || !v10->token[0] )
      {
        if ( strlen(animName) )
          goto LABEL_45;
        BG_AnimParseError("BG_ParseCommands: expected animation");
        goto LABEL_43;
      }
      --i;
      v11 = (const char *)v10;
      if ( I_stricmp(v10->token, "%vehicle_name") )
      {
        v21 = v11;
        v22 = strlen(v11) + 1;
        v23 = (char *)&token + 3;
        while ( *++v23 )
          ;
        goto LABEL_37;
      }
      v12 = parseVehicleNameIndex;
      if ( parseVehicleNameIndex >= 0 )
      {
        string = animVehicleNameStr[0].string;
        v14 = 0;
        v15 = animVehicleNameStr;
        if ( animVehicleNameStr[0].string )
        {
          while ( v14 != parseVehicleNameIndex )
          {
            v16 = v15[1].string;
            ++v15;
            ++v14;
            if ( !v16 )
              goto LABEL_23;
          }
          if ( v15->string && parseVehicleLoop )
            goto LABEL_27;
        }
        else
        {
LABEL_23:
          BG_AnimParseError("BG_StringForIndex: index out of range (%i, max is %i)", parseVehicleNameIndex, v14 - 1);
        }
      }
      BG_AnimParseError("BG_ParseCommands: %vehicle_name variable used outside #FOR_ALL_VEHICLES loop");
      v12 = parseVehicleNameIndex;
      string = animVehicleNameStr[0].string;
LABEL_27:
      v17 = 0;
      v18 = animVehicleNameStr;
      if ( string )
      {
        while ( v17 != v12 )
        {
          v19 = v18[1].string;
          ++v18;
          ++v17;
          if ( !v19 )
            goto LABEL_30;
        }
        v20 = v18->string;
      }
      else
      {
LABEL_30:
        BG_AnimParseError("BG_StringForIndex: index out of range (%i, max is %i)", v12, v17 - 1);
        v20 = 0;
      }
      v21 = v20;
      v22 = strlen(v20) + 1;
      v23 = (char *)&token + 3;
      while ( *++v23 )
        ;
LABEL_37:
      qmemcpy(v23, v21, v22);
      v26 = Com_ParseOnLine(input);
      if ( v26 )
      {
        if ( !I_stricmp(v26->token, "+") )
        {
          i = 1;
          goto LABEL_15;
        }
        Com_UngetToken();
      }
LABEL_43:
      if ( i <= 0 )
      {
        v3 = scriptData;
        v5 = partIndex;
LABEL_45:
        v27 = BG_AnimationIndexForString(animName);
        v4->animIndex[v5] = v27;
        duration_low = LOWORD(v3->animations[v27].duration);
        v29 = &v3->animations[v27];
        v4->animDuration[v5] = duration_low;
        if ( duration_low != v29->duration )
          v29->flags |= 0x1000u;
        if ( g_pLoadAnims )
          goto LABEL_129;
        v30 = parseEvent;
        if ( parseMovetype || parseEvent )
        {
          if ( v4->bodyPart[v5] != 2 )
          {
            p_stance = &v3->animations[v4->animIndex[v5]].stance;
            *p_stance |= 1 << parseStance;
            ib = &v3->animations[v4->animIndex[v5]].movetype;
            v32 = 1i64 << parseMovetype;
            *(_DWORD *)ib |= 1i64 << parseMovetype;
            v33 = parseMovestatus;
            *((_DWORD *)ib + 1) |= HIDWORD(v32);
            if ( v33 == ANIM_MOVESTATUS_RUN )
            {
              v34 = v4->animIndex[v5];
              v3->animations[v34].flags |= (unsigned int)&g_hunk_track[160413].name[112];
            }
            else if ( v33 == ANIM_MOVESTATUS_WALK )
            {
              v35 = v4->animIndex[v5];
              v3->animations[v35].flags |= (unsigned int)&g_hunklow_track[6894].name[40];
            }
            if ( (parseMovetype == ANIM_MT_CLIMBUP || parseMovetype == ANIM_MT_CLIMBDOWN)
              && v3->animations[v4->animIndex[v5]].moveSpeed != 0.0 )
            {
              v36 = &v3->animations[v4->animIndex[v5]];
              v36->flags |= 2u;
            }
            ia = 0;
            if ( scriptItem->numConditions > 0 )
            {
              p_value = &scriptItem->conditions[0].value;
              do
              {
                v38 = *(p_value - 1);
                switch ( v38 )
                {
                  case 7:
                    v39 = *p_value;
                    if ( *p_value == 3 )
                    {
                      v40 = v4->animIndex[v5];
                      v3->animations[v40].flags |= 0x10u;
                    }
                    else
                    {
                      switch ( v39 )
                      {
                        case 4u:
                          v41 = v4->animIndex[v5];
                          v3->animations[v41].flags |= 0x20u;
                          break;
                        case 2u:
                          v42 = v4->animIndex[v5];
                          v3->animations[v42].flags |= 0x40u;
                          break;
                        case 1u:
                          v43 = v4->animIndex[v5];
                          v3->animations[v43].flags |= 0x80u;
                          break;
                      }
                    }
                    break;
                  case 14:
                    if ( *p_value == 1 )
                    {
                      v44 = v4->animIndex[v5];
                      v3->animations[v44].flags |= 0x20000u;
                    }
                    else if ( *p_value == 2 )
                    {
                      v45 = v4->animIndex[v5];
                      v3->animations[v45].flags |= 0x40000u;
                    }
                    break;
                  case 8:
                    v46 = *p_value;
                    if ( *p_value == 3 )
                    {
                      v47 = v4->animIndex[v5];
                      v3->animations[v47].flags |= 0x80000u;
                    }
                    else
                    {
                      switch ( v46 )
                      {
                        case 4u:
                          v48 = v4->animIndex[v5];
                          v3->animations[v48].flags |= 0x100000u;
                          break;
                        case 2u:
                          v49 = v4->animIndex[v5];
                          v3->animations[v49].flags |= 0x200000u;
                          break;
                        case 1u:
                          v50 = v4->animIndex[v5];
                          v3->animations[v50].flags |= 0x400000u;
                          break;
                      }
                    }
                    break;
                  case 5:
                    v51 = *p_value;
                    if ( *p_value == 2 )
                    {
                      v52 = v4->animIndex[v5];
                      v3->animations[v52].flags |= (unsigned int)&g_hunk_track[160413].name[112];
                    }
                    else if ( v51 == 1 )
                    {
                      v53 = v4->animIndex[v5];
                      v3->animations[v53].flags |= (unsigned int)&g_hunklow_track[6894].name[40];
                    }
                    else if ( !v51 )
                    {
                      v54 = v4->animIndex[v5];
                      v3->animations[v54].flags &= 0xF9FFFFFF;
                    }
                    break;
                  case 10:
                    if ( *p_value == 1 )
                    {
                      v55 = v4->animIndex[v5];
                      v3->animations[v55].flags |= (unsigned int)&loc_7FFFFF + 1;
                    }
                    else
                    {
                      v56 = v4->animIndex[v5];
                      if ( *p_value == 2 )
                        v3->animations[v56].flags |= (unsigned int)&g_sd.voiceDecodeBuffer[774848];
                      else
                        v3->animations[v56].flags &= 0xFE7FFFFF;
                    }
                    break;
                }
                p_value += 2;
                ++ia;
              }
              while ( ia < scriptItem->numConditions );
            }
          }
          if ( parseMovetype != ANIM_MT_IDLE )
          {
            v30 = parseEvent;
            goto LABEL_100;
          }
          v30 = parseEvent;
LABEL_104:
          v3->animations[v4->animIndex[v5]].moveSpeed = 0.0;
        }
        else
        {
LABEL_100:
          if ( v30 == 25 )
            goto LABEL_104;
        }
        if ( parseMovetype == ANIM_MT_RUN )
        {
          v57 = v4->animIndex[v5];
          v3->animations[v57].flags |= (unsigned int)&g_hunk_track[160413].name[112];
        }
        else if ( parseMovetype == ANIM_MT_WALK )
        {
          v58 = v4->animIndex[v5];
          v3->animations[v58].flags |= (unsigned int)&g_hunklow_track[6894].name[40];
        }
        switch ( v30 )
        {
          case 2:
            v59 = v4->animIndex[v5];
            v3->animations[v59].flags |= 8u;
            v3->animations[v4->animIndex[v5]].initialLerp = 30;
            goto LABEL_129;
          case 18:
          case 19:
            v64 = v4->animIndex[v5];
            v3->animations[v64].flags |= 0x400u;
            goto LABEL_129;
          case 1:
            v3->animations[v4->animIndex[v5]].moveSpeed = 0.0;
            v3->animations[v4->animIndex[v5]].rotSpeed = 0.0;
            v60 = v4->animIndex[v5];
            v3->animations[v60].flags |= 0x100u;
            goto LABEL_129;
          case 8:
            v3->animations[v4->animIndex[v5]].moveSpeed = 0.0;
            v61 = v4->animIndex[v5];
            v3->animations[v61].flags |= 0x10000000u;
            goto LABEL_129;
        }
        if ( (unsigned int)(parseMovetype - 9) <= 9 || (unsigned int)(v30 - 22) <= 2 )
        {
          v3->animations[v4->animIndex[v5]].moveSpeed = 0.0;
          v3->animations[v4->animIndex[v5]].rotSpeed = 0.0;
          goto LABEL_129;
        }
        if ( v30 == 25 )
        {
          v62 = v4->animIndex[v5];
          v3->animations[v62].flags |= 0x800u;
          goto LABEL_129;
        }
        if ( v30 == 5 || v30 == 6 )
        {
          v63 = v4->animIndex[v5];
          v3->animations[v63].flags |= 0x20000000u;
          goto LABEL_129;
        }
        if ( (unsigned int)(v30 - 9) <= 5 && Dvar_GetInt(bg_playerAnimStanceAllowMovementInteruptTime) > 0 )
        {
LABEL_168:
          v73 = v4->animIndex[v5];
          v3->animations[v73].flags |= (unsigned int)&g_npPool[24648];
        }
LABEL_129:
        while ( 1 )
        {
          v65 = Com_ParseOnLine(input);
          token = (const char *)v65;
          if ( !v65 || !v65->token[0] )
            break;
          if ( I_stricmp(v65->token, "duration") )
          {
            if ( I_stricmp(token, "turretanim") )
            {
              if ( I_stricmp(token, "blendtime") )
              {
                if ( I_stricmp(token, "blendouttime") )
                {
                  if ( I_stricmp(token, "attach") )
                  {
                    if ( I_stricmp(token, "turn_to_turret") )
                    {
                      if ( I_stricmp(token, "throw_grenade") )
                      {
                        if ( I_stricmp(token, "grenadeAnim") )
                        {
                          if ( I_stricmp(token, "allowMovementInterrupt") )
                          {
                            if ( I_stricmp(token, "allowReloadInterrupt") )
                            {
                              if ( I_stricmp(token, "weaponTimeScale") )
                              {
                                if ( I_stricmp(token, "weaponDelayScale") )
                                {
                                  if ( I_stricmp(token, "animrate") )
                                    break;
                                  if ( (v3->animations[v4->animIndex[v5]].flags & 0xC000) != 0
                                    && !Assert_MyHandler(
                                          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
                                          1952,
                                          0,
                                          "(( scriptData->animations[command->animIndex[partIndex]].flags & ((1<<15) | (1<<14)) ) == 0)",
                                          "%s",
                                          "ERROR: You cannot set animRate along with either weaponDelayScale or weaponTimeScale\n") )
                                  {
                                    __debugbreak();
                                  }
                                  v77 = Com_ParseOnLine(input);
                                  token = (const char *)v77;
                                  if ( !v77 || !v77->token[0] )
                                    BG_AnimParseError("BG_ParseCommands: expected animrate value");
                                  if ( !g_pLoadAnims )
                                    v3->animations[v4->animIndex[v5]].forceAnimRate = atof(token);
                                }
                                else
                                {
                                  if ( ((v3->animations[v4->animIndex[v5]].flags & 0x4000) != 0
                                     || v3->animations[v4->animIndex[v5]].forceAnimRate > 0.0)
                                    && !Assert_MyHandler(
                                          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
                                          1944,
                                          0,
                                          "(( scriptData->animations[command->animIndex[partIndex]].flags & (1<<14) ) == "
                                          "0 && scriptData->animations[command->animIndex[partIndex]].forceAnimRate <= 0.f)",
                                          "%s",
                                          "ERROR: You cannot set weaponDelayScale along with either animRate or weaponTimeScale\n") )
                                  {
                                    __debugbreak();
                                  }
                                  if ( !g_pLoadAnims )
                                  {
                                    v76 = v4->animIndex[v5];
                                    v3->animations[v76].flags |= 0x8000u;
                                  }
                                }
                              }
                              else
                              {
                                if ( ((v3->animations[v4->animIndex[v5]].flags & 0x8000) != 0
                                   || v3->animations[v4->animIndex[v5]].forceAnimRate > 0.0)
                                  && !Assert_MyHandler(
                                        "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
                                        1936,
                                        0,
                                        "(( scriptData->animations[command->animIndex[partIndex]].flags & (1<<15) ) == 0 "
                                        "&& scriptData->animations[command->animIndex[partIndex]].forceAnimRate <= 0.f)",
                                        "%s",
                                        "ERROR: You cannot set weaponTimeScale along with either animRate or weaponDelayScale\n") )
                                {
                                  __debugbreak();
                                }
                                if ( !g_pLoadAnims )
                                {
                                  v75 = v4->animIndex[v5];
                                  v3->animations[v75].flags |= 0x4000u;
                                }
                              }
                            }
                            else if ( !g_pLoadAnims )
                            {
                              v74 = v4->animIndex[v5];
                              v3->animations[v74].flags |= 0x20000000u;
                            }
                          }
                          else if ( !g_pLoadAnims )
                          {
                            goto LABEL_168;
                          }
                        }
                        else if ( !g_pLoadAnims )
                        {
                          v72 = v4->animIndex[v5];
                          v3->animations[v72].flags |= 0x10000u;
                        }
                      }
                      else
                      {
                        v4->flags |= 1u;
                      }
                    }
                    else
                    {
                      v4->flags |= 2u;
                    }
                  }
                  else
                  {
                    v70 = Com_ParseOnLine(input);
                    token = (const char *)v70;
                    if ( !v70 || !v70->token[0] )
                      BG_AnimParseError("BG_ParseCommands: expected attach tag name");
                    v71 = SL_FindString(token);
                    v4->tagName = v71;
                    if ( !v71 )
                      v4->tagName = SL_GetString_(token, 0, 17);
                  }
                }
                else
                {
                  v69 = Com_ParseOnLine(input);
                  token = (const char *)v69;
                  if ( !v69 || !v69->token[0] )
                    BG_AnimParseError("BG_ParseCommands: expected blendtime value");
                  if ( !g_pLoadAnims )
                    v3->animations[v4->animIndex[v5]].finalLerp = atoi(token);
                }
              }
              else
              {
                v68 = Com_ParseOnLine(input);
                token = (const char *)v68;
                if ( !v68 || !v68->token[0] )
                  BG_AnimParseError("BG_ParseCommands: expected blendtime value");
                if ( !g_pLoadAnims )
                  v3->animations[v4->animIndex[v5]].initialLerp = atoi(token);
              }
            }
            else
            {
              if ( !g_pLoadAnims )
              {
                v67 = v4->animIndex[v5];
                v3->animations[v67].flags |= 4u;
              }
              if ( v4->bodyPart[v5] != 3 )
                BG_AnimParseError("BG_ParseCommands: Turret animations can only be played on the 'both' body part");
            }
          }
          else
          {
            v66 = Com_ParseOnLine(input);
            token = (const char *)v66;
            if ( !v66 || !v66->token[0] )
              BG_AnimParseError("BG_ParseCommands: expected duration value");
            v4->animDuration[v5] = atoi(token);
          }
        }
        Com_UngetToken();
        if ( v4->bodyPart[v5] == 3 || (v78 = v5, ++v5, partIndex = v5, v78 >= 1) )
        {
LABEL_199:
          for ( j = Com_ParseOnLine(input); j; j = Com_ParseOnLine(input) )
          {
            if ( !j->token[0] )
              break;
            if ( I_stricmp(j->token, "sound") )
            {
              BG_AnimParseError("BG_ParseCommands: unknown parameter '%s'", j->token);
            }
            else
            {
              v80 = Com_ParseOnLine(input);
              v81 = (unsigned __int8 *)v80;
              if ( !v80 || !v80->token[0] )
                BG_AnimParseError("BG_ParseCommands: expected sound");
              strstr(v81, ".wav");
              if ( v82 )
                BG_AnimParseError("BG_ParseCommands: wav files not supported, only sound scripts");
              v4->soundAlias = (SndAliasList *)(*(int (__cdecl **)(unsigned __int8 *))(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
                                                                                     + 601976))(v81);
            }
          }
          goto LABEL_2;
        }
        goto LABEL_3;
      }
LABEL_15:
      v5 = partIndex;
      v3 = scriptData;
    }
  }
}

#endif // __UNIMPLEMENTED__
