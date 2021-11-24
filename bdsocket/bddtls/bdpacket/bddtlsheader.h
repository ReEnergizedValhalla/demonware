#pragma once

#include "../bdDTLSPackets.h"

class bdDTLSHeader
{
public:
	unsigned char m_type;
	unsigned char m_version;
	unsigned short m_vtag;
	unsigned short m_counter;

	bdDTLSHeader();
	bdDTLSHeader(unsigned char type, unsigned short vtag, unsigned short counter);
	unsigned char getType();
	unsigned short getVtag();
	unsigned short getCounter();

	virtual bool serialize(void* data, unsigned int size, unsigned int offset, unsigned int* newOffset);
	virtual bool deserialize(void* data, unsigned int size, unsigned int offset, unsigned int* newOffset);
};