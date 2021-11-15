#pragma once

void* bdAlignedOffsetMalloc(unsigned int size, unsigned int align, unsigned int offset);
void bdAlignedOffsetFree(void* p);
void* bdAlignedOffsetRealloc(void* p, unsigned int origSize, unsigned int size, unsigned int align, unsigned int offset);