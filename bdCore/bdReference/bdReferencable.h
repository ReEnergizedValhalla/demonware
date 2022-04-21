// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

class bdReferencable
{
public:
	volatile int m_refCount;

	~bdReferencable();
	bdReferencable* operator=(bdReferencable* a);
	bdInt releaseRef();
	bdInt addRef();
	bdInt getRefCount();
	bdReferencable();
	void operator delete(void* p);
};

#include "bdReferencable.inl"