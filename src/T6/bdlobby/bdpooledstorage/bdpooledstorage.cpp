// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x932E70
int __cdecl Demo_GetVersion()
{
  if ( Demo_IsIdle() )
    Com_Error(ERR_DROP, &byte_CDE8DC);
  return demo.header.version;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x932E90
bool __cdecl Demo_IsVersionAtLeast(int version)
{
  if ( !Demo_IsPlaying() )
    return 1;
  if ( Demo_IsIdle() )
    Com_Error(ERR_DROP, &byte_CDE8DC);
  return demo.header.version >= version;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x932ED0
const NetFieldList *__cdecl Demo_GetNetFieldListForType(netFieldTypes_t fieldType)
{
  int v1; // esi

  if ( Demo_IsIdle() )
    Com_Error(ERR_DROP, &byte_CDE8DC);
  v1 = 13 - demo.header.version;
  if ( 13 - demo.header.version < 0 )
    Com_Error(ERR_DROP, &byte_CDE91C);
  return &s_demoOtherNetFieldLists[v1][fieldType];
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x932F20
const NetFieldList *__cdecl Demo_GetStateFieldListForEntityType(const int eType)
{
  int v1; // esi
  int v2; // eax

  if ( Demo_IsIdle() )
    Com_Error(ERR_DROP, &byte_CDE8DC);
  v1 = 13 - demo.header.version;
  if ( 13 - demo.header.version < 0 )
    Com_Error(ERR_DROP, &byte_CDE91C);
  v2 = eType;
  if ( eType > 21 )
    v2 = 21;
  return &s_demoEntityNetFieldLists[v1][v2];
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x932F80
IPakLoadedPackfile *__cdecl IPak_FindPackfile(const char *name)
{
  int v1; // edi
  IPakLoadedPackfile *v2; // esi

  v1 = 0;
  v2 = s_loadedPackfiles;
  while ( v2->refCount <= 0 || I_stricmp(v2->name, name) )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)&s_adjacencyInfoStale )
      return 0;
  }
  return &s_loadedPackfiles[v1];
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x932FD0
void __cdecl IPak_MarkAdjacencyInfoAsStale()
{
  s_adjacencyInfoStale = 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x932FE0
int __cdecl IPak_RemovePackfile(const char *name)
{
  IPakLoadedPackfile *Packfile; // eax
  IPakLoadedPackfile *v2; // esi

  PIXBeginNamedEvent(-1, "IPak_RemovePackfile");
  if ( !Sys_IsMainThread()
    && !Sys_IsRenderThread()
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
          432,
          0,
          "(Sys_IsMainThread() || Sys_IsRenderThread())",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  Packfile = IPak_FindPackfile(name);
  v2 = Packfile;
  if ( Packfile )
  {
    if ( Packfile->refCount <= 0
      && !Assert_MyHandler(
            "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
            439,
            0,
            "(pak->refCount > 0)",
            (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v2->refCount-- == 1 )
    {
      Stream_CloseFile(v2->fh);
      v2->fh = -16777217;
      Com_Printf(41, "Removed ipak file: %s\n", v2->name);
      s_adjacencyInfoStale = 1;
    }
    if ( Sys_IsRenderThread() )
      D3DPERF_EndEvent();
    return 1;
  }
  else
  {
    if ( Sys_IsRenderThread() )
      D3DPERF_EndEvent();
    return 0;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x9330C0
void __cdecl IPak_IndexReadCallback(int id, stream_status result, unsigned int numBytesRead, void *user)
{
  *(_DWORD *)user = (result != STREAM_STATUS_FINISHED) + 2;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x9330E0
void __usercall IPak_ReadIndexData(IPakWorkData *work@<esi>, int buffer@<eax>)
{
  int indexReadOffset; // ecx
  int v4; // eax
  unsigned int v5; // ebx
  unsigned __int16 *v6; // [esp-8h] [ebp-10h]

  if ( (unsigned int)buffer >= 2
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
          496,
          0,
          "(unsigned)(buffer) < (unsigned)(2)",
          "buffer doesn't index IPAK_INDEX_BUFFER_COUNT\n\t%i not in [0, %i)",
          buffer,
          2) )
  {
    __debugbreak();
  }
  if ( *(_DWORD *)&work[1].imageParts[2 * buffer + 52]
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
          497,
          0,
          "(work->indexBufferState[ buffer ] == 0)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  indexReadOffset = work->indexReadOffset;
  v4 = work->pak->index.size - indexReadOffset;
  if ( v4 > 0x10000 )
    v4 = 0x10000;
  v5 = (v4 + 0x7FFF) & 0xFFFF8000;
  if ( v5 )
  {
    *(_DWORD *)&work[1].imageParts[2 * buffer + 48] = indexReadOffset;
    v6 = &work[1].imageParts[2 * buffer + 52];
    *(_DWORD *)v6 = 1;
    Stream_AddRequest(
      work->pak->fh,
      work->indexReadOffset + work->pak->index.offset,
      v5,
      &work->indexBuffer[buffer][8],
      0,
      STREAM_PRIO_NORMAL,
      IPak_IndexReadCallback,
      v6,
      0);
    work->indexReadOffset += v5;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x9331B0
void __usercall IPak_WaitReadIndexData(IPakWorkData *work@<edi>, int buffer@<eax>)
{
  if ( (unsigned int)buffer >= 2
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
          517,
          0,
          "(unsigned)(buffer) < (unsigned)(2)",
          "buffer doesn't index IPAK_INDEX_BUFFER_COUNT\n\t%i not in [0, %i)",
          buffer,
          2) )
  {
    __debugbreak();
  }
  if ( !*(_DWORD *)&work[1].imageParts[2 * buffer + 52]
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
          518,
          0,
          "(work->indexBufferState[ buffer ] != 0)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  while ( *(_DWORD *)&work[1].imageParts[2 * buffer + 52] == 1 )
  {
    Sys_CheckQuitRequest();
    NET_Sleep(1u);
  }
  if ( *(_DWORD *)&work[1].imageParts[2 * buffer + 52] == 3 )
  {
    Com_PrintError(
      41,
      "Error while reading ipak %s index data, offset %d\n",
      work->pak->name,
      *(_DWORD *)&work[1].imageParts[2 * buffer + 48]);
    memset((unsigned __int8 *)&work->indexBuffer[buffer][8], 0xFFu, 0x10000u);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x933270
void __cdecl IPak_BeginIndexRead(IPakWorkData *work, IPakLoadedPackfile *pak)
{
  unsigned int v3; // eax
  unsigned __int16 *v4; // edi
  int indexReadOffset; // ecx
  int v6; // eax
  unsigned int v7; // ebx
  int buffer; // [esp+14h] [ebp+8h]
  IPakLoadedPackfile *paka; // [esp+18h] [ebp+Ch]

  if ( !work
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp", 538, 0, "(work)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( !pak
    && !Assert_MyHandler("c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp", 539, 0, "(pak)", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( work->pak
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
          541,
          0,
          "(work->pak == 0)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v3 = 0;
  work->pak = pak;
  work->indexReadOffset = 0;
  work->activeBuffer = 0;
  work->currentEntry = 0;
  buffer = 0;
  paka = (IPakLoadedPackfile *)&work->indexBuffer[0][8];
  v4 = &work[1].imageParts[52];
  while ( 1 )
  {
    *(_DWORD *)v4 = 0;
    if ( v3 >= 2 )
    {
      if ( !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
              496,
              0,
              "(unsigned)(buffer) < (unsigned)(2)",
              "buffer doesn't index IPAK_INDEX_BUFFER_COUNT\n\t%i not in [0, %i)",
              v3,
              2) )
        __debugbreak();
      if ( *(_DWORD *)v4
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
              497,
              0,
              "(work->indexBufferState[ buffer ] == 0)",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    indexReadOffset = work->indexReadOffset;
    v6 = work->pak->index.size - indexReadOffset;
    if ( v6 > 0x10000 )
      v6 = 0x10000;
    v7 = (v6 + 0x7FFF) & 0xFFFF8000;
    if ( v7 )
    {
      *((_DWORD *)v4 - 2) = indexReadOffset;
      *(_DWORD *)v4 = 1;
      Stream_AddRequest(
        work->pak->fh,
        work->indexReadOffset + work->pak->index.offset,
        v7,
        paka,
        0,
        STREAM_PRIO_NORMAL,
        IPak_IndexReadCallback,
        v4,
        0);
      work->indexReadOffset += v7;
    }
    paka = (IPakLoadedPackfile *)((char *)paka + 0x10000);
    v4 += 2;
    if ( ++buffer >= 2 )
      break;
    v3 = buffer;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x9333F0
char __cdecl IPak_CurrentIndexEntry(IPakWorkData *work, IPakIndexEntry *entry)
{
  unsigned int currentEntry; // eax
  unsigned int itemCount; // ecx
  int v5; // ebx
  unsigned int v6; // edx
  int v7; // eax

  if ( !work->pak
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
          559,
          0,
          "(work->pak)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  LODWORD(entry->key) = -1;
  HIDWORD(entry->key) = -1;
  currentEntry = work->currentEntry;
  itemCount = work->pak->index.itemCount;
  if ( currentEntry == itemCount )
    return 0;
  if ( currentEntry >= itemCount
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
          566,
          0,
          "(work->currentEntry < work->pak->index.itemCount)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  IPak_WaitReadIndexData(work, work->activeBuffer);
  v5 = *(_DWORD *)&work[1].imageParts[2 * work->activeBuffer + 48] >> 4;
  if ( work->currentEntry >= v5 + 4096
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
          571,
          0,
          "(work->currentEntry < bufferEntryOffset + ( ( ( 64 * 1024 ) ) / sizeof( IPakIndexEntry ) ))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v6 = work->currentEntry;
  v7 = 2 * ((work->activeBuffer << 12) - v5 + v6 + 673);
  entry->key = work->indexBuffer[0][(work->activeBuffer << 12) - v5 + 8 + v6].key;
  *(_QWORD *)&entry->offset = *((_QWORD *)&work->activeBuffer + v7);
  return 1;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x9334E0
char __cdecl IPak_NextIndexEntry(IPakWorkData *work, IPakIndexEntry *entry)
{
  unsigned int currentEntry; // eax
  unsigned int v4; // eax

  if ( !work->pak
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
          580,
          0,
          "(work->pak)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  LODWORD(entry->key) = -1;
  HIDWORD(entry->key) = -1;
  currentEntry = work->currentEntry;
  if ( currentEntry == work->pak->index.itemCount )
    return 0;
  v4 = currentEntry + 1;
  work->currentEntry = v4;
  if ( (v4 & 0xFFF) == 0 )
  {
    *(_DWORD *)&work[1].imageParts[2 * work->activeBuffer + 52] = 0;
    IPak_ReadIndexData(work, work->activeBuffer);
    if ( ++work->activeBuffer == 2 )
      work->activeBuffer = 0;
  }
  return IPak_CurrentIndexEntry(work, entry);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x933570
void __cdecl IPak_EndIndexRead(IPakWorkData *work)
{
  int v1; // edi
  unsigned __int8 *v2; // ebx
  unsigned __int16 *v3; // esi

  if ( !work->pak
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
          605,
          0,
          "(work->pak)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1 = 0;
  v2 = (unsigned __int8 *)&work->indexBuffer[0][8];
  v3 = &work[1].imageParts[52];
  do
  {
    if ( *(_DWORD *)v3 == 1 )
    {
      if ( (unsigned int)v1 >= 2
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
              517,
              0,
              "(unsigned)(buffer) < (unsigned)(2)",
              "buffer doesn't index IPAK_INDEX_BUFFER_COUNT\n\t%i not in [0, %i)",
              v1,
              2) )
      {
        __debugbreak();
      }
      if ( !*(_DWORD *)v3
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
              518,
              0,
              "(work->indexBufferState[ buffer ] != 0)",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      while ( *(_DWORD *)v3 == 1 )
      {
        Sys_CheckQuitRequest();
        NET_Sleep(1u);
      }
      if ( *(_DWORD *)v3 == 3 )
      {
        Com_PrintError(41, "Error while reading ipak %s index data, offset %d\n", work->pak->name, *((_DWORD *)v3 - 2));
        memset(v2, 0xFFu, 0x10000u);
      }
    }
    ++v1;
    v3 += 2;
    v2 += 0x10000;
  }
  while ( v1 < 2 );
  work->pak = 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x933680
int __cdecl IPak_CompareImagePartHashes(const void *A, const void *B)
{
  unsigned int v2; // esi
  XAssetPoolEntry<GfxImage> *ImageAtIndex; // edi
  XAssetPoolEntry<GfxImage> *v4; // eax
  unsigned int hash; // ecx
  unsigned int v6; // esi
  unsigned __int64 v7; // rax

  v2 = *(unsigned __int16 *)B;
  ImageAtIndex = DB_GetImageAtIndex(*(unsigned __int16 *)A);
  v4 = DB_GetImageAtIndex(v2);
  hash = ImageAtIndex->entry.hash;
  v6 = ImageAtIndex->entry.streamedParts[0].hash;
  HIDWORD(v7) = v4->entry.hash;
  LODWORD(v7) = v4->entry.streamedParts[0].hash;
  if ( hash > HIDWORD(v7) )
    return 1;
  if ( hash < HIDWORD(v7) || v6 < (unsigned int)v7 )
    return -1;
  return __PAIR64__(hash, v6) > v7;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x9336F0
int __cdecl IPak_CompareImageOffsets(const void *A, const void *B)
{
  GfxStreamedPartInfo *ImagePartAtIndex; // esi
  GfxStreamedPartInfo *v3; // eax
  unsigned int v4; // ecx
  unsigned int v5; // edx
  unsigned int v7; // esi
  unsigned int v8; // eax

  ImagePartAtIndex = DB_GetImagePartAtIndex(*(unsigned __int16 *)A);
  v3 = DB_GetImagePartAtIndex(*(unsigned __int16 *)B);
  v4 = *((_DWORD *)v3 + 4) >> 28;
  v5 = *((_DWORD *)ImagePartAtIndex + 4) >> 28;
  if ( v5 < v4 )
    return -1;
  if ( v5 > v4 )
    return 1;
  v7 = *((_DWORD *)ImagePartAtIndex + 3);
  v8 = *((_DWORD *)v3 + 3);
  if ( v8 > v7 )
    return -1;
  return v8 < v7;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x933750
void __cdecl IPak_BuildAdjacencyInfo(unsigned __int8 *workBuffer, int workBufferSize)
{
  unsigned __int8 *v2; // ebx
  unsigned int v3; // esi
  unsigned int v4; // edi
  XAssetPoolEntry<GfxImage> *ImageAtIndex; // eax
  unsigned int v6; // edx
  _DWORD *v7; // ecx
  unsigned int *p_offset; // edi
  XAssetPoolEntry<GfxImage> *v9; // esi
  unsigned int hash; // edi
  unsigned int v11; // ebx
  unsigned int key_high; // ecx
  unsigned int key; // eax
  unsigned int size; // eax
  unsigned int v15; // eax
  GfxStreamedPartInfo *v16; // edi
  unsigned int v17; // ebx
  XAssetPoolEntry<GfxImage> *v18; // edi
  GfxStreamedPartInfo *streamedParts; // esi
  GfxStreamedPartInfo *v20; // edi
  DWORD v21; // eax
  IPakIndexEntry indexEntry; // [esp+0h] [ebp-28h] BYREF
  int startMS; // [esp+10h] [ebp-18h]
  GfxStreamedPartInfo *leftStreamedPart; // [esp+14h] [ebp-14h]
  unsigned int idx; // [esp+18h] [ebp-10h]
  unsigned int imagePartCount; // [esp+1Ch] [ebp-Ch]
  unsigned int imageIndex; // [esp+20h] [ebp-8h]
  unsigned int *v28; // [esp+24h] [ebp-4h]
  unsigned __int8 *workBuffera; // [esp+30h] [ebp+8h]
  unsigned __int8 *pakIdx; // [esp+34h] [ebp+Ch]
  int pakIdxa; // [esp+34h] [ebp+Ch]
  int pakIdxb; // [esp+34h] [ebp+Ch]

  startMS = Sys_Milliseconds();
  if ( (unsigned int)workBufferSize < 0x22A20
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
          700,
          0,
          "(workBufferSize >= sizeof( IPakWorkData ))",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v2 = workBuffer;
  memset(workBuffer, 0, 0x22A20u);
  v3 = 0;
  imagePartCount = 0;
  v4 = 0;
  leftStreamedPart = (GfxStreamedPartInfo *)DB_GetImagePartPoolSize();
  imageIndex = 0;
  if ( leftStreamedPart )
  {
    do
    {
      ImageAtIndex = DB_GetImageAtIndex(v4);
      v6 = 0;
      if ( ImageAtIndex->entry.streamedPartCount )
      {
        pakIdx = &v2[2 * v3 + 16];
        v7 = (_DWORD *)((char *)ImageAtIndex->entry.streamedParts + 16);
        do
        {
          *(v7 - 1) = 0;
          *v7 = 0;
          v7[1] = 0x3FFFFFFF;
          if ( ImageAtIndex->entry.streaming )
          {
            *(_WORD *)pakIdx = v4 + v6;
            ++v3;
            pakIdx += 2;
            v4 = imageIndex;
          }
          ++v6;
          v7 += 6;
        }
        while ( v6 < ImageAtIndex->entry.streamedPartCount );
        v2 = workBuffer;
      }
      imageIndex = ++v4;
    }
    while ( v4 < (unsigned int)leftStreamedPart );
    imagePartCount = v3;
  }
  leftStreamedPart = (GfxStreamedPartInfo *)(v2 + 16);
  qsort(v2 + 16, v3, 2u, IPak_CompareImagePartHashes);
  p_offset = &s_loadedPackfiles[0].data.offset;
  pakIdxa = 0;
  v28 = &s_loadedPackfiles[0].data.offset;
  do
  {
    if ( !p_offset[8] )
      goto LABEL_42;
    IPak_BeginIndexRead((IPakWorkData *)v2, (IPakLoadedPackfile *)(p_offset - 17));
    idx = 0;
    if ( !v3 )
      goto LABEL_41;
    imageIndex = (unsigned int)leftStreamedPart;
    do
    {
      v9 = DB_GetImageAtIndex(*(unsigned __int16 *)imageIndex);
      if ( !v9->entry.streamedPartCount
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
              755,
              0,
              "(imagePartIndex % 1 < image->streamedPartCount)",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      hash = v9->entry.hash;
      v11 = v9->entry.streamedParts[0].hash;
      if ( (*((_DWORD *)v9->entry.streamedParts + 5) & 0x80000000) == 0x80000000
        && s_loadedPackfiles[*((_DWORD *)v9->entry.streamedParts + 4) >> 28].priority >= (signed int)v28[9] )
      {
        goto LABEL_39;
      }
      IPak_CurrentIndexEntry((IPakWorkData *)workBuffer, &indexEntry);
      key_high = HIDWORD(indexEntry.key);
      if ( hash >= HIDWORD(indexEntry.key) )
      {
        if ( hash <= HIDWORD(indexEntry.key) )
        {
          key = indexEntry.key;
          if ( v11 <= LODWORD(indexEntry.key) )
            goto LABEL_30;
        }
        while ( 1 )
        {
          do
          {
            IPak_NextIndexEntry((IPakWorkData *)workBuffer, &indexEntry);
            key_high = HIDWORD(indexEntry.key);
          }
          while ( hash > HIDWORD(indexEntry.key) );
          if ( hash < HIDWORD(indexEntry.key) )
            break;
          key = indexEntry.key;
          if ( v11 <= LODWORD(indexEntry.key) )
            goto LABEL_30;
        }
      }
      key = indexEntry.key;
LABEL_30:
      if ( (key_high & key) == -1 )
        break;
      if ( hash >= key_high && (hash > key_high || v11 >= key) )
      {
        if ( (v11 != key || hash != key_high)
          && !Assert_MyHandler(
                "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
                790,
                0,
                "(imageKey == indexEntry.key)",
                (const char *)&pBlock) )
        {
          __debugbreak();
        }
        size = indexEntry.size;
        *((_DWORD *)v9->entry.streamedParts + 4) = (pakIdxa << 28) ^ indexEntry.size & 0xFFFFFFF;
        v15 = *((_DWORD *)v9->entry.streamedParts + 5) & 0x3FFFFFFF | (size >> 1) & 0xC0000000 | 0x80000000;
        *((_DWORD *)v9->entry.streamedParts + 3) = indexEntry.offset + *v28;
        *((_DWORD *)v9->entry.streamedParts + 5) = v15;
      }
LABEL_39:
      imageIndex += 2;
      ++idx;
    }
    while ( idx < imagePartCount );
    p_offset = v28;
    v3 = imagePartCount;
    v2 = workBuffer;
LABEL_41:
    IPak_EndIndexRead((IPakWorkData *)v2);
LABEL_42:
    ++pakIdxa;
    p_offset += 27;
    v28 = p_offset;
  }
  while ( (int)p_offset < 136283468 );
  v16 = leftStreamedPart;
  qsort(leftStreamedPart, v3, 2u, IPak_CompareImageOffsets);
  pakIdxb = -1;
  idx = 0x7FFF;
  leftStreamedPart = 0;
  if ( v3 )
  {
    workBuffera = (unsigned __int8 *)v16;
    imagePartCount = v3;
    do
    {
      v17 = *(unsigned __int16 *)workBuffera;
      imageIndex = v17;
      v18 = DB_GetImageAtIndex(v17);
      if ( !v18->entry.streamedPartCount
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
              812,
              0,
              "(imagePartIndex % 1 < image->streamedPartCount)",
              (const char *)&pBlock) )
      {
        __debugbreak();
      }
      streamedParts = v18->entry.streamedParts;
      if ( (*((_DWORD *)v18->entry.streamedParts + 5) & 0x7FFF) != 0x7FFF
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
              816,
              0,
              "((streamedPart->adjacentLeft == ((uint)0x7fff)))",
              "(image->name) = %s",
              v18->entry.name) )
      {
        __debugbreak();
      }
      if ( (*((_DWORD *)v18->entry.streamedParts + 5) & 0x3FFF8000) != 1073709056
        && !Assert_MyHandler(
              "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
              817,
              0,
              "((streamedPart->adjacentRight == ((uint)0x7fff)))",
              "(image->name) = %s",
              v18->entry.name) )
      {
        __debugbreak();
      }
      if ( *((int *)&v18->next + 14) < 0 )
      {
        if ( pakIdxb == *((_DWORD *)v18->entry.streamedParts + 4) >> 28 )
        {
          v20 = leftStreamedPart;
          *((_DWORD *)streamedParts + 5) ^= (*((_DWORD *)streamedParts + 5) ^ idx) & 0x7FFF;
          if ( !v20
            && !Assert_MyHandler(
                  "c:\\t6\\code\\src_noserver\\ipak\\ipak_game.cpp",
                  827,
                  0,
                  "(leftStreamedPart)",
                  (const char *)&pBlock) )
          {
            __debugbreak();
          }
          *((_DWORD *)v20 + 5) ^= (*((_DWORD *)v20 + 5) ^ (v17 << 15)) & 0x3FFF8000;
        }
        else
        {
          pakIdxb = *((_DWORD *)v18->entry.streamedParts + 4) >> 28;
        }
        leftStreamedPart = streamedParts;
        idx = (unsigned __int16)imageIndex;
      }
      workBuffera += 2;
      --imagePartCount;
    }
    while ( imagePartCount );
  }
  v21 = Sys_Milliseconds();
  Com_Printf(41, "Built adjacency info for IPaks %dms\n", v21 - startMS);
  s_adjacencyInfoStale = 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x933BB0
void __cdecl IPak_InvalidateImages()
{
  unsigned int *p_size; // edi
  unsigned int i; // esi
  GfxStreamedPartInfo *ImagePartAtIndex; // eax
  int v3; // ecx
  unsigned int v4; // edx
  int v5; // [esp+Ch] [ebp-8h]
  unsigned int pakIdx; // [esp+10h] [ebp-4h]

  PIXBeginNamedEvent(-1, "IPak_InvalidateImages");
  pakIdx = 0;
  p_size = &s_loadedPackfiles[0].data.size;
  v5 = 16;
  do
  {
    if ( !p_size[7] )
    {
      if ( *p_size )
      {
        for ( i = 0; i < DB_GetImagePartPoolSize(); ++i )
        {
          ImagePartAtIndex = DB_GetImagePartAtIndex(i);
          v3 = *((_DWORD *)ImagePartAtIndex + 5);
          if ( v3 < 0 )
          {
            v4 = *((_DWORD *)ImagePartAtIndex + 4);
            if ( v4 >> 28 == pakIdx )
            {
              *((_DWORD *)ImagePartAtIndex + 3) = 0;
              *((_DWORD *)ImagePartAtIndex + 4) = v4 & 0xF0000000;
              *((_DWORD *)ImagePartAtIndex + 5) = v3 & 0x40000000 | 0x3FFFFFFF;
            }
          }
        }
      }
    }
    ++pakIdx;
    p_size += 27;
    --v5;
  }
  while ( v5 );
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x933C60
void __cdecl IPak_RemovePackfilesForZone(const char *zoneName)
{
  _BYTE *v1; // eax
  const char *name; // [esp+0h] [ebp-48h] BYREF
  char zoneNameRoot[64]; // [esp+4h] [ebp-44h] BYREF

  PIXBeginNamedEvent(-1, "IPak_RemovePackfilesForZone");
  name = 0;
  strcpy(zoneNameRoot, zoneName);
  strchr((unsigned __int8 *)zoneNameRoot, 0x21u);
  if ( v1 )
    *v1 = 0;
  while ( KeyValuePairs_GetNextValue("ipak_read", zoneNameRoot, &name) )
    IPak_RemovePackfile(name);
  IPak_InvalidateImages();
  if ( Sys_IsRenderThread() )
    D3DPERF_EndEvent();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x933D20
int __cdecl BG_Actor_GetAnimStateIndex(unsigned __int16 animStateName)
{
  int result; // eax
  char *v2; // eax
  const char *v3; // eax

  result = 0;
  while ( *s_animStateNames[result].name != animStateName )
  {
    if ( ++result >= 47 )
    {
      if ( result != 47 )
      {
        v2 = SL_ConvertToString(animStateName);
        v3 = va("Actor_GetAnimStateIndex: Could not find anim state %s", v2);
        if ( !Assert_MyHandler(
                "c:\\t6\\code\\src_noserver\\bgame\\bg_actor.cpp",
                201,
                0,
                "(i == ACTOR_ANIMATION_COUNT)",
                "%s",
                v3) )
          __debugbreak();
      }
      return 0;
    }
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x933D80
char *__cdecl BG_Actor_GetAnimStateName(int animStateIndex)
{
  if ( (animStateIndex & 0xFFFFFEFF) >= 0x2F
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_actor.cpp",
          251,
          0,
          "(unsigned)(animStateIndex & ~(1<<(9-1))) < (unsigned)((sizeof( s_animStateNames ) / (sizeof( s_animStateNames["
          "0] ) * (sizeof( s_animStateNames ) != 4 || sizeof( s_animStateNames[0] ) <= 4))))",
          "animStateIndex & ~ANIM_STATE_TOGGLEBIT doesn't index ARRAY_COUNT( s_animStateNames )\n\t%i not in [0, %i)",
          animStateIndex & 0xFFFFFEFF,
          47) )
  {
    __debugbreak();
  }
  return SL_ConvertToString(*s_animStateNames[animStateIndex & 0xFFFFFEFF].name);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdpooledstorage.cpp:0x933DE0
char *__cdecl BG_Actor_GetAnimStateCategoryName(int animStateIndex)
{
  if ( (animStateIndex & 0xFFFFFEFF) >= 0x2F
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_actor.cpp",
          268,
          0,
          "(unsigned)(animStateIndex & ~(1<<(9-1))) < (unsigned)((sizeof( s_animStateNames ) / (sizeof( s_animStateNames["
          "0] ) * (sizeof( s_animStateNames ) != 4 || sizeof( s_animStateNames[0] ) <= 4))))",
          "animStateIndex & ~ANIM_STATE_TOGGLEBIT doesn't index ARRAY_COUNT( s_animStateNames )\n\t%i not in [0, %i)",
          animStateIndex & 0xFFFFFEFF,
          47) )
  {
    __debugbreak();
  }
  return SL_ConvertToString(*s_animStateCategories[s_animStateNames[animStateIndex & 0xFFFFFEFF].category]);
}

#endif // __UNIMPLEMENTED__
