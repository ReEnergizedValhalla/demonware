// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdfileinfo.cpp:0x937F90
unsigned int __cdecl BG_AnimGetConditionValue(animScriptItem_t *scriptItem, int conditionIndex)
{
  animScriptCondition_t *conditions; // ecx
  int v3; // eax

  conditions = scriptItem->conditions;
  v3 = 0;
  if ( scriptItem->numConditions <= 0 )
    return -1;
  while ( conditions->index != conditionIndex )
  {
    ++v3;
    ++conditions;
    if ( v3 >= scriptItem->numConditions )
      return -1;
  }
  return conditions->value;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdfileinfo.cpp:0x937FC0
int __cdecl BG_GetVehicleAnimSetIndex(unsigned __int16 animSetStr)
{
  char *v1; // eax

  v1 = SL_ConvertToString(animSetStr);
  return BG_IndexForString(v1, animVehicleNameStr, 1);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdfileinfo.cpp:0x937FF0
void __usercall BG_SetupAnimNoteTypes(animScriptData_t *scriptData@<esi>)
{
  unsigned int v1; // edi
  unsigned int v2; // eax
  int *p_noteType; // ecx
  animScriptItem_t *v4; // edi
  int v5; // edx
  __int16 *v6; // eax
  int itemIndex; // [esp+4h] [ebp-8h]
  animScriptItem_t **items; // [esp+8h] [ebp-4h]

  BG_CheckThread();
  v1 = _tls_index;
  if ( !*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp", 1053, 0, "(bgs)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v2 = 0;
  if ( scriptData->numAnimations )
  {
    p_noteType = &scriptData->animations[0].noteType;
    do
    {
      *p_noteType = 0;
      ++v2;
      p_noteType += 30;
    }
    while ( v2 < scriptData->numAnimations );
  }
  if ( !*(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v1) + 14960) + 28) )
  {
    itemIndex = 0;
    if ( scriptData->scriptEvents[8].numItems > 0 )
    {
      items = scriptData->scriptEvents[8].items;
      do
      {
        v4 = *items;
        v5 = 0;
        if ( (*items)->numCommands > 0 )
        {
          v6 = &v4->commands[0].bodyPart[1];
          do
          {
            if ( *(v6 - 1) )
              scriptData->animations[v6[1]].noteType = 1;
            if ( *v6 )
              scriptData->animations[v6[2]].noteType = 1;
            ++v5;
            v6 += 10;
          }
          while ( v5 < v4->numCommands );
        }
        ++items;
        ++itemIndex;
      }
      while ( itemIndex < scriptData->scriptEvents[8].numItems );
    }
  }
}

#endif // __UNIMPLEMENTED__
