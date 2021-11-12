#pragma once

#include <bdPlatform/bdPlatform.h>

namespace bdPlatformMutex
{
	HANDLE createMutex();
	void unlock(void** handle);
	void destroy(void** handle);
	void lock(void** handle);
};