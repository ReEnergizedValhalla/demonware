// SPDX-License-Identifier: GPL-3.0-or-later
#include "bdCore/bdCore.h"

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