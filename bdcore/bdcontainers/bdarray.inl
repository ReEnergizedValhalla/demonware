// SPDX-License-Identifier: GPL-3.0-or-later

#include "bdarray.h"

#include <bdCore/bdmemory/bdmemory.h>

template<typename T>
void bdArray<T>::clear()
{
	T* m_data;
	unsigned int m_size;

	m_data = this->m_data;
	if (m_size)
	{
		for ( m_size = this->m_size; m_size; --m_size, m_data++ )
		{
			delete m_data;
		}
	}
	bdMemory::deallocate(this->m_data);
	this->m_data = 0;
	this->m_size = 0;
	this->m_capacity = 0;
}