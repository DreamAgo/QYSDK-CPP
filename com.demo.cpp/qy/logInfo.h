#pragma once
#include "log.h"

class QYLOG_INFO
{
	private:
		/* ��־���� */
		static const auto LOG_INFO_SUCCESS = 11;	//��Ϣ(�ɹ�)		������������ɫ(BlueViolet)	14822282  #8A2BE2  RGB(138,43,226)
		static const auto LOG_INFO_FAIL = 12;		//��Ϣ(ʧ��)		��ɫ(Brown)					2763429   #A52A2A  RGB(165,42,42)
		static const auto LOG_INFO_RECEIVE = 13;	//��Ϣ(����)		����(Blue)					16711680  #0000FF  RGB(0,0,255)
		static const auto LOG_INFO_SEND = 14;		//��Ϣ(����)		����(Green)					32768     #008000  RGB(0,128,0)

	public:

		/**
		 * ��ӳɹ���Ϣ��־
		 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
		 * @param	string	 event		�¼�����
		 * @param	string	 contents	�¼�����
		 * @return	INT32	 unknown	�̶�����0
		 */
		static INT32 Success(INT64 robotID, string event, string contents);


		/**
		 * ���ʧ����Ϣ��־
		 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
		 * @param	string	 event		�¼�����
		 * @param	string	 contents	�¼�����
		 * @return	INT32	 unknown	�̶�����0
		 */
		static INT32 Fail(INT64 robotID, string event, string contents);


		/**
		 * ��ӽ�����Ϣ��־
		 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
		 * @param	string	 event		�¼�����
		 * @param	string	 contents	�¼�����
		 * @return	INT32	 unknown	�̶�����0
		 */
		static INT32 Receive(INT64 robotID, string event, string contents);


		/**
		 * ��ӷ�����Ϣ��־
		 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
		 * @param	string	 event		�¼�����
		 * @param	string	 contents	�¼�����
		 * @return	INT32	 unknown	�̶�����0
		 */
		static INT32 Send(INT64 robotID, string event, string contents);
};