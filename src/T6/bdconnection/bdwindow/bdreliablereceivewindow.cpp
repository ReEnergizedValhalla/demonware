// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdreliablereceivewindow.cpp:0x9CB590
void __cdecl lsp_interpolate(
        float *old_lsp,
        float *new_lsp,
        float *interp_lsp,
        int len,
        int subframe,
        int nb_subframes)
{
  float *v6; // ebx
  int v7; // edi
  int v8; // edx
  double v9; // st6
  double v10; // st5
  float *v11; // ecx
  float *v12; // eax
  double v13; // st4
  double v14; // st3
  float *v15; // eax
  int v16; // edi
  double v17; // st5
  float tmp; // [esp+1Ch] [ebp+18h]

  v6 = new_lsp;
  v7 = len;
  v8 = 0;
  tmp = ((double)subframe + 1.0) / (double)nb_subframes;
  v9 = tmp;
  if ( len >= 4 )
  {
    v10 = 1.0 - v9;
    v11 = interp_lsp + 2;
    v12 = new_lsp + 1;
    v7 = len;
    do
    {
      v13 = old_lsp[v8] * v10;
      v8 += 4;
      v14 = *(v12 - 1);
      v12 += 4;
      v11 += 4;
      *(v11 - 6) = v13 + v14 * v9;
      *(float *)((char *)v12 + (char *)interp_lsp - (char *)new_lsp - 16) = *(float *)((char *)v12
                                                                                     + (char *)old_lsp
                                                                                     - (char *)new_lsp
                                                                                     - 16)
                                                                          * v10
                                                                          + v9 * *(v12 - 4);
      *(v11 - 4) = *(float *)((char *)v11 + (char *)old_lsp - (char *)interp_lsp - 16) * v10 + *(v12 - 3) * v9;
      *(v11 - 3) = old_lsp[v8 - 1] * v10 + *(v12 - 2) * v9;
    }
    while ( v8 < len - 3 );
    v6 = new_lsp;
  }
  if ( v8 < v7 )
  {
    v15 = &v6[v8];
    v16 = v7 - v8;
    do
    {
      v17 = *(float *)((char *)v15++ + (char *)old_lsp - (char *)v6);
      --v16;
      *(float *)((char *)v15 + (char *)interp_lsp - (char *)v6 - 4) = v17 * (1.0 - v9) + *(v15 - 1) * v9;
    }
    while ( v16 );
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablereceivewindow.cpp:0x9CB680
double __cdecl _spx_lpc(float *lpc, const float *ac, int p)
{
  const float *v3; // edi
  double result; // st7
  int v5; // ebx
  const float *v6; // ecx
  int v7; // edx
  unsigned int v8; // edi
  float *v9; // eax
  double v10; // st5
  const float *v11; // eax
  int v12; // edx
  double v13; // st6
  double v14; // st5
  int v15; // ebx
  float *v16; // ecx
  unsigned int v17; // edi
  float *v18; // eax
  double v19; // st4
  int v20; // ecx
  float *v21; // eax
  double v22; // st4
  float error; // [esp+8h] [ebp-10h]
  float errora; // [esp+8h] [ebp-10h]
  const float *v25; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  float tmp; // [esp+14h] [ebp-4h]
  float tmpa; // [esp+14h] [ebp-4h]
  float tmpb; // [esp+14h] [ebp-4h]
  float tmpc; // [esp+14h] [ebp-4h]
  float tmpd; // [esp+14h] [ebp-4h]
  float tmpe; // [esp+14h] [ebp-4h]
  float tmpf; // [esp+14h] [ebp-4h]
  float tmpg; // [esp+14h] [ebp-4h]
  float tmph; // [esp+14h] [ebp-4h]

  v3 = ac;
  error = *ac;
  result = 0.0;
  if ( 0.0 == error )
  {
    if ( p > 0 )
      memset(lpc, 0, 4 * p);
  }
  else
  {
    v5 = 0;
    i = 0;
    if ( p > 0 )
    {
      v6 = ac - 2;
      v25 = ac - 2;
      while ( 1 )
      {
        v7 = 0;
        tmp = -v6[3];
        if ( v5 >= 4 )
        {
          v8 = ((unsigned int)(v5 - 4) >> 2) + 1;
          v9 = lpc + 2;
          v7 = 4 * v8;
          do
          {
            v9 += 4;
            v10 = v6[2];
            v6 -= 4;
            --v8;
            tmpa = tmp - v10 * *(v9 - 6);
            tmpb = tmpa - v6[5] * *(v9 - 5);
            tmpc = tmpb - *(v9 - 4) * v6[4];
            tmp = tmpc - v6[3] * *(v9 - 3);
          }
          while ( v8 );
          v3 = ac;
        }
        if ( v7 < v5 )
        {
          v11 = &v3[v5 - v7];
          do
          {
            ++v7;
            --v11;
            tmp = tmp - lpc[v7 - 1] * v11[1];
          }
          while ( v7 < v5 );
        }
        v12 = 0;
        v13 = error;
        errora = tmp / (*v3 * 0.003 + error);
        v14 = errora;
        lpc[v5] = errora;
        v15 = v5 >> 1;
        if ( v15 >= 4 )
        {
          v16 = (float *)((char *)v25 + (char *)lpc - (char *)ac);
          v17 = ((unsigned int)(v15 - 4) >> 2) + 1;
          v18 = lpc + 2;
          v12 = 4 * v17;
          do
          {
            v19 = *(v18 - 2);
            v18 += 4;
            tmpd = v19;
            v16 -= 4;
            --v17;
            *(v18 - 6) = v16[5] * v14 + *(v18 - 6);
            v16[5] = tmpd * v14 + v16[5];
            tmpe = *(v18 - 5);
            *(v18 - 5) = v16[4] * v14 + tmpe;
            v16[4] = tmpe * v14 + v16[4];
            tmpf = *(v18 - 4);
            *(v18 - 4) = v16[3] * v14 + tmpf;
            v16[3] = tmpf * v14 + v16[3];
            tmpg = *(v18 - 3);
            *(v18 - 3) = v16[2] * v14 + tmpg;
            v16[2] = tmpg * v14 + v16[2];
          }
          while ( v17 );
        }
        v20 = i;
        if ( v12 < v15 )
        {
          v21 = &lpc[i - v12 - 1];
          do
          {
            v22 = lpc[v12++];
            tmph = v22;
            --v21;
            lpc[v12 - 1] = v21[1] * v14 + lpc[v12 - 1];
            v21[1] = tmph * v14 + v21[1];
          }
          while ( v12 < v15 );
        }
        if ( (i & 1) != 0 )
          lpc[v12] = v14 * lpc[v12] + lpc[v12];
        ++v25;
        ++i;
        error = v13 - v14 * (v14 * v13);
        if ( v20 + 1 >= p )
          break;
        v6 = v25;
        v5 = i;
        v3 = ac;
      }
    }
    return error;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablereceivewindow.cpp:0x9CB8A0
void __cdecl _spx_autocorr(const float *x, float *ac, int lag, int n)
{
  int v4; // edi
  const float *v5; // edx
  int v6; // ecx
  const float *i; // eax
  const float *v8; // eax
  int v9; // esi
  const float *v10; // ecx
  const float *v11; // edx
  unsigned int v12; // eax
  double v13; // st6
  float *v14; // eax
  double v15; // st6
  double v16; // st6
  int v17; // [esp+4h] [ebp-8h]
  const float *v18; // [esp+8h] [ebp-4h]
  float d; // [esp+1Ch] [ebp+10h]
  float da; // [esp+1Ch] [ebp+10h]
  float db; // [esp+1Ch] [ebp+10h]
  float dc; // [esp+1Ch] [ebp+10h]

  v4 = lag;
  if ( lag )
  {
    v5 = x;
    v6 = n - lag;
    for ( i = &x[lag + 2]; ; i = v18 )
    {
      --v4;
      d = 0.0;
      ++v6;
      v8 = i - 1;
      v17 = v6;
      v18 = v8;
      v9 = v4;
      if ( v4 < n )
      {
        if ( v6 >= 4 )
        {
          v10 = v8;
          v11 = v5 + 2;
          v12 = ((unsigned int)(n - v4 - 4) >> 2) + 1;
          v9 = v4 + 4 * v12;
          do
          {
            v10 += 4;
            v13 = *(v11 - 2) * *(v10 - 6);
            v11 += 4;
            --v12;
            da = v13 + d;
            db = da + *(v11 - 5) * *(v10 - 5);
            dc = db + *(v11 - 4) * *(v10 - 4);
            d = dc + *(v11 - 3) * *(v10 - 3);
          }
          while ( v12 );
          v5 = x;
          v6 = v17;
        }
        if ( v9 < n )
        {
          v14 = (float *)&v5[v9 - v4];
          do
          {
            v15 = v5[v9++];
            v16 = v15 * *v14++;
            d = v16 + d;
          }
          while ( v9 < n );
        }
      }
      ac[v4] = d;
      if ( !v4 )
        break;
    }
  }
  *ac = *ac + 10.0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablereceivewindow.cpp:0x9CB980
int __cdecl scal_quant(float in, const float *boundary, int entries)
{
  double v3; // st7
  int v5; // esi
  int v6; // edx

  v3 = in;
  v5 = entries - 1;
  v6 = 0;
  if ( entries - 1 < 4 )
  {
LABEL_7:
    while ( v6 < v5 )
    {
      if ( *boundary >= v3 )
        break;
      ++v6;
      ++boundary;
    }
  }
  else
  {
    while ( *boundary < v3 )
    {
      if ( boundary[1] >= v3 )
        return v6 + 1;
      if ( boundary[2] >= v3 )
        return v6 + 2;
      if ( boundary[3] >= v3 )
        return v6 + 3;
      v6 += 4;
      boundary += 4;
      if ( v6 >= entries - 4 )
        goto LABEL_7;
    }
  }
  return v6;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablereceivewindow.cpp:0x9CBA10
int __cdecl scal_quant32(float in, const float *boundary, int entries)
{
  double v3; // st7
  int v5; // esi
  int v6; // edx

  v3 = in;
  v5 = entries - 1;
  v6 = 0;
  if ( entries - 1 < 4 )
  {
LABEL_7:
    while ( v6 < v5 )
    {
      if ( *boundary >= v3 )
        break;
      ++v6;
      ++boundary;
    }
  }
  else
  {
    while ( *boundary < v3 )
    {
      if ( boundary[1] >= v3 )
        return v6 + 1;
      if ( boundary[2] >= v3 )
        return v6 + 2;
      if ( boundary[3] >= v3 )
        return v6 + 3;
      v6 += 4;
      boundary += 4;
      if ( v6 >= entries - 4 )
        goto LABEL_7;
    }
  }
  return v6;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablereceivewindow.cpp:0x9CBAA0
int __cdecl vq_index(float *in, const float *codebook, int len, int entries)
{
  int result; // eax
  int v5; // esi
  int v7; // edx
  unsigned int v8; // esi
  float *v9; // eax
  double v10; // st6
  double v11; // st6
  double v12; // st6
  int best_index; // [esp+4h] [ebp-14h]
  int i; // [esp+8h] [ebp-10h]
  float min_dist; // [esp+Ch] [ebp-Ch]
  float tmp; // [esp+10h] [ebp-8h]
  float tmpa; // [esp+10h] [ebp-8h]
  float tmpb; // [esp+10h] [ebp-8h]
  float tmpc; // [esp+10h] [ebp-8h]
  float tmpd; // [esp+10h] [ebp-8h]
  float dist; // [esp+14h] [ebp-4h]
  float dista; // [esp+14h] [ebp-4h]
  float distb; // [esp+14h] [ebp-4h]
  float distc; // [esp+14h] [ebp-4h]

  result = 0;
  min_dist = 0.0;
  v5 = 0;
  best_index = 0;
  i = 0;
  if ( entries > 0 )
  {
    do
    {
      v7 = 0;
      dist = 0.0;
      if ( len >= 4 )
      {
        v8 = ((unsigned int)(len - 4) >> 2) + 1;
        v9 = in + 2;
        v7 = 4 * v8;
        do
        {
          codebook += 4;
          v10 = *(v9 - 2) - *(codebook - 4);
          v9 += 4;
          --v8;
          tmp = v10;
          dista = tmp * tmp + dist;
          tmpa = *(v9 - 5) - *(codebook - 3);
          distb = tmpa * tmpa + dista;
          tmpb = *(v9 - 4) - *(codebook - 2);
          distc = tmpb * tmpb + distb;
          tmpc = *(v9 - 3) - *(codebook - 1);
          dist = tmpc * tmpc + distc;
        }
        while ( v8 );
        v5 = i;
      }
      for ( ; v7 < len; dist = tmpd * tmpd + dist )
      {
        v11 = in[v7++];
        v12 = v11 - *codebook++;
        tmpd = v12;
      }
      if ( !v5 || min_dist > (double)dist )
      {
        min_dist = dist;
        best_index = v5;
      }
      i = ++v5;
    }
    while ( v5 < entries );
    return best_index;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreliablereceivewindow.cpp:0x9CBBA0
void __cdecl vq_nbest(
        float *in,
        const float *codebook,
        int len,
        int entries,
        float *E,
        int N,
        int *nbest,
        float *best_dist)
{
  int v8; // edx
  double v9; // st7
  int *v10; // ebx
  double v11; // st6
  const float *v12; // esi
  double v13; // rt0
  double v14; // rt1
  double v15; // st6
  double v16; // st7
  int v17; // ecx
  float *v18; // eax
  unsigned int v19; // edx
  double v20; // st5
  double v21; // st5
  double v22; // st5
  double v23; // st5
  int v24; // edx
  int v25; // edi
  float *v26; // esi
  int v27; // ebx
  float *v28; // ecx
  float *v29; // ecx
  int i; // [esp+0h] [ebp-Ch]
  int used; // [esp+4h] [ebp-8h]
  float dist; // [esp+8h] [ebp-4h]
  float distb; // [esp+8h] [ebp-4h]
  float distc; // [esp+8h] [ebp-4h]
  float distd; // [esp+8h] [ebp-4h]
  float diste; // [esp+8h] [ebp-4h]
  int dista; // [esp+8h] [ebp-4h]

  v8 = 0;
  used = 0;
  i = 0;
  if ( entries > 0 )
  {
    v9 = 0.0;
    v10 = nbest;
    v11 = 0.5;
    v12 = codebook;
    while ( 1 )
    {
      v14 = v11;
      v15 = v9;
      v16 = v14;
      v17 = 0;
      dist = v15;
      if ( len >= 4 )
      {
        v18 = in + 2;
        v19 = ((unsigned int)(len - 4) >> 2) + 1;
        v17 = 4 * v19;
        do
        {
          v12 += 4;
          v20 = *(v18 - 1) * *(v12 - 3);
          v18 += 4;
          --v19;
          distb = *(v18 - 6) * *(v12 - 4) + dist;
          distc = v20 + distb;
          distd = distc + *(v12 - 2) * *(v18 - 4);
          dist = distd + *(v18 - 3) * *(v12 - 1);
        }
        while ( v19 );
        v8 = i;
        codebook = v12;
      }
      if ( v17 < len )
      {
        do
        {
          v21 = in[v17++];
          v22 = v21 * *v12++;
          dist = v22 + dist;
        }
        while ( v17 < len );
        codebook = v12;
      }
      diste = E[v8] * v16 - dist;
      v23 = diste;
      if ( v8 < N || best_dist[N - 1] > v23 )
      {
        v24 = N - 1;
        if ( N - 1 < 4 )
        {
LABEL_26:
          if ( v24 >= 1 )
          {
            v29 = &best_dist[v24 - 1];
            do
            {
              if ( v24 <= used && *v29 <= v23 )
                break;
              --v24;
              v29[1] = *v29;
              v10[v24 + 1] = *(_DWORD *)((char *)v29-- + (char *)v10 - (char *)best_dist);
            }
            while ( v24 >= 1 );
          }
        }
        else
        {
          v25 = N - 3;
          v26 = (float *)&v10[N - 3];
          v27 = (char *)v10 - (char *)best_dist;
          v28 = &best_dist[v24 - 1];
          dista = v27;
          while ( v24 > used || *v28 > v23 )
          {
            v28[1] = *v28;
            v26[2] = *(float *)((char *)v28 + v27);
            if ( v25 + 1 <= used && *(v28 - 1) <= v23 )
            {
              --v24;
              break;
            }
            *v28 = *(v28 - 1);
            *(float *)((char *)v28 + dista) = *v26;
            if ( v25 <= used && *(v28 - 2) <= v23 )
            {
              v24 -= 2;
              break;
            }
            *(v28 - 1) = *(v28 - 2);
            *v26 = *(v26 - 1);
            if ( v25 - 1 <= used && *(v28 - 3) <= v23 )
            {
              v24 -= 3;
              break;
            }
            v24 -= 4;
            *(v28 - 2) = *(v28 - 3);
            *(v26 - 1) = *(v26 - 2);
            v28 -= 4;
            v26 -= 4;
            v25 -= 4;
            if ( v24 < 4 )
            {
              v10 = nbest;
              v12 = codebook;
              goto LABEL_26;
            }
            v27 = dista;
          }
          v12 = codebook;
          v10 = nbest;
        }
        best_dist[v24] = v23;
        ++used;
        v10[v24] = i;
        v8 = i;
      }
      i = ++v8;
      if ( v8 >= entries )
        break;
      v13 = v15;
      v11 = v16;
      v9 = v13;
    }
  }
}

#endif // __UNIMPLEMENTED__
