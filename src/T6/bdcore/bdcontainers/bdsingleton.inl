// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdsingleton.inl:0x4FC960
void __cdecl CL_AddDebugString(const vec3_t *xyz, const vec4_t *color, float scale, const char *text, int duration)
{
  int v5; // esi
  clientDebugStringInfo_t *p_svStrings; // edi

  if ( cls.rendererStarted && CreateDebugStringsIfNeeded() )
  {
    v5 = *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 16);
    p_svStrings = &cls.debug.svStrings;
    if ( !v5 )
      p_svStrings = &cls.debug.clStrings;
    AddDebugStringInternal(color->v, &xyz->x, p_svStrings, SLODWORD(scale), text, duration);
    if ( v5 )
      cls.debug.fromServer = 1;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsingleton.inl:0x4FCB00
int __usercall AddDebugSphereInternal@<eax>(
        float *a1@<edx>,
        _DWORD *a2@<ecx>,
        int a3@<xmm0>,
        const vec3_t *center,
        int sideCount,
        int depthTest,
        int duration)
{
  int result; // eax
  int v8; // edi
  int v9; // eax
  int v10; // eax

  result = a2[1];
  if ( result + 1 <= *a2 )
  {
    v8 = a2[2];
    v9 = 5 * result;
    *(float *)(v8 + 8 * v9) = center->x;
    v10 = v8 + 8 * v9;
    *(float *)(v10 + 4) = center->y;
    *(float *)(v10 + 8) = center->z;
    *(_DWORD *)(v10 + 12) = a3;
    *(float *)(v10 + 20) = *a1;
    *(float *)(v10 + 24) = a1[1];
    *(float *)(v10 + 28) = a1[2];
    *(float *)(v10 + 32) = a1[3];
    *(_DWORD *)(v10 + 36) = depthTest;
    *(_DWORD *)(v10 + 16) = sideCount;
    result = a2[1];
    *(_DWORD *)(a2[3] + 4 * result) = duration;
    ++a2[1];
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsingleton.inl:0x4FCB00
int __usercall AddDebugSphereInternal@<eax>(
        float *a1@<edx>,
        _DWORD *a2@<ecx>,
        int a3@<xmm0>,
        const vec3_t *center,
        int sideCount,
        int depthTest,
        int duration)
{
  int result; // eax
  int v8; // edi
  int v9; // eax
  int v10; // eax

  result = a2[1];
  if ( result + 1 <= *a2 )
  {
    v8 = a2[2];
    v9 = 5 * result;
    *(float *)(v8 + 8 * v9) = center->x;
    v10 = v8 + 8 * v9;
    *(float *)(v10 + 4) = center->y;
    *(float *)(v10 + 8) = center->z;
    *(_DWORD *)(v10 + 12) = a3;
    *(float *)(v10 + 20) = *a1;
    *(float *)(v10 + 24) = a1[1];
    *(float *)(v10 + 28) = a1[2];
    *(float *)(v10 + 32) = a1[3];
    *(_DWORD *)(v10 + 36) = depthTest;
    *(_DWORD *)(v10 + 16) = sideCount;
    result = a2[1];
    *(_DWORD *)(a2[3] + 4 * result) = duration;
    ++a2[1];
  }
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsingleton.inl:0x5321C0
int __usercall parseBandwidthTestPacketSyn@<eax>(
        msg_t *msg@<ecx>,
        int seq@<eax>,
        __int64 localControllerIndex,
        __int64 from_8,
        int from_16)
{
  int Long; // ebx
  int v9; // edi
  netadr_t v10; // [esp-14h] [ebp-20h]

  Long = 0;
  if ( seq > Dvar_GetInt(partymigrate_MaxBWPackets) )
  {
    Com_PrintWarning(51, "Received invalid seq %i\n", seq);
    return Long;
  }
  Long = MSG_ReadLong(msg);
  v9 = MSG_ReadLong(msg);
  if ( v9 == Com_BlockChecksumKey32(&msg->data[msg->readcount], msg->cursize - msg->readcount, 0) )
  {
    *(_QWORD *)v10.ip = localControllerIndex;
    *(_QWORD *)&v10.type = from_8;
    *(_DWORD *)&v10.serverID = from_16;
    if ( Party_FindMember(&g_lobbyData, v10) != -1 )
      return Long;
    Com_PrintError(51, "Received bw test packet from unknown peer\n");
  }
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsingleton.inl:0x5321C0
int __usercall parseBandwidthTestPacketSyn@<eax>(
        msg_t *msg@<ecx>,
        int seq@<eax>,
        __int64 localControllerIndex,
        __int64 from_8,
        int from_16)
{
  int Long; // ebx
  int v9; // edi
  netadr_t v10; // [esp-14h] [ebp-20h]

  Long = 0;
  if ( seq > Dvar_GetInt(partymigrate_MaxBWPackets) )
  {
    Com_PrintWarning(51, "Received invalid seq %i\n", seq);
    return Long;
  }
  Long = MSG_ReadLong(msg);
  v9 = MSG_ReadLong(msg);
  if ( v9 == Com_BlockChecksumKey32(&msg->data[msg->readcount], msg->cursize - msg->readcount, 0) )
  {
    *(_QWORD *)v10.ip = localControllerIndex;
    *(_QWORD *)&v10.type = from_8;
    *(_DWORD *)&v10.serverID = from_16;
    if ( Party_FindMember(&g_lobbyData, v10) != -1 )
      return Long;
    Com_PrintError(51, "Received bw test packet from unknown peer\n");
  }
  return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsingleton.inl:0x532270
void __cdecl sendTestPacketAck(ControllerIndex_t localControllerIndex, const netadr_t from, int fromMS, int seq)
{
  netsrc_t NetworkID; // eax
  unsigned __int8 *data; // [esp-8h] [ebp-5Ch]
  int cursize; // [esp-4h] [ebp-58h]
  msg_t msg; // [esp+0h] [ebp-54h] BYREF
  unsigned __int8 msgBuf[32]; // [esp+30h] [ebp-24h] BYREF

  memset(msgBuf, 0, sizeof(msgBuf));
  MSG_Init(&msg, msgBuf, 32);
  MSG_WriteString(&msg, "b");
  MSG_WriteBit0(&msg);
  MSG_WriteByte(&msg, seq);
  MSG_WriteLong(&msg, fromMS);
  cursize = msg.cursize;
  data = msg.data;
  NetworkID = Com_ControllerIndex_GetNetworkID(localControllerIndex);
  NET_OutOfBandData(NetworkID, from, data, cursize);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsingleton.inl:0x532270
void __cdecl sendTestPacketAck(ControllerIndex_t localControllerIndex, const netadr_t from, int fromMS, int seq)
{
  netsrc_t NetworkID; // eax
  unsigned __int8 *data; // [esp-8h] [ebp-5Ch]
  int cursize; // [esp-4h] [ebp-58h]
  msg_t msg; // [esp+0h] [ebp-54h] BYREF
  unsigned __int8 msgBuf[32]; // [esp+30h] [ebp-24h] BYREF

  memset(msgBuf, 0, sizeof(msgBuf));
  MSG_Init(&msg, msgBuf, 32);
  MSG_WriteString(&msg, "b");
  MSG_WriteBit0(&msg);
  MSG_WriteByte(&msg, seq);
  MSG_WriteLong(&msg, fromMS);
  cursize = msg.cursize;
  data = msg.data;
  NetworkID = Com_ControllerIndex_GetNetworkID(localControllerIndex);
  NET_OutOfBandData(NetworkID, from, data, cursize);
}

#endif // __UNIMPLEMENTED__
