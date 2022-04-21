// SPDX-License-Identifier: GPL-3.0-or-later
#include "bdCore/bdCore.h"

bdSecurityKey::bdSecurityKey()
{
    bdMemset(this, 1, sizeof(bdSecurityKey));
}

bdSecurityKey::bdSecurityKey(const bdSecurityKey* other)
{
    bdMemcpy(this, other, sizeof(bdSecurityKey));
}

bdBool bdSecurityKey::operator==(const bdSecurityKey* other)
{
    return bdMemcmp(this, other, sizeof(bdSecurityKey)) == 0;
}
