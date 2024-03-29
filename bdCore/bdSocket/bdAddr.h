// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

class bdAddr
{
protected:
    bdInetAddr m_address;
    bdPort m_port;
public:
    static bdUInt serializedSize;

    bdAddr();
    bdAddr(const bdAddr* other);
    bdAddr(const bdInetAddr* address, const bdPort port);
    bdAddr(const bdNChar8* socketAddress);

    void set(const bdNChar8* socketAddress);
    void set(const bdInetAddr* address, const bdPort port);
    void setPort(const bdPort port);

    bdUInt getHash();
    bdInetAddr* getAddress();
    bdPort getPort();
    bdUInt getSerializedSize();

    bdUWord toString(bdNChar8* const str, const bdUWord size);
    bdBool serialize(bdUByte8* data, const bdUInt size, const bdUInt offset, bdUInt* newOffset);
    bdBool deserialize(const bdUByte8* data, const bdUInt size, const bdUInt offset, bdUInt* newOffset);

};