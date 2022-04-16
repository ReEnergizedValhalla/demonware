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

class bdBytePacker
{
public:
	static bdBool appendBuffer(bdUByte8* dest, bdUInt destSize, bdUInt offset, bdUInt* newOffset, const void* src, bdUInt writeSize);
	static bdBool appendEncodedUInt16(bdUByte8* buffer, bdUInt bufferSize, bdUInt offset, bdUInt* newOffset, bdUInt16 value);
	static bdBool removeBuffer(bdUByte8* src, bdUInt srcSize, bdUInt offset, bdUInt* newOffset, void* dest, bdUInt readSize);
	static bdBool removeEncodedUInt16(bdUByte8* buffer, bdUInt bufferSize, bdUInt offset, bdUInt* newOffset, bdUInt16* value);
	static bdBool skipBytes(const bdUByte8* buffer, bdUInt bufferSize, bdUInt offset, bdUInt* newOffset, bdUInt bytes);
	static bdBool rewindBytes(const bdUByte8* buffer, bdUInt bufferSize, bdUInt offset, bdUInt* newOffset, bdUInt bytes);
	template <typename varType>
	static bdBool removeBasicType(const void* buffer, bdUInt bufferSize, bdUInt offset, bdUInt* newOffset, varType* var);
};