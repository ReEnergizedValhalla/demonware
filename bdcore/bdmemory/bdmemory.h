// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

static class bdMemory
{
public:
    void setAllocateFunc(void* (*allocator)(const unsigned int));
    void setDeallocateFunc(void  (*deallocator)(void*));
    void setReallocateFunc(void* (*reallocator)(void*, const unsigned int));
    void setAlignedAllocateFunc(void* (*allocator)(const unsigned int, const unsigned int));
    void setAlignedDeallocateFunc(void  (*deallocator)(void*));
    void setAlignedReallocateFunc(void* (*reallocator)(void*, const unsigned int, const unsigned int));
    void* (*getAllocateFunc())(const unsigned int);
    void (*getDeallocateFunc())(void*);
    void* (*getReallocateFunc())(void*, const unsigned int);
    void* (*getAlignedAllocateFunc())(const unsigned int, const unsigned int);
    void (*getAlignedDeallocateFunc())(void*);
    void* (*getAlignedReallocateFunc())(void*, const unsigned int, const unsigned int);
    void* allocate(const unsigned int size);
    void deallocate(void* p);
    void* reallocate(void* p, const unsigned int size);
    void* alignedAllocate(const unsigned int, const unsigned int); // Not used
    void alignedDeallocate(void*); // Not used
    void* alignedReallocate(void*, const unsigned int, const unsigned int); // Not used
protected:
    void* (*m_allocateFunc)(const unsigned int);
    void (*m_deallocateFunc)(void*);
    void* (*m_reallocateFunc)(void*, const unsigned int);
    void* (*m_alignedAllocateFunc)(const unsigned int, const unsigned int);
    void (*m_alignedDeallocateFunc)(void*);
    void* (*m_alignedReallocateFunc)(void*, const unsigned int, const unsigned int);
private:
    bdMemory();
};