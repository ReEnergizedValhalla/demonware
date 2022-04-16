/*
* DemonWare
* Copyright (c) 2020-2022 OpenIW
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, version 3.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#include "bdPlatform/bdPlatform.h"
#include "bdPlatform/bdPlatformLog/bdPlatformLog.h"
#include "bdCore/bdUtilities/bdBitOperations.h"

#include "bdBytePacker.h"

bdBool bdBytePacker::appendBuffer(bdUByte8* dest, bdUInt destSize, bdUInt offset, bdUInt* newOffset, const void* src, bdUInt writeSize)
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

bdBool bdBytePacker::appendEncodedUInt16(bdUByte8* buffer, bdUInt bufferSize, bdUInt offset, bdUInt* newOffset, bdUInt16 value)
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

bdBool bdBytePacker::removeBuffer(bdUByte8* src, bdUInt srcSize, bdUInt offset, bdUInt* newOffset, void* dest, bdUInt readSize)
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

bdBool bdBytePacker::removeEncodedUInt16(bdUByte8* buffer, bdUInt bufferSize, bdUInt offset, bdUInt* newOffset, bdUInt16* value)
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

bdBool bdBytePacker::skipBytes(const bdUByte8* buffer, bdUInt bufferSize, bdUInt offset, bdUInt* newOffset, bdUInt bytes)
{
	*newOffset = bytes + offset;

	if (buffer)
	{
		return bufferSize >= *newOffset;
	}
	return false;
}

bdBool bdBytePacker::rewindBytes(const bdUByte8* buffer, bdUInt bufferSize, bdUInt offset, bdUInt* newOffset, bdUInt bytes)
{
	*newOffset = offset - bytes;

	if (buffer)
	{
		return offset >= bytes;
	}
	return false;
}

template<typename varType>
inline bdBool bdBytePacker::removeBasicType(const void* buffer, bdUInt bufferSize, bdUInt offset, bdUInt* newOffset, varType* var)
{
	bdBool read;
	varType nvar;

	read = removeBuffer(buffer, bufferSize, offset, newOffset, &nvar, sizeof(varType));
	if (read)
	{
		buffer = &nvar;
		bdBitOperations::endianSwap<varType>(&nvar, var);
	}
	return read;
}