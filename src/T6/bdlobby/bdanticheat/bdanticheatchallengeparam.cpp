// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdanticheatchallengeparam.cpp:0x942240
double __cdecl BG_EmblemsGetIconOutlineSize(__int16 id)
{
  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          686,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( id < 0 || id >= (int)s_emblemSet[13].layers )
    return 0.0;
  else
    return *((float *)&s_emblemSet[13].iconTypeCount + 9 * id);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdanticheatchallengeparam.cpp:0x9422A0
bool __usercall BG_EmblemsCheckDLCLocked@<al>(emblemChallengeLookup_t *challengeLookup@<esi>)
{
  challengeTableRow_t *ChallengeRowByIndex; // eax
  bool result; // al

  result = 0;
  if ( Dvar_GetBool(tu6_hideDLCImages) )
  {
    if ( challengeLookup )
    {
      if ( challengeLookup->challengeIndex != -1 )
      {
        ChallengeRowByIndex = CL_GetChallengeRowByIndex(challengeLookup->challengeIndex);
        if ( ChallengeRowByIndex )
        {
          if ( ChallengeRowByIndex->type == 1
            && BG_UnlockablesGetItemDLCIndex(challengeLookup->itemIndex)
            && BG_UnlockablesDLCWeaponDisabled(challengeLookup->itemIndex) )
          {
            return 1;
          }
        }
      }
    }
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdanticheatchallengeparam.cpp:0x942300
char __cdecl BG_EmblemsIsIconLocked(ControllerIndex_t controllerIndex, __int16 id)
{
  int IconUnlockPLevel; // ebx
  int unlockLevel; // [esp+0h] [ebp-8h]
  int prestige; // [esp+4h] [ebp-4h]

  if ( allEmblemsUnlocked && Dvar_GetBool(allEmblemsUnlocked) )
    return 0;
  unlockLevel = BG_EmblemsGetIconUnlockLevel(id);
  IconUnlockPLevel = BG_EmblemsGetIconUnlockPLevel(id);
  prestige = LiveStats_GetPrestige(controllerIndex);
  if ( BG_UnlockablesEmblemLockedByChallenge(controllerIndex, id) )
    return 1;
  if ( IconUnlockPLevel )
    return IconUnlockPLevel > prestige;
  if ( prestige <= 0 )
    return unlockLevel > LiveStats_GetRank(controllerIndex);
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdanticheatchallengeparam.cpp:0x9423A0
bool __cdecl BG_EmblemsIsIconPurchased(ControllerIndex_t controllerIndex, __int16 id)
{
  const ddlState_t *RootDDLState; // eax
  persistentStats *StatsBufferWithCaller; // eax
  char *v5; // [esp-10h] [ebp-24h]
  ddlState_t searchState; // [esp+0h] [ebp-14h] BYREF

  if ( allEmblemsPurchased && Dvar_GetBool(allEmblemsPurchased) )
    return 1;
  if ( BG_EmblemsIsIconLocked(controllerIndex, id) )
    return 0;
  if ( !BG_EmblemsGetIconCost(id) )
    return 1;
  v5 = va("%d", id);
  RootDDLState = LiveStats_GetRootDDLState();
  if ( !DDL_MoveTo(RootDDLState, &searchState, 4, "emblemStats", "icons", v5) )
  {
    Com_PrintError(32, "DDL: Error could not find emblem icon %d\n", id);
    return 0;
  }
  StatsBufferWithCaller = LiveStorage_GetStatsBufferWithCaller(
                            controllerIndex,
                            "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
                            "BG_EmblemsIsIconPurchased",
                            798,
                            STATS_LOCATION_NORMAL,
                            1);
  return DDL_GetUInt(&searchState, StatsBufferWithCaller->statsBuffer) != 0;
}

#endif // __UNIMPLEMENTED__
