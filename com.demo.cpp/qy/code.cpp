#include "../stdafx.h"
#include "code.h"

/**
 * �滻���ı�
 * @param	string	str			��Ҫ�������ı�
 * @param	string	find		��Ҫ�滻���ı�
 * @param	string	replace		�����滻���ı�
 * @param	size_t	count		�滻������0/�����滻ֱ���޷��ҵ����滻�ı�
 */
void replaceStr(
	string & str,			// ��Ҫ�������ı�
	string find,			// ��Ҫ�滻���ı�
	string replace = "",	// �����滻���ı�
	size_t count = 0		// �滻����
)
{
	if(find == "") return;
	size_t t = 0; // ����ͳ���滻����
	size_t pos = 0;
	while(str.length() > 0) {
		pos = str.find(find, pos);
		if(pos == string::npos) break;
		str = str.replace(pos, find.length(), replace);
		pos += replace.length();
		if(count || ++t == count) break;
	}
}

/**
 * ת��
 * @param	string	text			ԭ�ı�
 * @param	bool	escapeComma		ת�嶺�ţ�Ĭ�ϲ�ת��
 * @return	string	ת����
 */
string QYCODE::Escape(
	string text,		// ԭ�ı�
	bool escapeComma	// ת�嶺��
)
{
	string result = text;
	replaceStr(result, "&", "&amp;");
	replaceStr(result, "[", "&#91;");
	replaceStr(result, "]", "&#93;");
	if(escapeComma)
		replaceStr(result, ",", "&#44;");
	return result;
}

/**
 * ��ת��
 * @param	string	text		��Ҫ��ת����ı�
 * @return	string	��ת����
 */
string QYCODE::AntiEscape(
	string text		// ��Ҫ��ת����ı�
)
{
	string result = text;
	replaceStr(result, "&amp;", "&");
	replaceStr(result, "&#91;", "[");
	replaceStr(result, "&#93;", "]");
	replaceStr(result, "&#44;", ",");
	return result;
}

/**
 * ���ͱ���(face)
 * @param	INT32	faceID		����ID
 * @return	string	LQ��_����
 */
string QYCODE::Face(
	INT32 faceID	// ����ID
)
{
	return "[LQ:face,id=" + to_string(faceID) + "]";
}

/**
 * @ĳ��(at) - ��֧��Ⱥ
 * @param	INT64	uin			��Ҫ@�Ķ���-1Ϊȫ���Ա
 * @param	bool	needSpace	At��ӿո�Ĭ��ΪTrue����ʹAt���淶����
 * @return	string	LQ��_AT
 */
string QYCODE::At(
	INT64 uin,		// ��Ҫ@�Ķ���
	bool needSpace	// At��ӿո�
)
{
	return "[@" + (uin == -1 ? "all" : to_string(uin)) + "]" + (needSpace ? " " : "");
}

/**
 * ���ͱ���ͼƬ
 * @param	string	localPath	ͼƬ·��������дȫ·������ E:\robot\image\1.jpg
 * @return	string	LQ��_ͼƬ
 */
string QYCODE::LocalImage(
	string localPath	// ͼƬ·��
)
{
	return "[LQ:image,path=" + QYCODE::Escape(localPath, true) + "]";
}

/**
 * ��������ͼƬ
 * @param	string	url		����ͼƬ·��������д����ͼƬ����ַ�� �� http://dwz.cn/2ZJkzQ
 * @return	string	LQ��_ͼƬ
 */
string QYCODE::OnlineImage(
	string url	// ����ͼƬ·��
)
{
	return "[LQ:image,urls=" + QYCODE::Escape(url, true) + "]";
}

/**
 * ��������
 * @param	string	localPath	ͼƬ·��������дȫ·������ E:\robot\image\1.jpg
 * @return	string	LQ��_����
 */
string QYCODE::FlashPic(
	string localPath	// ͼƬ·��
)
{
	return "[LQ:flashpic,path=" + QYCODE::Escape(localPath, true) + "]";
}

/**
 * ���ͱ�������
 * @param	string	localPath	����·��������дȫ·������ E:\robot\record\1.amr
 * @return	string	LQ��_����
 */
string QYCODE::Record(
	string localPath	// ����·��
)
{
	return "[LQ:record,path=" + QYCODE::Escape(localPath, true) + "]";
}