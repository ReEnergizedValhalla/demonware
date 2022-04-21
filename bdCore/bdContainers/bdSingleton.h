// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

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
    static T* m_instance;
public:
    static T* getInstance();
    static T* destroyInstance();
};