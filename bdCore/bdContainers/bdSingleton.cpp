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
#include "bdCore/bdContainers/bdFastArray.h"
#include "bdPlatform/bdPlatform.h"

#include "bdSingleton.h"

template<typename T>
T* bdSingleton<T>::getInstance()
{
	T* instance;
	void(*destructor)();
	bdSingletonRegistryImpl* singletonInstance;

	if (m_instance)
	{
		return m_instance;
	}
	instance = bdMemory::allocate(sizeof(T));
	if (instance)
	{
		instance = new T();
	}
	else
	{
		instance = 0;
	}

	m_instance = instance;
	if (instance)
	{
		destructor = destroyInstance;
		singletonInstance = bdSingleton<bdSingletonRegistryImpl>::getInstance();

		if (!singletonInstance->m_cleaningUp)
		{
			singletonInstance->m_destoryFunctions.pushBack(&destructor);
		}

		if (!!singletonInstance->m_cleaningUp)
		{
			if (m_instance)
			{
				delete m_instance;
			}
			m_instance = 0;
			DebugBreak();
		}
	}
	else
	{
		DebugBreak()
	}
}

template<typename T>
T* bdSingleton<T>::destroyInstance()
{
	if (m_instance)
	{
		delete m_instance;
		m_instance = 0;
	}
}