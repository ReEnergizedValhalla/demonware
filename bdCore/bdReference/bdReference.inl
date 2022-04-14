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

#include "bdReference.h"

template<typename T>
inline bdReference<T>::bdReference(bdReference<T>* other)
{
	this->m_ptr = other->operator->();
	if (this->m_ptr)
	{
		reinterpret_cast<bdReferencable*>(this->m_ptr)->addRef();
	}
}

template<typename T>
inline bdReference<T>::~bdReference()
{
	if (this->m_ptr)
	{
		if (!reinterpret_cast<bdReferencable*>(this->m_ptr)->releaseRef())
		{
			if (this->m_ptr)
			{
				reinterpret_cast<bdReferencable*>(this->m_ptr)->~bdReferencable();
			}
			this->m_ptr = NULL;
		}
	}
}

template<typename T>
inline bdReference<T>::bdReference(T* p)
{
	this->m_ptr = p;
	if (this->m_ptr)
	{
		reinterpret_cast<bdReferencable*>(this->m_ptr)->addRef();
	}
}

template<typename T>
inline bdBool bdReference<T>::notNull()
{
	return this->m_ptr != NULL;
}

template<typename T>
inline T* bdReference<T>::operator->()
{
	return this->m_ptr;
}

template<typename T>
inline void bdReference<T>::operator=(T* p)
{
	if (this->m_ptr)
	{
		if (!reinterpret_cast<bdReferencable*>(this->m_ptr)->releaseRef())
		{
			if (this->m_ptr)
			{
				reinterpret_cast<bdReferencable*>(this->m_ptr)->~bdReferencable();
			}
		}
	}
	this->m_ptr = p;
	if (this->m_ptr)
	{
		reinterpret_cast<bdReferencable*>(this->m_ptr)->addRef();
	}
}

template<typename T>
inline bdReference<T>* bdReference<T>::operator=(const bdReference<T>* other)
{
	if (other != this)
	{
		if (this->m_ptr)
		{
			if (!reinterpret_cast<bdReferencable*>(this->m_ptr)->releaseRef())
			{
				if (this->m_ptr)
				{
					reinterpret_cast<bdReferencable*>(this->m_ptr)->~bdReferencable();
				}
			}
		}
		this->m_ptr = other->m_ptr;
		if (this->m_ptr)
		{
			reinterpret_cast<bdReferencable*>(this->m_ptr)->addRef()
		}
	}
	return this;
}

template<typename T>
inline T* bdReference<T>::operator*()
{
	return this->m_ptr;
}

template<typename T>
inline bdReference<T>::operator T* ()
{
	return this->m_ptr;
}
