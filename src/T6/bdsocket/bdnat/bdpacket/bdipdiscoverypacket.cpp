// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdipdiscoverypacket.cpp:0x959130
void __usercall PM_EndSprint(playerState_s *ps@<eax>, pmove_t *pm@<ecx>)
{
  if ( (ps->pm_flags & 0x8000) != 0 )
  {
    ps->sprintState.sprintDelay = 0;
    ps->sprintState.lastSprintEnd = pm->cmd.serverTime;
    ps->pm_flags &= ~0x8000u;
    if ( (pm->cmd.button_bits.array[0] & 0x40000000) != 0 )
      ps->sprintState.sprintButtonUpRequired = 1;
  }
}

#endif // __UNIMPLEMENTED__
