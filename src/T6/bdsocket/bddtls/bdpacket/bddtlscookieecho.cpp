// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bddtlscookieecho.cpp:0x958370
void __usercall PM_MeleeChargeCatchupVelocity(pmove_t *pm@<edi>, pml_t *pml)
{
  playerState_s *ps; // esi
  int meleeChargeEnt; // ecx
  int weaponstate; // eax
  int weaponstateLeft; // eax
  __m128i v6; // xmm0
  float x; // xmm3_4
  float y; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm5_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float timeUntilTrace; // [esp+0h] [ebp-30h]
  float meleeMaxSpeed; // [esp+4h] [ebp-2Ch]
  float meleeRange; // [esp+8h] [ebp-28h]
  float meleeChargeFriction; // [esp+Ch] [ebp-24h] BYREF
  float v23; // [esp+10h] [ebp-20h]
  vec3_t targetOrigin; // [esp+14h] [ebp-1Ch] BYREF
  vec3_t targetVelocity; // [esp+20h] [ebp-10h] BYREF

  if ( Dvar_GetBool(player_meleeCalcSpeedFromTarget) )
  {
    if ( !pm
      && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6501, 0, "(pm)", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    ps = pm->ps;
    if ( !pm->ps
      && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6504, 0, "(ps)", (const char *)&pBlock) )
    {
      __debugbreak();
    }
    meleeRange = Dvar_GetFloat(player_meleeRange);
    meleeMaxSpeed = Dvar_GetFloat(player_meleeChargeMaxSpeed);
    meleeChargeFriction = Dvar_GetFloat(player_meleeChargeFriction);
    if ( PM_IsValidCharge(pm) )
    {
      meleeChargeEnt = ps->meleeChargeEnt;
      if ( meleeChargeEnt != 1023 )
      {
        weaponstate = ps->weaponstate;
        if ( weaponstate == 19 || weaponstate == 20 || weaponstate == 21 )
        {
          v6 = _mm_cvtsi32_si128(ps->weaponDelay);
        }
        else
        {
          weaponstateLeft = ps->weaponstateLeft;
          if ( weaponstateLeft != 19 && weaponstateLeft != 20 && weaponstateLeft != 21 )
            return;
          v6 = _mm_cvtsi32_si128(ps->weaponDelayLeft);
        }
        timeUntilTrace = _mm_cvtepi32_ps(v6).m128_f32[0] * 0.001;
        if ( timeUntilTrace > 0.0 )
        {
          if ( PM_GetEntityOrigin(pm->handler, pm->localClientNum, meleeChargeEnt, &targetOrigin) )
          {
            if ( PM_GetEntityVelocity(pm->handler, pm->localClientNum, ps->meleeChargeEnt, &targetVelocity) )
            {
              x = ps->origin.x;
              y = ps->origin.y;
              v9 = targetOrigin.x - x;
              v10 = targetOrigin.y - y;
              v11 = (float)((float)(v10 * v10) + (float)(v9 * v9))
                  + (float)((float)(targetOrigin.z - ps->origin.z) * (float)(targetOrigin.z - ps->origin.z));
              if ( v11 > (float)(meleeRange * meleeRange) )
              {
                v12 = fsqrt(v11);
                v13 = (float)(v12 - meleeRange) / v12;
                v14 = COERCE_FLOAT(LODWORD(x) ^ _mask__NegFloat_) + (float)((float)(v9 * v13) + x);
                v15 = COERCE_FLOAT(LODWORD(y) ^ _mask__NegFloat_) + (float)((float)(v10 * v13) + y);
                v16 = (float)(pml->frametime * meleeChargeFriction) + 1.0;
                v17 = (float)((float)((float)(targetVelocity.y * timeUntilTrace) + v15) * (float)(1.0 / timeUntilTrace))
                    * v16;
                v18 = (float)((float)((float)(targetVelocity.x * timeUntilTrace) + v14) * (float)(1.0 / timeUntilTrace))
                    * v16;
                meleeChargeFriction = v18;
                v23 = v17;
                if ( (float)((float)(v17 * v17) + (float)(v18 * v18)) > (float)(meleeMaxSpeed * meleeMaxSpeed) )
                {
                  Vec2NormalizeFast((vec2_t *)&meleeChargeFriction);
                  v18 = meleeChargeFriction * meleeMaxSpeed;
                  v17 = v23 * meleeMaxSpeed;
                }
                ps->velocity.x = v18;
                ps->velocity.y = v17;
              }
            }
          }
        }
      }
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddtlscookieecho.cpp:0x958630
void __cdecl PM_MeleeChargeUpdate(pml_t *pml)
{
  pmove_t *pm; // ecx
  pmove_t *v2; // edi
  playerState_s *ps; // esi
  double Float; // st7
  float v5; // xmm0_4
  bool v6; // zf
  float meleeChargeFriction; // [esp+20h] [ebp-4D8h]
  vec2_t chargeDir; // [esp+24h] [ebp-4D4h] BYREF
  actors_rewind_context_t actors_rewind_context; // [esp+2Ch] [ebp-4CCh] BYREF
  AntilagClientStore antilagClients; // [esp+330h] [ebp-1C8h] BYREF

  v2 = pm;
  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6573, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !pml
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6574, 0, "(pml)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ps = v2->ps;
  if ( !v2->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 6577, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( PM_IsValidCharge(v2) )
  {
    if ( v2->handler == 1 )
      G_AntiLagRewindClientIndexPos(ps->clientNum, &antilagClients);
    actors_rewind_context.m_active = 0;
    if ( v2->handler == 1 )
      actors_rewind_context_t::rewind(
        &actors_rewind_context,
        level.time,
        level.clients[ps->clientNum].lastServerTime,
        1023);
    if ( !ps->meleeChargeTime )
    {
      Float = Dvar_GetFloat(player_meleeChargeFriction);
      meleeChargeFriction = Float;
      if ( Float <= 0.0
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp",
              6604,
              0,
              "(meleeChargeFriction > 0.0f)",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      PM_GetMeleeChargeYaw(v2);
      YawVectors2D(0.0, &chargeDir, 0);
      v5 = fsqrt((float)((float)ps->meleeChargeDist * 2.0) * meleeChargeFriction);
      ps->velocity.x = chargeDir.v[0] * v5;
      ps->velocity.y = chargeDir.v[1] * v5;
      ps->meleeChargeTime = (int)(float)((float)(v5 / meleeChargeFriction) * 1000.0);
    }
    PM_MeleeChargeCatchupVelocity(v2, pml);
    v6 = v2->handler == 1;
    if ( v2->handler == 1 )
    {
      actors_rewind_context_t::restore(&actors_rewind_context);
      v6 = v2->handler == 1;
    }
    if ( v6 )
      G_AntiLag_RestoreClientPos(&antilagClients);
    ps->meleeChargeTime -= pml->msec;
    if ( ps->meleeChargeTime <= 0 )
      PM_MeleeChargeClear(ps);
    actors_rewind_context_t::restore(&actors_rewind_context);
  }
  else
  {
    PM_MeleeChargeClear(ps);
  }
}

#endif // __UNIMPLEMENTED__
