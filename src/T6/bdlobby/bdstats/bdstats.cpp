// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdstats.cpp:0x92E370
void __usercall Demo_PopulateStaticFooterInformation(demoFooter *footer@<esi>)
{
  const char *String; // eax
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax

  String = (const char *)Dvar_GetString(g_gametype);
  I_strncpyz(footer->info.gameType, String, 256);
  v2 = (const char *)Dvar_GetString(sv_mapname);
  I_strncpyz(footer->info.mapName, v2, 256);
  v3 = (const char *)Dvar_GetString(ui_zm_gamemodegroup);
  I_strncpyz(footer->info.zmGameModeGroup, v3, 256);
  v4 = (const char *)Dvar_GetString(ui_zm_mapstartlocation);
  I_strncpyz(footer->info.zmMapStartLoc, v4, 256);
  footer->info.createTime = LiveStorage_GetUTC();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdstats.cpp:0x92E410
unsigned __int8 *__cdecl Demo_GetActiveMemoryBuffer()
{
  unsigned __int8 *result; // eax

  result = demo.msgBuf1;
  if ( !demo.msgBufFlag )
    return demo.msgBuf0;
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdstats.cpp:0x92E430
int __cdecl Demo_WriteMemoryBlockDataToFile()
{
  int v0; // esi
  int v1; // eax
  int uncompressedSize; // [esp+4h] [ebp-8h] BYREF
  int compressedSize; // [esp+8h] [ebp-4h] BYREF

  if ( Com_IsClientConsole() )
  {
    compressedSize = (((demo.memBlock.compressedSize << 16) | demo.memBlock.compressedSize & 0xFF00) << 8) | ((HIWORD(demo.memBlock.compressedSize) | (unsigned int)&g_sd.voiceDecodeBuffer[742080] & demo.memBlock.compressedSize) >> 8);
    uncompressedSize = (((demo.memBlock.uncompressedSize << 16) | demo.memBlock.uncompressedSize & 0xFF00) << 8) | ((HIWORD(demo.memBlock.uncompressedSize) | (unsigned int)&g_sd.voiceDecodeBuffer[742080] & demo.memBlock.uncompressedSize) >> 8);
    v0 = Demo_Write(&compressedSize, 4, demo.demoFileHandle);
    v1 = Demo_Write(&uncompressedSize, 4, demo.demoFileHandle);
  }
  else
  {
    v0 = Demo_Write(&demo.memBlock, 4, demo.demoFileHandle);
    v1 = Demo_Write(&demo.memBlock.uncompressedSize, 4, demo.demoFileHandle);
  }
  return v1 + v0 + Demo_Write(demo.memBlock.compressedMsgBuf, demo.memBlock.compressedSize, demo.demoFileHandle);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdstats.cpp:0x92E510
int __cdecl Demo_WriteMemoryBlockDataToBuffer(demoMemBlock *memBlock, unsigned __int8 *to, int maxBufferSize)
{
  int v3; // esi
  int v4; // edi
  int compressedSize; // esi
  int v6; // edi

  if ( Com_IsClientConsole() )
  {
    v3 = (((memBlock->compressedSize << 16) | memBlock->compressedSize & 0xFF00) << 8) | ((((unsigned __int64)(unsigned int)memBlock->compressedSize >> 16) | (unsigned int)&g_sd.voiceDecodeBuffer[742080] & memBlock->compressedSize) >> 8);
    v4 = (((memBlock->uncompressedSize << 16) | memBlock->uncompressedSize & 0xFF00) << 8) | ((((unsigned __int64)(unsigned int)memBlock->uncompressedSize >> 16) | (unsigned int)&g_sd.voiceDecodeBuffer[742080] & memBlock->uncompressedSize) >> 8);
    if ( maxBufferSize <= 4 )
      Com_Error(ERR_DROP, &byte_CDD778);
    *(_DWORD *)to = v3;
    if ( maxBufferSize <= 8 )
      Com_Error(ERR_DROP, &byte_CDD778);
    *((_DWORD *)to + 1) = v4;
  }
  else
  {
    if ( maxBufferSize <= 4 )
      Com_Error(ERR_DROP, &byte_CDD778);
    *(_DWORD *)to = memBlock->compressedSize;
    if ( maxBufferSize <= 8 )
      Com_Error(ERR_DROP, &byte_CDD778);
    *((_DWORD *)to + 1) = memBlock->uncompressedSize;
  }
  compressedSize = memBlock->compressedSize;
  v6 = memBlock->compressedSize + 8;
  if ( v6 >= maxBufferSize )
    Com_Error(ERR_DROP, &byte_CDD778);
  memcpy(to + 8, memBlock->compressedMsgBuf, compressedSize);
  return v6;
}

#endif // __UNIMPLEMENTED__
