// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdreliablesendwindow.h:0x9CBDC0
void __cdecl vq_nbest_sign(
        float *in,
        const float *codebook,
        int len,
        int entries,
        float *E,
        int N,
        int *nbest,
        float *best_dist)
{
  double v8; // st7
  int *v9; // ebx
  double v10; // st6
  const float *v11; // esi
  double v12; // rt0
  double v13; // rt1
  double v14; // st6
  double v15; // st7
  int v16; // ecx
  float *v17; // eax
  unsigned int v18; // edx
  double v19; // st5
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
  float signa; // [esp+0h] [ebp-10h]
  float signb; // [esp+0h] [ebp-10h]
  float signc; // [esp+0h] [ebp-10h]
  int sign; // [esp+0h] [ebp-10h]
  int i; // [esp+4h] [ebp-Ch]
  int used; // [esp+8h] [ebp-8h]
  float dist; // [esp+Ch] [ebp-4h]
  float distb; // [esp+Ch] [ebp-4h]
  float distc; // [esp+Ch] [ebp-4h]
  int dista; // [esp+Ch] [ebp-4h]

  used = 0;
  i = 0;
  if ( entries > 0 )
  {
    v8 = 0.0;
    v9 = nbest;
    v10 = 0.5;
    v11 = codebook;
    while ( 1 )
    {
      v13 = v10;
      v14 = v8;
      v15 = v13;
      v16 = 0;
      dist = v14;
      if ( len >= 4 )
      {
        v17 = in + 2;
        v18 = ((unsigned int)(len - 4) >> 2) + 1;
        v16 = 4 * v18;
        do
        {
          v11 += 4;
          v19 = *(v17 - 1) * *(v11 - 3);
          v17 += 4;
          --v18;
          signa = *(v17 - 6) * *(v11 - 4) + dist;
          signb = v19 + signa;
          signc = signb + *(v11 - 2) * *(v17 - 4);
          dist = signc + *(v17 - 3) * *(v11 - 1);
        }
        while ( v18 );
        codebook = v11;
      }
      if ( v16 < len )
      {
        do
        {
          v20 = in[v16++];
          v21 = v20 * *v11++;
          dist = v21 + dist;
        }
        while ( v16 < len );
        codebook = v11;
      }
      v22 = dist;
      if ( dist <= v14 )
      {
        sign = 1;
      }
      else
      {
        sign = 0;
        distb = -v22;
        v22 = distb;
      }
      distc = v22 + E[i] * v15;
      v23 = distc;
      if ( i < N || best_dist[N - 1] > v23 )
      {
        v24 = N - 1;
        if ( N - 1 < 4 )
        {
LABEL_29:
          if ( v24 >= 1 )
          {
            v29 = &best_dist[v24 - 1];
            do
            {
              if ( v24 <= used && *v29 <= v23 )
                break;
              --v24;
              v29[1] = *v29;
              v9[v24 + 1] = *(_DWORD *)((char *)v29-- + (char *)v9 - (char *)best_dist);
            }
            while ( v24 >= 1 );
          }
        }
        else
        {
          v25 = N - 3;
          v26 = (float *)&v9[N - 3];
          v27 = (char *)v9 - (char *)best_dist;
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
              v9 = nbest;
              v11 = codebook;
              goto LABEL_29;
            }
            v27 = dista;
          }
          v11 = codebook;
          v9 = nbest;
        }
        best_dist[v24] = v23;
        ++used;
        v9[v24] = i;
        if ( sign )
          v9[v24] = entries + i;
      }
      if ( ++i >= entries )
        break;
      v12 = v14;
      v10 = v15;
      v8 = v12;
    }
  }
}

#endif // __UNIMPLEMENTED__
