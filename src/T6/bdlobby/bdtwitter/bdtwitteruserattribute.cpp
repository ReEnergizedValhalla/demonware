// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdtwitteruserattribute.cpp:0x93C1C0
void __cdecl BG_PlayerAnimation(
        LocalClientNum_t localClientNum,
        const entityState_s *es,
        clientInfo_t *ci,
        vec3_t origin,
        vec3_t angles)
{
  void (__cdecl **v6)(const entityState_s *, const clientInfo_t *); // esi
  XAnimTree_s *pAnimTree; // [esp+18h] [ebp+Ch]

  BG_PlayerAngles((LocalClientNum_t)es);
  v6 = clientConditionUpdateFunc;
  do
    (*v6++)(es, ci);
  while ( (int)v6 < (int)difficulty_strings_658 );
  pAnimTree = ci->pXAnimTree;
  BG_PlayerAnimation_VerifyAnim(&ci->legs, pAnimTree);
  BG_PlayerAnimation_VerifyAnim(&ci->torso, pAnimTree);
  if ( ci->leftHandGun && (ci->torso.animationNumber & 0xFFFFFBFF) == 0 )
  {
    ci->leftHandGun = 0;
    ci->dobjDirty = 1;
  }
  BG_RunLerpFrameRate(ci, &ci->legs, localClientNum, es->un2.anim.legsAnim, es, origin, angles);
  BG_RunLerpFrameRate(ci, &ci->torso, localClientNum, es->un2.anim.torsoAnim, es, origin, angles);
}

#endif // __UNIMPLEMENTED__
