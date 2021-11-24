// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdstopwatch.cpp:0x9D03F0
void __cdecl bdBitBuffer::typeToString(
        const bdBitBufferDataType type,
        char *const strBuffer,
        const unsigned int strLength)
{
  bdBitBufferDataType v3; // eax
  char *v4; // ebx
  unsigned int v5; // eax
  unsigned int v6; // esi
  const char *dataTypeDescs[23]; // [esp+0h] [ebp-5Ch]

  dataTypeDescs[16] = "String";
  dataTypeDescs[17] = "String";
  dataTypeDescs[0] = "NoType";
  dataTypeDescs[1] = "Bool";
  dataTypeDescs[2] = "Char8";
  dataTypeDescs[3] = "UChar8";
  dataTypeDescs[4] = "WChar16";
  dataTypeDescs[5] = "Int16";
  dataTypeDescs[6] = "UInt16";
  dataTypeDescs[7] = "Int32";
  dataTypeDescs[8] = "UInt32";
  dataTypeDescs[9] = "Int64";
  dataTypeDescs[10] = "UInt64";
  dataTypeDescs[11] = "RangedInt32";
  dataTypeDescs[12] = "RangeUInt32";
  dataTypeDescs[13] = "Float32";
  dataTypeDescs[14] = "Float64";
  dataTypeDescs[15] = "RangeFloat32";
  dataTypeDescs[18] = "MultiByteString";
  dataTypeDescs[19] = "Blob";
  dataTypeDescs[20] = "NaN";
  dataTypeDescs[21] = "FullType";
  dataTypeDescs[22] = "Unknown Type";
  if ( type <= (BD_BB_NAN_TYPE|BD_BB_SIGNED_CHAR8_TYPE) )
    v3 = type < BD_BB_NO_TYPE ? BD_BB_NO_TYPE : type;
  else
    v3 = BD_BB_NAN_TYPE|BD_BB_SIGNED_CHAR8_TYPE;
  v4 = (char *)dataTypeDescs[v3];
  v5 = strlen(v4);
  if ( strLength && strBuffer )
  {
    v6 = strLength - 1;
    if ( v5 < strLength - 1 )
      v6 = v5;
    memcpy((unsigned __int8 *)strBuffer, (unsigned __int8 *)v4, v6);
    strBuffer[v6] = 0;
  }
}

#endif // __UNIMPLEMENTED__
