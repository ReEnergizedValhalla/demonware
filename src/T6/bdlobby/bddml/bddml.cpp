// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bddml.cpp:0x936DF0
void __cdecl BG_Dog_Traverse_Jump_Down_40(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax

  v2 = _tls_index;
  v3 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v4 = (DObj *)v3;
  if ( v3 )
  {
    Tree = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(Tree, 0, 0.2, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0x21u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960) + 602012),
      2u,
      1,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddml.cpp:0x936EA0
void __cdecl BG_Dog_Traverse_Jump_Down_80(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax

  v2 = _tls_index;
  v3 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v4 = (DObj *)v3;
  if ( v3 )
  {
    Tree = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(Tree, 0, 0.2, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0x22u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960) + 602012),
      2u,
      1,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddml.cpp:0x936F50
void __cdecl BG_Dog_Traverse_Wallhop(LocalClientNum_t localClientNum, const entityState_s *es)
{
  unsigned int v2; // edi
  const DObj *v3; // eax
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax

  v2 = _tls_index;
  v3 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v4 = (DObj *)v3;
  if ( v3 )
  {
    Tree = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(Tree, 0, 0.2, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0x23u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v2) + 14960) + 602012),
      2u,
      1,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
