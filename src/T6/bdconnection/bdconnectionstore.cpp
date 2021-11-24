// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdconnectionstore.cpp:0x9C66D0
void __usercall compute_weighted_codebook(
        const char *shape_cb@<edx>,
        char *stack@<eax>,
        const float *r,
        float *resp,
        float *resp2,
        float *E,
        int shape_cb_size)
{
  char *v7; // ebx
  double v8; // st7
  double v9; // st6
  int v10; // edi
  double v11; // rt0
  int v12; // eax
  char *v13; // ecx
  float *v14; // ecx
  double v15; // rt1
  double v16; // st6
  double v17; // st7
  int v18; // esi
  int v19; // edx
  float *v20; // ecx
  unsigned int v21; // edi
  char *v22; // eax
  double v23; // st5
  float *v24; // eax
  double v25; // st5
  double v26; // st5
  const char *v27; // [esp+4h] [ebp-14h]
  int v29; // [esp+Ch] [ebp-Ch]
  int v30; // [esp+Ch] [ebp-Ch]
  const float *v31; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  float resj; // [esp+14h] [ebp-4h]
  float resja; // [esp+14h] [ebp-4h]
  float resjb; // [esp+14h] [ebp-4h]
  float resjc; // [esp+14h] [ebp-4h]
  float resjd; // [esp+14h] [ebp-4h]

  v7 = &stack[-(int)stack & 3];
  i = 0;
  if ( (int)E > 0 )
  {
    v8 = 0.0;
    v9 = 0.03125;
    v10 = shape_cb_size;
    v27 = shape_cb;
    while ( 1 )
    {
      v12 = 0;
      if ( v10 >= 4 )
      {
        v13 = v7 + 8;
        do
        {
          v29 = shape_cb[v12];
          v12 += 4;
          v13 += 16;
          *((float *)v13 - 6) = (float)v29;
          *((float *)v13 - 5) = (float)shape_cb[v12 - 3];
          *((float *)v13 - 4) = (float)shape_cb[v12 - 2];
          *((float *)v13 - 3) = (float)shape_cb[v12 - 1];
        }
        while ( v12 < v10 - 3 );
      }
      for ( ; v12 < v10; *(float *)&v7[4 * v12 - 4] = (float)v30 )
        v30 = shape_cb[v12++];
      v14 = resp2;
      v15 = v9;
      v16 = v8;
      v17 = v15;
      v18 = 0;
      resp2[i] = v16;
      if ( v10 > 0 )
      {
        v31 = r - 2;
        do
        {
          v19 = 0;
          resj = v16;
          if ( v18 >= 0 )
          {
            if ( v18 + 1 >= 4 )
            {
              v20 = (float *)v31;
              v21 = (unsigned int)(v18 + 1) >> 2;
              v22 = v7 + 8;
              v19 = 4 * v21;
              do
              {
                v22 += 16;
                v23 = v20[2] * *((float *)v22 - 6);
                v20 -= 4;
                --v21;
                resja = v23 + resj;
                resjb = resja + v20[5] * *((float *)v22 - 5);
                resjc = resjb + *((float *)v22 - 4) * v20[4];
                resj = resjc + v20[3] * *((float *)v22 - 3);
              }
              while ( v21 );
              v14 = resp2;
            }
            if ( v19 <= v18 )
            {
              v24 = (float *)&r[v18 - v19];
              do
              {
                v25 = *(float *)&v7[4 * v19++];
                v26 = v25 * *v24--;
                resj = v26 + resj;
              }
              while ( v19 <= v18 );
            }
            v10 = shape_cb_size;
          }
          ++v31;
          ++v18;
          resjd = resj * v17;
          v14[i] = resjd * resjd + v14[i];
          resp[v18 - 1] = resjd;
        }
        while ( v18 < v10 );
        shape_cb = v27;
      }
      resp += v10;
      shape_cb += v10;
      ++i;
      v27 = shape_cb;
      if ( i >= (int)E )
        break;
      v11 = v16;
      v9 = v17;
      v8 = v11;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdconnectionstore.cpp:0x9C6E70
void __cdecl split_cb_search_shape_sign(
        float *target,
        float *ak,
        float *awk1,
        float *awk2,
        const void *par,
        int p,
        int nsf,
        float *exc,
        float *r,
        SpeexBits *bits,
        char *stack,
        int complexity,
        int update_target)
{
  int v13; // edi
  int v14; // eax
  float **v15; // edi
  char *v16; // eax
  int **v17; // ebx
  int v18; // edx
  int v19; // ecx
  char *v20; // eax
  float *v21; // esi
  char *v22; // eax
  char *v23; // eax
  char *v24; // eax
  char *v25; // eax
  char *v26; // eax
  int v27; // esi
  char *v28; // eax
  float *v29; // esi
  char *v30; // edx
  float **v31; // ecx
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // ecx
  char *v37; // eax
  float **v38; // edx
  char *v39; // esi
  int m; // ecx
  int v41; // edi
  float *v42; // ebx
  int v43; // ecx
  float *v44; // esi
  unsigned int v45; // edi
  float *v46; // ecx
  float *v47; // ecx
  int v48; // ebx
  int v49; // esi
  double v50; // st7
  int v51; // ebx
  int v52; // edi
  int v53; // esi
  int v54; // ecx
  float *v55; // edx
  char *v56; // ebx
  unsigned int v57; // esi
  int v58; // edx
  int v59; // ecx
  char *v60; // esi
  int v61; // edx
  double v62; // st7
  double v63; // st7
  double v64; // st6
  double v65; // st5
  double v66; // st5
  int v67; // ecx
  float *v68; // edi
  int v69; // edx
  int v70; // esi
  unsigned int v71; // ecx
  int v72; // eax
  float *v73; // eax
  int v74; // ecx
  double v75; // st4
  int v76; // eax
  float *v77; // ebx
  int v78; // esi
  float *v79; // eax
  unsigned int v80; // edx
  float *v81; // ecx
  double v82; // st4
  double v83; // st4
  float *v84; // eax
  double v85; // st4
  int v86; // ecx
  float *v87; // eax
  unsigned int v88; // edx
  float *v89; // ecx
  double v90; // st4
  float *v91; // eax
  double v92; // st4
  double v93; // st4
  int v94; // eax
  unsigned int v95; // ecx
  int v96; // edx
  double v97; // st4
  double v98; // st4
  double v99; // st4
  double v100; // st4
  int v101; // edx
  int v102; // ecx
  int v103; // esi
  unsigned int v104; // ecx
  int v105; // eax
  float *v106; // eax
  int v107; // ecx
  double v108; // st3
  int v109; // edi
  float *v110; // esi
  int v111; // ebx
  double v112; // rt2
  double v113; // st4
  double v114; // st5
  int v115; // eax
  int v116; // ecx
  double v117; // st3
  int v118; // eax
  unsigned int v119; // edx
  double v120; // st2
  float *v121; // eax
  double v122; // st2
  double v123; // st1
  double v124; // rt1
  int v125; // edx
  double v126; // rt2
  double v127; // st3
  bool v128; // c0
  bool v129; // c3
  double v130; // rtt
  double v131; // st6
  double v132; // rt0
  float **v133; // ecx
  int v134; // esi
  int **v135; // ecx
  int jj; // eax
  int v137; // ebx
  float *v138; // ecx
  unsigned int v139; // edx
  float *v140; // eax
  float *v141; // eax
  int v142; // ecx
  double v143; // st4
  int v144; // esi
  int v145; // eax
  int v146; // edx
  float *v147; // ecx
  int v148; // eax
  float **v149; // edi
  float *v150; // ebx
  int v151; // edx
  float *v152; // eax
  int v153; // ecx
  int v154; // esi
  char *v155; // ebx
  unsigned int v156; // eax
  float *v157; // ecx
  float *v158; // eax
  char *v159; // esi
  int v160; // ecx
  double v161; // st3
  int n; // eax
  bool v163; // zf
  int v164; // edx
  float *v165; // eax
  int v166; // ecx
  char *v167; // edi
  unsigned int v168; // eax
  int v169; // esi
  float *v170; // ecx
  float *v171; // eax
  char *v172; // esi
  int v173; // ecx
  double v174; // st3
  int ii; // eax
  double v176; // rt2
  double v177; // st4
  double v178; // rtt
  double v179; // rt0
  double v180; // st5
  double v181; // st7
  int v182; // edi
  double v183; // st4
  int v184; // eax
  double v185; // st3
  int v186; // edx
  double v187; // st4
  const char *v188; // edi
  float *v189; // ecx
  float *v190; // edx
  int v191; // ebx
  float *v192; // eax
  float *v193; // ecx
  unsigned int v194; // edx
  double v195; // st7
  float *v196; // eax
  int v197; // ecx
  double v198; // st7
  float *v199; // edi
  int v200; // ebx
  float *v201; // eax
  float *v202; // ecx
  unsigned int v203; // edx
  double v204; // st7
  double v205; // st7
  int v206; // edi
  float *v207; // eax
  int v208; // esi
  double v209; // st7
  float *v210; // [esp-30h] [ebp-A8h]
  int v211; // [esp+0h] [ebp-78h]
  int v212; // [esp+0h] [ebp-78h]
  float g; // [esp+4h] [ebp-74h]
  float *r2; // [esp+8h] [ebp-70h]
  int *ind; // [esp+Ch] [ebp-6Ch]
  int have_sign; // [esp+10h] [ebp-68h]
  int have_signa; // [esp+10h] [ebp-68h]
  float v218; // [esp+14h] [ebp-64h]
  float v219; // [esp+14h] [ebp-64h]
  float v220; // [esp+14h] [ebp-64h]
  float *v221; // [esp+14h] [ebp-64h]
  int v222; // [esp+14h] [ebp-64h]
  float *v223; // [esp+14h] [ebp-64h]
  float *v224; // [esp+14h] [ebp-64h]
  float v225; // [esp+18h] [ebp-60h]
  int v226; // [esp+18h] [ebp-60h]
  float *best_dist; // [esp+1Ch] [ebp-5Ch]
  int **oind; // [esp+20h] [ebp-58h]
  float *E; // [esp+24h] [ebp-54h]
  const char *shape_cb; // [esp+28h] [ebp-50h]
  float *odist; // [esp+2Ch] [ebp-4Ch]
  float *odista; // [esp+2Ch] [ebp-4Ch]
  float **ot; // [esp+30h] [ebp-48h]
  float **ota; // [esp+30h] [ebp-48h]
  float *ct; // [esp+34h] [ebp-44h]
  float *cta; // [esp+34h] [ebp-44h]
  float *ctb; // [esp+34h] [ebp-44h]
  float *resp; // [esp+38h] [ebp-40h]
  float *e; // [esp+3Ch] [ebp-3Ch]
  int **nind; // [esp+40h] [ebp-38h]
  float **nt; // [esp+44h] [ebp-34h]
  char *k; // [esp+48h] [ebp-30h]
  int ka; // [esp+48h] [ebp-30h]
  int *best_index; // [esp+4Ch] [ebp-2Ch]
  int shape_cb_size; // [esp+50h] [ebp-28h]
  float *ndist; // [esp+54h] [ebp-24h]
  int v247; // [esp+58h] [ebp-20h]
  int v248; // [esp+58h] [ebp-20h]
  int j; // [esp+5Ch] [ebp-1Ch]
  int ja; // [esp+5Ch] [ebp-1Ch]
  int jb; // [esp+5Ch] [ebp-1Ch]
  float sign; // [esp+60h] [ebp-18h]
  float signa; // [esp+60h] [ebp-18h]
  int signb; // [esp+60h] [ebp-18h]
  int signc; // [esp+60h] [ebp-18h]
  int nb_subvect; // [esp+64h] [ebp-14h]
  int i; // [esp+68h] [ebp-10h]
  int ia; // [esp+68h] [ebp-10h]
  int ib; // [esp+68h] [ebp-10h]
  float *t; // [esp+6Ch] [ebp-Ch]
  int v261; // [esp+70h] [ebp-8h]
  int subvect_size; // [esp+74h] [ebp-4h]
  char *stacka; // [esp+A8h] [ebp+30h]
  int N; // [esp+ACh] [ebp+34h]

  if ( complexity <= 10 )
  {
    if ( complexity <= 1 )
    {
      split_cb_search_shape_sign_N1(target, ak, awk1, awk2, par, p, nsf, exc, r, bits, stack, update_target);
      return;
    }
  }
  else
  {
    complexity = 10;
  }
  k = &stack[4 * complexity + (-(int)stack & 3) + -4 * complexity];
  v13 = (int)&stack[4 * complexity
                  + 4 * complexity
                  + (-(int)stack & 3)
                  + (-(int)&stack[4 * complexity + (-(int)stack & 3)] & 3)];
  v14 = 4 * complexity + (-v13 & 3) + v13;
  oind = (int **)(v14 - 4 * complexity);
  v15 = (float **)(v13 - 4 * complexity);
  v16 = (char *)(4 * complexity + (-v14 & 3) + v14);
  v17 = (int **)&v16[-4 * complexity];
  subvect_size = *(_DWORD *)par;
  nb_subvect = *((_DWORD *)par + 1);
  v18 = 1 << *((_DWORD *)par + 3);
  shape_cb = (const char *)*((_DWORD *)par + 2);
  have_sign = *((_DWORD *)par + 4);
  v19 = 4 * *(_DWORD *)par * v18;
  v20 = &v16[v19 + (-(int)v16 & 3)];
  v21 = (float *)&v20[-v19];
  shape_cb_size = v18;
  v18 *= 4;
  v22 = &v20[v18 + (-(int)v20 & 3)];
  E = (float *)&v22[-v18];
  nind = v17;
  resp = v21;
  v23 = &v22[4 * nsf + (-(int)v22 & 3)];
  t = (float *)&v23[-4 * nsf];
  v24 = &v23[4 * nsf + (-(int)v23 & 3)];
  e = (float *)&v24[-4 * nsf];
  v25 = &v24[4 * nsf + (-(int)v24 & 3)];
  r2 = (float *)&v25[-4 * nsf];
  v26 = &v25[4 * nb_subvect + (-(int)v25 & 3)];
  ind = (int *)&v26[-4 * nb_subvect];
  v27 = 8 * nsf * complexity;
  v28 = (int)&v26[v27 + (-(int)v26 & 3)];
  v29 = (float *)(v28 - v27);
  odist = &v29[nsf];
  v30 = (char *)(k - (char *)v15);
  ot = (float **)complexity;
  v31 = v15;
  while ( 1 )
  {
    *(float **)((char *)v31 + (_DWORD)v30) = v29;
    *v31 = odist;
    odist += 2 * nsf;
    ++v31;
    ot = (float **)((char *)ot - 1);
    if ( !ot )
      break;
    v30 = (char *)(k - (char *)v15);
    v29 += 2 * nsf;
  }
  ota = (float **)&stack[4 * complexity + (-(int)stack & 3) + -4 * complexity];
  v32 = 4 * complexity + (-v28 & 3) + v28;
  best_index = (int *)(v32 - 4 * complexity);
  v33 = 4 * complexity + (-v32 & 3) + v32;
  best_dist = (float *)(v33 - 4 * complexity);
  v34 = 4 * complexity + (-v33 & 3) + v33;
  ndist = (float *)(v34 - 4 * complexity);
  v35 = 4 * complexity + (-v34 & 3) + v34;
  nt = v15;
  odista = (float *)(v35 - 4 * complexity);
  v36 = 8 * complexity * nb_subvect;
  v37 = (char *)(v36 + (-v35 & 3) + v35);
  stacka = v37;
  ct = (float *)&v37[-v36];
  v247 = (int)&v37[4 * nb_subvect - v36];
  v38 = (float **)v17;
  v39 = (char *)((char *)oind - (char *)v17);
  j = complexity;
  do
  {
    *v38 = ct;
    *(float **)((char *)v38 + (_DWORD)v39) = (float *)v247;
    for ( m = 0; m < nb_subvect; ++m )
    {
      (*(float **)((char *)v38 + (_DWORD)v39))[m] = NAN;
      (*v38)[m] = NAN;
    }
    ct += 2 * nb_subvect;
    v247 += 8 * nb_subvect;
    ++v38;
    --j;
  }
  while ( j );
  v41 = nsf;
  v42 = target;
  v43 = 0;
  i = 0;
  if ( nsf >= 4 )
  {
    v44 = target + 3;
    v45 = ((unsigned int)(nsf - 4) >> 2) + 1;
    v46 = t + 1;
    i = 4 * v45;
    do
    {
      v46 += 4;
      *(v46 - 5) = *(v44 - 3);
      v44 += 4;
      --v45;
      *(v46 - 4) = *(float *)((char *)v46 + (char *)target - (char *)t - 16);
      *(v46 - 3) = *(v44 - 5);
      *(v46 - 2) = *(v44 - 4);
    }
    while ( v45 );
    v41 = nsf;
    v42 = target;
    v43 = i;
  }
  if ( v43 < v41 )
  {
    v47 = &t[v43];
    v48 = (char *)v42 - (char *)t;
    v49 = v41 - i;
    do
    {
      v50 = *(float *)((char *)v47++ + v48);
      --v49;
      *(v47 - 1) = v50;
    }
    while ( v49 );
  }
  v51 = 0;
  ja = 0;
  do
  {
    v52 = 0;
    if ( nsf >= 4 )
    {
      v53 = *(_DWORD *)&k[4 * v51];
      v54 = v53 + 4;
      v55 = t + 3;
      v56 = (char *)t - v53;
      v57 = ((unsigned int)(nsf - 4) >> 2) + 1;
      v52 = 4 * v57;
      do
      {
        v54 += 16;
        *(float *)(v54 - 20) = *(v55 - 3);
        v55 += 4;
        --v57;
        *(float *)(v54 - 16) = *(float *)&v56[v54 - 16];
        *(float *)(v54 - 12) = *(v55 - 5);
        *(float *)(v54 - 8) = *(v55 - 4);
      }
      while ( v57 );
      v51 = ja;
    }
    if ( v52 < nsf )
    {
      v58 = *(_DWORD *)&k[4 * v51];
      v59 = v58 + 4 * v52;
      v60 = (char *)t - v58;
      v61 = nsf - v52;
      do
      {
        v62 = *(float *)&v60[v59];
        v59 += 4;
        --v61;
        *(float *)(v59 - 4) = v62;
      }
      while ( v61 );
    }
    ja = ++v51;
  }
  while ( v51 < complexity );
  compute_weighted_codebook(shape_cb, v37, r, resp, E, (float *)shape_cb_size, subvect_size);
  memset(odista, 0, 4 * complexity);
  v63 = 1.0;
  v64 = -1.0;
  ia = 0;
  v65 = 0.03125;
  if ( nb_subvect > 0 )
  {
    do
    {
      memset32(ndist, -1073741824, complexity);
      jb = 0;
      v248 = subvect_size * ia;
      v261 = subvect_size * (ia + 1);
      do
      {
        v210 = &ota[jb][v248];
        if ( have_sign )
          vq_nbest_sign(v210, resp, subvect_size, shape_cb_size, E, complexity, best_index, best_dist, stacka);
        else
          vq_nbest(v210, resp, subvect_size, shape_cb_size, E, complexity, best_index, best_dist, stacka);
        v64 = -1.0;
        ka = 0;
        v66 = 1.0;
        do
        {
          v67 = subvect_size * (ia + 1);
          v68 = t;
          cta = ota[jb];
          v69 = subvect_size * ia;
          if ( v248 < v261 )
          {
            if ( v261 - v248 >= 4 )
            {
              v70 = (int)&cta[v248 + 3];
              v71 = ((unsigned int)(v261 - v248 - 4) >> 2) + 1;
              v72 = (int)&t[v248 + 1];
              v69 = v248 + 4 * v71;
              do
              {
                v72 += 16;
                *(float *)(v72 - 20) = *(float *)(v70 - 12);
                v70 += 16;
                --v71;
                *(float *)(v72 - 16) = *(float *)((char *)cta - (char *)t + v72 - 16);
                *(float *)(v72 - 12) = *(float *)(v70 - 20);
                *(float *)(v72 - 8) = *(float *)(v70 - 16);
              }
              while ( v71 );
              v67 = subvect_size * (ia + 1);
            }
            if ( v69 < v67 )
            {
              v73 = &t[v69];
              v74 = v67 - v69;
              do
              {
                v75 = *(float *)((char *)v73++ + (char *)cta - (char *)t);
                --v74;
                *(v73 - 1) = v75;
              }
              while ( v74 );
            }
          }
          sign = v66;
          v76 = best_index[ka];
          if ( v76 >= shape_cb_size )
          {
            v76 -= shape_cb_size;
            sign = v64;
          }
          v77 = &resp[subvect_size * v76];
          v78 = 0;
          if ( sign <= 0.0 )
          {
            v86 = subvect_size;
            if ( subvect_size >= 4 )
            {
              v87 = &t[v248];
              v88 = ((unsigned int)(subvect_size - 4) >> 2) + 1;
              v89 = v77 + 2;
              v78 = 4 * v88;
              do
              {
                v87 += 4;
                v90 = *(v89 - 2) + *(v87 - 4);
                v89 += 4;
                --v88;
                *(v87 - 4) = v90;
                *(v87 - 3) = *(v89 - 5) + *(v87 - 3);
                *(v87 - 2) = *(v87 - 2) + *(v89 - 4);
                *(v87 - 1) = *(v89 - 3) + *(v87 - 1);
              }
              while ( v88 );
              v86 = subvect_size;
            }
            if ( v78 < v86 )
            {
              v91 = &t[v78 + v248];
              do
              {
                v92 = v77[v78++];
                v93 = v92 + *v91++;
                *(v91 - 1) = v93;
              }
              while ( v78 < v86 );
            }
          }
          else
          {
            if ( subvect_size >= 4 )
            {
              v79 = &t[v248];
              v80 = ((unsigned int)(subvect_size - 4) >> 2) + 1;
              v81 = v77 + 2;
              v78 = 4 * v80;
              do
              {
                v82 = *v79;
                v79 += 4;
                v83 = v82 - *(v81 - 2);
                v81 += 4;
                --v80;
                *(v79 - 4) = v83;
                *(v79 - 3) = *(v79 - 3) - *(v81 - 5);
                *(v79 - 2) = *(v79 - 2) - *(v81 - 4);
                *(v79 - 1) = *(v79 - 1) - *(v81 - 3);
              }
              while ( v80 );
            }
            if ( v78 < subvect_size )
            {
              v84 = &t[v78 + v248];
              do
              {
                v85 = *v84 - v77[v78++];
                *v84++ = v85;
              }
              while ( v78 < subvect_size );
            }
          }
          v94 = subvect_size * ia;
          signa = odista[jb];
          if ( v248 < v261 )
          {
            if ( v261 - v248 >= 4 )
            {
              v95 = ((unsigned int)(v261 - v248 - 4) >> 2) + 1;
              v96 = (int)&t[v248 + 2];
              v94 = v248 + 4 * v95;
              do
              {
                v97 = *(float *)(v96 - 8);
                v96 += 16;
                --v95;
                v218 = v97 * v97 + signa;
                v219 = *(float *)(v96 - 20) * *(float *)(v96 - 20) + v218;
                v220 = *(float *)(v96 - 16) * *(float *)(v96 - 16) + v219;
                signa = *(float *)(v96 - 12) * *(float *)(v96 - 12) + v220;
              }
              while ( v95 );
            }
            for ( ; v94 < v261; signa = v98 * v98 + signa )
              v98 = t[v94++];
          }
          v99 = signa;
          if ( ndist[complexity - 1] <= (double)signa )
          {
            v100 = v64;
            if ( v64 <= ndist[complexity - 1] )
            {
LABEL_94:
              v64 = v100;
              goto LABEL_95;
            }
            v68 = t;
            v99 = signa;
          }
          v101 = subvect_size * (ia + 1);
          v102 = nsf;
          if ( v261 < nsf )
          {
            if ( nsf - v261 >= 4 )
            {
              v103 = (int)&cta[v261 + 3];
              v104 = ((unsigned int)(nsf - v261 - 4) >> 2) + 1;
              v105 = (int)&v68[v261 + 1];
              v101 = v261 + 4 * v104;
              do
              {
                v105 += 16;
                *(float *)(v105 - 20) = *(float *)(v103 - 12);
                v103 += 16;
                --v104;
                *(float *)(v105 - 16) = *(float *)(v105 + (char *)cta - (char *)v68 - 16);
                *(float *)(v105 - 12) = *(float *)(v103 - 20);
                *(float *)(v105 - 8) = *(float *)(v103 - 16);
              }
              while ( v104 );
              v102 = nsf;
            }
            if ( v101 < v102 )
            {
              v106 = &v68[v101];
              v107 = v102 - v101;
              do
              {
                v108 = *(float *)((char *)v106++ + (char *)cta - (char *)v68);
                --v107;
                *(v106 - 1) = v108;
              }
              while ( v107 );
            }
          }
          v109 = 0;
          signb = 0;
          if ( subvect_size > 0 )
          {
            v110 = &r[subvect_size + 2];
            v111 = subvect_size;
            ctb = (float *)subvect_size;
            v221 = v110;
            do
            {
              v112 = v99;
              v113 = v66;
              v114 = v112;
              v225 = v113;
              v115 = best_index[ka];
              if ( v115 >= shape_cb_size )
              {
                v115 -= shape_cb_size;
                v225 = v64;
              }
              v116 = subvect_size * (ia + 1);
              if ( v261 < nsf )
              {
                g = (double)shape_cb[v109 + subvect_size * v115] * (v225 * 0.03125);
                v117 = g;
                if ( nsf - v261 >= 4 )
                {
                  v118 = (int)&t[v261 + 2];
                  v119 = ((unsigned int)(nsf - v261 - 4) >> 2) + 1;
                  v111 = (int)&ctb[v119];
                  v116 = 4 * v119 + v261;
                  do
                  {
                    v120 = *(float *)(v118 - 8);
                    v110 += 4;
                    v118 += 16;
                    --v119;
                    *(float *)(v118 - 24) = v120 - *(v110 - 6) * v117;
                    *(float *)(v118 - 20) = *(float *)(v118 - 20) - *(v110 - 5) * v117;
                    *(float *)(v118 - 16) = *(float *)(v118 - 16) - *(v110 - 4) * v117;
                    *(float *)(v118 - 12) = *(float *)(v118 - 12) - *(v110 - 3) * v117;
                  }
                  while ( v119 );
                  v109 = signb;
                }
                if ( v116 < nsf )
                {
                  v121 = &r[v111];
                  do
                  {
                    v122 = t[v116++];
                    v123 = *v121++;
                    t[v116 - 1] = v122 - v123 * v117;
                  }
                  while ( v116 < nsf );
                }
              }
              v124 = v113;
              v99 = v114;
              v66 = v124;
              ++v109;
              v111 = (int)ctb - 1;
              v110 = v221 - 1;
              signb = v109;
              ctb = (float *)((char *)ctb - 1);
              --v221;
            }
            while ( v109 < subvect_size );
          }
          v125 = 0;
          while ( 1 )
          {
            v127 = ndist[v125];
            v128 = v127 < v99;
            v129 = v127 == v99;
            v130 = v99;
            v100 = v64;
            v131 = v130;
            if ( !v128 && !v129 || v100 > ndist[v125] )
              break;
            if ( ++v125 >= complexity )
              goto LABEL_94;
            v126 = v100;
            v99 = v131;
            v64 = v126;
          }
          v148 = complexity - 1;
          signc = v125;
          if ( complexity - 1 > v125 )
          {
            v149 = &nt[v148 - 1];
            v150 = &ndist[v148];
            v224 = v150;
            v226 = v148 - v125;
            do
            {
              v151 = subvect_size * (ia + 1);
              if ( v261 < nsf )
              {
                if ( nsf - v261 >= 4 )
                {
                  v152 = v149[1];
                  v153 = (int)&v152[v261 + 1];
                  v154 = (int)&(*v149)[v261 + 3];
                  v155 = (char *)((char *)*v149 - (char *)v152);
                  v156 = ((unsigned int)(nsf - v261 - 4) >> 2) + 1;
                  v151 = v261 + 4 * v156;
                  do
                  {
                    v153 += 16;
                    *(float *)(v153 - 20) = *(float *)(v154 - 12);
                    v154 += 16;
                    --v156;
                    *(float *)(v153 - 16) = *(float *)&v155[v153 - 16];
                    *(float *)(v153 - 12) = *(float *)(v154 - 20);
                    *(float *)(v153 - 8) = *(float *)(v154 - 16);
                  }
                  while ( v156 );
                  v150 = v224;
                }
                if ( v151 < nsf )
                {
                  v157 = v149[1];
                  v158 = &v157[v151];
                  v159 = (char *)((char *)*v149 - (char *)v157);
                  v160 = nsf - v151;
                  do
                  {
                    v161 = *(float *)((char *)v158++ + (_DWORD)v159);
                    --v160;
                    *(v158 - 1) = v161;
                  }
                  while ( v160 );
                }
              }
              for ( n = 0; n < nb_subvect; ++n )
                *(float *)(*(_DWORD *)((char *)v150 + (char *)nind - (char *)ndist) + 4 * n) = (*(float **)((char *)v149 + (char *)nind - (char *)nt))[n];
              --v150;
              v150[1] = *(float *)((char *)v149-- + (char *)ndist - (char *)nt);
              v163 = v226-- == 1;
              v224 = v150;
            }
            while ( !v163 );
          }
          v164 = subvect_size * (ia + 1);
          if ( v261 < nsf )
          {
            if ( nsf - v261 >= 4 )
            {
              v165 = nt[signc];
              v166 = (int)&v165[v261 + 1];
              v167 = (char *)((char *)t - (char *)v165);
              v168 = ((unsigned int)(nsf - v261 - 4) >> 2) + 1;
              v169 = (int)&t[v261 + 3];
              v164 = v261 + 4 * v168;
              do
              {
                v166 += 16;
                *(float *)(v166 - 20) = *(float *)(v169 - 12);
                v169 += 16;
                --v168;
                *(float *)(v166 - 16) = *(float *)&v167[v166 - 16];
                *(float *)(v166 - 12) = *(float *)(v169 - 20);
                *(float *)(v166 - 8) = *(float *)(v169 - 16);
              }
              while ( v168 );
            }
            if ( v164 < nsf )
            {
              v170 = nt[signc];
              v171 = &v170[v164];
              v172 = (char *)((char *)t - (char *)v170);
              v173 = nsf - v164;
              do
              {
                v174 = *(float *)&v172[(_DWORD)v171++];
                --v173;
                *(v171 - 1) = v174;
              }
              while ( v173 );
            }
          }
          for ( ii = 0; ii < nb_subvect; ++ii )
            nind[signc][ii] = oind[jb][ii];
          v176 = v100;
          v177 = v131;
          v64 = v176;
          nind[signc][ia] = best_index[ka];
          ndist[signc] = v177;
LABEL_95:
          ++ka;
        }
        while ( ka < complexity );
        if ( !ia )
          break;
        ++jb;
      }
      while ( jb < complexity );
      v132 = v66;
      v65 = 0.03125;
      v63 = v132;
      v133 = nt;
      v134 = nb_subvect;
      nt = ota;
      ota = v133;
      v135 = oind;
      v222 = complexity;
      do
      {
        for ( jj = 0; jj < nb_subvect; ++jj )
          (*v135)[jj] = (*(int **)((char *)v135 + (char *)nind - (char *)oind))[jj];
        ++v135;
        --v222;
      }
      while ( v222 );
      v137 = 0;
      if ( complexity >= 4 )
      {
        v138 = ndist + 3;
        v139 = ((unsigned int)(complexity - 4) >> 2) + 1;
        v140 = odista + 1;
        v137 = 4 * v139;
        do
        {
          v140 += 4;
          *(v140 - 5) = *(v138 - 3);
          v138 += 4;
          --v139;
          *(v140 - 4) = *(float *)((char *)v140 + (char *)ndist - (char *)odista - 16);
          *(v140 - 3) = *(v138 - 5);
          *(v140 - 2) = *(v138 - 4);
        }
        while ( v139 );
        v134 = nb_subvect;
      }
      if ( v137 < complexity )
      {
        v141 = &odista[v137];
        v142 = complexity - v137;
        do
        {
          v143 = *(float *)((char *)v141++ + (char *)ndist - (char *)odista);
          --v142;
          *(v141 - 1) = v143;
        }
        while ( v142 );
      }
      ++ia;
    }
    while ( ia < v134 );
  }
  v144 = 0;
  if ( nb_subvect > 0 )
  {
    do
    {
      v145 = (*nind)[v144];
      ind[v144] = v145;
      speex_bits_pack(bits, v145, have_sign + *((_DWORD *)par + 3));
      ++v144;
    }
    while ( v144 < nb_subvect );
    v64 = -1.0;
    v65 = 0.03125;
    v63 = 1.0;
  }
  v146 = 0;
  ib = 0;
  if ( nb_subvect > 0 )
  {
    v147 = e;
    N = 0;
    v223 = e;
    while ( 1 )
    {
      v179 = v65;
      v180 = v63;
      v181 = v179;
      v182 = ind[v146];
      *(float *)&have_signa = v180;
      if ( v182 >= shape_cb_size )
      {
        v182 -= shape_cb_size;
        *(float *)&have_signa = v64;
      }
      v183 = *(float *)&have_signa;
      v184 = 0;
      if ( subvect_size >= 4 )
      {
        v185 = v183 * v181;
        v186 = (int)&shape_cb[subvect_size * v182 + 1];
        do
        {
          v211 = shape_cb[subvect_size * v182 + v184];
          v184 += 4;
          v147 += 4;
          *(v147 - 4) = (double)v211 * v185;
          *(v147 - 3) = (double)*(char *)(v186 + v184 - 4) * v185;
          *(v147 - 2) = (double)*(char *)(v186 + v184 - 3) * v185;
          *(v147 - 1) = (double)*(char *)(v186 + v184 - 2) * v185;
        }
        while ( v184 < subvect_size - 3 );
        v146 = ib;
      }
      if ( v184 < subvect_size )
      {
        v187 = v183 * v181;
        v188 = &shape_cb[subvect_size * v182];
        v189 = &e[v184 + N];
        do
        {
          v212 = v188[v184++];
          *v189++ = (double)v212 * v187;
        }
        while ( v184 < subvect_size );
      }
      N += subvect_size;
      ++v146;
      v147 = &v223[subvect_size];
      ib = v146;
      v223 = v147;
      if ( v146 >= nb_subvect )
        break;
      v178 = v180;
      v65 = v181;
      v63 = v178;
    }
  }
  v190 = exc;
  v191 = 0;
  if ( nsf >= 4 )
  {
    v192 = exc + 1;
    v193 = e + 3;
    v194 = ((unsigned int)(nsf - 4) >> 2) + 1;
    v191 = 4 * v194;
    do
    {
      v192 += 4;
      v195 = *(v193 - 3) + *(v192 - 5);
      v193 += 4;
      --v194;
      *(v192 - 5) = v195;
      *(v192 - 4) = *(float *)((char *)v192 + (char *)e - (char *)exc - 16) + *(v192 - 4);
      *(v192 - 3) = *(v193 - 5) + *(v192 - 3);
      *(v192 - 2) = *(v193 - 4) + *(v192 - 2);
    }
    while ( v194 );
    v190 = exc;
  }
  if ( v191 < nsf )
  {
    v196 = &v190[v191];
    v197 = nsf - v191;
    do
    {
      v198 = *(float *)((char *)v196++ + (char *)e - (char *)v190);
      --v197;
      *(v196 - 1) = v198 + *(v196 - 1);
    }
    while ( v197 );
  }
  if ( update_target )
  {
    v199 = r2;
    syn_percep_zero(e, ak, awk1, awk2, r2, nsf, p, stacka);
    v200 = 0;
    if ( nsf >= 4 )
    {
      v201 = target + 1;
      v202 = r2 + 3;
      v203 = ((unsigned int)(nsf - 4) >> 2) + 1;
      v200 = 4 * v203;
      do
      {
        v204 = *(v201 - 1);
        v201 += 4;
        v205 = v204 - *(v202 - 3);
        v202 += 4;
        --v203;
        *(v201 - 5) = v205;
        *(v201 - 4) = *(v201 - 4) - *(float *)((char *)v201 + (char *)r2 - (char *)target - 16);
        *(v201 - 3) = *(v201 - 3) - *(v202 - 5);
        *(v201 - 2) = *(v201 - 2) - *(v202 - 4);
      }
      while ( v203 );
      v199 = r2;
    }
    if ( v200 < nsf )
    {
      v206 = (char *)v199 - (char *)target;
      v207 = &target[v200];
      v208 = nsf - v200;
      do
      {
        v209 = *v207++;
        --v208;
        *(v207 - 1) = v209 - *(float *)((char *)v207 + v206 - 4);
      }
      while ( v208 );
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdconnectionstore.cpp:0x9C7C10
void __cdecl split_cb_shape_sign_unquant(float *exc, const void *par, int nsf, SpeexBits *bits, char *stack)
{
  _DWORD *v5; // ecx
  int v6; // eax
  char *v7; // edx
  int v8; // esi
  char *v9; // ebx
  int v10; // edi
  unsigned int v11; // eax
  bool v12; // zf
  int *v13; // edx
  double v14; // st7
  double v15; // st5
  int *v16; // ebx
  double v17; // rt0
  double v18; // rt1
  double v19; // st5
  double v20; // st7
  double v21; // st4
  int v22; // ecx
  float *v23; // eax
  double v24; // st3
  double v25; // st4
  float *v26; // eax
  int *ind; // [esp+Ch] [ebp-14h]
  int *inda; // [esp+Ch] [ebp-14h]
  char *v29; // [esp+10h] [ebp-10h]
  int v30; // [esp+10h] [ebp-10h]
  int v31; // [esp+10h] [ebp-10h]
  int have_sign; // [esp+14h] [ebp-Ch]
  int s; // [esp+18h] [ebp-8h]
  float sa; // [esp+18h] [ebp-8h]
  int nb_subvect; // [esp+1Ch] [ebp-4h]
  const void *para; // [esp+2Ch] [ebp+Ch]
  char *stacka; // [esp+38h] [ebp+18h]
  float *stackb; // [esp+38h] [ebp+18h]

  v5 = par;
  have_sign = *((_DWORD *)par + 4);
  nb_subvect = *((_DWORD *)par + 1);
  v6 = (int)&stack[4 * nb_subvect + (-(int)stack & 3)];
  v7 = &stack[-(int)stack & 3];
  v8 = *(_DWORD *)par;
  v9 = (char *)(v6 + (-v6 & 3));
  v10 = *((_DWORD *)par + 2);
  ind = (int *)v7;
  if ( nb_subvect > 0 )
  {
    stacka = (char *)(v6 + (-v6 & 3));
    v29 = (char *)(v7 - v9);
    s = *((_DWORD *)par + 1);
    while ( 1 )
    {
      if ( have_sign )
      {
        v11 = speex_bits_unpack_unsigned(bits, 1);
        v5 = par;
        *(_DWORD *)stacka = v11;
      }
      else
      {
        *(_DWORD *)stacka = 0;
      }
      *(_DWORD *)&stacka[(_DWORD)v29] = speex_bits_unpack_unsigned(bits, v5[3]);
      v12 = s-- == 1;
      stacka += 4;
      if ( v12 )
        break;
      v5 = par;
    }
    v13 = ind;
    v14 = 1.0;
    v15 = 0.03125;
    v16 = (int *)(v9 - (char *)ind);
    para = 0;
    stackb = exc;
    inda = v16;
    while ( 1 )
    {
      v18 = v15;
      v19 = v14;
      v20 = v18;
      sa = v19;
      if ( *(int *)((char *)v13 + (_DWORD)v16) )
        sa = -1.0;
      v21 = sa;
      v22 = 0;
      if ( v8 >= 4 )
      {
        v23 = stackb;
        v24 = v21 * v20;
        do
        {
          v23 += 4;
          *(v23 - 4) = (double)*(char *)(v22 + v8 * *v13 + v10) * v24 + *(v23 - 4);
          *(v23 - 3) = (double)*(char *)(v22 + v8 * *v13 + v10 + 1) * v24 + *(v23 - 3);
          *(v23 - 2) = (double)*(char *)(v22 + v8 * *v13 + v10 + 2) * v24 + *(v23 - 2);
          v30 = *(char *)(v22 + v8 * *v13 + v10 + 3);
          v22 += 4;
          *(v23 - 1) = (double)v30 * v24 + *(v23 - 1);
        }
        while ( v22 < v8 - 3 );
      }
      if ( v22 < v8 )
      {
        v25 = v21 * v20;
        v26 = &exc[(_DWORD)para + v22];
        do
        {
          v31 = *(char *)(v22 + v8 * *v13 + v10);
          ++v22;
          ++v26;
          *(v26 - 1) = (double)v31 * v25 + *(v26 - 1);
        }
        while ( v22 < v8 );
      }
      para = (char *)para + v8;
      stackb += v8;
      ++v13;
      if ( !--nb_subvect )
        break;
      v16 = inda;
      v17 = v19;
      v15 = v20;
      v14 = v17;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdconnectionstore.cpp:0x9C7DF0
void __cdecl noise_codebook_quant(
        float *target,
        float *ak,
        float *awk1,
        float *awk2,
        const void *par,
        int p,
        int nsf,
        float *exc,
        float *r,
        SpeexBits *bits,
        char *stack)
{
  float *v11; // esi
  float *v12; // edx
  int v13; // edi
  float *v14; // eax
  unsigned int v15; // edx
  float *v16; // ecx
  double v17; // st7
  int v18; // esi
  float *v19; // eax
  int v20; // ecx
  double v21; // st7
  int i; // [esp+3Ch] [ebp+30h]

  v11 = (float *)&stack[4 * nsf + (-(int)stack & 3) + -4 * nsf];
  residue_percep_zero(target, ak, awk1, awk2, v11, nsf, p, &stack[4 * nsf + (-(int)stack & 3)]);
  v12 = exc;
  v13 = 0;
  if ( nsf >= 4 )
  {
    v14 = exc + 1;
    v15 = ((unsigned int)(nsf - 4) >> 2) + 1;
    i = 4 * v15;
    v16 = v11 + 3;
    do
    {
      v14 += 4;
      v17 = *(v16 - 3) + *(v14 - 5);
      v16 += 4;
      --v15;
      *(v14 - 5) = v17;
      *(v14 - 4) = *(float *)((char *)v14 + (char *)v11 - (char *)exc - 16) + *(v14 - 4);
      *(v14 - 3) = *(v16 - 5) + *(v14 - 3);
      *(v14 - 2) = *(v14 - 2) + *(v16 - 4);
    }
    while ( v15 );
    v12 = exc;
    v13 = i;
  }
  if ( v13 < nsf )
  {
    v18 = (char *)v11 - (char *)v12;
    v19 = &v12[v13];
    v20 = nsf - v13;
    do
    {
      v21 = *(float *)((char *)v19++ + v18);
      --v20;
      *(v19 - 1) = v21 + *(v19 - 1);
    }
    while ( v20 );
  }
  if ( nsf > 0 )
    memset(target, 0, 4 * nsf);
}

#endif // __UNIMPLEMENTED__
