// SPDX-License-Identifier: GPL-3.0-or-later
#include "bdCore/bdCore.h"

bdUInt bdCommonAddrInfo::getInfo(bdCommonAddrRef addr, bdNChar8* buf, const bdUInt length)
{
    if (addr.notNull())
    {
        return getInfo(addr.m_ptr, buf, length);
    }
    return 0;
}

bdUInt bdCommonAddrInfo::getInfo(const bdCommonAddr* addr, bdNChar8* buf, const bdUInt length)
{
    return bdUInt();
}

bdUInt bdCommonAddrInfo::getBriefInfo(const bdCommonAddrRef addr, bdNChar8* buf, const bdUInt length)
{
    return bdUInt();
}

bdUInt bdCommonAddrInfo::getBriefInfo(const bdCommonAddr* addr, bdNChar8* buf, const bdUInt length)
{
    return bdUInt();
}
