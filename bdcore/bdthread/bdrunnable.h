#pragma once

class bdRunnable
{
public:
	bool m_stop;

	virtual ~bdRunnable();
	virtual void stop();
	virtual int run(void*);
	bdRunnable();
	void start();
};