// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

typedef void* Position;

template<typename T>
class bdLinkedList
{
public:
    class Node
    {
    public:
        T m_data;
        Node* m_next;
        Node* m_prev;

        Node(T* data)
        {
            m_data = T(data);
        }
        void operator delete(void* p)
        {
            bdMemory::deallocate(p);
        }
        void* operator new(bdUWord nBytes)
        {
            return bdMemory::allocate(nBytes);
        }
    };
    Node* m_head;
    Node* m_tail;
    bdUInt m_size;

    bdLinkedList();
    ~bdLinkedList();

    void clear();
    T* forward(Position* position);
    void addTail(const T* value);
    T* getHead();
    Position getHeadPosition();
    bdUInt getSize();
    Position getTailPosition();
    void insertAfter(const Position position, const T* value);
    bdBool isEmpty();
    void removeAt(Position* position);
    void removeHead();
};

#include "bdLinkedList.inl"