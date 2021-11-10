#include "types.h"
#include "functions.h"
#include "vars.h"

bdRemoteTask::bdStatus bdRemoteTask::getStatus()
{
	if ( m_status == BD_PENDING && m_timeout > 0.0 )
	{
		if (m_timeout <= m_timer.getElapsedTimeInSeconds())
		{
			m_status = BD_TIMED_OUT;
			m_byteResults.m_ptr = 0;

			bdLogMessage(
				BD_LOG_INFO,
				"info/",
				"remote task",
				__FILE__,
				"bdRemoteTask::getStatus",
				__LINE__,
				"Remote task timed out after %.3fs.",
				m_timeout);
		}
	}
}

unsigned int bdRemoteTask::getTotalNumResults()
{

}

void bdRemoteTask::cancelTask()
{

}

void bdRemoteTask::setTimeout(float timeout)
{

}

unsigned __int64 bdRemoteTask::getTransactionID()
{

}

bdLobbyErrorCode bdRemoteTask::getErrorCode()
{

}
void bdRemoteTask::setTaskResult(bdTaskResult* result, unsigned int maxResults)
{

}

void bdRemoteTask::setTaskResultProcessor(bdTaskResultProcessor* resultProcessor)
{

}

void bdRemoteTask::handleTaskReply(bdReference<bdCommonAddr> addr)
{

}

void bdRemoteTask::handleAsyncTaskReply(bdReference<bdCommonAddr> addr)
{

}
bool bdRemoteTask::deserializeTaskReply(bdReference<bdCommonAddr> addr)
{

}

void bdRemoteTask::start(float timeout)
{

}

void bdRemoteTask::stop(bdReference<bdCommonAddr> addr, unsigned __int64 transactionID)
{

}
