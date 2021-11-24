#include "bdSecurityID.h"

bdSecurityID::bdSecurityID()
{
	*(unsigned int*)ab = 0x1010101;
	*(unsigned int*)ab[4] = 0x1010101;
}

bdSecurityID::bdSecurityID(bdSecurityID* other)
{
	*this = *other;
}
