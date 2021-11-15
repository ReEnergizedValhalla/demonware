#include "bdAlignedOffsetMemory.h"

#include <bdPlatform/bdPlatform.h>

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
