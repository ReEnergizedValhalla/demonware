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

#include "bdLinkedList.h"

template<typename T>
inline bdLinkedList<T>::bdLinkedList()
{
    m_head = NULL;
    m_tail = NULL;
    m_size = 0;
}

template<typename T>
inline bdLinkedList<T>::~bdLinkedList()
{
    clear();
}

template<typename T>
inline void bdLinkedList<T>::clear()
{
    Node* p;
    Node* next;

    while (this->m_head)
    {
        next = m_head->m_next;
        p = this->m_head;
        if (this->m_head)
        {
            delete p;
        }
        this->m_head = next;
    }
    this->m_tail = NULL;
    this->m_size = 0;
}

template<typename T>
inline T* bdLinkedList<T>::forward(Position* position)
{
    *position = reinterpret_cast<Node*>(*position)->m_next;
}

template<typename T>
inline void bdLinkedList<T>::addTail(const T* value)
{
    Position position;

    position = getTailPosition();
    insertAfter(position, value);
}

template<typename T>
inline T* bdLinkedList<T>::getHead()
{
    return &this->m_head->m_data;
}

template<typename T>
inline Position bdLinkedList<T>::getHeadPosition()
{
    return this->m_head;
}

template<typename T>
inline bdUInt bdLinkedList<T>::getSize()
{
    return this->m_size;
}

template<typename T>
inline Position bdLinkedList<T>::getTailPosition()
{
    return this->m_tail;
}

template<typename T>
inline void bdLinkedList<T>::insertAfter(const Position position, const T* value)
{
    Node* node = new Node((T*)value);

    if (position)
    {
        node->m_next = reinterpret_cast<Node*>(position)->m_next;
        node->m_prev = reinterpret_cast<Node*>(position);

        if (reinterpret_cast<Node*>(position)->m_next)
        {
            reinterpret_cast<Node*>(position)->m_next->m_prev = node;
        }
        else
        {
            m_tail = node;
        }
        reinterpret_cast<Node*>(position)->m_next = node;
    }
    else
    {
        node->m_next = NULL;
        node->m_prev = m_tail;
        if (m_tail)
        {
            m_tail->m_next = node;
        }
        else
        {
            m_head = node;
        }
    }
    ++m_size;
}

template<typename T>
inline bdBool bdLinkedList<T>::isEmpty()
{
    return (bdBool)(this->m_size == 0);
}

template<typename T>
inline void bdLinkedList<T>::removeAt(Position* position)
{
    Node* node;

    node = reinterpret_cast<Node*>(*position);
    if (node)
    {
        forward(position);
        if (node == this->m_head)
        {
            this->m_head = this->m_head->m_next;
        }
        else
        {
            node->m_prev->m_next = node->m_next;
        }

        if (node == this->m_tail)
        {
            this->m_tail = node->m_prev;
        }
        else
        {
            node->m_next->m_prev = node->m_prev;
        }
        if (node)
        {
            delete node;
        }
        --this->m_size;
    }
}

template<typename T>
inline void bdLinkedList<T>::removeHead()
{
    Position headPosition;

    headPosition = getHeadPosition();
    removeAt(&headPosition);
}
