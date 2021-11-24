#pragma once

#include "bdCore/bdContainers/bdFastArray.h"

class bdSingletonRegistryImpl
{
public:
	bdFastArray<void(__cdecl*)(void)> m_destoryFunctions;
	bool m_cleaningUp;
};

template<typename T>
class bdSingleton
{
protected:
	T* m_instance;
public:
	T* getInstance()
	{
		T* instance;
		void(*destructor)();
		bdSingletonRegistryImpl* singletonInstance;

		if (!m_instance)
		{
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
		return m_instance;
	}
	T* destroyInstance()
	{
		if (m_instance)
		{
			delete m_instance;
			m_instance = 0;
		}
	}
};