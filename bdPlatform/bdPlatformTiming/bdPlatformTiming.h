#pragma once

#include <Windows.h>

namespace bdPlatformTiming
{
	LARGE_INTEGER getHiResTimeStamp();
	float getElapsedTime(unsigned __int64 time1, unsigned __int64 time2);
	void sleep(unsigned int timeInMs);
	unsigned int getLoResElapsedTime(unsigned int time1, unsigned int time2);
}