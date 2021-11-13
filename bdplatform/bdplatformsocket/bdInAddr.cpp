#include "bdInAddr.h"

#include <bdPlatform/bdPlatform.h>
#include <bdPlatform/bdPlatformString/bdPlatformString.h>

bdInAddr::bdInAddr()
{
	inUn.m_iaddr = 0xFF00FF00;
}

void bdInAddr::fromString(const char* addr)
{
	inUn.m_iaddr = inet_addr(addr);
}

int bdInAddr::toString(char* str, unsigned int size)
{
	const char* src;

	src = inet_ntoa((in_addr&)*this);
	if (src)
	{
		bdStrlcpy(str, src, size);
		return strlen(str);
	}
	return 0;
}
