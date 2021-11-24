// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bducd.cpp:0x934090
void __cdecl BG_Dog_UpdateAnimationState(
        LocalClientNum_t localClientNum,
        const entityState_s *es,
        actorInfo_t *actorInfo)
{
  int state; // edi
  animInfo_t *p_animInfo; // esi
  void (__cdecl *v5)(LocalClientNum_t, const entityState_s *); // edi

  state = es->un2.animState.state;
  p_animInfo = &actorInfo->animInfo;
  if ( BG_Actor_ApplyNewAnimState(actorInfo->pXAnimTree, &actorInfo->animInfo.lerp, state) )
  {
    BG_Dog_SetNewAnimationState(&p_animInfo->lerp, state, localClientNum, (animInfo_t *)es);
  }
  else if ( p_animInfo->lerp.bAnimating
         && (*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                    + _tls_index)
                                                                  + 14960)
                                                      + 120))(
              es->number,
              localClientNum) )
  {
    v5 = (void (__cdecl *)(LocalClientNum_t, const entityState_s *))dword_CDF684[4 * (state & 0xFFFFFEFF)];
    if ( v5 )
      v5(localClientNum, es);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bducd.cpp:0x934120
XAnim_s *__cdecl Dog_GetAnims()
{
  return s_dogAnims;
}

#endif // __UNIMPLEMENTED__
