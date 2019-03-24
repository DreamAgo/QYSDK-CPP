#pragma once
// LQ��
class QYCODE
{
	public:
		/**
		 * ת��
		 * @param	string	text			ԭ�ı�
		 * @param	bool	escapeComma		ת�嶺�ţ�Ĭ�ϲ�ת��
		 * @return	string	ת����
		 */
		static string Escape(string text, bool escapeComma = false);

		/**
		 * ��ת��
		 * @param	string	text		��Ҫ��ת����ı�
		 * @return	string	��ת����
		 */
		static string AntiEscape(string text);

		/**
		 * ���ͱ���(face)
		 * @param	INT32	faceID		����ID
		 * @return	string	LQ��_����
		 */
		static string Face(INT32 faceID);

		/**
		 * @ĳ��(at) - ��֧��Ⱥ
		 * @param	INT64	uin			��Ҫ@�Ķ���-1Ϊȫ���Ա
		 * @param	bool	needSpace	At��ӿո�Ĭ��ΪTrue����ʹAt���淶����
		 * @return	string	LQ��_AT
		 */
		static string At(INT64 uin, bool needSpace = true);

		/**
		 * ���ͱ���ͼƬ
		 * @param	string	localPath	ͼƬ·��������дȫ·������ E:\robot\image\1.jpg 
		 * @return	string	LQ��_ͼƬ
		 */
		static string LocalImage(string localPath);

		/**
		 * ��������ͼƬ
		 * @param	string	url		����ͼƬ·��������д����ͼƬ����ַ�� �� http://dwz.cn/2ZJkzQ
		 * @return	string	LQ��_ͼƬ
		 */
		static string OnlineImage(string url);

		/**
		 * ��������
		 * @param	string	localPath	ͼƬ·��������дȫ·������ E:\robot\image\1.jpg
		 * @return	string	LQ��_����
		 */
		static string FlashPic(string localPath);

		/**
		 * ���ͱ�������
		 * @param	string	localPath	����·��������дȫ·������ E:\robot\record\1.amr
		 * @return	string	LQ��_����
		 */
		static string Record(string localPath);

};