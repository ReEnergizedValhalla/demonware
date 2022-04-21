// SPDX-License-Identifier: GPL-3.0-or-later
#include "bdCore/bdCore.h"

bdHash::bdHash()
{
    m_type = BD_HASH_SHA256;
    m_digestSize = 0;
}

bdHash::bdHash(bdHashAlgorithms type, bdUInt digestSize)
{
    m_type = type;
    m_digestSize = digestSize;
}

bdHash::~bdHash()
{
    delete this;
}

void bdHash::operator delete(void* p)
{
    bdMemory::deallocate(p);
}
