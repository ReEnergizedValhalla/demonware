#pragma once

#include <bdPlatform/bdPlatformPatterns/bdLinkable.h>

#define BD_MAX_CHANNELS 5

enum bdLogMessageType
{
	BD_LOG_INFO = 0x0,
	BD_LOG_WARNING = 0x1,
	BD_LOG_ERROR = 0x2,
};

int bdSnprintf(char* buf, unsigned int maxlen, const char* format, ...);
int bdPrintf(const char* format, ...);
void bdLogMessage(bdLogMessageType type, const char* baseChannel, const char* channel, const char* file, const char* function, unsigned int line, const char* format, ...);

class bdLogSubscriber : public bdLinkable
{
public:
	const char* m_channels[BD_MAX_CHANNELS];

	bdLogSubscriber();
	bool addChannel(const char* channel);
	void logMessage(bdLogMessageType type, const char* channelName, const char* file, const char* function, unsigned int line, const char* msg);
	virtual void publish(bdLogMessageType type, const char* channelName, const char* file, const char* function, unsigned int line, const char* msg);
};