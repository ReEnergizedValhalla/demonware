// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

class bdRandom
{
protected:
	unsigned int m_val;
public:
	bdRandom();
	unsigned int nextUInt();
	void nextUBytes(unsigned char* in, int length);
	void setSeed(unsigned int seed);
};