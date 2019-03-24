#pragma once
#include "logInfo.h"

class QYLOG
{	
	private:
		/* ��־���� */
		static const auto LOG_DEBUG = 0;			//����			�����Ļ�ɫ(DimGray)			6908265   #696969  RGB(105,105,105)
		static const auto LOG_INFO = 10;			//��Ϣ			����(Black)					0         #000000  RGB(0,0,0)
		static const auto LOG_WARNING = 20;			//����			���ɫ(DarkOrange)			36095     #FF8C00  RGB(255,140,0)
		static const auto LOG_ERROR = 30;			//����			���ɫ(DeepPink)				9639167   #FF1493  RGB(255,20,147)
		static const auto LOG_FATAL = 40;			//��������		����(Red)					255       #FF0000  RGB(255,0,0)

		/** 
		 * �����־
		 * ������ֱ��ʹ�ñ�����
		 * @param	INT32	 level		��־�ȼ������� LOG_ ��ͷ�Ķ�Ӧ����
		 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
		 * @param	string	 event		�¼�����
		 * @param	string	 contents	�¼�����
		 * @return	INT32	 unknown	�̶�����0
		 */
		static INT32 addLog(INT32 level, INT64 robotID, string event, string contents);

	public:
		/**
		 * ��ӵ�����־
		 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
		 * @param	string	 event		�¼�����
		 * @param	string	 contents	�¼�����
		 * @return	INT32	 unknown	�̶�����0
		 */
		static INT32 Debug(INT64 robotID, string event, string contents);


		/**
		 * �����Ϣ��־
		 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
		 * @param	string	 event		�¼�����
		 * @param	string	 contents	�¼�����
		 * @return	INT32	 unknown	�̶�����0
		 */
		static INT32 Info(INT64 robotID, string event, string contents);


		friend class QYLOG_INFO;
		typedef QYLOG_INFO Infos; // ��Ϣ����־����


		/**
		 * ��Ӿ�����־
		 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
		 * @param	string	 event		�¼�����
		 * @param	string	 contents	�¼�����
		 * @return	INT32	 unknown	�̶�����0
		 */
		static INT32 Warning(INT64 robotID, string event, string contents);


		/**
		 * ��Ӵ�����־
		 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
		 * @param	string	 event		�¼�����
		 * @param	string	 contents	�¼�����
		 * @return	INT32	 unknown	�̶�����0
		 */
		static INT32 Error(INT64 robotID, string event, string contents);


		/**
		 * �������������־
		 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
		 * @param	string	 event		�¼�����
		 * @param	string	 contents	�¼�����
		 * @return	INT32	 unknown	�̶�����0
		 */
		static INT32 Fatal(INT64 robotID, string event, string contents);


};