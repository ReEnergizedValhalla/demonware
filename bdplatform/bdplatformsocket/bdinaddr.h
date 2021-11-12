#pragma once

class bdInAddr
{
public:
	bdInAddr();
	void fromString(const char* addr);
	int toString(char* str, unsigned int size);
	union
	{
		struct
		{
			char m_b1;
			char m_b2;
			char m_b3;
			char m_b4;
		} m_caddr;
		unsigned int m_iaddr;
	} inUn;
};