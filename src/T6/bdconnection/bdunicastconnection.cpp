// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9C8510
int __usercall pitch_gain_search_3tap@<eax>(
        const float *ak@<ecx>,
        const void *par@<edx>,
        const float *target,
        const float *awk1,
        const float *awk2,
        float *exc,
        int pitch,
        int p,
        int nsf,
        SpeexBits *bits,
        char *stack,
        const float *exc2,
        const float *r,
        float *new_target,
        int *cdbk_index,
        int cdbk_offset)
{
  char *v16; // ebx
  double v17; // st7
  float *v18; // ecx
  int v19; // edi
  float v20; // edx
  int v21; // ecx
  int v22; // ecx
  int v23; // edx
  float *v24; // eax
  unsigned int v25; // edi
  float *v26; // ecx
  float v27; // eax
  float *v28; // edx
  int v29; // ecx
  float *v30; // eax
  float v31; // ecx
  int v32; // eax
  float *v33; // ecx
  float *v34; // ebx
  float *v35; // edx
  float v36; // ebx
  float *v37; // eax
  unsigned int v38; // ecx
  double v39; // st6
  int v40; // edx
  float *v41; // eax
  int v42; // ecx
  float *v43; // edx
  double v44; // st6
  float *v45; // ecx
  int v46; // ebx
  float *v47; // edi
  const float *v48; // edx
  char *v49; // ebx
  float *v50; // eax
  unsigned int v51; // ecx
  double v52; // st6
  float *v53; // ecx
  float *v54; // eax
  char *v55; // edx
  int v56; // ecx
  double v57; // st6
  float *v58; // ebx
  int i; // edi
  int v60; // ebx
  int v61; // edi
  float v62; // ecx
  double v63; // st7
  float *v64; // eax
  double v65; // st7
  int v66; // edx
  int v67; // ecx
  double v68; // st4
  double v69; // st6
  double v70; // st5
  double v71; // st6
  double v72; // st6
  double v73; // st5
  const char *v74; // edi
  double v75; // st4
  float v76; // eax
  double v77; // rt2
  double v78; // st4
  double v79; // st6
  double v80; // st3
  int v81; // eax
  double v82; // rtt
  double v83; // st4
  double v84; // st5
  double v85; // st4
  double v86; // st5
  double v87; // st3
  double v88; // st6
  double v89; // st4
  double v90; // st7
  double v91; // st7
  const char *v92; // eax
  float v93; // ecx
  float v94; // eax
  double v95; // st4
  int v96; // edi
  double v97; // st4
  double v98; // st6
  double v99; // st5
  double v100; // st4
  float *v101; // eax
  float *v102; // edx
  float *v103; // ecx
  float v104; // ebx
  double v105; // st3
  double v106; // st2
  float *v107; // eax
  int v108; // edx
  int v109; // ebx
  int v110; // ecx
  double v111; // st3
  int result; // eax
  double v113; // rt2
  double v114; // st4
  double v115; // st7
  float *v116; // eax
  float v117; // ebx
  float *v118; // edx
  float *v119; // ecx
  float *v120; // edi
  double v121; // st4
  float *v122; // ebx
  double v123; // st4
  double v124; // st4
  double v125; // st4
  double v126; // st4
  double v127; // st2
  double v128; // st3
  char *v129; // edx
  char *v130; // edi
  int v131; // ebx
  int v132; // esi
  char *v133; // ecx
  double v134; // st4
  double v135; // st4
  float C; // [esp+Ch] [ebp-B8h]
  float C_4; // [esp+10h] [ebp-B4h]
  float C_8; // [esp+14h] [ebp-B0h]
  float C_24; // [esp+24h] [ebp-A0h]
  float C_28; // [esp+28h] [ebp-9Ch]
  float C_32; // [esp+2Ch] [ebp-98h]
  float *tmp1; // [esp+30h] [ebp-94h]
  double v143; // [esp+34h] [ebp-90h]
  char *v144; // [esp+38h] [ebp-8Ch]
  char *v145; // [esp+38h] [ebp-8Ch]
  float g0; // [esp+40h] [ebp-84h]
  int g0a; // [esp+40h] [ebp-84h]
  char *g0b; // [esp+40h] [ebp-84h]
  float *e[3]; // [esp+44h] [ebp-80h]
  int gain_cdbk_size; // [esp+50h] [ebp-74h]
  const char *gain_cdbk; // [esp+54h] [ebp-70h]
  float *y; // [esp+58h] [ebp-6Ch]
  const float *v153; // [esp+5Ch] [ebp-68h]
  float *tmp2; // [esp+60h] [ebp-64h]
  float *x[3]; // [esp+64h] [ebp-60h]
  float *v156; // [esp+70h] [ebp-54h]
  int j; // [esp+74h] [ebp-50h]
  float v158; // [esp+78h] [ebp-4Ch]
  float gain_sum; // [esp+7Ch] [ebp-48h]
  float v160; // [esp+80h] [ebp-44h]
  float best_sum; // [esp+84h] [ebp-40h]
  float pitch_control; // [esp+88h] [ebp-3Ch]
  float g2; // [esp+8Ch] [ebp-38h]
  float A[3][3]; // [esp+90h] [ebp-34h] BYREF
  float g1; // [esp+B4h] [ebp-10h]
  float *v166[2]; // [esp+B8h] [ebp-Ch]

  v16 = stack;
  v17 = 0.0;
  y = (float *)target;
  v166[1] = (float *)awk1;
  g2 = *(float *)&ak;
  v156 = exc;
  v160 = *(float *)&new_target;
  v153 = r;
  gain_cdbk_size = 1 << *((_DWORD *)par + 1);
  gain_cdbk = (const char *)(*(_DWORD *)par + 3 * (_DWORD)cdbk_index * gain_cdbk_size);
  v18 = (float *)((char *)bits + 12 * nsf + (-(int)bits & 3) + -12 * nsf);
  tmp1 = v18;
  x[0] = v18;
  x[1] = &v18[nsf];
  x[2] = &v18[2 * nsf];
  v19 = 2;
  tmp2 = (float *)((char *)bits
                 + 12 * nsf
                 + 12 * nsf
                 + (-(int)bits & 3)
                 + (-((int)bits + 12 * nsf + (-(int)bits & 3)) & 3)
                 + -12 * nsf);
  e[0] = tmp2;
  e[1] = &tmp2[nsf];
  e[2] = &tmp2[2 * nsf];
  LODWORD(gain_sum) = 2;
  while ( 1 )
  {
    LODWORD(v20) = pitch - v19 + 1;
    v21 = 0;
    best_sum = v20;
    j = 0;
    if ( nsf >= 4 )
    {
      v22 = 2 - LODWORD(v20);
      v23 = 2 - LODWORD(v20) - pitch;
      v24 = e[v19] + 2;
      LODWORD(pitch_control) = &v16[4 * v23];
      v25 = ((unsigned int)(nsf - 4) >> 2) + 1;
      v26 = (float *)&v16[4 * v22];
      j = 4 * v25;
      do
      {
        if ( pitch + v23 - 2 >= 0 )
        {
          if ( v23 - 2 >= 0 )
            *(v24 - 2) = v17;
          else
            *(v24 - 2) = *(float *)(LODWORD(pitch_control) - 8);
        }
        else
        {
          *(v24 - 2) = *(v26 - 2);
        }
        if ( pitch + v23 - 1 >= 0 )
        {
          if ( v23 - 1 >= 0 )
            *(v24 - 1) = v17;
          else
            *(v24 - 1) = *(float *)(LODWORD(pitch_control) - 4);
        }
        else
        {
          *(v24 - 1) = *(v26 - 1);
        }
        if ( v23 + pitch >= 0 )
        {
          if ( v23 >= 0 )
            *v24 = v17;
          else
            *v24 = *(float *)LODWORD(pitch_control);
        }
        else
        {
          *v24 = *v26;
        }
        if ( pitch + v23 + 1 >= 0 )
        {
          if ( v23 + 1 >= 0 )
            v24[1] = v17;
          else
            v24[1] = *(float *)(LODWORD(pitch_control) + 4);
        }
        else
        {
          v24[1] = v26[1];
        }
        LODWORD(pitch_control) += 16;
        v24 += 4;
        v26 += 4;
        v23 += 4;
        --v25;
      }
      while ( v25 );
      *(float *)&v19 = gain_sum;
      v20 = best_sum;
      v21 = j;
    }
    if ( v21 < nsf )
    {
      LODWORD(v27) = v21 - LODWORD(v20);
      v28 = &e[v19][v21];
      pitch_control = v27;
      LODWORD(v158) = LODWORD(v27) - pitch;
      LODWORD(best_sum) = &stack[4 * (LODWORD(v27) - pitch)];
      v29 = nsf - j;
      v30 = (float *)&stack[4 * LODWORD(v27)];
      do
      {
        if ( pitch_control >= 0.0 )
        {
          if ( v158 >= 0.0 )
            *v28 = v17;
          else
            *v28 = *(float *)LODWORD(best_sum);
        }
        else
        {
          *v28 = *v30;
        }
        ++LODWORD(pitch_control);
        ++LODWORD(v158);
        LODWORD(best_sum) += 4;
        ++v30;
        ++v28;
        --v29;
      }
      while ( v29 );
    }
    if ( v19 == 2 )
    {
      syn_percep_zero(
        e[2],
        (const float *)LODWORD(g2),
        v166[1],
        awk2,
        x[2],
        nsf,
        p,
        (char *)bits + 12 * nsf + 12 * nsf + (-(int)bits & 3) + (-((int)bits + 12 * nsf + (-(int)bits & 3)) & 3));
      v17 = 0.0;
    }
    else
    {
      LODWORD(v31) = nsf - 1;
      v32 = 0;
      j = 0;
      LODWORD(best_sum) = nsf - 1;
      if ( nsf - 1 >= 4 )
      {
        v33 = x[v19 + 1];
        v34 = x[v19];
        v35 = v34 + 3;
        LODWORD(v36) = (char *)v34 - (char *)v33;
        v37 = v33 + 1;
        v158 = v36;
        v38 = ((unsigned int)(LODWORD(best_sum) - 4) >> 2) + 1;
        j = 4 * v38;
        do
        {
          v39 = *(v37 - 1);
          v37 += 4;
          *(float *)((char *)v37 + LODWORD(v36) - 16) = v39;
          v35 += 4;
          --v38;
          *(v35 - 5) = *(v37 - 4);
          *(v35 - 4) = *(v37 - 3);
          *(v35 - 3) = *(v37 - 2);
        }
        while ( v38 );
        v31 = best_sum;
        v32 = j;
      }
      if ( v32 < SLODWORD(v31) )
      {
        v40 = v32;
        v41 = &x[v19 + 1][v32];
        v42 = LODWORD(v31) - j;
        v43 = &x[v19][v40 + 1];
        do
        {
          v44 = *v41++;
          *v43++ = v44;
          --v42;
        }
        while ( v42 );
      }
      v45 = x[v19];
      v46 = 0;
      *v45 = v17;
      if ( nsf >= 4 )
      {
        v47 = e[v19];
        v48 = exc2 + 3;
        v49 = (char *)((char *)exc2 - (char *)v45);
        v50 = v45 + 1;
        LODWORD(best_sum) = (char *)exc2 - (char *)v45;
        v51 = ((unsigned int)(nsf - 4) >> 2) + 1;
        j = 4 * v51;
        do
        {
          v50 += 4;
          v52 = *(v48 - 3) * *v47;
          v48 += 4;
          --v51;
          *(v50 - 5) = v52 + *(v50 - 5);
          *(v50 - 4) = *(float *)&v49[(_DWORD)v50 - 16] * *v47 + *(v50 - 4);
          *(v50 - 3) = *(v48 - 5) * *v47 + *(v50 - 3);
          *(v50 - 2) = *v47 * *(v48 - 4) + *(v50 - 2);
        }
        while ( v51 );
        v46 = j;
        *(float *)&v19 = gain_sum;
      }
      if ( v46 < nsf )
      {
        v53 = x[v19];
        v54 = &v53[v46];
        v55 = (char *)((char *)exc2 - (char *)v53);
        v56 = nsf - v46;
        do
        {
          v57 = *(float *)((char *)v54++ + (_DWORD)v55) * *e[v19];
          --v56;
          *(v54 - 1) = v57 + *(v54 - 1);
        }
        while ( v56 );
      }
    }
    --v19;
    gain_sum = *(float *)&v19;
    if ( v19 < 0 )
      break;
    v16 = stack;
  }
  v58 = y;
  for ( i = 0; i < 3; ++i )
    *(float *)&v166[i - 1] = inner_prod(x[i], v58, nsf);
  v60 = 0;
  best_sum = COERCE_FLOAT(A);
  do
  {
    v61 = 0;
    if ( v60 >= 0 )
    {
      v158 = best_sum;
      LODWORD(pitch_control) = (char *)A + 4 * v60;
      do
      {
        g2 = inner_prod(x[v60], x[v61], nsf);
        v62 = pitch_control;
        v63 = g2;
        v64 = (float *)LODWORD(v158);
        *(float *)LODWORD(pitch_control) = g2;
        *v64 = v63;
        ++v61;
        LODWORD(v158) = v64 + 1;
        LODWORD(pitch_control) = LODWORD(v62) + 12;
      }
      while ( v61 <= v60 );
    }
    LODWORD(best_sum) += 12;
    ++v60;
  }
  while ( v60 < 3 );
  v65 = 0.0;
  v66 = 0;
  best_sum = 0.0;
  if ( cdbk_offset < 2 )
    cdbk_offset = 2;
  v67 = 0;
  v143 = (double)cdbk_offset;
  v68 = 1.0 - v143 * 0.01;
  C = *(float *)&v166[1] * v68;
  C_4 = *(float *)v166 * v68;
  C_8 = v68 * g1;
  v69 = (v143 * 0.01 + 1.0) * 0.5;
  C_24 = A[2][2] * v69;
  C_28 = A[1][1] * v69;
  v70 = v69 * A[0][0];
  v71 = 0.5;
  C_32 = v70;
  if ( gain_cdbk_size > 0 )
  {
    v72 = 64.0;
    v73 = 32.0;
    v74 = gain_cdbk + 2;
    v75 = 64.0;
    while ( 1 )
    {
      LODWORD(v76) = *(v74 - 2);
      v77 = v75;
      v78 = v72;
      v79 = v77;
      pitch_control = v78;
      g2 = v76;
      v80 = (double)SLODWORD(v76);
      LODWORD(g2) = *(v74 - 1);
      v81 = *v74;
      g0 = v80 + v73;
      *(float *)&v166[1] = (double)SLODWORD(g2) + v73;
      v82 = v78;
      v83 = v73 + (double)v81;
      v84 = v82;
      g2 = v83;
      v85 = *(float *)&v166[1];
      gain_sum = *(float *)&v166[1];
      if ( g0 > v65 )
        gain_sum = v85 + g0;
      if ( g2 > v65 )
        gain_sum = gain_sum + g2;
      if ( gain_sum <= v84 )
      {
        v86 = g2;
        v88 = g0;
        v90 = *(float *)&v166[1];
      }
      else
      {
        v86 = g2;
        gain_sum = gain_sum - v79;
        if ( gain_sum > 127.0 )
          gain_sum = 127.0;
        v87 = v79 * (1.0 - v143 * 0.001 * gain_sum);
        v88 = g0;
        pitch_control = v87;
        if ( pitch_control >= v65 )
        {
          v91 = pitch_control;
          goto LABEL_74;
        }
        v89 = v65;
        v90 = *(float *)&v166[1];
        pitch_control = v89;
      }
      v85 = v90;
      v91 = pitch_control;
LABEL_74:
      *(double *)v166 = v85;
      g2 = v88 * v91 * C + 0.0;
      g2 = g2 + v85 * v91 * C_4;
      g2 = v91 * v86 * C_8 + g2;
      g2 = g2 - v85 * v88 * A[1][2];
      g2 = g2 - v85 * v86 * A[0][1];
      g2 = g2 - v88 * v86 * A[0][2];
      g2 = g2 - v88 * v88 * C_24;
      g2 = g2 - *(double *)v166 * *(double *)v166 * C_28;
      g2 = g2 - v86 * v86 * C_32;
      if ( best_sum < (double)g2 || !v67 )
      {
        best_sum = g2;
        v66 = v67;
      }
      v65 = 0.0;
      ++v67;
      v74 += 3;
      if ( v67 >= gain_cdbk_size )
      {
        v71 = 0.5;
        break;
      }
      v73 = 32.0;
      v75 = 64.0;
      v72 = 64.0;
    }
  }
  v92 = &gain_cdbk[2 * v66];
  LODWORD(g2) = v92[v66];
  LODWORD(v93) = v92[v66 + 1];
  LODWORD(v94) = v92[v66 + 2];
  v95 = (double)SLODWORD(g2) * 0.015625;
  g2 = v93;
  v96 = 0;
  *(_DWORD *)LODWORD(v160) = v66;
  gain_sum = 0.0;
  g1 = v95 + v71;
  v97 = (double)SLODWORD(g2);
  g2 = v94;
  *(float *)v166 = v97 * 0.015625 + v71;
  *(float *)&v166[1] = v71 + 0.015625 * (double)SLODWORD(v94);
  v98 = *(float *)&v166[1];
  v99 = *(float *)v166;
  v100 = g1;
  if ( nsf >= 4 )
  {
    LODWORD(v160) = (char *)e[2] - (char *)e[1];
    LODWORD(g2) = (char *)tmp2 - (char *)e[1];
    v101 = e[1] + 1;
    LODWORD(best_sum) = (char *)v156 - (char *)e[1];
    v166[1] = (float *)((char *)e[2] - (char *)tmp2);
    g0a = (char *)v156 - (char *)tmp2;
    v102 = v156 + 3;
    v103 = tmp2 + 2;
    v144 = (char *)((char *)e[2] - (char *)v156);
    v96 = LODWORD(gain_sum);
    do
    {
      v104 = v160;
      v105 = e[2][v96] * v100;
      v96 += 4;
      v106 = *(v101 - 1);
      v101 += 4;
      v103 += 4;
      v102 += 4;
      *(v102 - 7) = v105 + v106 * v99 + *(v103 - 6) * v98;
      *(float *)((char *)v101 + LODWORD(best_sum) - 16) = *(float *)((char *)v101 + LODWORD(v104) - 16) * v100
                                                        + *(v101 - 4) * v99
                                                        + *(float *)((char *)v101 + LODWORD(g2) - 16) * v98;
      *(float *)((char *)v103 + g0a - 16) = *(float *)((char *)v166[1] + (unsigned int)v103 - 16) * v100
                                          + *(v101 - 3) * v99
                                          + *(v103 - 4) * v98;
      *(v102 - 4) = *(float *)((char *)v102 + (_DWORD)v144 - 16) * v100 + *(v101 - 2) * v99 + *(v103 - 3) * v98;
    }
    while ( v96 < nsf - 3 );
  }
  if ( v96 < nsf )
  {
    v107 = &e[1][v96];
    v108 = (char *)e[2] - (char *)e[1];
    v109 = (char *)tmp2 - (char *)e[1];
    LODWORD(best_sum) = (char *)v156 - (char *)e[1];
    v110 = nsf - v96;
    do
    {
      v111 = *(float *)((char *)v107++ + v108) * v100;
      --v110;
      *(float *)((char *)v107 + LODWORD(best_sum) - 4) = v111
                                                       + *(v107 - 1) * v99
                                                       + *(float *)((char *)v107 + v109 - 4) * v98;
    }
    while ( v110 );
  }
  result = 0;
  v113 = v100;
  v114 = v65;
  v115 = v113;
  pitch_control = v114;
  gain_sum = 0.0;
  if ( nsf >= 4 )
  {
    v166[1] = (float *)((char *)y - (char *)tmp1);
    g0b = (char *)((char *)x[1] - (char *)tmp1);
    LODWORD(best_sum) = (char *)x[2] - (char *)tmp1;
    v116 = tmp1 + 1;
    gain_cdbk = (const char *)((char *)v153 - (char *)tmp1);
    v145 = (char *)((char *)y - (char *)x[1]);
    tmp2 = (float *)((char *)x[2] - (char *)x[1]);
    gain_cdbk_size = (char *)v153 - (char *)x[1];
    v156 = (float *)((char *)y - (char *)x[2]);
    LODWORD(v117) = (char *)y - (char *)v153;
    j = (char *)v153 - (char *)x[2];
    LODWORD(v158) = ((unsigned int)(nsf - 4) >> 2) + 1;
    v118 = x[2] + 3;
    v119 = x[1] + 2;
    LODWORD(gain_sum) = 4 * LODWORD(v158);
    v120 = (float *)v153;
    LODWORD(g2) = (char *)y - (char *)v153;
    while ( 1 )
    {
      v121 = *(float *)((char *)v120 + LODWORD(v117));
      v122 = v166[1];
      v160 = *(v116 - 1) * v98 + *(v119 - 2) * v99 + *(v118 - 3) * v115;
      *v120 = v121 - v160;
      v123 = *(float *)((char *)v116 + (_DWORD)v122);
      v160 = *(float *)((char *)v116 + (_DWORD)g0b) * v99
           + *v116 * v98
           + *(float *)((char *)v116 + LODWORD(best_sum)) * v115;
      *(float *)((char *)v116 + (_DWORD)gain_cdbk) = v123 - v160;
      v124 = *(float *)((char *)v119 + (_DWORD)v145);
      v160 = v116[1] * v98 + *v119 * v99 + *(float *)((char *)tmp2 + (_DWORD)v119) * v115;
      *(float *)((char *)v119 + gain_cdbk_size) = v124 - v160;
      v125 = *(float *)((char *)v156 + (_DWORD)v118);
      v160 = v116[2] * v98 + v119[1] * v99 + *v118 * v115;
      v160 = v125 - v160;
      v126 = v160;
      *(float *)((char *)v118 + j) = v160;
      v127 = *(float *)((char *)v116 + (_DWORD)gain_cdbk);
      v128 = *(float *)((char *)v119 + gain_cdbk_size);
      v160 = *v120 * *v120 + pitch_control;
      v160 = v127 * v127 + v160;
      v160 = v128 * v128 + v160;
      v116 += 4;
      pitch_control = v126 * v126 + v160;
      v118 += 4;
      v120 += 4;
      v119 += 4;
      --LODWORD(v158);
      if ( v158 == 0.0 )
        break;
      v117 = g2;
    }
    result = LODWORD(gain_sum);
  }
  if ( result < nsf )
  {
    LODWORD(best_sum) = (char *)x[2] - (char *)tmp1;
    v129 = (char *)((char *)y - (char *)tmp1);
    v130 = (char *)((char *)x[1] - (char *)tmp1);
    v131 = (char *)v153 - (char *)tmp1;
    v132 = nsf - LODWORD(gain_sum);
    result = (int)&tmp1[result];
    v133 = (char *)((char *)x[2] - (char *)tmp1);
    do
    {
      v134 = *(float *)&v129[result];
      result += 4;
      --v132;
      v160 = *(float *)&v130[result - 4] * v99 + v98 * *(float *)(result - 4) + *(float *)&v133[result - 4] * v115;
      v160 = v134 - v160;
      v135 = v160;
      *(float *)(v131 + result - 4) = v160;
      pitch_control = v135 * v135 + pitch_control;
    }
    while ( v132 );
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9C92C0
void __cdecl pitch_unquant_3tap(
        float *exc,
        int start,
        int end,
        float pitch_coef,
        const void *par,
        int nsf,
        int *pitch_val,
        float *gain_val,
        SpeexBits *bits,
        char *stack,
        int count_lost,
        int subframe_offset,
        float last_pitch_gain,
        int cdbk_offset)
{
  int v14; // ebx
  signed int v15; // edi
  unsigned int v16; // eax
  const char *v17; // edx
  int v18; // ecx
  const char *v19; // eax
  int v20; // edx
  int v21; // eax
  double v22; // st6
  double v23; // st6
  double v24; // st5
  double v25; // st4
  double v26; // st2
  double v27; // st1
  double v28; // st6
  double v29; // rt1
  double v30; // st4
  double v31; // st5
  int v32; // esi
  double v33; // rt2
  double v34; // st4
  double v35; // st6
  int v36; // edx
  int v37; // ecx
  int v38; // edi
  float *v39; // eax
  float *v40; // edx
  float *v41; // eax
  unsigned int v42; // esi
  float *v43; // esi
  int v44; // eax
  float *v45; // edi
  double v46; // st3
  int v47; // edi
  float *v48; // esi
  unsigned int v49; // eax
  float *v50; // edx
  float *v51; // esi
  int v52; // eax
  float *v53; // ecx
  double v54; // st3
  float *v55; // ecx
  unsigned int v56; // eax
  int v57; // esi
  float *v58; // eax
  float *v59; // edx
  float *v60; // ecx
  double v61; // st3
  int v62; // ecx
  int v63; // edx
  float *v64; // eax
  int v65; // ebx
  int v66; // esi
  double v67; // st3
  int v68; // [esp+10h] [ebp-30h]
  int pitch; // [esp+14h] [ebp-2Ch]
  const char *gain_cdbkb; // [esp+18h] [ebp-28h]
  const char *gain_cdbk; // [esp+18h] [ebp-28h]
  const char *gain_cdbka; // [esp+18h] [ebp-28h]
  float tmp2a; // [esp+1Ch] [ebp-24h]
  float *tmp2; // [esp+1Ch] [ebp-24h]
  int v75; // [esp+20h] [ebp-20h]
  int v76; // [esp+20h] [ebp-20h]
  int v77; // [esp+28h] [ebp-18h]
  float fact; // [esp+2Ch] [ebp-14h]
  float facta; // [esp+2Ch] [ebp-14h]
  float factd; // [esp+2Ch] [ebp-14h]
  float *factb; // [esp+2Ch] [ebp-14h]
  int factc; // [esp+2Ch] [ebp-14h]
  float *e[3]; // [esp+30h] [ebp-10h]

  v14 = nsf;
  gain_cdbkb = (const char *)(*(_DWORD *)par + 3 * cdbk_offset * (1 << *((_DWORD *)par + 1)));
  v15 = start + speex_bits_unpack_unsigned(bits, *((_DWORD *)par + 2));
  pitch = v15;
  v16 = speex_bits_unpack_unsigned(bits, *((_DWORD *)par + 1));
  v17 = &gain_cdbkb[2 * v16];
  v18 = v17[v16];
  v19 = &v17[v16];
  v20 = v19[1];
  v21 = v19[2];
  *(float *)e = (double)v18 * 0.015625 + 0.5;
  *(float *)&e[1] = (double)v20 * 0.015625 + 0.5;
  *(float *)&e[2] = 0.015625 * (double)v21 + 0.5;
  if ( count_lost && v15 > subframe_offset )
  {
    v22 = last_pitch_gain;
    if ( count_lost >= 4 )
      v22 = v22 * 0.4;
    tmp2a = v22;
    v23 = tmp2a;
    if ( tmp2a > 0.95 )
      v23 = (float)0.94999999;
    v24 = *(float *)&e[1];
    if ( *(float *)&e[1] >= 0.0 )
      fact = *(float *)&e[1];
    else
      fact = -v24;
    v25 = *(float *)e;
    v26 = *(float *)e;
    if ( *(float *)e <= 0.0 )
      v26 = v26 * -0.5;
    v27 = *(float *)&e[2];
    if ( *(float *)&e[2] <= 0.0 )
      v27 = -0.5 * v27;
    facta = v26 + fact + v27;
    if ( facta <= v23 )
    {
      v28 = *(float *)&e[2];
      goto LABEL_18;
    }
    factd = v23 / facta;
    *(float *)e = v25 * factd;
    *(float *)&e[1] = v24 * factd;
    *(float *)&e[2] = *(float *)&e[2] * factd;
  }
  v28 = *(float *)&e[2];
  v24 = *(float *)&e[1];
  v25 = *(float *)e;
LABEL_18:
  *pitch_val = v15;
  *gain_val = v25;
  v29 = v25;
  v30 = v24;
  v31 = v29;
  gain_val[1] = v30;
  v32 = v15 + 1;
  v33 = v30;
  v34 = v28;
  v35 = v33;
  v75 = v15 + 1;
  gain_val[2] = v34;
  tmp2 = (float *)&stack[-(int)stack & 3];
  e[0] = tmp2;
  e[2] = &tmp2[2 * nsf];
  e[1] = &tmp2[nsf];
  v36 = 0;
  gain_cdbk = 0;
  factb = &exc[-v15 + 1];
  do
  {
    v37 = nsf;
    if ( nsf > v32 )
      v37 = v32;
    v38 = 0;
    if ( v37 >= 4 )
    {
      v39 = e[v36];
      v40 = factb;
      v41 = v39 + 2;
      v42 = ((unsigned int)(v37 - 4) >> 2) + 1;
      v38 = 4 * v42;
      do
      {
        v41 += 4;
        *(v41 - 6) = *(v40 - 2);
        v40 += 4;
        --v42;
        *(v41 - 5) = *(v40 - 5);
        *(v41 - 4) = *(v40 - 4);
        *(v41 - 3) = *(v40 - 3);
      }
      while ( v42 );
      v32 = v75;
      v36 = (int)gain_cdbk;
    }
    if ( v38 < v37 )
    {
      v43 = &exc[v38 - v32];
      v44 = v37 - v38;
      v45 = &e[v36][v38];
      do
      {
        v46 = *v43++;
        *v45++ = v46;
        --v44;
      }
      while ( v44 );
      v32 = v75;
    }
    v47 = nsf;
    if ( nsf > v32 + pitch )
      v47 = v32 + pitch;
    if ( v37 < v47 )
    {
      if ( v47 - v37 >= 4 )
      {
        v48 = &exc[v37 - v32 - pitch + 2];
        v49 = ((unsigned int)(v47 - v37 - 4) >> 2) + 1;
        v50 = &e[v36][v37 + 2];
        v37 += 4 * v49;
        do
        {
          v50 += 4;
          *(v50 - 6) = *(v48 - 2);
          v48 += 4;
          --v49;
          *(v50 - 5) = *(v48 - 5);
          *(v50 - 4) = *(v48 - 4);
          *(v50 - 3) = *(v48 - 3);
        }
        while ( v49 );
        v32 = v75;
        v36 = (int)gain_cdbk;
      }
      if ( v37 < v47 )
      {
        v51 = &exc[v37 - v32 - pitch];
        v52 = v47 - v37;
        v53 = &e[v36][v37];
        do
        {
          v54 = *v51++;
          *v53++ = v54;
          --v52;
        }
        while ( v52 );
        v32 = v75;
      }
    }
    if ( v47 < nsf )
    {
      if ( nsf - v47 >= 4 )
      {
        v55 = &e[v36][v47 + 2];
        v56 = ((unsigned int)(nsf - v47 - 4) >> 2) + 1;
        v47 += 4 * v56;
        do
        {
          v55 += 4;
          --v56;
          *(v55 - 6) = 0.0;
          *(v55 - 5) = 0.0;
          *(v55 - 4) = 0.0;
          *(v55 - 3) = 0.0;
        }
        while ( v56 );
      }
      if ( v47 < nsf )
        memset(&e[v36][v47], 0, 4 * (nsf - v47));
    }
    ++factb;
    ++v36;
    --v32;
    gain_cdbk = (const char *)v36;
    v75 = v32;
  }
  while ( v36 < 3 );
  v57 = 0;
  if ( nsf >= 4 )
  {
    v77 = (char *)e[2] - (char *)e[1];
    factc = (char *)tmp2 - (char *)e[1];
    v58 = e[1] + 1;
    v68 = (char *)exc - (char *)e[1];
    gain_cdbka = (const char *)((char *)e[2] - (char *)tmp2);
    v14 = nsf;
    v59 = exc + 3;
    v60 = tmp2 + 2;
    v76 = (char *)e[2] - (char *)exc;
    do
    {
      v61 = e[2][v57] * v31;
      v57 += 4;
      v58 += 4;
      v60 += 4;
      v59 += 4;
      *(v59 - 7) = v61 + 1.0e-15 + *(v58 - 5) * v35 + *(v60 - 6) * v34;
      *(float *)((char *)v58 + v68 - 16) = *(float *)((char *)v58 + v77 - 16) * v31
                                         + 1.0e-15
                                         + *(v58 - 4) * v35
                                         + *(float *)((char *)v58 + factc - 16) * v34;
      *(float *)((char *)v60 + (char *)exc - (char *)tmp2 - 16) = *(float *)((char *)v60 + (_DWORD)gain_cdbka - 16)
                                                                * v31
                                                                + 1.0e-15
                                                                + *(v58 - 3) * v35
                                                                + v34 * *(v60 - 4);
      *(v59 - 4) = *(float *)((char *)v59 + v76 - 16) * v31 + 1.0e-15 + *(v58 - 2) * v35 + *(v60 - 3) * v34;
    }
    while ( v57 < nsf - 3 );
  }
  if ( v57 < v14 )
  {
    v62 = (char *)e[2] - (char *)e[1];
    v63 = (char *)exc - (char *)e[1];
    v64 = &e[1][v57];
    v65 = v14 - v57;
    v66 = (char *)tmp2 - (char *)e[1];
    do
    {
      v67 = *(float *)((char *)v64++ + v62);
      --v65;
      *(float *)((char *)v64 + v63 - 4) = v67 * v31
                                        + 1.0e-15
                                        + *(v64 - 1) * v35
                                        + *(float *)((char *)v64 + v66 - 4) * v34;
    }
    while ( v65 );
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9C9760
int __cdecl forced_pitch_quant(
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
        int nsf)
{
  double v12; // st7
  int v13; // esi
  unsigned int v14; // edi
  float *v15; // ecx
  float *v16; // edx
  double v17; // st6
  float *v18; // ecx
  double v19; // st6

  if ( pitch_coef > 0.99 )
    pitch_coef = 0.99000001;
  v12 = pitch_coef;
  v13 = 0;
  if ( nsf >= 4 )
  {
    v14 = ((unsigned int)(nsf - 4) >> 2) + 1;
    v15 = exc + 2;
    v16 = &exc[2 - start];
    v13 = 4 * v14;
    do
    {
      v15 += 4;
      v17 = *(v16 - 2) * v12;
      v16 += 4;
      --v14;
      *(v15 - 6) = v17;
      *(v15 - 5) = *(v16 - 5) * v12;
      *(v15 - 4) = v12 * *(v16 - 4);
      *(v15 - 3) = *(v16 - 3) * v12;
    }
    while ( v14 );
  }
  if ( v13 >= nsf )
    return start;
  v18 = &exc[v13 - start];
  do
  {
    ++v13;
    v19 = v12 * *v18++;
    exc[v13 - 1] = v19;
  }
  while ( v13 < nsf );
  return start;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9C9810
void __cdecl forced_pitch_unquant(
        float *exc,
        int start,
        int end,
        float pitch_coef,
        const void *par,
        int nsf,
        int *pitch_val,
        float *gain_val)
{
  double v8; // st7
  double v9; // st6
  int v10; // edx
  unsigned int v11; // esi
  float *v12; // eax
  float *v13; // ecx
  double v14; // st5
  float *v15; // eax
  double v16; // st5

  v8 = pitch_coef;
  if ( pitch_coef > 0.99 )
    pitch_coef = 0.99000001;
  v9 = pitch_coef;
  v10 = 0;
  if ( nsf >= 4 )
  {
    v11 = ((unsigned int)(nsf - 4) >> 2) + 1;
    v12 = exc + 2;
    v13 = &exc[2 - start];
    v10 = 4 * v11;
    do
    {
      v12 += 4;
      v14 = *(v13 - 2) * v9;
      v13 += 4;
      --v11;
      *(v12 - 6) = v14;
      *(v12 - 5) = *(v13 - 5) * v9;
      *(v12 - 4) = v9 * *(v13 - 4);
      *(v12 - 3) = *(v13 - 3) * v9;
    }
    while ( v11 );
  }
  if ( v10 < nsf )
  {
    v15 = &exc[v10 - start];
    do
    {
      ++v10;
      v16 = v9 * *v15++;
      exc[v10 - 1] = v16;
    }
    while ( v10 < nsf );
  }
  *pitch_val = start;
  gain_val[2] = 0.0;
  *gain_val = 0.0;
  gain_val[1] = v8;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9C98C0
void __cdecl bw_lpc(float gamma, const float *lpc_in, float *lpc_out, int order)
{
  double v4; // st7
  float *v5; // edx
  int v6; // ebx
  const float *v7; // edi
  float *v8; // eax
  const float *v9; // ecx
  unsigned int v10; // edx
  double v11; // st6
  float *v12; // eax
  int v13; // esi
  double v14; // st6
  float tmp; // [esp+8h] [ebp+8h]
  float tmpa; // [esp+8h] [ebp+8h]
  float tmpb; // [esp+8h] [ebp+8h]

  v4 = gamma;
  v5 = lpc_out;
  v6 = 0;
  v7 = lpc_in;
  if ( order >= 4 )
  {
    v8 = lpc_out + 1;
    v9 = lpc_in + 3;
    v10 = ((unsigned int)(order - 4) >> 2) + 1;
    v6 = 4 * v10;
    do
    {
      v11 = *(v9 - 3);
      v8 += 4;
      v9 += 4;
      --v10;
      *(v8 - 5) = v11 * gamma;
      tmp = gamma * v4;
      *(v8 - 4) = *(float *)((char *)v8 + (char *)lpc_in - (char *)lpc_out - 16) * tmp;
      tmpa = tmp * v4;
      *(v8 - 3) = *(v9 - 5) * tmpa;
      tmpb = tmpa * v4;
      *(v8 - 2) = *(v9 - 4) * tmpb;
      gamma = tmpb * v4;
    }
    while ( v10 );
    v5 = lpc_out;
    v7 = lpc_in;
  }
  if ( v6 < order )
  {
    v12 = &v5[v6];
    v13 = order - v6;
    do
    {
      v14 = *(float *)((char *)v12++ + (char *)v7 - (char *)v5);
      --v13;
      *(v12 - 1) = v14 * gamma;
      gamma = gamma * v4;
    }
    while ( v13 );
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9C9980
void __cdecl signal_mul(const float *x, float *y, float scale, int len)
{
  double v4; // st7
  float *v5; // edx
  int v6; // ebx
  const float *v7; // edi
  float *v8; // eax
  const float *v9; // ecx
  unsigned int v10; // edx
  double v11; // st6
  float *v12; // eax
  int v13; // esi
  double v14; // st6

  v4 = scale;
  v5 = y;
  v6 = 0;
  v7 = x;
  if ( len >= 4 )
  {
    v8 = y + 1;
    v9 = x + 3;
    v10 = ((unsigned int)(len - 4) >> 2) + 1;
    v6 = 4 * v10;
    do
    {
      v8 += 4;
      v11 = *(v9 - 3) * v4;
      v9 += 4;
      --v10;
      *(v8 - 5) = v11;
      *(v8 - 4) = *(float *)((char *)v8 + (char *)x - (char *)y - 16) * v4;
      *(v8 - 3) = *(v9 - 5) * v4;
      *(v8 - 2) = *(v9 - 4) * v4;
    }
    while ( v10 );
    v5 = y;
    v7 = x;
  }
  if ( v6 < len )
  {
    v12 = &v5[v6];
    v13 = len - v6;
    do
    {
      v14 = *(float *)((char *)v12++ + (char *)v7 - (char *)v5);
      --v13;
      *(v12 - 1) = v14 * v4;
    }
    while ( v13 );
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9C9A10
void __cdecl signal_div(const float *x, float *y, float scale, int len)
{
  float *v4; // edx
  int v5; // ebx
  const float *v6; // edi
  double v7; // st7
  float *v8; // eax
  const float *v9; // ecx
  unsigned int v10; // edx
  double v11; // st6
  float *v12; // eax
  int v13; // esi
  double v14; // st6
  float scale_1; // [esp+10h] [ebp+10h]

  v4 = y;
  v5 = 0;
  v6 = x;
  scale_1 = 1.0 / scale;
  v7 = scale_1;
  if ( len >= 4 )
  {
    v8 = y + 1;
    v9 = x + 3;
    v10 = ((unsigned int)(len - 4) >> 2) + 1;
    v5 = 4 * v10;
    do
    {
      v8 += 4;
      v11 = *(v9 - 3) * v7;
      v9 += 4;
      --v10;
      *(v8 - 5) = v11;
      *(v8 - 4) = *(float *)((char *)v8 + (char *)x - (char *)y - 16) * v7;
      *(v8 - 3) = *(v9 - 5) * v7;
      *(v8 - 2) = *(v9 - 4) * v7;
    }
    while ( v10 );
    v4 = y;
    v6 = x;
  }
  if ( v5 < len )
  {
    v12 = &v4[v5];
    v13 = len - v5;
    do
    {
      v14 = *(float *)((char *)v12++ + (char *)v6 - (char *)v4);
      --v13;
      *(v12 - 1) = v14 * v7;
    }
    while ( v13 );
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9C9AA0
double __cdecl compute_rms(const float *x, int len)
{
  int v2; // edx
  unsigned int v3; // ecx
  const float *v4; // eax
  double v5; // st7
  double v6; // st7
  float sum; // [esp+4h] [ebp-4h]
  float suma; // [esp+4h] [ebp-4h]
  float sumb; // [esp+4h] [ebp-4h]
  float sumc; // [esp+4h] [ebp-4h]

  sum = 0.0;
  v2 = 0;
  if ( len >= 4 )
  {
    v3 = ((unsigned int)(len - 4) >> 2) + 1;
    v4 = x + 2;
    v2 = 4 * v3;
    do
    {
      v5 = *(v4 - 2);
      v4 += 4;
      --v3;
      suma = v5 * v5 + sum;
      sumb = *(v4 - 5) * *(v4 - 5) + suma;
      sumc = *(v4 - 4) * *(v4 - 4) + sumb;
      sum = *(v4 - 3) * *(v4 - 3) + sumc;
    }
    while ( v3 );
  }
  for ( ; v2 < len; sum = v6 * v6 + sum )
    v6 = x[v2++];
  return (float)sqrt(sum / (double)len + 0.1);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9C9B50
void __cdecl filter_mem2(const float *x, const float *num, const float *den, float *y, int N, int ord, float *mem)
{
  int v7; // eax
  float *v8; // esi
  int v9; // edi
  double v10; // st7
  float *v11; // esi
  int v12; // edx
  double v13; // st7
  double v14; // st6
  double v15; // st5
  const float *v16; // ecx
  int v17; // edi
  float *v18; // eax
  double v19; // st4
  float *v20; // esi
  float *v21; // eax
  int v22; // ecx
  float *v23; // edx
  double v24; // st4
  bool v25; // zf
  int v26; // [esp+0h] [ebp-10h]
  int v27; // [esp+0h] [ebp-10h]
  int v28; // [esp+8h] [ebp-8h]
  float *v29; // [esp+Ch] [ebp-4h]
  float nyi; // [esp+28h] [ebp+18h]
  float nyia; // [esp+28h] [ebp+18h]
  float nyib; // [esp+28h] [ebp+18h]

  if ( N > 0 )
  {
    v7 = ord;
    v8 = y;
    v9 = (char *)x - (char *)y;
    v29 = y;
    v28 = N;
    while ( 1 )
    {
      v10 = *(float *)((char *)v8 + v9);
      v11 = mem;
      nyi = v10;
      v12 = 0;
      v13 = nyi;
      nyia = *mem + nyi;
      v14 = nyia;
      nyib = -nyia;
      v15 = nyib;
      if ( v7 - 1 >= 4 )
      {
        v26 = v7 - 4;
        v16 = den + 2;
        v17 = (char *)num - (char *)den;
        v18 = mem + 1;
        do
        {
          v19 = num[v12] * v13;
          v20 = (float *)((char *)v18 + (char *)den - (char *)mem);
          v12 += 4;
          v18 += 4;
          v16 += 4;
          *(v18 - 5) = v19 + *(v18 - 4) + *(v16 - 6) * v15;
          *(v18 - 4) = *(float *)((char *)v20 + v17) * v13 + *(v18 - 3) + v15 * *v20;
          *(v18 - 3) = *(const float *)((char *)v16 + v17 - 16) * v13 + *(v18 - 2) + *(v16 - 4) * v15;
          *(v18 - 2) = num[v12 - 1] * v13 + *(v18 - 1) + *(v16 - 3) * v15;
        }
        while ( v12 < v26 );
        v7 = ord;
        v11 = mem;
      }
      v27 = v7 - 1;
      if ( v12 < v7 - 1 )
      {
        v21 = &v11[v12];
        v22 = v27 - v12;
        do
        {
          v23 = (float *)((char *)v21 + (char *)den - (char *)v11);
          v24 = *(const float *)((char *)num + (char *)v21++ - (char *)v11);
          --v22;
          *(v21 - 1) = v24 * v13 + *v21 + *v23 * v15;
        }
        while ( v22 );
        v7 = ord;
      }
      v11[v7 - 1] = v13 * num[v7 - 1] - v14 * den[v7 - 1];
      v8 = v29 + 1;
      v25 = v28-- == 1;
      *v29++ = v14;
      if ( v25 )
        break;
      v9 = (char *)x - (char *)y;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9C9CA0
void __cdecl iir_mem2(const float *x, const float *den, float *y, int N, int ord, float *mem)
{
  int v7; // eax
  const float *v8; // edi
  double v9; // st7
  int v10; // eax
  int v11; // ebx
  double v12; // st7
  double v13; // st6
  const float *v14; // ecx
  int v15; // edi
  unsigned int v16; // edx
  float *v17; // eax
  double v18; // st5
  int v19; // ecx
  float *v20; // eax
  int v21; // ecx
  double v22; // st5
  bool v23; // zf
  float nyi; // [esp+0h] [ebp-Ch]
  float nyia; // [esp+0h] [ebp-Ch]
  int v26; // [esp+8h] [ebp-4h]
  float *Na; // [esp+20h] [ebp+14h]

  if ( N > 0 )
  {
    v7 = (char *)x - (char *)y;
    v8 = den;
    Na = y;
    v26 = N;
    while ( 1 )
    {
      v9 = *(float *)((char *)Na + v7);
      v10 = ord;
      v11 = 0;
      nyi = v9 + *mem;
      v12 = nyi;
      nyia = -nyi;
      v13 = nyia;
      if ( ord - 1 >= 4 )
      {
        v14 = v8 + 3;
        v15 = (char *)v8 - (char *)mem;
        v16 = ((unsigned int)(ord - 5) >> 2) + 1;
        v17 = mem + 1;
        v11 = 4 * v16;
        do
        {
          v17 += 4;
          v18 = *(v14 - 3) * v13;
          v14 += 4;
          --v16;
          *(v17 - 5) = v18 + *(v17 - 4);
          *(v17 - 4) = *(float *)((char *)v17 + v15 - 16) * v13 + *(v17 - 3);
          *(v17 - 3) = *(v14 - 5) * v13 + *(v17 - 2);
          *(v17 - 2) = *(v14 - 4) * v13 + *(v17 - 1);
        }
        while ( v16 );
        v8 = den;
        v10 = ord;
      }
      v19 = v10 - 1;
      if ( v11 < v10 - 1 )
      {
        v20 = &mem[v11];
        v21 = v19 - v11;
        do
        {
          v22 = *(float *)((char *)v20++ + (char *)v8 - (char *)mem);
          --v21;
          *(v20 - 1) = v22 * v13 + *v20;
        }
        while ( v21 );
        v10 = ord;
      }
      mem[v10 - 1] = v13 * v8[v10 - 1];
      v23 = v26-- == 1;
      *Na++ = v12;
      if ( v23 )
        break;
      v7 = (char *)x - (char *)y;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9C9DA0
void __cdecl fir_mem2(const float *x, const float *num, float *y, int N, int ord, float *mem)
{
  int v7; // eax
  const float *v8; // edi
  double v9; // st7
  int v10; // eax
  int v11; // ebx
  double v12; // st7
  const float *v13; // ecx
  int v14; // edi
  unsigned int v15; // edx
  float *v16; // eax
  double v17; // st6
  int v18; // ecx
  float *v19; // eax
  int v20; // ecx
  double v21; // st6
  bool v22; // zf
  float yia; // [esp+0h] [ebp-Ch]
  float yi; // [esp+0h] [ebp-Ch]
  int v25; // [esp+8h] [ebp-4h]
  float *Na; // [esp+20h] [ebp+14h]

  if ( N > 0 )
  {
    v7 = (char *)x - (char *)y;
    v8 = num;
    Na = y;
    v25 = N;
    while ( 1 )
    {
      v9 = *(float *)((char *)Na + v7);
      v10 = ord;
      yia = v9;
      v11 = 0;
      v12 = yia;
      yi = *mem + yia;
      if ( ord - 1 >= 4 )
      {
        v13 = v8 + 3;
        v14 = (char *)v8 - (char *)mem;
        v15 = ((unsigned int)(ord - 5) >> 2) + 1;
        v16 = mem + 1;
        v11 = 4 * v15;
        do
        {
          v16 += 4;
          v17 = *(v13 - 3) * v12;
          v13 += 4;
          --v15;
          *(v16 - 5) = v17 + *(v16 - 4);
          *(v16 - 4) = *(float *)((char *)v16 + v14 - 16) * v12 + *(v16 - 3);
          *(v16 - 3) = *(v13 - 5) * v12 + *(v16 - 2);
          *(v16 - 2) = *(v13 - 4) * v12 + *(v16 - 1);
        }
        while ( v15 );
        v8 = num;
        v10 = ord;
      }
      v18 = v10 - 1;
      if ( v11 < v10 - 1 )
      {
        v19 = &mem[v11];
        v20 = v18 - v11;
        do
        {
          v21 = *(float *)((char *)v19++ + (char *)v8 - (char *)mem);
          --v20;
          *(v19 - 1) = v21 * v12 + *v19;
        }
        while ( v20 );
        v10 = ord;
      }
      mem[v10 - 1] = v12 * v8[v10 - 1];
      v22 = v25-- == 1;
      *Na++ = yi;
      if ( v22 )
        break;
      v7 = (char *)x - (char *)y;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9C9EA0
void __cdecl syn_percep_zero(
        const float *xx,
        const float *ak,
        const float *awk1,
        const float *awk2,
        float *y,
        int N,
        int ord,
        char *stack)
{
  char *v8; // esi
  float *v9; // edi

  v8 = &stack[-(int)stack & 3];
  if ( ord > 0 )
    memset(v8, 0, 4 * ord);
  v9 = y;
  iir_mem2(xx, ak, y, N, ord, (float *)v8);
  if ( ord > 0 )
  {
    memset(v8, 0, 4 * ord);
    v9 = y;
  }
  filter_mem2(v9, awk1, awk2, v9, N, ord, (float *)v8);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9C9F10
void __cdecl residue_percep_zero(
        const float *xx,
        const float *ak,
        const float *awk1,
        const float *awk2,
        float *y,
        int N,
        int ord,
        char *stack)
{
  char *v8; // esi
  float *v9; // edi

  v8 = &stack[-(int)stack & 3];
  if ( ord > 0 )
    memset(v8, 0, 4 * ord);
  v9 = y;
  filter_mem2(xx, ak, awk1, y, N, ord, (float *)v8);
  if ( ord > 0 )
  {
    memset(v8, 0, 4 * ord);
    v9 = y;
  }
  fir_mem2(v9, awk2, v9, N, ord, (float *)v8);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9C9F80
void __cdecl compute_impulse_response(
        const float *ak,
        const float *awk1,
        const float *awk2,
        float *y,
        int N,
        int ord,
        char *stack)
{
  int v7; // ecx
  int v8; // eax
  float *v9; // esi
  float *v10; // ebx
  float *v11; // edx
  int v12; // edi
  const float *v13; // eax
  float *v14; // ecx
  int v15; // esi
  double v16; // st7
  bool v17; // zf
  int v18; // edi
  float *v19; // eax
  int v20; // eax
  int v21; // esi
  double v22; // st7
  double v23; // st6
  float *v24; // eax
  const float *v25; // edx
  float *v26; // ecx
  int v27; // ebx
  double v28; // st5
  float *v29; // edi
  double v30; // st5
  int v31; // ecx
  float *v32; // eax
  int v33; // edi
  double v34; // st5
  int v35; // [esp+Ch] [ebp-1Ch]
  float *mem1; // [esp+10h] [ebp-18h]
  char *v37; // [esp+14h] [ebp-14h]
  int i; // [esp+18h] [ebp-10h]
  float *ia; // [esp+18h] [ebp-10h]
  int ib; // [esp+18h] [ebp-10h]
  int ic; // [esp+18h] [ebp-10h]
  float ny1ia; // [esp+1Ch] [ebp-Ch]
  char *ny1i; // [esp+1Ch] [ebp-Ch]
  char *v44; // [esp+20h] [ebp-8h]
  int v45; // [esp+24h] [ebp-4h]
  float y1a; // [esp+44h] [ebp+1Ch]
  float y1b; // [esp+44h] [ebp+1Ch]
  float y1c; // [esp+44h] [ebp+1Ch]
  int y1; // [esp+44h] [ebp+1Ch]
  float *mem2; // [esp+48h] [ebp+20h]

  v7 = ord;
  v8 = (int)&stack[4 * ord + (-(int)stack & 3)];
  v9 = y;
  v35 = ord;
  *y = 1.0;
  v10 = (float *)(v8 - 4 * ord);
  v11 = (float *)(v8 + (-v8 & 3));
  v12 = 0;
  mem1 = v10;
  mem2 = v11;
  if ( ord >= 4 )
  {
    v13 = awk1 + 1;
    v14 = y + 3;
    v15 = (char *)y - (char *)awk1;
    i = ((unsigned int)(ord - 4) >> 2) + 1;
    v12 = 4 * i;
    while ( 1 )
    {
      v16 = *(v13 - 1);
      v13 += 4;
      *(float *)((char *)v13 + v15 - 16) = v16;
      v14 += 4;
      v17 = i-- == 1;
      *(v14 - 5) = *(v13 - 4);
      *(v14 - 4) = *(v13 - 3);
      *(v14 - 3) = *(v13 - 2);
      if ( v17 )
        break;
      v15 = (char *)y - (char *)awk1;
    }
    v9 = y;
    v7 = ord;
  }
  if ( v12 < v7 )
  {
    ia = &v9[v12 + 1];
    do
      *ia++ = awk1[v12++];
    while ( v12 < v7 );
  }
  v18 = v12 + 1;
  if ( v18 < N )
  {
    memset32(&v9[v18], 646978941, N - v18);
    v7 = ord;
  }
  if ( v7 > 0 )
  {
    v19 = v10;
    ib = v7;
    do
    {
      *(float *)((char *)v19++ + (char *)v11 - (char *)v10) = 0.0;
      v17 = ib-- == 1;
      *(v19 - 1) = 0.0;
    }
    while ( !v17 );
  }
  v20 = 0;
  ic = 0;
  if ( N > 0 )
  {
    v45 = v7 - 1;
    while ( 1 )
    {
      y1a = v9[v20] + *v10;
      ny1ia = -y1a;
      y1b = y1a + *v11;
      v9[v20] = y1b;
      v21 = 0;
      y1c = -y1b;
      v22 = ny1ia;
      v23 = y1c;
      if ( v45 >= 4 )
      {
        v44 = (char *)((char *)awk2 - (char *)v10);
        ny1i = (char *)((char *)ak - (char *)v10);
        y1 = (char *)mem2 - (char *)v10;
        v24 = v10 + 1;
        v25 = ak + 3;
        v26 = mem2 + 2;
        v27 = (char *)awk2 - (char *)ak;
        v37 = (char *)((char *)ak - (char *)mem2);
        do
        {
          v28 = awk2[v21] * v22;
          v21 += 4;
          v24 += 4;
          v25 += 4;
          *(v24 - 5) = v28 + *(v24 - 4);
          *(v26 - 2) = *(v25 - 7) * v23 + *(float *)((char *)v24 + y1 - 16);
          *(v24 - 4) = *(float *)((char *)v24 + (_DWORD)v44 - 16) * v22 + *(v24 - 3);
          *(float *)((char *)v24 + y1 - 16) = *(float *)((char *)v24 + (_DWORD)ny1i - 16) * v23 + *v26;
          v29 = (float *)&v37[(_DWORD)v26];
          v30 = *(float *)&v37[(_DWORD)v26 + v27];
          v26 += 4;
          *(v24 - 3) = v30 * v22 + *(v24 - 2);
          *(v26 - 4) = *v29 * v23 + *(v26 - 3);
          *(v24 - 2) = *(const float *)((char *)v25 + v27 - 16) * v22 + *(v24 - 1);
          *(v26 - 3) = *(v25 - 4) * v23 + *(v26 - 2);
        }
        while ( v21 < v45 - 3 );
        v10 = mem1;
        v11 = mem2;
        v20 = ic;
      }
      if ( v21 < v45 )
      {
        v31 = (int)&v11[v21 + 1];
        v32 = &v10[v21];
        v33 = v45 - v21;
        do
        {
          v34 = *(float *)((char *)v32++ + (char *)awk2 - (char *)v10) * v22;
          v31 += 4;
          --v33;
          *(v32 - 1) = v34 + *(float *)((char *)v10 - (char *)mem2 + v31 - 4);
          *(float *)(v31 - 8) = *(float *)((char *)v32 + (char *)ak - (char *)v10 - 4) * v23 + *(float *)(v31 - 4);
        }
        while ( v33 );
        v11 = mem2;
        v20 = ic;
      }
      ic = ++v20;
      v10[v35 - 1] = v22 * awk2[v35 - 1];
      v11[v35 - 1] = v23 * ak[v35 - 1];
      if ( v20 >= N )
        break;
      v9 = y;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9CA220
void __cdecl qmf_decomp(const float *xx, const float *aa, float *y1, float *y2, int N, int M, float *mem, char *stack)
{
  int v9; // ebx
  char *v10; // ecx
  float *v11; // ebx
  const float *v12; // esi
  int v13; // eax
  const float *v14; // esi
  float *v15; // edi
  bool v16; // zf
  float *v17; // edi
  double v18; // st7
  int v19; // esi
  signed int v20; // eax
  unsigned int v21; // esi
  char *v22; // eax
  float *v23; // edi
  float *v24; // esi
  int v25; // esi
  signed int v26; // eax
  const float *v27; // eax
  unsigned int v28; // esi
  int v29; // edi
  double v30; // st7
  float *v31; // edx
  double v32; // st7
  float *v33; // eax
  int v34; // edi
  unsigned int v35; // edx
  int v36; // ecx
  float *v37; // esi
  float *v38; // edx
  double v39; // st6
  double v40; // st6
  int v41; // edi
  float *v42; // eax
  unsigned int v43; // edx
  const float *v44; // ecx
  float *v45; // esi
  int v46; // [esp+Ch] [ebp-10h]
  float *a; // [esp+10h] [ebp-Ch]
  int M2; // [esp+14h] [ebp-8h]
  float *x2; // [esp+18h] [ebp-4h]
  float *x2a; // [esp+18h] [ebp-4h]
  int i; // [esp+38h] [ebp+1Ch]
  int ia; // [esp+38h] [ebp+1Ch]
  int stacka; // [esp+40h] [ebp+24h]

  v9 = (int)&stack[4 * M + (-(int)stack & 3)];
  v10 = (char *)(v9 + (-v9 & 3));
  x2 = (float *)&v10[4 * M - 4];
  v11 = (float *)(v9 - 4 * M);
  v12 = aa;
  M2 = M >> 1;
  v13 = 0;
  a = v11;
  if ( M >= 4 )
  {
    i = ((unsigned int)(M - 4) >> 2) + 1;
    v14 = aa + 2;
    v15 = &v11[M - 2];
    v13 = 4 * i;
    do
    {
      v15 -= 4;
      v15[5] = *(v14 - 2);
      v14 += 4;
      v16 = i-- == 1;
      v15[4] = *(v14 - 5);
      v15[3] = *(v14 - 4);
      v15[2] = *(v14 - 3);
    }
    while ( !v16 );
    v12 = aa;
  }
  if ( v13 < M )
  {
    v17 = &v11[M - v13 - 1];
    do
    {
      v18 = v12[v13++];
      *v17-- = v18;
    }
    while ( v13 < M );
  }
  v19 = M - 1;
  v20 = 0;
  stacka = M - 1;
  if ( M - 1 >= 4 )
  {
    v21 = ((unsigned int)(M - 5) >> 2) + 1;
    v22 = v10 + 8;
    v23 = &mem[M - 3];
    do
    {
      v22 += 16;
      *((float *)v22 - 6) = v23[1];
      v23 -= 4;
      --v21;
      *((float *)v22 - 5) = v23[4];
      *((float *)v22 - 4) = v23[3];
      *((float *)v22 - 3) = v23[2];
    }
    while ( v21 );
    v20 = 4 * (((unsigned int)(M - 5) >> 2) + 1);
    v19 = M - 1;
  }
  if ( v20 < v19 )
  {
    v24 = &mem[M - v20 - 2];
    do
    {
      ++v20;
      *(float *)&v10[4 * v20 - 4] = *v24--;
    }
    while ( v20 < stacka );
  }
  v25 = N;
  v26 = 0;
  if ( N >= 4 )
  {
    v27 = xx + 2;
    v28 = ((unsigned int)(N - 4) >> 2) + 1;
    v29 = (int)&v10[4 * M + 4];
    do
    {
      v30 = *(v27 - 2);
      v27 += 4;
      *(float *)(v29 - 8) = v30;
      v29 += 16;
      --v28;
      *(float *)(v29 - 20) = *(v27 - 5);
      *(float *)(v29 - 16) = *(v27 - 4);
      *(float *)(v29 - 12) = *(v27 - 3);
    }
    while ( v28 );
    v25 = N;
    v26 = 4 * (((unsigned int)(N - 4) >> 2) + 1);
  }
  if ( v26 < v25 )
  {
    v31 = (float *)&v10[4 * v26 - 4 + 4 * M];
    do
    {
      v32 = xx[v26++];
      *v31++ = v32;
    }
    while ( v26 < v25 );
  }
  if ( v25 > 0 )
  {
    ia = (int)x2;
    v33 = y2;
    v34 = (char *)y1 - (char *)y2;
    v35 = ((unsigned int)(v25 - 1) >> 1) + 1;
    v46 = v10 - (char *)x2;
    x2a = (float *)v35;
    do
    {
      v36 = 0;
      *(float *)((char *)v33 + v34) = 0.0;
      *v33 = 0.0;
      if ( M2 > 0 )
      {
        v37 = (float *)(v46 + ia);
        v38 = (float *)ia;
        do
        {
          v36 += 2;
          v39 = *v38 + *v37;
          v38 -= 2;
          v37 += 2;
          *(float *)((char *)v33 + v34) = v39 * v11[v36 - 2] + *(float *)((char *)v33 + v34);
          *v33 = *v33 - (*(v37 - 2) - v38[2]) * v11[v36 - 2];
          *(float *)((char *)v33 + v34) = (v38[1] + *(v37 - 1)) * v11[v36 - 1] + *(float *)((char *)v33 + v34);
          v40 = (*(v37 - 1) - v38[1]) * v11[v36 - 1];
          v11 = a;
          *v33 = v40 + *v33;
        }
        while ( v36 < M2 );
        v25 = N;
        v35 = (unsigned int)x2a;
      }
      ia += 8;
      ++v33;
      x2a = (float *)--v35;
    }
    while ( v35 );
  }
  v41 = 0;
  if ( stacka >= 4 )
  {
    v42 = mem + 2;
    v43 = ((unsigned int)(stacka - 4) >> 2) + 1;
    v44 = &xx[v25 - 2];
    v41 = 4 * v43;
    do
    {
      v42 += 4;
      *(v42 - 6) = v44[1];
      v44 -= 4;
      --v43;
      *(v42 - 5) = v44[4];
      *(v42 - 4) = v44[3];
      *(v42 - 3) = v44[2];
    }
    while ( v43 );
  }
  if ( v41 < stacka )
  {
    v45 = (float *)&xx[v25 - v41 - 1];
    do
      mem[v41++] = *v45--;
    while ( v41 < stacka );
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9CA4B0
void __cdecl fir_mem_up(const float *x, const float *a, float *y, int N, int M, float *mem, char *stack)
{
  int v7; // ecx
  char *v8; // edi
  const float *v9; // edx
  int v10; // eax
  int v11; // esi
  unsigned int v12; // edx
  float *v13; // ecx
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  float *v18; // edx
  int v19; // ebx
  float *v20; // edx
  float *v21; // esi
  unsigned int v22; // eax
  double v23; // st7
  float *v24; // ebx
  unsigned int v25; // eax
  char *v26; // esi
  double v27; // st6
  const float *v28; // eax
  char *v29; // edx
  unsigned int v30; // ecx
  double v31; // st5
  double v32; // st5
  double v33; // st6
  double v34; // st4
  int v35; // eax
  float *v36; // edx
  double v37; // st7
  unsigned int v38; // [esp+10h] [ebp-18h]
  float a1; // [esp+14h] [ebp-14h]
  float a1a; // [esp+14h] [ebp-14h]
  float x1; // [esp+18h] [ebp-10h]
  float x1a; // [esp+18h] [ebp-10h]
  float *a0; // [esp+1Ch] [ebp-Ch]
  float a0a; // [esp+1Ch] [ebp-Ch]
  float a0b; // [esp+1Ch] [ebp-Ch]
  float *y3; // [esp+20h] [ebp-8h]
  float y3a; // [esp+20h] [ebp-8h]
  float y3b; // [esp+20h] [ebp-8h]
  float *y2; // [esp+24h] [ebp-4h]
  float y2a; // [esp+24h] [ebp-4h]
  float y2b; // [esp+24h] [ebp-4h]
  float y0; // [esp+3Ch] [ebp+14h]
  float y0a; // [esp+3Ch] [ebp+14h]
  float *y1; // [esp+48h] [ebp+20h]
  float y1a; // [esp+48h] [ebp+20h]
  float y1b; // [esp+48h] [ebp+20h]

  v7 = N;
  v8 = &stack[-(int)stack & 3];
  v9 = x;
  v10 = N / 2;
  v11 = 0;
  if ( N / 2 >= 4 )
  {
    a0 = (float *)&x[v10 - 4];
    y2 = (float *)&x[v10 - 3];
    y1 = (float *)&x[v10 - 1];
    v12 = ((unsigned int)(v10 - 4) >> 2) + 1;
    y3 = (float *)&x[v10 - 2];
    v13 = (float *)(v8 + 16);
    v11 = 4 * v12;
    do
    {
      v14 = *y1;
      y1 -= 4;
      *(v13 - 4) = v14;
      v15 = *y3;
      y3 -= 4;
      *(v13 - 2) = v15;
      v16 = *y2;
      y2 -= 4;
      *v13 = v16;
      v17 = *a0;
      a0 -= 4;
      v13[2] = v17;
      v13 += 8;
      --v12;
    }
    while ( v12 );
    v7 = N;
    v9 = x;
  }
  if ( v11 < v10 )
  {
    v18 = (float *)&v9[v10 - v11 - 1];
    do
    {
      ++v11;
      *(float *)&v8[8 * v11 - 8] = *v18--;
    }
    while ( v11 < v10 );
  }
  v19 = M - 1;
  if ( M - 1 > 0 )
  {
    v20 = mem + 1;
    v21 = (float *)&v8[4 * v7];
    v22 = ((unsigned int)(M - 2) >> 1) + 1;
    do
    {
      v23 = *v20;
      v20 += 2;
      *v21 = v23;
      v21 += 2;
      --v22;
    }
    while ( v22 );
  }
  if ( v7 > 0 )
  {
    v24 = y + 2;
    v25 = ((unsigned int)(v7 - 1) >> 2) + 1;
    v26 = &v8[4 * v7];
    v38 = v25;
    do
    {
      y3a = 0.0;
      y2a = 0.0;
      y1a = 0.0;
      y0 = 0.0;
      if ( M > 0 )
      {
        v27 = *((float *)v26 - 4);
        v28 = a + 2;
        v29 = v26;
        v30 = ((unsigned int)(M - 1) >> 2) + 1;
        do
        {
          v31 = *(v28 - 2);
          v28 += 4;
          a0a = v31;
          v29 += 16;
          --v30;
          a1 = *(v28 - 5);
          x1 = *((float *)v29 - 6);
          y0a = x1 * a0a + y0;
          y1b = x1 * a1 + y1a;
          y2b = a0a * v27 + y2a;
          v32 = v27 * a1 + y3a;
          v33 = x1;
          y3b = v32;
          a0b = *(v28 - 4);
          a1a = *(v28 - 3);
          x1a = *((float *)v29 - 4);
          y0 = a0b * x1a + y0a;
          y1a = a1a * x1a + y1b;
          y2a = a0b * v33 + y2b;
          v34 = v33;
          v27 = x1a;
          y3a = a1a * v34 + y3b;
        }
        while ( v30 );
        v25 = v38;
      }
      v26 -= 16;
      *(v24 - 2) = y0;
      v24 += 4;
      --v25;
      *(v24 - 5) = y1a;
      v38 = v25;
      *(v24 - 4) = y2a;
      *(v24 - 3) = y3a;
    }
    while ( v25 );
    v19 = M - 1;
  }
  v35 = 0;
  if ( v19 > 0 )
  {
    v36 = mem + 1;
    do
    {
      v37 = *(float *)&v8[4 * v35];
      v35 += 2;
      *v36 = v37;
      v36 += 2;
    }
    while ( v35 < v19 );
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9CA6E0
void __cdecl comb_filter_mem_init(CombFilterMem *mem)
{
  mem->last_pitch_gain[2] = 0.0;
  mem->last_pitch = 0;
  mem->last_pitch_gain[1] = 0.0;
  mem->last_pitch_gain[0] = 0.0;
  mem->smooth_gain = 1.0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9CA700
void __cdecl comb_filter(
        float *exc,
        float *new_exc,
        float *ak,
        int p,
        int nsf,
        int pitch,
        float *pitch_gain,
        float comb_gain,
        CombFilterMem *mem)
{
  double v10; // st6
  double v11; // st5
  double v12; // st7
  double v13; // st4
  double v15; // st5
  double v16; // st3
  double v17; // st3
  double v18; // st4
  double v19; // st6
  double v20; // st3
  double v21; // rt0
  double v22; // st4
  double v23; // st7
  double v24; // st6
  int v25; // edx
  float *v26; // ebx
  double v27; // st6
  double v28; // st5
  double v29; // st4
  float *v30; // eax
  double v31; // st3
  double v32; // st4
  double v33; // st3
  double v34; // st4
  double v35; // st3
  double v36; // st4
  int v37; // ebx
  double v38; // st4
  double v39; // st3
  float *v40; // ebx
  double v41; // st3
  double v42; // st4
  double v43; // rtt
  double v44; // st3
  float *v45; // ebx
  int v46; // eax
  double v47; // st3
  double v48; // st4
  double v49; // rt0
  double v50; // st3
  double v51; // st7
  int v53; // ecx
  double v54; // st4
  unsigned int v55; // edx
  float *v56; // eax
  float v57; // [esp+Ch] [ebp-14h]
  float v58; // [esp+Ch] [ebp-14h]
  float v59; // [esp+Ch] [ebp-14h]
  float v60; // [esp+Ch] [ebp-14h]
  float v61; // [esp+Ch] [ebp-14h]
  float exc_energy; // [esp+10h] [ebp-10h]
  float v63; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  int ia; // [esp+18h] [ebp-8h]
  float *v66; // [esp+1Ch] [ebp-4h]
  float nsfa; // [esp+38h] [ebp+18h]
  float nsfb; // [esp+38h] [ebp+18h]
  float nsfc; // [esp+38h] [ebp+18h]
  float nsfd; // [esp+38h] [ebp+18h]
  float nsfe; // [esp+38h] [ebp+18h]
  float gain; // [esp+3Ch] [ebp+1Ch]
  float gaina; // [esp+3Ch] [ebp+1Ch]
  float g; // [esp+40h] [ebp+20h]
  float ga; // [esp+40h] [ebp+20h]
  float gb; // [esp+40h] [ebp+20h]
  float gc; // [esp+40h] [ebp+20h]
  float gd; // [esp+40h] [ebp+20h]
  float ge; // [esp+40h] [ebp+20h]
  float gf; // [esp+40h] [ebp+20h]
  float gg; // [esp+40h] [ebp+20h]
  float gh; // [esp+40h] [ebp+20h]
  float gi; // [esp+40h] [ebp+20h]
  float gj; // [esp+40h] [ebp+20h]
  float gk; // [esp+40h] [ebp+20h]
  float gl; // [esp+40h] [ebp+20h]
  float stepb; // [esp+48h] [ebp+28h]
  float *step; // [esp+48h] [ebp+28h]
  float *stepa; // [esp+48h] [ebp+28h]

  exc_energy = compute_rms(exc, nsf);
  v10 = pitch_gain[1];
  if ( v10 < 0.0 )
    v10 = -v10;
  v63 = v10;
  v11 = *pitch_gain;
  if ( v11 <= 0.0 )
    v11 = v11 * -0.5;
  v12 = v11;
  v13 = pitch_gain[2];
  if ( v13 <= 0.0 )
    v13 = v13 * -0.5;
  v15 = v13;
  v16 = mem->last_pitch_gain[1];
  if ( v16 < 0.0 )
    v16 = -v16;
  g = v16;
  v17 = mem->last_pitch_gain[0];
  if ( v17 <= 0.0 )
    v17 = v17 * -0.5;
  v18 = v17;
  if ( mem->last_pitch_gain[2] <= 0.0 )
  {
    v20 = -0.5 * mem->last_pitch_gain[2];
    v19 = 0.0;
  }
  else
  {
    v19 = 0.0;
    v20 = mem->last_pitch_gain[2];
  }
  v21 = v18 + g + v20;
  v22 = v12 + v63;
  v23 = v19;
  ga = (v21 + v15 + v22) * 0.5;
  v24 = ga;
  if ( ga > 1.3 )
    comb_gain = 1.3 / v24 * comb_gain;
  if ( v24 < 0.5 )
    comb_gain = (v24 + v24) * comb_gain;
  v25 = 0;
  v26 = new_exc;
  i = 0;
  stepb = 1.0 / (double)nsf;
  gb = v23;
  v27 = comb_gain;
  v28 = stepb;
  v29 = gb;
  if ( nsf >= 4 )
  {
    step = exc + 3;
    v66 = new_exc + 1;
    v30 = &exc[-pitch + 1];
    v25 = 0;
    do
    {
      gc = v29 + v28;
      v57 = exc[v25 - mem->last_pitch + 1] * mem->last_pitch_gain[0]
          + exc[v25 - mem->last_pitch] * mem->last_pitch_gain[1]
          + exc[v25 - mem->last_pitch - 1] * mem->last_pitch_gain[2];
      v31 = gc;
      v32 = v57 * (1.0 - gc);
      gd = *v30 * *pitch_gain + *(v30 - 1) * pitch_gain[1] + *(v30 - 2) * pitch_gain[2];
      *(v66 - 1) = (v32 + gd * v31) * v27 + *(step - 3);
      ge = v31 + v28;
      v58 = exc[v25 - mem->last_pitch + 2] * mem->last_pitch_gain[0]
          + exc[v25 - mem->last_pitch + 1] * mem->last_pitch_gain[1]
          + exc[v25 - mem->last_pitch] * mem->last_pitch_gain[2];
      v33 = ge;
      v34 = v58 * (1.0 - ge);
      gf = *v30 * pitch_gain[1] + *pitch_gain * v30[1] + pitch_gain[2] * *(v30 - 1);
      *v66 = (v34 + gf * v33) * v27 + *(float *)((char *)v66 + (char *)exc - (char *)new_exc);
      gg = v33 + v28;
      v30 += 4;
      v59 = exc[i - mem->last_pitch + 3] * mem->last_pitch_gain[0]
          + exc[i - mem->last_pitch + 2] * mem->last_pitch_gain[1]
          + exc[i - mem->last_pitch + 1] * mem->last_pitch_gain[2];
      v35 = gg;
      v36 = v59 * (1.0 - gg);
      gh = *pitch_gain * *(v30 - 2) + *(v30 - 3) * pitch_gain[1] + *(v30 - 4) * pitch_gain[2];
      v66[1] = (v36 + gh * v35) * v27 + *(step - 1);
      v37 = i - mem->last_pitch;
      v25 = i + 4;
      i = v25;
      gi = v35 + v28;
      v38 = exc[v37 + 4] * mem->last_pitch_gain[0] + exc[v37 + 3] * mem->last_pitch_gain[1];
      v39 = exc[v37 + 2];
      v40 = step;
      step += 4;
      v60 = v38 + v39 * mem->last_pitch_gain[2];
      v41 = gi;
      v42 = v60 * (1.0 - gi);
      gj = *(v30 - 1) * *pitch_gain + *(v30 - 2) * pitch_gain[1] + pitch_gain[2] * *(v30 - 3);
      v66 += 4;
      v43 = v41;
      v44 = (v42 + gj * v41) * v27 + *v40;
      v29 = v43;
      *(v66 - 2) = v44;
    }
    while ( v25 < nsf - 3 );
    v26 = new_exc;
  }
  if ( v25 < nsf )
  {
    ia = (int)&v26[v25];
    stepa = &exc[v25 - pitch - 1];
    v45 = stepa;
    do
    {
      v46 = v25 - mem->last_pitch;
      ++v25;
      gk = v29 + v28;
      ia += 4;
      v61 = exc[v46 + 1] * mem->last_pitch_gain[0]
          + exc[v46] * mem->last_pitch_gain[1]
          + exc[v46 - 1] * mem->last_pitch_gain[2];
      v47 = gk;
      v48 = v61 * (1.0 - gk);
      gl = v45[1] * pitch_gain[1] + v45[2] * *pitch_gain + pitch_gain[2] * *v45;
      v45 = ++stepa;
      v49 = v47;
      v50 = (v48 + gl * v47) * v27 + *(float *)(ia + (char *)exc - (char *)new_exc - 4);
      v29 = v49;
      *(float *)(ia - 4) = v50;
    }
    while ( v25 < nsf );
    v26 = new_exc;
  }
  mem->last_pitch_gain[0] = *pitch_gain;
  mem->last_pitch_gain[1] = pitch_gain[1];
  mem->last_pitch_gain[2] = pitch_gain[2];
  mem->last_pitch = pitch;
  gain = compute_rms(v26, nsf);
  if ( gain < (double)exc_energy )
    exc_energy = gain;
  gaina = exc_energy / (gain + 1.0);
  if ( gaina >= 0.5 )
    v51 = gaina;
  else
    v51 = (float)0.5;
  v53 = 0;
  if ( nsf >= 4 )
  {
    v54 = v51 * 0.04;
    v55 = ((unsigned int)(nsf - 4) >> 2) + 1;
    v56 = v26 + 2;
    v53 = 4 * v55;
    do
    {
      v56 += 4;
      --v55;
      nsfa = mem->smooth_gain * 0.96 + v54;
      mem->smooth_gain = nsfa;
      *(v56 - 6) = nsfa * *(v56 - 6);
      nsfb = mem->smooth_gain * 0.96 + v54;
      mem->smooth_gain = nsfb;
      *(v56 - 5) = nsfb * *(v56 - 5);
      nsfc = mem->smooth_gain * 0.96 + v54;
      mem->smooth_gain = nsfc;
      *(v56 - 4) = nsfc * *(v56 - 4);
      nsfd = mem->smooth_gain * 0.96 + v54;
      mem->smooth_gain = nsfd;
      *(v56 - 3) = nsfd * *(v56 - 3);
    }
    while ( v55 );
  }
  for ( ; v53 < nsf; v26[v53 - 1] = nsfe * v26[v53 - 1] )
  {
    ++v53;
    nsfe = mem->smooth_gain * 0.96 + 0.04 * v51;
    mem->smooth_gain = nsfe;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9CABD0
double __cdecl spx_cos(float x)
{
  double v1; // st7
  float xb; // [esp+8h] [ebp+8h]
  float xc; // [esp+8h] [ebp+8h]
  float xd; // [esp+8h] [ebp+8h]

  v1 = x;
  if ( x >= 1.5707963268 )
  {
    xc = 3.141592653589793 - v1;
    xd = xc * xc;
    return (float)-(xd * ((0.04148774594068527 - 0.001271209446713328 * xd) * xd - 0.499912440776825)
                  + 0.9999933242797852);
  }
  else
  {
    xb = v1 * v1;
    return (float)(xb * ((0.04148774594068527 - 0.001271209446713328 * xb) * xb - 0.499912440776825) + 0.9999933242797852);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9CAC50
double __usercall cheb_poly_eva@<st0>(int m@<edx>, char *stack@<eax>, float *coef, float x)
{
  float *v4; // ecx
  int v5; // esi
  char *v6; // esi
  int v7; // edx
  float *v8; // eax
  int v9; // ebx
  double v10; // st7
  unsigned int v11; // edi
  float *v12; // ecx
  double v13; // st6
  double v14; // st6
  double v15; // rt0
  int v16; // edx
  float *v17; // ecx
  int v18; // eax
  int v19; // edx
  double v20; // st6
  float sum; // [esp+8h] [ebp-4h]
  float suma; // [esp+8h] [ebp-4h]
  float sumb; // [esp+8h] [ebp-4h]
  float sumc; // [esp+8h] [ebp-4h]
  float xa; // [esp+18h] [ebp+Ch]
  float xb; // [esp+18h] [ebp+Ch]
  float xc; // [esp+18h] [ebp+Ch]
  float xd; // [esp+18h] [ebp+Ch]
  float xe; // [esp+18h] [ebp+Ch]
  float xf; // [esp+18h] [ebp+Ch]

  v4 = coef;
  v5 = -(int)stack & 3;
  *(float *)&stack[v5] = 1.0;
  v6 = &stack[v5];
  v7 = m >> 1;
  *((float *)v6 + 1) = x;
  v8 = (float *)(v6 + 4);
  v9 = 2;
  sum = v4[v7 - 1] * x + v4[v7];
  xa = x + x;
  if ( v7 >= 2 )
  {
    v10 = xa;
    if ( v7 - 1 >= 4 )
    {
      v11 = (unsigned int)(v7 - 1) >> 2;
      v12 = &coef[v7 - 4];
      v9 = 4 * v11 + 2;
      do
      {
        v13 = *v8;
        v8 += 4;
        v12 -= 4;
        --v11;
        xb = v13 * v10 - *(v8 - 5);
        v14 = xb;
        *(v8 - 3) = xb;
        suma = v12[6] * xb + sum;
        xc = xb * v10 - *(v8 - 4);
        *(v8 - 2) = xc;
        sumb = v12[5] * xc + suma;
        v15 = xc;
        xd = xc * v10 - v14;
        *(v8 - 1) = xd;
        sumc = xd * v12[4] + sumb;
        xe = xd * v10 - v15;
        *v8 = xe;
        sum = xe * v12[3] + sumc;
      }
      while ( v11 );
      v4 = coef;
    }
    if ( v9 <= v7 )
    {
      v16 = v7 - v9;
      v17 = &v4[v16];
      v18 = (int)&v6[4 * v9 - 8];
      v19 = v16 + 1;
      do
      {
        v20 = *(float *)(v18 + 4);
        v18 += 4;
        --v17;
        --v19;
        xf = v20 * v10 - *(float *)(v18 - 4);
        *(float *)(v18 + 4) = xf;
        sum = xf * v17[1] + sum;
      }
      while ( v19 );
    }
  }
  return sum;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9CAD70
int __cdecl lpc_to_lsp(float *a, int lpcrdr, float *freq, int nb, float delta, char *stack)
{
  int v6; // eax
  int v7; // ecx
  int v8; // ebx
  float *v9; // esi
  float *v10; // ebx
  int v11; // edx
  float *v12; // ecx
  float *v13; // edi
  float *v14; // edx
  float *v15; // esi
  double v16; // st5
  float *v17; // ebx
  float *v18; // ebx
  bool v19; // zf
  float *v20; // esi
  char *v21; // ebx
  double v22; // st5
  int v23; // edi
  float *v24; // ecx
  float *v25; // edx
  double v26; // st4
  int v27; // edx
  int v28; // eax
  double v29; // st4
  double v30; // st7
  float *v31; // edi
  double v32; // st6
  float x; // [esp+0h] [ebp-38h]
  int psumm; // [esp+10h] [ebp-28h]
  float psumma; // [esp+10h] [ebp-28h]
  float psummb; // [esp+10h] [ebp-28h]
  float *Q; // [esp+14h] [ebp-24h]
  float *Qa; // [esp+14h] [ebp-24h]
  float *Qb; // [esp+14h] [ebp-24h]
  unsigned int v41; // [esp+18h] [ebp-20h]
  char *v42; // [esp+18h] [ebp-20h]
  int dd; // [esp+1Ch] [ebp-1Ch]
  int dda; // [esp+1Ch] [ebp-1Ch]
  float ddb; // [esp+1Ch] [ebp-1Ch]
  int roots; // [esp+20h] [ebp-18h]
  float *P; // [esp+24h] [ebp-14h]
  int Pa; // [esp+24h] [ebp-14h]
  int psuml; // [esp+28h] [ebp-10h]
  float psumla; // [esp+28h] [ebp-10h]
  float xm; // [esp+2Ch] [ebp-Ch]
  float *xr; // [esp+30h] [ebp-8h]
  float xra; // [esp+30h] [ebp-8h]
  float *px; // [esp+34h] [ebp-4h]
  float pxa; // [esp+34h] [ebp-4h]
  char *stacka; // [esp+54h] [ebp+1Ch]

  xm = 0.0;
  v6 = lpcrdr / 2;
  v7 = 4 * (lpcrdr / 2);
  v8 = (int)&stack[v7 + 4 + (-(int)stack & 3)];
  stacka = (char *)(v8 + v7 + (-v8 & 3) + 4);
  v9 = (float *)(v8 + (-v8 & 3));
  v10 = (float *)(v8 - v7 - 4);
  *v9 = 1.0;
  px = (float *)&stacka[-v7];
  *v10 = 1.0;
  xr = v10 + 1;
  v11 = 0;
  roots = 0;
  Q = v10;
  P = v9;
  v12 = v9;
  v13 = v10;
  if ( lpcrdr / 2 >= 4 )
  {
    v14 = a + 2;
    v15 = &a[lpcrdr - 2];
    psuml = (char *)v12 - (char *)v10;
    v41 = ((unsigned int)(v6 - 4) >> 2) + 1;
    dd = 4 * v41;
    v13 = v10;
    do
    {
      v16 = v15[1] + *(v14 - 2);
      v12 += 4;
      v13 += 4;
      v14 += 4;
      v15 -= 4;
      *px = v16 - *(v12 - 4);
      *xr = *(v14 - 6) - v15[5] + *(v13 - 4);
      px[1] = v15[4] + *(v14 - 5) - *(float *)((char *)v13 + psuml - 12);
      xr[1] = *(v14 - 5) - v15[4] + *(v13 - 3);
      px[2] = v15[3] + *(v14 - 4) - *(v12 - 2);
      xr[2] = *(v14 - 4) - v15[3] + *(v13 - 2);
      v17 = px;
      px += 4;
      v17[3] = v15[2] + *(v14 - 3) - *(v12 - 1);
      v18 = xr;
      xr += 4;
      v19 = v41-- == 1;
      v18[3] = *(v14 - 3) - v15[2] + *(v13 - 1);
    }
    while ( !v19 );
    v11 = dd;
    v10 = Q;
    v9 = P;
  }
  if ( v11 < v6 )
  {
    v20 = &a[lpcrdr - v11 - 1];
    psumm = (char *)v13 - (char *)v12;
    v21 = (char *)((char *)px - (char *)v12);
    v42 = (char *)((char *)xr - (char *)v12);
    do
    {
      v22 = *v20 + a[v11++];
      ++v12;
      --v20;
      *(float *)((char *)v12 + (_DWORD)v21 - 4) = v22 - *(v12 - 1);
      *(float *)((char *)v12 + (_DWORD)v42 - 4) = a[v11 - 1] - v20[1] + *(float *)((char *)v12 + psumm - 4);
    }
    while ( v11 < v6 );
    v10 = Q;
    v9 = P;
  }
  v23 = 0;
  v24 = v9;
  v25 = v10;
  if ( v6 >= 4 )
  {
    Qa = (float *)(((unsigned int)(v6 - 4) >> 2) + 1);
    dda = 4 * (_DWORD)Qa;
    do
    {
      v26 = *v24 * 2.0;
      v24 += 4;
      v25 += 4;
      v19 = Qa == (float *)1;
      Qa = (float *)((char *)Qa - 1);
      *(v24 - 4) = v26;
      *(v25 - 4) = *(v25 - 4) * 2.0;
      *(float *)((char *)v25 + (char *)v9 - (char *)v10 - 12) = *(float *)((char *)v25 + (char *)v9 - (char *)v10 - 12)
                                                              * 2.0;
      *(v25 - 3) = *(v25 - 3) * 2.0;
      *(v24 - 2) = *(v24 - 2) * 2.0;
      *(v25 - 2) = *(v25 - 2) * 2.0;
      *(v24 - 1) = *(v24 - 1) * 2.0;
      *(v25 - 1) = *(v25 - 1) * 2.0;
    }
    while ( !v19 );
    v23 = dda;
  }
  if ( v23 < v6 )
  {
    v27 = (char *)v25 - (char *)v24;
    v28 = v6 - v23;
    do
    {
      v29 = *v24++;
      --v28;
      *(v24 - 1) = v29 * 2.0;
      *(float *)((char *)v24 + v27 - 4) = *(float *)((char *)v24 + v27 - 4) * 2.0;
    }
    while ( v28 );
  }
  Pa = 0;
  xra = 0.0;
  pxa = 1.0;
  if ( lpcrdr > 0 )
  {
    v30 = pxa;
    do
    {
      v31 = v10;
      if ( (Pa & 1) == 0 )
        v31 = v9;
      x = v30;
      psumla = cheb_poly_eva(lpcrdr, stacka, v31, x);
      v30 = pxa;
      v32 = xra;
      while ( v32 >= -1.0 )
      {
        ddb = (1.0 - 0.9 * v30 * v30) * delta;
        if ( fabs(psumla) < 0.2 )
          ddb = ddb * 0.5;
        xra = v30 - ddb;
        psumma = cheb_poly_eva(lpcrdr, stacka, v31, xra);
        if ( psumma * psumla < 0.0 )
        {
          ++roots;
          if ( nb >= 0 )
          {
            Qb = (float *)(nb + 1);
            do
            {
              xm = (pxa + xra) * 0.5;
              psummb = cheb_poly_eva(lpcrdr, stacka, v31, xm);
              if ( psummb * psumla < 0.0 )
              {
                xra = (pxa + xra) * 0.5;
              }
              else
              {
                psumla = psummb;
                pxa = (pxa + xra) * 0.5;
              }
              Qb = (float *)((char *)Qb - 1);
            }
            while ( Qb );
          }
          freq[Pa] = acos(xm);
          pxa = xm;
          v30 = xm;
          break;
        }
        psumla = psumma;
        pxa = xra;
        v32 = xra;
        v30 = xra;
      }
      ++Pa;
    }
    while ( Pa < lpcrdr );
  }
  return roots;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdunicastconnection.cpp:0x9CB110
void __cdecl lsp_to_lpc(float *freq, float *ak, int lpcrdr, char *stack)
{
  int v4; // ebx
  int v5; // edi
  char *v6; // esi
  float *v7; // edx
  float *v8; // ecx
  float *v9; // edi
  int v10; // eax
  int v11; // edi
  float *v12; // eax
  float *v13; // ecx
  unsigned int v14; // esi
  double v15; // st2
  float *v16; // ecx
  int v17; // eax
  int v18; // esi
  int v19; // eax
  double v20; // st4
  double v21; // st2
  int i2; // [esp+10h] [ebp-20h]
  char *j; // [esp+14h] [ebp-1Ch]
  int ja; // [esp+14h] [ebp-1Ch]
  float *x_freq; // [esp+18h] [ebp-18h]
  float *Wp; // [esp+1Ch] [ebp-14h]
  int v27; // [esp+20h] [ebp-10h]
  float *v28; // [esp+20h] [ebp-10h]
  float xout2; // [esp+24h] [ebp-Ch]
  float xout2a; // [esp+24h] [ebp-Ch]
  float xout2b; // [esp+24h] [ebp-Ch]
  float xout2c; // [esp+24h] [ebp-Ch]
  float xout2d; // [esp+24h] [ebp-Ch]
  float xout1; // [esp+28h] [ebp-8h]
  float xout1a; // [esp+28h] [ebp-8h]
  float xout1b; // [esp+28h] [ebp-8h]
  float xout1c; // [esp+28h] [ebp-8h]
  float xout1d; // [esp+28h] [ebp-8h]
  float xin2; // [esp+2Ch] [ebp-4h]
  float xin2a; // [esp+2Ch] [ebp-4h]
  float xin2b; // [esp+2Ch] [ebp-4h]
  float xin2c; // [esp+2Ch] [ebp-4h]
  float xin1; // [esp+44h] [ebp+14h]
  float xin1a; // [esp+44h] [ebp+14h]
  float xin1b; // [esp+44h] [ebp+14h]
  float xin1c; // [esp+44h] [ebp+14h]
  float xin1d; // [esp+44h] [ebp+14h]
  float xin1e; // [esp+44h] [ebp+14h]

  v4 = lpcrdr >> 1;
  v5 = (int)&stack[16 * (lpcrdr >> 1) + 8 + (-(int)stack & 3)];
  v6 = &stack[-(int)stack & 3];
  v7 = 0;
  Wp = (float *)v6;
  if ( 4 * (lpcrdr >> 1) + 1 >= 0 )
    memset(v6, 0, 4 * (4 * (lpcrdr >> 1) + 2));
  xin1 = 1.0;
  xin2 = 1.0;
  v8 = (float *)(v5 + (-v5 & 3));
  x_freq = v8;
  if ( lpcrdr > 0 )
  {
    j = (char *)((char *)freq - (char *)v8);
    v9 = (float *)(v5 + (-v5 & 3));
    v27 = lpcrdr;
    do
    {
      *v9 = spx_cos(*(float *)((char *)v9 + (_DWORD)j));
      ++v9;
      --v27;
    }
    while ( v27 );
  }
  ja = (int)v7;
  if ( lpcrdr >= (int)v7 )
  {
    v28 = ak - 1;
    do
    {
      v10 = 0;
      v11 = 0;
      if ( v4 >= 4 )
      {
        v12 = (float *)(v6 + 44);
        v13 = v8 + 2;
        v14 = ((unsigned int)(v4 - 4) >> 2) + 1;
        v11 = 4 * v14;
        i2 = 8 * v14;
        do
        {
          v7 = v12 + 4;
          xout1 = xin1 - *(v13 - 2) * 2.0 * *(v12 - 11) + *(v12 - 10);
          xout2 = xin2 - *(v13 - 1) * 2.0 * *(v12 - 9) + *(v12 - 8);
          *(v12 - 10) = *(v12 - 11);
          *(v12 - 8) = *(v12 - 9);
          *(v12 - 11) = xin1;
          *(v12 - 9) = xin2;
          xin1a = xout1;
          xin2a = xout2;
          xout1a = xout1 - *v13 * 2.0 * *(v12 - 7) + *(v12 - 6);
          xout2a = xout2 - v13[1] * 2.0 * *(v12 - 5) + *(v12 - 4);
          *(v12 - 6) = *(v12 - 7);
          *(v12 - 4) = *(v12 - 5);
          *(v12 - 7) = xin1a;
          *(v12 - 5) = xin2a;
          xin1b = xout1a;
          xin2b = xout2a;
          xout1b = xout1a - v13[2] * 2.0 * *(v12 - 3) + *(v12 - 2);
          xout2b = xout2a - v13[3] * 2.0 * *(v12 - 1) + *v12;
          *(v12 - 2) = *(v12 - 3);
          *v12 = *(v12 - 1);
          *(v12 - 3) = xin1b;
          *(v12 - 1) = xin2b;
          xin1c = xout1b;
          xin2c = xout2b;
          v15 = v13[4] * 2.0;
          v13 += 8;
          v12 += 16;
          --v14;
          xout1c = xout1b - v15 * *(v12 - 15) + *(v12 - 14);
          xout2c = xout2b - *(v13 - 3) * 2.0 * *(v12 - 13) + *v7;
          *(v12 - 14) = *(v12 - 15);
          *v7 = *(v12 - 13);
          *(v12 - 15) = xin1c;
          *(v12 - 13) = xin2c;
          xin1 = xout1c;
          xin2 = xout2c;
        }
        while ( v14 );
        v6 = (char *)Wp;
        v10 = i2;
        v8 = x_freq;
      }
      if ( v11 < v4 )
      {
        v16 = &v8[v10];
        v17 = (int)&v6[16 * v11 + 8];
        v18 = v4 - v11;
        do
        {
          v7 = (float *)(v17 + 4);
          v16 += 2;
          v17 += 16;
          --v18;
          xout1d = xin1 - *(v16 - 2) * 2.0 * *(float *)(v17 - 24) + *(float *)(v17 - 20);
          xout2d = xin2 - *(v16 - 1) * 2.0 * *(float *)(v17 - 16) + *v7;
          *(float *)(v17 - 20) = *(float *)(v17 - 24);
          *v7 = *(float *)(v17 - 16);
          *(float *)(v17 - 24) = xin1;
          *(float *)(v17 - 16) = xin2;
          xin1 = xout1d;
          xin2 = xout2d;
        }
        while ( v18 );
        v6 = (char *)Wp;
        v8 = x_freq;
      }
      v19 = ja;
      v20 = xin1;
      if ( ja > 0 )
      {
        xin1d = xin2 - v7[2];
        v21 = xin1d;
        xin1e = v7[1] + v20;
        *v28 = (v21 + xin1e) * 0.5;
      }
      ++v28;
      v7[1] = v20;
      ++ja;
      v7[2] = xin2;
      xin1 = 0.0;
      xin2 = 0.0;
    }
    while ( v19 + 1 <= lpcrdr );
  }
}

#endif // __UNIMPLEMENTED__
