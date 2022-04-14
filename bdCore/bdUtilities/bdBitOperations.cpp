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

#include "bdBitOperations.h"

unsigned int bdBitOperations::nextPowerOf2(const unsigned int v)
{
	unsigned int result;

	result = ~((((((((((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 4) | ((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 8) | ((((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 4) | ((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 16) | ((((((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 4) | ((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 8) | ((((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 4) | ((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 1) & (((((((((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 4) | ((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 8) | ((((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 4) | ((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 16) | ((((((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 4) | ((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 8) | ((((v | (v >> 1)) >> 2) | v | (v >> 1)) >> 4) | ((v | (v >> 1)) >> 2) | v | (v >> 1));
	if (result != v)
	{
		result *= 2;
	}
	return result;
}

unsigned int bdBitOperations::highBitNumber(unsigned int v)
{
	bdInt i;

	i = 16;
	if ((v & 0xFFFF0000) == 0)
	{
		i = 0;
	}
	v >>= i;
	if ((v & 0xFF00) != 0)
	{
		i |= 8u;
		v >>= 8;
	}
	if ((v & 0xF0) != 0)
	{
		i |= 4u;
		v >>= 4;
	}
	if ((v & 0xC) != 0)
	{
		i |= 2u;
		v >>= 2;
	}
	return (v >> 1) | i;
}

template<typename T>
void bdBitOperations::endianSwap(const T* src, T* dest)
{
	*dest = *src;
}