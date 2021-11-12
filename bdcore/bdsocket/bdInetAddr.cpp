#include "bdInetAddr.h"

#include <bdPlatform/bdPlatform.h>

bool bdInetAddr::operator==(bdInetAddr* comp)
{
	return (int*)this == (int*)comp;
}

bdInetAddr bdInetAddr::Broadcast()
{
	bdInetAddr addr;

	addr.set(0xFFFFFFFF);
	bdInetAddr* InetAddr(&addr);
	return InetAddr;
}

bdInetAddr bdInetAddr::All()
{
	bdInetAddr addr;

	addr.set(0u);
	bdInetAddr* InetAddr(&addr);
	return InetAddr;
}

bdInetAddr::bdInetAddr()
{
}

bdInetAddr::~bdInetAddr()
{
	m_addr.inUn.m_iaddr = 0xDEADBEEF;
}

bdInetAddr::bdInetAddr(bdInetAddr* other)
{
	*this = *other;
}

bdInetAddr::bdInetAddr(const char* address)
{
	set(address);
}

bdInetAddr::bdInetAddr(unsigned int address)
{
	set(address);
}

void bdInetAddr::set(const bdInetAddr* other)
{
	*this = *other;
}

void bdInetAddr::set(const char* address)
{
	m_addr.fromString(address);
}

void bdInetAddr::set(unsigned int address)
{
	m_addr.inUn.m_iaddr = address;
}

bool bdInetAddr::isValid()
{
	bdInetAddr* chk = &bdInetAddr();

	return (this == chk) == 0;
}

unsigned int bdInetAddr::toString(char* str, unsigned int size)
{
	if (isValid())
	{
		return m_addr.toString(str, size);
	}
	return 0;
}

bdInAddr bdInetAddr::getInAddr()
{
	return bdInAddr();
}

bool bdInetAddr::serialize(char* data, unsigned int size, unsigned int offset, unsigned int* newOffset)
{
	return false;
}

bool bdInetAddr::deserialize(char* data, unsigned int size, unsigned int offset, unsigned int* newOffset)
{
	return false;
}

