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
#include "bdMutex.h"

#include "bdPlatform/bdPlatformThread/bdPlatformMutex.h"

bdMutex::bdMutex()
{
	m_handle = bdPlatformMutex::createMutex();
}

bdMutex::~bdMutex()
{
	bdPlatformMutex::destroy(&m_handle);
}

void bdMutex::lock()
{
	bdPlatformMutex::lock(&m_handle);
}

void bdMutex::unlock()
{
	bdPlatformMutex::unlock(&m_handle);
}
