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
#include "bdCore/bdMemory/bdmemory.h"
#include "bdCore/bdContainers/bdLinkedList.h"

#include "bdQueue.h"

template<typename T>
inline bdQueue<T>::bdQueue() : T()
{
}

template<typename T>
inline void bdQueue<T>::dequeue()
{
	//bdAssertMsg(getSize() > 0, "bdQueue::dequeue, queue empty, can't dequeue.");
	m_list.removeHead();
}

template<typename T>
inline void bdQueue<T>::enqueue(const T* item)
{
	m_list.addTail(item);
}

template<typename T>
inline bdUInt bdQueue<T>::getSize()
{
	return m_list.getSize();
}

template<typename T>
inline bdBool bdQueue<T>::isEmpty()
{
	return m_list.isEmpty();
}

template<typename T>
inline T* bdQueue<T>::peek()
{
	//bdAssertMsg(getSize() > 0, "bdQueue::dequeue, queue empty, can't peek.");
	return m_list.getHead();
}

