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

class bdSequenceNumber
{
public:
    bdInt32 m_seqNum;

    bdSequenceNumber(const bdSequenceNumber* last, const bdUInt seqNumber, const bdUInt bits);
    bdSequenceNumber(const bdInt seqNum);
    bdSequenceNumber();

    bdBool operator!=(const bdSequenceNumber* other);
    bdSequenceNumber operator+(const bdSequenceNumber* other);
    bdSequenceNumber* operator++();
    bdSequenceNumber* operator+=(const bdSequenceNumber* other);
    bdSequenceNumber operator-(const bdSequenceNumber* other);
    bdBool operator<(const bdSequenceNumber* other);
    bdBool operator<=(const bdSequenceNumber* other);
    bdBool operator==(const bdSequenceNumber* other);
    bdBool operator>(const bdSequenceNumber* other);
    bdBool operator>=(const bdSequenceNumber* other);

    bdInt32 getValue();
    void set(const bdSequenceNumber* last, const bdUInt seqNumber, const bdUInt bits);
};