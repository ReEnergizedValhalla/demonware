// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdgenericleagueid.cpp:0x938450
int __cdecl BG_ParseConditions(const char **text_pp, animScriptItem_t *scriptItem)
{
  const char **v2; // edi
  parseInfo_t *i; // esi
  int v4; // eax
  int v5; // ebx
  parseInfo_t *v6; // eax
  const char *v7; // esi
  unsigned int v8; // eax
  parseInfo_t *v9; // eax
  const char *v10; // esi
  int conditionIndex; // [esp+Ch] [ebp-8h]
  unsigned int conditionValue; // [esp+10h] [ebp-4h] BYREF

  v2 = text_pp;
  conditionValue = 0;
  parseStance = ANIM_STANCE_STAND;
  parseMovestatus = ANIM_MOVESTATUS_STATIONARY;
  for ( i = Com_ParseOnLine(text_pp); i; i = Com_ParseOnLine(v2) )
  {
    if ( !i->token[0] )
      break;
    if ( !I_stricmp(i->token, "default") )
      return 1;
    v4 = BG_IndexForString(i->token, animConditionsStr, 0);
    v5 = v4;
    conditionIndex = v4;
    switch ( animConditionsTable[v4].type )
    {
      case ANIM_CONDTYPE_BITFLAGS:
        BG_ParseConditionBits(animConditionsTable[v4].values, v4, &conditionValue, v2);
        v2 = text_pp;
        break;
      case ANIM_CONDTYPE_VALUE:
        v6 = Com_ParseOnLine(v2);
        v7 = (const char *)v6;
        if ( !v6 || !v6->token[0] )
          BG_AnimParseError("BG_ParseConditions: expected condition value, found end of line");
        if ( v7[strlen(v7) - 1] == 44 )
          v7[strlen(v7) - 1] = 0;
        if ( !animConditionsTable[v5].values )
        {
          v8 = atoi(v7);
          goto LABEL_25;
        }
        if ( I_stricmp(v7, "%vehicle_name") )
        {
          conditionValue = BG_IndexForString(v7, animConditionsTable[v5].values, 0);
        }
        else
        {
          if ( parseVehicleNameIndex < 0 )
            BG_AnimParseError("BG_ParseConditions: %vehicle_name found outside of #FOR_ALL_VEHICLES loop");
          conditionValue = parseVehicleNameIndex;
        }
        break;
      case ANIM_CONDTYPE_ENABLED:
        conditionValue = 1;
        break;
      case ANIM_CONDTYPE_STRINGHASH:
        v9 = Com_ParseOnLine(v2);
        v10 = (const char *)v9;
        if ( !v9 || !v9->token[0] )
          BG_AnimParseError("BG_ParseConditions: expected condition value, found end of line");
        if ( v10[strlen(v10) - 1] == 44 )
          v10[strlen(v10) - 1] = 0;
        v8 = BG_StringHashValue(v10);
LABEL_25:
        conditionValue = v8;
        break;
      default:
        break;
    }
    scriptItem->conditions[scriptItem->numConditions].index = conditionIndex;
    scriptItem->conditions[scriptItem->numConditions++].value = conditionValue;
  }
  if ( !scriptItem->numConditions )
    BG_AnimParseError("BG_ParseConditions: no conditions found");
  return 1;
}

#endif // __UNIMPLEMENTED__
