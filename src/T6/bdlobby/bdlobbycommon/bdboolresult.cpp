// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdboolresult.cpp:0x939A80
animScriptCommand_t *__cdecl BG_AnimScriptEventGetCommand(
        playerState_s *ps,
        scriptAnimEventTypes_t event,
        unsigned int *holdrand)
{
  _DWORD *v4; // edx
  animScriptItem_t *ValidItem; // eax

  if ( event != ANIM_ET_DEATH && ps->pm_type >= 10 )
    return 0;
  if ( G_IsServerGameSystem(ps->clientNum) )
    Com_Printf(18, "event: %s\n", animEventTypesStr[event].string);
  v4 = *(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960);
  if ( *(_DWORD *)(*v4 + 516 * event + 151264)
    && (ValidItem = BG_FirstValidItem(ps->clientNum, (animScript_t *)(*v4 + 516 * event + 151264))) != 0
    && ValidItem->numCommands )
  {
    return &ValidItem->commands[BG_rand(holdrand) % ValidItem->numCommands];
  }
  else
  {
    return 0;
  }
}

#endif // __UNIMPLEMENTED__
