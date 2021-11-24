// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdplatformlog.cpp:0x9476B0
void __usercall Mantle_DebugPrint(const char *msg@<esi>)
{
  if ( !msg
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp", 216, 0, "(msg)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( Dvar_GetBool(mantle_debug) )
    Com_Printf(27, "%s\n", msg);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformlog.cpp:0x947780
int __usercall Mantle_GetOverLength@<eax>(const MantleState *mstate@<eax>)
{
  int transIndex; // esi

  if ( (mstate->flags & 1) == 0 )
    return 0;
  transIndex = mstate->transIndex;
  if ( (transIndex < 0 || transIndex > 7)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
          242,
          0,
          "(0) <= (transIndex) && (transIndex) <= (MANTLE_UP_COUNT)",
          "transIndex not in [0, MANTLE_UP_COUNT]\n\t%i not in [%i, %i]",
          transIndex,
          0,
          7) )
  {
    __debugbreak();
  }
  return XAnimGetLengthMsec(s_mantleAnims, s_mantleTrans[transIndex].overAnimIndex);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformlog.cpp:0x9477E0
int __usercall Mantle_GetAnim@<eax>(MantleState *mstate@<eax>)
{
  int UpLength; // esi
  int OverLength; // eax
  int timer; // ecx
  bool v5; // cc
  int transIndex; // edi

  UpLength = Mantle_GetUpLength(mstate);
  OverLength = Mantle_GetOverLength(mstate);
  timer = mstate->timer;
  if ( (timer < 0 || timer > UpLength + OverLength)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
          313,
          0,
          "((mstate->timer >= 0) && (mstate->timer <= (upTime + overTime)))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v5 = mstate->timer <= UpLength;
  transIndex = mstate->transIndex;
  if ( v5 )
  {
    if ( (transIndex < 0 || transIndex > 7)
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
            230,
            0,
            "(0) <= (transIndex) && (transIndex) <= (MANTLE_UP_COUNT)",
            "transIndex not in [0, MANTLE_UP_COUNT]\n\t%i not in [%i, %i]",
            transIndex,
            0,
            7) )
    {
      __debugbreak();
    }
    return s_mantleTrans[transIndex].upAnimIndex;
  }
  else
  {
    if ( (transIndex < 0 || transIndex > 7)
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
            242,
            0,
            "(0) <= (transIndex) && (transIndex) <= (MANTLE_UP_COUNT)",
            "transIndex not in [0, MANTLE_UP_COUNT]\n\t%i not in [%i, %i]",
            transIndex,
            0,
            7) )
    {
      __debugbreak();
    }
    return s_mantleTrans[transIndex].overAnimIndex;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformlog.cpp:0x9478B0
void __cdecl Mantle_GetAnimDelta(MantleState *mstate, vec3_t *delta)
{
  int time; // ecx
  int v3; // esi
  int UpLength; // edi
  int OverLength; // eax
  const char *v6; // eax
  float v7; // xmm0_4
  int v8; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int transIndex; // esi
  int v12; // edi
  int overTime; // [esp+14h] [ebp-24h]
  int overTimea; // [esp+14h] [ebp-24h]
  vec4_t rot; // [esp+18h] [ebp-20h] BYREF
  vec3_t trans; // [esp+28h] [ebp-10h] BYREF

  v3 = time;
  UpLength = Mantle_GetUpLength(mstate);
  OverLength = Mantle_GetOverLength(mstate);
  overTime = OverLength;
  if ( v3 < 0 || v3 > OverLength + UpLength )
  {
    v6 = va("time: %i, upTime: %i, overTime: %i", v3, UpLength, OverLength);
    if ( !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
            339,
            0,
            "((time >= 0) && (time <= (upTime + overTime)))",
            "%s",
            v6) )
      __debugbreak();
    OverLength = overTime;
  }
  if ( v3 > UpLength )
  {
    v10 = (float)(v3 - UpLength);
    transIndex = mstate->transIndex;
    *(float *)&overTimea = v10 / (float)OverLength;
    if ( (transIndex < 0 || transIndex > 7)
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
            230,
            0,
            "(0) <= (transIndex) && (transIndex) <= (MANTLE_UP_COUNT)",
            "transIndex not in [0, MANTLE_UP_COUNT]\n\t%i not in [%i, %i]",
            transIndex,
            0,
            7) )
    {
      __debugbreak();
    }
    XAnimGetAbsDelta(s_mantleAnims, s_mantleTrans[transIndex].upAnimIndex, &rot, &trans, 1.0);
    v12 = mstate->transIndex;
    if ( (v12 < 0 || v12 > 7)
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
            242,
            0,
            "(0) <= (transIndex) && (transIndex) <= (MANTLE_UP_COUNT)",
            "transIndex not in [0, MANTLE_UP_COUNT]\n\t%i not in [%i, %i]",
            v12,
            0,
            7) )
    {
      __debugbreak();
    }
    XAnimGetAbsDelta(s_mantleAnims, s_mantleTrans[v12].overAnimIndex, &rot, delta, *(float *)&overTimea);
    delta->x = delta->x + trans.x;
    delta->y = delta->y + trans.y;
    delta->z = delta->z + trans.z;
  }
  else
  {
    v7 = (float)v3;
    v8 = mstate->transIndex;
    v9 = v7 / (float)UpLength;
    if ( (v8 < 0 || v8 > 7)
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
            230,
            0,
            "(0) <= (transIndex) && (transIndex) <= (MANTLE_UP_COUNT)",
            "transIndex not in [0, MANTLE_UP_COUNT]\n\t%i not in [%i, %i]",
            v8,
            0,
            7) )
    {
      __debugbreak();
    }
    XAnimGetAbsDelta(s_mantleAnims, s_mantleTrans[v8].upAnimIndex, &rot, delta, v9);
  }
  VectorAngleMultiply((vec2_t *)delta, mstate->yaw);
}

#endif // __UNIMPLEMENTED__
