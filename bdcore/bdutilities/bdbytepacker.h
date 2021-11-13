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