#pragma once

#include "bdPlatform/bdPlatformSocket/bdInAddr.h"

class bdInetAddr
{
protected:
	bdInAddr m_addr;
public:
	bool operator == (bdInetAddr* comp);

	static bdInetAddr Broadcast();
	static bdInetAddr All();
	bdInetAddr();
	~bdInetAddr();
	bdInetAddr(bdInetAddr* other);
	bdInetAddr(const char* address);
	bdInetAddr(unsigned int address);
	void set(const bdInetAddr* other);
	void set(const char* address);
	void set(unsigned int address);
	bool isValid();
	unsigned int toString(char* str, unsigned int size);
	bdInAddr getInAddr();
	bool serialize(char* data, unsigned int size, unsigned int offset, unsigned int* newOffset);
	bool deserialize(char* data, unsigned int size, unsigned int offset, unsigned int* newOffset);
};