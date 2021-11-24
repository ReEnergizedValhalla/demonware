// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x942480
void __cdecl BG_EmblemsCheckEmblemAndBackingUnlocks(const ControllerIndex_t controllerIndex)
{
  EmblemSet *v1; // eax
  int i; // esi
  int v3; // esi

  v1 = s_emblemSet;
  for ( i = 0; i < (int)s_emblemSet[13].layers; ++i )
  {
    BG_UnlockablesEmblemLockedByChallenge(controllerIndex, i);
    v1 = s_emblemSet;
  }
  v3 = 0;
  if ( v1[627].iconCount > 0 )
  {
    do
      BG_UnlockablesEmblemBackingLockedByChallenge(controllerIndex, v3++, 0);
    while ( v3 < s_emblemSet[627].iconCount );
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x9424E0
EmblemBGCategory *__cdecl BG_EmblemsGetCategoryCount()
{
  EmblemSet *v0; // eax

  v0 = s_emblemSet;
  if ( s_emblemSet )
    return v0[6].bgCategories;
  if ( !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          952,
          (int)s_emblemSet,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
    v0 = s_emblemSet;
    return v0[6].bgCategories;
  }
  return s_emblemSet[6].bgCategories;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x942530
const GfxViewParms *__cdecl BG_EmblemsGetCategoryDesc(int index)
{
  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1003,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( index < 0 || index > (int)s_emblemSet[6].bgCategories )
    return &pBlock;
  else
    return (const GfxViewParms *)*((_DWORD *)&s_emblemSet[6].icons + 2 * index);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x942590
EmblemIcon *__cdecl BG_EmblemsGetBackgroundCount()
{
  EmblemSet *v0; // eax

  v0 = s_emblemSet;
  if ( s_emblemSet )
    return v0[975].icons;
  if ( !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1013,
          (int)s_emblemSet,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
    v0 = s_emblemSet;
    return v0[975].icons;
  }
  return s_emblemSet[975].icons;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x9425E0
__int16 __cdecl BG_EmblemsGetBackgroundID(int index)
{
  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1059,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( index < 0 || index >= (int)s_emblemSet[975].icons )
    return -1;
  else
    return *((_WORD *)&s_emblemSet[975].backgroundCount + index);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x942640
int __cdecl BG_EmblemsGetBackgroundIndex(__int16 id)
{
  EmblemIcon *icons; // edx
  int result; // eax
  int *i; // ecx

  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1071,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  icons = s_emblemSet[975].icons;
  result = 0;
  if ( (int)icons <= 0 )
    return -1;
  for ( i = &s_emblemSet[975].backgroundCount; *(_WORD *)i != id; i = (int *)((char *)i + 2) )
  {
    if ( ++result >= (int)icons )
      return -1;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x9426B0
int __cdecl BG_EmblemsGetBackgroundCost(__int16 id)
{
  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1136,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( id < 0 || id >= s_emblemSet[627].iconCount )
    return -1;
  else
    return *((_DWORD *)&s_emblemSet[627].backgrounds + 9 * id);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x9426B0
int __cdecl BG_EmblemsGetBackgroundCost(__int16 id)
{
  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1136,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( id < 0 || id >= s_emblemSet[627].iconCount )
    return -1;
  else
    return *((_DWORD *)&s_emblemSet[627].backgrounds + 9 * id);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x942710
int __cdecl BG_EmblemsGetBackgroundUnlockLevel(__int16 id)
{
  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1146,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( id < 0 || id >= s_emblemSet[627].iconCount )
    return -1;
  else
    return *(&s_emblemSet[627].backgroundLookupCount + 9 * id);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x942770
int __cdecl BG_EmblemsGetBackgroundUnlockPLevel(__int16 id)
{
  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1156,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( id < 0 || id >= s_emblemSet[627].iconCount )
    return -1;
  else
    return *((_DWORD *)&s_emblemSet[627].backgroundLookup + 9 * id);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x9427D0
int __cdecl BG_EmblemsGetBackgroundUnclassifyAt(__int16 id)
{
  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1166,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( id < 0 || id >= s_emblemSet[627].iconCount )
    return 0;
  else
    return *(&s_emblemSet[628].colorCount + 9 * id);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x942830
EmblemIcon *__cdecl BG_EmblemsGetBackgroundMaterial(__int16 id)
{
  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1176,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( id < 0 || id >= s_emblemSet[627].iconCount )
    return (EmblemIcon *)s_missingEmblemMaterial;
  else
    return (&s_emblemSet[627].icons)[9 * id];
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x942890
int __cdecl BG_EmblemsGetBackgroundMTXIndex(__int16 id)
{
  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1197,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( id < 0 || id >= s_emblemSet[627].iconCount )
    return -1;
  else
    return *(&s_emblemSet[628].categoryCount + 9 * id);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x9428F0
bool __cdecl BG_EmblemsIsBackgroundMTX(__int16 id)
{
  return BG_EmblemsGetBackgroundMTXIndex(id) != -1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x942AA0
emblemChallengeLookup_t *__cdecl BG_EmblemGetChallengeLookup(__int16 emblemIndex)
{
  emblemChallengeLookup_t *result; // eax

  result = 0;
  if ( emblemIndex < (int)s_emblemSet[13].layers
    && s_emblemChallengeTable.emblemChallengeLookups[emblemIndex].challengeIndex != -1 )
  {
    return (emblemChallengeLookup_t *)(4 * emblemIndex + 136343912);
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x942AD0
emblemChallengeLookup_t *__cdecl BG_EmblemBackingGetChallengeLookup(__int16 backingIndex)
{
  emblemChallengeLookup_t *result; // eax

  result = 0;
  if ( backingIndex < s_emblemSet[627].iconCount )
    return (emblemChallengeLookup_t *)(4 * backingIndex + 136348008);
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x942AF0
void __cdecl BG_EmblemsClearDefaults()
{
  BGDefaultEmblem *v0; // eax

  v0 = s_defaultEmblems;
  do
  {
    v0->maxlevel = -1;
    v0->minlevel = -1;
    ++v0;
  }
  while ( (int)v0 < (int)bg_iconNames );
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x942B20
void __cdecl BG_EmblemsSetDefaultForLevel(int minlevel, int maxlevel, CompositeEmblemLayer *s_emblem, int layerCount)
{
  int v4; // esi
  BGDefaultEmblem *v5; // eax
  int v6; // esi

  if ( minlevel < 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          2289,
          0,
          "(minlevel >= 0)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( maxlevel < 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          2290,
          0,
          "(maxlevel >= 0)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( minlevel > maxlevel
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          2291,
          0,
          "(minlevel <= maxlevel)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v4 = 0;
  v5 = s_defaultEmblems;
  while ( v5->minlevel != -1 )
  {
    ++v5;
    ++v4;
    if ( (int)v5 >= (int)bg_iconNames )
    {
      Com_PrintError(10, "Ran out of default emblem slots\n");
      return;
    }
  }
  v6 = v4;
  if ( s_defaultEmblems[v6].maxlevel != -1
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          2297,
          0,
          "(s_defaultEmblems[def].maxlevel == -1)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  s_defaultEmblems[v6].layerCount = layerCount;
  s_defaultEmblems[v6].minlevel = minlevel;
  s_defaultEmblems[v6].maxlevel = maxlevel;
  memcpy((unsigned __int8 *)s_defaultEmblems[v6].layers, (unsigned __int8 *)s_emblem, 44 * layerCount);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x942C40
void __cdecl BG_EmblemsGenerateDefault(
        ControllerIndex_t controllerIndex,
        int level,
        CompositeEmblemLayer *layers,
        int layerCount)
{
  CompositeEmblemLayer *v4; // esi
  int v5; // edi
  int *p_maxlevel; // esi
  int v7; // eax

  if ( layerCount > 0 )
  {
    v4 = layers;
    v5 = layerCount;
    do
    {
      CL_CompositeClearLayer(v4++);
      --v5;
    }
    while ( v5 );
  }
  p_maxlevel = &s_defaultEmblems[0].maxlevel;
  do
  {
    if ( *(p_maxlevel - 1) <= level && *p_maxlevel >= level )
    {
      v7 = p_maxlevel[353];
      if ( v7 >= layerCount )
        v7 = layerCount;
      memcpy((unsigned __int8 *)layers, (unsigned __int8 *)p_maxlevel + 4, 44 * v7);
    }
    p_maxlevel += 355;
  }
  while ( (int)p_maxlevel < (int)&bg_iconNames[1] );
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x9432D0
int __cdecl BG_EmblemsGetIconCount(
        ControllerIndex_t controllerIndex,
        unsigned __int16 include,
        unsigned __int16 exclude)
{
  return BG_EmblemsGetResults(controllerIndex, include, exclude)->count;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x9432F0
__int16 __cdecl BG_EmblemsGetIconID(
        ControllerIndex_t controllerIndex,
        int index,
        unsigned __int16 include,
        unsigned __int16 exclude)
{
  ResultCache *Results; // ecx
  int count; // esi

  Results = BG_EmblemsGetResults(controllerIndex, include, exclude);
  count = Results->count;
  if ( count > 0 )
    return Results->ids[index % count];
  else
    return -1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x943330
const char *__cdecl BG_EmblemsGetIconDesc(ControllerIndex_t controllerIndex, __int16 id)
{
  int IconUnclassifyAt; // esi

  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          566,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( id < 0 || id >= (int)s_emblemSet[13].layers )
    return 0;
  if ( controllerIndex == INVALID_CONTROLLER_PORT )
    return (const char *)*((_DWORD *)&s_emblemSet[13].categories + 9 * id);
  IconUnclassifyAt = BG_EmblemsGetIconUnclassifyAt(id);
  if ( BG_EmblemsGetResults(controllerIndex, 2u, 0)->count >= IconUnclassifyAt )
    return (const char *)*((_DWORD *)&s_emblemSet[13].categories + 9 * id);
  return "@MENU_CLASSIFIED";
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x9433C0
const char *__cdecl BG_EmblemsGetIconUnlockDesc(ControllerIndex_t controllerIndex, __int16 id)
{
  int IconUnclassifyAt; // edi
  int count; // ebx
  int Prestige; // eax
  int v5; // edi
  const char *v6; // eax
  int v8; // [esp-4h] [ebp-1Ch]
  int rank; // [esp+Ch] [ebp-Ch]
  int unlockLevel; // [esp+10h] [ebp-8h]
  int unlockPLevel; // [esp+14h] [ebp-4h]

  unlockLevel = BG_EmblemsGetIconUnlockLevel(id);
  unlockPLevel = BG_EmblemsGetIconUnlockPLevel(id);
  IconUnclassifyAt = BG_EmblemsGetIconUnclassifyAt(id);
  count = BG_EmblemsGetResults(controllerIndex, 2u, 0)->count;
  rank = LiveStats_GetRank(controllerIndex);
  Prestige = LiveStats_GetPrestige(controllerIndex);
  if ( count >= IconUnclassifyAt )
  {
    if ( unlockPLevel > Prestige )
    {
      v8 = unlockPLevel;
      v6 = UI_SafeTranslateString("CLASS_PRESTIGE_UNLOCK_DESC");
      return UI_ReplaceConversionInt(v6, v8);
    }
    if ( Prestige <= 0 && unlockLevel > rank )
    {
      v8 = unlockLevel + 1;
      v6 = UI_SafeTranslateString("PERKS_UNLOCKED_AT_LV");
      return UI_ReplaceConversionInt(v6, v8);
    }
    return (const char *)&pBlock;
  }
  else
  {
    v5 = IconUnclassifyAt - count;
    if ( v5 > 1 )
    {
      v8 = v5;
      v6 = UI_SafeTranslateString("MENU_EMBLEM_ICON_CLASSIFIED_TOOLTIP");
      return UI_ReplaceConversionInt(v6, v8);
    }
    return "@MENU_EMBLEM_ICON_CLASSIFIED_TOOLTIP_SING";
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x943470
bool __cdecl BG_EmblemsIsIconClassified(ControllerIndex_t controllerIndex, __int16 id)
{
  int IconUnlockPLevel; // esi
  int IconUnclassifyAt; // esi

  if ( allEmblemsUnlocked && Dvar_GetBool(allEmblemsUnlocked) )
    return 0;
  IconUnlockPLevel = BG_EmblemsGetIconUnlockPLevel(id);
  if ( IconUnlockPLevel && IconUnlockPLevel > LiveStats_GetPrestige(controllerIndex) )
    return 1;
  IconUnclassifyAt = BG_EmblemsGetIconUnclassifyAt(id);
  return IconUnclassifyAt > BG_EmblemsGetResults(controllerIndex, 2u, 0)->count;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x9434E0
char __cdecl BG_EmblemsIsBackgroundLocked(ControllerIndex_t controllerIndex, __int16 id)
{
  int BackgroundUnlockLevel; // ebx
  int BackgroundUnlockPLevel; // esi
  int Prestige; // eax

  if ( allEmblemsUnlocked && Dvar_GetBool(allEmblemsUnlocked) )
    return 0;
  if ( BG_EmblemsIsBackgroundClassified(controllerIndex, id)
    || BG_UnlockablesEmblemBackingLockedByChallenge(controllerIndex, id, 0) )
  {
    return 1;
  }
  BackgroundUnlockLevel = BG_EmblemsGetBackgroundUnlockLevel(id);
  BackgroundUnlockPLevel = BG_EmblemsGetBackgroundUnlockPLevel(id);
  Prestige = LiveStats_GetPrestige(controllerIndex);
  if ( BackgroundUnlockPLevel )
    return BackgroundUnlockPLevel > Prestige;
  if ( Prestige <= 0 )
    return BackgroundUnlockLevel > LiveStats_GetRank(controllerIndex);
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x943580
void __usercall BG_HeliCmdScale(const char *move@<esi>, vec4_t *outFracs@<edi>, bool scaleMovement)
{
  int v3; // xmm3_4
  int v4; // eax
  float v5; // xmm0_4
  int v6; // ecx
  int v7; // eax
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4

  if ( !move
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp", 42, 0, "(move)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  outFracs->v[0] = (float)*move * 0.0078740157;
  outFracs->v[1] = (float)move[1] * 0.0078740157;
  outFracs->v[2] = (float)move[2] * 0.0078740157;
  outFracs->v[3] = (float)move[3] * 0.0078740157;
  v3 = _mask__AbsFloat_;
  if ( *move || move[1] )
  {
    v4 = *move;
    v5 = (float)(move[1] * move[1] + v4 * v4);
    v6 = abs8(v4);
    v7 = abs8(move[1]);
    if ( v7 > v6 )
      v6 = v7;
    v8 = fsqrt(v5);
    if ( v6 )
    {
      v9 = (float)v6 / v8;
      outFracs->v[0] = outFracs->v[0] * v9;
      outFracs->v[1] = outFracs->v[1] * v9;
    }
    if ( COERCE_FLOAT(LODWORD(outFracs->v[1]) & _mask__AbsFloat_) < 0.30000001 )
      outFracs->v[1] = 0.0;
    if ( scaleMovement )
    {
      v10 = *(float *)&FLOAT_1_0;
      LODWORD(v11) = LODWORD(outFracs->v[0]) & _mask__AbsFloat_;
      LODWORD(v12) = LODWORD(outFracs->v[1]) & _mask__AbsFloat_;
      if ( v11 > 1.0 )
      {
        if ( !Assert_MyHandler(
                "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
                71,
                0,
                "(absAxis[0] <= 1.0f)",
                (const char *)&pBlock) )
          __debugbreak();
        v10 = *(float *)&FLOAT_1_0;
      }
      if ( v10 < v12 )
      {
        if ( !Assert_MyHandler(
                "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
                72,
                0,
                "(absAxis[1] <= 1.0f)",
                (const char *)&pBlock) )
          __debugbreak();
        v10 = *(float *)&FLOAT_1_0;
      }
      if ( v11 <= v12 )
        outFracs->v[0] = (float)(v10 - (float)(v12 - v11)) * outFracs->v[0];
      else
        outFracs->v[1] = (float)(v10 - (float)(v11 - v12)) * outFracs->v[1];
      v3 = _mask__AbsFloat_;
    }
  }
  if ( COERCE_FLOAT(LODWORD(outFracs->v[2]) & v3) < 0.30000001 )
    outFracs->v[2] = 0.0;
  if ( COERCE_FLOAT(LODWORD(outFracs->v[3]) & v3) < 0.30000001 )
    outFracs->v[3] = 0.0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x9437B0
void __usercall BG_HeliCalcAccelFromTilt(
        vec3_t *bodyAccel@<ecx>,
        vec3_t *rotAccel@<edx>,
        const pmove_t *pm,
        const pml_t *pml,
        VehicleState *vehicleState,
        vec4_t *moveRequest)
{
  const VehicleDef *VehicleDef; // ebx
  float accel; // xmm0_4
  float maxSpeedVertical; // xmm1_4
  float accelVertical; // xmm7_4
  float v10; // xmm5_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float z; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm7_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  vec3_t *p_bodyVelocity; // eax
  float v19; // xmm1_4
  float v20; // xmm4_4
  int i; // esi
  float v22; // xmm0_4
  float x; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm3_4
  float v26; // xmm0_4
  float vehHelicopterTiltMomentum; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm0_4
  float v32; // xmm3_4
  float v33; // xmm1_4
  float v34; // xmm4_4
  float v35; // xmm6_4
  float v36; // xmm0_4
  float frametime; // xmm4_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm3_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  bool v43; // cc
  float v44; // xmm0_4
  float v45; // xmm0_4
  bool v46; // cc
  vec2_t *p_tilt; // ebx
  int j; // esi
  float v49; // xmm2_4
  float v50; // xmm0_4
  float v51; // xmm1_4
  float v52; // xmm0_4
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm5_4
  float v56; // xmm4_4
  float v57; // xmm3_4
  float v58; // xmm1_4
  float v59; // xmm0_4
  float v60; // xmm0_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  float v63; // xmm0_4
  float v64; // xmm2_4
  bool v65; // cf
  float v66; // xmm1_4
  playerState_s *ps; // eax
  __m128 v68; // xmm0
  __m128 v69; // xmm3
  __m128 v70; // xmm1
  __m128 v71; // xmm2
  __m128 v72; // xmm4
  __m128 v73; // xmm2
  __m128 v74; // xmm3
  float rotRate; // xmm2_4
  float v76; // xmm0_4
  float tgt; // xmm1_4
  float v78; // xmm1_4
  float v79; // xmm2_4
  float v80; // xmm0_4
  int k; // esi
  float deltaTime; // [esp+Ch] [ebp-B0h]
  float rate; // [esp+1Ch] [ebp-A0h]
  float cur; // [esp+20h] [ebp-9Ch]
  float v85; // [esp+24h] [ebp-98h]
  float tgtSpeed; // [esp+2Ch] [ebp-90h]
  float speedParallel; // [esp+30h] [ebp-8Ch]
  const VehicleDef *vehDef; // [esp+34h] [ebp-88h]
  float v91; // [esp+3Ch] [ebp-80h]
  float v92; // [esp+44h] [ebp-78h]
  vec3_t *nextState; // [esp+48h] [ebp-74h]
  float nextStatea; // [esp+48h] [ebp-74h]
  float nextStateb; // [esp+48h] [ebp-74h]
  float nextStatec; // [esp+48h] [ebp-74h]
  float nextStated; // [esp+48h] [ebp-74h]
  float tgtYawVel; // [esp+4Ch] [ebp-70h]
  float tgtYawVela; // [esp+4Ch] [ebp-70h]
  vec3_t velOrthogonal; // [esp+50h] [ebp-6Ch]
  vec3_t maxAccel; // [esp+5Ch] [ebp-60h]
  vec3_t velParallel; // [esp+68h] [ebp-54h] BYREF
  vec4_t track; // [esp+74h] [ebp-48h]
  vec3_t maxSpeed; // [esp+84h] [ebp-38h]
  vec3_t tgtVel; // [esp+90h] [ebp-2Ch]
  vec2_t newAccel; // [esp+9Ch] [ebp-20h]
  vec2_t decel; // [esp+A4h] [ebp-18h]
  float vehHelicopterDecelerationSide; // [esp+ACh] [ebp-10h]
  vec2_t newDecel; // [esp+B0h] [ebp-Ch]

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp", 405, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !pm->ps
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          406,
          0,
          "(pm->ps)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  VehicleDef = BG_GetVehicleDef(pm);
  vehDef = VehicleDef;
  if ( !VehicleDef
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          409,
          0,
          "(vehDef)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  accel = VehicleDef->accel;
  maxSpeedVertical = VehicleDef->maxSpeedVertical;
  accelVertical = VehicleDef->accelVertical;
  v10 = *(float *)&FLOAT_1_0;
  maxSpeed.x = VehicleDef->maxSpeed;
  *(_QWORD *)&maxSpeed.v[1] = __PAIR64__(LODWORD(maxSpeedVertical), LODWORD(maxSpeed.x));
  maxAccel.x = accel;
  *(_QWORD *)&maxAccel.v[1] = __PAIR64__(LODWORD(accelVertical), LODWORD(accel));
  if ( maxSpeed.x == 0.0 )
    LODWORD(track.v[0]) = FLOAT_1_0;
  else
    track.v[0] = accel / maxSpeed.x;
  if ( maxSpeed.x == 0.0 )
    LODWORD(track.v[1]) = FLOAT_1_0;
  else
    track.v[1] = accel / maxSpeed.x;
  if ( maxSpeedVertical == 0.0 )
    LODWORD(track.v[2]) = FLOAT_1_0;
  else
    track.v[2] = accelVertical / maxSpeedVertical;
  v11 = maxSpeed.x * moveRequest->v[0];
  v12 = moveRequest->v[1] * maxSpeed.x;
  z = moveRequest->v[2] * maxSpeedVertical;
  v14 = (float)(v12 * v12) + (float)(v11 * v11);
  tgtVel.x = v11;
  *(_QWORD *)&tgtVel.v[1] = __PAIR64__(LODWORD(z), LODWORD(v12));
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(fsqrt(v14)) ^ _mask__NegFloat_) < 0.0 )
    v15 = fsqrt(v14);
  else
    v15 = *(float *)&FLOAT_1_0;
  v16 = v11 * (float)(1.0 / v15);
  v17 = v12 * (float)(1.0 / v15);
  decel = (vec2_t)__PAIR64__(LODWORD(v17), LODWORD(v16));
  if ( maxSpeed.z == 0.0 )
  {
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
            440,
            0,
            "(maxSpeed[2])",
            (const char *)&pBlock) )
      __debugbreak();
    v10 = *(float *)&FLOAT_1_0;
    z = tgtVel.z;
    v16 = decel.v[0];
    v17 = decel.v[1];
  }
  vehHelicopterDecelerationSide = z / maxSpeed.z;
  tgtSpeed = fsqrt((float)(z * z) + v14);
  p_bodyVelocity = &vehicleState->bodyVelocity;
  if ( v10 <= tgtSpeed )
  {
    v19 = (float)(v17 * vehicleState->bodyVelocity.y) + (float)(v16 * vehicleState->bodyVelocity.x);
    velOrthogonal.x = (float)(v16 * COERCE_FLOAT(LODWORD(v19) ^ _mask__NegFloat_)) + p_bodyVelocity->x;
    velParallel.y = v17 * v19;
    speedParallel = v19;
    velOrthogonal.y = (float)(v17 * COERCE_FLOAT(LODWORD(v19) ^ _mask__NegFloat_)) + vehicleState->bodyVelocity.y;
    velOrthogonal.z = 0.0;
    velParallel.x = v16 * v19;
    velParallel.z = vehHelicopterDecelerationSide * z;
  }
  else
  {
    *(_QWORD *)&velOrthogonal.x = *(_QWORD *)&p_bodyVelocity->x;
    tgtSpeed = 0.0;
    speedParallel = 0.0;
    velOrthogonal.z = vehicleState->bodyVelocity.z;
    memset(&velParallel, 0, sizeof(velParallel));
  }
  v20 = percent;
  nextState = &vehicleState->bodyVelocity;
  for ( i = 0; i < 2; ++i )
  {
    v22 = *(float *)((char *)&tgtVel.x + i * 4);
    x = nextState->x;
    v24 = v10 / *(float *)((char *)&maxSpeed.x + i * 4);
    if ( v22 <= nextState->x )
      decel.v[i] = COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(x - v22) * v24) * (float)(v10 - v20)) ^ _mask__NegFloat_)
                 + (float)((float)(v22 * v20) * v24);
    else
      decel.v[i] = (float)((float)((float)(v22 - x) * v24) * (float)(v10 - v20)) + (float)((float)(v22 * v20) * v24);
    v92 = decel.v[i];
    if ( (LODWORD(v92) & 0x7F800000) == 2139095040 )
    {
      if ( !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
              475,
              0,
              "(!IS_NAN(targetTilt[axis]))",
              (const char *)&pBlock) )
        __debugbreak();
      v10 = *(float *)&FLOAT_1_0;
      v20 = percent;
    }
    if ( (float)(v92 - v10) < 0.0 )
      v25 = v92;
    else
      v25 = v10;
    if ( (float)(-1.0 - v92) < 0.0 )
      v26 = v25;
    else
      v26 = FLOAT_N1_0;
    nextState = (vec3_t *)((char *)nextState + 4);
    decel.v[i] = v26;
  }
  vehHelicopterTiltMomentum = VehicleDef->vehHelicopterTiltMomentum;
  v28 = decel.v[0] - vehicleState->tilt.v[0];
  v29 = decel.v[1] - vehicleState->tilt.v[1];
  newDecel.v[0] = v28;
  newDecel.v[1] = v29;
  if ( vehHelicopterTiltMomentum == 0.0 )
  {
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
            482,
            0,
            "(vehDef->vehHelicopterTiltMomentum)",
            (const char *)&pBlock) )
      __debugbreak();
    v29 = newDecel.v[1];
    v10 = *(float *)&FLOAT_1_0;
    v28 = newDecel.v[0];
  }
  v30 = vehicleState->tiltVelocity.v[1];
  v31 = v10 / VehicleDef->vehHelicopterTiltMomentum;
  v32 = (float)(VehicleDef->tiltSpeed[0] * v31) * v28;
  v33 = v31 * -1.0;
  v34 = (float)(VehicleDef->tiltSpeed[1] * v31) * v29;
  v35 = vehicleState->tiltVelocity.v[0];
  v36 = (float)((float)(v31 * -1.0) * v30) + v34;
  frametime = pml->frametime;
  v38 = (float)((float)((float)(v33 * v35) + v32) * frametime) + v35;
  vehicleState->tiltVelocity.v[0] = v38;
  v39 = (float)(v36 * frametime) + vehicleState->tiltVelocity.v[1];
  vehicleState->tiltVelocity.v[1] = v39;
  v40 = pml->frametime;
  v41 = (float)((float)((float)(v38 + v35) * 0.5) * v40) + vehicleState->tilt.v[0];
  vehicleState->tilt.v[0] = v41;
  vehicleState->tilt.v[1] = (float)((float)((float)(v39 + v30) * 0.5) * v40) + vehicleState->tilt.v[1];
  if ( v41 <= v10 )
  {
    if ( v41 >= -1.0 )
      goto LABEL_54;
    v43 = vehicleState->tiltVelocity.v[0] >= 0.0;
    vehicleState->tilt.v[0] = FLOAT_N1_0;
  }
  else
  {
    v42 = vehicleState->tiltVelocity.v[0];
    vehicleState->tilt.v[0] = v10;
    v43 = v42 <= 0.0;
  }
  if ( !v43 )
    vehicleState->tiltVelocity.v[0] = 0.0;
LABEL_54:
  v44 = vehicleState->tilt.v[1];
  if ( v44 <= v10 )
  {
    if ( v44 >= -1.0 )
      goto LABEL_60;
    v46 = vehicleState->tiltVelocity.v[1] >= 0.0;
    vehicleState->tilt.v[1] = FLOAT_N1_0;
  }
  else
  {
    v45 = vehicleState->tiltVelocity.v[1];
    vehicleState->tilt.v[1] = v10;
    v46 = v45 <= 0.0;
  }
  if ( !v46 )
    vehicleState->tiltVelocity.v[1] = 0.0;
LABEL_60:
  rotAccel->x = VehicleDef->maxBodyPitch * vehicleState->tilt.v[0];
  rotAccel->z = VehicleDef->maxBodyRoll * vehicleState->tilt.v[1];
  decel.v[1] = VehicleDef->vehHelicopterDecelerationFwd;
  vehHelicopterDecelerationSide = VehicleDef->vehHelicopterDecelerationSide;
  newAccel = 0i64;
  newDecel = 0i64;
  p_tilt = &vehicleState->tilt;
  for ( j = 0; j < 2; ++j )
  {
    v85 = track.v[j];
    rate = decel.v[j + 1] * v85;
    cur = *(float *)((char *)&velOrthogonal.x + j * 4);
    nextStatea = DiffTrack(0.0, cur, rate, pml->frametime);
    v49 = pml->frametime;
    v50 = (float)(nextStatea - cur) / v49;
    if ( v50 < 0.0 && (v51 = p_tilt->v[0], p_tilt->v[0] < 0.0) || v50 > 0.0 && (v51 = p_tilt->v[0], p_tilt->v[0] > 0.0) )
      newDecel.v[j] = COERCE_FLOAT(LODWORD(v51) & _mask__AbsFloat_) * v50;
    v52 = *(float *)((char *)&velParallel.x + j * 4);
    if ( tgtSpeed <= speedParallel )
    {
      nextStatec = DiffTrack(*(float *)((char *)&tgtVel.x + j * 4), v52, rate, v49);
      newDecel.v[j] = (float)((float)(nextStatec - v52) / pml->frametime) + newDecel.v[j];
    }
    else
    {
      nextStateb = DiffTrack(*(float *)((char *)&tgtVel.x + j * 4), v52, v85, v49);
      v53 = (float)(nextStateb - v52) / pml->frametime;
      if ( v53 < 0.0 && (v54 = p_tilt->v[0], p_tilt->v[0] < 0.0)
        || v53 > 0.0 && (v54 = p_tilt->v[0], p_tilt->v[0] > 0.0) )
      {
        newAccel.v[j] = (float)(COERCE_FLOAT(LODWORD(v54) & _mask__AbsFloat_) * v53) + newAccel.v[j];
      }
    }
    v55 = newAccel.v[j];
    v56 = newDecel.v[j];
    v57 = *(float *)((char *)&maxAccel.x + j * 4);
    *(float *)((char *)&bodyAccel->x + j * 4) = v55 + v56;
    LODWORD(v58) = LODWORD(v57) ^ _mask__NegFloat_;
    if ( (float)((float)(v55 + v56) - v57) < 0.0 )
      v91 = v55 + v56;
    else
      v91 = v57;
    if ( (float)(v58 - (float)(v55 + v56)) < 0.0 )
      v59 = v91;
    else
      LODWORD(v59) = LODWORD(v57) ^ _mask__NegFloat_;
    *(float *)((char *)&bodyAccel->x + j * 4) = v59;
    v60 = v57;
    if ( (float)(v56 - v57) < 0.0 )
      v60 = v56;
    if ( (float)(v58 - v56) >= 0.0 )
      LODWORD(v60) = LODWORD(v57) ^ _mask__NegFloat_;
    newDecel.v[j] = v60;
    if ( (float)(v55 - v57) < 0.0 )
      v57 = v55;
    if ( (float)(v58 - v55) < 0.0 )
      v58 = v57;
    newAccel.v[j] = v58;
    p_tilt = (vec2_t *)((char *)p_tilt + 4);
  }
  v61 = vehicleState->bodyVelocity.z;
  if ( (v61 <= tgtVel.z || v61 <= 0.0) && (tgtVel.z <= v61 || v61 >= 0.0) )
    v62 = track.v[2];
  else
    v62 = vehDef->vehHelicopterDecelerationUp * track.v[2];
  nextStated = DiffTrack(tgtVel.z, v61, v62, pml->frametime);
  v63 = (float)(nextStated - vehicleState->bodyVelocity.z) / pml->frametime;
  v64 = maxAccel.z;
  v65 = (float)(v63 - maxAccel.z) < 0.0;
  bodyAccel->z = v63;
  LODWORD(v66) = LODWORD(v64) ^ _mask__NegFloat_;
  if ( v65 )
    v64 = v63;
  if ( (float)(v66 - v63) < 0.0 )
    v66 = v64;
  bodyAccel->z = v66;
  if ( vehDef->rotRate <= 0.0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          555,
          0,
          "(vehDef->rotRate > 0.0f)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = pm->ps;
  deltaTime = pml->frametime;
  track.v[3] = vehDef->rotAccel / vehDef->rotRate;
  tgtYawVel = DiffTrackAngle(ps->viewangles.y, vehicleState->previousAngles.y, track.v[3], deltaTime);
  v68 = (__m128)LODWORD(tgtYawVel);
  v68.m128_f32[0] = (float)(tgtYawVel - vehicleState->previousAngles.y) * 0.0027777778;
  v69.m128_f32[0] = FLOAT_8388608_0;
  v70 = v68;
  v70.m128_f32[0] = v68.m128_f32[0] + 0.5;
  v71 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v70);
  v72.m128_i32[0] = v71.m128_i32[0];
  v69.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v70, v71), v69).m128_u32[0] | v71.m128_i32[0];
  v73 = v70;
  v73.m128_f32[0] = (float)((float)(v68.m128_f32[0] + 0.5) + v69.m128_f32[0]) - v69.m128_f32[0];
  v74 = v73;
  v74.m128_f32[0] = v73.m128_f32[0] - (float)(v68.m128_f32[0] + 0.5);
  v68.m128_f32[0] = (float)(v68.m128_f32[0]
                          - (float)(v73.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v74, v72).m128_u32[0] & FLOAT_1_0)))
                  * 360.0;
  rotRate = vehDef->rotRate;
  v76 = v68.m128_f32[0] * (float)(1.0 / pml->frametime);
  LODWORD(tgt) = LODWORD(rotRate) ^ _mask__NegFloat_;
  if ( (float)(v76 - rotRate) < 0.0 )
    rotRate = v76;
  if ( (float)(tgt - v76) < 0.0 )
    tgt = rotRate;
  if ( COERCE_FLOAT(LODWORD(tgt) & _mask__AbsFloat_) > COERCE_FLOAT(LODWORD(vehicleState->angVelocity.y) & _mask__AbsFloat_) )
  {
    tgtYawVela = DiffTrack(tgt, vehicleState->angVelocity.y, track.v[3], pml->frametime);
    tgt = tgtYawVela;
  }
  v78 = (float)(tgt - vehicleState->angVelocity.y) / pml->frametime;
  rotAccel->y = v78;
  v79 = vehDef->rotAccel;
  LODWORD(v80) = LODWORD(v79) ^ _mask__NegFloat_;
  if ( (float)(v78 - v79) < 0.0 )
    v79 = v78;
  if ( (float)(v80 - v78) < 0.0 )
    v80 = v79;
  rotAccel->y = v80;
  for ( k = 0; k < 8; k += 4 )
  {
    if ( *(float *)((char *)&maxSpeed.x + k) <= 0.0 )
    {
      if ( vehDef->maxSpeed <= 0.0
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
              572,
              0,
              "(vehDef->maxSpeed > 0.0f)",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      *(float *)((char *)&maxSpeed.x + k) = vehDef->maxSpeed * 17.6;
    }
    if ( *(float *)((char *)&maxAccel.x + k) <= 0.0 )
    {
      if ( vehDef->accel <= 0.0
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
              577,
              0,
              "(vehDef->accel > 0.0f)",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      *(float *)((char *)&maxAccel.x + k) = vehDef->accel * 17.6;
    }
  }
  if ( ((LODWORD(bodyAccel->x) & 0x7F800000) == 2139095040
     || (LODWORD(bodyAccel->y) & 0x7F800000) == 2139095040
     || (LODWORD(bodyAccel->z) & 0x7F800000) == 2139095040)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          668,
          0,
          "(!IS_NAN((bodyAccel)[0]) && !IS_NAN((bodyAccel)[1]) && !IS_NAN((bodyAccel)[2]))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( ((LODWORD(rotAccel->x) & 0x7F800000) == 2139095040
     || (LODWORD(rotAccel->y) & 0x7F800000) == 2139095040
     || (LODWORD(rotAccel->z) & 0x7F800000) == 2139095040)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          669,
          0,
          "(!IS_NAN((rotAccel)[0]) && !IS_NAN((rotAccel)[1]) && !IS_NAN((rotAccel)[2]))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x944430
void __cdecl BG_HelicopterHeightTrace(
        pmove_t *pm,
        VehicleState *vehicleState,
        trace_t *trace,
        vec3_t *hitOrigin,
        float dt,
        float trace_offset)
{
  float z; // xmm2_4
  float y; // xmm1_4
  float fraction; // xmm0_4
  int entity; // [esp-8h] [ebp-34h]
  int clipmask; // [esp-4h] [ebp-30h]
  vec3_t startTrace; // [esp+10h] [ebp-1Ch] BYREF
  vec3_t endTrace; // [esp+1Ch] [ebp-10h] BYREF

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp", 679, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !pm->ps
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          680,
          0,
          "(pm->ps)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !trace
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          681,
          0,
          "(trace)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  z = vehicleState->origin.z;
  y = vehicleState->origin.y;
  clipmask = vehicleState->clipmask;
  entity = vehicleState->entity;
  startTrace.x = vehicleState->origin.x;
  startTrace.y = y;
  startTrace.z = z + trace_offset;
  *(_QWORD *)&endTrace.x = __PAIR64__(LODWORD(y), LODWORD(startTrace.x));
  endTrace.z = z;
  PM_trace(pm, trace, &startTrace, &vec3_origin, &vec3_origin, &endTrace, entity, clipmask);
  fraction = trace->fraction;
  if ( fraction < 1.0 )
  {
    hitOrigin->x = (float)((float)(endTrace.x - startTrace.x) * fraction) + startTrace.x;
    hitOrigin->y = (float)((float)(endTrace.y - startTrace.y) * fraction) + startTrace.y;
    hitOrigin->z = (float)((float)(endTrace.z - startTrace.z) * fraction) + startTrace.z;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnet.cpp:0x944590
void __cdecl BG_HelicopterGroundTrace(
        pmove_t *pm,
        VehicleState *vehicleState,
        GroundTrace *groundTrace,
        float dt,
        float trace_offset)
{
  float x; // xmm1_4
  float y; // xmm2_4
  float fraction; // xmm0_4
  float v8; // xmm0_4
  int entity; // [esp-8h] [ebp-30h]
  int clipmask; // [esp-4h] [ebp-2Ch]
  vec3_t startTrace; // [esp+Ch] [ebp-1Ch] BYREF
  vec3_t endTrace; // [esp+18h] [ebp-10h] BYREF

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp", 697, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !pm->ps
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          698,
          0,
          "(pm->ps)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !groundTrace
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_helicopter.cpp",
          699,
          0,
          "(groundTrace)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  x = vehicleState->origin.x;
  y = vehicleState->origin.y;
  clipmask = vehicleState->clipmask;
  entity = vehicleState->entity;
  startTrace.z = vehicleState->origin.z;
  *(_QWORD *)&startTrace.x = __PAIR64__(LODWORD(y), LODWORD(x));
  *(_QWORD *)&endTrace.x = __PAIR64__(LODWORD(y), LODWORD(x));
  endTrace.z = startTrace.z - trace_offset;
  PM_trace(pm, &groundTrace->trace, &startTrace, &vec3_origin, &vec3_origin, &endTrace, entity, clipmask);
  fraction = groundTrace->trace.fraction;
  if ( fraction >= 1.0 )
  {
    groundTrace->location = endTrace;
  }
  else
  {
    groundTrace->location.x = (float)((float)(endTrace.x - startTrace.x) * fraction) + startTrace.x;
    groundTrace->location.y = (float)((float)(endTrace.y - startTrace.y) * fraction) + startTrace.y;
    groundTrace->location.z = (float)((float)(endTrace.z - startTrace.z) * fraction) + startTrace.z;
  }
  v8 = groundTrace->trace.fraction;
  groundTrace->hasGround = 0;
  groundTrace->onGround = 0;
  groundTrace->validGroundNormal = 0;
  if ( v8 < 1.0 )
  {
    groundTrace->hasGround = 1;
    groundTrace->onGround = 1;
    if ( groundTrace->trace.walkable
      || groundTrace->trace.normal.vec.m128_f32[2] >= Dvar_GetFloat(bg_vehicle_ground_min_normal) )
    {
      groundTrace->validGroundNormal = 1;
    }
  }
}

#endif // __UNIMPLEMENTED__
