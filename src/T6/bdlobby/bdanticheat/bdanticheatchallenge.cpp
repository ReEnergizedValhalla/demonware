// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdanticheatchallenge.cpp:0x942000
int __cdecl BG_EmblemsGetIconCost(__int16 id)
{
  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          620,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( id < 0 || id >= (int)s_emblemSet[13].layers )
    return -1;
  else
    return *((_DWORD *)&s_emblemSet[13].iconTypes + 9 * id);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdanticheatchallenge.cpp:0x942060
int __cdecl BG_EmblemsGetIconUnlockLevel(__int16 id)
{
  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          630,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( id < 0 || id >= (int)s_emblemSet[13].layers )
    return -1;
  else
    return *(&s_emblemSet[13].bgCategoryCount + 9 * id);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdanticheatchallenge.cpp:0x9420C0
int __cdecl BG_EmblemsGetIconUnlockPLevel(__int16 id)
{
  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          640,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( id < 0 || id >= (int)s_emblemSet[13].layers )
    return -1;
  else
    return *((_DWORD *)&s_emblemSet[13].bgCategories + 9 * id);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdanticheatchallenge.cpp:0x942120
int __cdecl BG_EmblemsGetIconUnclassifyAt(__int16 id)
{
  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          650,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( id < 0 || id >= (int)s_emblemSet[13].layers )
    return -1;
  else
    return *(&s_emblemSet[13].iconCount + 9 * id);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdanticheatchallenge.cpp:0x942180
const vec4_t *__cdecl BG_EmblemsGetIconDefaultColor(const vec4_t *result, __int16 id)
{
  const vec4_t *v2; // eax
  vec4_t oddIconIdColor; // [esp+10h] [ebp-10h]

  if ( !s_emblemSet
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_emblems.cpp",
          661,
          0,
          "(s_emblemSet)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  LODWORD(oddIconIdColor.v[0]) = FLOAT_1_0;
  LODWORD(oddIconIdColor.v[1]) = FLOAT_1_0;
  LODWORD(oddIconIdColor.v[2]) = FLOAT_1_0;
  LODWORD(oddIconIdColor.v[3]) = FLOAT_1_0;
  if ( id < 0 || id >= (int)s_emblemSet[13].layers )
  {
    v2 = result;
    *(_QWORD *)result->v = 0i64;
    *(_QWORD *)&result->b = 0i64;
  }
  else
  {
    v2 = result;
    *result = oddIconIdColor;
  }
  return v2;
}

#endif // __UNIMPLEMENTED__
