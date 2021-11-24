// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdleagueteaminfo.cpp:0x938190
void __usercall BG_ParseConditionBits(
        animStringItem_t *stringTable@<ecx>,
        int condIndex@<edx>,
        unsigned int *result@<edi>,
        const char **text_pp)
{
  parseInfo_t *v4; // eax
  const char *v5; // esi
  unsigned int v6; // eax
  int v7; // eax
  int v8; // eax
  int minus; // [esp+10h] [ebp-54h]
  unsigned int tempBits; // [esp+18h] [ebp-4Ch] BYREF
  int endFlag; // [esp+1Ch] [ebp-48h]
  char currentString[64]; // [esp+20h] [ebp-44h] BYREF

  endFlag = 0;
  minus = 0;
  currentString[0] = 0;
  *result = 0;
  while ( 1 )
  {
    v4 = Com_ParseOnLine(text_pp);
    v5 = (const char *)v4;
    if ( !v4 || !v4->token[0] )
    {
      Com_UngetToken();
      endFlag = 1;
      if ( !strlen(currentString) )
        break;
    }
    if ( !I_stricmp(v5, ",") )
      endFlag = 1;
    if ( I_stricmp(v5, "none") )
    {
      if ( !I_stricmp(v5, "none,") )
      {
        Com_BitSetAssert(result, 0, 0xFFFFFFF);
        break;
      }
      if ( !I_stricmp(v5, "NOT") )
        v5 = "MINUS";
      if ( !endFlag && I_stricmp(v5, "AND") && I_stricmp(v5, "MINUS") )
      {
        if ( v5[strlen(v5) - 1] == 44 )
        {
          endFlag = 1;
          v5[strlen(v5) - 1] = 0;
        }
        if ( strlen(currentString) )
          I_strncat(currentString, 64, " ");
        I_strncat(currentString, 64, v5);
      }
      if ( !I_stricmp(v5, "AND") || !I_stricmp(v5, "MINUS") || endFlag )
      {
        if ( strlen(currentString) )
          goto LABEL_29;
        if ( endFlag )
        {
          BG_AnimParseError("BG_ParseConditionBits: unexpected end of condition");
LABEL_29:
          if ( I_stricmp(currentString, "all") )
          {
            v7 = BG_IndexForString(currentString, defineStr[condIndex], 1);
            if ( v7 < 0 )
            {
              tempBits = 0;
              v8 = BG_IndexForString(currentString, stringTable, 0);
              Com_BitSetAssert(&tempBits, v8, 0xFFFFFFF);
              v6 = tempBits;
            }
            else
            {
              v6 = defineBits[condIndex][v7];
            }
          }
          else
          {
            v6 = -1;
          }
          if ( minus )
          {
            if ( !*result )
              *result = -1;
            *result &= ~v6;
          }
          else
          {
            *result |= v6;
          }
          currentString[0] = 0;
          if ( !I_stricmp(v5, "MINUS") )
            minus = 1;
          goto LABEL_41;
        }
        if ( I_stricmp(v5, "MINUS") )
        {
          BG_AnimParseError("BG_ParseConditionBits: unexpected '%s'", v5);
          goto LABEL_29;
        }
        minus = 1;
      }
    }
    else
    {
      *result |= 1u;
LABEL_41:
      if ( endFlag )
        break;
    }
  }
  BG_SetAnimConditionFlags(condIndex, *result);
}

#endif // __UNIMPLEMENTED__
