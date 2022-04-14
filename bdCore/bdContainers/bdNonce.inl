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
#include "bdPlatform/bdPlatformRandom/bdPlatformTrulyRandom.h"
#include "bdCore/bdContainers/bdSingleton.h"

#include "bdNonce.h"

template<bdInt SIZE>
inline bdNonce<SIZE>::bdNonce()
{
    m_initialised = false;
}

template<bdInt SIZE>
inline void bdNonce<SIZE>::ensureCreated()
{
    if (!m_initialised)
    {
        bdSingleton<bdTrulyRandomImpl>::getInstance()->getRandomUByte8(m_nonce, SIZE);
        m_initialised = true;
    }
}

template<bdInt SIZE>
inline const bdUByte8* bdNonce<SIZE>::getData()
{
    //bdAssertMsg(m_initialised, "Attempted to retrieve a nonce without initialising it first");
    return m_nonce;
}

