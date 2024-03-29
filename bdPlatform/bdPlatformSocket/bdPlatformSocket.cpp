// SPDX-License-Identifier: GPL-3.0-or-later
#include "bdPlatform/bdPlatform.h"

__int64 bdPlatformSocket::m_totalBytesSent = 0;
__int64 bdPlatformSocket::m_totalPacketsSent = 0;
__int64 bdPlatformSocket::m_totalBytesRecvd = 0;
__int64 bdPlatformSocket::m_totalPacketsRecvd = 0;

SOCKET bdPlatformSocket::create(bool blocking, bool broadcast)
{
    SOCKET sockBroadcast;
    u_long nonblocking;

    sockBroadcast = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (broadcast)
    {
        if (setsockopt(sockBroadcast, 0xFFFF, 32, (char*)&broadcast, sizeof(&broadcast)))
        {
            return -1;
        }
    }
    nonblocking = !blocking;
    if (ioctlsocket(sockBroadcast, 0x8004667E, &nonblocking))
    {
        return -1;
    }
    return sockBroadcast;
}

bdSocketStatusCode bdPlatformSocket::bind(int* handle, bdInAddr addr, unsigned short port)
{
    sockaddr_in localAddr;

    if (*handle == -1)
    {
        return BD_NET_INVALID_HANDLE;
    }
    memset(&localAddr, 0, sizeof(localAddr));
    localAddr.sin_family = 2;
    localAddr.sin_addr.S_un.S_addr = addr.inUn.m_iaddr;
    localAddr.sin_port = htons(port);

    if (::bind(*handle, (sockaddr*)&localAddr, sizeof(localAddr)))
    {
        return BD_NET_SUCCESS;
    }
    bdLogMessage(BD_LOG_WARNING, "warn/", "platform/socket", __FILE__, __FUNCTION__, __LINE__, "Call to bind() failed, WSAGetLastError: %d", WSAGetLastError());
    closesocket(*handle);
    if (WSAGetLastError() == 10013 || 10047 || 10049)
    {
        return BD_NET_ADDRESS_IN_USE;
    }
    return BD_NET_ERROR;
}

bdInt bdPlatformSocket::sendTo(SOCKET handle, bdInAddr addr, unsigned short port, const void* data, unsigned int len)
{
    sockaddr_in recpt;

    if (handle == -1)
    {
        return BD_NET_INVALID_HANDLE;
    }
    memset(&recpt, 0, sizeof(recpt));
    recpt.sin_family = 2;
    recpt.sin_addr.S_un.S_addr = addr.inUn.m_iaddr;
    recpt.sin_port = htons(port);

    int bytesSent = sendto(handle, reinterpret_cast<const char*>(data), len, 0, (sockaddr*)&recpt, sizeof(recpt));
    if (bytesSent < 0)
    {
        switch (WSAGetLastError())
        {
        case WSAEINTR:
            return BD_NET_BLOCKING_CALL_CANCELED;
        case WSAEINVAL:
            return BD_NET_NOT_BOUND;
        case WSAEWOULDBLOCK:
            return BD_NET_WOULD_BLOCK;
        case WSAEMSGSIZE:
            return BD_NET_MSG_SIZE;
        case WSAEHOSTUNREACH:
            bdLogMessage(BD_LOG_INFO, "info/", "platform/socket", __FILE__, __FUNCTION__, __LINE__, "send: Received connection reset : %i", BD_NET_CONNECTION_RESET);
            return BD_NET_CONNECTION_RESET;
        default:
            return BD_NET_ERROR;
        }
    }
    m_totalBytesSent += bytesSent + 28;
    ++m_totalPacketsSent;
    return bytesSent;
}

bdInt bdPlatformSocket::receiveFrom(SOCKET handle, bdInAddr* addr, unsigned short* port, void* data, unsigned int len)
{
    bdInt remoteAddrLen;
    sockaddr_in remoteAddr;

    if (handle == -1)
    {
        return BD_NET_INVALID_HANDLE;
    }
    memset(&remoteAddr, 0, sizeof(remoteAddr));
    remoteAddrLen = sizeof(remoteAddr);

    bdInt bytesRecvd = recvfrom(handle, reinterpret_cast<char*>(data), len, 0, (sockaddr*)&remoteAddr, &remoteAddrLen);
    if (bytesRecvd < 0)
    {
        switch (WSAGetLastError())
        {
        case WSAEINTR:
            return BD_NET_BLOCKING_CALL_CANCELED;
        case WSAEINVAL:
            return BD_NET_NOT_BOUND;
        case WSAEWOULDBLOCK:
            return BD_NET_WOULD_BLOCK;
        case WSAEMSGSIZE:
            return BD_NET_MSG_SIZE;
        case WSAEHOSTUNREACH:
            bdLogMessage(BD_LOG_INFO, "info/", "platform/socket", __FILE__, __FUNCTION__, __LINE__, "recv: Received connection reset : %i", BD_NET_CONNECTION_RESET);
            *port = ntohs(remoteAddr.sin_port);
            addr->inUn.m_iaddr = remoteAddr.sin_addr.S_un.S_addr;
            return BD_NET_CONNECTION_RESET;
        default:
            return BD_NET_ERROR;
        }
    }
    *port = ntohs(remoteAddr.sin_port);
    addr->inUn.m_iaddr = remoteAddr.sin_addr.S_un.S_addr;
    m_totalBytesRecvd += bytesRecvd + 28;
    ++m_totalPacketsRecvd;
    return bytesRecvd;
}

bdBool bdPlatformSocket::close(int* handle)
{
    bool result;

    result = *handle == -1;
    if (*handle != -1)
    {
        result = closesocket(*handle) == 0;
        *handle = -1;
    }
    return result;
}

const char* magicCase = "255.255.255.255";

bdUInt bdPlatformSocket::getHostByName(const char* name, bdInAddr* addresses, int numAddresses)
{
    char dst[4];
    int i;
    hostent* hostName;

    if (!isalpha(*name))
    {
        addresses->inUn.m_iaddr = inet_addr(name);
        if (addresses->inUn.m_iaddr == -1)
        {
            return strcmp(magicCase, name);
        }
        else
        {
            return 1;
        }
    }
    hostName = gethostbyname(name);
    if (hostName)
    {
        for (i = 0; i < numAddresses && hostName->h_addr_list[i]; ++i)
        {
            memcpy(dst, hostName->h_addr_list[i], sizeof(dst));
            addresses[i] = *(bdInAddr*)dst;
        }
        return i;
    }
    else
    {
        bdLogMessage(BD_LOG_WARNING, "warn/", "platform/socket", __FILE__, __FUNCTION__, __LINE__, "gethostbyname: Error : %i", WSAGetLastError());
        return 0;
    }
}
