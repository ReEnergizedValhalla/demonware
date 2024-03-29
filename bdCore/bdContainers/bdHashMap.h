// SPDX-License-Identifier: GPL-3.0-or-later
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
    Iterator getIterator()
    {
        bdUInt numIter;

        if (!m_size)
        {
            return NULL;
        }
        for (numIter = 0; numIter < m_capacity, m_map[numIter] == NULL; ++numIter);
        if (m_map[numIter])
        {
            ++m_numIterators;
        }
        return m_map[numIter];
    }
    Iterator getIterator(const keyType* key)
    {
        Node* n;

        if (!m_size)
        {
            return NULL;
        }
        hash = m_hashClass.getHash(key);
        for (n = m_map[getHashIndex(hash)]; n; n = n->m_next)
        {
            if (key == &n->m_key)
            {
                ++m_numIterators;
                return n;
            }
        }
        return NULL;
    }
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

#include "bdHashMap.inl"