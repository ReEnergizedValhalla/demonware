#pragma once

typedef unsigned int SOCKET;

enum bdSocketStatusCode
{
	BD_NET_SUCCESS = 0x1,
	BD_NET_CONNECTION_CLOSED = 0x0,
	BD_NET_ERROR = 0xFFFFFFFF,
	BD_NET_WOULD_BLOCK = 0xFFFFFFFE,
	BD_NET_SUBSYTEM_ERROR = 0xFFFFFFFD,
	BD_NET_ADDRESS_IN_USE = 0xFFFFFFFC,
	BD_NET_CONNECTION_RESET = 0xFFFFFFFB,
	BD_NET_MSG_SIZE = 0xFFFFFFFA,
	BD_NET_ADDRESS_INVALID = 0xFFFFFFF9,
	BD_NET_BLOCKING_CALL_CANCELED = 0xFFFFFFF8,
	BD_NET_NOT_BOUND = 0xFFFFFFF7,
	BD_NET_INVALID_HANDLE = 0xFFFFFFF6,
	BD_NET_NOT_CONNECTED = 0xFFFFFFF5,
	BD_NET_CONNECTION_REFUSED = 0xFFFFFFF4,
	BD_NET_HOST_UNREACH = 0xFFFFFFF3,
};

class bdPlatformSocket
{
private:
	static __int64 m_totalBytesSent;
	static __int64 m_totalPacketsSent;
	static __int64 m_totalBytesRecvd;
	static __int64 m_totalPacketsRecvd;
public:
	static SOCKET create(bool blocking, bool broadcast);
	static int bind(int* handle, class bdInAddr addr, unsigned short port);
	static int sendTo(SOCKET handle, class bdInAddr addr, unsigned short port, char* data, unsigned int len);
	static int receiveFrom(SOCKET handle, class bdInAddr* addr, unsigned short* port, void* data, unsigned int len);
	static bool close(int* handle);
	static unsigned int getHostByName(const char* name, class bdInAddr* addresses, int numAddresses);
};