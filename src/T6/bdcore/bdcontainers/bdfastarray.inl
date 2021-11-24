// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdfastarray.inl:0x4FC9D0
BOOL __cdecl CreateDebugSpheresIfNeeded()
{
  if ( !cls.debug.clSpheres.spheres )
  {
    if ( cls.debug.svSpheres.spheres
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\client\\cl_debugdata.cpp",
            118,
            0,
            "(0 == cls.debug.svSpheres.spheres)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( cls.debug.svSpheresBuffer.spheres
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\client\\cl_debugdata.cpp",
            119,
            0,
            "(0 == cls.debug.svSpheresBuffer.spheres)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    cls.debug.clSpheres.max = 128;
    cls.debug.svSpheres.max = 128;
    cls.debug.svSpheresBuffer.max = 128;
    R_DebugAlloc((void **)&cls.debug.clSpheres.spheres, 5120, "Client Debug Spheres");
    R_DebugAlloc((void **)&cls.debug.clSpheres.durations, 512, "Client Debug Spheres");
    cls.debug.clSpheres.num = 0;
    R_DebugAlloc((void **)&cls.debug.svSpheres.spheres, 5120, "Server Debug Spheres");
    R_DebugAlloc((void **)&cls.debug.svSpheres.durations, 512, "Server Debug Spheres");
    cls.debug.svSpheres.num = 0;
    R_DebugAlloc((void **)&cls.debug.svSpheresBuffer.spheres, 5120, "Server buffer Debug Spheres");
    cls.debug.svSpheresBuffer.num = 0;
    if ( !cls.debug.clSpheres.spheres )
      return 0;
  }
  return cls.debug.clSpheres.durations
      && cls.debug.svSpheres.spheres
      && cls.debug.svSpheres.durations
      && cls.debug.svSpheresBuffer.spheres;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdfastarray.inl:0x9282B0
void __usercall Demo_ReadConfigStrings(msg_t *msg@<esi>, LocalClientNum_t localClientNum)
{
  int v2; // edi
  int v3; // eax

  PIXBeginNamedEvent(-1, "Demo - Read Config Strings");
  cls.gameState.dataCount = 1;
  v2 = MSG_GetNumBitsRead(msg);
  CL_ParseConfigStrings_Internal(localClientNum, msg, Demo_StoreConfigString);
  v3 = MSG_GetNumBitsRead(msg);
  Demo_Printf(131, "Demo_ReadConfigStrings() - Size: %d bytes\n", (v3 - v2) / 8);
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdfastarray.inl:0x934690
void __cdecl BG_Dog_Clear_Look_At(LocalClientNum_t localClientNum, const entityState_s *es)
{
  const DObj *v2; // eax
  const DObj *v3; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v5; // eax
  XAnimTree_s *v6; // eax
  XAnimTree_s *v7; // eax

  v2 = (const DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + _tls_index)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       localClientNum);
  v3 = v2;
  if ( v2 )
  {
    Tree = DObjGetTree(v2);
    XAnimClearTreeGoalWeights(Tree, 0x29u, 0.0, -1);
    v5 = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(v5, 0x2Au, 0.0, -1);
    v6 = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(v6, 0x2Cu, 0.0, -1);
    v7 = DObjGetTree(v3);
    XAnimClearTreeGoalWeights(v7, 0x2Bu, 0.0, -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdfastarray.inl:0x934740
void __usercall BG_Dog_Init_Normal_Look_At(const entityState_s *es@<edi>, LocalClientNum_t localClientNum)
{
  DObj *v2; // esi

  v2 = (DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                       + _tls_index)
                                                                     + 14960)
                                                         + 120))(
                 es->number,
                 localClientNum);
  if ( v2 )
  {
    BG_Dog_Clear_Look_At(localClientNum, es);
    XAnimSetGoalWeight(v2, 0x39u, 1.0, 0.0, s_animRate, 0, 0, 0, -1);
    XAnimSetGoalWeight(v2, 0x37u, 1.0, 0.0, s_animRate, 0, 0, 0, -1);
    XAnimSetGoalWeight(v2, 0x3Du, 1.0, 0.0, s_animRate, 0, 0, 0, -1);
    XAnimSetGoalWeight(v2, 0x3Bu, 1.0, 0.0, s_animRate, 0, 0, 0, -1);
  }
}

#endif // __UNIMPLEMENTED__
