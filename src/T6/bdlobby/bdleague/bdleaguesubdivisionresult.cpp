// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdleaguesubdivisionresult.cpp:0x9380F0
void __usercall BG_SetAnimConditionFlags(int condIndex@<eax>, unsigned int result)
{
  if ( condIndex == 5 )
  {
    if ( Com_BitCheckAssert(&result, 2, 0xFFFFFFF) )
      parseMovestatus = ANIM_MOVESTATUS_RUN;
    else
      parseMovestatus = Com_BitCheckAssert(&result, 1, 0xFFFFFFF);
  }
  else if ( condIndex == 10 )
  {
    if ( Com_BitCheckAssert(&result, 2, 0xFFFFFFF) )
      parseStance = ANIM_STANCE_PRONE;
    else
      parseStance = Com_BitCheckAssert(&result, 1, 0xFFFFFFF);
  }
}

#endif // __UNIMPLEMENTED__
