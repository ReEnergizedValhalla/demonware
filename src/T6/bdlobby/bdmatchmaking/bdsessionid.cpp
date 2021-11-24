// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdsessionid.cpp:0x929710
void __usercall Demo_SetupPlaybackForClient(playerState_s *ps@<eax>, LocalClientNum_t localClientNum)
{
  cg_t *v3; // edi
  clientActive_t *LocalClientGlobals; // ebx
  Weapon v5; // eax
  LocalClientNum_t v6; // ebx
  demoPlayback *playback; // eax
  int DollyCamMarkerForTime; // eax
  double InterpolatedTimeScaleForDollyCamMarker; // st7
  float timeScale; // [esp+10h] [ebp-4h]

  if ( cgArray )
  {
    if ( localClientNum
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\cgame\\../cgame_mp/cg_local_mp.h",
            2171,
            0,
            "((localClientNum == 0))",
            "(localClientNum) = %i",
            localClientNum) )
    {
      __debugbreak();
    }
    v3 = cgArray;
  }
  else
  {
    v3 = 0;
  }
  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
  BG_GetWeaponDef(ps->weapon);
  ps->pm_flags &= ~0x800u;
  v3->clientNum = ps->clientNum;
  v3->weaponSelect.weaponData = ps->weapon.weaponData;
  v5.0 = ($190F2CF944EC18EE3AF27F473C4F9DBE)ps->weapon;
  if ( v5.weaponData && *(_BYTE *)&v5.0 && LocalClientGlobals->snap.ps.weapon.weaponData != v5.weaponData )
  {
    v6 = localClientNum;
    v3->weaponSelectTime = v3->time;
    CG_MenuShowNotify(localClientNum, 1);
  }
  else
  {
    v6 = localClientNum;
  }
  v3->bThirdPerson = 0;
  if ( Dvar_GetFloat(cg_fov) != demo.playback->fov )
    demo.playback->fov = Dvar_GetFloat(cg_fov);
  if ( !Demo_IsDollyCamera() || Demo_IsPlaying() && demo.header.isDemoClip )
    goto LABEL_23;
  if ( !Demo_IsPlaying()
    || !demo.playbackInited
    || (playback = demo.playback, demo.playback->clipState != DEMO_CLIP_PREVIEW) )
  {
    DollyCamMarkerForTime = Demo_GetDollyCamMarkerForTime(v3->time);
    if ( DollyCamMarkerForTime >= 0 )
    {
      InterpolatedTimeScaleForDollyCamMarker = Demo_GetInterpolatedTimeScaleForDollyCamMarker(v6, DollyCamMarkerForTime);
      if ( InterpolatedTimeScaleForDollyCamMarker > 0.0 )
      {
        timeScale = InterpolatedTimeScaleForDollyCamMarker;
        Demo_SetTimeScale(timeScale);
      }
    }
LABEL_23:
    playback = demo.playback;
  }
  if ( demo.playbackInited && playback->clipState == DEMO_CLIP_RECORD_CONTINUOUS )
    Demo_TagPlayers(&playback->segments[playback->segmentCount].taggedPlayers, v6);
}

#endif // __UNIMPLEMENTED__
