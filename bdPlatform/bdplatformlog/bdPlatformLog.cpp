#include "bdPlatformLog.h"

#include "bdPlatform/bdPlatform.h"
#include "bdPlatform/bdPlatformString/bdPlatformString.h"

#include <stdio.h>

bdLogSubscriber* g_logSubscriberList;

int bdSnprintf(char* buf, unsigned int maxlen, const char* format, ...)
{
	va_list ap;
	int len;

	va_start(ap, format);
	len = _vscprintf(format, ap);
	vsnprintf_s(buf, maxlen, 0xFFFFFFFF, format, ap);
	return len;
}

int bdPrintf(const char* format, ...)
{
	va_list va;

	va_start(va, format);
	return vfprintf(stdout + 1, format, va);
}

void bdLogMessage(bdLogMessageType type, const char* baseChannel, const char* channel, const char* file, const char* function, unsigned int line, const char* format, ...)
{
	va_list ap;
	bdLogSubscriber* i;
	char channelNameBuffer[256];
	char message[256];

	va_start(ap, format);
	if (g_logSubscriberList)
	{
		memset(message, 0, sizeof(message));
		vsnprintf_s(message, 0x100u, 0xFFFFFFFF, format, ap);
		if (_vscprintf(format, ap) >= 256)
		{
			bdLogMessage(BD_LOG_WARNING, "warn/", "bdPlatformLog", __FILE__, __FUNCTION__, __LINE__, "Message truncated.", 0);
		}
		if (baseChannel && channel)
		{
			if (bdSnprintf(channelNameBuffer, 0x100u, "%s%s", baseChannel, channel) >= 256)
			{
				bdLogMessage(BD_LOG_WARNING, "warn/", "bdPlatformLog", __FILE__, __FUNCTION__, __LINE__, "Channel name truncated: %s%s", baseChannel, channel);
			}
			baseChannel = channelNameBuffer;
		}
		for (i = g_logSubscriberList; i; i = (bdLogSubscriber*)i->getNext())
		{
			i->logMessage(type, baseChannel, file, function, line, message);
		}
	}
}

bdLogSubscriber::bdLogSubscriber()
{
	memset(m_channels, 0, sizeof(m_channels));
}

bool bdLogSubscriber::addChannel(const char* channel)
{
	unsigned int i;
	bool found = false;

	for (i = 0; !found && i < BD_MAX_CHANNELS; ++i)
	{
		if (!m_channels[i])
		{
			found = true;
			m_channels[i] = channel;
		}
	}
	if (found && !bdLinkable::find(g_logSubscriberList, this))
	{
		link((bdLinkable**)&g_logSubscriberList);
	}
	return found;
}

void bdLogSubscriber::logMessage(bdLogMessageType type, const char* channelName, const char* file, const char* function, unsigned int line, const char* msg)
{
	unsigned int i;

	for (i = 0; i < BD_MAX_CHANNELS; ++i)
	{
		if (m_channels[i])
		{
			if (bdDelimSubstr(channelName, m_channels[i], "\\/"))
			{
				publish(type, channelName, file, function, line, msg);
			}
		}
	}
}

void bdLogSubscriber::publish(bdLogMessageType type, const char* channelName, const char* file, const char* function, unsigned int line, const char* msg)
{
	const char* logType;
	const char* fileName;

	switch (type)
	{
	case BD_LOG_INFO:
		logType = " ";
		break;
	case BD_LOG_WARNING:
		logType = " WARNING: ";
		break;
	case BD_LOG_ERROR:
		logType = " ERROR: ";
		break;
	default:
		logType = " ";
		break;
	}
	fileName = strrchr(file, '\\');
	if (fileName)
	{
		bdPrintf("%s(%u):%s%s\n", fileName + 1, line, logType, msg);
	}
	else
	{
		bdPrintf("%s(%u):%s%s\n", file, line, logType, msg);
	}
}
