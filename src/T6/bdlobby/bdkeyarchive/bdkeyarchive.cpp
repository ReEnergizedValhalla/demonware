// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdkeyarchive.cpp:0x930CA0
void __cdecl Demo_WriteFooter(int handle, demoFooter *footer)
{
  int cursize; // esi
  unsigned int v3; // eax
  msg_t msg; // [esp+8h] [ebp-3Ch] BYREF
  int version; // [esp+38h] [ebp-Ch] BYREF
  int totalWritten; // [esp+3Ch] [ebp-8h] BYREF
  int totalBytesWritten; // [esp+40h] [ebp-4h] BYREF

  memset(demo.msgBuf1, 0, sizeof(demo.msgBuf1));
  MSG_Init(&msg, demo.msgBuf1, 0x10000);
  Demo_WriteFooterInternal(&msg, footer, 0);
  cursize = msg.cursize;
  memset(demo.memBlock.compressedMsgBuf, 0, sizeof(demo.memBlock.compressedMsgBuf));
  demo.memBlock.compressedSize = Com_CompressWithZLib(msg.data, msg.cursize, demo.memBlock.compressedMsgBuf, 0x10000);
  demo.memBlock.uncompressedSize = cursize;
  totalBytesWritten = Demo_WriteMemoryBlockDataToFile();
  if ( Com_IsClientConsole() )
  {
    v3 = footer->version;
    totalWritten = (((totalBytesWritten << 16) | totalBytesWritten & 0xFF00) << 8) | ((HIWORD(totalBytesWritten) | (unsigned int)&g_sd.voiceDecodeBuffer[742080] & totalBytesWritten) >> 8);
    version = ((v3 & 0xFF00 | (v3 << 16)) << 8) | ((HIWORD(v3) | (unsigned int)&g_sd.voiceDecodeBuffer[742080] & v3) >> 8);
    Demo_Write(&totalWritten, 4, demo.demoFileHandle);
    Demo_Write(&version, 4, demo.demoFileHandle);
  }
  else
  {
    Demo_Write(&totalBytesWritten, 4, handle);
    Demo_Write(footer, 4, handle);
  }
  Demo_Printf(258, "DEMO Info: Written %d bytes to demo file.\n", totalBytesWritten + 8);
}

#endif // __UNIMPLEMENTED__
