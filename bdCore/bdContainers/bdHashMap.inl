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
#include "bdCore/bdMemory/bdMemory.h"
#include "bdCore/bdUtilities/bdBitOperations.h"
#include "bdPlatform/bdPlatformLog/bdplatformlog.h"

#include "bdHashMap.h"

// bdHashMap::Node

template<typename hashClass, typename dataType, typename keyType>
inline bdHashMap<hashClass, dataType, keyType>::Node::Node()
{
}

template<typename hashClass, typename dataType, typename keyType>
inline bdHashMap<hashClass, dataType, keyType>::Node::Node(keyType* key, dataType* value, const Node* next)
{
}

template<typename hashClass, typename dataType, typename keyType>
inline bdHashMap<hashClass, dataType, keyType>::Node::~Node()
{
}

// bdHashMap

template<typename hashClass, typename dataType, typename keyType>
inline bdHashMap<hashClass, dataType, keyType>::bdHashMap()
{
    m_numIterators = 0;
}

template<typename hashClass, typename dataType, typename keyType>
inline bdHashMap<hashClass, dataType, keyType>::bdHashMap(const bdUInt initialCapacity, const bdFloat32 loadFactor)
{
    m_numIterators = 0;
    createMap(initialCapacity, loadFactor);
}

template<typename hashClass, typename dataType, typename keyType>
inline bdHashMap<hashClass, dataType, keyType>::~bdHashMap()
{
    clear();
    bdDeallocate<bdHashMap<hashClass, dataType, keyType>::Node*>(m_map);
}

template<typename hashClass, typename dataType, typename keyType>
inline bdHashMap<hashClass,dataType,keyType>::Iterator bdHashMap<hashClass, dataType, keyType>::getIterator()
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

template<typename hashClass, typename dataType, typename keyType>
inline bdHashMap<hashClass, dataType, keyType>::Iterator bdHashMap<hashClass, dataType, keyType>::getIterator(const keyType* key)
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

template<typename hashClass, typename dataType, typename keyType>
inline void bdHashMap<hashClass, dataType, keyType>::releaseIterator(Iterator iterator)
{
    if (iterator)
    {
        //bdAssertMsg(m_numIterators != 0, "bdHashMap::releaseIteratorIterator count reached 0, can't release iterator");
        --m_numIterators;
    }
}

template<typename hashClass, typename dataType, typename keyType>
inline dataType* bdHashMap<hashClass, dataType, keyType>::getValue(Iterator* iterator)
{
    return reinterpret_cast<Node*>(*iterator)->m_data;
}

template<typename hashClass, typename dataType, typename keyType>
inline void bdHashMap<hashClass, dataType, keyType>::next(Iterator* iterator)
{
    bdUInt hash;
    Node* n;

    n = reinterpret_cast<Node*>(*iterator);

    if (n->m_next)
    {
        n = n->m_next;
    }
    else
    {
        hash = m_hashClass.getHash(&n->m_key);
        for (bdUInt i = getHashIndex(hash) + 1; i < m_capacity; ++i)
        {
            if (m_map[i])
            {
                n = m_map[i];
                return;
            }
        }
        n = NULL;
        --m_numIterators;
    }
}

template<typename hashClass, typename dataType, typename keyType>
inline bdBool bdHashMap<hashClass, dataType, keyType>::remove(keyType* key)
{
    Node* prevNode;
    Node* n;
    bdUInt hash;
    bdUInt i;

    //bdAssertMsg(m_numIterators == 0, "bdHashMap::remove, another iterator is being held while removing from hashmap");
    hash = m_hashClass.getHash(key);
    i = getHashIndex(hash);
    n = m_map[i];
    prevNode = NULL;
    while (1)
    {
        if (!n)
        {
            return false;
        }
        if (key == &n->m_key)
        {
            break;
        }
        prevNode = n;
        n = n->m_next;
    }
    if (prevNode)
    {
        prevNode->m_next = n->m_next;
    }
    else
    {
        m_map[i] = n->m_next;
    }
    n->~Node();
    delete n;
    --m_size;

    return true;
}

template<typename hashClass, typename dataType, typename keyType>
inline void bdHashMap<hashClass, dataType, keyType>::clear()
{
    Node* n;
    Node* last;
    bdUInt i;

    //bdAssertMsg(m_numIterators == 0, "bdHashMap::clear, another iterator is being held while clearing the hashmap");

    for (i = 0; i < m_capacity; ++i)
    {
        n = m_map[i];
        while (n)
        {
            last = n;
            n = n->m_next;
            last->~Node();
            delete last;
        }
        m_map[i] = NULL;
    }
    m_size = 0;
}

template<typename hashClass, typename dataType, typename keyType>
inline void bdHashMap<hashClass, dataType, keyType>::resize(const bdUInt newSize)
{
    bdUInt i;
    bdUInt targetCapacity;
    bdUInt oldCapacity;
    Node* prev;
    Node* n;
    Node** oldmap;

    oldmap = m_map;
    oldCapacity = m_capacity;
    targetCapacity = getNextCapacity(newSize);
    if (targetCapacity <= m_capacity)
    {
        return;
    }
    m_capacity = targetCapacity;
    m_threshold = (static_cast<bdFloat32>(targetCapacity) * m_loadFactor);
    m_map = bdAllocate<Node*>(m_capacity);
    m_size = 0;
    bdMemset(m_map, 0, 8 * m_capacity);
    for (i = 0; i < oldCapacity; ++i)
    {
        n = oldmap[i];
        while (n)
        {
            put(&n->m_key, &n->m_data);
            prev = n;
            n = n->m_next;

            prev->~Node();
            delete prev;
        }
    }
    bdDeallocate<Node*>(oldmap);
}

template<typename hashClass, typename dataType, typename keyType>
inline bdBool bdHashMap<hashClass, dataType, keyType>::get(const keyType* key, const dataType* value)
{
    Iterator iterator = getIterator(key);
    if (!iterator)
    {
        return false;
    }
    value = getValue(iterator);
    releaseIterator(iterator);
    return true;
}

template<typename hashClass, typename dataType, typename keyType>
inline bdBool bdHashMap<hashClass, dataType, keyType>::put(const keyType* key, const dataType* value)
{
    Node* n;
    bdUInt i;
    bdUInt hash;

    //bdAssertMsg(m_numIterators == 0, "bdHashMap::put, another iterator is being held while inserting to hashmap");

    hash = m_hashClass.getHash(key);
    i = getHashIndex(hash);
    for (n = this->m_map[i]; n; n = n->next)
    {
        if (key == &n->m_key)
        {
            return false;
        }
    }
    if (m_size + 1 > m_threshold)
    {
        resize(2 * m_capacity);
        i = getHashIndex(hash);
    }
    ++m_size;
    m_map[i] = new Node(key, value, m_map[i]);
    return true;
}

template<typename hashClass, typename dataType, typename keyType>
inline void bdHashMap<hashClass, dataType, keyType>::createMap(const bdUInt initialCapacity, const bdFloat32 loadFactor)
{
    if (loadFactor <= 0.0 || loadFactor > 1.0)
    {
        bdLogMessage(
            BD_LOG_WARNING,
            "warn/",
            "hashmap",
            __FILE__,
            __FUNCTION__,
            __LINE__,
            "Illegal loadFactor. Using default value.");
    }
}

template<typename hashClass, typename dataType, typename keyType>
inline bdUInt bdHashMap<hashClass, dataType, keyType>::getHashIndex(const bdUInt hash)
{
    return hash & m_capacity - 1;
}

template<typename hashClass, typename dataType, typename keyType>
inline bdInt bdHashMap<hashClass, dataType, keyType>::getSize()
{
    return this->m_size;
}

template<typename hashClass, typename dataType, typename keyType>
inline bdUInt bdHashMap<hashClass, dataType, keyType>::getNextCapacity(const bdUInt targetCapacity)
{
    return bdBitOperations::nextPowerOf2(targetCapacity);
}
