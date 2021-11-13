#pragma once

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
				// FINISH!!!
			}
		}
	}
	T* destroyInstance();
};