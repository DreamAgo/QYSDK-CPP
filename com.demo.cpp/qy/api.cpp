#include "../stdafx.h"
#include "../utils/utils.h"
#include "../resource.h"
#include "api.h"
//#include "dll.h"
#include <qy\dll.h>

#ifndef QYAPI_TOLOG
#define QYAPI_TOLOG true // ����APIʱ���������־�������ж��Ƿ񴥷�API
#endif // !QYAPI_TOLOG


bool QYAPI::appEnable = false;
INT32 QYAPI::authCode = 0;
INT32 QYAPI::protocolType = 0;
string QYAPI::appDirectory = "";



/**
 * ȡ�����Json��Ϣ
 * @return	CSTRING		json�ı�
 */
CSTRING QYAPI::getJsonInfo()
{
	static char * info = nullptr;
	if(info) return info;
	//ofstream out("test.log");

	string source = GetResourceFile("JSON", IDR_JSON1);
	//out << source;

	string json = "";
	string lineText = "";

	uint32_t index = 0;
	uint32_t indexLine = 0;
	uint32_t indexNote = 0;

	while(true) {
		/* ��ȡÿ���ı�����Ϊ��β������\n\r��\n�����Է������� */
		indexLine = source.find("\n\r", index);
		if(indexLine == (uint32_t)string::npos)
			indexLine = source.find("\n", index);
		lineText = (indexLine == (uint32_t)string::npos)
			? source.substr(index) : source.substr(index, (indexLine - index));
		//out << lineText << " " << lineText.length() << endl;

		/* �򵥹��˵���ע�� */
		indexNote = 0;
		while(true) {
			indexNote = lineText.find("//", indexNote);
			if(indexNote == (uint32_t)string::npos) break;
			/* ȡ��ǰ���ı����������������ж��Ƿ�Ϊע�� */
			int qm = 0; //��������
			const char * head = lineText.substr(0, indexNote).c_str();
			for(int i = 0; head[i] != '\0'; i++) {
				if(head[i] == '"' && (i > 0 && head[i - 1] != '\\')) ++qm;
			}
			//out << "qm = " << qm << " ";
			if(qm % 2 == 0) {
				//��ע��
				lineText = lineText.substr(0, indexNote);
				break;
			}
			indexNote += 2;
		}
		/* �ж��Ƿ�Ϊ���ı���(���ո�) */
		int nSpace = 0;
		const char * s = lineText.c_str();
		for(int i = 0; s[i] == ' '; i++) nSpace++;
		/* �ǿ��ı��оͲ����� */
		if(nSpace != lineText.length()) {
			json += lineText; // +"\n\r";
			//out << lineText << " [E]" << endl;
		}
		if(indexLine == (uint32_t)string::npos) break;
		index = indexLine + strlen("\n");
	}


	//out << endl << endl;
	//��֪��Ϊʲô��ĩ���룬��֮�ٽ�ȡһ�ξ�over
	json = json.substr(0, json.find_last_of('}') + 1);
	//out << json;
	//MessageBoxA(NULL, json.c_str(), "��Ϣ��", 0);
	info = new char[json.length() + 1];
	strcpy_s(info, json.length() + 1, json.c_str());
	return info;
}

/**
 * ��AuthCode
 * @param	INT32	authCode	Ӧ�ñ�ʶ
 */
void QYAPI::setAuthCode(
	INT32	authCode	// Ӧ�ñ�ʶ
)
{
	QYAPI::authCode = authCode;
}

/**
 * ȡAuthCode
 * @return	INT32	authCode	Ӧ�ñ�ʶ
 */
INT32 QYAPI::getAuthCode()
{
	return QYAPI::authCode;
}

/**
 * ��ProtocolType
 * @param	INT32	ProtocolType	Э������ 1/��׿QQЭ�� 2/PCQQЭ��
 */
void QYAPI::setProtocolType(
	INT32	protocolType	// Э������ 1/��׿QQЭ�� 2/PCQQЭ��
)
{
	QYAPI::protocolType = protocolType;
}

/**
 * ȡProtocolType
 * @return	INT32	ProtocolType	Э������ 1/��׿QQЭ�� 2/PCQQЭ��
 */
INT32 QYAPI::getProtocolType()
{
	return QYAPI::protocolType;
}

/**
 * �ò������״̬
 * @param	bool	state	����״̬
 */
void QYAPI::setAppEnable(
	bool state
)
{
	QYAPI::appEnable = state;
}

/**
 * ȡ�������״̬
 * @return	bool	AppEnable	����״̬
 */
bool QYAPI::getAppEnable()
{
	return QYAPI::appEnable;
}

/**
 * ȡ�����
 * @return	string		�����
 */
string QYAPI::getFrameName()
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(QYAPI::getRandomLoginQQ(true), __func__, "");
	return QY_getFrameName(QYAPI::authCode);
}

/*
 * ��Ӧ����ͣ��
 * @param	INT64	waitTime		�ȴ�ʱ�䣬��λ������
 * @return	INT32	unknown
 */
INT32 QYAPI::setAppSelfDiscontinue(
	INT64 waitTime	// �ȴ�ʱ��
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(QYAPI::getRandomLoginQQ(true), __func__, "�ȴ�ʱ�䣺" + to_string(waitTime));
	return QY_setAppSelfDiscontinue(QYAPI::authCode, waitTime);
}

/*
 * ��Ӧ����ж��
 * @param	INT64	waitTime	�ȴ�ʱ�䣬��λ������
 * @return	INT32	unknown
 */
INT32 QYAPI::setAppSelfUninstall(
	INT64 waitTime		//�ȴ�ʱ��
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(QYAPI::getRandomLoginQQ(true), __func__, "�ȴ�ʱ�䣺" + to_string(waitTime));
	return QY_setAppSelfUninstall(QYAPI::authCode, waitTime);
}

/**
 * ȡӦ��Ŀ¼
 * ���ص�·��ĩβ����\��
 * @return	string		Ӧ��Ŀ¼
 */
string QYAPI::getAppDirectory()
{
	if(QYAPI::appDirectory == "") {
		if(QYAPI_TOLOG)
			QYAPI::addLog::Debug(QYAPI::getRandomLoginQQ(true), __func__, "");
		QYAPI::appDirectory = QY_getAppDirectory(QYAPI::authCode);
	}
	return QYAPI::appDirectory;
}

/**
 * ����_����¼QQ�б�
 * @param	string		strLoginQQList
 * @param	INT64List	bindLoginQQList
 * @return	bool		�����Ƿ�ɹ�
 */
bool decodeLoginQQList(
	string		strLoginQQList,		// �ӽӿڻ�ȡ�ı����ı�
	INT64List &	bindLoginQQList		// ��¼QQ����
)
{
	if(!strLoginQQList.length()) return false;
	string data = base64_decode(strLoginQQList);
	if(data.length() < 12) return false;
	UnPack u(data);
	INT32 count = u.GetInt();
	bindLoginQQList.resize(count);
	for(int i = 0; i < count; i++) 
		bindLoginQQList[i] = u.GetLong();
	return true;
}
/**
 * ȡ��¼QQ�б�
 * @param	INT64List	bindLoginQQList
 * @return	bool		ִ�н��
 */
bool QYAPI::getLoginQQList(
	INT64List & bindLoginQQList	// ��¼QQ����
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(QYAPI::getRandomLoginQQ(true), __func__, "");
	string strLoginQQList = QY_getLoginQQList(QYAPI::authCode);
	if(!strLoginQQList.length()) return false;
	return decodeLoginQQList(strLoginQQList, bindLoginQQList);
}

/**
 * ȡ��¼QQ�б�(������״̬)
 * @param	bool		getState			ȡ����״̬
 * @param	LoginQQList	bindLoginQQList		��¼QQ�б�ִ�гɹ��󽫴�������ڴ�
 * @return	bool		ִ�н��
 */
bool QYAPI::getLoginQQList(
	bool getState,							// ȡ����״̬
	QYTYPE::LoginQQList & bindLoginQQList	// ��¼QQ�б�
)
{
	INT64List intLoginQQList;
	if(!QYAPI::getLoginQQList(intLoginQQList)) return false;
	bindLoginQQList.resize(intLoginQQList.size());
	for(size_t i = 0; i < intLoginQQList.size(); ++i)
	{
		bindLoginQQList[i].id = intLoginQQList[i];
		if(getState)
			bindLoginQQList[i].state = QYAPI::getFrameAccountState(bindLoginQQList[i].id);
	}
	return true;
}

#include <random>
/**
 * ���ȡһ����¼QQ
 * @param	useCache	ʹ�û���
 * @return	INT64		��¼QQ
 */
INT64 QYAPI::getRandomLoginQQ(bool useCache)
{
	static INT64 loginQQ = 0;
	if(useCache && loginQQ) return loginQQ;
	INT64List loginQQList;
	if(!QYAPI::getLoginQQList(loginQQList)) return false;
	std::random_device seed;
	std::mt19937 mt(seed());
	std::uniform_int_distribution<int> dist(1, loginQQList.size());
	loginQQ = loginQQList[dist(mt) - 1];
	return loginQQ;
}

/*
 * ȡ����˺�״̬
 * @param	INT64	robotID		Ҫ��ѯ���˺�
 * @return	INT32	�˺�״̬		0/���� 1/����
 */
INT32 QYAPI::getFrameAccountState(
	INT64 robotID
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__, "������QQ��" + to_string(robotID));
	return QY_getFrameAccountState(QYAPI::authCode, robotID);
}

/**
 * ȡָ�������˵��ǳ�
 * @param	INT64		robotID		Ҫ��ѯ�ǳƵĻ�����QQ
 * @return	string		nick		�û����˵��ǳ�
 */
string QYAPI::getLoginQQName(
	INT64 robotID // Ҫ��ѯ�ǳƵ��ѵ�¼QQ
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__, "������QQ��" + to_string(robotID));
	return QY_getLoginNick(QYAPI::authCode, robotID);
}

/**
 * ȡָ�������˵�Cookies
 * @param	INT64		robotID		Ҫ��ѯ�Ļ�����QQ
 * @return	string		cookies		�û����˵�Cookies
 */
string QYAPI::getCookies(
	INT64 robotID	// Ҫ��ѯ�ǳƵĻ�����QQ
) 
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__, "������QQ��" + to_string(robotID));
	return QY_getCookies(QYAPI::authCode, robotID);
}

/**
 * ȡָ�������˵�csrfToken
 * @param	INT64	robotID		Ҫ��ѯ�Ļ�����QQ
 * @return	INT32	csrfToken	�û����˵�csrfToken
 */
INT32 QYAPI::getCsrfToken(
	INT64 robotID	// Ҫ��ѯ�Ļ�����QQ
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__, "������QQ��" + to_string(robotID));
	return QY_getCsrfToken(QYAPI::authCode, robotID);
}

/**
 * ȡָ��������cookie
 * @param	INT64		robotID		Ҫ��ѯ�Ļ�����QQ
 * @param	string		domain		Ҫ��ȡcookies��������http://qun.qq.com �� http://qun.qzone.qq.com
 * @return	string		cookies		��¼ָ����������ת�ɹ����cookies
 */
string QYAPI::getDomainCookies(
	INT64	robotID,	// Ҫ��ѯ�Ļ�����QQ
	string	domain		// Ҫ��ȡcookies��������http://qun.qq.com �� http://qun.qzone.qq.com
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__, 
			"������QQ��" + to_string(robotID) \
			+ "��Ҫ��ȡcookies��������" + domain
		);
	if(domain == "") domain = "http://qun.qq.com";
	return QY_getDomainCookie(QYAPI::authCode, robotID, domain.c_str());
}

/**
 * ����_�������б�
 * @param	string		strFriendList
 * @param	FriendList	bindFriendList
 * @return	bool		�����Ƿ�ɹ�
 */
bool decodeFriendList(
	string strFriendList,					// �ӽӿڻ�ȡ�ı�������
	QYTYPE::FriendList & bindFriendList		// �����б������
)
{
	if(!strFriendList.length()) return false;
	string data = base64_decode(strFriendList);
	if(data.length() < 10) return false;
	UnPack u(data);
	INT32 count = u.GetInt();
	bindFriendList.resize(count);
	for(int i = 0; i < count; i++) {
		bindFriendList[i].uin = u.GetLong();
		bindFriendList[i].nick = u.GetLenStr();
	}
	return true;
}
/**
 * ȡ�����б�
 * @param	INT64		robotID			Ҫ��ѯ�Ļ�����QQ
 * @param	FriendList	bindFriendList	�����б�����ã�ִ�гɹ��󽫴�������ڴ�
 * @return	bool		ִ�н��
 */
bool QYAPI::getFriendList(
	INT64 robotID,							// Ҫ��ѯ�Ļ�����QQ
	Type::FriendList & bindFriendList		// �����б������
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__, "������QQ��" + to_string(robotID));
	string strFriendList = QY_getFriendList(QYAPI::authCode, robotID);
	if(!strFriendList.length()) return false;
	return decodeFriendList(strFriendList, bindFriendList);
}

#include <ctime>
/**
 * ����_��QQ��Ҫ��Ϣ
 * @param	string			strSummaryInfo
 * @param	QQSummaryInfo	bindQSummaryInfo
 * @return	bool			�����Ƿ�ɹ�
 */
bool decodeQQSummaryInfo(
	string strSummaryInfo,						// �ӽӿڻ�ȡ�ı�������
	QYTYPE::QQSummaryInfo &	bindQSummaryInfo	// QQ��Ҫ��Ϣ������
)
{
	if(!strSummaryInfo.length()) return false;
	string data = base64_decode(strSummaryInfo);
	if(data.length() < 9) return false;
	UnPack u(data);
	bindQSummaryInfo.uin = u.GetLong();
	bindQSummaryInfo.sex = u.GetInt();
	bindQSummaryInfo.nick = u.GetLenStr();
	u.GetToken();
	bindQSummaryInfo.signature = u.GetLenStr();
	u.GetToken();
	bindQSummaryInfo.birthday = u.GetLenStr();
	if(bindQSummaryInfo.birthday == "0/0/0" || bindQSummaryInfo.birthday == "")
		bindQSummaryInfo.age = -1;
	else {
		// ��ȡʵ��ʱ��
		int AgeYear = static_cast<int>(strtoll(bindQSummaryInfo.birthday.c_str(), nullptr, 10));
		int AgeMonth = static_cast<int>(
			strtoll(
				bindQSummaryInfo.birthday.substr(
					bindQSummaryInfo.birthday.find_first_of('/') + 1, 
					bindQSummaryInfo.birthday.find_last_of('/') - bindQSummaryInfo.birthday.find_first_of('/')
				).c_str(),
				nullptr, 
				10
			));
		int AgeDay = static_cast<int>(strtoll(bindQSummaryInfo.birthday.substr(bindQSummaryInfo.birthday.find_last_of('/') + 1).c_str(), nullptr, 10));
		/*
		QYAPI::addLog::Debug(QYAPI::getRandomLoginQQ(), "TransformBirthday", 
			to_string(AgeYear) + "/" + to_string(AgeMonth) + "/" + to_string(AgeDay));
		*/
		// ��ȡ��ǰʱ��
		time_t timeStamp = time(NULL);
		struct tm NowTime;
		localtime_s(&NowTime, &timeStamp);
		NowTime.tm_year += 1900;
		++NowTime.tm_mon;
		NowTime.tm_wday;

		bindQSummaryInfo.age = NowTime.tm_year - AgeYear;
		//�ж��Ƿ���Ҫ��1(�Ƿ�����)
		if(AgeMonth > NowTime.tm_mon || (AgeMonth == NowTime.tm_mon && AgeDay > NowTime.tm_wday))
			--bindQSummaryInfo.age;
	}
	bindQSummaryInfo.level = u.GetInt();
	bindQSummaryInfo.qAge = u.GetInt();
	bindQSummaryInfo.likeCount = u.GetInt();
	bindQSummaryInfo.isLike = u.GetInt();
	return true;
}
/**
 * ȡQQ��Ҫ��Ϣ
 * @param	INT64			robotID				ʹ�õĻ�����QQ
 * @param	INT64			uin					��ѯQQ
 * @param	QQSummaryInfo	bindQSummaryInfo	QQ��Ҫ��Ϣ�����ã�ִ�гɹ��󽫴�������ڴ�
 * @return	bool			ִ�н��
 */
bool QYAPI::getQQSummaryInfo(
	INT64 robotID,								// ʹ�õĻ�����QQ
	INT64 uin,									// ��ѯQQ
	QYTYPE::QQSummaryInfo & bindQSummaryInfo	// QQ��Ҫ��Ϣ������
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__, 
			"������QQ��" + to_string(robotID) \
			+ "����ѯ��QQ��" + to_string(uin)
		);
	string strSummaryInfo = QY_getSummaryInfo(QYAPI::authCode, robotID, uin);
	if(!strSummaryInfo.length()) return false;
	return decodeQQSummaryInfo(strSummaryInfo, bindQSummaryInfo);
}

/**
 * ����_��Ⱥ�б�
 * @param	string		strGroupList
 * @param	GroupList	bindGroupList
 * @return	bool		�����Ƿ�ɹ�
 */
bool decodeGroupList(
	string strGroupList,				// �ӽӿڻ�ȡ�ı�������
	QYTYPE::GroupList &	bindGroupList	// Ⱥ�б����������
)
{
	if(!strGroupList.length()) return false;
	string data = base64_decode(strGroupList);
	if(data.length() < 10) return false;
	UnPack u(data);
	INT32 count = u.GetInt();
	bindGroupList.resize(count);
	for(int i = 0; i < count; i++) {
		bindGroupList[i].tempID = u.GetLong();
		bindGroupList[i].id = u.GetLong();
		bindGroupList[i].name = u.GetLenStr();
	}
	return true;
}
/**
 * ȡȺ�б�
 * @param	INT64		robotID			Ҫ��ѯ�Ļ�����QQ
 * @param	GroupList	bindGroupList	Ⱥ�б�����ã�ִ�гɹ��󽫴�������ڴ�
 * @return	bool		ִ�н��
 */
bool QYAPI::getGroupList(
	INT64 robotID,						// Ҫ��ѯ�Ļ�����QQ
	QYTYPE::GroupList & bindGroupList	// Ⱥ�б�����ã�ִ�гɹ��󽫴�������ڴ�
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID)
		);
	string strGroupList = QY_getGroupList(QYAPI::authCode, robotID);
	if(!strGroupList.length()) return false;
	return decodeGroupList(strGroupList, bindGroupList);
}

/**
 * ����_��Ⱥ����
 * @param	string		strGroupInfo
 * @param	GroupInfo	bindGroupInfo
 * @return	bool		�����Ƿ�ɹ�
 */
bool decodeGroupInfo(
	string strGroupInfo,				// �ӽӿڻ�ȡ�ı�������
	QYTYPE::GroupInfo &	bindGroupInfo	// Ⱥ��Ϣ������
)
{
	if(!strGroupInfo.length()) return false;
	string data = base64_decode(strGroupInfo);
	if(data.length() < 9) return false;
	UnPack u(data);
	bindGroupInfo.id = u.GetLong();
	bindGroupInfo.ownerUin = u.GetLong();
	bindGroupInfo.createTimeStamp = u.GetInt();
	bindGroupInfo.maxMemberNum = u.GetInt();
	bindGroupInfo.memberNum = u.GetInt();
	bindGroupInfo.name = u.GetLenStr();
	bindGroupInfo.nameBuffer = u.GetToken();
	bindGroupInfo.level = u.GetInt();
	bindGroupInfo.introduction = u.GetLenStr();
	bindGroupInfo.introductionBuffer = u.GetToken();
	return true;
}
/**
 * ȡȺ����
 * @param	INT64		robotID			ʹ�õĻ�����QQ
 * @param	INT64		dwGroup			Ҫ��ѯ��Ⱥ��
 * @param	GroupInfo	bindGroupInfo	Ⱥ���ϵ����ã�ִ�гɹ��󽫴�������ڴ�
 * @return	bool		ִ�н��
 */
bool QYAPI::getGroupInfo(
	INT64 robotID,						// Ҫ��ѯ�Ļ�����QQ
	INT64 dwGroup,						// Ҫ��ѯ��Ⱥ��
	QYTYPE::GroupInfo & bindGroupInfo	// Ⱥ���ϵ�����
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "����ѯ��Ⱥ��" + to_string(dwGroup)
		);
	string strGroupInfo = QY_getGroupInfo(QYAPI::authCode, robotID, dwGroup);
	if(!strGroupInfo.length()) return false;
	return decodeGroupInfo(strGroupInfo, bindGroupInfo);
}

/**
 * ����_��Ⱥ����Ա�б�
 * @param	string			strGroupAdminList
 * @param	GroupAdminList	bindGroupAdminList
 * @return	bool			�����Ƿ�ɹ�
 */
bool decodeGroupAdminList(
	string strGroupAdminList,					// �ӽӿڻ�ȡ�ı�������
	QYTYPE::GroupAdminList & bindGroupAdminList	// Ⱥ����Ա���������
)
{
	if(!strGroupAdminList.length()) return false;
	string data = base64_decode(strGroupAdminList);
	if(data.length() < 12) return false;
	UnPack u(data);
	INT32 count = u.GetInt();
	bindGroupAdminList.resize(count);
	for(int i = 0; i < count; i++) {
		bindGroupAdminList[i].uin = u.GetLong();
		bindGroupAdminList[i].permission = u.GetInt();
	}
	return true;
}
/**
 * ȡȺ����Ա�б�
 * ����Ⱥ��
 * @param	INT64			robotID					ʹ�õĻ�����QQ
 * @param	INT64			dwGroup					Ҫ��ѯ��Ⱥ��
 * @param	GroupAdminList	bindGroupAdminList		Ⱥ������������ã�ִ�гɹ��󽫴�������ڴ�
 * @return	bool			ִ�н��
 */
bool QYAPI::getGroupAdminList(
	INT64 robotID,									// ʹ�õĻ�����QQ
	INT64 dwGroup,									// Ҫ��ѯ��Ⱥ��
	QYTYPE::GroupAdminList & bindGroupAdminList		// Ⱥ�������������
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "����ѯ��Ⱥ��" + to_string(dwGroup)
		);
	string strAdminList = QY_getGroupAdminList(QYAPI::authCode, robotID, dwGroup);
	if(strAdminList == "") return false;
	return decodeGroupAdminList(strAdminList, bindGroupAdminList);
}

/**
 * ����_��Ⱥ��Ա��Ϣ
 * @param	string			bytesGroupMember
 * @param	GroupMember		gMember
 * @return	bool			�����Ƿ�ɹ�
 */
bool decodeGroupMember(
	BYTES bytesGroupMember,			// �ӽӿڻ�ȡ�ı�������
	QYTYPE::GroupMember & gMember	// Ⱥ��Ա����
)
{
	if(bytesGroupMember.size() < 40) return false;
	UnPack u(bytesGroupMember);
	gMember.uin = u.GetLong();
	gMember.nick = u.GetLenStr();
	gMember.card = u.GetLenStr();
	gMember.sex = u.GetInt();
	gMember.age = u.GetInt();
	gMember.area = u.GetLenStr();
	gMember.joinTimeStamp = u.GetInt();
	gMember.lastSpeakTimeStamp = u.GetInt();
	gMember.gLevelName = u.GetLenStr();
	gMember.permission = u.GetInt();
	gMember.isBadMember = u.GetInt();
	gMember.sTitle = u.GetLenStr();
	gMember.sTitleValidPeriod = u.GetInt();
	gMember.allowChangeCard = u.GetInt();
	return true;
}
/**
 * ����_��Ⱥ��Ա�б�
 * @param	string			strGroupMemberList
 * @param	GroupMemberList	gMemberList
 * @return	bool			�����Ƿ�ɹ�
 */
bool decodeGroupMemberList(
	string strGroupMemberList,				// �ӽӿڻ�ȡ�ı�������
	QYTYPE::GroupMemberList & gMemberList	// Ⱥ��Ա����
)
{
	if(!strGroupMemberList.length()) return false;
	string data = base64_decode(strGroupMemberList);
	if(data.length() < 10) return false;
	UnPack u(data);
	INT32 count = u.GetInt();
	gMemberList.resize(count);
	for(int i = 0; i < count; i++) {
		if(u.Len() <= 0) return false;
		if(!decodeGroupMember(u.GetToken(), gMemberList[i])) return false;
	}
	return true;
}
/**
 * ȡȺ��Ա�б�
 * PCЭ���ȡֻ��QQ�͹���Ȩ��
 * @param	INT64			robotID					ʹ�õĻ�����QQ
 * @param	INT64			dwGroup					Ҫ��ѯ��Ⱥ��
 * @param	GroupMemberList	bindGroupMemberList		Ⱥ��Ա��������ã�ִ�гɹ��󽫴�������ڴ�
 * @return	bool			ִ�н��
 */
bool QYAPI::getGroupMemberList(
	INT64 robotID,									// ʹ�õĻ�����QQ
	INT64 dwGroup,									// Ҫ��ѯ��Ⱥ��
	QYTYPE::GroupMemberList & bindGroupMemberList	// Ⱥ��Ա���������
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "����ѯ��Ⱥ��" + to_string(dwGroup)
		);
	string strGroupMemberList = QY_getGroupMemberList(QYAPI::authCode, robotID, dwGroup);
	if(strGroupMemberList == "") return false;
	return decodeGroupMemberList(strGroupMemberList, bindGroupMemberList);
}

/**
 * ����_��Ⱥ��Ƭ
 * @param	string	strGroupMemberCard
 * @param	string	card
 * @param	bool	useNick
 * @return	bool	�����Ƿ�ɹ�
 */
bool decodeGroupAdminList(
	string strGroupMemberCard,		// �ӽӿڻ�ȡ�ı�������
	string & card,					// Ⱥ��Ƭ
	bool useNick					// ʹ���ǳ�
)
{
	if(!strGroupMemberCard.length()) return false;
	string data = base64_decode(strGroupMemberCard);
	if(data.length() < 8) return false;
	UnPack u(data);
	card = u.GetLenStr();
	if(card == "" && useNick)
		card = u.GetLenStr();
	return true;
}
/**
 * ȡȺ��Ա��Ƭ
 * @param	INT64		robotID			ʹ�õĻ�����QQ
 * @param	INT64		dwGroup			����Ⱥ
 * @param	INT64		QQUin			Ҫ��ѯ��QQ��
 * @param	bool		useNick			ʹ���ǳƣ�Ĭ�ϲ�ʹ�á�ʹ��ʱ������ƬΪ���򷵻��ǳƣ���ʹ���򷵻���Ƭ
 * @param	bool		useCache		ʹ�û��棬Ĭ��ʹ��
 * @return	string		��Ⱥ��Ա����Ƭ
 */
string QYAPI::getGroupMemberCard(
	INT64	robotID,	// ʹ�õĻ�����QQ
	INT64	dwGroup,	// ����Ⱥ
	INT64	uin,		// Ҫ��ѯ��QQ��
	bool	useNick,	// ʹ���ǳ�
	bool	useCache	// ʹ�û���
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "����ѯ��QQ��" + to_string(uin) \
			+ "������Ⱥ��" + to_string(dwGroup) \
			+ "��" + (useNick ? "" : "��") + "ʹ���ǳ�" \
			+ "��" + (useCache ? "" : "��") + "ʹ�û���"
		);
	string strGroupMemberCard = QY_getGroupMemberCard(QYAPI::authCode, robotID, dwGroup, uin, !useCache);
	if(strGroupMemberCard == "") return false;
	string card;
	decodeGroupAdminList(strGroupMemberCard, card, useNick);
	return card;
}

/**
 * ����_���������б�
 * @param	string			strDiscussList
 * @param	DiscussList		DiscussList
 * @return	bool			�����Ƿ�ɹ�
 */
bool decodeDiscussList(
	string	strDiscussList,					// �ӽӿڻ�ȡ�ı�������
	QYTYPE::DiscussList & bindDiscussList	// �������б�����
)
{
	if(!strDiscussList.length()) return false;
	string data = base64_decode(strDiscussList);
	if(data.length() < 10) return false;
	UnPack u(data);
	INT32 count = u.GetInt();
	bindDiscussList.resize(count);
	for(int i = 0; i < count; i++) {
		bindDiscussList[i].id = u.GetLong();
		bindDiscussList[i].nameBuffer = u.GetToken();
		bindDiscussList[i].name = u.GetLenStr();
		u.GetInt();  // �������
		bindDiscussList[i].createTimeStamp = u.GetInt();
		bindDiscussList[i].createUin = u.GetLong();
		bindDiscussList[i].infoSeq = u.GetInt();
		bindDiscussList[i].lastInfoTimeStamp = u.GetInt();
		bindDiscussList[i].msgSeq = u.GetInt();
		bindDiscussList[i].lastMsgTimeStamp = u.GetInt();
		bindDiscussList[i].memberNum = u.GetInt();
		bindDiscussList[i].flag = u.GetInt();
		bindDiscussList[i].inheritOwnerUin = u.GetLong();
		bindDiscussList[i].groupID = u.GetLong();
		bindDiscussList[i].groupTempID = u.GetLong();
		bindDiscussList[i].confMeetingOrigin = u.GetInt();
		bindDiscussList[i].qidianConfType = u.GetInt();
		bindDiscussList[i].confMeetingOption = u.GetInt();
	}
	return true;
}
/**
 * ȡ�������б�
 * @param	INT64			robotID				Ҫ��ѯ�Ļ�����QQ
 * @param	DiscussList		bindDiscussList		�������б�ִ�гɹ��󽫴�������ڴ�
 * @return	bool			ִ�н��
 */
bool QYAPI::getDiscussList(
	INT64 robotID,							// Ҫ��ѯ�Ļ�����QQ
	QYTYPE::DiscussList & bindDiscussList	// �������б�
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) 
		);
	string strDiscussList = QY_getDiscussList(QYAPI::authCode, robotID);
	if(strDiscussList == "") return false;
	return decodeDiscussList(strDiscussList, bindDiscussList);
}

/**
 * ����_UTF8תAnsi
 * @param	BYTES		contents		UTF-8�����ı�
 * @return	CSTRING		GB2312�����ı�
 */
CSTRING QYAPI::convertUtf8ToAnsi(
	BYTES contents	// UTF-8�����ı�
)
{
	BYTE * bin = new BYTE[contents.size()];
	for(size_t i = 0; i < contents.size(); i++)
		bin[i] = contents[i];
	string str = base64_encode(bin, contents.size());
	delete[] bin;
	return QY_setEncodeUtf8ToAnsi(QYAPI::authCode, str.c_str());
}
/**
 * ����_UTF8תAnsi
 * @param	string		contents		UTF-8�����ı�
 * @return	CSTRING		GB2312�����ı�
 */
CSTRING QYAPI::convertUtf8ToAnsi(
	string contents	// UTF-8�����ı�
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(QYAPI::getRandomLoginQQ(true), __func__,
			"�������utf-8�ı���" + contents
		);
	BYTES bin(contents.cbegin(), contents.cend());
	return QYAPI::convertUtf8ToAnsi(bin);
}

/**
 * ����_GB2312תUTF8
 * @param	string		contents	GB2312�����ı�
 * @return	BYTES		UTF-8�����ı�
 */
BYTES QYAPI::convertAnsiToUtf8(
	string contents	// GB2312�����ı�
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(QYAPI::getRandomLoginQQ(true), __func__,
			"�������gb2312�ı���" + contents
		);
	string utf8 = QY_setEncodeAnsiToUtf8(QYAPI::authCode, contents.c_str());
	if(utf8 == "") return BYTES();
	utf8 = base64_decode(utf8);
	BYTES bin(utf8.cbegin(), utf8.cend());
	return bin;
}

/**
 * ������������Ϣ
 * @param	string		strAnonymousInfo	��������
 * @param	Anonymous	bindAnonymousInfo	������Ϣ������
 * @return	bool		�������
 */
bool QYAPI::decodeAnonymousInfo(
	string strAnonymousInfo,
	QYTYPE::Anonymous & bindAnonymousInfo
)
{
	if(strAnonymousInfo == "") return false;
	string data = base64_decode(strAnonymousInfo);
	if(data.length() < 9) return false;
	UnPack u(data);
	bindAnonymousInfo.token = u.GetToken();
	bindAnonymousInfo.card = u.GetLenStr();
	bindAnonymousInfo.headMark = u.GetLong();
	bindAnonymousInfo.expireTimeStamp = u.GetLong();
	return true;
}

/**
 * ������Ⱥ������Ϣ
 * @param	string					strGroupAdditionalInfo		Ⱥ������Ϣ����
 * @param	GroupAdditionalInfo		bindGroupAdditionalInfo		Ⱥ������Ϣ�����ã������ɹ��󽫴�������ڴ�
 * @return	bool					�������
 */
bool QYAPI::decodeGroupAdditionalInfo(
	string strGroupAdditionalInfo,							// Ⱥ������Ϣ����
	QYTYPE::GroupAdditionalInfo & bindGroupAdditionalInfo	// Ⱥ������Ϣ������
)
{
	if(strGroupAdditionalInfo == "") return false;
	string data = base64_decode(strGroupAdditionalInfo);
	if(data.length() < 9) return false;
	UnPack u(data);
	bindGroupAdditionalInfo.nick = u.GetLenStr();
	bindGroupAdditionalInfo.gCard = u.GetLenStr();
	bindGroupAdditionalInfo.level = u.GetInt();
	bindGroupAdditionalInfo.flags = u.GetInt();
	bindGroupAdditionalInfo.gLevel = u.GetInt();
	bindGroupAdditionalInfo.sTitle = u.GetLenStr();
	bindGroupAdditionalInfo.MTID = u.GetInt();
	return true;
}

/**
 * ������������Ϣ
 * @param	string		strFontInfo		��������
 * @param	Font		bindFontInfo	������Ϣ�����ã������ɹ��󽫴�������ڴ�
 * @return	bool		�������
 */
bool QYAPI::decodeFontInfo(
	string strFontInfo,				// ��������
	QYTYPE::Font & bindFontInfo		// ������Ϣ������
)
{
	if(strFontInfo == "") return false;
	string data = base64_decode(strFontInfo);
	if(data.length() < 9) return false;
	UnPack u(data);
	bindFontInfo.name = u.GetLenStr();
	bindFontInfo.size = u.GetInt();
	bindFontInfo.color = u.GetInt();
	bindFontInfo.effect = u.GetInt();
	bindFontInfo.colorTextID = u.GetInt();
	return true;
}

/**
 * ������Ⱥ�ļ���Ϣ
 * @param	string		strFileInfo		�ļ�����
 * @param	File		bindFileInfo	�ļ���Ϣ�����ã������ɹ��󽫴�������ڴ�
 * @return	bool		�������
 */
bool QYAPI::decodeFileInfo(
	string strFileInfo,				// �ļ�����
	QYTYPE::File & bindFileInfo		// �ļ���Ϣ������
)
{
	if(strFileInfo == "") return false;
	string data = base64_decode(strFileInfo);
	if(data.length() < 12) return false;
	UnPack u(data);
	bindFileInfo.name = u.GetLenStr();
	bindFileInfo.id = u.GetLenStr();
	bindFileInfo.size = u.GetLenStr();
	bindFileInfo.busID = u.GetLong();
	bindFileInfo.byteSize = u.GetLong();
	return true;
}

/**
 * ������������ʾ
 * @param	string		errMsg		������Ϣ
 * @return	INT32		unknown
 */
INT32 QYAPI::setFatal(
	string errMsg	// ������Ϣ
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(QYAPI::getRandomLoginQQ(true), __func__,
			"������Ϣ��" + errMsg
		);
	return QY_setFatal(QYAPI::authCode, errMsg.c_str());
}

/**
 * ������Ƭ��
 * @param	INT64	robotID		ʹ�õĻ�����QQ
 * @param	INT64	uin			Ŀ�����
 * @param	INT32	count		���޴���
 * @return	INT32	�̶�����0
 */
INT32 QYAPI::sendLikeFavorite(
	INT64 robotID,	// ������QQ
	INT64 uin,		// Ŀ��QQ
	INT32 count		// ����
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "������" + to_string(uin) \
			+ "��������" + to_string(count)
		);
	for(INT32 i = 0; i < count; i++) {
		QY_sendLikeFavorite(QYAPI::authCode, robotID, uin);
	}
	return 0;
}

/*
 * ���ͺ�����Ϣ
 * @param	INT64	 robotID	ʹ�õĻ�����QQ
 * @param	INT64	 uin		Ŀ��QQ
 * @param	CSTRING	 msg		��Ϣ����
 * @return	INT32	 unknown	(�Ʋ�)״̬��
 */
INT32 QYAPI::sendFriendMsg(
	INT64 robotID,	// ʹ�û�����QQ
	INT64 uin,		// Ŀ��QQ
	string msg		// ��Ϣ����
)
{
	if(msg == "") return -1;
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "�����͵����ѣ�" + to_string(uin) \
			+ "����Ϣ���ݣ�" + msg
		);
	return QY_sendFriendMsg(QYAPI::authCode, robotID, uin, msg.c_str());
}

/*
 * ����Ⱥ��Ϣ
 * @param	INT64	 robotID	ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup	Ŀ��Ⱥ
 * @param	CSTRING	 msg		��Ϣ����
 * @return	INT32	 unknown	(�Ʋ�)״̬��
 */
INT32 QYAPI::sendGroupMsg(
	INT64 robotID,	// ʹ�õĻ�����QQ
	INT64 dwGroup,	// Ŀ��Ⱥ
	string msg		// ��Ϣ����
)
{
	if(msg == "") return -1;
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "�����͵�Ⱥ��" + to_string(dwGroup) \
			+ "����Ϣ���ݣ�" + msg
		);
	return QY_sendGroupMsg(QYAPI::authCode, robotID, dwGroup, msg.c_str());
}

/*
 * ����Ⱥ��ʱ��Ϣ
 * @param	INT64	 robotID	ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup	����Ⱥ
 * @param	INT64	 uin		Ŀ��QQ
 * @param	string	 msg		��Ϣ����
 * @return	INT32	 unknown	(�Ʋ�)״̬��
 */
INT32 QYAPI::sendGroupTmpMsg(
	INT64 robotID,	// ʹ�õĻ�����QQ
	INT64 dwGroup,	// ����Ⱥ
	INT64 uin,		// Ŀ��QQ
	string msg		// ��Ϣ����
)
{
	if(msg == "") return -1;
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "�����͵���ʱ����" + to_string(uin) \
			+ "������Ⱥ��" + to_string(dwGroup) \
			+ "����Ϣ���ݣ�" + msg
		);
	return QY_sendGroupTmpMsg(QYAPI::authCode, robotID, dwGroup, uin, msg.c_str());
}

/*
 * ������������Ϣ
 * @param	INT64	 robotID	ʹ�õĻ�����QQ
 * @param	INT64	 dwDiscuss	Ŀ��������
 * @param	string	 msg		��Ϣ����
 * @return	INT32	 unknown	(�Ʋ�)״̬��
 */
INT32 QYAPI::sendDiscussMsg(
	INT64 robotID,		// ʹ�õĻ�����QQ
	INT64 dwDiscuss,	// Ŀ��������
	string msg			// ��Ϣ����
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "�����͵������飺" + to_string(dwDiscuss) \
			+ "����Ϣ���ݣ�" + msg
		);
	return QY_sendDiscussMsg(QYAPI::authCode, robotID, dwDiscuss, msg.c_str());
}

/*
 * ������������ʱ��Ϣ
 * @param	INT64	 robotID	ʹ�õĻ�����QQ
 * @param	INT64	 dwDiscuss	����������
 * @param	INT64	 uin		Ŀ��QQ
 * @param	string	 msg		��Ϣ����
 * @return	INT32	 unknown	(�Ʋ�)״̬��
 */
INT32 QYAPI::sendDiscussTmpMsg(
	INT64 robotID,		// ʹ�õĻ�����QQ
	INT64 dwDiscuss,	// ����������
	INT64 uin,			// Ŀ��QQ
	string msg			// ��Ϣ����
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "�����͵���ʱ����" + to_string(uin) \
			+ "�����������飺" + to_string(dwDiscuss) \
			+ "����Ϣ���ݣ�" + msg
		);
	return QY_sendDiscussTmpMsg(QYAPI::authCode, robotID, dwDiscuss, uin, msg.c_str());
}

/*
 * ���������ļ�
 * �����ϴ�Ⱥ�ļ���ָ��Ŀ¼����ʹ�á�setGroupFileUpload��
 * @param	INT64		robotID			ʹ�õĻ�����QQ
 * @param	INT32		dwMsgType		��Ϣ���ͣ�1/���� 2/Ⱥ 3/������ 4/Ⱥ��ʱ 5/��������ʱ
 * @param	INT64		dwGroup			����Ⱥ��� Ⱥ�� / ������ID
 * @param	INT64		dwUin			QQ�ţ����͸�����Ϣʱʹ��(������ʱ��Ϣ)
 * @param	CSTRING		strLocalPath	�ļ�·��
 * @return	INT32		unknown			(�Ʋ�)״̬��
 */
INT32 QYAPI::sendOfflineFile(
	INT64 robotID,			// ʹ�õĻ�����QQ
	INT32 dwMsgType,		// ��Ϣ����
	INT64 dwGroup,			// Ⱥ���
	INT64 dwUin,			// QQ��
	string strLocalPath		// �ļ�·��
)
{
	switch(dwMsgType)
	{
		case 1: // ������Ϣ
		{
			if(QYAPI_TOLOG)
				QYAPI::addLog::Debug(robotID, __func__,
					"������QQ��" + to_string(robotID) \
					+ "�����͵����ѣ�" + to_string(dwUin) \
					+ "���ļ�·����" + strLocalPath
				);
			return QY_sendOfflineFile(QYAPI::authCode, robotID, dwUin, dwUin, 166, 0, strLocalPath.c_str());
		}

		case 2: // Ⱥ��Ϣ
		{
			return QYAPI::setGroupFileUpload(robotID, dwGroup, "/", strLocalPath);
		}

		case 3: // ������
		{
			if(QYAPI_TOLOG)
				QYAPI::addLog::Debug(robotID, __func__,
					"������QQ��" + to_string(robotID) \
					+ "�����͵������飺" + to_string(dwGroup) \
					+ "���ļ�·����" + strLocalPath
				);
			return QY_sendOfflineFile(QYAPI::authCode, robotID, dwGroup, 0, 83, 0, strLocalPath.c_str());
		}

		case 4: // Ⱥ��ʱ
		{
			if(QYAPI_TOLOG)
				QYAPI::addLog::Debug(robotID, __func__,
					"������QQ��" + to_string(robotID) \
					+ "�����͵���ʱ����" + to_string(dwUin) \
					+ "������Ⱥ��" + to_string(dwGroup) \
					+ "���ļ�·����" + strLocalPath
				);
			return QY_sendOfflineFile(QYAPI::authCode, robotID, dwGroup, dwUin, 141, 0, strLocalPath.c_str());
		}

		case 5: // ��������ʱ
		{
			if(QYAPI_TOLOG)
				QYAPI::addLog::Debug(robotID, __func__,
					"������QQ��" + to_string(robotID) \
					+ "�����͵���ʱ����" + to_string(dwUin) \
					+ "�����������飺" + to_string(dwGroup) \
					+ "���ļ�·����" + strLocalPath
				);
			return QY_sendOfflineFile(QYAPI::authCode, robotID, dwGroup, dwUin, 141, 1, strLocalPath.c_str());
		}
	}
	return -1;
}

/**
 * ����Ϣ����
 * @param	INT64		robotID		ʹ�õĻ�����QQ
 * @param	string		msgInfo		��Ϣ��Ϣ
 * @return	INT32		�������
 */
INT32 QYAPI::setMessageSvcMsgWithDraw(
	INT64 robotID,		// ʹ�õĻ�����
	string msgInfo		// ��Ϣ��Ϣ
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "��msgInfo��" + msgInfo
		);
	return QY_setMessageSvcMsgWithDraw(QYAPI::authCode, robotID, msgInfo.c_str());
}

/*
 * ɾ������
 * @param	INT64	 robotID	ʹ�õĻ�����QQ
 * @param	INT64	 QQUin		Ŀ��QQ
 * @return	INT32	 unknown	(�Ʋ�)״̬��
 */
INT32 QYAPI::setFriendDelete(
	INT64 robotID,	// ʹ�õĻ�����QQ
	INT64 uin		// Ŀ��QQ
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "��Ŀ��QQ��" + to_string(uin)
		);
	return QY_setDelFriend(QYAPI::authCode, robotID, uin);
}

/*
 * ��Ⱥ�ļ��ϴ�
 * @param	INT64	 robotID			ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup			Ŀ��Ⱥ
 * @param	string	 strParentFolder	Ⱥ�ļ���·������ ��/��Ϊ��Ŀ¼
 * @param	string	 strLocalPath		�����ļ�·��
 * @return	INT32	 unknown			(�Ʋ�)״̬��
 */
INT32 QYAPI::setGroupFileUpload(
	INT64 robotID,				// ʹ�õĻ�����QQ
	INT64 dwGroup,				// Ŀ��Ⱥ
	string strParentFolder,		// Ⱥ�ļ���·��
	string strLocalPath			// �����ļ�·��
)
{
	if(strLocalPath == "") return -1;
	if(strParentFolder == "") strParentFolder = "/";
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "��Ŀ��Ⱥ��" + to_string(dwGroup) \
			+ "��Ⱥ�ļ���Ŀ¼��" + strParentFolder \
			+ "�������ļ�·����" + strLocalPath
		);
	return QY_setGroupFileUpload(QYAPI::authCode, robotID, dwGroup, strParentFolder.c_str(), strLocalPath.c_str());
}

/*
 * ��Ⱥ�ļ�ɾ��
 * @param	INT64	 robotID			ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup			Ŀ��Ⱥ
 * @param	INT64	 fileBusID			�ļ�����ID
 * @param	string	 strParentFolder	���ļ���ID Ŀ�� Ⱥ�ļ���·������ ��/��Ϊ��Ŀ¼
 * @param	string	 fileID				�ļ�ID�����ɿ�
 * @return	INT32	 unknown			(�Ʋ�)״̬��
 */
INT32 QYAPI::setGroupFileDelete(
	INT64 robotID,				// ʹ�õĻ�����QQ
	INT64 dwGroup,				// Ŀ��Ⱥ
	INT64 fileBusID,			// �ļ�����ID
	string strParentFolder,		// ���ļ���ID
	string fileID				// �ļ�ID
)
{
	if(fileID == "") return -1;
	if(strParentFolder == "") strParentFolder = "/";
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "��Ŀ��Ⱥ��" + to_string(dwGroup) \
			+ "���ļ�����ID��" + to_string(fileBusID) \
			+ "�����ļ���ID��" + strParentFolder \
			+ "���ļ�ID��" + fileID
		);
	return QY_setDelGroupFile(QYAPI::authCode, robotID, dwGroup, fileBusID, strParentFolder.c_str(), fileID.c_str());
}

/*
 * ��ȺԱ�Ƴ�
 * ��Ҫ����ԱȨ��
 * @param	INT64	 robotID			ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup			����Ⱥ
 * @param	INT64	 uin				Ŀ��QQ
 * @param	bool	 rejectAddRequest	���ٽ��մ��˼�Ⱥ���룬������
 * @return	INT32	 unknown			(�Ʋ�)״̬��
 */
INT32 QYAPI::setGroupMembersKick(
	INT64 robotID,				// ʹ�õĻ�����QQ
	INT64 dwGroup,				// ����Ⱥ
	INT64 uin,					// Ŀ��QQ
	bool rejectAddRequest		// ���ٽ��մ��˼�Ⱥ����
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "������Ⱥ��" + to_string(dwGroup) \
			+ "��Ŀ��QQ��" + to_string(uin) \
			+ "��" + (rejectAddRequest ? "���ٽ��մ��˼�Ⱥ����" : "�����´μ�Ⱥ")
		);
	return QY_setGroupMembersKick(QYAPI::authCode, robotID, dwGroup, uin, int(rejectAddRequest));
}

/*
 * ��ȫȺ����
 * ��Ҫ����ԱȨ��
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		Ŀ��Ⱥ
 * @param	bool	 newStatus		Ҫ���õ���״̬��true/�������� false/�رս���
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
INT32 QYAPI::setGroupWholeBanSpeak(
	INT64 robotID,		// ʹ�õĻ�����QQ
	INT64 dwGroup,		// ����Ⱥ
	bool newStatus		// Ҫ���õ���״̬
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "��Ⱥ��" + to_string(dwGroup) \
			+ "��" + (newStatus ? "����" : "�ر�") + "ȫȺ����"
		);
	return QY_setGroupWholeBanSpeak(QYAPI::authCode, robotID, dwGroup, int(newStatus));
}

/*
 * ��ȺԱ����
 * ��Ҫ����ԱȨ��
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		����Ⱥ
 * @param	INT64	 uin			Ŀ��QQ
 * @param	INT64	 timeStamp		����ʱ�䣬��λΪ�롣���Ҫ�����������д0
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
INT32 QYAPI::setGroupMemberBanSpeak(
	INT64 robotID,		// ʹ�õĻ�����QQ
	INT64 dwGroup,		// ����Ⱥ
	INT64 uin,			// Ŀ��QQ
	INT64 timeStamp		// ����ʱ��
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "������Ⱥ��" + to_string(dwGroup) \
			+ "��Ŀ��QQ��" + to_string(uin) \
			+ "��" + (timeStamp ? ("����" + to_string(timeStamp) + "��") : "�������")
		);
	return QY_setGroupMembersBanSpeak(QYAPI::authCode, robotID, dwGroup, uin, timeStamp);
}

/*
 * ��Ⱥ������Ա����
 * ���Ժ��޷����
 * ��Ҫ����ԱȨ��
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		����Ⱥ
 * @param	INT64	 headMark		�����û���ͷ���ʶ
 * @param	BYTES	 token			�����û�Token
 * @param	string	 card			�����û���Ƭ
 * @param	INT64	 timeStamp		����ʱ�䣬��λΪ��
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
INT32 QYAPI::setGroupAnonymousBanSpeak(
	INT64 robotID,
	INT64 dwGroup,
	INT64 headMark,
	BYTES token,
	string card,
	INT64 timeStamp
)
{
	BYTE * bin = new BYTE[token.size()];
	for(size_t i = 0; i < token.size(); i++)
		bin[i] = token[i];
	string strToken = base64_encode(bin, token.size());
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "������Ⱥ��" + to_string(dwGroup) \
			+ "��ͷ���ʶ��" + to_string(headMark) \
			+ "��Token��" + strToken \
			+ "����Ƭ��" + card \
			+ "�����ԣ�" + to_string(timeStamp) + "��"
		);
	return QY_setGroupAnonymousBanSpeak(QYAPI::authCode, robotID, dwGroup, (INT32)headMark, strToken.c_str(), card.c_str(), timeStamp);
}

/*
 * ����Ⱥ�������쿪��
 * ��Ҫ����ԱȨ��
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		Ŀ��Ⱥ
 * @param	bool	 newStatus		Ҫ���õ���״̬
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
INT32 QYAPI::setGroupAnonymousBan(
	INT64 robotID,		// ʹ�õĻ�����QQ
	INT64 dwGroup,		// Ŀ��Ⱥ
	bool newStatus		// Ҫ���õ���״̬
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "��Ⱥ��" + to_string(dwGroup) \
			+ "��" + (newStatus ? "����" : "��ֹ") + "��������"
		);
	return QY_setGroupAnonymousBan(QYAPI::authCode, robotID, dwGroup, int(newStatus));
}

/*
 * ��Ⱥ��ʱ�Ự����
 * ��ҪȺ��Ȩ��
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		Ŀ��Ⱥ
 * @param	bool	 newStatus		Ҫ���õ���״̬
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
INT32 QYAPI::setGroupPrivateSession(
	INT64 robotID,		// ʹ�õĻ�����QQ
	INT64 dwGroup,		// Ŀ��Ⱥ
	bool newStatus		// Ҫ���õ���״̬
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "��Ⱥ��" + to_string(dwGroup) \
			+ "��" + (newStatus ? "����" : "��ֹ") + "ͨ��Ⱥ������ʱ�Ự"
		);
	return QY_setGroupPrivateSession(QYAPI::authCode, robotID, dwGroup, int(newStatus));
}

/*
 * ��Ⱥ��Ա����������쿪��
 * ��ҪȺ��Ȩ��
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		Ŀ��Ⱥ
 * @param	INT32	 Switch			����
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
INT32 QYAPI::setGroupManyPeopleChat(
	INT64 robotID,		// ʹ�õĻ�����QQ
	INT64 dwGroup,		// Ŀ��Ⱥ
	bool newStatus		// Ҫ���õ���״̬
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "��Ⱥ��" + to_string(dwGroup) \
			+ "��" + (newStatus ? "����" : "��ֹ") + "ͨ��Ⱥ�����������"
		);
	return QY_setGroupManyPeopleChat(QYAPI::authCode, robotID, dwGroup, int(newStatus));
}

/*
 * ����Ⱥ����Ա
 * ��ҪȺ��Ȩ��
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		����Ⱥ
 * @param	INT64	 uin			Ŀ��QQ
 * @param	bool	 newStatus		true/���� false/ȡ��
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
INT32 QYAPI::setGroupAdmini(
	INT64 robotID,		// ʹ�õĻ�����QQ
	INT64 dwGroup,		// ����Ⱥ
	INT64 uin,			// Ŀ��QQ
	bool newStatus		// Ҫ���õ���״̬
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "��Ⱥ��" + to_string(dwGroup) \
			+ "��" + (newStatus ? "����" : "ȡ��") + "����Ա��" + to_string(uin)
		);
	return QY_setGroupAdmini(QYAPI::authCode, robotID, dwGroup, uin, int(newStatus));
}

/*
 * ����Ⱥ��Ա��Ƭ
 * ��Ҫ����ԱȨ��
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		����Ⱥ
 * @param	INT64	 QQUin			Ŀ��QQ
 * @param	string	 newCard		����Ƭ
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
INT32 QYAPI::setGroupMemberCard(
	INT64 robotID,		// ʹ�õĻ�����QQ
	INT64 dwGroup,		// ����Ⱥ
	INT64 uin,			// Ŀ��QQ
	string newCard		// ����Ƭ
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "������Ⱥ��" + to_string(dwGroup) \
			+ "��Ŀ��QQ��" + to_string(uin) \
			+ "��" + (newCard.length() ? ("����Ƭ��" + newCard) : "ɾ����Ƭ")
		);
	return QY_setModifyGroupMemberCard(QYAPI::authCode, robotID, dwGroup, uin, newCard.c_str());
}

/*
 * ����Ⱥ��Աר��ͷ��
 * ��ҪȺ��Ȩ��
 * Ŀǰ����׿QQЭ��֧��
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		����Ⱥ
 * @param	INT64	 uin			Ŀ��QQ
 * @param	CSTRING	 specialTitle	ͷ�Σ�����ɾ����������ı�
 * @param	INT32	 ExpireTime		��Ч�ڣ���λΪ�롣���������Ч������-1
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
INT32 QYAPI::setGroupSpecialTitle(
	INT64 robotID,			// ʹ�õĻ�����QQ
	INT64 dwGroup,			// ����Ⱥ
	INT64 uin,				// Ŀ��QQ
	string specialTitle,	// ͷ��
	INT32 expireTime		// ��Ч��
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "������Ⱥ��" + to_string(dwGroup) \
			+ "��Ŀ��QQ��" + to_string(uin) \
			+ "��" + (specialTitle.length() ? ("������ͷ�Σ�" + specialTitle + "����Чʱ�䣺" + (expireTime == -1 ? "����" : (to_string(expireTime) + "��"))) : "ɾ��ͷ��")
		);
	return QY_setGroupSpecialTitle(QYAPI::authCode, robotID, dwGroup, uin, specialTitle.c_str(), expireTime);
}

/*
 * ��Ⱥ�˳�
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		Ŀ��Ⱥ
 * @param	bool	 Disband		�Ƿ��ɢȺ��true/��ɢ false/�˳�
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
INT32 QYAPI::setGroupExit(
	INT64 robotID,	// ʹ�õĻ�����QQ
	INT64 dwGroup,	// Ŀ��Ⱥ
	bool disband	// �Ƿ��ɢȺ
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "��" + (disband ? "��ɢ" : "�˳�") + "Ⱥ��" + to_string(dwGroup)
		);
	return QY_setExitGroupChat(QYAPI::authCode, robotID, dwGroup, int(disband));
}

/*
 * ���������˳�
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwDiscuss		Ŀ��������
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
INT32 QYAPI::setDiscussExit(
	INT64 robotID,		// ʹ�õĻ�����QQ
	INT64 dwDiscuss		// Ŀ��������
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "���˳������飺" + to_string(dwDiscuss)
		);
	return QY_setExitDiscussChat(QYAPI::authCode, robotID, dwDiscuss);
}

/*
 * ���������Ա�Ƴ�
 * ��Ҫ������Ȩ��
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwDiscuss		����������
 * @param	INT64	 uin			Ŀ��QQ
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
INT32 QYAPI::setDiscussMembersKick(
	INT64 robotID,		// ʹ�õĻ�����QQ
	INT64 dwDiscuss,	// Ŀ��������
	INT64 uin			// Ŀ��QQ
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "���������飺" + to_string(dwDiscuss) \
			+ "���߳���Ա��" + to_string(uin)
		);
	return QY_setDiscussMembersKick(QYAPI::authCode, robotID, dwDiscuss, uin);
}

/*
 * �����Ⱥ
 * @param	INT64	 robotID			ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup			Ŀ��Ⱥ
 * @param	string	 additionalMsg		������Ϣ
 * @return	INT32	 unknown			(�Ʋ�)״̬��
 */
INT32 QYAPI::setGroupAdd(
	INT64 robotID,			// ʹ�õĻ�����QQ
	INT64 dwGroup,			// Ŀ��Ⱥ
	string additionalMsg	// ������Ϣ
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "����Ⱥ��" + to_string(dwGroup)  + "������Ⱥ����"\
			+ "��������Ϣ��" + additionalMsg
		);
	return QY_setAddGroup(QYAPI::authCode, robotID, dwGroup, additionalMsg.c_str());
}

/*
 * �ô���Ⱥ�������
 * @param	INT64	 robotID			ʹ�õĻ�����QQ
 * @param	string	 responseFlag		�����¼��յ��ġ�������ʶ������
 * @param	INT32	 requestType		�������ͣ�����/REQUEST_GROUP_INVITE �� ��Ⱥ/REQUEST_GROUP_INVITE
 * @param	INT32	 resultFlag			��������ͨ��/REQUEST_ALLOW �� �ܾ�/REQUEST_DENY
 * @param	string	 reason				�ܾ����ɣ����� �ܾ� ʱ����
 * @return	INT32	 unknown			(�Ʋ�)״̬��
 */
INT32 QYAPI::setGroupAddRequest(
	INT64 robotID,			// ʹ�õĻ�����QQ
	string responseFlag,	// ������ʶ
	INT32 requestType,		// ��������
	INT32 resultFlag,		// ������
	string reason			// �ܾ�����
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "��������ʶ��" + responseFlag \
			+ "���������ͣ�" + to_string(requestType) \
			+ "����������" + ((resultFlag == REQUEST_ALLOW) ? "ͨ��" : "�ܾ�") \
			+ ((resultFlag == REQUEST_DENY) ? ("���ܾ����ɣ�" + reason) : "")
		);
	return QY_setGroupAddRequest(QYAPI::authCode, robotID, responseFlag.c_str(), requestType, resultFlag, reason.c_str());
}

/*
 * �ô�������������
 * @param	INT64	 robotID			ʹ�õĻ�����QQ
 * @param	string	 responseFlag		�����¼��յ��ġ�������ʶ������
 * @param	INT32	 resultFlag			��������ͨ��/REQUEST_ALLOW �� �ܾ�/REQUEST_DENY
 * @param	string	 remarks			ͨ��ʱΪ��Ӻ�ĺ��ѱ�ע���ܾ�ʱΪ�ܾ�����
 * @return	INT32	 unknown			(�Ʋ�)״̬��
 */
INT32 QYAPI::setFriendAddRequest(
	INT64 robotID,			// ʹ�õĻ�����QQ
	string responseFlag,	// ������ʶ
	INT32 resultFlag,		// ������
	string remarks			// ͨ��ʱΪ��Ӻ�ĺ��ѱ�ע���ܾ�ʱΪ�ܾ�����
)
{
	if(QYAPI_TOLOG)
		QYAPI::addLog::Debug(robotID, __func__,
			"������QQ��" + to_string(robotID) \
			+ "��������ʶ��" + responseFlag \
			+ "����������" + ((resultFlag == REQUEST_ALLOW) ? "ͨ��" : "�ܾ�") \
			+ "��" + ((resultFlag == REQUEST_ALLOW) ? "��ע��" : "�ܾ����ɣ�") + remarks
		);
	return QY_setFriendAddRequest(QYAPI::authCode, robotID, responseFlag.c_str(), resultFlag, remarks.c_str());
}

#undef QYAPI_TOLOG