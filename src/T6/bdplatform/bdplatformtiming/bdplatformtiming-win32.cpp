// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdplatformtiming-win32.cpp:0x948110
void __cdecl Mantle_CreateAnims(void *(__cdecl *xanimAlloc)(int))
{
  signed int i; // esi
  int v2; // esi
  float *p_height; // ebx
  const char **j; // edi
  int v5; // edi
  const char **v6; // esi
  vec4_t rot; // [esp+20h] [ebp-20h] BYREF
  vec3_t delta; // [esp+30h] [ebp-10h] BYREF

  if ( !s_mantleAnims )
  {
    s_mantleAnims = XAnimCreateAnims("PLAYER_MANTLE", 11, xanimAlloc);
    if ( !s_mantleAnims
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
            1080,
            0,
            "(s_mantleAnims)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    XAnimBlend(s_mantleAnims, 0, s_mantleAnimNames[0], 1u, 0xAu, 0);
    for ( i = 1; i < 11; ++i )
      BG_CreateXAnim(s_mantleAnims, i, s_mantleAnimNames[i]);
    v2 = 0;
    p_height = &s_mantleTrans[0].height;
    for ( j = s_mantleAnimNames + 4; (int)j < 17690036; ++j )
    {
      XAnimGetAbsDelta(s_mantleAnims, v2 + 1, &rot, &delta, 1.0);
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(delta.x - 16.0) & _mask__AbsFloat_) > 1.0 )
        Com_Error(ERR_DROP, "Mantle anim [%s] has X translation %f, should be %f\n", *j, delta.x, DOUBLE_16_0);
      if ( COERCE_FLOAT(LODWORD(delta.y) & _mask__AbsFloat_) > 1.0 )
        Com_Error(ERR_DROP, "Mantle anim [%s] has Y translation %f, should be %f\n", *j, delta.y, 0.0);
      if ( (v2 < 0 || v2 > 7)
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
              254,
              0,
              "(0) <= (transIndex) && (transIndex) <= (MANTLE_UP_COUNT)",
              "transIndex not in [0, MANTLE_UP_COUNT]\n\t%i not in [%i, %i]",
              v2,
              0,
              7) )
      {
        __debugbreak();
      }
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(delta.z - *p_height) & _mask__AbsFloat_) > 1.0 )
      {
        if ( (v2 < 0 || v2 > 7)
          && !Assert_MyHandler(
                "c:\\t6\\code\\src_noserver\\bgame\\bg_mantle.cpp",
                254,
                0,
                "(0) <= (transIndex) && (transIndex) <= (MANTLE_UP_COUNT)",
                "transIndex not in [0, MANTLE_UP_COUNT]\n\t%i not in [%i, %i]",
                v2,
                0,
                7) )
        {
          __debugbreak();
        }
        Com_Error(ERR_DROP, "Mantle anim [%s] has Z translation %f, should be %f\n", *j, delta.z, *p_height);
      }
      ++v2;
      p_height += 3;
    }
    v5 = 0;
    v6 = s_mantleAnimNames + 32;
    do
    {
      XAnimGetAbsDelta(s_mantleAnims, v5 + 8, &rot, &delta, 1.0);
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(delta.x - 31.0) & _mask__AbsFloat_) > 1.0 )
        Com_Error(ERR_DROP, "Mantle anim [%s] has X translation %f, should be %f\n", *v6, delta.x, DOUBLE_31_0);
      if ( COERCE_FLOAT(LODWORD(delta.y) & _mask__AbsFloat_) > 1.0 )
        Com_Error(ERR_DROP, "Mantle anim [%s] has Y translation %f, should be %f\n", *v6, delta.y, 0.0);
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(delta.z - -18.0) & _mask__AbsFloat_) > 1.0 )
        Com_Error(ERR_DROP, "Mantle anim [%s] has Z translation %f, should be %f\n", *v6, delta.z, DOUBLE_N18_0);
      ++v6;
      ++v5;
    }
    while ( (int)v6 < (int)s_mantleTrans );
  }
}

#endif // __UNIMPLEMENTED__
