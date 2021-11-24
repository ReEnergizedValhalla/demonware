#include "bdPlatformTrulyRandom.h"

#include <bdPlatform/bdPlatform.h>

static HCRYPTPROV phProv;

bdTrulyRandomImpl::bdTrulyRandomImpl()
{
	CryptAcquireContext(&phProv, 0, 0, 1, 0xF0000000);
}

bdTrulyRandomImpl::~bdTrulyRandomImpl()
{
	CryptReleaseContext(phProv, 0);
}

int bdTrulyRandomImpl::getRandomUInt()
{
	return 0;
}

void bdTrulyRandomImpl::getRandomUByte8()
{
}

static bdTrulyRandomImpl s_randomInit = bdTrulyRandomImpl();

void bdGetRandomUChar8(unsigned char* in, int length)
{
	CryptGenRandom(phProv, length, in);
}