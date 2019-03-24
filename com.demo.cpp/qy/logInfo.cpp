#include "../stdafx.h"
#include "logInfo.h"

/**
 * ��ӳɹ���Ϣ��־
 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
 * @param	string	 event		�¼�����
 * @param	string	 contents	�¼�����
 * @return	INT32	 unknown	�̶�����0
 */
INT32 QYLOG_INFO::Success(
	INT64	robotID,	//������QQ���������ֶ�ŵ�¼
	string	event,		//�¼�����
	string	contents	//�¼�����
)
{
	return QYLOG::addLog(LOG_INFO_SUCCESS, robotID, event, contents);
}

/**
 * ���ʧ����Ϣ��־
 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
 * @param	string	 event		�¼�����
 * @param	string	 contents	�¼�����
 * @return	INT32	 unknown	�̶�����0
 */
INT32 QYLOG_INFO::Fail(
	INT64	robotID,	//������QQ���������ֶ�ŵ�¼
	string	event,		//�¼�����
	string	contents	//�¼�����
)
{
	return QYLOG::addLog(LOG_INFO_FAIL, robotID, event, contents);
}

/**
 * ��ӽ�����Ϣ��־
 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
 * @param	string	 event		�¼�����
 * @param	string	 contents	�¼�����
 * @return	INT32	 unknown	�̶�����0
 */
INT32 QYLOG_INFO::Receive(
	INT64	robotID,	//������QQ���������ֶ�ŵ�¼
	string	event,		//�¼�����
	string	contents	//�¼�����
)
{
	return QYLOG::addLog(LOG_INFO_RECEIVE, robotID, event, contents);
}

/**
 * ��ӷ�����Ϣ��־
 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
 * @param	string	 event		�¼�����
 * @param	string	 contents	�¼�����
 * @return	INT32	 unknown	�̶�����0
 */
INT32 QYLOG_INFO::Send(
	INT64	robotID,	//������QQ���������ֶ�ŵ�¼
	string	event,		//�¼�����
	string	contents	//�¼�����
)
{
	return QYLOG::addLog(LOG_INFO_SEND, robotID, event, contents);
}
