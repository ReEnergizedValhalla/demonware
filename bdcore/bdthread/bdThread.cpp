#include <bdCore/bdCore.h>

#include "bdThread.h"

bdThread::bdThread(bdRunnable* runnable, int priority, unsigned int stackSize)
{
	m_handle = nullptr; // ?

	m_runnable = runnable;
	m_threadArgs.m_args = 0;
	m_threadArgs.m_runnable = 0;
	m_isRunning = 0;
	m_stackSize = stackSize;
	m_priority = priority;
	m_threadArgs.m_runnable = m_runnable;
	m_threadArgs.m_thread = this;
}

bdThread::~bdThread()
{
	if (m_threadArgs.m_args)
	{

	}
}