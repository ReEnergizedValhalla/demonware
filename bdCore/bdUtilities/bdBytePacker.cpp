#include "bdBytePacker.h"

#include <bdPlatform/bdPlatform.h>
#include <bdPlatform/bdPlatformLog/bdPlatformLog.h>

bool bdBytePacker::appendBuffer(char* dest, unsigned int destSize, unsigned int offset, unsigned int* newOffset, void* src, unsigned int writeSize)
{
	*newOffset = writeSize + offset;

	if (dest && src)
	{
		if (*newOffset > destSize)
		{
			bdLogMessage(BD_LOG_WARNING, "warn/", "byte packer", __FILE__, "bdBytePacker::appendBuffer", __LINE__, "Not enough room left to write %u bytes.", writeSize);
		}

		if (offset <= destSize && *newOffset <= destSize)
		{
			memmove(&dest[offset], src, writeSize);
			return true;
		}
	}
	return false;
}

bool bdBytePacker::appendEncodedUInt16(char* buffer, unsigned int bufferSize, unsigned int offset, unsigned int* newOffset, unsigned short value)
{
	char src;

	if (value <= 127)
	{
		return appendBuffer(buffer, bufferSize, offset, newOffset, (char*)&value, 1);
	}
	else
	{
		src = value | 0x8000;
		if (appendBuffer(buffer, bufferSize, offset, newOffset, (char*)&src + 3, 1))
		{
			if (appendBuffer(buffer, bufferSize, *newOffset, newOffset, (char*)&src, 1u))
			{
				return true;
			}
		}
		return false;
	}
}

bool bdBytePacker::removeBuffer(char* src, unsigned int srcSize, unsigned int offset, unsigned int* newOffset, void* dest, unsigned int readSize)
{
	*newOffset = readSize + offset;

	if (dest && src)
	{
		if (*newOffset > srcSize)
		{
			bdLogMessage(BD_LOG_WARNING, "warn/", "byte packer", __FILE__, __FUNCTION__, __LINE__, "Not enough data left to read %u bytes.", readSize);
		}

		if ((*newOffset <= srcSize) && offset <= srcSize)
		{
			memmove(dest, &src[offset], readSize);
			return true;
		}
	}
	return false;
}

bool bdBytePacker::removeEncodedUInt16(char* buffer, unsigned int bufferSize, unsigned int offset, unsigned int* newOffset, unsigned short* value)
{
	unsigned char firstByte = 0;

	if (!removeBuffer(buffer, bufferSize, offset, newOffset, &firstByte, 1))
	{
		*value = 0;
		return false;
	}

	if (firstByte < 0x80)
	{
		*value = firstByte;
		return true;
	}

	firstByte &= ~0x80;
	if (removeBuffer(buffer, bufferSize, *newOffset, newOffset, &firstByte, 1))
	{
		*value = firstByte + (firstByte << 8);
		return true;
	}
	else
	{
		*value = (firstByte << 8);
		return false;
	}
}

bool bdBytePacker::skipBytes(const char* buffer, unsigned int bufferSize, unsigned int offset, unsigned int* newOffset, unsigned int bytes)
{
	*newOffset = bytes + offset;

	if (buffer)
	{
		return bufferSize >= *newOffset;
	}
	return false;
}

bool bdBytePacker::rewindBytes(const char* buffer, unsigned int bufferSize, unsigned int offset, unsigned int* newOffset, unsigned int bytes)
{
	*newOffset = offset - bytes;

	if (buffer)
	{
		return offset >= bytes;
	}
	return false;
}
