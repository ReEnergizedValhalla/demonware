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

template<typename T>
class bdArray
{
public:
    T* m_data;
    unsigned int m_capacity;
    unsigned int m_size;

    bdUInt getSize();
    T* uninitializedCopy(const bdArray<T>* a);
    void clear();
    void pushBack(const T* value);
    void copyConstructObjectObject(T* dest, const T* src);
    void copyConstructArrayArray(T* dest, const T* src, unsigned int n);
    void destruct(T* src, bdUInt n);
    void increaseCapacity(unsigned int increase);
    void decreaseCapacity(const bdUInt decrease);
    ~bdArray();
    bdBool rangeCheck(const bdUInt i);
    T* operator[](const bdUInt i);
    void operator=(bdArray<T>* a);
};
