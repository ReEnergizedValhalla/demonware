// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bddispatcher.cpp:0x9C7ED0
void __cdecl noise_codebook_unquant(float *exc, const void *par, int nsf)
{
  speex_rand_vec(1.0, exc, nsf);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddispatcher.cpp:0x9C7EF0
double __usercall inner_prod@<st0>(const float *x@<ecx>, const float *y@<eax>, int len@<edx>)
{
  int v3; // edx
  double v4; // st6
  float sum; // [esp+0h] [ebp-8h]
  float part; // [esp+4h] [ebp-4h]
  float parta; // [esp+4h] [ebp-4h]
  float partb; // [esp+4h] [ebp-4h]
  float partc; // [esp+4h] [ebp-4h]

  v3 = len >> 2;
  for ( sum = 0.0; v3; sum = partc + sum )
  {
    y += 4;
    v4 = *x * *(y - 4);
    x += 4;
    --v3;
    part = v4 + 0.0;
    parta = *(x - 3) * *(y - 3) + part;
    partb = *(x - 2) * *(y - 2) + parta;
    partc = *(x - 1) * *(y - 1) + partb;
  }
  return sum;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddispatcher.cpp:0x9C7F50
void __usercall pitch_xcorr(const float *_y@<edx>, float *corr@<eax>, int nb_pitch@<ecx>, const float *_x, int len)
{
  int v5; // ebx
  float *v7; // edi

  v5 = nb_pitch;
  if ( nb_pitch > 0 )
  {
    v7 = &corr[nb_pitch - 1];
    do
    {
      *v7-- = inner_prod(_x, _y++, len);
      --v5;
    }
    while ( v5 );
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bddispatcher.cpp:0x9C7F80
void __cdecl open_loop_nbest_pitch(float *sw, int start, int end, int len, int *pitch, float *gain, int N, char *stack)
{
  char *v8; // ebx
  int v9; // esi
  int v10; // edx
  char *v11; // edi
  int *v12; // eax
  int v13; // ecx
  float *v14; // eax
  float *v15; // edx
  unsigned int v16; // ecx
  float *v17; // ebx
  double v18; // st7
  double v19; // st6
  float *v20; // eax
  int v21; // ecx
  double v22; // st7
  double v23; // st6
  int v24; // eax
  double v25; // st6
  double v26; // st5
  float *v27; // edx
  unsigned int v28; // ecx
  float *v29; // ebx
  double v30; // rtt
  double v31; // st5
  double v32; // st6
  double v33; // rt0
  double v34; // st4
  double v35; // rtt
  float *v36; // edx
  int v37; // ecx
  double v38; // rt0
  double v39; // rt1
  double v40; // st5
  double v41; // st6
  double v42; // rt2
  double v43; // st4
  float *v44; // edx
  int v45; // ecx
  int v46; // edi
  int v47; // ecx
  int *v48; // eax
  float *v49; // edx
  unsigned int v50; // esi
  double v51; // st7
  int *v52; // eax
  int j; // edx
  float *v54; // edi
  int v55; // eax
  bool v56; // zf
  float e0; // [esp+10h] [ebp-20h]
  float *best_score; // [esp+18h] [ebp-18h]
  int v59; // [esp+1Ch] [ebp-14h]
  int v60; // [esp+1Ch] [ebp-14h]
  float *v61; // [esp+1Ch] [ebp-14h]
  float v62; // [esp+20h] [ebp-10h]
  float v63; // [esp+20h] [ebp-10h]
  float v64; // [esp+20h] [ebp-10h]
  float *v65; // [esp+20h] [ebp-10h]
  float *corr; // [esp+24h] [ebp-Ch]
  float *v67; // [esp+28h] [ebp-8h]
  float *v68; // [esp+28h] [ebp-8h]
  float *energy; // [esp+2Ch] [ebp-4h]
  float g; // [esp+38h] [ebp+8h]
  float ga; // [esp+38h] [ebp+8h]
  float gb; // [esp+38h] [ebp+8h]
  float gc; // [esp+38h] [ebp+8h]
  float gd; // [esp+38h] [ebp+8h]
  int ge; // [esp+38h] [ebp+8h]
  int gf; // [esp+38h] [ebp+8h]
  int starta; // [esp+3Ch] [ebp+Ch]
  float endb; // [esp+40h] [ebp+10h]
  float enda; // [esp+40h] [ebp+10h]
  int i; // [esp+54h] [ebp+24h]
  int ia; // [esp+54h] [ebp+24h]
  int ib; // [esp+54h] [ebp+24h]

  v8 = &stack[4 * N + (-(int)stack & 3) + -4 * N];
  v9 = start;
  corr = (float *)&stack[4 * N
                       + 4 * (end - start)
                       + 4 * (start - end)
                       + (-(int)stack & 3)
                       + (-(int)&stack[4 * N + (-(int)stack & 3)] & 3)];
  v10 = N;
  v59 = end - start;
  v11 = &stack[4 * N
             + 12
             + 4 * (end - start)
             + 4 * (end - start)
             + (-(int)stack & 3)
             + (-(int)&stack[4 * N + (-(int)stack & 3)] & 3)
             + (-(int)&stack[4 * N
                           + 4
                           + 4 * (end - start)
                           + (-(int)stack & 3)
                           + (-(int)&stack[4 * N + (-(int)stack & 3)] & 3)] & 3)
             + (-(int)&stack[4 * N
                           + 12
                           + 4 * (end - start)
                           + 4 * (end - start)
                           + (-(int)stack & 3)
                           + (-(int)&stack[4 * N + (-(int)stack & 3)] & 3)
                           + (-(int)&stack[4 * N
                                         + 4
                                         + 4 * (end - start)
                                         + (-(int)stack & 3)
                                         + (-(int)&stack[4 * N + (-(int)stack & 3)] & 3)] & 3)] & 3)];
  best_score = (float *)v8;
  energy = (float *)&stack[4 * N
                         + 4
                         + 4 * (end - start)
                         + 4 * (end - start)
                         + 4 * (start - end)
                         + (-(int)stack & 3)
                         + (-(int)&stack[4 * N + (-(int)stack & 3)] & 3)
                         + (-(int)&stack[4 * N
                                       + 4
                                       + 4 * (end - start)
                                       + (-(int)stack & 3)
                                       + (-(int)&stack[4 * N + (-(int)stack & 3)] & 3)] & 3)];
  if ( N > 0 )
  {
    v12 = pitch;
    do
    {
      *(float *)((char *)v12 + v8 - (char *)pitch) = -1.0;
      *v12++ = start;
      --v10;
    }
    while ( v10 );
  }
  *energy = inner_prod(&sw[-start], &sw[-start], len);
  e0 = inner_prod(sw, sw, len);
  v13 = start;
  i = start;
  if ( start <= end )
  {
    if ( v59 + 1 >= 4 )
    {
      v14 = &sw[-start - 2];
      v15 = energy + 2;
      v16 = ((unsigned int)(end - start - 3) >> 2) + 1;
      i = start + 4 * v16;
      v17 = &sw[len - start - 2];
      do
      {
        v18 = v14[1];
        v14 -= 4;
        v19 = v17[1];
        v15 += 4;
        v17 -= 4;
        --v16;
        v62 = v18 * v18 + *(v15 - 6) - v19 * v19;
        *(v15 - 5) = v62;
        v63 = v62 + v14[4] * v14[4] - v17[4] * v17[4];
        *(v15 - 4) = v63;
        v64 = v63 + v14[3] * v14[3] - v17[3] * v17[3];
        *(v15 - 3) = v64;
        *(v15 - 2) = v64 + v14[2] * v14[2] - v17[2] * v17[2];
      }
      while ( v16 );
      v8 = (char *)best_score;
      v13 = i;
    }
    if ( v13 <= end )
    {
      v20 = &energy[v13 - start];
      v67 = &sw[-v13 - 1];
      v65 = &sw[len - i - 1];
      v21 = end - i + 1;
      do
      {
        v22 = *v67;
        v23 = *v65;
        --v67;
        --v65;
        ++v20;
        --v21;
        *v20 = v22 * v22 + *(v20 - 1) - v23 * v23;
      }
      while ( v21 );
    }
  }
  v60 = v59 + 1;
  pitch_xcorr(&sw[-end], corr, v60, sw, len);
  v24 = start;
  ia = start;
  if ( start <= end )
  {
    v25 = 16.0;
    v26 = -16.0;
    if ( v60 >= 4 )
    {
      v68 = energy;
      v27 = corr + 1;
      v28 = ((unsigned int)(end - start - 3) >> 2) + 1;
      v29 = (float *)(v11 + 8);
      ia = start + 4 * v28;
      do
      {
        g = *(v27 - 1) / (*v68 + 1.0);
        if ( g <= v25 )
        {
          if ( g < v26 )
            g = v26;
          v33 = v26;
          v31 = v25;
          v32 = v33;
        }
        else
        {
          v30 = v26;
          v31 = v25;
          v32 = v30;
          g = v31;
        }
        *(v29 - 2) = *(v27 - 1) * g;
        ga = *v27 / (*(float *)((char *)v27 + (char *)energy - (char *)corr) + 1.0);
        if ( ga <= v31 )
        {
          if ( ga < v32 )
            ga = v32;
        }
        else
        {
          ga = v31;
        }
        *(float *)((char *)v27 + v11 - (char *)corr) = *v27 * ga;
        gb = v27[1] / (*(float *)((char *)v29 + (char *)energy - v11) + 1.0);
        if ( gb <= v31 )
        {
          if ( gb < v32 )
            gb = v32;
        }
        else
        {
          gb = v31;
        }
        *v29 = v27[1] * gb;
        gc = v27[2] / (v68[3] + 1.0);
        if ( gc <= v31 )
        {
          if ( gc < v32 )
            gc = v32;
        }
        else
        {
          gc = v31;
        }
        v68 += 4;
        v34 = v27[2] * gc;
        v27 += 4;
        v29 += 4;
        --v28;
        *(v29 - 3) = v34;
        v35 = v31;
        v26 = v32;
        v25 = v35;
      }
      while ( v28 );
      v8 = (char *)best_score;
      v24 = ia;
    }
    if ( v24 <= end )
    {
      v36 = &corr[v24 - start];
      v37 = end - ia + 1;
      while ( 1 )
      {
        gd = *v36 / (*(float *)((char *)v36 + (char *)energy - (char *)corr) + 1.0);
        if ( gd <= v25 )
        {
          if ( gd < v26 )
            gd = v26;
          v42 = v26;
          v40 = v25;
          v41 = v42;
        }
        else
        {
          v39 = v26;
          v40 = v25;
          v41 = v39;
          gd = v40;
        }
        v43 = *v36++ * gd;
        --v37;
        *(float *)((char *)v36 + v11 - (char *)corr - 4) = v43;
        if ( !v37 )
          break;
        v38 = v40;
        v26 = v41;
        v25 = v38;
      }
    }
  }
  ib = start;
  if ( start > end )
  {
    v45 = N;
  }
  else
  {
    v44 = (float *)v11;
    v61 = (float *)v11;
    do
    {
      v45 = N;
      if ( *(float *)&v8[4 * N - 4] < (double)*v44 )
      {
        v46 = 0;
        if ( N > 0 )
        {
          while ( *(float *)&v8[4 * v46] >= (double)*v44 )
          {
            if ( ++v46 >= N )
              goto LABEL_62;
          }
          v47 = N - 1;
          if ( N - 1 > v46 )
          {
            if ( v47 - v46 >= 4 )
            {
              v48 = &pitch[v47 - 1];
              v49 = (float *)&v8[4 * v47 - 8];
              v50 = ((unsigned int)(v47 - v46 - 4) >> 2) + 1;
              ge = v8 - (char *)pitch;
              v47 -= 4 * v50;
              do
              {
                v51 = *(float *)((char *)v48 + ge);
                v48 -= 4;
                v49[2] = v51;
                v48[5] = v48[4];
                *(int *)((char *)v48 + ge + 16) = *(int *)v49;
                v48[4] = v48[3];
                *v49 = *(v49 - 1);
                v48[3] = v48[2];
                *(v49 - 1) = *(v49 - 2);
                v48[2] = v48[1];
                v49 -= 4;
                --v50;
              }
              while ( v50 );
              v44 = v61;
              v8 = (char *)best_score;
              v9 = start;
            }
            if ( v47 > v46 )
            {
              v52 = &pitch[v47 - 1];
              for ( j = v8 - (char *)pitch; ; j = v8 - (char *)pitch )
              {
                --v47;
                *(float *)&v8[4 * v47 + 4] = *(float *)((char *)v52 + j);
                v52[1] = *v52;
                --v52;
                if ( v47 <= v46 )
                  break;
              }
              v44 = v61;
            }
          }
          *(float *)&v8[4 * v46] = *v44;
          pitch[v46] = ib;
          v45 = N;
        }
      }
LABEL_62:
      ++v44;
      ++ib;
      v61 = v44;
    }
    while ( ib <= end );
  }
  v54 = gain;
  if ( gain && v45 > 0 )
  {
    *(float *)&starta = sqrt(e0);
    gf = N;
    do
    {
      v55 = *(_DWORD *)((char *)v54 + (char *)pitch - (char *)gain) - v9;
      endb = sqrt(energy[v55]);
      enda = corr[v55] / (endb * *(float *)&starta + 10.0);
      if ( enda < 0.0 )
        enda = 0.0;
      ++v54;
      v56 = gf-- == 1;
      *(v54 - 1) = enda;
    }
    while ( !v56 );
  }
}

#endif // __UNIMPLEMENTED__
