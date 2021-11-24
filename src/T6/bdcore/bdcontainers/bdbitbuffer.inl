// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdbitbuffer.inl:0x9280E0
bool __cdecl Demo_ShouldFilterHudElement(hudelem_s *elem)
{
  bool result; // al

  result = Demo_IsPlaying();
  if ( result )
    return (elem->flags & 0x200) != 0
        || Demo_IsAnyFreeMoveCamera() && (elem->flags & 0x10000) == 0
        || demo.playbackInited && demo.playback->hideGameHud && (elem->flags & 0x8000) == 0;
  return result;
}

#endif // __UNIMPLEMENTED__
