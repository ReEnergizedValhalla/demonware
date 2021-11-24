// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdlinkedlist.inl:0x9359A0
void __cdecl BG_Dog_Stop_AttackIdle_Growl(
        LocalClientNum_t localClientNum,
        const entityState_s *es,
        ActorAnimStates prevState)
{
  unsigned int v3; // edi
  DObj *v4; // esi
  XAnimTree_s *Tree; // eax
  XAnimTree_s *v6; // eax

  v3 = _tls_index;
  v4 = (DObj *)(*(int (__cdecl **)(int, LocalClientNum_t))(*(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                       + _tls_index)
                                                                     + 14960)
                                                         + 120))(
                 es->number,
                 localClientNum);
  if ( v4 )
  {
    if ( prevState < ACTOR_ANIMATION_STOP_IDLE || prevState > ACTOR_ANIMATION_STOP_ATTACKIDLE_GROWL )
      BG_Dog_Stop_Init(es, localClientNum);
    Tree = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(Tree, 1u, 0.2, -1);
    v6 = DObjGetTree(v4);
    XAnimClearTreeGoalWeights(v6, 0x28u, 0.1, -1);
    XAnimSetCompleteGoalWeight(
      v4,
      0x36u,
      1.0,
      0.2,
      s_animRate,
      *(_DWORD *)(**(_DWORD **)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + v3) + 14960) + 602012),
      2u,
      1,
      -1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlinkedlist.inl:0x9C8F10
int __cdecl pitch_search_3tap(
        float *target,
        float *sw,
        float *ak,
        float *awk1,
        float *awk2,
        float *exc,
        const void *par,
        int start,
        int end,
        float pitch_coef,
        int p,
        int nsf,
        SpeexBits *bits,
        char *stack,
        float *exc2,
        float *r,
        int complexity,
        int cdbk_offset,
        int plc_tuning)
{
  double v19; // st7
  int v20; // ebx
  int v22; // edi
  char *v23; // ebx
  char *v24; // ebx
  float *v25; // edi
  int v26; // edx
  int v27; // edx
  float *v28; // eax
  unsigned int v29; // edx
  float *v30; // ecx
  float *v31; // eax
  int v32; // edi
  int v33; // ecx
  double v34; // st7
  int v35; // ebx
  float *v36; // eax
  float *v37; // ecx
  int v38; // edi
  unsigned int v39; // edx
  int v40; // ecx
  float *v41; // eax
  int v42; // esi
  double v43; // st7
  int v44; // eax
  float *v45; // ecx
  float *v46; // eax
  unsigned int v47; // edx
  char *v48; // edi
  int v49; // ecx
  float *v50; // eax
  double v51; // st6
  int v52; // eax
  float *v53; // ecx
  int v54; // edi
  float *v55; // eax
  unsigned int v56; // edx
  float *v57; // eax
  int v58; // edx
  int v59; // ecx
  double v60; // st6
  int cdbk_index; // [esp+4h] [ebp-28h] BYREF
  int best_gain_index; // [esp+8h] [ebp-24h]
  int best_pitch; // [esp+Ch] [ebp-20h]
  float best_err; // [esp+10h] [ebp-1Ch]
  int *nbest; // [esp+14h] [ebp-18h]
  int pitch; // [esp+18h] [ebp-14h]
  float *new_target; // [esp+1Ch] [ebp-10h]
  float *best_exc; // [esp+20h] [ebp-Ch]
  float *best_target; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]
  float errb; // [esp+54h] [ebp+28h]
  int err; // [esp+54h] [ebp+28h]
  int erra; // [esp+54h] [ebp+28h]
  char *stacka; // [esp+68h] [ebp+3Ch]

  v19 = -1.0;
  best_err = -1.0;
  pitch = 0;
  best_gain_index = 0;
  best_pitch = 0;
  if ( complexity <= 10 )
  {
    if ( complexity < 1 )
      complexity = 1;
  }
  else
  {
    complexity = 10;
  }
  nbest = (int *)&stack[4 * complexity + (-(int)stack & 3) + -4 * complexity];
  if ( end >= start )
  {
    v20 = (int)&stack[4 * complexity + (-(int)stack & 3)];
    v22 = 4 * nsf + (-v20 & 3) + v20;
    v23 = (char *)(4 * nsf + (-v22 & 3) + v22);
    new_target = (float *)&v23[-4 * nsf];
    v24 = &v23[4 * nsf + (-(int)v23 & 3)];
    v25 = (float *)(v22 - 4 * nsf);
    best_target = (float *)&v24[-4 * nsf];
    best_exc = v25;
    stacka = v24;
    if ( complexity > end - start + 1 )
      complexity = end - start + 1;
    open_loop_nbest_pitch(sw, start, end, nsf, nbest, 0, complexity, v24);
    for ( i = 0; i < complexity; ++i )
    {
      v26 = nbest[i];
      pitch = v26;
      if ( nsf > 0 )
      {
        memset(exc, 0, 4 * nsf);
        v25 = best_exc;
      }
      pitch_gain_search_3tap(
        ak,
        par,
        target,
        awk1,
        awk2,
        exc,
        v26,
        p,
        nsf,
        (SpeexBits *)v24,
        (char *)exc2,
        r,
        new_target,
        (float *)&cdbk_index,
        (int *)cdbk_offset,
        plc_tuning);
      errb = v19;
      v19 = errb;
      if ( best_err > (double)errb || best_err < 0.0 )
      {
        v44 = 0;
        err = 0;
        if ( nsf >= 4 )
        {
          v45 = exc + 3;
          best_gain_index = (char *)exc - (char *)v25;
          v46 = v25 + 1;
          v47 = ((unsigned int)(nsf - 4) >> 2) + 1;
          err = 4 * v47;
          v48 = (char *)((char *)exc - (char *)v25);
          do
          {
            v46 += 4;
            *(v46 - 5) = *(v45 - 3);
            v45 += 4;
            --v47;
            *(v46 - 4) = *(float *)((char *)v46 + (_DWORD)v48 - 16);
            *(v46 - 3) = *(v45 - 5);
            *(v46 - 2) = *(v45 - 4);
          }
          while ( v47 );
          v25 = best_exc;
          v44 = err;
        }
        if ( v44 < nsf )
        {
          v49 = nsf - err;
          v50 = &v25[v44];
          do
          {
            v51 = *(float *)((char *)v50++ + (char *)exc - (char *)v25);
            --v49;
            *(v50 - 1) = v51;
          }
          while ( v49 );
        }
        v52 = 0;
        erra = 0;
        if ( nsf >= 4 )
        {
          v53 = new_target + 3;
          v54 = (char *)new_target - (char *)best_target;
          v55 = best_target + 1;
          v56 = ((unsigned int)(nsf - 4) >> 2) + 1;
          erra = 4 * v56;
          do
          {
            v55 += 4;
            *(v55 - 5) = *(v53 - 3);
            v53 += 4;
            --v56;
            *(v55 - 4) = *(float *)((char *)v55 + v54 - 16);
            *(v55 - 3) = *(v53 - 5);
            *(v55 - 2) = *(v53 - 4);
          }
          while ( v56 );
          v24 = stacka;
          v25 = best_exc;
          v52 = erra;
        }
        if ( v52 < nsf )
        {
          v57 = &best_target[v52];
          v58 = (char *)new_target - (char *)best_target;
          v59 = nsf - erra;
          do
          {
            v60 = *(float *)((char *)v57++ + v58);
            --v59;
            *(v57 - 1) = v60;
          }
          while ( v59 );
        }
        best_err = v19;
        best_pitch = pitch;
        best_gain_index = cdbk_index;
      }
    }
    speex_bits_pack(bits, best_pitch - start, *((_DWORD *)par + 2));
    speex_bits_pack(bits, best_gain_index, *((_DWORD *)par + 1));
    v27 = 0;
    if ( nsf >= 4 )
    {
      v28 = exc + 1;
      v29 = ((unsigned int)(nsf - 4) >> 2) + 1;
      i = 4 * v29;
      v30 = v25 + 3;
      do
      {
        v28 += 4;
        *(v28 - 5) = *(v30 - 3);
        v30 += 4;
        --v29;
        *(v28 - 4) = *(float *)((char *)v28 + (char *)v25 - (char *)exc - 16);
        *(v28 - 3) = *(v30 - 5);
        *(v28 - 2) = *(v30 - 4);
      }
      while ( v29 );
      v27 = i;
    }
    if ( v27 < nsf )
    {
      v31 = &exc[v27];
      v32 = (char *)v25 - (char *)exc;
      v33 = nsf - v27;
      do
      {
        v34 = *(float *)((char *)v31++ + v32);
        --v33;
        *(v31 - 1) = v34;
      }
      while ( v33 );
    }
    v35 = 0;
    if ( nsf >= 4 )
    {
      v36 = target + 1;
      v37 = best_target + 3;
      v38 = (char *)best_target - (char *)target;
      v39 = ((unsigned int)(nsf - 4) >> 2) + 1;
      v35 = 4 * v39;
      do
      {
        v36 += 4;
        *(v36 - 5) = *(v37 - 3);
        v37 += 4;
        --v39;
        *(v36 - 4) = *(float *)((char *)v36 + v38 - 16);
        *(v36 - 3) = *(v37 - 5);
        *(v36 - 2) = *(v37 - 4);
      }
      while ( v39 );
    }
    if ( v35 < nsf )
    {
      v40 = (char *)best_target - (char *)target;
      v41 = &target[v35];
      v42 = nsf - v35;
      do
      {
        v43 = *(float *)((char *)v41++ + v40);
        --v42;
        *(v41 - 1) = v43;
      }
      while ( v42 );
    }
    return pitch;
  }
  else
  {
    speex_bits_pack(bits, 0, *((_DWORD *)par + 2));
    speex_bits_pack(bits, 0, *((_DWORD *)par + 1));
    if ( nsf > 0 )
      memset(exc, 0, 4 * nsf);
    return start;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlinkedlist.inl:0x9CF560
bool __thiscall bdByteBuffer::readInt32(bdByteBuffer *this, int *i)
{
  bool result; // al
  int data; // [esp+4h] [ebp-4h] BYREF

  if ( !bdByteBuffer::readDataType(this, BD_BB_SIGNED_INTEGER32_TYPE) )
    return 0;
  result = bdByteBuffer::read(this, &data, 4u);
  if ( result )
  {
    *i = data;
    return result;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlinkedlist.inl:0x9CF5B0
bool __thiscall bdByteBuffer::readUInt32(bdByteBuffer *this, unsigned int *u)
{
  bool result; // al
  unsigned int data; // [esp+4h] [ebp-4h] BYREF

  if ( !bdByteBuffer::readDataType(this, BD_BB_UNSIGNED_INTEGER32_TYPE) )
    return 0;
  result = bdByteBuffer::read(this, &data, 4u);
  if ( result )
  {
    *u = data;
    return result;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlinkedlist.inl:0x9CFAF0
bool __thiscall bdByteBuffer::readUByte8(bdByteBuffer *this, unsigned __int8 *b)
{
  bool result; // al
  unsigned __int8 data; // [esp+7h] [ebp-1h] BYREF

  if ( !bdByteBuffer::readDataType(this, BD_BB_UNSIGNED_CHAR8_TYPE) )
    return 0;
  result = bdByteBuffer::read(this, &data, 1u);
  if ( result )
  {
    *b = data;
    return result;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdlinkedlist.inl:0x9CFAF0
bool __thiscall bdByteBuffer::readUByte8(bdByteBuffer *this, unsigned __int8 *b)
{
  bool result; // al
  unsigned __int8 data; // [esp+7h] [ebp-1h] BYREF

  if ( !bdByteBuffer::readDataType(this, BD_BB_UNSIGNED_CHAR8_TYPE) )
    return 0;
  result = bdByteBuffer::read(this, &data, 1u);
  if ( result )
  {
    *b = data;
    return result;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
