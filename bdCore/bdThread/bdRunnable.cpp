// SPDX-License-Identifier: GPL-3.0-or-later
#include "bdCore/bdCore.h"

bdRunnable::~bdRunnable()
{
}

void bdRunnable::stop()
{
	m_stop = 1;
}

bdRunnable::bdRunnable()
{
	m_stop = 0;
}

void bdRunnable::start()
{
	m_stop = 0;
}
