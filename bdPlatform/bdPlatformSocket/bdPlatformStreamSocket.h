// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

class bdPlatformStreamSocket
{
public:
    static SOCKET create(bdBool blocking);
    static bdSocketStatusCode connect(SOCKET handle, bdInAddr addr, bdUInt16 port);
    static bdBool close(SOCKET handle);
    static bdBool checkSocketException(SOCKET handle);
    static bdBool isWritable(SOCKET handle, bdSocketStatusCode* error);
    static bdBool getSocketAddr(SOCKET handle, bdInAddr* socketAddr);
    static bdInt send(SOCKET handle, const void* const data, bdUInt length);
    static bdInt recieve(SOCKET handle, void* data, bdUInt length);
    static bdBool isWritable(SOCKET handle);
};