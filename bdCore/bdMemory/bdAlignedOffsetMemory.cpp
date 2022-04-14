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

#include "bdAlignedOffsetMemory.h"

#include "bdPlatform/bdPlatform.h"

void* bdAlignedOffsetMalloc(unsigned int size, unsigned int align, unsigned int offset)
{
	void* alloc;

	if ((align & (align - 1)) != 0)
	{
		return 0;
	}
	unsigned int aligned = align + offset + 4;
	alloc = malloc(size + aligned);
	if (!alloc)
	{
		return 0;
	}
	*(int*)((~(align - 1) & ((unsigned int)alloc + aligned)) - offset - 4) = (int)alloc;
	return (void*)((~(align - 1) & ((unsigned int)alloc + aligned)) - offset);
}

void bdAlignedOffsetFree(void* p)
{
	free(*((void**)p - 1));
}

void* bdAlignedOffsetRealloc(void* p, unsigned int origSize, unsigned int size, unsigned int align, unsigned int offset)
{
	void* newAlloc;

	newAlloc = bdAlignedOffsetMalloc(size, align, offset);
	if (size >= origSize)
	{
		size = origSize;
	}
	memcpy(newAlloc, p, size);
	bdAlignedOffsetFree(p);
	return newAlloc;
}
