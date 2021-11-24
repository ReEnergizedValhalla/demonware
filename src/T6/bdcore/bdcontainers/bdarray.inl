// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x534550
void __cdecl PartyInfo_SetFlag(PartyInfo *party, int flag, bool enable)
{
  if ( !party
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\client_mp\\partyprober.cpp",
          176,
          0,
          "(party)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( enable )
    party->flags |= flag;
  else
    party->flags &= ~flag;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x5345A0
bool __cdecl PartyInfo_GetFlag(PartyInfo *party, int flag)
{
  if ( !party
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\client_mp\\partyprober.cpp",
          186,
          0,
          "(party)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  return (flag & party->flags) == flag;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x5345E0
int __cdecl PartyInfo_GetGeoMatch(const PartyInfo *host)
{
  const bdDMLHierarchicalInfo *GeoLocation; // ecx
  int result; // eax

  GeoLocation = Live_GetGeoLocation();
  result = 0;
  if ( GeoLocation )
  {
    if ( GeoLocation->m_tier0 == host->geo1 )
    {
      result = 1;
      if ( GeoLocation->m_tier1 == host->geo2 )
      {
        result = 2;
        if ( GeoLocation->m_tier2 == host->geo3 )
        {
          result = 3;
          if ( GeoLocation->m_tier3 == host->geo4 )
            return 4;
        }
      }
    }
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x534640
char *__cdecl PrettyFlags(int flags)
{
  int v1; // edi
  unsigned int i; // esi

  pretty[0] = 0;
  v1 = 1;
  for ( i = 0; i < 11; ++i )
  {
    if ( (v1 & flags) != 0 )
      I_strncat(pretty, 256, s_prettyFlags[i]);
    v1 = __ROL4__(v1, 1);
  }
  return pretty;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x925480
void __cdecl Demo_OpenManageSegments(LocalClientNum_t localClientNum)
{
  CG_CloseScoreboard(localClientNum);
  Key_SetCatcher(localClientNum, 8);
  UI_OpenMenu(localClientNum, "demo_manage_segments");
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x9254B0
void __cdecl Demo_ReadHeader()
{
  int Long; // eax

  demo.header.version = MSG_ReadByte(&demo.msg);
  demo.header.maxClients = MSG_ReadByte(&demo.msg);
  Long = MSG_ReadLong(&demo.msg);
  demo.header.defaultClient = Long;
  if ( (Long < 0 || Long >= demo.header.maxClients)
    && Long != -1
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
          6024,
          0,
          "(( demo.header.defaultClient >= CLIENT_INDEX_FIRST && demo.header.defaultClient < demo.header.maxClients ) || "
          "demo.header.defaultClient == INVALID_CLIENT_INDEX)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  demo.header.isDemoClip = MSG_ReadBit(&demo.msg) != 0;
  demo.header.hasExtraNetworkProfileData = MSG_ReadBit(&demo.msg) != 0;
  demo.header.isZombie = MSG_ReadBit(&demo.msg) != 0;
  demo.header.settings.onlinegame = MSG_ReadBit(&demo.msg) != 0;
  demo.header.settings.xblive_privatematch = MSG_ReadBit(&demo.msg) != 0;
  demo.header.settings.xblive_wagermatch = MSG_ReadBit(&demo.msg) != 0;
  demo.header.settings.systemlink = MSG_ReadBit(&demo.msg) != 0;
  demo.header.settings.isClientConsole = MSG_ReadBit(&demo.msg) != 0;
  demo.header.settings.isDedicatedServer = MSG_ReadBit(&demo.msg) != 0;
  if ( !Com_GametypeSettings_Read(&demo.msg) )
    Com_Error(ERR_DROP, "EXE_GAMESETTINGS");
  Demo_Printf(3, "DEMO Header: Version: %d\n", demo.header.version);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x941E40
int __cdecl BG_EmblemsGetUnlockedLayerCount(ControllerIndex_t controllerIndex)
{
  int Rank; // edi
  int Prestige; // esi
  int result; // eax
  int layerCount; // edx
  int *p_categoryCount; // ecx

  Rank = LiveStats_GetRank(controllerIndex);
  Prestige = LiveStats_GetPrestige(controllerIndex);
  if ( allEmblemsUnlocked && Dvar_GetBool(allEmblemsUnlocked) )
    return s_emblemSet->layerCount;
  if ( Prestige > 0 )
    return s_emblemSet->layerCount;
  layerCount = s_emblemSet->layerCount;
  result = 0;
  if ( layerCount > 0 )
  {
    p_categoryCount = &s_emblemSet->categoryCount;
    do
    {
      if ( *p_categoryCount > Rank )
        break;
      ++result;
      p_categoryCount += 3;
    }
    while ( result < layerCount );
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x941EB0
EmblemLayer *__cdecl BG_EmblemsGetLayerCost(int layer)
{
  if ( layer < 0 || layer >= s_emblemSet->layerCount )
    return 0;
  else
    return (&s_emblemSet->layers)[3 * layer];
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x941EE0
int __cdecl BG_EmblemsGetLayerUnlockLevel(int layer)
{
  if ( layer < 0 || layer >= s_emblemSet->layerCount )
    return 0;
  else
    return *(&s_emblemSet->categoryCount + 3 * layer);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x941F10
int __cdecl BG_EmblemsGetPurchasedLayerCount(ControllerIndex_t controllerIndex)
{
  const ddlState_t *RootDDLState; // eax
  persistentStats *StatsBufferWithCaller; // eax
  ddlState_t searchState; // [esp+0h] [ebp-14h] BYREF

  if ( allEmblemsPurchased && Dvar_GetBool(allEmblemsPurchased) )
    return BG_EmblemsGetUnlockedLayerCount(controllerIndex);
  RootDDLState = LiveStats_GetRootDDLState();
  if ( DDL_MoveTo(RootDDLState, &searchState, 2, "emblemStats", "layersPurchased") )
  {
    StatsBufferWithCaller = LiveStorage_GetStatsBufferWithCaller(
                              controllerIndex,
                              "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
                              "BG_EmblemsGetPurchasedLayerCount",
                              182,
                              STATS_LOCATION_NORMAL,
                              1);
    return DDL_GetUInt(&searchState, StatsBufferWithCaller->statsBuffer);
  }
  else
  {
    Com_PrintError(32, "DDL: Error could not find layersPurchased\n");
    return 0;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x941FA0
int __cdecl ResultSort(const void *a, const void *b)
{
  char *v2; // esi
  char *v3; // edx
  char v4; // cl

  v2 = (char *)s_emblemSet + 36 * *(__int16 *)a;
  v3 = (char *)s_emblemSet + 36 * *(__int16 *)b;
  v4 = v3[826] & 1;
  if ( (v2[826] & 1) != 0 )
  {
    if ( !v4 )
      return 1;
  }
  else if ( v4 )
  {
    return -1;
  }
  return *((_DWORD *)v2 + 205) - *((_DWORD *)v3 + 205);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x942910
bool __cdecl BG_EmblemsIsBackgroundPurchased(ControllerIndex_t controllerIndex, __int16 id)
{
  const ddlState_t *RootDDLState; // eax
  persistentStats *StatsBufferWithCaller; // eax
  char *v5; // [esp-8h] [ebp-20h]
  ddlState_t searchState; // [esp+4h] [ebp-14h] BYREF

  if ( BG_EmblemsGetBackgroundMTXIndex(id) != -1 )
    return 0;
  if ( allEmblemsPurchased && Dvar_GetBool(allEmblemsPurchased) || !BG_EmblemsGetBackgroundCost(id) )
    return 1;
  v5 = va("%d", id);
  RootDDLState = LiveStats_GetRootDDLState();
  if ( !DDL_MoveTo(RootDDLState, &searchState, 4, "emblemStats", "backgrounds", v5) )
  {
    Com_PrintError(32, "DDL: Error could not find emblem background %d\n", id);
    return 0;
  }
  StatsBufferWithCaller = LiveStorage_GetStatsBufferWithCaller(
                            controllerIndex,
                            "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
                            "BG_EmblemsIsBackgroundPurchased",
                            1385,
                            STATS_LOCATION_NORMAL,
                            1);
  return DDL_GetUInt(&searchState, StatsBufferWithCaller->statsBuffer) != 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x9429E0
GfxColor *__cdecl BG_GetSwatchColorByIndex(int rowNumber, int columnNumber)
{
  if ( rowNumber >= 9
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1615,
          0,
          "(rowNumber < 9)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( rowNumber < 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1616,
          0,
          "(rowNumber >= 0)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( columnNumber >= 13
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1618,
          0,
          "(columnNumber < 13)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( columnNumber < 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1619,
          0,
          "(columnNumber >= 0)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  return (GfxColor *)(4 * (columnNumber + 13 * rowNumber) + 136350336);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x942CB0
bool __cdecl BG_EmblemsIsIconHidden(ControllerIndex_t controllerIndex, __int16 id)
{
  emblemChallengeLookup_t *v3; // esi

  if ( BG_UnlockablesEmblemIsElite(id) && !R_Is3DOn() )
    return 1;
  v3 = 0;
  if ( id < (int)s_emblemSet[13].layers && s_emblemChallengeTable.emblemChallengeLookups[id].challengeIndex != -1 )
    v3 = (emblemChallengeLookup_t *)(4 * id + 136343912);
  if ( BG_EmblemsCheckDLCLocked(v3) )
    return 1;
  return BG_EmblemsIsIconLocked(controllerIndex, id) && BG_EmblemsGetIconUnclassifyAt(id) > 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x942D40
int __cdecl BG_EmblemsGetPurchasedBackgroundCount(ControllerIndex_t controllerIndex)
{
  ControllerIndex_t v1; // edi
  bool v3; // zf
  EmblemIcon *icons; // ebx
  int v5; // esi
  int v6; // edi
  __int16 v7; // ax

  v1 = controllerIndex;
  if ( controllerIndex
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1034,
          0,
          "(unsigned)(controllerIndex) < (unsigned)(1)",
          "controllerIndex doesn't index MAX_GPAD_COUNT\n\t%i not in [0, %i)",
          controllerIndex,
          1) )
  {
    __debugbreak();
  }
  if ( s_backgroundPurchasedCount[controllerIndex].flush == s_flushCount )
    return s_backgroundPurchasedCount[controllerIndex].count;
  v3 = s_emblemSet == 0;
  s_backgroundPurchasedCount[controllerIndex].count = 0;
  if ( v3
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1013,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  icons = s_emblemSet[975].icons;
  v5 = 0;
  if ( (int)icons > 0 )
  {
    v6 = 58544;
    do
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
      if ( v5 < 0 || v5 >= (int)s_emblemSet[975].icons )
        v7 = -1;
      else
        v7 = *(_WORD *)((char *)&s_emblemSet->colorCount + v6);
      if ( BG_EmblemsIsBackgroundPurchased(controllerIndex, v7) )
        ++s_backgroundPurchasedCount[controllerIndex].count;
      ++v5;
      v6 += 2;
    }
    while ( v5 < (int)icons );
    v1 = controllerIndex;
  }
  s_backgroundPurchasedCount[v1].flush = s_flushCount;
  return s_backgroundPurchasedCount[controllerIndex].count;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x942E70
const char *__cdecl BG_EmblemsGetBackgroundDesc(ControllerIndex_t controllerIndex, __int16 id)
{
  int BackgroundUnclassifyAt; // edi

  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          1084,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( id < 0 || id >= s_emblemSet[627].iconCount )
    return (const char *)&pBlock;
  BackgroundUnclassifyAt = BG_EmblemsGetBackgroundUnclassifyAt(id);
  if ( BG_EmblemsGetPurchasedBackgroundCount(controllerIndex) >= BackgroundUnclassifyAt )
    return (const char *)*(&s_emblemSet[627].backgroundCount + 9 * id);
  else
    return "MENU_CLASSIFIED";
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x94E750
BOOL __cdecl BG_CanItemBeGrabbed(const entityState_s *ent, const playerState_s *ps, int touched)
{
  BOOL result; // eax
  Weapon v4; // eax

  if ( !ent
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 1713, 0, "(ent)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 1714, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (ps->weapFlags & 0x80) != 0 || ent->clientNum == ps->clientNum )
    return 0;
  BG_GetWeaponDef(ent->weapon);
  result = 1;
  if ( !WeaponEntCanBeGrabbed(ps, ent, touched, ent->weapon) )
  {
    BG_GetWeaponVariantDef(ent->weapon);
    v4.0 = BG_GetAltWeapon(ent->weapon).0;
    if ( !v4.weaponData || !*(_BYTE *)&v4.0 || !WeaponEntCanBeGrabbed(ps, ent, touched, v4) )
      return 0;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x94F430
bool __cdecl BG_ValidateOrigin(const vec3_t *pos, const vec3_t *mapCenter)
{
  return BG_ValidateOrigin(pos, 0x10u, mapCenter, 0x11u);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x94F450
bool __cdecl BG_ValidateZOriginValue(const float val, const float mapCenterValue)
{
  return (int)val <= (int)(float)(mapCenterValue + 65536.0) && (int)val >= (int)(float)(mapCenterValue - 65536.0);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x94F490
void __cdecl BG_PlayerToEntitySetPitchAngles(playerState_s *ps, entityState_s *s)
{
  LocalClientNum_t v2; // xmm6_4
  float v3; // xmm5_4
  __m128 fTorsoPitch_low; // xmm0
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  __m128 fWaistPitch_low; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm4
  __m128 v14; // xmm2
  __m128 v15; // xmm3

  if ( PM_GetEffectiveStance(ps) == 1 )
  {
    if ( ps->viewHeightLerpTime )
    {
      v2 = FLOAT_1_0;
      v3 = (float)(ps->commandTime - ps->viewHeightLerpTime)
         / (float)PM_GetViewHeightLerpTime(ps, ps->viewHeightLerpTarget, ps->viewHeightLerpDown);
      if ( v3 >= 0.0 )
      {
        if ( v3 > 1.0 )
          v3 = *(float *)&FLOAT_1_0;
      }
      else
      {
        v3 = 0.0;
      }
      if ( !ps->viewHeightLerpDown )
        v3 = 1.0 - v3;
    }
    else
    {
      v2 = FLOAT_1_0;
      v3 = *(float *)&FLOAT_1_0;
    }
    fTorsoPitch_low = (__m128)LODWORD(ps->fTorsoPitch);
    fTorsoPitch_low.m128_f32[0] = fTorsoPitch_low.m128_f32[0] * 0.0027777778;
    v5.m128_f32[0] = FLOAT_8388608_0;
    v6 = fTorsoPitch_low;
    v6.m128_f32[0] = fTorsoPitch_low.m128_f32[0] + 0.5;
    v7 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v6);
    v8.m128_i32[0] = v7.m128_i32[0];
    v5.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v6, v7), v5).m128_u32[0] | v7.m128_i32[0];
    v9 = v6;
    v9.m128_f32[0] = (float)((float)(fTorsoPitch_low.m128_f32[0] + 0.5) + v5.m128_f32[0]) - v5.m128_f32[0];
    v10 = v9;
    v10.m128_f32[0] = v9.m128_f32[0] - (float)(fTorsoPitch_low.m128_f32[0] + 0.5);
    v9.m128_f32[0] = v9.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v10, v8).m128_u32[0] & v2);
    v10.m128_f32[0] = FLOAT_8388608_0;
    s->un2.animState.fAimUpDown = (float)((float)(fTorsoPitch_low.m128_f32[0] - v9.m128_f32[0]) * 360.0) * v3;
    fWaistPitch_low = (__m128)LODWORD(ps->fWaistPitch);
    fWaistPitch_low.m128_f32[0] = fWaistPitch_low.m128_f32[0] * 0.0027777778;
    v12 = fWaistPitch_low;
    v12.m128_f32[0] = fWaistPitch_low.m128_f32[0] + 0.5;
    v13 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v12);
    v10.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v12, v13), v10).m128_u32[0] | v13.m128_i32[0];
    v14 = v12;
    v14.m128_f32[0] = (float)((float)(fWaistPitch_low.m128_f32[0] + 0.5) + v10.m128_f32[0]) - v10.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - (float)(fWaistPitch_low.m128_f32[0] + 0.5);
    s->un2.animState.fAimLeftRight = (float)((float)(fWaistPitch_low.m128_f32[0]
                                                   - (float)(v14.m128_f32[0]
                                                           - COERCE_FLOAT(_mm_cmpgt_ss(v15, v13).m128_u32[0] & v2)))
                                           * 360.0)
                                   * v3;
    s->lerp.u.player.proneLegsAngle = (int)(AngleNormalize360(ps->proneDirection) * 0.0027777778 * 255.0);
  }
  else
  {
    *((_QWORD *)&s->un2.fx + 1) = 0i64;
  }
}

#endif // __UNIMPLEMENTED__
