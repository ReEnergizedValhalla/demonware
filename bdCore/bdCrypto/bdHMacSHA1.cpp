// SPDX-License-Identifier: GPL-3.0-or-later
#include "bdCore/bdCore.h"

bdHMacSHA1::bdHMacSHA1() : bdHMac()
{
}

bdHMacSHA1::bdHMacSHA1(const bdUByte8* const key, const bdUInt keySize) : bdHMac()
{
    bdInt idx;
    bdInt status;

    if (register_hash(&sha1_desc) == -1)
    {
        //bdLog(BD_LOG_ERROR, "Error registering SHA1");
    }
    idx = find_hash("sha1");
    status = hmac_init(&m_state, idx, key, keySize);
    if (status)
    {
        //bdLog(BD_LOG_ERROR, "Error setting up HMAC-SHA1: [%s]", error_to_string(status));
    }
}

bdHMacSHA1::~bdHMacSHA1()
{
    delete this;
}

void* bdHMacSHA1::operator new(bdUWord nbytes)
{
    return bdMemory::allocate(nbytes);
}

void* bdHMacSHA1::operator new(bdUWord __needed, void* p)
{
    return p;
}

void bdHMacSHA1::operator delete(void* p)
{
    bdMemory::deallocate(p);
}

bdBool bdHMacSHA1::process(const bdUByte8* const data, const bdUInt length)
{
    bdInt status;

    status = hmac_process(&m_state, data, length);
    if (!status)
    {
        return 1;
    }
    //bdLog(BD_LOG_ERROR, "Error processing HMAC-SHA1: [%s]", error_to_string(status));
}

bdBool bdHMacSHA1::getData(bdUByte8* dst, bdUInt* length)
{
    bdULong tmpLength;
    bdInt status;

    if (*length > 20)
    {
        //bdLog(BD_LOG_ERROR, "Hmac result buffer of invalid size.");
        return false;
    }

    tmpLength = *length;
    status = hmac_done(&m_state, dst, &tmpLength);
    if (status)
    {
        //bdLog(BD_LOG_ERROR, "Error getting HMAC-SHA1 data: [%s]", error_to_string(status));
        return false;
    }
    *length = tmpLength;
    return true;
}
