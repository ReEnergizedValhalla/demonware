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

class Test
{
public:
    int x;
    int y;

    Test();
    Test(Test* data)
    {
        x = data->x;
        y = data->y;
    }
};

class Test1
{
public:
    bdLinkedList<Test>* value;
};
