// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdauthservice-steam.cpp:0x93BEC0
void __cdecl BG_Player_DoControllersSetup(const entityState_s *es, clientInfo_t *ci, int frametime)
{
  int v3; // eax
  int *v4; // ecx
  int v5; // eax
  float v6; // xmm1_4
  controller_info_t *p_info; // edi
  clientControllers_t *p_control; // ecx
  float *v9; // eax
  int v10; // esi
  int v11; // edx
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  double v20; // st7
  float z; // xmm0_4
  int v22; // [esp+10h] [ebp-78h]
  float v23; // [esp+14h] [ebp-74h]
  controller_info_t info; // [esp+18h] [ebp-70h] BYREF
  float v25; // [esp+78h] [ebp-10h]
  float v26; // [esp+7Ch] [ebp-Ch]
  float v27; // [esp+80h] [ebp-8h]

  v3 = *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960);
  if ( v3 )
  {
    if ( (es->lerp.eFlags & 8) != 0 )
    {
      v4 = (int *)(v3 + 4 * es->number + 32);
      v5 = frametime + *v4;
      if ( v5 >= 500 )
        v5 = 500;
      *v4 = v5;
    }
    else
    {
      *(_DWORD *)(v3 + 4 * es->number + 32) = (*(_DWORD *)(v3 + 4 * es->number + 32) - frametime) & ((*(_DWORD *)(v3 + 4 * es->number + 32) - frametime <= 0) - 1);
    }
  }
  BG_Player_DoControllersInternal(es, ci, &info);
  v6 = (float)frametime * 0.30000001;
  p_info = &info;
  p_control = &ci->control;
  v22 = 6;
  do
  {
    v9 = (float *)p_control;
    v10 = (char *)p_info - (char *)p_control;
    v11 = 3;
    do
    {
      v12 = *(float *)((char *)v9 + v10) - *v9;
      if ( v12 <= v6 )
      {
        if ( COERCE_FLOAT(LODWORD(v6) ^ _mask__NegFloat_) <= v12 )
          *v9 = *(float *)((char *)v9 + v10);
        else
          *v9 = *v9 - v6;
      }
      else
      {
        *v9 = *v9 + v6;
      }
      ++v9;
      --v11;
    }
    while ( v11 );
    p_control = (clientControllers_t *)((char *)p_control + 12);
    p_info = (controller_info_t *)((char *)p_info + 12);
    --v22;
  }
  while ( v22 );
  v13 = info.tag_origin_angles.x - ci->control.tag_origin_angles.x;
  if ( v13 <= v6 )
  {
    if ( COERCE_FLOAT(LODWORD(v6) ^ _mask__NegFloat_) <= v13 )
      ci->control.tag_origin_angles.x = info.tag_origin_angles.x;
    else
      ci->control.tag_origin_angles.x = ci->control.tag_origin_angles.x - v6;
  }
  else
  {
    ci->control.tag_origin_angles.x = ci->control.tag_origin_angles.x + v6;
  }
  v14 = info.tag_origin_angles.y - ci->control.tag_origin_angles.y;
  if ( v14 <= v6 )
  {
    if ( COERCE_FLOAT(LODWORD(v6) ^ _mask__NegFloat_) <= v14 )
      ci->control.tag_origin_angles.y = info.tag_origin_angles.y;
    else
      ci->control.tag_origin_angles.y = ci->control.tag_origin_angles.y - v6;
  }
  else
  {
    ci->control.tag_origin_angles.y = v6 + ci->control.tag_origin_angles.y;
  }
  v15 = info.tag_origin_angles.z - ci->control.tag_origin_angles.z;
  if ( v15 <= v6 )
  {
    if ( COERCE_FLOAT(LODWORD(v6) ^ _mask__NegFloat_) <= v15 )
      ci->control.tag_origin_angles.z = info.tag_origin_angles.z;
    else
      ci->control.tag_origin_angles.z = ci->control.tag_origin_angles.z - v6;
  }
  else
  {
    ci->control.tag_origin_angles.z = ci->control.tag_origin_angles.z + v6;
  }
  v16 = info.tag_origin_offset.x - ci->control.tag_origin_offset.x;
  v17 = info.tag_origin_offset.z - ci->control.tag_origin_offset.z;
  v26 = info.tag_origin_offset.y - ci->control.tag_origin_offset.y;
  v25 = v16;
  v27 = v17;
  v18 = v16 * v16;
  v19 = v17 * v17;
  if ( (float)((float)((float)(v26 * v26) + v18) + v19) != 0.0 )
  {
    v20 = I_rsqrt((float)((float)(v26 * v26) + v18) + v19) * ((float)frametime * 0.1);
    v23 = v20;
    if ( v20 >= 1.0 )
    {
      *(_QWORD *)&ci->control.tag_origin_offset.x = *(_QWORD *)&info.tag_origin_offset.x;
      z = info.tag_origin_offset.z;
    }
    else
    {
      ci->control.tag_origin_offset.x = (float)(v25 * v23) + ci->control.tag_origin_offset.x;
      ci->control.tag_origin_offset.y = (float)(v26 * v23) + ci->control.tag_origin_offset.y;
      z = (float)(v27 * v23) + ci->control.tag_origin_offset.z;
    }
    ci->control.tag_origin_offset.z = z;
  }
}

#endif // __UNIMPLEMENTED__
