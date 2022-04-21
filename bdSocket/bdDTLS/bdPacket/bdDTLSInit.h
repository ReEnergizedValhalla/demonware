// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include "bdDTLSHeader.h"
#include <bdCore/bdSocket/bdSecurityID.h>

class bdDTLSInit : public bdDTLSHeader
{
public:
	unsigned short m_initTag;
	bdSecurityID m_secID;

	bdDTLSInit();
	bdDTLSInit(unsigned short initTag, bdSecurityID* secID);

	unsigned short getInitTag();
	void getSecID(bdSecurityID* secID);

	bool serialize(void* data, unsigned int size, unsigned int offset, unsigned int* newOffset);
	bool deserialize(void* data, unsigned int size, unsigned int offset, unsigned int* newOffset);
};
