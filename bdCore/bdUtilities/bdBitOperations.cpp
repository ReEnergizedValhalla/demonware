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
	unsigned int v1, v2;

	v1 = (v & 0xFFFF0000) != 0 ? 0x10 : 0;
	v2 = v >> ((v & 0xFFFF0000) != 0 ? 0x10 : 0);
	if ((v2 & 0xFF00) != 0)
	{
		v1 |= 8u;
		v2 >>= 8;
	}
	if ((v2 & 0xF0) != 0)
	{
		v1 |= 4u;
		v2 >>= 4;
	}
	if ((v2 & 0xC) != 0)
	{
		v1 |= 2u;
		v2 >>= 2;
	}
	return v1 | (v2 >> 1);
}
