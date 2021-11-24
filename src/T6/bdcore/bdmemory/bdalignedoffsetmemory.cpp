// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdalignedoffsetmemory.cpp:0x9291D0
char __usercall Demo_CanStartClipRecord@<al>(LocalClientNum_t localClientNum@<esi>)
{
  demoClipState clipState; // eax
  demoPlayback *playback; // eax

  if ( !demo.playbackInited )
    goto LABEL_10;
  clipState = demo.playback->clipState;
  if ( clipState && clipState != DEMO_CLIP_PAUSED )
  {
    Com_PrintError(25, "The clip system is doing some process. So, cant start record.\n");
    return 0;
  }
  if ( !demo.shutdownInProgress && demo.playback->completed )
  {
    Com_PrintError(25, "We cannot start record a clip for a demo that is completed\n");
    return 0;
  }
  else
  {
LABEL_10:
    if ( Demo_IsPlaying() && demo.header.isDemoClip )
      return 0;
    if ( Demo_IsPlaying() && demo.playbackInited && demo.playback->clipState == DEMO_CLIP_PREVIEW )
    {
      Com_PrintError(25, "We cannot start a clip record in a demo that is being previewed\n");
      return 0;
    }
    else if ( Demo_IsCameraEditMode() )
    {
      Com_PrintError(25, "Cannot start clip record when in edit mode.\n");
      return 0;
    }
    else
    {
      playback = demo.playback;
      if ( demo.playback->mainClipRecordingBuf )
      {
        if ( demo.playback->pendingSegmentSave )
        {
          if ( !Assert_MyHandler(
                  "c:\\t6\\code\\src_noserver\\demo\\demo_playback.cpp",
                  5264,
                  0,
                  "(!demo.playback->pendingSegmentSave)",
                  (const char *)&pBlock) )
            __debugbreak();
          playback = demo.playback;
        }
        if ( playback->segmentCount == 20 )
        {
          Demo_Error(localClientNum, "MENU_ERROR", "MENU_DEMO_MAX_SEGMENTS_REACHED");
          return 0;
        }
        else if ( playback->clipRecordBufIndex < 983040 )
        {
          return 1;
        }
        else
        {
          Demo_Error(localClientNum, "MENU_ERROR", "MENU_DEMO_MAX_CLIP_FILESIZE_REACHED");
          return 0;
        }
      }
      else
      {
        Com_PrintError(25, "Cannot start clip record since mainClipRecordingBuf is not allocated\n");
        return 0;
      }
    }
  }
}

#endif // __UNIMPLEMENTED__
