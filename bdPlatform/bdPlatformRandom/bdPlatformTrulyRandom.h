#pragma once

class bdTrulyRandomImpl
{
public:
	bdTrulyRandomImpl();
	~bdTrulyRandomImpl();
	virtual int getRandomUInt();
	virtual void getRandomUByte8();
};

void bdGetRandomUChar8(unsigned char* in, int length);