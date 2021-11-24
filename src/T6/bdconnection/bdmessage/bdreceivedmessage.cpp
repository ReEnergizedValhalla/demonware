// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdreceivedmessage.cpp:0x9CB3F0
void __cdecl lsp_enforce_margin(float *lsp, int len, float margin)
{
  double v3; // st7
  bool v4; // c0
  bool v5; // c3
  double v6; // st7
  int v7; // edx
  int v8; // ebx
  unsigned int v9; // esi
  float *v10; // ecx
  double v11; // st5
  double v12; // st5
  double v13; // st5
  double v14; // st5
  double v15; // st5

  v3 = *lsp;
  v4 = margin < v3;
  v5 = margin == v3;
  v6 = margin;
  if ( !v4 && !v5 )
    *lsp = margin;
  if ( lsp[len - 1] > 3.141592653589793 - v6 )
    lsp[len - 1] = 3.141592653589793 - v6;
  v7 = 1;
  v8 = len - 1;
  if ( len - 1 > 1 )
  {
    if ( len - 2 >= 4 )
    {
      v9 = ((unsigned int)(len - 6) >> 2) + 1;
      v10 = lsp + 2;
      v7 = 4 * v9 + 1;
      do
      {
        v11 = *(v10 - 2) + v6;
        if ( *(v10 - 1) < v11 )
          *(v10 - 1) = v11;
        if ( *v10 - v6 < *(v10 - 1) )
          *(v10 - 1) = (*(v10 - 1) + *v10 - v6) * 0.5;
        v12 = *(v10 - 1) + v6;
        if ( *v10 < v12 )
          *v10 = v12;
        if ( v10[1] - v6 < *v10 )
          *v10 = (v10[1] + *v10 - v6) * 0.5;
        v13 = *v10 + v6;
        if ( v10[1] < v13 )
          v10[1] = v13;
        if ( v10[2] - v6 < v10[1] )
          v10[1] = (v10[1] + v10[2] - v6) * 0.5;
        v14 = v10[1] + v6;
        if ( v10[2] < v14 )
          v10[2] = v14;
        if ( v10[3] - v6 < v10[2] )
          v10[2] = (v10[3] + v10[2] - v6) * 0.5;
        v10 += 4;
        --v9;
      }
      while ( v9 );
    }
    for ( ; v7 < v8; ++v7 )
    {
      v15 = lsp[v7 - 1] + v6;
      if ( lsp[v7] < v15 )
        lsp[v7] = v15;
      if ( lsp[v7 + 1] - v6 < lsp[v7] )
        lsp[v7] = (lsp[v7 + 1] + lsp[v7] - v6) * 0.5;
    }
  }
}

#endif // __UNIMPLEMENTED__
