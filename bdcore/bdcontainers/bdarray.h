// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

template<typename T>
class bdArray
{
public:
	T* m_data;
	unsigned int m_capacity;
	unsigned int m_size;

	void clear();
	void pushBack(const T* value);
	void copyConstructArrayArray(T* dest, const T* src, unsigned int n);
	void increaseCapacity(unsigned int increase);
	~bdArray();
	bdArray();
};
