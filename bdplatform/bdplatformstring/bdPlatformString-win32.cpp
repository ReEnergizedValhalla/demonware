#include "bdPlatformString.h"

unsigned int bdStrGetToken(const char* str, const char* delimeters, char* tokenBuffer, unsigned int tokenBufferSize, const char** end)
{
	int tokenSize;
	int offset = 0;

	if (str)
	{
		tokenSize = strspn(str, delimeters);
		offset = strcspn(&str[tokenSize], delimeters);
		if (offset + 1 >= tokenBufferSize)
		{
			bdStrlcpy(tokenBuffer, &str[tokenSize], tokenBufferSize);
		}
		else
		{
			bdStrlcpy(tokenBuffer, &str[tokenSize], offset + 1);
		}

		if (end)
		{
			*end = &str[tokenSize + offset];
		}
	}
	return offset;
}

bool bdDelimSubstr(const char* str, const char* substr, const char* delimeters)
{
	bool isSubStr = true;
	char subStrToken[68];
	char strToken[68];
	unsigned int token;

	while (isSubStr)
	{
		memset(subStrToken, 0, 64);
		token = bdStrGetToken(substr, delimeters, subStrToken, 64, &substr);
		if (token < 64 && token)
		{
			memset(strToken, 0, 64);
			if (bdStrGetToken(str, delimeters, strToken, 64, &str) < 64)
			{
				isSubStr = !_stricmp(subStrToken, strToken);
			}
		}
		else
		{
			break;
		}
	}
	return isSubStr;
}
