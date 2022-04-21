// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#define BD_ENDPOINT_SERIALIZED_SIZE 45

class bdEndpoint
{
public:
    bdCommonAddrRef m_ca;
    bdSecurityID m_secID;

    bdEndpoint();
    bdEndpoint(const bdEndpoint* other);
    bdEndpoint(const bdCommonAddrRef addr, const bdSecurityID* secID);
    ~bdEndpoint();
    bdBool operator==(bdEndpoint* other);
    bdCommonAddrRef getCommonAddr();
    bdSecurityID* getSecID();
    bdUInt getHash();
    bdUInt getSerializedLength();
    bdBool serialize(void* data, const bdUInt size, const bdUInt offset, bdUInt* newOffset);
    bdBool deserialize(bdCommonAddrRef me, const void* data, const bdUInt size, const bdUInt offset, bdUInt* newOffset);
};