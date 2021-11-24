// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x94E3F0
double __cdecl BG_GetFallDamageMaxHeight()
{
  return Dvar_GetFloat(bg_fallDamageMaxHeight);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x94E400
double __cdecl BG_GetFallDamageMinHeight()
{
  return Dvar_GetFloat(bg_fallDamageMinHeight);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x94E410
double __cdecl BG_GetSprintSpeedScale()
{
  return Dvar_GetFloat(player_sprintSpeedScale);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x94E420
bool __cdecl BG_GetSprintUnlimited()
{
  return Dvar_GetBool(player_sprintUnlimited);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x94E430
double __cdecl BG_GetSprintMinTime()
{
  return Dvar_GetFloat(player_sprintMinTime);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x94E440
double __cdecl BG_GetSprintStrafeSpeedScale()
{
  return Dvar_GetFloat(player_sprintStrafeSpeedScale);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x94E450
double __cdecl BG_GetFriction()
{
  return Dvar_GetFloat(friction);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x94E460
char *__cdecl BG_GetEntityTypeName(const int eType)
{
  int v2; // esi

  if ( eType < 21 )
    return g_entityTypeNames[eType];
  v2 = eType - 21;
  if ( (eType - 21 < 0 || v2 >= 240)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          1557,
          0,
          "((eType - ET_EVENTS >= 0 && eType - ET_EVENTS < EV_MAX_EVENTS))",
          "(eType) = %i",
          eType) )
  {
    __debugbreak();
  }
  return va("Event %s (%i)", eventnames[v2], v2);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x94E840
BOOL __cdecl BG_PlayerHasRoomForEntAllAmmoTypes(const entityState_s *ent, const playerState_s *ps)
{
  Weapon v2; // eax
  BOOL result; // eax
  Weapon v4; // eax

  if ( !ent
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 1746, 0, "(ent)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp", 1747, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v2.0 = ($190F2CF944EC18EE3AF27F473C4F9DBE)ps->weapon;
  result = 0;
  if ( v2.weaponData )
  {
    if ( v2.0 )
    {
      if ( BG_GetMaxPickupableAmmo(ps, ent->weapon) )
      {
        BG_GetWeaponVariantDef(ent->weapon);
        v4.0 = BG_GetAltWeapon(ent->weapon).0;
        if ( !v4.weaponData || !*(_BYTE *)&v4.0 || BG_GetMaxPickupableAmmo(ps, v4) )
          return 1;
      }
    }
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x94EF70
void __usercall BG_EvaluateTrajectoryDelta(float a1@<edi>, const trajectory_t *tr, int atTime, vec3_t *result)
{
  float v5; // xmm0_4
  float v6; // xmm0_4
  vec3_t *v7; // edi
  double Float; // st7
  int trTime; // ecx
  int v10; // ecx
  float deltaTime; // [esp+Ch] [ebp+8h]

  if ( ((LODWORD(tr->trBase.x) & 0x7F800000) == 2139095040
     || (LODWORD(tr->trBase.y) & 0x7F800000) == 2139095040
     || (LODWORD(tr->trBase.z) & 0x7F800000) == 2139095040)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          1895,
          0,
          "(!IS_NAN((tr->trBase)[0]) && !IS_NAN((tr->trBase)[1]) && !IS_NAN((tr->trBase)[2]))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( ((LODWORD(tr->trDelta.x) & 0x7F800000) == 2139095040
     || (LODWORD(tr->trDelta.y) & 0x7F800000) == 2139095040
     || (LODWORD(tr->trDelta.z) & 0x7F800000) == 2139095040)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          1896,
          0,
          "(!IS_NAN((tr->trDelta)[0]) && !IS_NAN((tr->trDelta)[1]) && !IS_NAN((tr->trDelta)[2]))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  switch ( tr->trType )
  {
    case 0u:
    case 1u:
      *(_QWORD *)&result->x = 0i64;
      result->z = 0.0;
      goto LABEL_29;
    case 3u:
      *result = tr->trDelta;
      goto LABEL_29;
    case 4u:
      if ( atTime > tr->trTime + tr->trDuration )
      {
        *(_QWORD *)&result->x = 0i64;
        result->z = 0.0;
        return;
      }
      *result = tr->trDelta;
      goto LABEL_29;
    case 5u:
      v5 = (float)((float)((float)(atTime - tr->trTime) / (float)tr->trDuration) * 3.1415927) * 2.0;
      __libm_sse2_cosf(a1);
      v6 = v5 * 0.5;
      goto LABEL_15;
    case 6u:
      v7 = result;
      deltaTime = (double)(atTime - tr->trTime) * 0.001;
      *result = tr->trDelta;
      Float = Dvar_GetFloat(bg_gravity);
      goto LABEL_20;
    case 7u:
      v7 = result;
      deltaTime = (double)(atTime - tr->trTime) * 0.001;
      *result = tr->trDelta;
      Float = Dvar_GetFloat(bg_lowGravity);
      goto LABEL_20;
    case 8u:
      trTime = tr->trTime;
      if ( atTime > trTime + tr->trDuration )
        goto LABEL_24;
      v6 = (float)((float)(atTime - trTime) * 0.001) * (float)((float)(atTime - trTime) * 0.001);
      goto LABEL_15;
    case 9u:
      v10 = tr->trTime;
      if ( atTime > v10 + tr->trDuration )
      {
LABEL_24:
        *(_QWORD *)&result->x = 0i64;
        result->z = 0.0;
      }
      else
      {
        v6 = (float)(atTime - v10) * 0.001;
LABEL_15:
        result->x = v6 * tr->trDelta.x;
        result->y = tr->trDelta.y * v6;
        result->z = tr->trDelta.z * v6;
LABEL_29:
        if ( ((LODWORD(tr->trBase.x) & 0x7F800000) == 2139095040
           || (LODWORD(tr->trBase.y) & 0x7F800000) == 2139095040
           || (LODWORD(tr->trBase.z) & 0x7F800000) == 2139095040)
          && !Assert_MyHandler(
                "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
                1961,
                0,
                "(!IS_NAN((tr->trBase)[0]) && !IS_NAN((tr->trBase)[1]) && !IS_NAN((tr->trBase)[2]))",
                (const char *)&pBlock) )
        {
          __debugbreak();
        }
        if ( ((LODWORD(tr->trDelta.x) & 0x7F800000) == 2139095040
           || (LODWORD(tr->trDelta.y) & 0x7F800000) == 2139095040
           || (LODWORD(tr->trDelta.z) & 0x7F800000) == 2139095040)
          && !Assert_MyHandler(
                "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
                1962,
                0,
                "(!IS_NAN((tr->trDelta)[0]) && !IS_NAN((tr->trDelta)[1]) && !IS_NAN((tr->trDelta)[2]))",
                (const char *)&pBlock) )
        {
          __debugbreak();
        }
      }
      return;
    case 0xFu:
      v7 = result;
      deltaTime = (double)(atTime - tr->trTime) * 0.001;
      *result = tr->trDelta;
      Float = Dvar_GetFloat(bg_moonGravity);
LABEL_20:
      v7->z = v7->z - Float * deltaTime;
      goto LABEL_29;
    default:
      Com_Error(ERR_DROP, &byte_CEB700, tr->trType);
      goto LABEL_29;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x94F680
void __usercall BG_PlayerToEntitySetTrajectory(playerState_s *ps@<edi>, entityState_s *s@<esi>, int snap)
{
  int movementDir; // eax
  float x; // xmm1_4
  float v5; // xmm2_4
  float y; // xmm1_4
  float v7; // xmm2_4
  float z; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm0_4

  s->lerp.pos.trDuration = 0;
  s->lerp.pos.trTime = 0;
  s->lerp.pos.trType = 1;
  *(_QWORD *)&s->lerp.pos.trDelta.x = 0i64;
  s->lerp.pos.trDelta.z = 0.0;
  s->lerp.pos.trBase = ps->origin;
  s->lerp.apos.trType = 1;
  s->lerp.apos.trDuration = 0;
  s->lerp.apos.trTime = 0;
  *(_QWORD *)&s->lerp.apos.trDelta.x = 0i64;
  s->lerp.apos.trDelta.z = 0.0;
  if ( (ps->eFlags & 0x300) == 0 && ps->vehicleState.entity == 1023 )
    s->lerp.apos.trBase = ps->viewangles;
  movementDir = ps->movementDir;
  if ( (movementDir >= 128 || movementDir < -128)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          2420,
          0,
          "((ps->movementDir < 128 && ps->movementDir >= -128))",
          "(ps->movementDir) = %i",
          ps->movementDir) )
  {
    __debugbreak();
  }
  s->lerp.u.loopFx.period = SLOWORD(ps->movementDir);
  if ( snap )
  {
    x = s->lerp.pos.trBase.x;
    if ( x >= 0.0 )
      v5 = FLOAT_0_5;
    else
      v5 = FLOAT_N0_5;
    s->lerp.pos.trBase.x = (float)(int)(float)(x + v5);
    y = s->lerp.pos.trBase.y;
    if ( y >= 0.0 )
      v7 = FLOAT_0_5;
    else
      v7 = FLOAT_N0_5;
    s->lerp.pos.trBase.y = (float)(int)(float)(y + v7);
    z = s->lerp.pos.trBase.z;
    if ( z >= 0.0 )
      v9 = FLOAT_0_5;
    else
      v9 = FLOAT_N0_5;
    s->lerp.pos.trBase.z = (float)(int)(float)(z + v9);
    v10 = s->lerp.apos.trBase.x;
    if ( v10 >= 0.0 )
      v11 = FLOAT_0_5;
    else
      v11 = FLOAT_N0_5;
    s->lerp.apos.trBase.x = (float)(int)(float)(v10 + v11);
    v12 = s->lerp.apos.trBase.y;
    if ( v12 >= 0.0 )
      v13 = FLOAT_0_5;
    else
      v13 = FLOAT_N0_5;
    s->lerp.apos.trBase.y = (float)(int)(float)(v12 + v13);
    v14 = s->lerp.apos.trBase.z;
    if ( v14 >= 0.0 )
      v15 = FLOAT_0_5;
    else
      v15 = FLOAT_N0_5;
    s->lerp.apos.trBase.z = (float)(int)(float)(v14 + v15);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x94F9D0
void __cdecl BG_LerpFontScale(const hudelem_s *elem, int time, float *toScale)
{
  __int16 fontScaleTime; // cx
  int v4; // eax
  float v5; // xmm0_4

  fontScaleTime = elem->fontScaleTime;
  v4 = time - elem->fontScaleStartTime;
  if ( fontScaleTime <= 0 || v4 >= fontScaleTime )
  {
    *toScale = elem->fontScale;
  }
  else
  {
    if ( v4 < 0 )
      v4 = 0;
    v5 = (float)v4 / (float)fontScaleTime;
    if ( (v5 < 0.0 || v5 > 1.0)
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            2945,
            0,
            "((lerp >= 0.0f && lerp <= 1.0f))",
            "(lerp) = %g",
            v5) )
    {
      __debugbreak();
    }
    *toScale = (float)((float)(elem->fontScale - elem->fromFontScale) * v5) + elem->fromFontScale;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x94FA90
void __cdecl BG_LerpHudColors(const hudelem_s *elem, int time, hudelem_color_t *toColor)
{
  __int16 fadeTime; // cx
  int v4; // eax
  float v5; // xmm0_4

  fadeTime = elem->fadeTime;
  v4 = time - elem->fadeStartTime;
  if ( fadeTime <= 0 || v4 >= fadeTime )
  {
    *toColor = elem->color;
  }
  else
  {
    if ( v4 < 0 )
      v4 = 0;
    v5 = (float)v4 / (float)fadeTime;
    if ( (v5 < 0.0 || v5 > 1.0)
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
            2969,
            0,
            "((lerp >= 0.0f && lerp <= 1.0f))",
            "(lerp) = %g",
            v5) )
    {
      __debugbreak();
    }
    toColor->r = (int)(float)((float)((float)(elem->color.r - elem->fromColor.r) * v5) + (float)elem->fromColor.r);
    toColor->g = (int)(float)((float)((float)(elem->color.g - elem->fromColor.g) * v5) + (float)elem->fromColor.g);
    toColor->b = (int)(float)((float)((float)(elem->color.b - elem->fromColor.b) * v5) + (float)elem->fromColor.b);
    toColor->a = (int)(float)((float)((float)(elem->color.a - elem->fromColor.a) * v5) + (float)elem->fromColor.a);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x950280
int __cdecl BG_SaveShellShockDvars(const char *name)
{
  const char *v2; // eax
  const char *bg_shock_dvar_names[32]; // [esp+8h] [ebp-84h] BYREF
  int fh; // [esp+88h] [ebp-4h] BYREF

  qmemcpy(bg_shock_dvar_names, bgShockDvarNames, sizeof(bg_shock_dvar_names));
  if ( !Com_SaveDvarsToBuffer(bg_shock_dvar_names, 0x20u, filebuf, 0x10000u) )
    return 0;
  v2 = va("shock/%s.shock", name);
  if ( FS_FOpenFileByMode(v2, &fh, FS_WRITE) < 0 )
    return 0;
  FS_Write(filebuf, strlen(filebuf), fh);
  FS_FCloseFile(fh);
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x950320
shellshock_parms_t *__cdecl BG_GetShellshockParms(const int index)
{
  if ( (index < 0 || index >= 16)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          3106,
          0,
          "((index >= 0 && index < 16))",
          "(index) = %i",
          index) )
  {
    __debugbreak();
  }
  return &bg_shellshockParms[index];
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x950370
BOOL __cdecl BG_IsShellshockAnim(const playerState_s *ps)
{
  int shellshockIndex; // esi

  if ( (ps->pm_flags & 0x10000) == 0 )
    return 0;
  shellshockIndex = ps->shellshockIndex;
  if ( (shellshockIndex < 0 || shellshockIndex >= 16)
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          3106,
          0,
          "((index >= 0 && index < 16))",
          "(index) = %i",
          ps->shellshockIndex) )
  {
    __debugbreak();
  }
  return bg_shellshockParms[shellshockIndex].animation.affect;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x9503D0
void __cdecl BG_CreateXAnim(XAnim_s *anims, unsigned int animIndex, const char *name)
{
  if ( !Dvar_GetBool(useFastFile) )
    XAnimPrecache(name, (void *(__cdecl *)(int))Hunk_AllocXAnimPrecache);
  XAnimCreate(anims, animIndex, name);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdqosprobe.cpp:0x950410
void __cdecl BG_CheckThread()
{
  if ( !Sys_IsServerThread()
    && !Sys_IsMainThread()
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_misc.cpp",
          3133,
          0,
          "(Sys_IsServerThread() || Sys_IsMainThread())",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
}

#endif // __UNIMPLEMENTED__
