#include "bdRandom.h"

#include <bdPlatform/bdPlatform.h>
#include <bdPlatform/bdPlatformTiming/bdPlatformTiming.h>

bdRandom::bdRandom()
{
	setSeed(bdPlatformTiming::getHiResTimeStamp().LowPart);
}

unsigned int bdRandom::nextUInt()
{
	unsigned int next;

	next = 0x41A7 * (m_val % 0x1F31D) - 0xB14 * (m_val / 0x1F31D);
	if (next <= 0)
	{
		next += 0x7FFFFFFF;
	}
	m_val = next;
	return m_val;
}

void bdRandom::nextUBytes(unsigned char* in, int length)
{
	int i;

	for (i = 0; i < length; ++i)
	{
		in[i] = nextUInt();
	}
}

void bdRandom::setSeed(unsigned int seed)
{
	m_val = seed;
	if (!seed)
	{
		//bdLogMessage(BD_LOG_WARNING, "warn/", "random", __FILE__, __FUNCTION__, __LINE__, "Shouldn't use 0 for seed. 12,195,257 used instead.");
		m_val = 12195257;
	}
}
