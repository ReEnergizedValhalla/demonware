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
#include "bdPlatform/bdPlatform.h"
#include "bdCore/bdContainers/bdSequenceNumber.h"

#include "bdSequenceNumberStore.h"

bdSequenceNumberStore::bdSequenceNumberStore()
{
    m_bitmap = 0;
    m_lastSeq.m_seqNum = 0;
}

bdSequenceNumberStore::bdSequenceNumberStore(const bdSequenceNumber* initial)
{
    m_bitmap = 0;
    m_lastSeq.m_seqNum = initial->m_seqNum;
}

bdSequenceNumberStore::bdSequenceStatus bdSequenceNumberStore::check(const bdSequenceNumber* thisSeq)
{
    bdUInt diff;
    bdSequenceNumber sdiff;

    if (thisSeq > &m_lastSeq)
    {
        sdiff = thisSeq - &m_lastSeq;
        diff = sdiff.getValue();
        if (diff >= 32)
        {
            m_lastSeq = *thisSeq;
            m_bitmap = 1;
            return BD_SN_VALID_MUCH_LARGER;
        }
        else
        {
            m_bitmap = (m_bitmap << diff) | 1;
            m_lastSeq = *thisSeq;
            return BD_SN_VALID_LARGER;
        }
    }
    else
    {
        sdiff = &m_lastSeq - thisSeq;
        diff = sdiff.getValue();
        if (diff < 0x20)
        {
            if (((1 << diff) & m_bitmap) != 0)
            {
                return BD_SN_INVALID_DUPLICATE;
            }
            else
            {
                m_bitmap |= 1 << diff;
                return BD_SN_VALID_SMALLER;
            }
        }
        else
        {
            return BD_SN_INVALID_SMALLER;
        }
    }
}

bdSequenceNumber* bdSequenceNumberStore::getLastSequenceNumber()
{
    return &m_lastSeq;
}

void bdSequenceNumberStore::reset(const bdSequenceNumber* initial)
{
    m_bitmap = 0;
    m_lastSeq.m_seqNum = initial->m_seqNum;
}
