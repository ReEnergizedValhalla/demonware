// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdbytepacker.h:0x927860
void __cdecl Demo_SetTimeScale(float timeScale)
{
  if ( timeScale <= 0.0
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
          988,
          0,
          "(timeScale > 0.f)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( demo.playbackInited && !demo.shutdownInProgress && demo.playback->completed )
  {
    Com_PrintError(25, "We cannot timescale in a demo that is completed.\n");
  }
  else
  {
    demo.playback->timeScale = timeScale;
    Com_SetTimeScale(timeScale);
  }
}

#endif // __UNIMPLEMENTED__
