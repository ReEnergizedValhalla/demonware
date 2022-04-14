/*
* DemonWare
* Copyright (c) 2020-2022 OpenIW
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, version 3.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#include "bdBitBufferTypes.h"

class bdBitBuffer : bdReferencable
{
public:
    bdFastArray<unsigned char> m_data;
    bdUInt m_writePosition;
    bdUInt m_maxWritePosition;
    bdUInt m_readPosition;
    bdBool m_failedRead;
    bdBool m_typeChecked;

    bdBitBuffer(const bdUInt capacityBits, const bdBool typeChecked);
    bdBitBuffer(const bdUByte8* bits, const bdUInt numBits, const bdBool dataHasTypeCheckedBit);
    ~bdBitBuffer();
    void* operator new(bdUWord nbytes);
    void operator delete(void* p);

    void writeBits(const void* bits, const bdUInt numBits);
    bdBool writeBool(const bdBool b);
    void writeUInt32(const bdUInt32 u);
    void writeInt32(const bdInt32 i);
    void writeFloat32(const bdFloat32 f);
    void writeRangedUInt32(const bdUInt u, const bdUInt begin, const bdUInt end, const bdBool typeChecked);
    void writeDataType(const bdBitBufferDataType dataType);
    void writeRangedInt32(const bdInt i, const bdInt begin, const bdInt end);
    void writeRangedFloat32(const bdFloat32 f, const bdFloat32 begin, const bdFloat32 end, const bdFloat32 precision);
    bdBool readBits(void* bits, bdUInt numBits);
    bdBool readUint32(bdUInt* u);
    bdBool readInt32(bdInt32* i);
    bdBool readFloat32(bdFloat32* f);
    bdBool readRangedUInt32(bdUInt* u, const bdUInt begin, const bdUInt end, const bdBool typeChecked);
    bdBool readDataType(const bdBitBufferDataType expectedDataType);
    bdBool readRangedInt32(bdInt* i, const bdInt begin, const bdInt end);
    bdBool readRangedFloat32(bdFloat32* f, const bdFloat32 begin, const bdFloat32 end, const bdFloat32 precision);
    void setTypeCheck(const bdBool flag);
    bdBool getTypeCheck();
    bdUByte8* getData();
    static void typeToString(const bdBitBufferDataType type, bdNChar8* const strBuffer, const bdUWord strLength);
    bdBitBufferDataType readDataType();
    bdBool append(bdBitBuffer* other);
    void resetReadPosition();
    bdUInt getReadPosition();
    bdUInt getDataSize();
    bdUInt getNumBitsWritten();
    void setReadPosition(const bdUInt bitPosition);
};