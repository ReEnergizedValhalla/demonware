// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdleague.cpp:0x939420
const char *__usercall GetWeaponTypeName@<eax>(int type@<eax>)
{
  const char *result; // eax

  switch ( type )
  {
    case 0:
      result = "Rifle";
      break;
    case 1:
      result = "Machine Gun";
      break;
    case 2:
      result = "Submachine Gun";
      break;
    case 4:
    case 13:
      result = "Pistol";
      break;
    case 5:
      result = "Grenade";
      break;
    case 6:
      result = "Rocket Launcher";
      break;
    case 7:
      result = "Turret";
      break;
    case 8:
      result = "Weapon that's not meant for use by the player";
      break;
    case 9:
      result = "Flamethrower";
      break;
    case 10:
      result = "Item";
      break;
    default:
      result = "Unknown";
      break;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdleague.cpp:0x9394B0
int __cdecl GetValueForBitfield(unsigned int bitfield)
{
  int v1; // esi

  v1 = 0;
  while ( 1 )
  {
    if ( (unsigned int)v1 >= 0x7FFFFFF8
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\../universal/q_shared.h",
            957,
            0,
            "(unsigned)(bitNum) < (unsigned)(size * 8)",
            "bitNum doesn't index size * 8\n\t%i not in [0, %i)",
            v1,
            2147483640) )
    {
      __debugbreak();
    }
    if ( ((1 << (v1 & 0x1F)) & *(&bitfield + (v1 >> 5))) != 0 )
      break;
    if ( ++v1 >= 32 )
      return 0;
  }
  return v1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdleague.cpp:0x939510
const char *__usercall BG_GetConditionString@<eax>(int condition@<edi>, int value@<esi>)
{
  const char *result; // eax
  const char *v3; // eax

  BG_CheckThread();
  switch ( condition )
  {
    case 0:
    case 2:
      result = BG_GetPlayerAnimTypeName(value);
      break;
    case 1:
    case 3:
      result = animWeaponClassStr[value].string;
      break;
    case 4:
      result = animConditionMountedStr[value].string;
      break;
    case 5:
      result = animMoveStatusStr[value].string;
      break;
    case 6:
      result = animPrevDirectionStr[value].string;
      break;
    case 7:
      result = animDirectionStr[value].string;
      break;
    case 8:
      result = animDmgDirectionStr[value].string;
      break;
    case 10:
      result = animStanceStr[value].string;
      break;
    case 11:
    case 12:
    case 17:
    case 24:
      result = "true";
      if ( !value )
        result = "false";
      break;
    case 13:
      result = animWeaponPositionStr[value].string;
      break;
    case 14:
      result = animSlopeStateStr[value].string;
      break;
    case 23:
      sprintf(debugString, "0x%08x", value);
      result = debugString;
      break;
    default:
      v3 = va("BG_GetConditionString: unhandled case: %d", condition);
      if ( !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp", 2875, 0, (const char *)&pBlock, v3) )
        __debugbreak();
      result = 0;
      break;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdleague.cpp:0x939630
int __cdecl BG_EvaluateConditions(clientInfo_t *ci, animScriptItem_t *scriptItem)
{
  unsigned int *p_value; // ebx
  int v3; // edi
  int ValueForBitfield; // eax
  const char *PlayerAnimTypeName; // eax
  int v6; // eax
  const char *WeaponTypeName; // eax
  const char *ConditionString; // eax
  int v9; // esi
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  int index; // eax
  animScriptConditionTypes_t type; // ecx
  animScriptCondition_t *cond; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  i = 0;
  cond = scriptItem->conditions;
  if ( scriptItem->numConditions > 0 )
  {
    p_value = &scriptItem->conditions[0].value;
    do
    {
      if ( Dvar_GetBool(animscript_debug) )
      {
        v3 = *(p_value - 1);
        switch ( v3 )
        {
          case 0:
            ValueForBitfield = GetValueForBitfield(*p_value);
            PlayerAnimTypeName = BG_GetPlayerAnimTypeName(ValueForBitfield);
            Com_Printf(18, "Checking to see if weapon animtype is %s...\n", PlayerAnimTypeName);
            break;
          case 1:
            v6 = GetValueForBitfield(*p_value);
            WeaponTypeName = GetWeaponTypeName(v6);
            Com_Printf(18, "Checking to see if weapon type is %s...\n", WeaponTypeName);
            break;
          case 4:
            ConditionString = BG_GetConditionString(v3, *p_value);
            Com_Printf(18, "Checking to see if player is mounted status is %s...\n", ConditionString);
            break;
          case 5:
            v9 = GetValueForBitfield(*p_value);
            v10 = BG_GetConditionString(*(p_value - 1), v9);
            Com_Printf(18, "Checking to see if player movestatus is %s...\n", v10);
            break;
          case 7:
            v11 = BG_GetConditionString(v3, *p_value);
            Com_Printf(18, "Checking to see if player direction is %s...\n", v11);
            break;
          case 8:
            v12 = BG_GetConditionString(v3, *p_value);
            Com_Printf(18, "Checking to see if player damage direction is %s...\n", v12);
            break;
          case 10:
            v13 = BG_GetConditionString(v3, *p_value);
            Com_Printf(18, "Checking to see if player stance is %s...\n", v13);
            break;
          case 11:
            Com_Printf(18, "Checking to see if player using underhand...\n");
            break;
          case 12:
            Com_Printf(18, "Checking to see if player is firing...\n");
            break;
          case 13:
            Com_Printf(18, "Checking weapon position...\n");
            break;
          case 17:
            Com_Printf(18, "Checking to see if player is switching to riot shield...\n");
            break;
          case 18:
            Com_Printf(18, "Checking for vehicle name...\n");
            break;
          case 19:
            Com_Printf(18, "Checking for vehicle seat to...\n");
            break;
          case 20:
            Com_Printf(18, "Checking for vehicle seat from...\n");
            break;
          case 23:
            Com_Printf(18, "Checking for script event...\n");
            break;
          case 24:
            Com_Printf(18, "Checking if Crate a Class...\n");
            break;
          default:
            break;
        }
      }
      index = cond->index;
      type = animConditionsTable[cond->index].type;
      if ( type )
      {
        if ( (unsigned int)(type - 1) <= 2 && ci->clientConditions[index] != cond->value )
        {
LABEL_30:
          if ( Dvar_GetBool(animscript_debug) )
            Com_Printf(18, "failed\n");
          return 0;
        }
      }
      else if ( (ci->clientConditions[index] & cond->value) == 0 )
      {
        goto LABEL_30;
      }
      p_value += 2;
      ++i;
      ++cond;
    }
    while ( i < scriptItem->numConditions );
  }
  if ( Dvar_GetBool(animscript_debug) )
    Com_Printf(18, "Success\n");
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdleague.cpp:0x9398C0
animScriptItem_t *__cdecl BG_FirstValidItem(int client, animScript_t *script)
{
  unsigned int v2; // esi
  unsigned int v3; // edi
  int v4; // edx
  animScript_t *v5; // esi
  animScriptItem_t **items; // ebx
  animScriptItem_t *v8; // eax
  int v9; // esi
  int v10; // edi
  const char *v11; // ecx
  clientInfo_t *clientInfo; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  BG_CheckThread();
  v2 = _tls_index;
  if ( !*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp", 3051, 0, "(bgs)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = client;
  v4 = *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960);
  v5 = script;
  clientInfo = (clientInfo_t *)(v4 + 2056 * client + 152);
  i = 0;
  items = script->items;
  if ( script->numItems <= 0 )
    return 0;
  while ( 1 )
  {
    _EAX = items[1];
    __asm { prefetcht0 byte ptr [eax] }
    if ( Dvar_GetBool(animscript_debug) )
    {
      Com_Printf(18, "Evaluating whether to play: ");
      v8 = *items;
      v9 = 0;
      if ( (*items)->numCommands > 0 )
      {
        v10 = 0;
        do
        {
          switch ( v8->commands[v10].bodyPart[0] )
          {
            case 1:
              v11 = "legs";
              break;
            case 2:
              v11 = "torso";
              break;
            case 3:
              v11 = "fullbody";
              break;
            default:
              v11 = "unknown body part";
              break;
          }
          Com_Printf(
            18,
            "%s on %s",
            (const char *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
                         + 120 * v8->commands[v10].animIndex[0]),
            v11);
          if ( v9 > 0 )
            Com_Printf(18, ", ");
          v8 = *items;
          ++v9;
          ++v10;
        }
        while ( v9 < (*items)->numCommands );
        v3 = client;
      }
      Com_Printf(18, "\n");
      v5 = script;
    }
    if ( v3 >= 0x12
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
            3071,
            0,
            "(unsigned)(client) < (unsigned)(18)",
            "client doesn't index MAX_CLIENTS\n\t%i not in [0, %i)",
            v3,
            18) )
    {
      __debugbreak();
    }
    if ( BG_EvaluateConditions(clientInfo, *items) )
      break;
    ++items;
    if ( ++i >= v5->numItems )
      return 0;
  }
  return *items;
}

#endif // __UNIMPLEMENTED__
