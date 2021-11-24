// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdplatformsemaphore-win32.cpp:0x9D1F90
bdReference<bdRemoteTask> *__thiscall bdMatchMaking::deleteSession(
        bdMatchMaking *this,
        bdReference<bdRemoteTask> *result,
        const bdSessionID *sessionID)
{
  bdTaskByteBuffer *v4; // eax
  bdTaskByteBuffer *v5; // eax
  bdLobbyErrorCode started; // eax
  bdReference<bdTaskByteBuffer> buffer; // [esp+14h] [ebp-10h] BYREF
  int v9; // [esp+20h] [ebp-4h]

  result->m_ptr = 0;
  v4 = (bdTaskByteBuffer *)bdMemory::allocate(0x2Cu);
  v9 = 1;
  if ( v4 )
    bdTaskByteBuffer::bdTaskByteBuffer(v4, 0x4Du, 1);
  else
    v5 = 0;
  buffer.m_ptr = v5;
  if ( v5 )
    InterlockedIncrement(&v5->m_refCount);
  v9 = 2;
  bdRemoteTaskManager::initTaskBuffer(&buffer, 0x15u, 3u);
  sessionID->serialize((bdSessionID *)sessionID, buffer.m_ptr);
  started = bdRemoteTaskManager::startTask(this->m_remoteTaskManager, result, &buffer);
  if ( started )
    bdLogMessage(
      BD_LOG_WARNING,
      "warn/",
      "matchmaking",
      "c:\\t6\\code\\DemonWare\\bdLobby\\bdMatchMaking\\bdMatchMaking.cpp",
      "bdMatchMaking::deleteSession",
      0x71u,
      "Failed to start task: Error %i",
      started);
  LOBYTE(v9) = 0;
  if ( buffer.m_ptr && !InterlockedDecrement(&buffer.m_ptr->m_refCount) && buffer.m_ptr )
    ((void (__thiscall *)(bdTaskByteBuffer *, int))buffer.m_ptr->~bdReferencable)(buffer.m_ptr, 1);
  return result;
}

#endif // __UNIMPLEMENTED__
