// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdnattypediscoverypacketreply.cpp:0x959500
bool __usercall PM_SprintEndingButtons@<al>(const pmove_t *pm@<eax>)
{
  playerState_s *ps; // eax
  playerState_s *v4; // esi
  Weapon v5; // eax
  int v6; // eax
  int v7; // eax
  playerState_s *v8; // edi
  int weaponstate; // eax
  int pm_flags; // eax

  ps = pm->ps;
  if ( ps->waterlevel >= 2
    || (ps->pm_flags & 0x10018) != 0
    || pm->cmd.forwardmove <= Dvar_GetInt(player_sprintForwardMinimum) )
  {
    return 1;
  }
  v4 = pm->ps;
  if ( (Com_BitCheckAssert(pm->ps->perks, 42, 0xFFFFFFF) > 0
     || (v5.0 = BG_GetViewmodelWeaponIndex(v4).0, BG_WeaponHasPerk(v5, 0x2Au)))
    && Com_SessionMode_IsMode(SESSIONMODE_ZOMBIES) )
  {
    v6 = pm->cmd.button_bits.array[0];
    if ( (v6 & 0x20000000) == 0 && v6 >= 0 )
      return (v6 & 0x80) != 0;
  }
  else
  {
    v7 = pm->cmd.button_bits.array[0];
    if ( (v7 & 0x200000) == 0
      && (v7 & 0x8000000) == 0
      && (v7 & 0x20000000) == 0
      && v7 >= 0
      && (v7 & 0x4000000) == 0
      && (v7 & 0x20000) == 0
      && (v7 & 0x10000) == 0
      && ((v7 & 0x800000) == 0 || BG_WeaponBlocksProne(pm->ps->weapon))
      && (pm->cmd.button_bits.array[0] & 0x400000) == 0
      && pm->ps->leanf == 0.0
      && ((pm->cmd.button_bits.array[0] & 0x80) == 0
       || BG_GetWeaponDef(pm->ps->weapon)->offhandSlot == OFFHAND_SLOT_EQUIPMENT) )
    {
      v8 = pm->ps;
      weaponstate = v8->weaponstate;
      if ( weaponstate != 19
        && weaponstate != 20
        && weaponstate != 21
        && (weaponstate < 22 || weaponstate > 29)
        && weaponstate != 42
        && weaponstate != 43
        && (weaponstate < 30 || weaponstate > 34) )
      {
        pm_flags = v8->pm_flags;
        if ( (pm_flags & 0x400000) == 0 )
          return (pm_flags & 0x40000) != 0;
      }
    }
  }
  return 1;
}

#endif // __UNIMPLEMENTED__
