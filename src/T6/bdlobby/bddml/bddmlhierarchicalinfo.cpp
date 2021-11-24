// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bddmlhierarchicalinfo.cpp:0x93A860
void __usercall BG_RunLerpFrameRate(
        clientInfo_t *ci@<ecx>,
        lerpFrame_t *lf@<esi>,
        LocalClientNum_t localClientNum,
        int newAnimation,
        const entityState_s *es,
        vec3_t origin,
        vec3_t angles)
{
  animation_s *animation; // eax
  animation_s *v9; // edi
  float forceAnimRate; // xmm0_4
  unsigned int v11; // edx
  int oldFrameSnapshotTime; // ecx
  int v13; // eax
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float animSpeedScale; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  unsigned int v21; // ecx
  int animationNumber; // eax
  XAnimTree_s *pAnimTree; // [esp+Ch] [ebp-38h]
  float moveSpeed; // [esp+10h] [ebp-34h]
  float v25; // [esp+14h] [ebp-30h]
  int isScriptEventAnim; // [esp+18h] [ebp-2Ch]
  int isLadderAnim; // [esp+20h] [ebp-24h]
  float rotSpeeda; // [esp+24h] [ebp-20h]
  float rotSpeed; // [esp+24h] [ebp-20h]

  BG_CheckThread();
  if ( !*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp", 4153, 0, "(bgs)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  animation = lf->animation;
  if ( !animation || (isLadderAnim = 1, (animation->flags & 2) == 0) )
    isLadderAnim = 0;
  if ( !animation || (isScriptEventAnim = 1, (animation->flags & 0x800) == 0) )
    isScriptEventAnim = 0;
  pAnimTree = ci->pXAnimTree;
  if ( newAnimation != lf->animationNumber )
  {
LABEL_13:
    BG_SetNewAnimation(lf, newAnimation, (int)ci, localClientNum, ci, es);
    goto LABEL_14;
  }
  if ( !animation )
  {
    if ( (newAnimation & 0xFFFFFBFF) == 0 )
      return;
    goto LABEL_13;
  }
LABEL_14:
  if ( (newAnimation & 0xFFFFFBFF) != 0 )
  {
    v9 = lf->animation;
    if ( v9 )
    {
      forceAnimRate = v9->forceAnimRate;
      if ( forceAnimRate > 0.0 )
      {
        v11 = _tls_index;
        lf->animSpeedScale = forceAnimRate;
        lf->oldFramePos = origin;
        lf->oldFrameYaw = angles.y;
        lf->oldFrameSnapshotTime = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v11)
                                                         + 14960)
                                             + 20);
        goto LABEL_53;
      }
      v25 = v9->rotSpeed;
      if ( v25 == 0.0 && v9->moveSpeed == 0.0 || (oldFrameSnapshotTime = lf->oldFrameSnapshotTime) == 0 )
      {
        v21 = _tls_index;
        LODWORD(lf->animSpeedScale) = FLOAT_1_0;
        lf->oldFrameSnapshotTime = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v21)
                                                         + 14960)
                                             + 20);
        lf->oldFramePos = origin;
        lf->oldFrameYaw = angles.y;
      }
      else
      {
        v13 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960) + 20);
        if ( v13 == oldFrameSnapshotTime )
          goto LABEL_53;
        if ( isLadderAnim )
          LODWORD(v14) = COERCE_UNSIGNED_INT(lf->oldFramePos.z - origin.z) & _mask__AbsFloat_;
        else
          v14 = fsqrt(
                  (float)((float)(origin.y - lf->oldFramePos.y) * (float)(origin.y - lf->oldFramePos.y))
                + (float)((float)(origin.x - lf->oldFramePos.x) * (float)(origin.x - lf->oldFramePos.x)));
        rotSpeeda = 1.0 / (float)((float)(v13 - oldFrameSnapshotTime) * 0.001);
        moveSpeed = rotSpeeda * v14;
        rotSpeed = fabs(AngleNormalize180(lf->oldFrameYaw - angles.y)) * rotSpeeda;
        if ( v9->moveSpeed == 0.0
          && v25 == 0.0
          && !Assert_MyHandler(
                "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
                4203,
                0,
                "((anim->moveSpeed || anim->rotSpeed))",
                (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v15 = v9->moveSpeed;
        if ( v15 == 0.0 )
        {
          v16 = rotSpeed / v9->rotSpeed;
          lf->animSpeedScale = v16;
          if ( v16 <= 1.0 )
          {
            if ( v16 < 0.40000001 )
              lf->animSpeedScale = FLOAT_0_40000001;
          }
          else
          {
            LODWORD(lf->animSpeedScale) = FLOAT_1_0;
          }
        }
        else
        {
          lf->animSpeedScale = moveSpeed / v15;
        }
        lf->oldFrameSnapshotTime = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                           + _tls_index)
                                                         + 14960)
                                             + 20);
        if ( isScriptEventAnim )
          LODWORD(lf->animSpeedScale) = FLOAT_1_0;
        lf->oldFramePos = origin;
        animSpeedScale = lf->animSpeedScale;
        lf->oldFrameYaw = es->lerp.apos.trBase.y;
        v18 = FLOAT_0_1;
        if ( animSpeedScale < 0.1 )
        {
          if ( animSpeedScale < 0.0099999998 && isLadderAnim )
          {
            lf->animSpeedScale = 0.0;
            goto LABEL_53;
          }
          goto LABEL_51;
        }
        if ( animSpeedScale > 2.0 )
        {
          if ( (v9->flags & 2) == 0 )
          {
            v19 = v9->moveSpeed;
            if ( v19 <= 150.0 )
            {
              if ( v19 >= 20.0 )
              {
                v20 = 3.0 - (float)((float)(v19 - 20.0) * 0.0076923077);
                if ( animSpeedScale > v20 )
                  lf->animSpeedScale = v20;
              }
              else if ( animSpeedScale > 3.0 )
              {
                lf->animSpeedScale = FLOAT_3_0;
              }
            }
            else
            {
              lf->animSpeedScale = FLOAT_2_0;
            }
            goto LABEL_53;
          }
          v18 = FLOAT_4_0;
          if ( animSpeedScale > 4.0 )
LABEL_51:
            lf->animSpeedScale = v18;
        }
      }
LABEL_53:
      animationNumber = lf->animationNumber;
      if ( animationNumber )
        XAnimSetAnimRate(pAnimTree, animationNumber & 0xFFFFFBFF, lf->animSpeedScale);
    }
  }
}

#endif // __UNIMPLEMENTED__
