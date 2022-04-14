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
	static bool appendBuffer(char* dest, unsigned int destSize, unsigned int offset, unsigned int* newOffset, void* src, unsigned int writeSize);
	static bool appendEncodedUInt16(char* buffer, unsigned int bufferSize, unsigned int offset, unsigned int* newOffset, unsigned short value);
	static bool removeBuffer(char* src, unsigned int srcSize, unsigned int offset, unsigned int* newOffset, void* dest, unsigned int readSize);
	static bool removeEncodedUInt16(char* buffer, unsigned int bufferSize, unsigned int offset, unsigned int* newOffset, unsigned short* value);
	static bool skipBytes(const char* buffer, unsigned int bufferSize, unsigned int offset, unsigned int* newOffset, unsigned int bytes);
	static bool rewindBytes(const char* buffer, unsigned int bufferSize, unsigned int offset, unsigned int* newOffset, unsigned int bytes);
};