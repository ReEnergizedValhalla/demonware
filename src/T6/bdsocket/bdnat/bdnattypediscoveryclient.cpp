// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdnattypediscoveryclient.cpp:0x950B80
void __cdecl BG_ShieldHitDecode(unsigned int encoded, int *segY, int *segZ, bool *resultHitFront)
{
  *segY = (encoded >> 4) & ((unsigned int)MY_MASK_Y_0 >> 4);
  *segZ = (encoded >> 1) & ((unsigned int)MY_MASK_Z_0 >> 1);
  *resultHitFront = encoded & 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattypediscoveryclient.cpp:0x950BC0
void __cdecl BG_ClipCameraToHeliPatch(vec3_t *origin, vec3_t *oldpos, vec3_t *velocity, vec3_t *breachPos)
{
  float heliPatchZ; // [esp+18h] [ebp-18h] BYREF
  bool oldposValid; // [esp+1Fh] [ebp-11h]
  vec3_t newpos; // [esp+20h] [ebp-10h] BYREF
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  if ( Dvar_GetBool(bg_freeCamClipToHeliPatch) && num_heli_height_lock_patches > 0 )
  {
    oldposValid = CM_GetHeliHeight((unsigned int)&savedregs, oldpos, 3000.0, &heliPatchZ, 0) != 0;
    if ( !CM_GetHeliHeight((unsigned int)&savedregs, origin, 3000.0, &heliPatchZ, 0) )
    {
      *(_QWORD *)&newpos.v[1] = *(_QWORD *)&origin->v[1];
      newpos.x = oldpos->x;
      if ( CM_GetHeliHeight((unsigned int)&savedregs, &newpos, 3000.0, &heliPatchZ, 0) )
      {
        origin->x = oldpos->x;
      }
      else
      {
        newpos.x = origin->x;
        newpos.z = origin->z;
        newpos.y = oldpos->y;
        if ( CM_GetHeliHeight((unsigned int)&savedregs, &newpos, 3000.0, &heliPatchZ, 0) )
        {
          origin->y = oldpos->y;
        }
        else if ( oldposValid )
        {
          *origin = *oldpos;
          *(_QWORD *)&velocity->x = 0i64;
          velocity->z = 0.0;
        }
        else if ( breachPos )
        {
          *origin = *breachPos;
          *(_QWORD *)&velocity->x = 0i64;
          velocity->z = 0.0;
          if ( CM_GetHeliHeight((unsigned int)&savedregs, origin, 3000.0, &heliPatchZ, 0) )
            origin->z = heliPatchZ - 1.0;
        }
      }
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattypediscoveryclient.cpp:0x950DA0
void __cdecl BG_AddEvent<int,unsigned int>(
        int newEvent,
        unsigned int eventParm,
        __int16 *eventSequence,
        int *events,
        unsigned int *eventParms,
        const unsigned int eventTime,
        const char addType)
{
  int v7; // esi

  if ( newEvent )
  {
    if ( (unsigned int)newEvent >= 0x100
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            2113,
            0,
            "(unsigned)(newEvent) < (unsigned)(256)",
            "newEvent doesn't index 256\n\t%i not in [0, %i)",
            newEvent,
            256) )
    {
      __debugbreak();
    }
    if ( eventParm > (unsigned int)&g_hunk_track[160413].name[111]
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            2114,
            0,
            "(eventParm <= (1 << ( 8 + 6 * 3)) - 1)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( !events
      && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 2116, 0, "(events)", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( !eventParms
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            2117,
            0,
            "(eventParms)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( !eventSequence
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            2118,
            0,
            "(eventSequence)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( Dvar_GetBool(showevents) )
      Com_Printf(
        27,
        "AddEvent [%c] | %8d | %4d | %30s | %d\n",
        addType,
        eventTime,
        *eventSequence,
        eventnames[newEvent],
        eventParm);
    v7 = *eventSequence & 3;
    events[v7] = newEvent;
    eventParms[v7] = eventParm;
    if ( newEvent != events[v7]
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            2130,
            0,
            "(newEvent == (int)events[sequence])",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( eventParm != eventParms[v7]
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            2131,
            0,
            "(eventParm == (uint)eventParms[sequence])",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    *eventSequence = (unsigned __int8)(*(_BYTE *)eventSequence + 1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattypediscoveryclient.cpp:0x950F50
void __cdecl BG_AddEvent<unsigned char,unsigned int>(
        int newEvent,
        unsigned int eventParm,
        __int16 *eventSequence,
        unsigned __int8 *events,
        unsigned int *eventParms,
        const unsigned int eventTime,
        const char addType)
{
  int v7; // esi

  if ( newEvent )
  {
    if ( (unsigned int)newEvent >= 0x100
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            2113,
            0,
            "(unsigned)(newEvent) < (unsigned)(256)",
            "newEvent doesn't index 256\n\t%i not in [0, %i)",
            newEvent,
            256) )
    {
      __debugbreak();
    }
    if ( eventParm > (unsigned int)&g_hunk_track[160413].name[111]
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            2114,
            0,
            "(eventParm <= (1 << ( 8 + 6 * 3)) - 1)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( !events
      && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 2116, 0, "(events)", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( !eventParms
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            2117,
            0,
            "(eventParms)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( !eventSequence
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            2118,
            0,
            "(eventSequence)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( Dvar_GetBool(showevents) )
      Com_Printf(
        27,
        "AddEvent [%c] | %8d | %4d | %30s | %d\n",
        addType,
        eventTime,
        *eventSequence,
        eventnames[newEvent],
        eventParm);
    v7 = *eventSequence & 3;
    events[v7] = newEvent;
    eventParms[v7] = eventParm;
    if ( newEvent != events[v7]
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            2130,
            0,
            "(newEvent == (int)events[sequence])",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( eventParm != eventParms[v7]
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            2131,
            0,
            "(eventParm == (uint)eventParms[sequence])",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    *eventSequence = (unsigned __int8)(*(_BYTE *)eventSequence + 1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattypediscoveryclient.cpp:0x951100
BOOL __cdecl BG_PlayerTouchesItem(const playerState_s *ps, const entityState_s *item, int atTime)
{
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  BOOL result; // eax
  vec3_t origin; // [esp+0h] [ebp-10h] BYREF

  BG_EvaluateTrajectory(&item->lerp.pos, atTime, &origin);
  v3 = ps->origin.x - origin.x;
  result = 0;
  if ( v3 <= 36.0 && v3 >= -36.0 )
  {
    v4 = ps->origin.y - origin.y;
    if ( v4 <= 36.0 && v4 >= -36.0 )
    {
      v5 = ps->origin.z - origin.z;
      if ( v5 <= 18.0 && v5 >= -88.0 )
        return 1;
    }
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattypediscoveryclient.cpp:0x9511B0
void __cdecl BG_AddPredictableEventToPlayerstate(int newEvent, unsigned int eventParm, playerState_s *ps)
{
  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 2143, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  BG_AddEvent<int,unsigned int>(
    newEvent,
    eventParm,
    &ps->predictableEventSequence,
    ps->predictableEvents,
    ps->predictableEventParms,
    ps->commandTime,
    80);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattypediscoveryclient.cpp:0x951210
void __cdecl BG_AddUnpredictableEventToPlayerstate(int newEvent, unsigned int eventParm, playerState_s *ps)
{
  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 2155, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  BG_AddEvent<int,unsigned int>(
    newEvent,
    eventParm,
    &ps->unpredictableEventSequence,
    ps->unpredictableEvents,
    ps->unpredictableEventParms,
    ps->commandTime,
    85);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattypediscoveryclient.cpp:0x951270
void __cdecl BG_AddEntityStateEvent(int newEvent, unsigned int eventParm, entityState_s *es, const int eventTime)
{
  if ( !es
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 2167, 0, "(es)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  BG_AddEvent<unsigned char,unsigned int>(
    newEvent,
    eventParm,
    &es->eventSequence,
    es->events,
    es->eventParms,
    eventTime,
    69);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattypediscoveryclient.cpp:0x9512D0
void __cdecl BG_AddSentinelEventToEntityState(entityState_s *es, const int eventTime)
{
  unsigned __int8 *events; // edi
  unsigned int *eventParms; // ebx
  __int16 *p_eventSequence; // esi
  int v5; // esi
  __int16 *type; // [esp+14h] [ebp+8h]

  if ( !es
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 2173, 0, "(es)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  events = es->events;
  eventParms = es->eventParms;
  p_eventSequence = &es->eventSequence;
  type = &es->eventSequence;
  if ( !events
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 2116, 0, "(events)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !eventParms
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          2117,
          0,
          "(eventParms)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !p_eventSequence
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          2118,
          0,
          "(eventSequence)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( Dvar_GetBool(showevents) )
    Com_Printf(27, "AddEvent [%c] | %8d | %4d | %30s | %d\n", 69, eventTime, *p_eventSequence, off_10DF2A8[0], 0);
  v5 = *p_eventSequence & 3;
  events[v5] = -18;
  eventParms[v5] = 0;
  if ( events[v5] != 0xEE
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          2130,
          0,
          "(newEvent == (int)events[sequence])",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( eventParms[v5]
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          2131,
          0,
          "(eventParm == (uint)eventParms[sequence])",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  *type = (unsigned __int8)(*(_BYTE *)type + 1);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattypediscoveryclient.cpp:0x951440
void __cdecl BG_PlayerToEntityProcessEvents_Internal(
        entityState_s *s,
        unsigned __int8 handler,
        __int16 *eventSequence,
        __int16 *oldEventSequence,
        int *events,
        unsigned int *eventParms,
        const unsigned int eventTime)
{
  __int16 v7; // si
  int v8; // ebx
  int v9; // eax
  int v10; // esi
  unsigned int v11; // edi
  void (__cdecl *v12)(int, int); // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  entityState_s *v17; // eax

  if ( *oldEventSequence <= *eventSequence + 64 )
    v7 = *oldEventSequence;
  else
    v7 = *oldEventSequence - 256;
  if ( *eventSequence < v7
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          2205,
          0,
          "(*eventSequence >= oldSequenceNum)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v8 = v7;
  if ( v7 >= *eventSequence )
  {
    *oldEventSequence = *eventSequence;
  }
  else
  {
    do
    {
      v9 = v8 & 3;
      v10 = events[v9];
      v11 = eventParms[v9];
      v12 = (void (__cdecl *)(int, int))dword_10DF6F4[9 * handler];
      if ( v12 )
        v12(s->number, v10);
      v13 = 0;
      v14 = 40;
      while ( v14 != v10 )
      {
        v14 = serverOnlyEvents[++v13];
        if ( v14 <= 0 )
        {
          v15 = 0;
          v16 = 8;
          while ( v16 != v10 )
          {
            v16 = singleClientEvents[++v15];
            if ( v16 <= 0 )
            {
              v17 = s;
              if ( !s )
              {
                if ( !Assert_MyHandler(
                        "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
                        2167,
                        0,
                        "(es)",
                        (const char *)&pBlock) )
                  __debugbreak();
                v17 = 0;
              }
              BG_AddEvent<unsigned char,unsigned int>(
                v10,
                v11,
                &v17->eventSequence,
                v17->events,
                v17->eventParms,
                eventTime,
                69);
              goto LABEL_21;
            }
          }
          break;
        }
      }
LABEL_21:
      ++v8;
    }
    while ( v8 < *eventSequence );
    *oldEventSequence = *eventSequence;
  }
}

#endif // __UNIMPLEMENTED__
