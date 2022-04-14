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

#include "bdReferencable.h"

inline bdReferencable::~bdReferencable()
{
	delete this;
}

inline bdReferencable* bdReferencable::operator=(bdReferencable* a)
{
	return this;
}

inline bdInt bdReferencable::releaseRef()
{
	return InterlockedDecrement((volatile LONG*)&this->m_refCount) - 1;
}

inline bdInt bdReferencable::addRef()
{
	return InterlockedIncrement((volatile LONG*)&this->m_refCount) + 1;
}

inline bdInt bdReferencable::getRefCount()
{
	return this->m_refCount;
}

inline bdReferencable::bdReferencable()
{
	this->m_refCount = 0;
}

inline void bdReferencable::operator delete(void* p)
{
}
