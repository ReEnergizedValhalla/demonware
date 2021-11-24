// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdplatformstreamsocket-win32.cpp:0x9D18A0
void __thiscall bdTaskResult::bdTaskResult(bdTaskResult *this)
{
  this->__vftable = (bdTaskResult_vtbl *)&bdTaskResult::`vftable';
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformstreamsocket-win32.cpp:0x9D18B0
void __thiscall bdTaskResult::~bdTaskResult(bdTaskResult *this)
{
  this->__vftable = (bdTaskResult_vtbl *)&bdTaskResult::`vftable';
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformstreamsocket-win32.cpp:0x9D18C0
void __thiscall bdMatchMakingInfo::bdMatchMakingInfo(bdMatchMakingInfo *this)
{
  bdTaskResult::bdTaskResult(this);
  this->__vftable = (bdMatchMakingInfo_vtbl *)&bdMatchMakingInfo::`vftable';
  bdSecurityID::bdSecurityID(&this->m_sessionID);
  this->m_hostAddrSize = 0;
  this->m_maxPlayers = 0;
  this->m_numPlayers = 0;
  this->m_gameType = 0;
  memset(this->m_hostAddr, 0, sizeof(this->m_hostAddr));
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformstreamsocket-win32.cpp:0x9D1940
void __thiscall bdMatchMakingInfo::~bdMatchMakingInfo(bdMatchMakingInfo *this)
{
  this->__vftable = (bdMatchMakingInfo_vtbl *)&bdMatchMakingInfo::`vftable';
  bdTaskResult::~bdTaskResult(this);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformstreamsocket-win32.cpp:0x9D1950
void __thiscall bdMatchMakingInfo::serialize(bdMatchMakingInfo *this, bdByteBuffer *buffer)
{
  bdByteBuffer::writeBlob(buffer, this->m_hostAddr, this->m_hostAddrSize);
  bdByteBuffer::writeUInt32(buffer, this->m_gameType);
  bdByteBuffer::writeUInt32(buffer, this->m_maxPlayers);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformstreamsocket-win32.cpp:0x9D1990
bdMatchMakingInfo *__thiscall bdMatchMakingInfo::`scalar deleting destructor'(bdMatchMakingInfo *this, unsigned int a2)
{
  bdMatchMakingInfo::~bdMatchMakingInfo(this);
  if ( (a2 & 1) != 0 )
    bdMemory::deallocate(this);
  return this;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformstreamsocket-win32.cpp:0x9D19C0
void __thiscall bdMatchMakingInfo::setHostAddr(bdMatchMakingInfo *this, bdReference<bdCommonAddr> localCommonAddr)
{
  bdCommonAddr *m_ptr; // edi

  m_ptr = localCommonAddr.m_ptr;
  if ( localCommonAddr.m_ptr )
  {
    bdCommonAddr::serialize(localCommonAddr.m_ptr, this->m_hostAddr);
    m_ptr = localCommonAddr.m_ptr;
    this->m_hostAddrSize = 37;
  }
  else
  {
    memset(this->m_hostAddr, 0, sizeof(this->m_hostAddr));
    this->m_hostAddrSize = 0;
  }
  if ( m_ptr && !InterlockedDecrement(&m_ptr->m_refCount) )
  {
    if ( localCommonAddr.m_ptr )
      ((void (__thiscall *)(bdCommonAddr *, int))localCommonAddr.m_ptr->~bdReferencable)(localCommonAddr.m_ptr, 1);
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformstreamsocket-win32.cpp:0x9D1A70
bdReference<bdCommonAddr> *__thiscall bdMatchMakingInfo::getHostAddrAsCommonAddr(
        bdMatchMakingInfo *this,
        bdReference<bdCommonAddr> *result,
        bdReference<bdCommonAddr> localCommonAddr)
{
  bdCommonAddr *v4; // edi
  bool v5; // zf
  bdCommonAddr *v6; // eax
  bdCommonAddr *v7; // eax
  bdCommonAddr *m_ptr; // eax
  bdReference<bdCommonAddr> v10; // [esp-8h] [ebp-2Ch] BYREF
  unsigned __int8 *m_hostAddr; // [esp-4h] [ebp-28h]
  bdReference<bdCommonAddr> *v12; // [esp+10h] [ebp-14h]
  int v13; // [esp+14h] [ebp-10h]
  int v14; // [esp+20h] [ebp-4h]

  v4 = 0;
  v13 = 0;
  v14 = 1;
  result->m_ptr = 0;
  v5 = this->m_hostAddrSize == 37;
  v13 = 1;
  if ( v5 )
  {
    v6 = (bdCommonAddr *)bdMemory::allocate(0x28u);
    v12 = (bdReference<bdCommonAddr> *)v6;
    LOBYTE(v14) = 2;
    if ( v6 )
    {
      bdCommonAddr::bdCommonAddr(v6);
      v4 = v7;
    }
    m_ptr = result->m_ptr;
    LOBYTE(v14) = 1;
    if ( m_ptr && !InterlockedDecrement(&m_ptr->m_refCount) && result->m_ptr )
      ((void (__thiscall *)(bdCommonAddr *, int))result->m_ptr->~bdReferencable)(result->m_ptr, 1);
    result->m_ptr = v4;
    if ( v4 )
      InterlockedIncrement(&v4->m_refCount);
    m_hostAddr = this->m_hostAddr;
    v10.m_ptr = localCommonAddr.m_ptr;
    v12 = &v10;
    if ( localCommonAddr.m_ptr )
      InterlockedIncrement(&localCommonAddr.m_ptr->m_refCount);
    bdCommonAddr::deserialize(result->m_ptr, v10, m_hostAddr);
    if ( !localCommonAddr.m_ptr )
      bdLogMessage(
        BD_LOG_WARNING,
        "warn/",
        "match making info",
        "c:\\t6\\code\\DemonWare\\bdLobby\\bdMatchMaking\\bdMatchMakingInfo.cpp",
        "bdMatchMakingInfo::getHostAddrAsCommonAddr",
        0x4Fu,
        "localCommonAddr not set. ");
  }
  else
  {
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "match making info",
      "c:\\t6\\code\\DemonWare\\bdLobby\\bdMatchMaking\\bdMatchMakingInfo.cpp",
      "bdMatchMakingInfo::getHostAddrAsCommonAddr",
      0x54u,
      "m_hostAddrSize != BD_COMMON_ADDR_SERIALIZED_SIZE, ");
  }
  LOBYTE(v14) = 0;
  if ( localCommonAddr.m_ptr && !InterlockedDecrement(&localCommonAddr.m_ptr->m_refCount) )
    ((void (__thiscall *)(bdCommonAddr *, int))localCommonAddr.m_ptr->~bdReferencable)(localCommonAddr.m_ptr, 1);
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformstreamsocket-win32.cpp:0x9D1BC0
bool __thiscall bdMatchMakingInfo::deserialize(bdMatchMakingInfo *this, bdReference<bdByteBuffer> buffer)
{
  bool v3; // al
  bool v4; // al
  bool v5; // al
  bool v6; // al
  bool v7; // bl
  unsigned int intValue; // [esp+Ch] [ebp-18h] BYREF
  unsigned int uintValue; // [esp+10h] [ebp-14h] BYREF
  unsigned int length; // [esp+14h] [ebp-10h] BYREF
  int v12; // [esp+20h] [ebp-4h]

  v12 = 0;
  length = 255;
  v3 = bdByteBuffer::readBlob(buffer.m_ptr, this->m_hostAddr, &length);
  this->m_hostAddrSize = length;
  length = 8;
  v4 = v3 && bdByteBuffer::readBlob(buffer.m_ptr, this->m_sessionID.ab, &length);
  intValue = 0;
  v5 = v4 && bdByteBuffer::readUInt32(buffer.m_ptr, &intValue);
  this->m_gameType = intValue;
  uintValue = 0;
  v6 = v5 && bdByteBuffer::readUInt32(buffer.m_ptr, &uintValue);
  this->m_maxPlayers = uintValue;
  v7 = v6 && bdByteBuffer::readUInt32(buffer.m_ptr, &uintValue);
  this->m_numPlayers = uintValue;
  if ( !v7 )
    bdLogMessage(
      BD_LOG_ERROR,
      "err/",
      "match making info",
      "c:\\t6\\code\\DemonWare\\bdLobby\\bdMatchMaking\\bdMatchMakingInfo.cpp",
      "bdMatchMakingInfo::deserialize",
      0x78u,
      "Deserialization failed");
  v12 = -1;
  if ( buffer.m_ptr && !InterlockedDecrement(&buffer.m_ptr->m_refCount) )
    ((void (__thiscall *)(bdByteBuffer *, int))buffer.m_ptr->~bdReferencable)(buffer.m_ptr, 1);
  return v7;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformstreamsocket-win32.cpp:0x9D1D20
bdReference<bdRemoteTask> *__thiscall bdMatchMaking::createSession(
        bdMatchMaking *this,
        bdReference<bdRemoteTask> *result,
        bdMatchMakingInfo *sessionInfo,
        bdSessionID *const sessionCredentials)
{
  bdMatchMakingInfo *v4; // edi
  unsigned int v5; // esi
  bdTaskByteBuffer *v6; // eax
  int v7; // eax
  bdLobbyErrorCode started; // eax

  result->m_ptr = 0;
  v4 = sessionInfo;
  v5 = sessionInfo->sizeOf(sessionInfo) + 65;
  v6 = (bdTaskByteBuffer *)bdMemory::allocate(0x2Cu);
  if ( v6 )
    bdTaskByteBuffer::bdTaskByteBuffer(v6, v5, 1);
  else
    v7 = 0;
  sessionInfo = (bdMatchMakingInfo *)v7;
  if ( v7 )
    InterlockedIncrement((volatile LONG *)(v7 + 4));
  bdRemoteTaskManager::initTaskBuffer((bdReference<bdTaskByteBuffer> *)&sessionInfo, 0x15u, 1u);
  v4->serialize(v4, (bdByteBuffer *)sessionInfo);
  started = bdRemoteTaskManager::startTask(
              this->m_remoteTaskManager,
              result,
              (bdReference<bdTaskByteBuffer> *)&sessionInfo);
  if ( started )
    bdLogMessage(
      BD_LOG_WARNING,
      "warn/",
      "matchmaking",
      "c:\\t6\\code\\DemonWare\\bdLobby\\bdMatchMaking\\bdMatchMaking.cpp",
      "bdMatchMaking::createSession",
      0x2Du,
      "Failed to start task: Error %i",
      started);
  else
    bdRemoteTask::setTaskResult(result->m_ptr, sessionCredentials, 1u);
  if ( sessionInfo && !InterlockedDecrement((volatile LONG *)&sessionInfo->m_sessionID) && sessionInfo )
    ((void (__thiscall *)(bdMatchMakingInfo *, int))sessionInfo->~bdTaskResult)(sessionInfo, 1);
  return result;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdplatformstreamsocket-win32.cpp:0x9D1E50
bdReference<bdRemoteTask> *__thiscall bdMatchMaking::updateSessionPlayers(
        bdMatchMaking *this,
        bdReference<bdRemoteTask> *result,
        const bdSessionID *sessionID,
        bdMatchMakingInfo *const sessionInfo,
        unsigned int numPlayers)
{
  bdMatchMakingInfo *v5; // edi
  unsigned int v6; // esi
  bdTaskByteBuffer *v7; // eax
  int v8; // eax
  bdLobbyErrorCode started; // eax

  result->m_ptr = 0;
  v5 = sessionInfo;
  v6 = sessionInfo->sizeOf(sessionInfo) + 83;
  v7 = (bdTaskByteBuffer *)bdMemory::allocate(0x2Cu);
  if ( v7 )
    bdTaskByteBuffer::bdTaskByteBuffer(v7, v6, 1);
  else
    v8 = 0;
  sessionInfo = (bdMatchMakingInfo *const)v8;
  if ( v8 )
    InterlockedIncrement((volatile LONG *)(v8 + 4));
  bdRemoteTaskManager::initTaskBuffer((bdReference<bdTaskByteBuffer> *)&sessionInfo, 0x15u, 0xCu);
  sessionID->serialize((bdSessionID *)sessionID, (bdByteBuffer *)sessionInfo);
  bdByteBuffer::writeUInt32((bdByteBuffer *)sessionInfo, numPlayers);
  v5->serialize(v5, (bdByteBuffer *)sessionInfo);
  started = bdRemoteTaskManager::startTask(
              this->m_remoteTaskManager,
              result,
              (bdReference<bdTaskByteBuffer> *)&sessionInfo);
  if ( started )
    bdLogMessage(
      BD_LOG_WARNING,
      "warn/",
      "matchmaking",
      "c:\\t6\\code\\DemonWare\\bdLobby\\bdMatchMaking\\bdMatchMaking.cpp",
      "bdMatchMaking::updateSessionPlayers",
      0x5Eu,
      "Failed to start task: Error %i",
      started);
  if ( sessionInfo && !InterlockedDecrement((volatile LONG *)&sessionInfo->m_sessionID) && sessionInfo )
    ((void (__thiscall *)(bdMatchMakingInfo *const, int))sessionInfo->~bdTaskResult)(sessionInfo, 1);
  return result;
}

#endif // __UNIMPLEMENTED__
