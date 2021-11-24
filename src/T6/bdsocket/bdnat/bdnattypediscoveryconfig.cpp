// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdnattypediscoveryconfig.cpp:0x9515A0
void __usercall BG_PlayerToEntityProcessEvents(
        playerState_s *ps@<esi>,
        entityState_s *s@<edi>,
        unsigned __int8 handler)
{
  __int16 eventSequence; // ax
  __int16 v4; // cx
  __int16 v5; // ax
  __int16 originalEventSequence; // [esp+4h] [ebp-4h]

  originalEventSequence = s->eventSequence;
  BG_PlayerToEntityProcessEvents_Internal(
    s,
    handler,
    &ps->predictableEventSequence,
    &ps->predictableEventSequenceOld,
    ps->predictableEvents,
    ps->predictableEventParms,
    ps->commandTime);
  BG_PlayerToEntityProcessEvents_Internal(
    s,
    handler,
    &ps->unpredictableEventSequence,
    &ps->unpredictableEventSequenceOld,
    ps->unpredictableEvents,
    ps->unpredictableEventParms,
    ps->commandTime);
  eventSequence = s->eventSequence;
  s->eventParm = 0;
  if ( originalEventSequence <= eventSequence + 64 )
    v4 = originalEventSequence;
  else
    v4 = originalEventSequence - 256;
  v5 = eventSequence - v4;
  if ( v5 > 4 )
  {
    Com_PrintWarning(
      27,
      "[%c|%i] Circular event buffer overflow ( Received: %i | Max: %i )\n",
      (unsigned __int8)(handler - 1) != 0 ? 67 : 83,
      ps->clientNum,
      v5,
      4);
    Com_PrintWarning(
      27,
      "Events are:\n[0] %s\n[1] %s\n[2] %s\n[3] %s\n",
      eventnames[s->events[0]],
      eventnames[s->events[1]],
      eventnames[s->events[2]],
      eventnames[s->events[3]]);
  }
}

#endif // __UNIMPLEMENTED__
