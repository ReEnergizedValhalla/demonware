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

enum bdBitBufferDataType : __int32
{
	BD_BB_NO_TYPE = 0x0,
	BD_BB_BOOL_TYPE = 0x1,
	BD_BB_SIGNED_CHAR8_TYPE = 0x2,
	BD_BB_UNSIGNED_CHAR8_TYPE = 0x3,
	BD_BB_WCHAR16_TYPE = 0x4,
	BD_BB_SIGNED_INTEGER16_TYPE = 0x5,
	BD_BB_UNSIGNED_INTEGER16_TYPE = 0x6,
	BD_BB_SIGNED_INTEGER32_TYPE = 0x7,
	BD_BB_UNSIGNED_INTEGER32_TYPE = 0x8,
	BD_BB_SIGNED_INTEGER64_TYPE = 0x9,
	BD_BB_UNSIGNED_INTEGER64_TYPE = 0xA,
	BD_BB_RANGED_SIGNED_INTEGER32_TYPE = 0xB,
	BD_BB_RANGED_UNSIGNED_INTEGER32_TYPE = 0xC,
	BD_BB_FLOAT32_TYPE = 0xD,
	BD_BB_FLOAT64_TYPE = 0xE,
	BD_BB_RANGED_FLOAT32_TYPE = 0xF,
	BD_BB_SIGNED_CHAR8_STRING_TYPE = 0x10,
	BD_BB_UNSIGNED_CHAR8_STRING_TYPE = 0x11,
	BD_BB_MBSTRING_TYPE = 0x12,
	BD_BB_BLOB_TYPE = 0x13,
	BD_BB_NAN_TYPE = 0x14,
	BD_BB_FULL_TYPE = 0x15,
	BD_COMPRESSED_BB_PAYLOAD_TYPE = 0x16,
	BD_BB_MAX_TYPE = 0x20,
};