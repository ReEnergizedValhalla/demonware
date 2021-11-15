
#include "bdPlatformMutex.h"

#ifdef _WINDOWS
	HANDLE bdPlatformMutex::createMutex()
	{
		return CreateMutex(0, 0, 0);
	}

	void bdPlatformMutex::unlock(void** handle)
	{
		ReleaseMutex(*handle);
	}

	void bdPlatformMutex::destroy(void** handle)
	{
		ReleaseMutex(*handle);
		CloseHandle(*handle);
	}

	void bdPlatformMutex::lock(void** handle)
	{
		WaitForSingleObject(*handle, -1);
	}
#endif
