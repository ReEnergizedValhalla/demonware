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

class bdSequenceNumberStore
{
public:
    enum bdSequenceStatus : __int32
    {
        BD_SN_INVALID_SMALLER = -2,
        BD_SN_VALID_SMALLER = -1,
        BD_SN_INVALID_DUPLICATE = 0,
        BD_SN_VALID_LARGER = 1,
        BD_SN_VALID_MUCH_LARGER = 2,
    };
protected:
    bdUInt32 m_bitmap;
    bdSequenceNumber m_lastSeq;
public:
    bdSequenceNumberStore();
    bdSequenceNumberStore(const bdSequenceNumber* initial);

    bdSequenceStatus check(const bdSequenceNumber* thisSeq);
    bdSequenceNumber* getLastSequenceNumber();
    void reset(const bdSequenceNumber* initial);
};