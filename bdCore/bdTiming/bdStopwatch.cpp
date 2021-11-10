#include <bdPlatform/bdPlatformTiming/bdPlatformTiming.h>

bdStopwatch::bdStopwatch()
{
	reset();
}

void bdStopwatch::start()
{
	m_start = bdPlatformTiming::getHiResTimeStamp().QuadPart;
}

void bdStopwatch::reset()
{
	m_start = 0;
}

float bdStopwatch::getElapsedTimeInSeconds()
{
	if ( m_start )
	{
		return bdPlatformTiming::getElapsedTime(m_start, bdPlatformTiming::getHiResTimeStamp().QuadPart);
	}
	return 0.0f;
}