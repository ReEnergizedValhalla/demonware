// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

unsigned int bdStrlcpy(char* dst, const char* src, size_t size);
bdUWord bdStrlen(const bdNChar8* const s);
bdUWord bdStrnlen(const bdNChar8* const s, const bdUWord maxLen);
const bdNChar8* bdStrchr(const bdNChar8* s, const bdInt c);
int bdSnprintf(char* buf, unsigned int maxlen, const char* format, ...);
bdInt bdVsnprintf(bdNChar8* buf, const bdUWord maxlen, const bdNChar8* format, va_list* argPtr);
int bdPrintf(const char* format, ...);
unsigned int bdStrGetToken(const char* str, const char* delimeters, char* tokenBuffer, unsigned int tokenBufferSize, const char** end);
bool bdDelimSubstr(const char* str, const char* substr, const char* delimeters);