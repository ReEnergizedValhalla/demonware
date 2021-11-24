// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdyoutubeusertoken.cpp:0x939D10
unsigned int __cdecl BG_GetConditionValue(const clientInfo_t *ci, const int condition)
{
  if ( condition < 25 && condition >= 0 )
    return ci->clientConditions[condition];
  if ( !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          3670,
          0,
          "((condition < NUM_ANIM_CONDITIONS && condition >= 0))",
          "(condition) = %i",
          condition) )
    __debugbreak();
  return ci->clientConditions[condition];
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdyoutubeusertoken.cpp:0x939D70
int __usercall BG_GetConditionBit@<eax>(const int condition@<eax>, const clientInfo_t *ci)
{
  int v3; // esi
  unsigned int *v4; // edi

  if ( (condition >= 25 || condition < 0)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          3685,
          0,
          "((condition < NUM_ANIM_CONDITIONS && condition >= 0))",
          "(condition) = %i",
          condition) )
  {
    __debugbreak();
  }
  if ( animConditionsTable[condition].type
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          3686,
          0,
          "((animConditionsTable[condition].type == ANIM_CONDTYPE_BITFLAGS))",
          "(animConditionsTable[condition].type) = %i",
          animConditionsTable[condition].type) )
  {
    __debugbreak();
  }
  v3 = 0;
  v4 = &ci->clientConditions[condition];
  while ( 1 )
  {
    if ( !v4
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\../universal/q_shared.h",
            956,
            0,
            "(array)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( ((1 << (v3 & 0x1F)) & v4[v3 >> 5]) != 0 )
      break;
    if ( (unsigned int)++v3 >= 0x20 )
      return 0;
  }
  return v3;
}

#endif // __UNIMPLEMENTED__
