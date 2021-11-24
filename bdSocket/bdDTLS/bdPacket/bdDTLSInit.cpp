#include "bdDTLSInit.h"

#include <bdCore/bdUtilities/bdbytepacker.h>

bdDTLSInit::bdDTLSInit() : bdDTLSHeader()
{
	m_initTag = 0;
	m_secID = new bdSecurityID();
}

bdDTLSInit::bdDTLSInit(unsigned short initTag, bdSecurityID* secID) : bdDTLSHeader(BD_DTLS_INIT, 0, 0)
{
	m_initTag = initTag;
	m_secID = new bdSecurityID(secID);
}

unsigned short bdDTLSInit::getInitTag()
{
	return m_initTag;
}

void bdDTLSInit::getSecID(bdSecurityID* secID)
{
	*secID = m_secID;
}

bool bdDTLSInit::serialize(void* data, unsigned int size, unsigned int offset, unsigned int* newOffset)
{
	*newOffset = offset;
	if (bdDTLSHeader::serialize(data, size, offset, newOffset))
	{
		offset = *newOffset;
		if (bdBytePacker::appendBuffer((char*)data, size, offset, newOffset, &m_initTag, sizeof(m_initTag)))
		{
			offset = *newOffset;
			if (bdBytePacker::appendBuffer((char*)data, size, offset, newOffset, &m_secID, sizeof(m_secID)))
			{
				return true;
			}
		}
	}
	*newOffset = offset;
	return false;
}

bool bdDTLSInit::deserialize(void* data, unsigned int size, unsigned int offset, unsigned int* newOffset)
{
	*newOffset = offset;
	if (bdDTLSHeader::deserialize(data, size, offset, newOffset))
	{
		offset = *newOffset;
		if (bdBytePacker::removeBuffer((char*)data, size, offset, newOffset, &m_initTag, sizeof(m_initTag)))
		{
			offset = *newOffset;
			if (bdBytePacker::removeBuffer((char*)data, size, offset, newOffset, &m_secID, sizeof(m_secID)))
			{
				return 1;
			}
		}
	}
	*newOffset = offset;
	return 0;
}

