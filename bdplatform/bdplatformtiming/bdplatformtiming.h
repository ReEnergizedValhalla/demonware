#pragma once

#include <bdPlatform/bdPlatform.h>

class bdPlatformTiming
{
public:
	static LARGE_INTEGER getHiResTimeStamp();
	static float getElapsedTime(unsigned int time1, unsigned int time2);
	static void sleep(unsigned int timeInMs);
	static unsigned int getLoResElapsedTime(unsigned int time1, unsigned int time2);
};