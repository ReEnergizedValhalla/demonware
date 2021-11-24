// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdmatchmakinginfo.cpp:0x9298C0
void __cdecl Demo_UpdateCurrentSnapshot(LocalClientNum_t localClientNum, playerState_s *ps)
{
  clientActive_t *LocalClientGlobals; // esi
  cg_t *v4; // edi
  unsigned __int8 *v5; // ecx
  Weapon v6; // eax
  cgs_t *cgs; // [esp+18h] [ebp+8h]

  LocalClientGlobals = CL_GetLocalClientGlobals(localClientNum);
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
    v4 = cgArray;
  }
  else
  {
    v4 = 0;
  }
  if ( localClientNum
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\cgame\\../cgame_mp/cg_local_mp.h",
          2195,
          0,
          "((localClientNum == 0))",
          "(localClientNum) = %i",
          localClientNum) )
  {
    __debugbreak();
  }
  cgs = cgsArray;
  Dvar_GetInt(demo_client);
  v5 = (unsigned __int8 *)ps;
  v6.0 = ($190F2CF944EC18EE3AF27F473C4F9DBE)ps->weapon;
  if ( v6.weaponData && *(_BYTE *)&v6.0 )
    v4->weaponSelect = v6;
  if ( LocalClientGlobals->snap.ps.weapon.weaponData != ps->weapon.weaponData )
  {
    v4->weaponSelectTime = v4->time;
    CG_MenuShowNotify(localClientNum, 1);
    v5 = (unsigned __int8 *)ps;
  }
  memcpy((unsigned __int8 *)&LocalClientGlobals->snap.ps, v5, sizeof(LocalClientGlobals->snap.ps));
  memcpy((unsigned __int8 *)&v4->predictedPlayerState, (unsigned __int8 *)ps, sizeof(v4->predictedPlayerState));
  memcpy(
    (unsigned __int8 *)&LocalClientGlobals->snapshots[LocalClientGlobals->packetBackupMask & LocalClientGlobals->snap.messageNum],
    (unsigned __int8 *)&LocalClientGlobals->snap,
    sizeof(LocalClientGlobals->snapshots[LocalClientGlobals->packetBackupMask & LocalClientGlobals->snap.messageNum]));
  v4->snap = v4->nextSnap;
  --cgs->processedSnapshotNum;
  Demo_SetupPlaybackForClient(&LocalClientGlobals->snap.ps, localClientNum);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdmatchmakinginfo.cpp:0x929A00
void __usercall Demo_HandleInputForControllerConfig(
        int key@<edi>,
        LocalClientNum_t localClientNum,
        ControllerIndex_t controllerIndex,
        int pressed)
{
  LocalClientNum_t v4; // esi
  demoClipState clipState; // eax
  bool v6; // bl
  unsigned int Int; // esi
  int Primary; // eax
  float v9; // xmm0_4
  float v10; // xmm0_4
  double v11; // st7
  double v12; // st7
  float v13; // xmm0_4
  double Button; // st7
  double v15; // st7
  float val; // [esp+0h] [ebp-28h]
  float vala; // [esp+0h] [ebp-28h]
  float min; // [esp+4h] [ebp-24h]
  float mina; // [esp+4h] [ebp-24h]
  float timeScale; // [esp+8h] [ebp-20h]
  float timeScalea; // [esp+8h] [ebp-20h]
  float maxa; // [esp+1Ch] [ebp-Ch]
  float max; // [esp+1Ch] [ebp-Ch]
  float maxb; // [esp+1Ch] [ebp-Ch]
  float maxc; // [esp+1Ch] [ebp-Ch]
  float trigValue; // [esp+20h] [ebp-8h]
  float trigValuea; // [esp+20h] [ebp-8h]
  float trigValuec; // [esp+20h] [ebp-8h]
  float trigValued; // [esp+20h] [ebp-8h]
  float trigValuee; // [esp+20h] [ebp-8h]
  float trigValuef; // [esp+20h] [ebp-8h]
  float trigValueg; // [esp+20h] [ebp-8h]
  float trigValueh; // [esp+20h] [ebp-8h]
  float trigValueb; // [esp+20h] [ebp-8h]
  char v35; // [esp+25h] [ebp-3h]
  bool enableTimeScaleAdjustment; // [esp+26h] [ebp-2h]
  bool enableHostControls; // [esp+27h] [ebp-1h]

  v4 = localClientNum;
  v35 = 0;
  if ( demo.playbackInited )
  {
    clipState = demo.playback->clipState;
    if ( clipState == DEMO_CLIP_RECORD_CONTINUOUS || clipState == DEMO_CLIP_RECORD_UNCOMPRESSED_SNAPHOT )
      v35 = 1;
  }
  v6 = Demo_IsPlaying() && demo.header.isDemoClip;
  enableHostControls = Demo_IsHostControlsEnabled();
  enableTimeScaleAdjustment = Demo_IsTimeScaleAdjustmentEnabled(localClientNum);
  if ( Dvar_GetInt(net_showprofile) )
    goto LABEL_95;
  if ( Demo_IsPlaying() && (demo.playbackMode & 4) != 0 )
  {
    Int = 3;
    goto LABEL_10;
  }
  Primary = Com_ControllerIndexes_GetPrimary();
  Int = GamerProfile_GetInt(PROFILE_DEMO_CONTROLLER_CONFIG, (ControllerIndex_t)Primary);
  if ( Int )
  {
LABEL_10:
    if ( Key_IsValidGamePadChar(key) )
    {
      switch ( Int )
      {
        case 1u:
          switch ( key )
          {
            case 18:
              if ( v6 )
                return;
              if ( !enableHostControls )
                return;
              if ( !enableTimeScaleAdjustment )
                return;
              trigValue = GPad_GetButton(controllerIndex, GPAD_L_TRIG);
              if ( (float)GPad_IsButtonPressed(controllerIndex, GPAD_R_TRIG) != 0.0 )
                return;
              if ( trigValue <= 0.80000001 )
                goto LABEL_22;
              if ( Demo_IsPaused() )
                Demo_Pause();
              if ( Com_GetTimeScale() == 0.30000001 )
                goto LABEL_93;
              v9 = FLOAT_0_30000001;
              goto LABEL_92;
            case 19:
              if ( v6 )
                return;
              if ( !enableHostControls )
                return;
              if ( !enableTimeScaleAdjustment )
                return;
              trigValuea = GPad_GetButton(controllerIndex, GPAD_R_TRIG);
              if ( (float)GPad_IsButtonPressed(controllerIndex, GPAD_L_TRIG) != 0.0 )
                return;
              if ( trigValuea <= 0.80000001 )
              {
LABEL_22:
                if ( Com_GetTimeScale() != 1.0 )
                  Demo_SetTimeScale(1.0);
                return;
              }
              if ( Demo_IsPaused() )
                Demo_Pause();
              if ( Com_GetTimeScale() != 3.0 )
              {
                v10 = FLOAT_3_0;
                goto LABEL_84;
              }
              break;
            case 22:
              goto $LN55_7;
            case 23:
              goto $LN63_7;
            default:
              return;
          }
LABEL_85:
          demo.playback->buttonPressTime[9] = Sys_Milliseconds();
          break;
        case 2u:
          switch ( key )
          {
            case 18:
$LN55_7:
              if ( !v35 && enableHostControls && pressed )
                goto LABEL_42;
              return;
            case 19:
              goto $LN63_7;
            case 20:
              if ( v6 || !enableHostControls || !enableTimeScaleAdjustment || !pressed )
                return;
              trigValuec = Dvar_GetFloat(demo_maxTimeScale);
              timeScale = trigValuec;
              min = FLOAT_0_1;
              v11 = Com_GetTimeScale() + 0.1;
              goto LABEL_83;
            case 21:
              if ( v6 || !enableHostControls || !enableTimeScaleAdjustment || !pressed )
                return;
              trigValued = Dvar_GetFloat(demo_maxTimeScale);
              timeScalea = trigValued;
              mina = FLOAT_0_1;
              v12 = Com_GetTimeScale() - 0.1;
              goto LABEL_91;
            case 22:
              if ( !v6 && enableHostControls && enableTimeScaleAdjustment )
              {
                if ( pressed )
                {
                  maxa = Demo_GetTimeScale() - 1.0;
                  v13 = (float)(int)(maxa + 0.4999999990686774);
                  if ( v13 >= 1.0 )
                  {
                    Demo_SetTimeScale(v13);
                    demo.playback->buttonPressTime[8] = Sys_Milliseconds();
                  }
                }
              }
              return;
            case 23:
              if ( v6 )
                return;
              if ( !enableHostControls )
                return;
              if ( !enableTimeScaleAdjustment )
                return;
              if ( !pressed )
                return;
              max = Demo_GetTimeScale() + 1.0;
              trigValuee = (float)(int)(max - 0.4999999990686774);
              if ( Dvar_GetFloat(demo_maxTimeScale) < trigValuee )
                return;
              v10 = (float)(int)(max - 0.4999999990686774);
              goto LABEL_84;
            default:
              return;
          }
        case 3u:
          if ( !(unsigned __int8)Demo_IsShoutcastMode()
            && !Assert_MyHandler(
                  "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
                  8595,
                  0,
                  "(Demo_IsShoutcastMode())",
                  (const char *)&pBlock) )
          {
            __debugbreak();
          }
          switch ( key )
          {
            case 18:
              if ( !v6 && enableHostControls && enableTimeScaleAdjustment )
              {
                Button = GPad_GetButton(controllerIndex, GPAD_L_TRIG);
                goto LABEL_105;
              }
              break;
            case 20:
              if ( !v6 && enableHostControls && enableTimeScaleAdjustment && pressed )
              {
                maxb = Dvar_GetFloat(demo_maxTimeScale);
                timeScale = maxb;
                min = FLOAT_0_1;
                v11 = Com_GetTimeScale() + 0.5;
LABEL_83:
                val = v11;
                trigValuef = I_fclamp(val, min, timeScale);
                v10 = trigValuef;
LABEL_84:
                Demo_SetTimeScale(v10);
                goto LABEL_85;
              }
              break;
            case 21:
              if ( !v6 && enableHostControls && enableTimeScaleAdjustment && pressed )
              {
                maxc = Dvar_GetFloat(demo_maxTimeScale);
                timeScalea = maxc;
                mina = FLOAT_0_1;
                v12 = Com_GetTimeScale() - 0.5;
LABEL_91:
                vala = v12;
                trigValueg = I_fclamp(vala, mina, timeScalea);
                v9 = trigValueg;
LABEL_92:
                Demo_SetTimeScale(v9);
LABEL_93:
                demo.playback->buttonPressTime[8] = Sys_Milliseconds();
              }
              break;
            case 22:
              if ( !v35 && enableHostControls && pressed )
              {
LABEL_42:
                Cbuf_AddText(localClientNum, "demo_back\n");
                goto LABEL_100;
              }
              break;
            case 23:
$LN63_7:
              if ( !v35 && enableHostControls && pressed )
              {
                Cbuf_AddText(localClientNum, "demo_forward\n");
                goto LABEL_120;
              }
              break;
            default:
              return;
          }
          break;
      }
      return;
    }
  }
  v4 = localClientNum;
LABEL_95:
  switch ( key )
  {
    case 18:
    case 156:
      if ( pressed && !v35 && enableHostControls )
      {
        Cbuf_AddText(v4, "demo_back\n");
LABEL_100:
        demo.playback->buttonPressTime[6] = Sys_Milliseconds();
      }
      break;
    case 19:
      if ( !v6 && enableHostControls && enableTimeScaleAdjustment )
      {
        Button = GPad_GetButton(controllerIndex, GPAD_R_TRIG);
LABEL_105:
        if ( Button <= 0.0 )
        {
          trigValueb = *(float *)&FLOAT_1_0;
          if ( !Demo_IsPaused() )
            Demo_Pause();
        }
        else
        {
          if ( Demo_IsPaused() )
            Demo_Pause();
          trigValueh = Button;
          v15 = Dvar_GetFloat(demo_maxTimeScale) * trigValueh;
          trigValueb = v15;
          if ( v15 - 0.1 >= 0.0 )
          {
            if ( trigValueb >= 1.0 )
              demo.playback->buttonPressTime[9] = Sys_Milliseconds();
            else
              demo.playback->buttonPressTime[8] = Sys_Milliseconds();
          }
          else
          {
            trigValueb = FLOAT_0_1;
            demo.playback->buttonPressTime[8] = Sys_Milliseconds();
          }
        }
        Demo_SetTimeScale(trigValueb);
      }
      break;
    case 23:
    case 157:
      if ( !v35 && enableHostControls && pressed )
      {
        Cbuf_AddText(v4, "demo_forward\n");
LABEL_120:
        demo.playback->buttonPressTime[7] = Sys_Milliseconds();
      }
      break;
    default:
      return;
  }
}

#endif // __UNIMPLEMENTED__
