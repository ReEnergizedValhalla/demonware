// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

class bdRunnable
{
public:
	bool m_stop;

	virtual ~bdRunnable();
	virtual void stop();
	virtual int run(void*) { return 0; };
	bdRunnable();
	void start();
};