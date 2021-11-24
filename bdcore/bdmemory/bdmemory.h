#pragma once

#include <bdCore/bdThread/bdMutex.h>
#include <bdPlatform/bdPlatform.h>

static bdMutex g_MemoryThreadLock;

static class bdMemory
{
public:
    static void setAllocateFunc(void* (*allocator)(const unsigned int));
    static void setDeallocateFunc(void  (*deallocator)(void*));
    static void setReallocateFunc(void* (*reallocator)(void*, const unsigned int));
    static void setAlignedAllocateFunc(void* (*allocator)(const unsigned int, const unsigned int));
    static void setAlignedDeallocateFunc(void  (*deallocator)(void*));
    static void setAlignedReallocateFunc(void* (*reallocator)(void*, const unsigned int, const unsigned int));
    static void* (*getAllocateFunc())(const unsigned int);
    static void (*getDeallocateFunc())(void*);
    static void* (*getReallocateFunc())(void*, const unsigned int);
    static void* (*getAlignedAllocateFunc())(const unsigned int, const unsigned int);
    static void (*getAlignedDeallocateFunc())(void*);
    static void* (*getAlignedReallocateFunc())(void*, const unsigned int, const unsigned int);
    static void* allocate(const unsigned int size);
    static void deallocate(void* p);
    static void* reallocate(void* p, const unsigned int size);
    //static  void* alignedAllocate(const unsigned int, const unsigned int); Not used
    //static void alignedDeallocate(void*); Not used
    //static void* alignedReallocate(void*, const unsigned int, const unsigned int); Not used
protected:
    static void* (*m_allocateFunc)(const unsigned int);
	static void (*m_deallocateFunc)(void*);
	static void* (*m_reallocateFunc)(void*, const unsigned int);
	static void* (*m_alignedAllocateFunc)(const unsigned int, const unsigned int);
	static void (*m_alignedDeallocateFunc)(void*);
	static void* (*m_alignedReallocateFunc)(void*, const unsigned int, const unsigned int);
private:
    bdMemory();
};