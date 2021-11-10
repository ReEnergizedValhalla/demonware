#include "bdPlatformTiming.h"

namespace bdPlatformTiming
{
	LARGE_INTEGER getHiResTimeStamp()
	{
		LARGE_INTEGER time;

		QueryPerformanceCounter(&time);
		return time;
	}

	float getElapsedTime(unsigned __int64 time1, unsigned __int64 time2)
	{
		LARGE_INTEGER Frequency;

		QueryPerformanceFrequency(&Frequency);
		return ((time1 - time2) / Frequency.QuadPart);
	}

	void sleep(unsigned int timeInMs)
	{
		Sleep(timeInMs);
	}

	unsigned int getLoResElapsedTime(unsigned int time1, unsigned int time2)
	{
		if (time2 < time1)
		{
			time2 += 0xFFFFFFFF;
		}
		return (time2 - time1) / 1000;
	}
}