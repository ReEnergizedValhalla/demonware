// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdtwittersearchresult.cpp:0x93C2D0
void __cdecl BG_UpdatePlayerDObj(
        LocalClientNum_t localClientNum,
        DObj *pDObj,
        entityState_s *es,
        clientInfo_t *ci,
        int attachIgnoreCollision)
{
  int eFlags; // eax
  int ownerNum; // esi
  unsigned __int8 vehicleSeat; // al
  XAnimTree_s *pXAnimTree; // esi
  const WeaponDef *WeaponDef; // eax
  int HasIKActiveFlag; // eax
  unsigned int v11; // esi
  Weapon v12; // ecx
  void (__cdecl *v13)(LocalClientNum_t, clientInfo_t *, Weapon); // eax
  int v14; // esi
  bool v15; // zf
  unsigned __int16 (__cdecl *v16)(DObjModel_s *, int, clientInfo_t *, int); // eax
  unsigned __int16 (__cdecl *v17)(DObjModel_s *, int, entityState_s *, DObj *, int, int *); // eax
  unsigned __int16 *p_boneName; // ebx
  int v19; // eax
  unsigned __int16 String; // ax
  bool v21; // dl
  WeaponDobjInfo *v22; // eax
  const WeaponDef *v23; // ecx
  LocalClientNum_t v24; // ebx
  clientInfo_t *v25; // esi
  unsigned int v26; // eax
  Weapon v27; // eax
  const WeaponDef *v28; // ebx
  int weaponData; // eax
  int v30; // ebx
  int v31; // esi
  int v32; // edx
  unsigned int *v33; // eax
  int i; // esi
  unsigned int v35; // eax
  unsigned int *v36; // eax
  Weapon v37; // esi
  const WeaponDef *v38; // ebx
  int j; // esi
  unsigned int v40; // eax
  const char ***worldModel; // ecx
  unsigned int *v42; // eax
  int v43; // eax
  const DObj *v44; // ebx
  int k; // esi
  unsigned int v46; // eax
  unsigned int *v47; // eax
  DObj *v48; // esi
  Weapon v49; // [esp-Ch] [ebp-518h]
  int freeCameraLockOnAllowed; // [esp-8h] [ebp-514h]
  Weapon weapon; // [esp+Ch] [ebp-500h]
  int lastWeaponModel; // [esp+10h] [ebp-4FCh]
  XAnimTree_s *pAnimTree; // [esp+14h] [ebp-4F8h]
  int ikActive; // [esp+1Ch] [ebp-4F0h]
  int iStowedWeaponModelIndex; // [esp+20h] [ebp-4ECh] BYREF
  clientInfo_t *v56; // [esp+24h] [ebp-4E8h]
  LocalClientNum_t v57; // [esp+28h] [ebp-4E4h]
  const WeaponDef *weapDef; // [esp+2Ch] [ebp-4E0h]
  const WeaponDef *weapDefStowed; // [esp+30h] [ebp-4DCh]
  int objExists; // [esp+34h] [ebp-4D8h]
  DObj *obj; // [esp+38h] [ebp-4D4h]
  int hideClip; // [esp+3Ch] [ebp-4D0h]
  Weapon ClientWeapon; // [esp+40h] [ebp-4CCh]
  unsigned __int8 boneIndex; // [esp+47h] [ebp-4C5h] BYREF
  DObjModel_s dobjModels[32]; // [esp+48h] [ebp-4C4h] BYREF
  unsigned __int16 hideTags[32]; // [esp+4C8h] [ebp-44h] BYREF

  v57 = localClientNum;
  obj = pDObj;
  v56 = ci;
  ikActive = 0;
  BG_CheckThread();
  if ( !*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp", 5351, 0, "(bgs)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  eFlags = es->lerp.eFlags;
  ownerNum = es->lerp.u.turret.ownerNum;
  objExists = obj != 0;
  if ( (eFlags & 0x300) != 0 && (es->lerp.eFlags2 & 0x10000000) == 0 )
    ownerNum = 0;
  if ( BG_WeaponNotUsedOnVehicle(eFlags) )
  {
    if ( (es->lerp.eFlags2 & 0x10000000) == 0 )
    {
      vehicleSeat = es->lerp.u.player.vehicleSeat;
      if ( vehicleSeat < 5u || vehicleSeat > 0xAu )
        ownerNum = 0;
    }
  }
  if ( es->eType == 2 )
    ownerNum = 0;
  ClientWeapon.weaponData = ownerNum;
  if ( Com_SessionMode_IsZombiesGame() && ownerNum != es->weapon.weaponData )
    ClientWeapon.0 = ($190F2CF944EC18EE3AF27F473C4F9DBE)es->weapon;
  BG_WeaponNotUsedOnVehicle(es->lerp.eFlags);
  pXAnimTree = ci->pXAnimTree;
  freeCameraLockOnAllowed = es->lerp.u.actor.freeCameraLockOnAllowed;
  pAnimTree = pXAnimTree;
  iStowedWeaponModelIndex = 0;
  WeaponDef = BG_GetWeaponDef((const Weapon)freeCameraLockOnAllowed);
  v49.0 = ($190F2CF944EC18EE3AF27F473C4F9DBE)es->weapon;
  weapDefStowed = WeaponDef;
  weapon.0 = v49.0;
  weapDef = BG_GetWeaponDef(v49);
  if ( pXAnimTree && (!ci->infoValid || !ci->model[0]) )
  {
    XAnimClearTree(pXAnimTree);
    (*(void (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                             + _tls_index)
                                                           + 14960)
                                               + 124))(
      es->number,
      v57);
    return;
  }
  if ( objExists )
  {
    if ( ci->DObjWeapon.weaponData == ClientWeapon.weaponData
      && ci->weaponModel == es->weaponModel
      && ci->DObjMeleeWeapon.weaponData == es->lerp.u.player.meleeWeapon.weaponData
      && ci->meleeWeaponModel == es->lerp.u.player.meleeWeaponModel
      && !ci->dobjDirty )
    {
      if ( pXAnimTree != DObjGetTree(obj)
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
              5393,
              0,
              "(pAnimTree == DObjGetTree( pDObj ))",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      return;
    }
    HasIKActiveFlag = DObjHasIKActiveFlag(obj);
    v11 = _tls_index;
    ikActive = HasIKActiveFlag;
    (*(void (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                             + _tls_index)
                                                           + 14960)
                                               + 124))(
      es->number,
      v57);
  }
  else
  {
    v11 = _tls_index;
  }
  v12.0 = ClientWeapon.0;
  if ( ci->DObjWeapon.weaponData != ClientWeapon.weaponData && (ci->showReloadClipInHand || ci->hideWeaponClipModel) )
  {
    ci->showReloadClipInHand = 0;
    ci->hideWeaponClipModel = 0;
    ci->dropWeaponClipTime = 0;
  }
  v13 = *(void (__cdecl **)(LocalClientNum_t, clientInfo_t *, Weapon))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                                   + v11)
                                                                                 + 14960)
                                                                     + 77736);
  if ( v13 )
    ((void (__cdecl *)(_DWORD, _DWORD, _DWORD))v13)(v57, ci, (Weapon)v12.weaponData);
  ci->DObjMeleeWeapon.weaponData = es->lerp.u.player.meleeWeapon.weaponData;
  ci->meleeWeaponModel = es->lerp.u.player.meleeWeaponModel;
  ci->DObjOffhandWeapon.weaponData = es->lerp.u.primaryLight.mixerIndex;
  memset((unsigned __int8 *)dobjModels, 0, sizeof(dobjModels));
  dobjModels[0].model = (XModel *)(*(int (__cdecl **)(char *))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                           + v11)
                                                                         + 14960)
                                                             + 104))(ci->model);
  if ( !dobjModels[0].model
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          5429,
          0,
          "(dobjModels[iNumModels].model)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  ci->weaponDobjInfo.numModelMasks = 0;
  ci->weaponDobjInfo.addingSlot = HELD;
  ci->weaponDobjInfo.lastAddedModel = -1;
  dobjModels[0].boneName = 0;
  dobjModels[0].ignoreCollision = 0;
  v14 = 1;
  ci->DObjWeapon = ClientWeapon;
  obj = (DObj *)&ci->weaponDobjInfo;
  ci->weaponModel = es->weaponModel;
  if ( (es->lerp.eFlags2 & 0x400) == 0
    || (v15 = weapDef->weapClass == WEAPCLASS_ROCKETLAUNCHER, LOBYTE(hideClip) = 1, !v15) )
  {
    LOBYTE(hideClip) = 0;
  }
  v16 = *(unsigned __int16 (__cdecl **)(DObjModel_s *, int, clientInfo_t *, int))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                                              + _tls_index)
                                                                                            + 14960)
                                                                                + 112);
  if ( v16 )
    v14 = v16(dobjModels, 1, ci, hideClip);
  v17 = *(unsigned __int16 (__cdecl **)(DObjModel_s *, int, entityState_s *, DObj *, int, int *))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
                                                                                                + 116);
  lastWeaponModel = v14;
  if ( v17 )
    v14 = v17(dobjModels, v14, es, obj, es->lerp.u.actor.freeCameraLockOnAllowed, &iStowedWeaponModelIndex);
  ClientWeapon.weaponData = (unsigned int)ci->attachModelNames;
  objExists = 0;
  hideClip = 1;
  p_boneName = &dobjModels[v14].boneName;
  do
  {
    if ( !*(_BYTE *)ClientWeapon.weaponData )
      break;
    if ( v14 >= 32
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
            5458,
            0,
            "(iNumModels < 32)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v19 = (*(int (__cdecl **)(Weapon))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index)
                                                 + 14960)
                                     + 104))(ClientWeapon);
    *((_DWORD *)p_boneName - 1) = v19;
    if ( !v19
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
            5460,
            0,
            "(dobjModels[iNumModels].model)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    String = SL_FindString((const char *)(ClientWeapon.weaponData + 384));
    v15 = (attachIgnoreCollision & hideClip) == 0;
    *p_boneName = String;
    v21 = !v15;
    v15 = weapDef == 0;
    *((_BYTE *)p_boneName + 4) = v21;
    if ( v15 || weapDef->weapType != WEAPTYPE_RIOTSHIELD )
    {
      if ( weapDefStowed && weapDefStowed->weapType == WEAPTYPE_RIOTSHIELD )
      {
        v22 = (WeaponDobjInfo *)obj;
        v23 = weapDefStowed;
        *(_DWORD *)&obj->duplicateParts = 1;
        WeaponDobjInfo::Add(v22, v23, 1 << v14);
        *(_DWORD *)&obj->duplicateParts = 0;
      }
    }
    else
    {
      WeaponDobjInfo::Add((WeaponDobjInfo *)obj, weapDef, 1 << v14);
    }
    ClientWeapon.weaponData += 64;
    ++v14;
    p_boneName += 18;
    ++objExists;
    hideClip = __ROL4__(hideClip, 1);
  }
  while ( objExists < 6 );
  if ( pAnimTree )
  {
    v24 = v57;
    (*(void (__cdecl **)(DObjModel_s *, int, XAnimTree_s *, int, LocalClientNum_t, clientInfo_t *))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 14960)
                                                                                                  + 108))(
      dobjModels,
      v14,
      pAnimTree,
      es->number,
      v57,
      v56);
    v25 = v56;
    v26 = _tls_index;
    v56->dobjDirty = 0;
    v27.weaponData = (*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                             + v26)
                                                                           + 14960)
                                                               + 120))(
                       es->number,
                       v24);
    v28 = weapDef;
    ClientWeapon.0 = v27.0;
    *(_QWORD *)es->partBits = 0i64;
    *(_QWORD *)&es->partBits[2] = 0i64;
    es->partBits[4] = 0;
    v15 = v28->inventoryType == WEAPINVENTORY_ALTMODE;
    weapDefStowed = (const WeaponDef *)es->partBits;
    if ( v15 )
      weaponData = es->lerp.u.turret.ownerNum;
    else
      weaponData = weapon.weaponData;
    if ( v25->hideWeapon )
    {
      if ( lastWeaponModel > 1 )
      {
        hideClip = (int)&dobjModels[1];
        objExists = lastWeaponModel - 1;
        do
        {
          v30 = *(_DWORD *)hideClip;
          v31 = 0;
          if ( *(_BYTE *)(*(_DWORD *)hideClip + 4) )
          {
            do
            {
              v32 = *(_DWORD *)(v30 + 8);
              boneIndex = -2;
              if ( DObjGetBoneIndex(
                     (const DObj *)ClientWeapon.weaponData,
                     *(unsigned __int16 *)(v32 + 2 * v31),
                     &boneIndex,
                     -1) )
              {
                v33 = &es->partBits[boneIndex >> 5];
                *v33 |= 0x80000000 >> (boneIndex & 0x1F);
              }
              ++v31;
            }
            while ( v31 < *(unsigned __int8 *)(v30 + 4) );
          }
          hideClip += 36;
          --objExists;
        }
        while ( objExists );
        v25 = v56;
      }
      Com_Memcpy(v25->weaponHideBits, weapDefStowed, 20);
    }
    else
    {
      BG_GetHideTags((const Weapon)weaponData, hideTags);
      for ( i = 0; i < 32; ++i )
      {
        v35 = hideTags[i];
        if ( !(_WORD)v35 )
          break;
        boneIndex = -2;
        if ( DObjGetBoneIndex((const DObj *)ClientWeapon.weaponData, v35, &boneIndex, -1) )
        {
          v36 = &es->partBits[boneIndex >> 5];
          *v36 |= 0x80000000 >> (boneIndex & 0x1F);
        }
      }
      if ( v28->bDualWield && !v56->usingKnife )
      {
        v37.weaponData = LOBYTE(v28->dualWieldWeaponIndex);
        v38 = BG_GetWeaponDef(v37);
        BG_GetHideTags(v37, hideTags);
        for ( j = 0; j < 32; ++j )
        {
          v40 = hideTags[j];
          if ( !(_WORD)v40 )
            break;
          worldModel = (const char ***)v38->worldModel;
          boneIndex = -2;
          if ( DObjGetModelBoneIndex((const DObj *)ClientWeapon.weaponData, **worldModel, v40, &boneIndex) )
          {
            v42 = &es->partBits[boneIndex >> 5];
            *v42 |= 0x80000000 >> (boneIndex & 0x1F);
          }
        }
      }
    }
    v43 = es->lerp.u.actor.freeCameraLockOnAllowed;
    if ( v43 && (_BYTE)v43 )
    {
      BG_GetHideTags(es->lerp.u.player.stowedWeapon, hideTags);
      v44 = (const DObj *)ClientWeapon.weaponData;
      for ( k = 0; k < 32; ++k )
      {
        v46 = hideTags[k];
        if ( !(_WORD)v46 )
          break;
        boneIndex = -2;
        if ( DObjGetModelBoneIndex(v44, (unsigned __int16)iStowedWeaponModelIndex, v46, &boneIndex) )
        {
          v47 = &es->partBits[boneIndex >> 5];
          *v47 |= 0x80000000 >> (boneIndex & 0x1F);
        }
      }
    }
    v48 = (DObj *)ClientWeapon.weaponData;
    DObjSetHidePartBits((DObj *)ClientWeapon.weaponData, (const unsigned int *)weapDefStowed);
    if ( Dvar_GetBool(bg_enableIKActiveFix) )
      DObjSetIKActiveFlag(v48, ikActive);
  }
}

#endif // __UNIMPLEMENTED__
