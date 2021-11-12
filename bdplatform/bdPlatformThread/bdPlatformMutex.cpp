
#include "bdPlatformMutex.h"

namespace bdPlatformMutex
{

#ifdef _WINDOWS
	HANDLE createMutex()
	{
		return CreateMutex(0, 0, 0);
	}

	void unlock(void** handle)
	{
		ReleaseMutex(*handle);
	}

	void destroy(void** handle)
	{
		ReleaseMutex(*handle);
		CloseHandle(*handle);
	}

	void lock(void** handle)
	{
		WaitForSingleObject(*handle, -1);
	}
#endif

}
