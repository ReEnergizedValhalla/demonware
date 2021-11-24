// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdnattravclientdata.cpp:0x9599D0
void __usercall PM_FlyMove(pml_t *pml@<ecx>, double a2@<st0>, pmove_t *pm)
{
  playerState_s *v4; // edi
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm0_4
  float forwardmove; // xmm3_4
  float rightmove; // xmm4_4
  bool v10; // zf
  float v11; // xmm4_4
  float v12; // xmm3_4
  playerState_s *ps; // [esp+18h] [ebp-28h]
  float scale; // [esp+20h] [ebp-20h]
  float scalea; // [esp+20h] [ebp-20h]
  vec3_t forward; // [esp+24h] [ebp-1Ch] BYREF
  vec3_t up; // [esp+30h] [ebp-10h] BYREF

  if ( !pm
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 1767, 0, "(pm)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v4 = pm->ps;
  ps = pm->ps;
  if ( !pm->ps
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\bgame\\bg_pmove.cpp", 1770, 0, "(ps)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  PM_Friction(v4, pm, a2, pml);
  scale = PM_CmdScale(v4, &pm->cmd);
  if ( scale == 0.0 )
  {
    x = 0.0;
    y = 0.0;
    z = 0.0;
  }
  else
  {
    *(_QWORD *)&up.x = 0i64;
    LODWORD(up.z) = FLOAT_1_0;
    Vec3Cross(&up, &pml->right, &forward);
    forwardmove = (float)pm->cmd.forwardmove;
    rightmove = (float)pm->cmd.rightmove;
    x = (float)((float)(forwardmove * forward.x) + (float)(rightmove * pml->right.x)) * scale;
    y = (float)((float)(pml->right.y * rightmove) + (float)(forwardmove * forward.y)) * scale;
    z = (float)((float)(pml->right.z * rightmove) + (float)(forwardmove * forward.z)) * scale;
  }
  v10 = v4->speed == 0;
  *(_QWORD *)&up.v[1] = __PAIR64__(LODWORD(z), LODWORD(y));
  up.x = x;
  if ( !v10 )
  {
    scalea = PM_MoveScale(v4, 0.0, 0.0, 127.0);
    if ( Com_GetClientPlatform() || !pm->cmd.lastInput )
    {
      if ( pm->cmd.button_bits.array[0] >= 0 )
        z = up.z;
      else
        z = (float)(scalea * 127.0) + up.z;
      if ( (pm->cmd.button_bits.array[0] & 0x100000) != 0 )
        z = z - (float)(scalea * 127.0);
    }
    else
    {
      if ( (pm->cmd.button_bits.array[0] & 0x2000000) != 0 )
        z = up.z - (float)(scalea * 127.0);
      else
        z = up.z;
      if ( (pm->cmd.button_bits.array[0] & 0x1000000) != 0 )
        z = z + (float)(scalea * 127.0);
    }
    x = up.x;
    y = up.y;
  }
  v11 = fsqrt((float)((float)(y * y) + (float)(x * x)) + (float)(z * z));
  if ( COERCE_FLOAT(LODWORD(v11) ^ _mask__NegFloat_) < 0.0 )
    v12 = v11;
  else
    v12 = *(float *)&FLOAT_1_0;
  forward.z = z * (float)(1.0 / v12);
  forward.x = x * (float)(1.0 / v12);
  forward.y = y * (float)(1.0 / v12);
  PM_Accelerate(ps, &forward, pml, v11, 8.0);
  PM_StepSlideMove(pm, pml, 0);
}

#endif // __UNIMPLEMENTED__
