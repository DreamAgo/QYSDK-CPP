#include "../stdafx.h"
#include "dll.h"
#include "log.h"

/**
 * �����־
 * ������ֱ��ʹ�ñ�����
 * @param	INT32	 level		��־�ȼ������� LOG_ ��ͷ�Ķ�Ӧ����
 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
 * @param	string	 event		�¼�����
 * @param	string	 contents	�¼�����
 * @return	INT32	 unknown	�̶�����0
 */
INT32 QYLOG::addLog(
	INT32	level,		//��־�ȼ������� LOG_ ��ͷ�Ķ�Ӧ����
	INT64	robotID,	//������QQ���������ֶ�ŵ�¼
	string	event,		//�¼�����
	string	contents	//�¼�����
)
{
	return QY_addLog(QY::getAuthCode(), robotID, level, event.c_str(), contents.c_str());
}

/**
 * ��ӵ�����־
 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
 * @param	string	 event		�¼�����
 * @param	string	 contents	�¼�����
 * @return	INT32	 unknown	�̶�����0
 */
INT32 QYLOG::Debug(
	INT64	robotID,	//������QQ���������ֶ�ŵ�¼
	string	event,		//�¼�����
	string	contents	//�¼�����
)
{
	return QYLOG::addLog(LOG_DEBUG, robotID, event, contents);
}


/**
 * �����Ϣ��־
 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
 * @param	string	 event		�¼�����
 * @param	string	 contents	�¼�����
 * @return	INT32	 unknown	�̶�����0
 */
INT32 QYLOG::Info(
	INT64	robotID,	//������QQ���������ֶ�ŵ�¼
	string	event,		//�¼�����
	string	contents	//�¼�����
)
{
	return QYLOG::addLog(LOG_INFO, robotID, event, contents);
}

/**
 * ��Ӿ�����־
 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
 * @param	string	 event		�¼�����
 * @param	string	 contents	�¼�����
 * @return	INT32	 unknown	�̶�����0
 */
INT32 QYLOG::Warning(
	INT64	robotID,	//������QQ���������ֶ�ŵ�¼
	string	event,		//�¼�����
	string	contents	//�¼�����
)
{
	return QYLOG::addLog(LOG_WARNING, robotID, event, contents);
}

/**
 * ��Ӵ�����־
 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
 * @param	string	 event		�¼�����
 * @param	string	 contents	�¼�����
 * @return	INT32	 unknown	�̶�����0
 */
INT32 QYLOG::Error(
	INT64	robotID,	//������QQ���������ֶ�ŵ�¼
	string	event,		//�¼�����
	string	contents	//�¼�����
)
{
	return QYLOG::addLog(LOG_ERROR, robotID, event, contents);
}

/**
 * �������������־
 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
 * @param	string	 event		�¼�����
 * @param	string	 contents	�¼�����
 * @return	INT32	 unknown	�̶�����0
 */
INT32 QYLOG::Fatal(
	INT64	robotID,	//������QQ���������ֶ�ŵ�¼
	string	event,		//�¼�����
	string	contents	//�¼�����
)
{
	return QYLOG::addLog(LOG_FATAL, robotID, event, contents);
}