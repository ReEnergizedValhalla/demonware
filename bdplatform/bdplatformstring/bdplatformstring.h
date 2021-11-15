#pragma once

#include <bdPlatform/bdPlatform.h>

inline static unsigned int bdStrlcpy(char* dst, const char* src, size_t size)
{
    unsigned int slen;

    slen = strlen(src);
    if (size && dst)
    {
        if (slen >= size - 1)
        {
            slen = size - 1;
        }
        memcpy(dst, (char*)src, slen);
        dst[slen] = 0;
    }
    return slen;
}

unsigned int bdStrGetToken(const char* str, const char* delimeters, char* tokenBuffer, unsigned int tokenBufferSize, const char** end);
bool bdDelimSubstr(const char* str, const char* substr, const char* delimeters);