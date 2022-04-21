// SPDX-License-Identifier: GPL-3.0-or-later
#include "bdPlatform/bdPlatform.h"
#include "bdCore/bdUtilities/bdbytepacker.h"

#include "bdDTLSHeader.h"

bdDTLSHeader::bdDTLSHeader()
{
    m_version = 2;
    m_type = 0;
    m_vtag = 0;
    m_counter = 0;
}

bdDTLSHeader::bdDTLSHeader(unsigned char type, unsigned short vtag, unsigned short counter)
{
    m_vtag = vtag;
    m_version = 2;
    m_counter = counter;
    m_type = type;
}

unsigned char bdDTLSHeader::getType()
{
    return m_type;
}

unsigned short bdDTLSHeader::getVtag()
{
    return m_vtag;
}

unsigned short bdDTLSHeader::getCounter()
{
    return m_counter;
}

bool bdDTLSHeader::serialize(void* data, unsigned int size, unsigned int offset, unsigned int* newOffset)
{
    *newOffset = offset;
    if (bdBytePacker::appendBuffer(reinterpret_cast<bdUByte8*>(data), size, offset, newOffset, &m_type, sizeof(m_type)))
    {
        offset = *newOffset;
        if (bdBytePacker::appendBuffer(reinterpret_cast<bdUByte8*>(data), size, offset, newOffset, &m_version, sizeof(m_version)))
        {
            offset = *newOffset;
            if (bdBytePacker::appendBuffer(reinterpret_cast<bdUByte8*>(data), size, offset, newOffset, &m_vtag, sizeof(m_vtag)))
            {
                offset = *newOffset;
                if (bdBytePacker::appendBuffer(reinterpret_cast<bdUByte8*>(data), size, offset, newOffset, &m_counter, sizeof(m_counter)))
                {
                    return true;
                }
            }
        }
    }
    *newOffset = offset;
    return false;
}

bool bdDTLSHeader::deserialize(void* data, unsigned int size, unsigned int offset, unsigned int* newOffset)
{
    *newOffset = offset;
    if (bdBytePacker::removeBuffer(reinterpret_cast<bdUByte8*>(data), size, offset, newOffset, &m_type, sizeof(m_type)))
    {
        offset = *newOffset;
        if (bdBytePacker::removeBuffer(reinterpret_cast<bdUByte8*>(data), size, offset, newOffset, &m_version, sizeof(m_version)))
        {
            offset = *newOffset;
            if (bdBytePacker::removeBuffer(reinterpret_cast<bdUByte8*>(data), size, offset, newOffset, &m_vtag, sizeof(m_vtag)))
            {
                offset = *newOffset;
                if (bdBytePacker::removeBuffer(reinterpret_cast<bdUByte8*>(data), size, offset, newOffset, &m_counter, sizeof(m_counter)))
                {
                    return true;
                }
            }
        }
    }
    *newOffset = 0;
    return false;
}
