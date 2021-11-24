// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bducdaccountstatus.cpp:0x93B540
void __usercall BG_Player_DoControllersInternal(
        const entityState_s *es@<esi>,
        const clientInfo_t *ci@<ecx>,
        controller_info_t *info)
{
  int eFlags; // eax
  controller_info_t *v4; // ebx
  __int64 moveType; // kr00_8
  float angle; // xmm0_4
  double v8; // st7
  float v9; // xmm0_4
  const WeaponDef *WeaponDef; // eax
  long double LeanFraction; // st7
  float v12; // xmm3_4
  float v13; // xmm5_4
  BOOL v14; // ebx
  float v15; // xmm6_4
  float y; // xmm6_4
  int v17; // ecx
  __m128 y_low; // xmm0
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  __m128 v21; // xmm4
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  long double v24; // st7
  float v25; // xmm5_4
  __m128 fAimUpDown_low; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  __m128 v29; // xmm4
  __m128 v30; // xmm2
  __m128 v31; // xmm3
  BOOL v32; // edi
  float v33; // xmm0_4
  __m128 v34; // xmm0
  __m128 v35; // xmm3
  __m128 v36; // xmm1
  __m128 v37; // xmm4
  __m128 v38; // xmm2
  __m128 v39; // xmm3
  __m128 fAimLeftRight_low; // xmm1
  float z; // xmm0_4
  float v42; // xmm6_4
  float v43; // xmm7_4
  __m128 v44; // xmm3
  __m128 v45; // xmm0
  __m128 v46; // xmm4
  __m128 v47; // xmm2
  __m128 v48; // xmm3
  float x; // xmm1_4
  float v50; // xmm0_4
  float c; // [esp+Ch] [ebp-E8h] BYREF
  float s; // [esp+10h] [ebp-E4h] BYREF
  controller_info_t *p_s; // [esp+14h] [ebp-E0h]
  float v54; // [esp+18h] [ebp-DCh]
  float fLeanFrac; // [esp+1Ch] [ebp-D8h]
  vec3_t AimBlend_Back_Mid; // [esp+20h] [ebp-D4h] BYREF
  vec3_t AimBlend_Back_Up; // [esp+2Ch] [ebp-C8h] BYREF
  vec3_t AimBlend_Back_Low; // [esp+38h] [ebp-BCh] BYREF
  vec3_t AimBlend_Pelvis; // [esp+44h] [ebp-B0h] BYREF
  vec2_t lean_rotate_crouch; // [esp+50h] [ebp-A4h] BYREF
  vec3_t AimBlend_Head; // [esp+58h] [ebp-9Ch] BYREF
  vec2_t lean_rotate; // [esp+64h] [ebp-90h] BYREF
  vec3_t AimBlend_Neck; // [esp+6Ch] [ebp-88h] BYREF
  vec3_t tag_origin_offset; // [esp+78h] [ebp-7Ch]
  vec3_t tag_origin_angles; // [esp+84h] [ebp-70h] BYREF
  vec3_t vHeadAngles; // [esp+90h] [ebp-64h] BYREF
  vec3_t vTorsoAngles; // [esp+9Ch] [ebp-58h] BYREF
  vec3_t angles[6]; // [esp+A8h] [ebp-4Ch] BYREF

  eFlags = es->lerp.eFlags;
  v4 = info;
  p_s = info;
  if ( (eFlags & 0x300) != 0 && (es->lerp.eFlags2 & 0x10000000) == 0
    || (eFlags & 0x4000) != 0
    && (!es->lerp.u.player.vehicleSeat || (unsigned int)es->lerp.u.player.vehicleSeat - 1 <= 3)
    || (moveType = ci->moveType,
        tag_origin_angles.x = 0.0,
        vTorsoAngles.x = 0.0,
        vHeadAngles = ci->playerAngles,
        *(_QWORD *)&tag_origin_angles.v[1] = LODWORD(ci->legs.yawAngle),
        *(_QWORD *)&vTorsoAngles.v[1] = LODWORD(ci->torso.yawAngle),
        moveType == 24) )
  {
    memset((unsigned __int8 *)info, 0, sizeof(controller_info_t));
  }
  else
  {
    if ( moveType != 5 && moveType != 6 )
    {
      angle = ci->torso.pitchAngle;
      vTorsoAngles.x = angle;
      if ( (eFlags & 8) != 0 )
      {
        v8 = AngleNormalize180(angle);
        vTorsoAngles.x = v8;
        if ( v8 >= 0.0 )
          v9 = vTorsoAngles.x * 0.0;
        else
          v9 = vTorsoAngles.x * 0.5;
        vTorsoAngles.x = v9;
      }
    }
    WeaponDef = BG_GetWeaponDef(es->weapon);
    if ( WeaponDef && WeaponDef->weapType == WEAPTYPE_RIOTSHIELD )
      vTorsoAngles.x = AngleNormalize180(vTorsoAngles.x) * 0.5;
    AnglesSubtract(&vHeadAngles, &vTorsoAngles, &vHeadAngles);
    AnglesSubtract(&vTorsoAngles, &tag_origin_angles, &vTorsoAngles);
    *(_QWORD *)&tag_origin_offset.x = 0i64;
    LeanFraction = GetLeanFraction(ci->lerpLean);
    fLeanFrac = LeanFraction;
    v12 = fLeanFrac;
    v13 = fLeanFrac * 50.0;
    v54 = fLeanFrac * 50.0;
    vTorsoAngles.z = (float)(fLeanFrac * 50.0) * 0.92500001;
    vHeadAngles.z = vTorsoAngles.z;
    if ( LeanFraction == 0.0 )
    {
      y = tag_origin_offset.y;
    }
    else
    {
      v14 = fLeanFrac > 0.0;
      if ( (es->lerp.eFlags & 4) != 0 )
      {
        Dvar_GetVec2(player_lean_shift_crouch, &lean_rotate);
        v15 = lean_rotate.v[v14];
      }
      else
      {
        Dvar_GetVec2(player_lean_shift, &lean_rotate_crouch);
        v15 = lean_rotate_crouch.v[v14];
      }
      LODWORD(y) = COERCE_UNSIGNED_INT(v15 * fLeanFrac) ^ _mask__NegFloat_;
      v13 = v54;
      v12 = fLeanFrac;
      v4 = p_s;
      tag_origin_offset.y = y;
    }
    v17 = es->lerp.eFlags;
    if ( (v17 & 0x40000) == 0 )
    {
      y_low = (__m128)LODWORD(tag_origin_angles.y);
      y_low.m128_f32[0] = (float)(tag_origin_angles.y - ci->playerAngles.y) * 0.0027777778;
      v19.m128_f32[0] = FLOAT_8388608_0;
      v20 = y_low;
      v20.m128_f32[0] = y_low.m128_f32[0] + 0.5;
      v21 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v20);
      v19.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v20, v21), v19).m128_u32[0] | v21.m128_i32[0];
      v22 = v20;
      v22.m128_f32[0] = (float)((float)(y_low.m128_f32[0] + 0.5) + v19.m128_f32[0]) - v19.m128_f32[0];
      v23 = v22;
      v23.m128_f32[0] = v22.m128_f32[0] - (float)(y_low.m128_f32[0] + 0.5);
      v22.m128_f32[0] = v22.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v23, v21).m128_u32[0] & FLOAT_1_0);
      v12 = fLeanFrac;
      tag_origin_angles.y = (float)(y_low.m128_f32[0] - v22.m128_f32[0]) * 360.0;
    }
    memset(&angles[5], 0, sizeof(vec3_t));
    if ( (v17 & 8) != 0 )
    {
      if ( v12 != 0.0 )
        vHeadAngles.z = vHeadAngles.z * 0.5;
      tag_origin_angles.x = es->un2.animState.fAimLeftRight + tag_origin_angles.x;
      v54 = COERCE_FLOAT(&c);
      p_s = (controller_info_t *)&s;
      fLeanFrac = vTorsoAngles.y * 0.017453292;
      v24 = (float)(vTorsoAngles.y * 0.017453292);
      c = cos(v24);
      s = sin(v24);
      tag_origin_offset.x = (float)(1.0 - c) * 0.0;
      tag_origin_offset.y = (float)(s * 0.0) + y;
      if ( (float)(s * v12) > 0.0 )
        tag_origin_offset.y = (float)((float)(s * 0.0) + y) - (float)((float)((float)(1.0 - c) * v12) * 16.0);
      v25 = vTorsoAngles.y * 0.30000001;
      angles[0].y = (float)(vTorsoAngles.y * 0.30000001) - (float)(vTorsoAngles.z * 1.2);
      angles[0].z = vTorsoAngles.z * 0.30000001;
      fAimUpDown_low = (__m128)LODWORD(es->un2.animState.fAimUpDown);
      angles[0].x = 0.0;
      if ( fAimUpDown_low.m128_f32[0] != 0.0 || es->un2.animState.fAimLeftRight != 0.0 )
      {
        fAimUpDown_low.m128_f32[0] = (float)(fAimUpDown_low.m128_f32[0] - es->un2.animState.fAimLeftRight)
                                   * 0.0027777778;
        v27.m128_f32[0] = FLOAT_8388608_0;
        v28 = fAimUpDown_low;
        v28.m128_f32[0] = fAimUpDown_low.m128_f32[0] + 0.5;
        v29 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v28);
        v27.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v28, v29), v27).m128_u32[0] | v29.m128_i32[0];
        v30 = v28;
        v30.m128_f32[0] = (float)((float)(fAimUpDown_low.m128_f32[0] + 0.5) + v27.m128_f32[0]) - v27.m128_f32[0];
        v31 = v30;
        v31.m128_f32[0] = v30.m128_f32[0] - (float)(fAimUpDown_low.m128_f32[0] + 0.5);
        angles[0].x = (float)(fAimUpDown_low.m128_f32[0]
                            - (float)(v30.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v31, v29).m128_u32[0] & FLOAT_1_0)))
                    * 360.0;
      }
      angles[1].x = 0.0;
      angles[1].z = vTorsoAngles.z * 0.2;
      angles[2].x = vTorsoAngles.x;
      angles[1].y = v25 - (float)(vTorsoAngles.z * 0.2);
      angles[2].y = v25 - (float)(vTorsoAngles.z * -1.0);
      angles[2].z = vTorsoAngles.z * -0.2;
    }
    else
    {
      if ( v12 != 0.0 )
      {
        v32 = v12 > 0.0;
        if ( (v17 & 4) != 0 )
        {
          Dvar_GetVec2(player_lean_rotate_crouch, &lean_rotate_crouch);
          v33 = lean_rotate_crouch.v[v32];
        }
        else
        {
          Dvar_GetVec2(player_lean_rotate, &lean_rotate);
          v33 = lean_rotate.v[v32];
        }
        v13 = v54;
        vTorsoAngles.z = vTorsoAngles.z * v33;
        vHeadAngles.z = vHeadAngles.z * v33;
      }
      tag_origin_angles.z = (float)(v13 * 0.075000003) + tag_origin_angles.z;
      Dvar_GetVec3(player_AimBlend_Back_Low, &AimBlend_Back_Low);
      angles[0].y = AimBlend_Back_Low.y * vTorsoAngles.y;
      angles[0].z = AimBlend_Back_Low.z * vTorsoAngles.z;
      v34 = (__m128)LODWORD(es->un2.animState.fAimUpDown);
      angles[0].x = AimBlend_Back_Low.x * vTorsoAngles.x;
      if ( v34.m128_f32[0] != 0.0 || es->un2.animState.fAimLeftRight != 0.0 )
      {
        v34.m128_f32[0] = (float)(v34.m128_f32[0] - es->un2.animState.fAimLeftRight) * 0.0027777778;
        v35.m128_f32[0] = FLOAT_8388608_0;
        v36 = v34;
        v36.m128_f32[0] = v34.m128_f32[0] + 0.5;
        v37 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v36);
        v35.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v36, v37), v35).m128_u32[0] | v37.m128_i32[0];
        v38 = v36;
        v38.m128_f32[0] = (float)((float)(v34.m128_f32[0] + 0.5) + v35.m128_f32[0]) - v35.m128_f32[0];
        v39 = v38;
        v39.m128_f32[0] = v38.m128_f32[0] - (float)(v34.m128_f32[0] + 0.5);
        angles[0].x = (float)((float)(v34.m128_f32[0]
                                    - (float)(v38.m128_f32[0]
                                            - COERCE_FLOAT(_mm_cmpgt_ss(v39, v37).m128_u32[0] & FLOAT_1_0)))
                            * 360.0)
                    + (float)(AimBlend_Back_Low.x * vTorsoAngles.x);
      }
      Dvar_GetVec3(player_AimBlend_Back_Mid, &AimBlend_Back_Mid);
      angles[1].x = AimBlend_Back_Mid.x * vTorsoAngles.x;
      angles[1].y = AimBlend_Back_Mid.y * vTorsoAngles.y;
      angles[1].z = AimBlend_Back_Mid.z * vTorsoAngles.z;
      Dvar_GetVec3(player_AimBlend_Back_Up, &AimBlend_Back_Up);
      angles[2].x = AimBlend_Back_Up.x * vTorsoAngles.x;
      angles[2].y = AimBlend_Back_Up.y * vTorsoAngles.y;
      angles[2].z = AimBlend_Back_Up.z * vTorsoAngles.z;
      Dvar_GetVec3(player_AimBlend_Pelvis, &AimBlend_Pelvis);
      angles[5].x = AimBlend_Pelvis.x * vTorsoAngles.x;
      angles[5].y = AimBlend_Pelvis.y * vTorsoAngles.y;
      angles[5].z = AimBlend_Pelvis.z * vTorsoAngles.z;
    }
    Dvar_GetVec3(player_AimBlend_Neck, &AimBlend_Neck);
    angles[3].x = AimBlend_Neck.x * vHeadAngles.x;
    angles[3].y = AimBlend_Neck.y * vHeadAngles.y;
    angles[3].z = AimBlend_Neck.z * vHeadAngles.z;
    Dvar_GetVec3(player_AimBlend_Head, &AimBlend_Head);
    fAimLeftRight_low = (__m128)LODWORD(es->un2.animState.fAimLeftRight);
    z = AimBlend_Head.z * vHeadAngles.z;
    v42 = AimBlend_Head.x * vHeadAngles.x;
    v43 = AimBlend_Head.y * vHeadAngles.y;
    angles[4].z = AimBlend_Head.z * vHeadAngles.z;
    if ( fAimLeftRight_low.m128_f32[0] == 0.0 && es->un2.animState.fAimUpDown == 0.0 )
    {
      x = angles[5].x;
    }
    else
    {
      fAimLeftRight_low.m128_f32[0] = (float)(fAimLeftRight_low.m128_f32[0] - es->un2.animState.fAimUpDown)
                                    * 0.0027777778;
      v44.m128_f32[0] = FLOAT_8388608_0;
      v45 = fAimLeftRight_low;
      v45.m128_f32[0] = fAimLeftRight_low.m128_f32[0] + 0.5;
      v46 = _mm_and_ps((__m128)LODWORD(FLOAT_N0_0), v45);
      v44.m128_i32[0] = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(_mm_xor_ps(v45, v46), v44).m128_u32[0] | v46.m128_i32[0];
      v47 = v45;
      v47.m128_f32[0] = (float)((float)(fAimLeftRight_low.m128_f32[0] + 0.5) + v44.m128_f32[0]) - v44.m128_f32[0];
      v48 = v47;
      v48.m128_f32[0] = v47.m128_f32[0] - (float)(fAimLeftRight_low.m128_f32[0] + 0.5);
      z = angles[4].z;
      x = (float)(fAimLeftRight_low.m128_f32[0]
                - (float)(v47.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v48, v46).m128_u32[0] & FLOAT_1_0)))
        * 360.0;
    }
    v4->angles[0] = angles[0];
    v4->angles[1] = angles[1];
    v4->angles[2] = angles[2];
    v4->angles[3] = angles[3];
    v4->angles[4].x = v42;
    v4->angles[4].y = v43;
    v4->angles[4].z = z;
    v50 = angles[5].y;
    v4->angles[5].x = x;
    *(_QWORD *)&v4->angles[5].v[1] = __PAIR64__(LODWORD(angles[5].z), LODWORD(v50));
    v4->tag_origin_angles = tag_origin_angles;
    *(_QWORD *)&v4->tag_origin_offset.x = *(_QWORD *)&tag_origin_offset.x;
    v4->tag_origin_offset.z = 0.0;
  }
}

#endif // __UNIMPLEMENTED__
