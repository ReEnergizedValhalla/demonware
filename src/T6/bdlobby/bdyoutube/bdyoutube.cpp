// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdyoutube.cpp:0x9375B0
void __cdecl BG_Dog_Move_Walk(LocalClientNum_t localClientNum, const entityState_s *es, ActorAnimStates prevState)
{
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax
  XAnimTree_s *v7; // eax
  XAnimTree_s *v8; // eax

  v3 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v4 = (DObj *)v3;
  if ( v3 )
  {
    if ( prevState != ACTOR_ANIMATION_MOVE_RUN )
    {
      Tree = DObjGetTree(v3);
      XAnimClearTreeGoalWeights(Tree, 0x2Du, 0.0, -1);
      v6 = DObjGetTree(v4);
      XAnimClearTreeGoalWeights(v6, 3u, 0.0, -1);
      v7 = DObjGetTree(v4);
      XAnimClearTreeGoalWeights(v7, 0xAu, 0.2, -1);
      v8 = DObjGetTree(v4);
      XAnimClearTreeGoalWeights(v8, 0xBu, 0.2, -1);
      BG_Dog_Clear_Traverse_Anims(prevState, localClientNum, es);
    }
    XAnimSetCompleteGoalWeight(
      v4,
      2u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960) + 602012),
      2u,
      0,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdyoutube.cpp:0x9376F0
int __cdecl BG_ActorIsProne(actor_prone_info_s *pInfo, int iCurrentTime)
{
  int iProneTrans; // ecx
  int iProneTime; // esi

  if ( !pInfo->prone || pInfo->bCorpseOrientation || pInfo->orientPitch )
    return 0;
  iProneTrans = pInfo->iProneTrans;
  if ( !iProneTrans )
    return 1;
  iProneTime = pInfo->iProneTime;
  if ( iProneTrans >= 0 )
  {
    if ( iProneTrans + iProneTime < iCurrentTime )
      pInfo->iProneTrans = 0;
  }
  else if ( iProneTime - iProneTrans < iCurrentTime )
  {
    pInfo->prone = 0;
    return 0;
  }
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdyoutube.cpp:0x937740
double __cdecl BG_GetActorProneFraction(actor_prone_info_s *pInfo, int iCurrentTime)
{
  int iProneTrans; // eax
  int v3; // esi
  double result; // st7
  int iProneTime; // edx

  if ( !pInfo->prone )
    return 0.0;
  iProneTrans = pInfo->iProneTrans;
  if ( !iProneTrans )
    return 1.0;
  if ( iProneTrans >= 0 )
  {
    iProneTime = pInfo->iProneTime;
    if ( iProneTime + iProneTrans >= iCurrentTime )
    {
      return (double)(iCurrentTime - iProneTime) / (double)iProneTrans;
    }
    else
    {
      result = 1.0;
      pInfo->iProneTrans = 0;
    }
  }
  else
  {
    v3 = pInfo->iProneTime;
    if ( v3 - iProneTrans >= iCurrentTime )
    {
      return 1.0 - (double)(iCurrentTime - v3) / (double)-iProneTrans;
    }
    else
    {
      result = 0.0;
      pInfo->prone = 0;
    }
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdyoutube.cpp:0x9377D0
const char *__cdecl BG_GetPlayerAnimScriptFileName()
{
  const char *result; // eax
  bool v1; // cc

  if ( Com_SessionMode_IsZombiesGame() )
  {
    if ( Demo_IsPlaying() && Demo_GetVersion() <= 3 )
    {
      return globalPlayerAnimScriptFileName_zm_v1;
    }
    else if ( Demo_IsPlaying() && Demo_GetVersion() <= 4 )
    {
      return globalPlayerAnimScriptFileName_zm_v2;
    }
    else if ( Demo_IsPlaying() && Demo_GetVersion() <= 8 )
    {
      return globalPlayerAnimScriptFileName_zm_v3;
    }
    else if ( Demo_IsPlaying() && Demo_GetVersion() <= 10 )
    {
      return globalPlayerAnimScriptFileName_zm_v4;
    }
    else
    {
      return globalPlayerAnimScriptFileName_zm;
    }
  }
  else
  {
    if ( !Demo_IsPlaying() )
      return globalPlayerAnimScriptFileName;
    v1 = Demo_GetVersion() <= 9;
    result = globalPlayerAnimScriptFileName_v1;
    if ( !v1 )
      return globalPlayerAnimScriptFileName;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdyoutube.cpp:0x937870
void __cdecl TRACK_bg_animation_mp()
{
  track_static_alloc_internal(numDefines, 100, "numDefines", 11);
  track_static_alloc_internal(defineStrings, 10000, "defineStrings", 11);
  track_static_alloc_internal(defineStr, 3200, "defineStr", 11);
  track_static_alloc_internal(defineBits, 1600, "defineBits", 11);
  track_static_alloc_internal(weaponStrings, 2048, "weaponStrings", 11);
  track_static_alloc_internal(animStateStr, 16, "animStateStr", 11);
  track_static_alloc_internal(animMoveTypesStr, 224, "animMoveTypesStr", 11);
  track_static_alloc_internal(animEventTypesStr, 304, "animEventTypesStr", 11);
  track_static_alloc_internal(animBodyPartsStr, 40, "animBodyPartsStr", 11);
  track_static_alloc_internal(animConditionMountedStr, 24, "animConditionMountedStr", 11);
  track_static_alloc_internal(animWeaponClassStr, 120, "animWeaponClassStr", 11);
  track_static_alloc_internal(animWeaponPositionStr, 32, "animWeaponPositionStr", 11);
  track_static_alloc_internal(animStrafeStateStr, 32, "animStrafeStateStr", 11);
  track_static_alloc_internal(animSlopeStateStr, 32, "animSlopeStateStr", 11);
  track_static_alloc_internal(animPerkStateStr, 64, "animPerkStateStr", 11);
  track_static_alloc_internal(animAttachmentStateStr, 24, "animAttachmentStateStr", 11);
  track_static_alloc_internal(animConditionsStr, 208, "animConditionsStr", 11);
  track_static_alloc_internal(animConditionsTable, 400, "animConditionsTable", 11);
  track_static_alloc_internal(animVehicleSeatStr, 96, "animVehicleSeatStr", 11);
  track_static_alloc_internal(animVehicleEntryPosStr, 32, "animVehicleEntryPosStr", 11);
  track_static_alloc_internal(animVehicleAnimTypeStr, 24, "animVehicleAnimTypeStr", 11);
}

#endif // __UNIMPLEMENTED__
