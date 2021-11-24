// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdfeaturebaninfo.cpp:0x93FAF0
void __cdecl BG_FinalizePlayerAnims(const char *levelName)
{
  const char *v1; // edi
  int v2; // esi
  int AnimTreeSize; // ebx
  int v4; // esi
  int v5; // ebx
  int v6; // edx
  loadAnim_t *v7; // edi
  unsigned int v8; // eax
  bool v9; // zf
  XAnim_s *v10; // edi
  const char *AnimName; // eax
  int v12; // eax
  double Length; // st7
  int v14; // edi
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float Int; // xmm0_4
  int v19; // eax
  float v20; // xmm0_4
  const char *v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  double SprintSpeedScale; // st7
  float v26; // xmm1_4
  XAnim_s *v27; // [esp+10h] [ebp-5Ch]
  XAnim_s *v28; // [esp+18h] [ebp-54h]
  double time1; // [esp+20h] [ebp-4Ch]
  float rotate; // [esp+34h] [ebp-38h] BYREF
  char *v31; // [esp+38h] [ebp-34h]
  int iNumAnims; // [esp+3Ch] [ebp-30h]
  float v33; // [esp+40h] [ebp-2Ch]
  int devNumNamedAnims; // [esp+44h] [ebp-28h]
  XAnim_s *pXAnims; // [esp+48h] [ebp-24h]
  float fullspeed; // [esp+4Ch] [ebp-20h]
  int i; // [esp+50h] [ebp-1Ch]
  vec2_t vRot; // [esp+54h] [ebp-18h] BYREF
  vec3_t vDelta; // [esp+5Ch] [ebp-10h] BYREF

  v31 = (char *)levelName;
  if ( !g_pLoadAnims
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          1108,
          0,
          "(g_pLoadAnims)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !g_piNumLoadAnims
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          1109,
          0,
          "(g_piNumLoadAnims)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1 = (const char *)_tls_index;
  v2 = **(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960);
  pXAnims = *(XAnim_s **)(v2 + 601960);
  AnimTreeSize = XAnimGetAnimTreeSize(pXAnims);
  iNumAnims = AnimTreeSize;
  if ( AnimTreeSize >= 1024
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          1115,
          0,
          "(iNumAnims < 1024)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + (_DWORD)v1) + 14960) + 122880) = AnimTreeSize;
  *(_DWORD *)(v2 + 92) |= 0x2001u;
  I_strncpyz((char *)v2, "root", 64);
  *(_DWORD *)(v2 + 88) = 0;
  v4 = v2 + 120;
  devNumNamedAnims = 0;
  if ( Dvar_GetBool(animScript_listAnims) )
  {
    Com_Printf(18, "\n===========================================================\n");
    Com_Printf(18, "Listing playeranim.script animations...\n\n");
  }
  v5 = 1;
  for ( i = 1; v5 < iNumAnims; i = v5 )
  {
    v6 = *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + (_DWORD)v1) + 14960);
    if ( (unsigned int)v5 >= *(_DWORD *)(*(_DWORD *)v6 + 122880) )
      Com_Error(ERR_DROP, &byte_CE04F0, v5, *(_DWORD *)(*(_DWORD *)v6 + 122880));
    v7 = g_pLoadAnims;
    v8 = 0;
    if ( *g_piNumLoadAnims )
    {
      while ( i != v7->anim.index )
      {
        ++v8;
        ++v7;
        if ( v8 >= *g_piNumLoadAnims )
        {
          v5 = i;
          goto LABEL_19;
        }
      }
      v5 = i;
      if ( XAnimIsPrimitive(pXAnims, i) )
      {
        v10 = pXAnims;
        AnimName = XAnimGetAnimName(pXAnims, v5);
        I_strncpyz((char *)v4, AnimName, 64);
        v12 = BG_StringHashValue((const char *)v4);
        v9 = *(_DWORD *)(v4 + 64) == 0;
        *(_DWORD *)(v4 + 88) = v12;
        if ( v9 )
          *(_DWORD *)(v4 + 64) = -1;
        *(_DWORD *)(v4 + 68) = -1;
        *(float *)(v4 + 72) = FLOAT_N1_0;
        Length = XAnimGetLength(v10, v5);
        *(float *)&i = Length;
        if ( Length == 0.0 )
        {
          *(_DWORD *)(v4 + 84) = 500;
          *(_DWORD *)(v4 + 76) = 0;
        }
        else
        {
          v14 = (int)(float)(*(float *)&i * 1000.0);
          v27 = pXAnims;
          *(_DWORD *)(v4 + 84) = v14;
          XAnimGetRelDelta(v27, v5, &vRot, &vDelta, 0.0, 1.0);
          v15 = (float)(vDelta.y * vDelta.y) + (float)(vDelta.x * vDelta.x);
          if ( (float)(vDelta.y + vDelta.x) <= (float)(vDelta.z * 0.80000001) )
            v16 = fsqrt(v15 + (float)(vDelta.z * vDelta.z));
          else
            v16 = fsqrt(v15);
          v33 = 1.0 / *(float *)&i;
          v28 = pXAnims;
          *(float *)(v4 + 76) = v16 * (float)(1.0 / *(float *)&i);
          if ( XAnimGetParamValue(v28, v5, "turn", &rotate) )
            v17 = v33 * rotate;
          else
            v17 = 0.0;
          *(float *)(v4 + 80) = v17;
          if ( Dvar_GetBool(anim_debugSpeeds) )
          {
            if ( *(float *)(v4 + 76) <= 1.0 )
            {
              time1 = *(float *)&i;
              *(float *)&i = vDelta.y * vDelta.y;
              Com_Printf(
                18,
                "Anim '%s' moves %f units over %fms\n",
                (const char *)v4,
                fsqrt((float)((float)(vDelta.y * vDelta.y) + (float)(vDelta.x * vDelta.x)) + (float)(vDelta.z * vDelta.z)),
                time1);
            }
            else
            {
              if ( g_speed )
                Int = (float)Dvar_GetInt(g_speed);
              else
                Int = FLOAT_190_0;
              fullspeed = Int;
              strstr((unsigned __int8 *)v4, "crouch");
              if ( v19 )
              {
                v20 = fullspeed * 0.64999998;
                v21 = "crouch";
              }
              else
              {
                strstr((unsigned __int8 *)v4, "prone");
                if ( v22 )
                {
                  v20 = fullspeed * 0.15000001;
                  v21 = "prone";
                }
                else
                {
                  strstr((unsigned __int8 *)v4, "walk");
                  if ( v23 )
                  {
                    v20 = fullspeed * 0.40000001;
                    v21 = "walk";
                  }
                  else
                  {
                    strstr((unsigned __int8 *)v4, "fast");
                    if ( v24 )
                    {
                      SprintSpeedScale = BG_GetSprintSpeedScale();
                      v21 = "sprint";
                      fullspeed = SprintSpeedScale * fullspeed;
                    }
                    else
                    {
                      v21 = "run";
                    }
                    v20 = fullspeed;
                  }
                }
              }
              v26 = *(float *)(v4 + 76);
              *(float *)&i = vDelta.y * vDelta.y;
              Com_Printf(
                18,
                "Anim '%s' moves %f units over %ims (%f units/s), will play back at %.1f%% speed when player moves at ful"
                "l %s speed (%.0f units/sec)\n",
                (const char *)v4,
                fsqrt((float)((float)(vDelta.y * vDelta.y) + (float)(vDelta.x * vDelta.x)) + (float)(vDelta.z * vDelta.z)),
                v14,
                v26,
                (float)((float)(v20 * 100.0) / v26),
                v21,
                v20);
            }
          }
          if ( *(int *)(v4 + 84) < 500 )
            *(_DWORD *)(v4 + 84) = 500;
        }
        if ( XAnimIsLooped(pXAnims, v5) )
          *(_DWORD *)(v4 + 92) |= 0x200u;
        if ( Dvar_GetBool(animScript_listAnims) )
        {
          ++devNumNamedAnims;
          Com_Printf(18, "%s\n", (const char *)v4);
        }
      }
      else
      {
        *(_DWORD *)(v4 + 92) |= 1u;
        I_strncpyz((char *)v4, v7->szAnimName, 64);
        v9 = *(_DWORD *)(v4 + 64) == 0;
        *(_DWORD *)(v4 + 88) = v7->iNameHash;
        if ( v9 )
          *(_DWORD *)(v4 + 64) = -1;
        *(_DWORD *)(v4 + 76) = 0;
        *(_DWORD *)(v4 + 80) = 0;
        *(_DWORD *)(v4 + 84) = 0;
        *(_DWORD *)(v4 + 68) = -1;
        *(float *)(v4 + 72) = FLOAT_N1_0;
      }
    }
    else
    {
LABEL_19:
      *(_DWORD *)(v4 + 92) |= 0x2000u;
      I_strncpyz((char *)v4, "unused", 64);
      *(_DWORD *)(v4 + 88) = 0;
    }
    v1 = (const char *)_tls_index;
    ++v5;
    v4 += 120;
  }
  if ( Dvar_GetBool(animScript_listAnims) )
  {
    Com_Printf(18, "\n%i total player anims.\n", devNumNamedAnims);
    Com_Printf(18, "===========================================================\n");
  }
  BG_AnimParseAnimScript(
    v31,
    v1,
    **(animScriptData_t ***)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + (_DWORD)v1) + 14960),
    0,
    0);
  BG_SetupAnimNoteTypes(**(animScriptData_t ***)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + (_DWORD)v1)
                                               + 14960));
}

#endif // __UNIMPLEMENTED__
