// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdqosrequestpacket.cpp:0x958F40
void __cdecl BG_seedRandWithGameTime(unsigned int *pHoldrand)
{
  int v1; // ecx

  v1 = *(unsigned __int8 *)pHoldrand << 8;
  *pHoldrand ^= v1;
  *pHoldrand ^= (v1 << 8) ^ (v1 << 16);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosrequestpacket.cpp:0x958F60
unsigned int __cdecl BG_rand(unsigned int *pHoldrand)
{
  unsigned int v1; // eax

  v1 = 214013 * *pHoldrand + 2531011;
  *pHoldrand = v1;
  return v1 >> 17;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosrequestpacket.cpp:0x958F80
int __cdecl BG_irand(int min, int max, unsigned int *pHoldrand)
{
  unsigned int v3; // eax

  v3 = 214013 * *pHoldrand + 2531011;
  *pHoldrand = v3;
  return min + (((max - min) * (__int64)(v3 >> 17)) >> 15);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosrequestpacket.cpp:0x958FB0
double __cdecl BG_random(unsigned int *pHoldrand)
{
  unsigned int v1; // eax

  v1 = 214013 * *pHoldrand + 2531011;
  *pHoldrand = v1;
  return (double)(v1 >> 17) * 0.000030517578;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosrequestpacket.cpp:0x958FE0
void __cdecl PM_trace(
        pmove_t *pm,
        trace_t *results,
        const vec3_t *start,
        const vec3_t *mins,
        const vec3_t *maxs,
        const vec3_t *end,
        int passEntityNum,
        int contentMask)
{
  int nprims; // ecx
  void (__cdecl *trace)(trace_t *, const vec3_t *, const vec3_t *, const vec3_t *, const vec3_t *, int, int, col_context_t *); // edx
  col_context_t context; // [esp+Ch] [ebp-28h] BYREF
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  if ( pm->handler == 1 )
    ++g_num_server_trace_calls;
  else
    ++g_num_client_trace_calls;
  col_context_t::col_context_t(&context);
  colgeom_visitor_inlined_t<300>::update(&pm->proximity_data, start, end, mins, maxs, contentMask);
  nprims = pm->proximity_data.nprims;
  context.prims = pm->proximity_data.prims;
  trace = pmoveHandlers[pm->handler].trace;
  context.nprims = nprims;
  ((void (__usercall *)(int@<ebp>, trace_t *, const vec3_t *, const vec3_t *, const vec3_t *, const vec3_t *, int, int, col_context_t *))trace)(
    (int)&savedregs,
    results,
    start,
    mins,
    maxs,
    end,
    passEntityNum,
    contentMask,
    &context);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosrequestpacket.cpp:0x959080
int __cdecl PM_GetSprintLeftLastTime(const playerState_s *ps)
{
  int lastSprintStart; // eax
  int MaxSprintTime; // edi
  Weapon v3; // eax
  int v4; // eax
  int result; // eax

  lastSprintStart = ps->sprintState.lastSprintStart;
  if ( lastSprintStart
    && lastSprintStart > ps->sprintState.lastSprintEnd
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp",
          669,
          0,
          "(!PM_IsSprinting( ps ))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  MaxSprintTime = BG_GetMaxSprintTime(ps);
  if ( BG_GetSprintUnlimited() )
    return MaxSprintTime;
  if ( Com_BitCheckAssert(ps->perks, 62, 0xFFFFFFF) > 0 )
    return MaxSprintTime;
  v3.0 = BG_GetViewmodelWeaponIndex(ps).0;
  if ( BG_WeaponHasPerk(v3, 0x3Eu) )
    return MaxSprintTime;
  v4 = ps->sprintState.sprintStartMaxLength - ps->sprintState.lastSprintEnd;
  result = ps->sprintState.lastSprintStart + v4 < 0 ? 0 : ps->sprintState.lastSprintStart + v4;
  if ( MaxSprintTime < result )
    return MaxSprintTime;
  return result;
}

#endif // __UNIMPLEMENTED__
