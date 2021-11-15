#include "bdPlatformStreamSocket.h"
#include <bdPlatform/bdPlatform.h>

#include <bdCore/bdSocket/bdInetAddr.h>
#include <bdPlatform/bdPlatformLog/bdPlatformLog.h>
#include "bdPlatformSocket.h"
#include "bdInAddr.h"

SOCKET bdPlatformStreamSocket::create(bool blocking)
{
	u_long nonblocking;

	SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	nonblocking = !blocking;
	if (ioctlsocket(s, FIONBIO, &nonblocking))
	{
		return SOCKET_ERROR;
	}
	return s;
}

bdSocketStatusCode bdPlatformStreamSocket::connect(SOCKET handle, bdInAddr addr, unsigned short port)
{
	sockaddr_in remoteAddr;

	memset(&remoteAddr, 0, sizeof(remoteAddr));
	remoteAddr.sin_family = AF_INET;
	remoteAddr.sin_addr = *(in_addr*)&addr;
	remoteAddr.sin_port = htons(port);
	if (::connect(handle, (SOCKADDR*)&remoteAddr, sizeof(remoteAddr)))
	{
		return BD_NET_SUCCESS;
	}
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
		return BD_NET_CONNECTION_RESET;
	default:
		return BD_NET_ERROR;
	}
}

bool bdPlatformStreamSocket::close(SOCKET handle)
{
	if (handle == -1)
	{
		return true;
	}
	switch (closesocket(handle))
	{
	case 0:
		return true;
	case -1:
		bdLogMessage(BD_LOG_WARNING, "warn/", "platform stream socket", __FILE__, "bdPlatformStreamSocket::close", __LINE__, "Failed to close socket Error %i.", WSAGetLastError());
		break;
	default:
		bdLogMessage(BD_LOG_WARNING, "warn/", "platform stream socket", __FILE__, "bdPlatformStreamSocket::close", __LINE__, "Failed to close socket. Unknown Error Code.");
		break;
	}
	return false;
}

bool bdPlatformStreamSocket::checkSocketException(SOCKET handle)
{
	timeval zero;
	fd_set fdset;

	zero.tv_sec = 0;
	zero.tv_usec = 0;
	fdset.fd_array[0] = handle;
	fdset.fd_count = 1;

	return select(0, 0, 0, &fdset, &zero) || __WSAFDIsSet(handle, &fdset);
}

bool bdPlatformStreamSocket::isWritable(SOCKET handle, bdSocketStatusCode* error)
{
	timeval zero;
	fd_set fdwrite;
	fd_set fderr;
	bool success;
	int i;

	zero.tv_sec = 0;
	zero.tv_usec = 0;
	fderr.fd_count = 0;
	for (i = 0; i < fderr.fd_count && fderr.fd_array[i] != handle; ++i);

	if (i == fderr.fd_count && fderr.fd_count < 64)
	{
		fderr.fd_array[i] = handle;
		++fderr.fd_count;
	}

	*error = BD_NET_SUCCESS;
	success = __WSAFDIsSet(handle, &fdwrite) && select(0, 0, &fdwrite, &fderr, &zero) != -1;
	if (__WSAFDIsSet(handle, &fderr))
	{
		switch (WSAGetLastError())
		{
		case WSAEINTR:
			*error = BD_NET_BLOCKING_CALL_CANCELED;
		case WSAEINVAL:
			*error = BD_NET_NOT_BOUND;
		case WSAEWOULDBLOCK:
			*error = BD_NET_WOULD_BLOCK;
		case WSAEMSGSIZE:
			*error = BD_NET_MSG_SIZE;
		case WSAEHOSTUNREACH:
			*error = BD_NET_CONNECTION_RESET;
		default:
			*error = BD_NET_ERROR;
		}
	}
	return success;
}

bool bdPlatformStreamSocket::getSocketAddr(SOCKET handle, bdInAddr* socketAddr)
{
	sockaddr_in retrievedAddr;
	int length = 16;

	if (getsockname(handle, (sockaddr*)&retrievedAddr, &length) == -1)
	{
		return 0;
	}
	*socketAddr = *(bdInAddr*)&retrievedAddr.sin_addr;
	return 1;
}
