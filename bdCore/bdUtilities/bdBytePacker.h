// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

class bdBytePacker
{
public:
    static bdBool appendBuffer(bdUByte8* dest, bdUInt destSize, bdUInt offset, bdUInt* newOffset, const void* src, bdUInt writeSize);
    static bdBool appendEncodedUInt16(bdUByte8* buffer, bdUInt bufferSize, bdUInt offset, bdUInt* newOffset, bdUInt16 value);
    static bdBool removeBuffer(const bdUByte8* src, bdUInt srcSize, bdUInt offset, bdUInt* newOffset, void* dest, bdUInt readSize);
    static bdBool removeEncodedUInt16(bdUByte8* buffer, bdUInt bufferSize, bdUInt offset, bdUInt* newOffset, bdUInt16* value);
    static bdBool skipBytes(const bdUByte8* buffer, bdUInt bufferSize, bdUInt offset, bdUInt* newOffset, bdUInt bytes);
    static bdBool rewindBytes(const bdUByte8* buffer, bdUInt bufferSize, bdUInt offset, bdUInt* newOffset, bdUInt bytes);
    template <typename varType>
    static bdBool removeBasicType(const void* buffer, bdUInt bufferSize, bdUInt offset, bdUInt* newOffset, varType* var);
    template <typename varType>
    static bdBool appendBasicType(const void* buffer, bdUInt bufferSize, bdUInt offset, bdUInt* newOffset, varType* var);
};