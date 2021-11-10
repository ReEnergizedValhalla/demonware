// SPDX-License-Identifier: GPL-3.0-or-later

#ifdef    __UNIMPLEMENTED__

// bdplatformstring.inl:0x5A4270
int bdSnprintf(char *buf, const unsigned int maxlen, const char *format, ...)
{
  int v4; // [esp+4h] [ebp-Ch]
  va_list va; // [esp+24h] [ebp+14h] BYREF

  va_start(va, format);
  v4 = _vscprintf(format, va);
  vsnprintf_s(buf, maxlen, 0xFFFFFFFF, format, va);
  return v4;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformstring.inl:0x5A8FC0
unsigned int __cdecl bdStrlcpy(char *const dst, const char *const src, const unsigned int size)
{
  unsigned int v4; // [esp+0h] [ebp-1Ch]
  unsigned int slen; // [esp+18h] [ebp-4h]

  slen = strlen(src);
  if ( size && dst )
  {
    if ( slen >= size - 1 )
      v4 = size - 1;
    else
      v4 = slen;
    memcpy((unsigned __int8 *)dst, (unsigned __int8 *)src, v4);
    dst[v4] = 0;
  }
  return slen;
}

#endif // __UNIMPLEMENTED__
