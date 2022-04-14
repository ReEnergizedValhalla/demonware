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

class bdThreadArgs
{
public:
	void* m_args;
	class bdRunnable* m_runnable;
	class bdThread* m_thread;
};

class bdThread
{
public:
	class bdRunnable* m_runnable;
	bdThreadArgs m_threadArgs;
	void* m_handle;
	bool m_isRunning;
	unsigned int m_stackSize;
	unsigned int m_priority;

	bdThread(class bdRunnable* runnable, int priority, unsigned int stackSize);
	~bdThread();
	void join();
	void wakeupJoiningThread();
	void setThreadName(const char* name);
	static int threadProc(bdThreadArgs* args);
	bool start(char* args, unsigned int size);

};