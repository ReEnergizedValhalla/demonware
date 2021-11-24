// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdhttpwrapperbase.cpp:0x9410B0
void __cdecl BG_LocalEvalVehicleSeatTo(pmove_t *pm)
{
  playerState_s *ps; // eax
  int eFlags; // ecx

  ps = pm->ps;
  eFlags = pm->ps->eFlags;
  if ( (eFlags & 0x4000) != 0 && (eFlags & 0x10000) == 0 && (ps->eFlags2 & 0x10000000) == 0 )
    BG_SetConditionBit(ps->clientNum, 19, ps->vehiclePos);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapperbase.cpp:0x941100
void __cdecl BG_LocalEvalEvent(pmove_t *pm)
{
  playerState_s *ps; // esi

  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animconditions.cpp",
          613,
          0,
          "(ps)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (ps->pm_flags & 0x100000) != 0 )
  {
    if ( !ps->scriptedAnimTime )
      BG_SetConditionValue(ps->clientNum, 23, ps->scriptedAnim);
    if ( pm->cmd.serverTime < ps->scriptedAnimTime )
      BG_SetConditionValue(ps->clientNum, 23, ps->scriptedAnim);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapperbase.cpp:0x941190
void __cdecl BG_LocalEvalFiring(pmove_t *pm)
{
  if ( pm->cmd.button_bits.array[0] >= 0 )
    BG_SetConditionValue(pm->ps->clientNum, 12, 0i64);
  else
    BG_SetConditionValue(pm->ps->clientNum, 12, 1ui64);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapperbase.cpp:0x9411E0
void __usercall Dtp_RegisterDvars(double a1@<st0>)
{
  dtp = _Dvar_RegisterBool(a1, "dtp", 1, 0x4080u, "Turn on/off the dive to prone functionality");
  dtp_debug = _Dvar_RegisterBool(a1, "dtp_debug", 0, 0x4080u, "Turn on/off dive to prone debug draw path");
  dtp_max_slide_duration = _Dvar_RegisterFloat(
                             a1,
                             "dtp_max_slide_duration",
                             300.0,
                             0.0,
                             10000.0,
                             0x4080u,
                             "Determines the max time the slide portion of the dtp move will take");
  dtp_max_slide_addition = _Dvar_RegisterFloat(
                             a1,
                             "dtp_max_slide_addition",
                             0.0,
                             0.0,
                             10000.0,
                             0x4080u,
                             "Additional slide time should the player land on a mantle-able surface");
  dtp_startup_delay = _Dvar_RegisterFloat(
                        a1,
                        "dtp_startup_delay",
                        250.0,
                        100.0,
                        10000.0,
                        0x4080u,
                        "Determines how long the player has to sprint before the dtp move can trigger");
  dtp_post_move_pause = _Dvar_RegisterFloat(
                          a1,
                          "dtp_post_move_pause",
                          100.0,
                          0.0,
                          10000.0,
                          0x4080u,
                          "Duration of the post move pause");
  dtp_fall_damage_min_height = _Dvar_RegisterFloat(
                                 a1,
                                 "dtp_fall_damage_min_height",
                                 65.0,
                                 0.0,
                                 1000.0,
                                 0x4080u,
                                 "If the player dive to prone from less than this dvar value, he will not receive any kill damage");
  dtp_fall_damage_max_height = _Dvar_RegisterFloat(
                                 a1,
                                 "dtp_fall_damage_max_height",
                                 200.0,
                                 0.0,
                                 1000.0,
                                 0x4080u,
                                 "If the player dives to prone from more than this dvar value, he will receive kill damage");
  dtp_exhaustion_window = _Dvar_RegisterFloat(
                            a1,
                            "dtp_exhaustion_window",
                            1500.0,
                            100.0,
                            10000.0,
                            0x4080u,
                            "Determines how long the player has to sprint before the dtp move can trigger");
  dtp_min_speed = _Dvar_RegisterFloat(
                    a1,
                    "dtp_min_speed",
                    3.1600001,
                    0.0,
                    1000.0,
                    0x4080u,
                    "Minimum player speed required to start a DTP or sustain a DTP");
  door_breach_weapondrop = _Dvar_RegisterBool(
                             a1,
                             "door_breach_weapondrop",
                             1,
                             0x4080u,
                             "Turn on/off the waepon drop/rise for during door breach");
  dtp_new_trajectory = _Dvar_RegisterBool(a1, "dtp_new_trajectory", 1, 0x4080u, "Use new dive to prone trajectory");
  dtp_new_trajectory_multiplier = _Dvar_RegisterFloat(
                                    a1,
                                    "dtp_new_trajectory_multiplier",
                                    2.0,
                                    0.0,
                                    10.0,
                                    0x4080u,
                                    "New dive to prone trajectory modifier");
  dtp_max_apex_duration = _Dvar_RegisterInt(
                            a1,
                            "dtp_max_apex_duration",
                            400,
                            0,
                            10000,
                            0x4080u,
                            "Determines the max time in milliseconds the dtp will spend at the apex of the jump");
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdhttpwrapperbase.cpp:0x9414E0
int __cdecl Dtp_CalcSurfaceType(pmove_t *pm, pml_t *pml)
{
  return Dtp_SurfaceRemapTable[PM_GroundSurfaceType(pm->ps, pml)];
}

#endif // __UNIMPLEMENTED__
