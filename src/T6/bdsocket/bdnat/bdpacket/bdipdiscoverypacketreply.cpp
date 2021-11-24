// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdipdiscoverypacketreply.cpp:0x959170
char __cdecl PM_SprintStartInterferingButtons(
        const playerState_s *ps,
        const int forwardSpeed,
        bitarray<64> *button_bits)
{
  Weapon v3; // eax
  int v5; // eax
  int pm_flags; // eax
  int weaponstate; // eax
  int v8; // eax
  int v9; // eax

  if ( (ps->pm_flags & 8) == 0 && ps->waterlevel < 2 && forwardSpeed > Dvar_GetInt(player_sprintForwardMinimum) )
  {
    if ( (Com_BitCheckAssert(ps->perks, 42, 0xFFFFFFF) > 0
       || (v3.0 = BG_GetViewmodelWeaponIndex(ps).0, BG_WeaponHasPerk(v3, 0x2Au)))
      && Com_SessionMode_IsMode(SESSIONMODE_ZOMBIES) )
    {
      if ( (button_bits->array[0] & 0x20000000) == 0 && button_bits->array[0] >= 0 )
        return (button_bits->array[0] & 0x80) != 0;
    }
    else
    {
      v5 = button_bits->array[0];
      if ( (button_bits->array[0] & 0x200000) == 0
        && (v5 & 0x8000000) == 0
        && (v5 & 0x20000000) == 0
        && v5 >= 0
        && (v5 & 0x4000000) == 0
        && (v5 & 0x20000) == 0
        && (v5 & 0x10000) == 0
        && ((v5 & 0x80) == 0 || BG_GetWeaponDef(ps->weapon)->offhandSlot == OFFHAND_SLOT_EQUIPMENT)
        && ps->leanf == 0.0 )
      {
        pm_flags = ps->pm_flags;
        if ( (pm_flags & 0x1001C) == 0 )
        {
          if ( (pm_flags & 0x4000) != 0 && !ps->pm_time )
            return 0;
          weaponstate = ps->weaponstate;
          if ( weaponstate != 19
            && weaponstate != 20
            && weaponstate != 21
            && (weaponstate < 22 || weaponstate > 29)
            && (weaponstate < 30 || weaponstate > 34) )
          {
            if ( BG_GetWeaponDef(ps->weapon)->offhandSlot != OFFHAND_SLOT_EQUIPMENT
              || (v8 = ps->weaponstate, v8 != 6) && v8 != 7 && v8 != 8 && v8 != 40 && v8 != 19 && v8 != 20 && v8 != 21 )
            {
              v9 = ps->pm_flags;
              if ( (v9 & 0x400000) == 0 )
                return (v9 & 0x200000) != 0;
            }
          }
        }
      }
    }
  }
  return 1;
}

#endif // __UNIMPLEMENTED__
