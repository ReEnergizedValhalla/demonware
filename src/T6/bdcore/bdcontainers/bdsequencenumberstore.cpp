// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdsequencenumberstore.cpp:0x9D17D0
void __thiscall bdHash::~bdHash(bdHash *this)
{
  this->__vftable = (bdHash_vtbl *)&bdHash::`vftable';
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsequencenumberstore.cpp:0x9D17E0
void __thiscall bdCypher::~bdCypher(bdCypher *this)
{
  this->__vftable = (bdCypher_vtbl *)&bdCypher::`vftable';
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsequencenumberstore.cpp:0x9D17F0
_DWORD *__cdecl bdAlignedOffsetMalloc(const unsigned int size, const unsigned int align, const unsigned int offset)
{
  _DWORD *result; // eax
  unsigned int v4; // edi
  _DWORD *v5; // ecx

  if ( ((align - 1) & align) != 0 )
    return 0;
  v4 = align + offset + 4;
  result = malloc(v4 + size);
  v5 = result;
  if ( result )
  {
    result = (_DWORD *)((~(align - 1) & ((unsigned int)result + v4)) - offset);
    *(result - 1) = v5;
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsequencenumberstore.cpp:0x9D1840
void __cdecl bdAlignedOffsetFree(void *p)
{
  free(*((void **)p - 1));
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsequencenumberstore.cpp:0x9D1860
unsigned __int8 *__cdecl bdAlignedOffsetRealloc(
        void *p,
        const unsigned int origSize,
        const unsigned int size,
        const unsigned int align,
        const unsigned int offset)
{
  unsigned int v5; // esi
  unsigned __int8 *v6; // edi

  v5 = size;
  v6 = (unsigned __int8 *)bdAlignedOffsetMalloc(size, align, offset);
  if ( size >= origSize )
    v5 = origSize;
  memcpy(v6, (unsigned __int8 *)p, v5);
  bdAlignedOffsetFree(p);
  return v6;
}

#endif // __UNIMPLEMENTED__
