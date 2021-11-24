// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x951A30
// local variable allocation has failed, the output may be wrong!
char __usercall BG_CheckProne@<al>(
        unsigned int a1@<ebp>,
        const playerState_s *ps,
        int passEntityNum,
        const vec3_t *vPos,
        const float fSize,
        const float fHeight,
        const float fYaw,
        float *pfTorsoPitch,
        float *pfWaistPitch,
        bool isAlreadyProne,
        bool isOnGround,
        bool groundIsWalkable,
        unsigned __int8 handler,
        proneCheckType_t proneCheckType,
        float prone_feet_dist)
{
  BOOL IsSliding; // eax
  float v16; // xmm0_4
  char *v17; // esi
  float z; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  int v39; // xmm0_4
  float v40; // xmm3_4
  float v41; // esi
  float v42; // xmm2_4
  float *v43; // eax
  float angle; // [esp+4h] [ebp-140h]
  float anglea; // [esp+4h] [ebp-140h]
  _BYTE v46[12]; // [esp+18h] [ebp-12Ch] BYREF
  col_context_t context; // [esp+24h] [ebp-120h]
  float *v48; // [esp+4Ch] [ebp-F8h]
  float fTraceHeight; // [esp+50h] [ebp-F4h]
  float v50; // [esp+54h] [ebp-F0h]
  int v51; // [esp+58h] [ebp-ECh]
  float v52; // [esp+5Ch] [ebp-E8h]
  int v53; // [esp+60h] [ebp-E4h]
  int skip_adjustments; // [esp+64h] [ebp-E0h]
  float fPitchDiff; // [esp+68h] [ebp-DCh]
  int bFirstTraceHit; // [esp+6Ch] [ebp-D8h]
  void (__cdecl *trace)(trace_t *, const vec3_t *, const vec3_t *, const vec3_t *, const vec3_t *, int, int, col_context_t *); // [esp+70h] [ebp-D4h]
  float fFirstTraceDist; // [esp+74h] [ebp-D0h]
  _BYTE fWaistPitch[76]; // [esp+78h] [ebp-CCh] OVERLAPPED BYREF
  float v60; // [esp+C4h] [ebp-80h]
  vec3_t vTorsoPos; // [esp+C8h] [ebp-7Ch] BYREF
  float v62; // [esp+D4h] [ebp-70h]
  vec3_t vWaistPos; // [esp+D8h] [ebp-6Ch] BYREF
  float v64; // [esp+E4h] [ebp-60h]
  float v65; // [esp+E8h] [ebp-5Ch]
  vec3_t vForward; // [esp+ECh] [ebp-58h] BYREF
  vec3_t vMins; // [esp+F8h] [ebp-4Ch]
  vec3_t vFeetPos; // [esp+104h] [ebp-40h] BYREF
  vec3_t vMaxs; // [esp+110h] [ebp-34h] BYREF
  vec3_t vDelta; // [esp+11Ch] [ebp-28h] BYREF
  vec3_t vStart; // [esp+128h] [ebp-1Ch] BYREF
  vec3_t vEnd; // [esp+134h] [ebp-10h]
  unsigned int retaddr; // [esp+144h] [ebp+0h]

  *(_QWORD *)&vEnd.v[1] = __PAIR64__(retaddr, a1);
  v48 = pfWaistPitch;
  context.locational = (int)ps;
  fTraceHeight = *(float *)&pfTorsoPitch;
  HIBYTE(skip_adjustments) = handler;
  *(_OWORD *)fWaistPitch = 0i64;
  v53 = 0;
  HIBYTE(fFirstTraceDist) = 1;
  col_context_t::col_context_t((col_context_t *)v46);
  if ( !ps || (ps->pm_flags & 0x200000) == 0 || (IsSliding = Dtp_IsSliding(ps), v51 = 1, IsSliding) )
    v51 = 0;
  *(float *)&bFirstTraceHit = FLOAT_12_0;
  BYTE2(fFirstTraceDist) = 0;
  if ( ps && ps->pm_type == 7 )
  {
    if ( Com_SessionMode_IsMode(SESSIONMODE_ZOMBIES) )
    {
      v16 = FLOAT_N0_5;
      lastStandDistScale = FLOAT_N0_5;
      BYTE2(fFirstTraceDist) = 1;
    }
    else
    {
      v16 = lastStandDistScale;
    }
    *(float *)&bFirstTraceHit = v16 * 12.0;
    prone_feet_dist = v16 * prone_feet_dist;
  }
  trace = pmoveHandlers[HIBYTE(skip_adjustments)].trace;
  if ( !trace
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          2540,
          0,
          "(traceFunc)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v17 = (char *)&loc_81000F + (proneCheckType != PCT_CLIENT ? 0x10000 : 0) + 2;
  if ( !isAlreadyProne )
  {
    LODWORD(vForward.x) = LODWORD(fSize) ^ _mask__NegFloat_;
    *(_QWORD *)&vForward.v[1] = LODWORD(fSize) ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
    z = vPos->z;
    x = vPos->x;
    vFeetPos.x = fSize;
    *(_QWORD *)&vFeetPos.v[1] = __PAIR64__(LODWORD(fHeight), LODWORD(fSize));
    y = vPos->y;
    vDelta.x = x;
    *(_QWORD *)&vDelta.v[1] = __PAIR64__(LODWORD(z), LODWORD(y));
    *(_QWORD *)&vStart.x = __PAIR64__(LODWORD(y), LODWORD(x));
    vStart.z = z + 10.0;
    trace((trace_t *)fWaistPitch, &vDelta, &vForward, &vFeetPos, &vStart, passEntityNum, (int)v17, (col_context_t *)v46);
    if ( fWaistPitch[42] )
      return 0;
  }
  if ( isOnGround && !groundIsWalkable )
    return 0;
  vForward.x = FLOAT_N6_0;
  vForward.y = FLOAT_N6_0;
  vForward.z = FLOAT_N6_0;
  vFeetPos.x = FLOAT_6_0;
  vFeetPos.y = FLOAT_6_0;
  vFeetPos.z = FLOAT_6_0;
  vStart.x = 0.0;
  vStart.y = fYaw - 180.0;
  vStart.z = 0.0;
  AngleVectors(&vStart, (vec3_t *)&vWaistPos.v[2], 0, 0);
  v21 = vPos->x;
  v22 = vPos->y;
  v23 = vPos->z + (float)(fHeight - 6.0);
  *(float *)&context.priorityMap = fHeight - 6.0;
  vStart.x = (float)(vWaistPos.z * (float)(prone_feet_dist - 6.0)) + v21;
  vStart.y = (float)(v64 * (float)(prone_feet_dist - 6.0)) + v22;
  *(_QWORD *)&vDelta.x = __PAIR64__(LODWORD(v22), LODWORD(v21));
  vDelta.z = v23;
  *(float *)&context.collide_entity_func = prone_feet_dist - 6.0;
  vStart.z = (float)(v65 * (float)(prone_feet_dist - 6.0)) + v23;
  trace((trace_t *)fWaistPitch, &vDelta, &vForward, &vFeetPos, &vStart, passEntityNum, (int)v17, (col_context_t *)v46);
  v24 = *(float *)&fWaistPitch[16];
  if ( *(float *)&fWaistPitch[16] < 1.0 )
  {
    if ( !isOnGround )
      return 0;
    v25 = (float)(*(float *)&context.collide_entity_func * *(float *)&fWaistPitch[16]) + 6.0;
    v53 = 1;
    fPitchDiff = v25;
    if ( (float)(fSize + 2.0) > v25 )
      return 0;
    v50 = (float)(*(float *)&context.priorityMap * 0.69999999) + *(float *)&bFirstTraceHit;
    if ( v50 <= v25 )
      goto LABEL_26;
    vMaxs.x = vStart.x - vDelta.x;
    vStart.z = vStart.z + 22.0;
    v53 = 0;
    vMaxs.y = vStart.y - vDelta.y;
    vMaxs.z = vStart.z - vDelta.z;
    v52 = Vec3NormalizeTo(&vMaxs, (vec3_t *)&vWaistPos.v[2]);
    trace((trace_t *)fWaistPitch, &vDelta, &vForward, &vFeetPos, &vStart, passEntityNum, (int)v17, (col_context_t *)v46);
    v24 = *(float *)&fWaistPitch[16];
    if ( *(float *)&fWaistPitch[16] < 1.0 )
    {
      v53 = 1;
      fPitchDiff = (float)(v52 * *(float *)&fWaistPitch[16]) + 6.0;
      if ( v50 > fPitchDiff )
        return 0;
      goto LABEL_26;
    }
  }
  fPitchDiff = prone_feet_dist;
LABEL_26:
  vMins.x = (float)((float)(vStart.x - vDelta.x) * v24) + vDelta.x;
  vMins.y = (float)((float)(vStart.y - vDelta.y) * v24) + vDelta.y;
  v27 = (float)((float)(vStart.z - vDelta.z) * v24) + vDelta.z;
  v28 = (float)(vWaistPos.z * *(float *)&bFirstTraceHit) + vPos->x;
  vMins.z = v27;
  vDelta.x = v28;
  vStart.x = v28;
  v29 = (float)(v64 * *(float *)&bFirstTraceHit) + vPos->y;
  vDelta.z = (float)((float)(v65 * *(float *)&bFirstTraceHit) + vPos->z) + *(float *)&context.priorityMap;
  vDelta.y = v29;
  vStart.y = v29;
  v50 = (float)((float)(fSize * 2.5) + *(float *)&context.priorityMap) - 6.0;
  vStart.z = vDelta.z - v50;
  trace((trace_t *)fWaistPitch, &vDelta, &vForward, &vFeetPos, &vStart, passEntityNum, (int)v17, (col_context_t *)v46);
  if ( *(float *)&fWaistPitch[16] == 1.0 )
    goto LABEL_68;
  if ( !fWaistPitch[44] )
    return 0;
  v30 = (float)((float)((float)(vStart.z - vDelta.z) * *(float *)&fWaistPitch[16]) + vDelta.z) - 6.0;
  vTorsoPos.y = (float)((float)(vStart.x - vDelta.x) * *(float *)&fWaistPitch[16]) + vDelta.x;
  vTorsoPos.z = (float)((float)(vStart.y - vDelta.y) * *(float *)&fWaistPitch[16]) + vDelta.y;
  v62 = v30;
  if ( v53 )
  {
    if ( (float)((float)((float)(v50 * *(float *)&fWaistPitch[16]) + 6.0) * -0.75) > (float)(fPitchDiff
                                                                                           - (float)((float)(v50 * *(float *)&fWaistPitch[16]) + 6.0)) )
      goto LABEL_68;
    vMaxs.x = (float)(vWaistPos.z * 6.0)
            + (float)(vMins.x - (float)((float)((float)(vStart.x - vDelta.x) * *(float *)&fWaistPitch[16]) + vDelta.x));
    vMaxs.y = (float)(v64 * 6.0)
            + (float)(vMins.y - (float)((float)((float)(vStart.y - vDelta.y) * *(float *)&fWaistPitch[16]) + vDelta.y));
    vMaxs.z = (float)((float)(v65 * 6.0) + (float)(vMins.z - v30)) + 6.0;
    Vec3Normalize(&vMaxs);
    vStart.z = (float)(vMaxs.z * (float)(*(float *)&context.collide_entity_func - *(float *)&bFirstTraceHit)) + vDelta.z;
    v31 = (float)((float)((float)(v64 * *(float *)&context.collide_entity_func) + vPos->y)
                + (float)((float)(vMaxs.y * (float)(*(float *)&context.collide_entity_func - *(float *)&bFirstTraceHit))
                        + vDelta.y))
        * 0.5;
    vStart.x = (float)((float)((float)(vWaistPos.z * *(float *)&context.collide_entity_func) + vPos->x)
                     + (float)((float)(vMaxs.x
                                     * (float)(*(float *)&context.collide_entity_func - *(float *)&bFirstTraceHit))
                             + vDelta.x))
             * 0.5;
    vStart.y = v31;
    trace((trace_t *)fWaistPitch, &vDelta, &vForward, &vFeetPos, &vStart, passEntityNum, (int)v17, (col_context_t *)v46);
    v32 = *(float *)&fWaistPitch[16];
    if ( *(float *)&fWaistPitch[16] < 1.0 )
    {
      vDelta.x = (float)((float)(vStart.x - vDelta.x) * *(float *)&fWaistPitch[16]) + vDelta.x;
      vDelta.y = (float)((float)(vStart.y - vDelta.y) * *(float *)&fWaistPitch[16]) + vDelta.y;
      vDelta.z = (float)((float)((float)(vStart.z - vDelta.z) * *(float *)&fWaistPitch[16]) + vDelta.z) + 18.0;
      vStart.z = vStart.z + 18.0;
      trace(
        (trace_t *)fWaistPitch,
        &vDelta,
        &vForward,
        &vFeetPos,
        &vStart,
        passEntityNum,
        (int)v17,
        (col_context_t *)v46);
      v32 = *(float *)&fWaistPitch[16];
      if ( *(float *)&fWaistPitch[16] < 1.0 )
        goto LABEL_68;
    }
    v33 = (float)((float)(vStart.x - vDelta.x) * v32) + vDelta.x;
    v34 = (float)((float)(vStart.y - vDelta.y) * v32) + vDelta.y;
    v35 = (float)((float)(vStart.z - vDelta.z) * v32) + vDelta.z;
    v30 = v62;
  }
  else
  {
    v33 = vMins.x;
    v34 = vMins.y;
    v35 = vMins.z;
  }
  vDelta.x = v33;
  *(_QWORD *)&vStart.x = __PAIR64__(LODWORD(v34), LODWORD(v33));
  *(_QWORD *)&vDelta.v[1] = __PAIR64__(LODWORD(v35), LODWORD(v34));
  vStart.z = v35 - (float)((float)((float)(v35 - v30) * 2.0) + fSize);
  trace((trace_t *)fWaistPitch, &vDelta, &vForward, &vFeetPos, &vStart, passEntityNum, (int)v17, (col_context_t *)v46);
  if ( *(float *)&fWaistPitch[16] == 1.0 )
  {
LABEL_68:
    v43 = v48;
    v41 = fTraceHeight;
    goto fail_2;
  }
  if ( !fWaistPitch[44] )
    return 0;
  v36 = vPos->z;
  vMins.x = (float)((float)(vStart.x - vDelta.x) * *(float *)&fWaistPitch[16]) + vDelta.x;
  vMins.y = (float)((float)(vStart.y - vDelta.y) * *(float *)&fWaistPitch[16]) + vDelta.y;
  v37 = vPos->y;
  vMins.z = (float)((float)((float)(vStart.z - vDelta.z) * *(float *)&fWaistPitch[16]) + vDelta.z) - 6.0;
  *(float *)&fWaistPitch[68] = vPos->x;
  *(float *)&fWaistPitch[72] = v37;
  v60 = v36;
  vMaxs.x = *(float *)&fWaistPitch[68] - vTorsoPos.y;
  vMaxs.y = v37 - vTorsoPos.z;
  vMaxs.z = v36 - v62;
  angle = vectopitch(&vMaxs);
  fPitchDiff = AngleNormalize180(angle);
  vMaxs.x = vTorsoPos.y - vMins.x;
  vMaxs.y = vTorsoPos.z - vMins.y;
  vMaxs.z = v62 - vMins.z;
  anglea = vectopitch(&vMaxs);
  *(float *)&bFirstTraceHit = AngleNormalize180(anglea);
  v52 = AngleDelta(fPitchDiff, *(const float *)&bFirstTraceHit);
  if ( BYTE2(fFirstTraceDist) )
    v38 = FLOAT_N65_0;
  else
    v38 = FLOAT_N50_0;
  if ( v38 > v52 || v52 > 70.0 )
    HIBYTE(fFirstTraceDist) = 0;
  vForward.x = FLOAT_N0_0;
  vForward.y = FLOAT_N0_0;
  vForward.z = FLOAT_N0_0;
  memset(&vFeetPos, 0, sizeof(vFeetPos));
  *(_QWORD *)&vDelta.x = *(_QWORD *)&fWaistPitch[68];
  vDelta.z = v60 + 5.0;
  *(_QWORD *)&vStart.x = *(_QWORD *)&vTorsoPos.v[1];
  vStart.z = v62 + 5.0;
  trace((trace_t *)fWaistPitch, &vDelta, &vForward, &vFeetPos, &vStart, passEntityNum, (int)v17, (col_context_t *)v46);
  if ( *(float *)&fWaistPitch[16] < 1.0 )
    HIBYTE(fFirstTraceDist) = 0;
  vDelta = vStart;
  *(_QWORD *)&vStart.x = *(_QWORD *)&vMins.x;
  vStart.z = vMins.z + 5.0;
  trace((trace_t *)fWaistPitch, &vDelta, &vForward, &vFeetPos, &vStart, passEntityNum, (int)v17, (col_context_t *)v46);
  if ( render_waist_foot_line )
  {
    vTorsoPos = vDelta;
    *(vec3_t *)&fWaistPitch[64] = vStart;
    render_line((const phys_vec3 *)&vTorsoPos, (const phys_vec3 *)&fWaistPitch[64], &colorWhite, 0, 0);
  }
  if ( Dvar_GetInt(enable_new_prone_check) || *(float *)&fWaistPitch[16] >= 1.0 )
  {
    v39 = bFirstTraceHit;
  }
  else if ( *(float *)&bFirstTraceHit >= 0.0 || *(float *)&bFirstTraceHit <= -20.0 )
  {
    v39 = 0;
    HIBYTE(fFirstTraceDist) = 0;
  }
  else
  {
    v39 = 0;
  }
  if ( context.locational && *(_DWORD *)(context.locational + 4) == 7 )
  {
    LODWORD(v40) = LODWORD(fPitchDiff) ^ _mask__NegFloat_;
    v39 ^= _mask__NegFloat_;
  }
  else
  {
    v40 = fPitchDiff;
  }
  v41 = fTraceHeight;
  if ( fTraceHeight != 0.0 )
  {
    if ( v51 )
      v42 = 0.0;
    else
      v42 = v40;
    *(float *)LODWORD(fTraceHeight) = v42;
  }
  v43 = v48;
  if ( v48 )
  {
    if ( v51 )
      v39 = 0;
    *(_DWORD *)v48 = v39;
  }
  if ( HIBYTE(fFirstTraceDist) )
    return 1;
fail_2:
  if ( isOnGround )
    return 0;
  if ( v41 != 0.0 )
    *(_DWORD *)LODWORD(v41) = 0;
  if ( v43 )
    *v43 = 0.0;
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x952710
void __cdecl BG_GetPlayerViewOrigin(const playerState_s *ps, vec3_t *origin, int time)
{
  float speed; // xmm0_4
  float v4; // xmm0_4
  float deltaB; // [esp+1Ch] [ebp-14h]
  float deltaBa; // [esp+1Ch] [ebp-14h]
  vec3_t vRight; // [esp+20h] [ebp-10h] BYREF

  if ( (ps->eFlags & 0x300) != 0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          2812,
          0,
          "(!( ps->eFlags & ((1<<8) | (1<<9)) ))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  *origin = ps->origin;
  origin->z = ps->viewHeightCurrent + origin->z;
  deltaB = BG_GetBobCycle(ps);
  if ( (ps->pm_flags & 8) != 0 )
  {
    if ( time - ps->jumpTime >= 500 )
      speed = ps->velocity.z;
    else
      speed = 0.0;
  }
  else
  {
    speed = fsqrt((float)(ps->velocity.x * ps->velocity.x) + (float)(ps->velocity.y * ps->velocity.y));
  }
  origin->z = BG_CalculateViewMovement_VerticalBobFactor(ps, deltaB, speed) + origin->z;
  deltaBa = BG_CalculateViewMovement_HorizontalBobFactor(ps, deltaB, speed);
  AngleVectors(&ps->viewangles, 0, &vRight, 0);
  origin->x = vRight.x * deltaBa + origin->x;
  origin->y = vRight.y * deltaBa + origin->y;
  origin->z = deltaBa * vRight.z + origin->z;
  if ( (ps->eFlags & 0x4000) == 0 )
    AddLeanToPosition(origin, ps->viewangles.y, ps->leanf, 16.0, 20.0);
  v4 = ps->origin.z + 8.0;
  if ( v4 > origin->z )
    origin->z = v4;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x9528C0
int __cdecl VEH_ParseSpecificField(
        unsigned __int8 *pStruct,
        const char *pValue,
        const int fieldType,
        const int fieldOffset)
{
  int v4; // esi
  int result; // eax
  int v6; // esi
  int v7; // esi
  const char *v8; // eax

  switch ( fieldType )
  {
    case 18:
      v4 = 0;
      while ( I_stricmp(pValue, s_vehicleClassNames[v4]) )
      {
        if ( ++v4 >= 7 )
          goto LABEL_7;
      }
      *((_WORD *)pStruct + 2) = v4;
LABEL_7:
      if ( v4 != 7 )
        goto $LN3_224;
      Com_Error(ERR_DROP, &byte_CEC0B8, pValue);
      result = 1;
      break;
    case 19:
      v6 = 0;
      while ( I_stricmp(pValue, s_vehicleCameraModes[v6]) )
      {
        if ( ++v6 >= 8 )
          goto LABEL_14;
      }
      *((_WORD *)pStruct + 18) = v6;
LABEL_14:
      if ( v6 != 8 )
        goto $LN3_224;
      Com_Error(ERR_DROP, &byte_CEC094, pValue);
      result = 1;
      break;
    case 20:
      v7 = 0;
      while ( I_stricmp(pValue, s_tractionTypeNames[v7]) )
      {
        if ( ++v7 >= 3 )
          goto LABEL_21;
      }
      *((_DWORD *)pStruct + 363) = v7;
LABEL_21:
      if ( v7 != 3 )
        goto $LN3_224;
      Com_Error(ERR_DROP, &byte_CEC074, pValue);
      result = 1;
      break;
    case 21:
      *(float *)&pStruct[fieldOffset] = atof(pValue) * 17.6;
      result = 1;
      break;
    case 22:
      *(float *)&pStruct[fieldOffset] = atof(pValue) * 0.001;
      result = 1;
      break;
    case 23:
      if ( I_stricmp(pValue, "axis") )
      {
        if ( I_stricmp(pValue, "allies") )
        {
          Com_Error(ERR_DROP, "unknown team '%s', should be axis or allies\n", pValue);
          goto $LN3_224;
        }
        *((_DWORD *)pStruct + 270) = 1;
        result = 1;
      }
      else
      {
        *((_DWORD *)pStruct + 270) = 2;
        result = 1;
      }
      break;
    case 26:
$LN3_224:
      result = 1;
      break;
    default:
      v8 = va("Bad vehicle field type %i\n", fieldType);
      if ( !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misctables.cpp", 143, 0, (const char *)&pBlock, v8) )
        __debugbreak();
      Com_Error(ERR_DROP, &byte_CEBFDC, fieldType);
      result = 0;
      break;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x9536B0
char __cdecl BG_WeaponHasPerk(Weapon weapon, unsigned int perkIndex)
{
  const WeaponVariantDef *WeaponVariantDef; // edi
  int v4; // ebx
  WeaponAttachment *v5; // eax
  const unsigned int *perks; // edi
  WeaponAttachment *attachments[3]; // [esp+8h] [ebp-Ch] BYREF

  WeaponVariantDef = BG_GetWeaponVariantDef(weapon);
  if ( perkIndex >= 0x3F
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\../bgame/bg_perks.h",
          94,
          0,
          "(unsigned)(perkIndex) < (unsigned)(PERK_COUNT)",
          "perkIndex doesn't index PERK_COUNT\n\t%i not in [0, %i)",
          perkIndex,
          63) )
  {
    __debugbreak();
  }
  if ( Com_BitCheckAssert(WeaponVariantDef->perks, perkIndex, 0xFFFFFFF) > 0 )
    return 1;
  BG_GetWeaponAttachments(weapon, (WeaponAttachment *(*)[3])attachments);
  v4 = 0;
  while ( 1 )
  {
    v5 = attachments[v4];
    if ( !v5 )
      return 0;
    perks = v5->perks;
    if ( perkIndex >= 0x3F
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\../bgame/bg_perks.h",
            94,
            0,
            "(unsigned)(perkIndex) < (unsigned)(PERK_COUNT)",
            "perkIndex doesn't index PERK_COUNT\n\t%i not in [0, %i)",
            perkIndex,
            63) )
    {
      __debugbreak();
    }
    if ( Com_BitCheckAssert(perks, perkIndex, 0xFFFFFFF) > 0 )
      break;
    if ( ++v4 >= 3 )
      return 0;
  }
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x953790
void __cdecl setup_gjkcc_input(pmove_t *pm, gjkcc_input_t *gjkcc_in)
{
  bool v2; // bl

  gjkcc_in->gjkcc_id = (unsigned int)pm;
  v2 = pm->handler == 1;
  gjkcc_in->proximity_data = &pm->proximity_data;
  gjkcc_in->is_server_thread = v2;
  gjkcc_in->proximity_mask = (int)&g_hunk_track[105885].filename + 3;
  if ( pm->handler == 1 )
    gjkcc_in->m_ent_num = pm->ps->clientNum;
  else
    gjkcc_in->m_ent_num = -1;
  gjkcc_in->m_gjk_query_flags = 3;
  gjkcc_in->m_gjk_cg = 0;
  gjkcc_in->m_mat = 0;
  gjkcc_in->create_info = 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x953800
float __usercall PM_GetMoveSpeedScale@<xmm0>(pmove_t *pm@<eax>, const WeaponDef *weapDef@<edi>)
{
  playerState_s *ps; // esi
  Weapon v4; // eax
  float result; // xmm0_4

  if ( !weapDef
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 334, 0, "(weapDef)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !Com_SessionMode_IsMode(SESSIONMODE_ZOMBIES) )
    return weapDef->moveSpeedScale;
  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 341, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = pm->ps;
  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 343, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (ps->pm_flags & 0x8000) == 0 )
    return weapDef->moveSpeedScale;
  if ( Com_BitCheckAssert(ps->perks, 37, 0xFFFFFFF) <= 0 )
  {
    v4.0 = BG_GetViewmodelWeaponIndex(ps).0;
    if ( !BG_WeaponHasPerk(v4, 0x25u) )
      return weapDef->moveSpeedScale;
  }
  result = weapDef->moveSpeedScale;
  if ( (float)(result - 1.1) < 0.0 )
    return FLOAT_1_1;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x9538F0
void __cdecl PM_AddEvent(playerState_s *ps, int newEvent)
{
  BG_AddPredictableEventToPlayerstate(newEvent, 0, ps);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x953910
void __cdecl PM_AddTouchEnt(pmove_t *pm, int entityNum)
{
  int numtouch; // edx
  int v3; // eax
  int *touchents; // ecx

  if ( entityNum != 1022 )
  {
    if ( !pm
      && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 463, 0, "(pm)", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    numtouch = pm->numtouch;
    if ( numtouch != 32 )
    {
      v3 = 0;
      if ( numtouch <= 0 )
      {
LABEL_10:
        pm->touchents[numtouch] = entityNum;
        ++pm->numtouch;
      }
      else
      {
        touchents = pm->touchents;
        while ( *touchents != entityNum )
        {
          ++v3;
          ++touchents;
          if ( v3 >= numtouch )
            goto LABEL_10;
        }
      }
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x953980
void __cdecl PM_AddTouchGlass(pmove_t *pm, int glassId)
{
  int numGlassTouch; // edx
  int v3; // eax
  int *touchGlasses; // ecx

  if ( glassId != -1 )
  {
    if ( (glassId < 0 || glassId >= 1000)
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp",
            495,
            0,
            "(glassId >= 0 && glassId < 1000)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( !pm
      && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 497, 0, "(pm)", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    numGlassTouch = pm->numGlassTouch;
    if ( numGlassTouch != 32 )
    {
      v3 = 0;
      if ( numGlassTouch <= 0 )
      {
LABEL_14:
        pm->touchGlasses[numGlassTouch] = glassId;
        ++pm->numGlassTouch;
      }
      else
      {
        touchGlasses = pm->touchGlasses;
        while ( *touchGlasses != glassId )
        {
          ++v3;
          ++touchGlasses;
          if ( v3 >= numGlassTouch )
            goto LABEL_14;
        }
      }
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x953AB0
void __cdecl PM_ProjectVelocity(const vec3_t *velIn, const vec3_t *normal, vec3_t *velOut)
{
  float v3; // xmm1_4
  float y; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  v3 = (float)(velIn->x * velIn->x) + (float)(velIn->y * velIn->y);
  if ( COERCE_FLOAT(LODWORD(normal->z) & _mask__AbsFloat_) < 0.001 || v3 == 0.0 )
  {
    *velOut = *velIn;
  }
  else
  {
    y = velIn->y;
    LODWORD(v5) = COERCE_UNSIGNED_INT((float)((float)(normal->y * y) + (float)(normal->x * velIn->x)) / normal->z) ^ _mask__NegFloat_;
    v6 = fsqrt((float)((float)(velIn->z * velIn->z) + v3) / (float)((float)(v5 * v5) + v3));
    if ( v6 < 1.0 || v5 < 0.0 || velIn->z > 0.0 )
    {
      velOut->x = velIn->x * v6;
      velOut->y = y * v6;
      velOut->z = v6 * v5;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x953BC0
int __cdecl PM_GetEffectiveStance(const playerState_s *ps)
{
  int viewHeightTarget; // eax
  int waterlevel; // eax

  viewHeightTarget = ps->viewHeightTarget;
  if ( viewHeightTarget == 22 )
  {
    waterlevel = ps->waterlevel;
    if ( waterlevel < 3 )
      return (waterlevel != 0) + 1;
    else
      return 0;
  }
  else if ( viewHeightTarget == 40 )
  {
    return 2;
  }
  else
  {
    return viewHeightTarget == 11;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x953C10
int __cdecl PM_GetSprintLeft(const playerState_s *ps, const int gametime)
{
  int MaxSprintTime; // edi
  int v3; // eax
  Weapon v4; // eax
  int lastSprintStart; // ecx
  int v6; // eax
  int result; // eax

  MaxSprintTime = BG_GetMaxSprintTime(ps);
  if ( BG_GetSprintUnlimited() )
  {
    v3 = MaxSprintTime;
  }
  else if ( Com_BitCheckAssert(ps->perks, 62, 0xFFFFFFF) > 0
         || (v4.0 = BG_GetViewmodelWeaponIndex(ps).0, BG_WeaponHasPerk(v4, 0x3Eu)) )
  {
    v3 = MaxSprintTime;
  }
  else
  {
    lastSprintStart = ps->sprintState.lastSprintStart;
    if ( lastSprintStart )
    {
      if ( lastSprintStart <= ps->sprintState.lastSprintEnd )
      {
        if ( ps->sprintState.sprintDelay )
          v6 = ps->sprintState.sprintStartMaxLength
             + -2 * ps->sprintState.lastSprintEnd
             - ps->sprintState.sprintCooldown;
        else
          v6 = ps->sprintState.sprintStartMaxLength - 2 * ps->sprintState.lastSprintEnd;
        v3 = gametime + lastSprintStart + v6;
      }
      else
      {
        v3 = lastSprintStart + ps->sprintState.sprintStartMaxLength - gametime;
      }
    }
    else
    {
      v3 = MaxSprintTime;
    }
  }
  result = v3 < 0 ? 0 : v3;
  if ( MaxSprintTime < result )
    return MaxSprintTime;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x953CE0
bool __cdecl PM_IsSprinting(const playerState_s *ps)
{
  int lastSprintStart; // eax

  lastSprintStart = ps->sprintState.lastSprintStart;
  return lastSprintStart && lastSprintStart > ps->sprintState.lastSprintEnd;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x953D00
void __usercall PM_StartSprint(playerState_s *ps@<esi>, pmove_t *pm, const pml_t *pml)
{
  int lastSprintEnd; // eax

  lastSprintEnd = ps->sprintState.lastSprintEnd;
  if ( lastSprintEnd
    && lastSprintEnd < ps->sprintState.lastSprintStart
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp",
          708,
          0,
          "(ss->lastSprintEnd == 0 || ss->lastSprintEnd >= ss->lastSprintStart)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps->sprintState.sprintStartMaxLength = (int)pml;
  ps->sprintState.lastSprintStart = pm->cmd.serverTime;
  ps->pm_flags |= 0x8000u;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x953D60
void __usercall PM_UpdateVisionAnims(pmove_t *pm@<esi>, pml_t *pml@<eax>)
{
  unsigned int *p_holdrand; // edi
  playerState_s *ps; // eax
  __int16 v4; // bx
  animScriptCommand_t *Command; // eax

  if ( pm->ps->pm_type < 10 )
  {
    p_holdrand = &pml->holdrand;
    if ( BG_IsShellshockAnim(pm->ps) )
    {
      BG_AnimScriptEvent(pm, ANIM_ET_SHELLSHOCK, 1, 0, p_holdrand);
    }
    else
    {
      ps = pm->ps;
      if ( pm->ps->visionSetLerpRatio <= 0.0 )
      {
        v4 = ps->torsoAnim & 0xFBFF;
        Command = BG_AnimScriptEventGetCommand(ps, ANIM_ET_SHELLSHOCK, p_holdrand);
        if ( Command )
        {
          if ( Command->animIndex[0] == v4 )
            BG_AnimScriptAnimation(pm, AISTATE_COMBAT, ANIM_MT_IDLE, 1);
        }
      }
      else
      {
        BG_AnimScriptEvent(pm, ANIM_ET_FLARED, 1, 0, p_holdrand);
      }
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x953E00
void __usercall PM_UpdateScriptedAnim(pmove_t *pm@<edi>, pml_t *pml)
{
  playerState_s *ps; // esi

  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 970, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (ps->pm_flags & 0x100000) != 0 )
  {
    if ( !ps->scriptedAnimTime )
      ps->scriptedAnimTime = pm->cmd.serverTime + BG_AnimScriptEvent(pm, ANIM_ET_SCRIPTEVENT, 0, 1, &pml->holdrand);
    if ( pm->cmd.serverTime < ps->scriptedAnimTime )
    {
      BG_AnimScriptEvent(pm, ANIM_ET_SCRIPTEVENT, 1, 0, &pml->holdrand);
    }
    else
    {
      ps->scriptedAnimTime = 0;
      if ( !pm->handler )
        ps->scriptedAnim = 0;
      ps->pm_flags &= ~0x100000u;
      ps->torsoTimer = 0;
      ps->legsTimer = 0;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x953EC0
int __cdecl PM_GetEntityOrigin(
        const unsigned __int8 handler,
        LocalClientNum_t localClientNum,
        int entIndex,
        vec3_t *outPosition)
{
  char (__cdecl *v4)(LocalClientNum_t, int, vec3_t *, vec3_t *); // eax
  vec3_t angles; // [esp+0h] [ebp-10h] BYREF

  v4 = (char (__cdecl *)(LocalClientNum_t, int, vec3_t *, vec3_t *))*(&funcs_953EF4 + 9 * handler);
  if ( v4 )
    return (unsigned __int8)v4(localClientNum, entIndex, outPosition, &angles);
  else
    return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x953F20
BOOL __cdecl PM_GetEntityVelocity(
        const unsigned __int8 handler,
        LocalClientNum_t localClientNum,
        int entIndex,
        vec3_t *outVelocity)
{
  bool (__cdecl *v4)(LocalClientNum_t, int, vec3_t *); // eax

  v4 = *(&funcs_953F41 + 9 * handler);
  return v4 && v4(localClientNum, entIndex, outVelocity);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x953F50
void __usercall PM_GetMeleeChargeFriction(pmove_t *pm@<edi>)
{
  playerState_s *ps; // esi
  int weaponstate; // eax
  int weaponDelay; // eax
  bool v4; // cl
  int meleeChargeEnt; // eax
  vec3_t targetOrigin; // [esp+10h] [ebp-10h] BYREF

  if ( !Dvar_GetBool(player_meleeCalcSpeedFromTarget) )
    goto LABEL_21;
  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 1140, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 1143, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  weaponstate = ps->weaponstate;
  if ( weaponstate == 19 || weaponstate == 20 || weaponstate == 21 )
    weaponDelay = ps->weaponDelay;
  else
    weaponDelay = ps->weaponDelayLeft;
  v4 = weaponDelay <= 0 && ps->meleeChargeTime > 0;
  meleeChargeEnt = ps->meleeChargeEnt;
  if ( meleeChargeEnt == 1023
    || !v4
    || !PM_GetEntityOrigin(pm->handler, pm->localClientNum, meleeChargeEnt, &targetOrigin)
    || (float)(fsqrt((float)(ps->velocity.x * ps->velocity.x) + (float)(ps->velocity.y * ps->velocity.y))
             * (float)((float)ps->meleeChargeTime * 0.001)) <= (float)(fsqrt(
                                                                         (float)((float)(ps->origin.y - targetOrigin.y)
                                                                               * (float)(ps->origin.y - targetOrigin.y))
                                                                       + (float)((float)(ps->origin.x - targetOrigin.x)
                                                                               * (float)(ps->origin.x - targetOrigin.x)))
                                                                     - 15.0) )
  {
LABEL_21:
    Dvar_GetFloat(player_meleeChargeFriction);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x9540E0
void __usercall PM_Friction(playerState_s *ps@<esi>, pmove_t *pm@<ecx>, double a3@<st0>, pml_t *pml)
{
  int walking; // eax
  float z; // xmm0_4
  int pm_flags; // ecx
  float v8; // xmm1_4
  double Float; // st7
  float v10; // xmm0_4
  int v11; // eax
  int waterlevel; // eax
  bool v13; // zf
  double v14; // st7
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // [esp+8h] [ebp-2Ch]
  float speed; // [esp+Ch] [ebp-28h]
  float stopspeed_value; // [esp+10h] [ebp-24h]
  float stopspeed_valueb; // [esp+10h] [ebp-24h]
  float stopspeed_valuea; // [esp+10h] [ebp-24h]
  float stopspeed_valuec; // [esp+10h] [ebp-24h]
  float scales[7]; // [esp+14h] [ebp-20h]
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 1196, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  walking = pml->walking;
  z = ps->velocity.z;
  if ( walking )
    z = 0.0;
  speed = fsqrt(
            (float)((float)(ps->velocity.y * ps->velocity.y) + (float)(ps->velocity.x * ps->velocity.x))
          + (float)(z * z));
  if ( speed < 1.0 )
  {
    *(_QWORD *)&ps->velocity.x = 0i64;
    ps->velocity.z = 0.0;
    return;
  }
  pm_flags = ps->pm_flags;
  v8 = 0.0;
  stopspeed_value = 0.0;
  if ( (pm_flags & 0x20000) != 0 )
  {
    if ( !Dvar_GetBool(player_meleeCOD4ChargeMovement) )
    {
      if ( ps->meleeChargeTime <= 0
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp",
              1223,
              0,
              "(ps->meleeChargeTime > 0)",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v8 = (float)(speed / (float)((float)ps->meleeChargeTime * 0.001)) * pml->frametime;
      stopspeed_value = v8;
      goto LABEL_32;
    }
    PM_GetMeleeChargeFriction(pm);
    goto LABEL_31;
  }
  if ( ps->waterlevel > 1 )
    goto LABEL_32;
  if ( !walking || (pm_flags & 0x40000100) != 0 )
    goto LABEL_29;
  if ( (pml->groundTrace.sflags & 2) == 0 )
  {
    Float = Dvar_GetFloat(stopspeed);
    if ( Float <= speed )
    {
      v10 = speed;
    }
    else
    {
      stopspeed_valueb = Float;
      v10 = stopspeed_valueb;
    }
    v11 = ps->pm_flags;
    stopspeed_valuea = v10;
    if ( (v11 & 0x80u) == 0 )
    {
      if ( (v11 & 0x4000) != 0 )
        stopspeed_valuea = Jump_ReduceFriction(ps) * v10;
    }
    else
    {
      stopspeed_valuea = v10 * 0.30000001;
    }
    if ( (ps->pm_flags & 0x200000) != 0 )
      stopspeed_valuea = Dtp_ReduceFriction((unsigned int)&savedregs, pm, ps) * stopspeed_valuea;
    stopspeed_value = BG_GetFriction() * stopspeed_valuea * pml->frametime;
    v8 = stopspeed_value;
LABEL_29:
    if ( (pml->groundTrace.sflags & 2) == 0 )
      goto LABEL_32;
  }
  a3 = Dvar_GetFloat(player_sliding_friction) * speed * pml->frametime + stopspeed_value;
LABEL_31:
  stopspeed_value = a3;
  v8 = stopspeed_value;
LABEL_32:
  waterlevel = ps->waterlevel;
  if ( waterlevel )
  {
    v13 = pml->walking == 0;
    LODWORD(scales[1]) = FLOAT_1_0;
    scales[2] = FLOAT_2_0;
    scales[3] = FLOAT_2_0;
    scales[0] = 0.0;
    scales[4] = FLOAT_3_0;
    scales[5] = FLOAT_3_0;
    scales[6] = FLOAT_3_0;
    if ( !v13 )
    {
      if ( waterlevel == 2 )
      {
        v19 = Dvar_GetFloat(player_waistWaterFrictionScale);
        v14 = BG_GetFriction() * speed * v19;
      }
      else
      {
        v14 = BG_GetFriction() * speed * scales[ps->waterlevel];
      }
      stopspeed_valuec = v14 * pml->frametime + stopspeed_value;
      v8 = stopspeed_valuec;
    }
  }
  if ( ps->pm_type == 5 )
    v8 = (float)((float)(speed * 5.0) * pml->frametime) + v8;
  v15 = speed - v8;
  if ( (float)(speed - v8) < 0.0 )
    v15 = 0.0;
  v16 = v15 / speed;
  ps->velocity.x = ps->velocity.x * v16;
  v17 = ps->velocity.y * v16;
  v18 = v16 * ps->velocity.z;
  ps->velocity.y = v17;
  ps->velocity.z = v18;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x9543F0
void __usercall PM_Accelerate(
        playerState_s *ps@<esi>,
        vec3_t *wishdir@<edi>,
        const pml_t *pml,
        float wishspeed,
        float accel)
{
  double Float; // st7
  float v6; // xmm1_4
  float v7; // xmm0_4
  float x; // xmm7_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm5_4
  float v13; // xmm6_4
  float v14; // xmm3_4
  float v15; // xmm6_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float addspeed; // [esp+4h] [ebp-Ch]
  float stopspeed_value; // [esp+8h] [ebp-8h]

  if ( (ps->pm_flags & 8) != 0 )
  {
    x = ps->velocity.x;
    v9 = (float)(wishdir->y * wishspeed) - ps->velocity.y;
    v10 = (float)(wishdir->x * wishspeed) - x;
    v11 = (float)(wishdir->z * wishspeed) - ps->velocity.z;
    v12 = fsqrt((float)((float)(v9 * v9) + (float)(v10 * v10)) + (float)(v11 * v11));
    if ( COERCE_FLOAT(LODWORD(v12) ^ _mask__NegFloat_) < 0.0 )
      v13 = v12;
    else
      v13 = *(float *)&FLOAT_1_0;
    v14 = 1.0 / v13;
    v15 = v10 * (float)(1.0 / v13);
    v16 = (float)(pml->frametime * accel) * wishspeed;
    v17 = v9 * v14;
    v18 = v11 * v14;
    if ( v16 > v12 )
      v16 = v12;
    ps->velocity.x = (float)(v15 * v16) + x;
    ps->velocity.y = (float)(v17 * v16) + ps->velocity.y;
    ps->velocity.z = (float)(v18 * v16) + ps->velocity.z;
  }
  else
  {
    addspeed = wishspeed
             - (float)((float)((float)(ps->velocity.x * wishdir->x) + (float)(ps->velocity.y * wishdir->y))
                     + (float)(ps->velocity.z * wishdir->z));
    if ( addspeed > 0.0 )
    {
      Float = Dvar_GetFloat(stopspeed);
      if ( Float <= wishspeed )
      {
        v6 = wishspeed;
      }
      else
      {
        stopspeed_value = Float;
        v6 = stopspeed_value;
      }
      v7 = (float)(pml->frametime * accel) * v6;
      if ( v7 > addspeed )
        v7 = addspeed;
      ps->velocity.x = (float)(wishdir->x * v7) + ps->velocity.x;
      ps->velocity.y = (float)(wishdir->y * v7) + ps->velocity.y;
      ps->velocity.z = (float)(v7 * wishdir->z) + ps->velocity.z;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x9545B0
void __fastcall PM_DoSlideAdjustments(const pml_t *pml, playerState_s *ps)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  double v10; // st7
  float v11; // xmm1_4
  float v12; // xmm2_4
  vec3_t *p_velocity; // ebx
  float v14; // xmm3_4
  float wishspeed; // [esp+14h] [ebp-18h]
  float accelb; // [esp+18h] [ebp-14h]
  float accel; // [esp+18h] [ebp-14h]
  float accelc; // [esp+18h] [ebp-14h]
  float accela; // [esp+18h] [ebp-14h]
  vec3_t nvel; // [esp+1Ch] [ebp-10h] BYREF

  if ( (pml->groundTrace.sflags & 2) != 0 )
  {
    v4 = pml->groundTrace.normal.vec.m128_f32[0];
    v5 = pml->groundTrace.normal.vec.m128_f32[1];
    v6 = fsqrt((float)(v5 * v5) + (float)(v4 * v4));
    if ( COERCE_FLOAT(LODWORD(v6) ^ _mask__NegFloat_) >= 0.0 )
      v6 = *(float *)&FLOAT_1_0;
    nvel.x = v4 * (float)(1.0 / v6);
    nvel.y = v5 * (float)(1.0 / v6);
    nvel.z = (float)(1.0 / v6) * 0.0;
    accelb = Dvar_GetFloat(player_sliding_wishspeed);
    PM_Accelerate(ps, &nvel, pml, accelb, ::accel);
    accel = Dvar_GetFloat(player_sliding_velocity_cap);
    if ( fsqrt(
           (float)((float)(ps->velocity.x * ps->velocity.x) + (float)(ps->velocity.y * ps->velocity.y))
         + (float)(ps->velocity.z * ps->velocity.z)) > (float)(accel * accel) )
    {
      v7 = fsqrt(
             (float)((float)(ps->velocity.x * ps->velocity.x) + (float)(ps->velocity.y * ps->velocity.y))
           + (float)(ps->velocity.z * ps->velocity.z));
      if ( COERCE_FLOAT(LODWORD(v7) ^ _mask__NegFloat_) >= 0.0 )
        v7 = *(float *)&FLOAT_1_0;
      v8 = (float)(ps->velocity.y * (float)(1.0 / v7)) * accel;
      v9 = (float)(ps->velocity.z * (float)(1.0 / v7)) * accel;
      ps->velocity.x = (float)(ps->velocity.x * (float)(1.0 / v7)) * accel;
      ps->velocity.y = v8;
      ps->velocity.z = v9;
    }
  }
  else if ( (ps->pm_flags & 0x40000000) != 0 && pml->groundTrace.hitType )
  {
    v10 = 1.0 / Dvar_GetFloat(player_slick_invspeed);
    v11 = pml->groundTrace.normal.vec.m128_f32[0];
    v12 = pml->groundTrace.normal.vec.m128_f32[1];
    p_velocity = &ps->velocity;
    v14 = fsqrt((float)(v12 * v12) + (float)(v11 * v11));
    nvel.x = ps->velocity.x * v10;
    nvel.y = v10 * ps->velocity.y;
    if ( COERCE_FLOAT(LODWORD(v14) ^ _mask__NegFloat_) >= 0.0 )
      v14 = *(float *)&FLOAT_1_0;
    nvel.x = (float)((float)((float)(v11 * (float)(1.0 / v14)) * 2.0) + nvel.x) * 0.333;
    nvel.y = (float)((float)((float)(v12 * (float)(1.0 / v14)) * 2.0) + nvel.y) * 0.333;
    nvel.z = (float)((float)((float)(1.0 / v14) * 0.0) * 2.0) * 0.333;
    accelc = Dvar_GetFloat(player_slick_accel);
    wishspeed = Dvar_GetFloat(player_slick_wishspeed);
    PM_Accelerate(ps, &nvel, pml, wishspeed, accelc);
    accela = Dvar_GetFloat(player_sliding_velocity_cap);
    if ( fsqrt(
           (float)((float)(p_velocity->x * p_velocity->x) + (float)(ps->velocity.y * ps->velocity.y))
         + (float)(ps->velocity.z * ps->velocity.z)) > (float)(accela * accela) )
    {
      Vec3NormalizeTo(&ps->velocity, &nvel);
      p_velocity->x = nvel.x * accela;
      ps->velocity.y = nvel.y * accela;
      ps->velocity.z = nvel.z * accela;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0x9548D0
float __usercall PM_MoveScale@<xmm0>(playerState_s *ps@<esi>, float fmove, float rmove, float umove)
{
  float v4; // xmm1_4
  float result; // xmm0_4
  int pm_type; // eax
  float max; // [esp+0h] [ebp-4h]
  float scale; // [esp+Ch] [ebp+8h]

  LODWORD(v4) = LODWORD(fmove) & _mask__AbsFloat_;
  LODWORD(max) = LODWORD(fmove) & _mask__AbsFloat_;
  if ( COERCE_FLOAT(LODWORD(rmove) & _mask__AbsFloat_) > COERCE_FLOAT(LODWORD(fmove) & _mask__AbsFloat_) )
  {
    LODWORD(v4) = LODWORD(rmove) & _mask__AbsFloat_;
    LODWORD(max) = LODWORD(rmove) & _mask__AbsFloat_;
  }
  if ( COERCE_FLOAT(LODWORD(umove) & _mask__AbsFloat_) > v4 )
  {
    LODWORD(v4) = LODWORD(umove) & _mask__AbsFloat_;
    LODWORD(max) = LODWORD(umove) & _mask__AbsFloat_;
  }
  result = 0.0;
  if ( v4 != 0.0 )
  {
    if ( !ps )
    {
      if ( !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 1430, 0, "(ps)", (const char *)&pBlock) )
        __debugbreak();
      v4 = max;
    }
    result = (float)((float)ps->speed * v4)
           / (float)(fsqrt((float)((float)(fmove * fmove) + (float)(rmove * rmove)) + (float)(umove * umove)) * 127.0);
    scale = result;
    if ( (ps->pm_flags & 0x40) != 0 || ps->leanf != 0.0 )
    {
      result = result * 0.40000001;
      scale = result;
    }
    pm_type = ps->pm_type;
    if ( pm_type == 2 )
    {
      result = result * 3.0;
      scale = result;
    }
    if ( pm_type == 3 )
    {
      scale = Dvar_GetFloat(cg_ufo_scaler) * scale;
      result = scale;
    }
    if ( ps->pm_type == 5 )
      return Dvar_GetFloat(player_spectateSpeedScale) * scale;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0xA47E80
BOOL __cdecl R_SortSurfacesOnAxis_NegX(const GfxSurface *surf0, const GfxSurface *surf1)
{
  return (float)((float)(surf0->bounds[1].x + surf0->bounds[0].x) * 0.5) > (float)((float)(surf1->bounds[1].x
                                                                                         + surf1->bounds[0].x)
                                                                                 * 0.5);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdnattravclient.cpp:0xA47EC0
BOOL __cdecl R_SortSurfacesOnAxis_PosY(const GfxSurface *surf0, const GfxSurface *surf1)
{
  return (float)((float)(surf1->bounds[1].y + surf1->bounds[0].y) * 0.5) > (float)((float)(surf0->bounds[1].y
                                                                                         + surf0->bounds[0].y)
                                                                                 * 0.5);
}

#endif // __UNIMPLEMENTED__
