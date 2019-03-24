#pragma once
#include "log.h"
#include "code.h"
#include "typedef.h"
#include "infoAnalyze.h"

class QYAPI
{
	private:
		static bool		appEnable;		//�������״̬
		static INT32	authCode;		//Ӧ�ñ�ʶ�����ڵ���API
		static INT32	protocolType;	//Э�����ͣ�1/��׿QQЭ�� 2/PCQQЭ��
		static string	appDirectory;	//��ܷ����Ψһ���ݴ��Ŀ¼
	
	public:
		static const auto EVENT_IGNORE = 0;				//�¼�_����
		static const auto EVENT_BLOCK = 1;				//�¼�_����

		static const auto REQUEST_ALLOW = 0;			//����_ͨ��
		static const auto REQUEST_DENY = 1;				//����_�ܾ�

		static const auto REQUEST_GROUP_ADD = 0;		//����_Ⱥ���
		static const auto REQUEST_GROUP_INVITE = 1;		//����_Ⱥ����

		typedef QYLOG addLog;					// ��־��
		typedef QYInfoAnalyze infoAnalyze;		// ��Ϣ����
		typedef QYTYPE Type;					// �Զ�����������
		typedef QYCODE Code;					// LQ��

	public:
		/**
		 * ȡ�����Json��Ϣ
		 * ����APPInfo����
		 * @return	CSTRING		Json�ı�
		 */
		static CSTRING getJsonInfo();
		
		/**
		 * ��AuthCode
		 * @param	INT32	authCode	Ӧ�ñ�ʶ
		 */
		static void setAuthCode(INT32 authCode);

		/**
		 * ȡAuthCode
		 * @return	INT32	authCode	Ӧ�ñ�ʶ
		 */
		static INT32 getAuthCode();

		/**
		 * ��ProtocolType
		 * @param	INT32	protocolType	Э������ 1/��׿QQЭ�� 2/PCQQЭ��
		 */
		static void setProtocolType(INT32 protocolType);

		/**
		 * ȡProtocolType
		 * @return	INT32	protocolType	Э������ 1/��׿QQЭ�� 2/PCQQЭ��
		 */
		static INT32 getProtocolType();

		/**
		 * �ò������״̬
		 * @param	bool	state	����״̬
		 */
		static void setAppEnable(bool state);

		/**
		 * ȡ�������״̬
		 * @return	bool	state	����״̬
		 */
		static bool getAppEnable();

		/**
		 * ȡ�����
		 * @return	string		�����
		 */
		static string getFrameName();

		/*
		 * ��Ӧ����ͣ��
		 * @param	INT64	waitTime	�ȴ�ʱ��(��λ������)������һ��ʱ��ʹ����������ɣ�����ֱ�Ӳ������ֳ�ͻ��ɿ�ܱ���
		 * @return	INT32	unknown
		 */
		static INT32 setAppSelfDiscontinue(INT64 waitTime = 1000);

		/*
		 * ��Ӧ����ж��
		 * @param	INT64	waitTime	�ȴ�ʱ�䣬��λ������
		 * @return	INT32	unknown
		 */
		static INT32 setAppSelfUninstall(INT64 waitTime = 1000);

		/**
		 * ȡӦ��Ŀ¼
		 * ���ص�·��ĩβ����\��
		 * @return	string		Ӧ��Ŀ¼
		 */
		static string getAppDirectory();

		/**
		 * ȡ��¼QQ�б�
		 * @param	INT64List	bindLoginQQList		��¼QQ�б�����ã�ִ�гɹ��󽫴�������ڴ�
		 * @return	bool		ִ�н��
		 */
		static bool getLoginQQList(INT64List & bindLoginQQList);

		/**
		 * ȡ��¼QQ�б�(������״̬)
		 * @param	bool		getState			ȡ����״̬
		 * @param	LoginQQList	bindLoginQQList		��¼QQ�б�����ã�ִ�гɹ��󽫴�������ڴ�
		 * @return	bool		ִ�н��
		 */
		static bool getLoginQQList(bool getState, Type::LoginQQList & bindLoginQQList);

		/**
		 * ���ȡһ����¼QQ
		 * @param	useCache	ʹ�û���
		 * @return	INT64		��¼QQ
		 */
		static INT64 getRandomLoginQQ(bool useCache = false);

		/*
		 * ȡ����˺�״̬
		 * @param	INT64	robotID		Ҫ��ѯ���˺�
		 * @return	INT32	�˺�״̬		0/���� 1/����
		 */
		static INT32 getFrameAccountState(INT64 robotID);

		/**
		 * ȡָ�������˵��ǳ�
		 * @param	INT64	robotID		Ҫ��ѯ�ǳƵĻ�����QQ
		 * @return	string	nick		�û����˵��ǳ�
		 */
		static string getLoginQQName(INT64 robotID);

		/**
		 * ȡָ�������˵�cookies
		 * @param	INT64		robotID		Ҫ��ѯ�Ļ�����QQ
		 * @return	string		cookies		�û����˵�cookies
		 */
		static string getCookies(INT64 robotID);

		/**
		 * ȡָ�������˵�csrfToken
		 * @param	INT64	robotID		Ҫ��ѯ�Ļ�����QQ
		 * @return	INT32	csrfToken	�û����˵�csrfToken
		 */
		static INT32 getCsrfToken(INT64 robotID);

		/**
		 * ȡ����cookie
		 * @param	INT64		robotID		Ҫ��ѯ�Ļ�����QQ
		 * @param	string		domain		Ҫ��ȡcookies��������http://qun.qq.com �� http://qun.qzone.qq.com
		 * @return	string		cookies		��¼ָ����������ת�ɹ����cookies
		 */
		static string getDomainCookies(INT64 robotID, string domain = "http://qun.qq.com");

		/**
		 * ȡ�����б�
		 * @param	INT64		robotID			Ҫ��ѯ�Ļ�����QQ
		 * @param	FriendList	bindFriendList	�����б�����ã�ִ�гɹ��󽫴�������ڴ�
		 * @return	bool		ִ�н��
		 */
		static bool getFriendList(INT64 robotID, Type::FriendList & bindFriendList);

		/**
		 * ȡQQ��Ҫ��Ϣ
		 * @param	INT64			robotID				ʹ�õĻ�����QQ
		 * @param	INT64			uin					��ѯQQ
		 * @param	QQSummaryInfo	bindQSummaryInfo	QQ��Ҫ��Ϣ�����ã�ִ�гɹ��󽫴�������ڴ�
		 * @return	bool			ִ�н��
		 */
		static bool getQQSummaryInfo(INT64 robotID, INT64 uin, Type::QQSummaryInfo & bindQSummaryInfo);

		/**
		 * ȡȺ�б�
		 * @param	INT64		robotID			Ҫ��ѯ�Ļ�����QQ
		 * @param	GroupList	bindGroupList	Ⱥ�б�����ã�ִ�гɹ��󽫴�������ڴ�
		 * @return	bool		ִ�н��
		 */
		static bool getGroupList(INT64 robotID, Type::GroupList & bindGroupList);

		/**
		 * ȡȺ����
		 * @param	INT64		robotID			ʹ�õĻ�����QQ
		 * @param	INT64		dwGroup			Ҫ��ѯ��Ⱥ��
		 * @param	GroupInfo	bindGroupInfo	Ⱥ���ϵ����ã�ִ�гɹ��󽫴�������ڴ�
		 * @return	bool		ִ�н��
		 */
		static bool getGroupInfo(INT64 robotID, INT64 dwGroup, Type::GroupInfo & bindGroupInfo);

		/**
		 * ȡȺ����Ա�б�
		 * ����Ⱥ��
		 * @param	INT64			robotID				ʹ�õĻ�����QQ
		 * @param	INT64			dwGroup				Ҫ��ѯ��Ⱥ��
		 * @param	GroupAdminList	bindGroupAdminList	Ⱥ�����б�����ã�ִ�гɹ��󽫴�������ڴ�
		 * @return	bool			ִ�н��
		 */
		static bool getGroupAdminList(INT64 robotID, INT64 dwGroup, Type::GroupAdminList & bindGroupAdminList);

		/**
		 * ȡȺ��Ա�б�
		 * PCЭ��ֻ�ܻ�ȡQQ�͹���Ȩ��
		 * @param	INT64			robotID					ʹ�õĻ�����QQ
		 * @param	INT64			dwGroup					Ҫ��ѯ��Ⱥ��
		 * @param	GroupMemberList	bindGroupMemberList		Ⱥ��Ա�б�����ã�ִ�гɹ��󽫴�������ڴ�
		 * @return	bool			ִ�н��
		 */
		static bool getGroupMemberList(INT64 robotID, INT64 dwGroup, Type::GroupMemberList & bindGroupMemberList);

		/**
		 * ȡȺ��Ա��Ƭ
		 * @param	INT64		robotID			ʹ�õĻ�����QQ
		 * @param	INT64		dwGroup			����Ⱥ
		 * @param	INT64		uin				Ҫ��ѯ��QQ��
		 * @param	bool		useNick			ʹ���ǳƣ�Ĭ�ϲ�ʹ�á�����ƬΪ�գ�ʹ��ʱ�����ǳƣ���ʹ���򷵻ؿ�
		 * @param	bool		useCache		ʹ�û��棬Ĭ��ʹ��
		 * @return	string		��Ⱥ��Ա����Ƭ
		 */
		static string getGroupMemberCard(INT64 robotID, INT64 dwGroup, INT64 uin, bool useNick = false, bool useCache = true);

		/**
		 * ȡ�������б�
		 * @param	INT64			robotID				Ҫ��ѯ�Ļ�����QQ
		 * @param	DiscussList		bindDiscussList		�������б�����ã�ִ�гɹ��󽫴�������ڴ�
		 * @return	bool			ִ�н��
		 */
		static bool getDiscussList(INT64 robotID, Type::DiscussList & bindDiscussList);

		/**
		 * ����_UTF8תAnsi
		 * @param	BYTES		contents		UTF-8�����ı�
		 * @return	CSTRING		GB2312�����ı�
		 */
		static CSTRING convertUtf8ToAnsi(BYTES contents);
		/**
		 * ����_UTF8תAnsi
		 * @param	string		contents		UTF-8�����ı�
		 * @return	CSTRING		GB2312�����ı�
		 */
		static CSTRING convertUtf8ToAnsi(string contents);

		/**
		 * ����_GB2312תUTF8
		 * @param	string		contents	GB2312�����ı�
		 * @return	BYTES		UTF-8�����ı�
		 */
		static BYTES convertAnsiToUtf8(string contents);

		/**
		 * ������������Ϣ
		 * @param	string		strAnonymousInfo	��������
		 * @param	Anonymous	bindAnonymousInfo	������Ϣ�����ã������ɹ��󽫴�������ڴ�
		 * @return	bool		�������
		 */
		static bool decodeAnonymousInfo(string strAnonymousInfo, Type::Anonymous & bindAnonymousInfo);

		/**
		 * ������Ⱥ������Ϣ
		 * @param	string					strGroupAdditionalInfo		Ⱥ������Ϣ����
		 * @param	GroupAdditionalInfo		bindGroupAdditionalInfo		Ⱥ������Ϣ�����ã������ɹ��󽫴�������ڴ�
		 * @return	bool					�������
		 */
		static bool decodeGroupAdditionalInfo(string strGroupAdditionalInfo, Type::GroupAdditionalInfo & bindGroupAdditionalInfo);

		/**
		 * ������������Ϣ
		 * @param	string		strFontInfo		��������
		 * @param	Font		bindFontInfo	������Ϣ�����ã������ɹ��󽫴�������ڴ�
		 * @return	bool		�������
		 */
		static bool decodeFontInfo(string strFontInfo, Type::Font & bindFontInfo);

		/**
		 * ������Ⱥ�ļ���Ϣ
		 * @param	string		strFileInfo		�ļ�����
		 * @param	File		bindFileInfo	�ļ���Ϣ�����ã������ɹ��󽫴�������ڴ�
		 * @return	bool		�������
		 */
		static bool decodeFileInfo(string strFileInfo, Type::File & bindFileInfo);

		/**
		 * ������������ʾ
		 * @param	string		errMsg		������Ϣ
		 * @return	INT32		unknown
		 */
		static INT32 setFatal(string errMsg);

		/**
		 * ������Ƭ��
		 * @param	INT64	robotID		ʹ�õĻ�����QQ
		 * @param	INT64	uin			Ŀ�����
		 * @param	INT32	count		���޴�����Ĭ�ϵ���һ��
		 * @return	INT32	�̶�����0
		 */
		static INT32 sendLikeFavorite(INT64 robotID, INT64 uin, INT32 count = 1);

		/*
		 * ���ͺ�����Ϣ
		 * @param	INT64	 robotID	ʹ�õĻ�����QQ
		 * @param	INT64	 uin		Ŀ��QQ
		 * @param	string	 msg		��Ϣ����
		 * @return	INT32	 unknown	(�Ʋ�)״̬��
		 */
		static INT32 sendFriendMsg(INT64 robotID, INT64 uin, string msg);

		/*
		 * ����Ⱥ��Ϣ
		 * @param	INT64	 robotID	ʹ�õĻ�����QQ
		 * @param	INT64	 dwGroup	Ŀ��Ⱥ
		 * @param	string	 msg		��Ϣ����
		 * @return	INT32	 unknown	(�Ʋ�)״̬��
		 */
		static INT32 sendGroupMsg(INT64 robotID, INT64 dwGroup, string msg);

		/*
		 * ����Ⱥ��ʱ��Ϣ
		 * @param	INT64	 robotID	ʹ�õĻ�����QQ
		 * @param	INT64	 dwGroup	����Ⱥ
		 * @param	INT64	 uin		Ŀ��QQ
		 * @param	string	 msg		��Ϣ����
		 * @return	INT32	 unknown	(�Ʋ�)״̬��
		 */
		static INT32 sendGroupTmpMsg(INT64 robotID, INT64 dwGroup, INT64 uin, string msg);

		/*
		 * ������������Ϣ
		 * @param	INT64	 robotID	ʹ�õĻ�����QQ
		 * @param	INT64	 dwDiscuss	Ŀ��������
		 * @param	string	 msg		��Ϣ����
		 * @return	INT32	 unknown	(�Ʋ�)״̬��
		 */
		static INT32 sendDiscussMsg(INT64 robotID, INT64 dwDiscuss, string msg);

		/*
		 * ������������ʱ��Ϣ
		 * @param	INT64	 robotID	ʹ�õĻ�����QQ
		 * @param	INT64	 dwDiscuss	����������
		 * @param	INT64	 uin		Ŀ��QQ
		 * @param	string	 msg		��Ϣ����
		 * @return	INT32	 unknown	(�Ʋ�)״̬��
		 */
		static INT32 sendDiscussTmpMsg(INT64 robotID, INT64 dwDiscuss, INT64 uin, string msg);

		/*
		 * ���������ļ�
		 * �����ϴ�Ⱥ�ļ���ָ��Ŀ¼����ʹ�á�setGroupFileUpload��
		 * @param	INT64		robotID			ʹ�õĻ�����QQ
		 * @param	INT32		dwMsgType		��Ϣ���ͣ�1/���� 2/Ⱥ 3/������ 4/Ⱥ��ʱ 5/��������ʱ
		 * @param	INT64		dwGroup			����Ⱥ��� Ⱥ�� / ������ID
		 * @param	INT64		dwUin			QQ�ţ����͸�����Ϣʱʹ��
		 * @param	string		strLocalPath	�ļ�·��
		 * @return	INT32		unknown			(�Ʋ�)״̬��
		 */
		static INT32 sendOfflineFile(INT64 robotID, INT32 dwMsgType, INT64 dwGroup, INT64 dwUin, string strLocalPath);

		/**
		 * ����Ϣ����
		 * @param	INT64		robotID		ʹ�õĻ�����QQ
		 * @param	string		msgInfo		��Ϣ��Ϣ
		 * @return	INT32		�������
		 */
		static INT32 setMessageSvcMsgWithDraw(INT64 robotID, string msgInfo);

		/*
		 * ɾ������
		 * @param	INT64	 robotID	ʹ�õĻ�����QQ
		 * @param	INT64	 uin		Ŀ��QQ
		 * @return	INT32	 unknown	(�Ʋ�)״̬��
		 */
		static INT32 setFriendDelete(INT64 robotID, INT64 uin);

		/*
		 * ��Ⱥ�ļ��ϴ�
		 * @param	INT64	 robotID			ʹ�õĻ�����QQ
		 * @param	INT64	 dwGroup			Ŀ��Ⱥ
		 * @param	string	 strParentFolder	Ⱥ�ļ���·������ ��/��Ϊ��Ŀ¼
		 * @param	string	 strLocalPath		�����ļ�·������������·�������ɿ�
		 * @return	INT32	 unknown			(�Ʋ�)״̬��
		 */
		static INT32 setGroupFileUpload(INT64 robotID, INT64 dwGroup, string strParentFolder = "/", string strLocalPath = "");

		/*
		 * ��Ⱥ�ļ�ɾ��
		 * @param	INT64	 robotID			ʹ�õĻ�����QQ
		 * @param	INT64	 dwGroup			Ŀ��Ⱥ
		 * @param	INT64	 fileBusID			�ļ�����ID
		 * @param	string	 strParentFolder	���ļ���ID Ŀ��Ⱥ�ļ���·������ ��/��Ϊ��Ŀ¼
		 * @param	string	 fileID				�ļ�ID�����ɿ�
		 * @return	INT32	 unknown			(�Ʋ�)״̬��
		 */
		static INT32 setGroupFileDelete(INT64 robotID, INT64 dwGroup, INT64 fileBusID, string strParentFolder = "/", string fileID = "");

		/*
		 * ��ȺԱ�Ƴ�
		 * ��Ҫ����ԱȨ��
		 * @param	INT64	 robotID			ʹ�õĻ�����QQ
		 * @param	INT64	 dwGroup			����Ⱥ
		 * @param	INT64	 uin				Ŀ��QQ
		 * @param	bool	 ignoreAddRequest	���ٽ��մ��˼�Ⱥ���룬�޷�������������
		 * @return	INT32	 unknown			(�Ʋ�)״̬��
		 */
		static INT32 setGroupMembersKick(INT64 robotID, INT64 dwGroup, INT64 uin, bool ignoreAddRequest = false);

		/*
		 * ��ȫȺ����
		 * ��Ҫ����ԱȨ��
		 * @param	INT64	 robotID		ʹ�õĻ�����QQ
		 * @param	INT64	 dwGroup		Ŀ��Ⱥ
		 * @param	bool	 newStatus		Ҫ���õ���״̬��true/�������� false/�رս���
		 * @return	INT32	 unknown		(�Ʋ�)״̬��
		 */
		static INT32 setGroupWholeBanSpeak(INT64 robotID, INT64 dwGroup, bool newStatus);

		/*
		 * ��ȺԱ����
		 * ��Ҫ����ԱȨ��
		 * @param	INT64	 robotID		ʹ�õĻ�����QQ
		 * @param	INT64	 dwGroup		����Ⱥ
		 * @param	INT64	 uin			Ŀ��QQ
		 * @param	INT64	 timeStamp		����ʱ�䣬��λΪ�룬�Ϊ1���¡����Ҫ�����������д0
		 * @return	INT32	 unknown		(�Ʋ�)״̬��
		 */
		static INT32 setGroupMemberBanSpeak(INT64 robotID, INT64 dwGroup, INT64 uin, INT64 timeStamp = 0);

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
		static INT32 setGroupAnonymousBanSpeak(INT64 robotID, INT64 dwGroup, INT64 headMark, BYTES token, string card, INT64 timeStamp);

		/*
		 * ����Ⱥ�������쿪��
		 * ��Ҫ����ԱȨ��
		 * @param	INT64	 robotID		ʹ�õĻ�����QQ
		 * @param	INT64	 dwGroup		Ŀ��Ⱥ
		 * @param	bool	 newStatus		Ҫ���õ���״̬��true/����false/��ֹ ��������
		 * @return	INT32	 unknown		(�Ʋ�)״̬��
		 */
		static INT32 setGroupAnonymousBan(INT64 robotID, INT64 dwGroup, bool newStatus);

		/*
		 * ��Ⱥ��ʱ�Ự����
		 * ��ҪȺ��Ȩ��
		 * @param	INT64	 robotID		ʹ�õĻ�����QQ
		 * @param	INT64	 dwGroup		Ŀ��Ⱥ
		 * @param	bool	 newStatus		Ҫ���õ���״̬��true/����false/��ֹ ͨ��Ⱥ������ʱ�Ự
		 * @return	INT32	 unknown		(�Ʋ�)״̬��
		 */
		static INT32 setGroupPrivateSession(INT64 robotID, INT64 dwGroup, bool newStatus);

		/*
		 * ��Ⱥ��Ա����������쿪��
		 * ��ҪȺ��Ȩ��
		 * @param	INT64	 robotID		ʹ�õĻ�����QQ
		 * @param	INT64	 dwGroup		Ŀ��Ⱥ
		 * @param	bool	 newStatus		Ҫ���õ���״̬��true/����false/��ֹ ͨ��Ⱥ�����������
		 * @return	INT32	 unknown		(�Ʋ�)״̬��
		 */
		static INT32 setGroupManyPeopleChat(INT64 robotID, INT64 dwGroup, bool newStatus);

		/*
		 * ����Ⱥ����Ա
		 * ��ҪȺ��Ȩ��
		 * @param	INT64	 robotID		ʹ�õĻ�����QQ
		 * @param	INT64	 dwGroup		����Ⱥ
		 * @param	INT64	 uin			Ŀ��QQ
		 * @param	bool	 newStatus		true/���� false/ȡ�� ����Ա
		 * @return	INT32	 unknown		(�Ʋ�)״̬��
		 */
		static INT32 setGroupAdmini(INT64 robotID, INT64 dwGroup, INT64 uin, bool newStatus);

		/*
		 * ����Ⱥ��Ա��Ƭ
		 * ��Ҫ����ԱȨ��
		 * @param	INT64	 robotID		ʹ�õĻ�����QQ
		 * @param	INT64	 dwGroup		����Ⱥ
		 * @param	INT64	 uin			Ŀ��QQ
		 * @param	string	 newCard		����Ƭ�����Ҫɾ����������ı�
		 * @return	INT32	 unknown		(�Ʋ�)״̬��
		 */
		static INT32 setGroupMemberCard(INT64 robotID, INT64 dwGroup, INT64 uin, string newCard = "");

		/*
		 * ����Ⱥ��Աר��ͷ��
		 * ��ҪȺ��Ȩ��
		 * Ŀǰ����׿QQЭ��֧��
		 * @param	INT64	 robotID		ʹ�õĻ�����QQ
		 * @param	INT64	 dwGroup		����Ⱥ
		 * @param	INT64	 uin			Ŀ��QQ
		 * @param	string	 specialTitle	ͷ�Σ�����ɾ����������ı�
		 * @param	INT32	 expireTime		��Ч�ڣ���λΪ�롣���������Ч������-1
		 * @return	INT32	 unknown		(�Ʋ�)״̬��
		 */
		static INT32 setGroupSpecialTitle(INT64 robotID, INT64 dwGroup, INT64 uin, string  specialTitle = "", INT32 rxpireTime = -1);

		/*
		 * ��Ⱥ�˳�
		 * @param	INT64		robotID		ʹ�õĻ�����QQ
		 * @param	INT64		dwGroup		Ŀ��Ⱥ
		 * @param	newStatus	disband		�Ƿ��ɢȺ��true/��ɢ false/�˳�
		 * @return	INT32		unknown		(�Ʋ�)״̬��
		 */
		static INT32 setGroupExit(INT64 robotID, INT64 dwGroup, bool disband = false);

		/*
		 * ���������˳�
		 * @param	INT64	 robotID		ʹ�õĻ�����QQ
		 * @param	INT64	 dwDiscuss		Ŀ��������
		 * @return	INT32	 unknown		(�Ʋ�)״̬��
		 */
		static INT32 setDiscussExit(INT64 robotID, INT64 dwDiscuss);

		/*
		 * ���������Ա�Ƴ�
		 * ��Ҫ������Ȩ��
		 * @param	INT64	 robotID		ʹ�õĻ�����QQ
		 * @param	INT64	 dwDiscuss		����������
		 * @param	INT64	 uin			Ŀ��QQ
		 * @return	INT32	 unknown		(�Ʋ�)״̬��
		 */
		static INT32 setDiscussMembersKick(INT64 robotID, INT64 dwDiscuss, INT64 uin);

		/*
		 * �����Ⱥ
		 * ��Ϊ�������ƣ����ܲ��ɹ�
		 * @param	INT64	 robotID			ʹ�õĻ�����QQ
		 * @param	INT64	 dwGroup			Ŀ��Ⱥ
		 * @param	string	 additionalMsg		������Ϣ
		 * @return	INT32	 unknown			(�Ʋ�)״̬��
		 */
		static INT32 setGroupAdd(INT64 robotID, INT64 dwGroup, string additionalMsg);

		/*
		 * �ô���Ⱥ�������
		 * @param	INT64	 robotID			ʹ�õĻ�����QQ
		 * @param	string	 responseFlag		�����¼��յ��ġ�������ʶ������
		 * @param	INT32	 requestType		�������ͣ�����/REQUEST_GROUP_INVITE �� ��Ⱥ/REQUEST_GROUP_INVITE
		 * @param	INT32	 resultFlag			��������ͨ��/REQUEST_ALLOW �� �ܾ�/REQUEST_DENY
		 * @param	string	 reason				�ܾ����ɣ����� �ܾ� ʱ����
		 * @return	INT32	 unknown			(�Ʋ�)״̬��
		 */
		static INT32 setGroupAddRequest(INT64 robotID, string responseFlag, INT32 requestType, INT32 resultFlag, string reason = "");

		/*
		 * �ô�������������
		 * @param	INT64	 robotID			ʹ�õĻ�����QQ
		 * @param	string	 responseFlag		�����¼��յ��ġ�������ʶ������
		 * @param	INT32	 resultFlag			��������ͨ��/REQUEST_ALLOW �� �ܾ�/REQUEST_DENY
		 * @param	string	 remarks			ͨ��ʱΪ��Ӻ�ĺ��ѱ�ע���ܾ�ʱΪ�ܾ�����
		 * @return	INT32	 unknown			(�Ʋ�)״̬��
		 */
		static INT32 setFriendAddRequest(INT64 robotID, string responseFlag, INT32 resultFlag, string remarks = "");
};

typedef QYAPI QY;
