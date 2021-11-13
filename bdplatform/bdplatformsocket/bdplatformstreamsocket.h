#pragma once

typedef unsigned int SOCKET;

class bdPlatformStreamSocket
{
public:
	static SOCKET create(bool blocking);
	static enum bdSocketStatusCode connect(SOCKET handle, class bdInAddr addr, unsigned short port);
	static bool close(SOCKET handle);
	static bool checkSocketException(SOCKET handle);
	static bool isWritable(SOCKET handle, enum bdSocketStatusCode* error);
	static bool getSocketAddr(SOCKET handle, class bdInAddr* socketAddr);
	static int send(SOCKET handle, char* data, unsigned int length);
	static int recieve(SOCKET handle, char* data, unsigned int length);
	static bool isWritable(SOCKET handle);
};