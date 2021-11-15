#pragma once

#include <bdPlatform/bdPlatform.h>

class bdPlatformThread
{
public:
	static bool createThread(LPTHREAD_START_ROUTINE threadProc, void* args, void** handle, int __formal, unsigned int stackSize);
	static bool startThread(void** handle);
	static void deleteThread(void** handle);
};