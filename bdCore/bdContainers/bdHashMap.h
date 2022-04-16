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

template <typename hashClass, typename dataType, typename keyType>
class bdHashMap
{
public:
    typedef void* Iterator;
    class Node
    {
    public:
        dataType m_data;
        keyType m_key;
        Node* m_next;

        Node();
        Node(keyType* key, dataType* value, const Node* next);
        ~Node();
        void* operator new(bdUWord mbytes);
        void operator delete(void* p);
    };
    bdUInt m_size;
    bdUInt m_capacity;
    bdFloat32 m_loadFactor;
    bdUInt m_threshold;
    Node** m_map;
    hashClass m_hashClass;
    bdUInt m_numIterators;

    bdHashMap();
    bdHashMap(const bdUInt initialCapacity, const bdFloat32 loadFactor);
    ~bdHashMap();
    Iterator getIterator();
    Iterator getIterator(const keyType* key);
    void releaseIterator(Iterator iterator);
    dataType* getValue(Iterator* iterator);
    void next(Iterator* iterator);
    bdBool remove(keyType* key);
    void clear();
    void resize(const bdUInt newSize);
    bdBool get(const keyType* key, const dataType* value);
    bdBool put(const keyType* key, const dataType* value);
    void createMap(const bdUInt initialCapacity, const bdFloat32 loadFactor);
    bdUInt getHashIndex(const bdUInt hash);
    bdInt getSize();
    static bdUInt getNextCapacity(const bdUInt targetCapacity);
};