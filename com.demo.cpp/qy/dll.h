// ���ļ�����API���
// ��������Ķ�
// Ӧ��QY��������
#pragma once
#pragma comment(lib, "dll")

#ifndef QYAPI
#define QYAPI(RETURN_TYPE) extern "C" __declspec(dllimport) RETURN_TYPE __stdcall
#endif


/**
 * �����־
 * @param	INT32	 authCode	Ӧ�ñ�ʶ
 * @param	INT64	 robotID	������QQ���������ֶ�ŵ�¼
 * @param	INT32	 level		��־�ȼ������� LOG_ ��ͷ�Ķ�Ӧ����
 * @param	CSTRING	 event		�¼�����
 * @param	CSTRING	 contents	�¼�����
 * @return	INT32	 unknown	�̶�����0
 */
QYAPI(INT) QY_addLog(INT32 authCode, INT64 robotID, INT32 level, CSTRING event, CSTRING contents);

/*
 * ȡ�����
 * @param	INT32	 authCode	Ӧ�ñ�ʶ
 * @return	CSTRING	 frameName	�����
 */
QYAPI(CSTRING) QY_getFrameName(INT32 authCode);

/*
 * ��Ӧ����ͣ��
 * @param	INT32	authCode	Ӧ�ñ�ʶ
 * @param	INT64	waitTime	�ȴ�ʱ�䣬��λ������
 * @return	INT32	unknown
 */
QYAPI(INT32) QY_setAppSelfDiscontinue(INT32 authCode, INT64 waitTime);

/*
 * ��Ӧ����ж��
 * @param	INT32	authCode	Ӧ�ñ�ʶ
 * @param	INT64	waitTime	�ȴ�ʱ�䣬��λ������
 * @return	INT32	unknown
 */
QYAPI(INT32) QY_setAppSelfUninstall(INT32 authCode, INT64 waitTime);

/*
 * ȡӦ��Ŀ¼
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @return	CSTRING	 appDirectory	���Ŀ¼
 */
QYAPI(CSTRING) QY_getAppDirectory(INT32 authCode);

/*
 * ȡ��¼QQ�б�
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @return	CSTRING	 strLoginQQList	��¼QQ�б����ݣ���Ҫ����
 */
QYAPI(CSTRING) QY_getLoginQQList(INT32 authCode);

/*
 * ȡ����˺�״̬
 * @param	INT32	authCode	Ӧ�ñ�ʶ
 * @param	INT64	robotID		Ҫ��ѯ���˺�
 * @return	INT32	�˺�״̬
 */
QYAPI(INT32) QY_getFrameAccountState(INT32 authCode, INT64 robotID);

/*
 * ȡ��¼�ǳ�
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		�漰�Ļ�����QQ
 * @return	CSTRING	 loginNick		�ǳ�
 */
QYAPI(CSTRING) QY_getLoginNick(INT32 authCode, INT64 robotID);

/*
 * ȡcookies
 * �˽ӿ���Ҫ�ϸ���Ȩ
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		�漰�Ļ�����QQ
 * @return	CSTRING	 cookies		cookies
 */
QYAPI(CSTRING) QY_getCookies(INT32 authCode, INT64 robotID);

/*
 * ȡcsrfToken
 * �˽ӿ���Ҫ�ϸ���Ȩ
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		�漰�Ļ�����QQ
 * @return	INT32	 csrfToken		csrfToken
 */
QYAPI(INT32) QY_getCsrfToken(INT32 authCode, INT64 robotID);

/*
 * ��������ȡcookie
 * �˽ӿ���Ҫ�ϸ���Ȩ
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		�漰�Ļ�����QQ
 * @param	CSTRING	 domain			Ҫ��ȡ��������http://qun.qq.com �� http://qun.qzone.qq.com 
 * @return	CSTRING	 cookie			��¼ָ����������ת�ɹ����cookies
 */
QYAPI(CSTRING) QY_getDomainCookie(INT32 authCode, INT64 robotID, CSTRING domain);

/*
 * ȡȺ�б�
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		Ҫ��ѯ�Ļ�����QQ
 * @return	CSTRING	 strGroupList	Ⱥ�б����ݣ���Ҫ����
 */
QYAPI(CSTRING) QY_getGroupList(INT32 authCode, INT64 robotID);

/*
 * ȡȺ��Ϣ/����
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		������QQ
 * @param	INT64	 dwGroup		Ҫ��ѯ��Ⱥ��
 * @return	CSTRING	 strGroupInfo	Ⱥ�������ݣ���Ҫ����
 */
QYAPI(CSTRING) QY_getGroupInfo(INT32 authCode, INT64 robotID, INT64 dwGroup);

/*
 * ȡȺ�������б�
 * ����Ⱥ��
 * @param	INT32	 authCode				Ӧ�ñ�ʶ
 * @param	INT64	 robotID				������QQ
 * @param	INT64	 dwGroup				Ҫ��ѯ��Ⱥ��
 * @return	CSTRING	 strGroupAdminList		Ⱥ�������б����ݣ���Ҫ����
 */
QYAPI(CSTRING) QY_getGroupAdminList(INT32 authCode, INT64 robotID, INT64 dwGroup);

/*
 * ȡȺ��Ա�б�
 * @param	INT32	 authCode				Ӧ�ñ�ʶ
 * @param	INT64	 robotID				������QQ
 * @param	INT64	 dwGroup				Ҫ��ѯ��Ⱥ��
 * @return	CSTRING	 strGroupMemberList		Ⱥ��Ա�б����ݣ���Ҫ����
 */
QYAPI(CSTRING) QY_getGroupMemberList(INT32 authCode, INT64 robotID, INT64 dwGroup);

/*
 * ȡȺ��Ա��Ƭ
 * @param	INT32	 authCode				Ӧ�ñ�ʶ
 * @param	INT64	 robotID				������QQ
 * @param	INT64	 dwGroup				����Ⱥ
 * @param	INT64	 uin					Ҫ��ѯ��QQ
 * @param	BOOLEAN  ignoreCache			��ʹ�û��棬true/��ʹ�û��� false/ʹ�û���
 * @return	CSTRING	 strGroupMemberCard		��Ⱥ��Ա��Ƭ
 */
QYAPI(CSTRING) QY_getGroupMemberCard(INT32 authCode, INT64 robotID, INT64 dwGroup, INT64 uin, BOOLEAN ignoreCache);

/*
 * ȡQQ��Ϣ/����
 * @param	INT32	 authCode			Ӧ�ñ�ʶ
 * @param	INT64	 robotID			������QQ
 * @param	INT64	 uin				Ҫ��ѯ��QQ
 * @return	CSTRING	 strSummaryInfo		QQ��Ϣ���ݣ���Ҫ����
 */
QYAPI(CSTRING) QY_getSummaryInfo(INT32 authCode, INT64 robotID, INT64 uin);

/*
 * ȡ�����б�
 * @param	INT32	 authCode			Ӧ�ñ�ʶ
 * @param	INT64	 robotID			Ҫ��ѯ�Ļ�����QQ
 * @return	CSTRING	 strFriendList		�����б����ݣ���Ҫ����
 */
QYAPI(CSTRING) QY_getFriendList(INT32 authCode, INT64 robotID);

/*
 * ȡ�������б�
 * @param	INT32	 authCode			Ӧ�ñ�ʶ
 * @param	INT64	 robotID			Ҫ��ѯ�Ļ�����QQ
 * @return	CSTRING	 strDiscussList		�������б����ݣ���Ҫ����
 */
QYAPI(CSTRING) QY_getDiscussList(INT32 authCode, INT64 robotID);

/*
 * ������Ƭ����
 * @param	INT32	 authCode	Ӧ�ñ�ʶ
 * @param	INT64	 robotID	ʹ�õĻ�����QQ
 * @param	INT64	 uin		Ŀ��QQ
 * @return	INT32	 unknown	(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_sendLikeFavorite(INT32 authCode, INT64 robotID, INT64 uin);

/*
 * ���ͺ�����Ϣ
 * @param	INT32	 authCode	Ӧ�ñ�ʶ
 * @param	INT64	 robotID	ʹ�õĻ�����QQ
 * @param	INT64	 uin		Ŀ��QQ
 * @param	CSTRING	 msg		��Ϣ����
 * @return	INT32	 unknown	(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_sendFriendMsg(INT32 authCode, INT64 robotID, INT64 uin, CSTRING msg);

/*
 * ����Ⱥ��Ϣ
 * @param	INT32	 authCode	Ӧ�ñ�ʶ
 * @param	INT64	 robotID	ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup	Ŀ��Ⱥ
 * @param	CSTRING	 msg		��Ϣ����
 * @return	INT32	 unknown	(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_sendGroupMsg(INT32 authCode, INT64 robotID, INT64 dwGroup, CSTRING msg);

/*
 * ����Ⱥ��ʱ��Ϣ
 * @param	INT32	 authCode	Ӧ�ñ�ʶ
 * @param	INT64	 robotID	ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup	����Ⱥ
 * @param	INT64	 uin		Ŀ��QQ
 * @param	CSTRING	 msg		��Ϣ����
 * @return	INT32	 unknown	(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_sendGroupTmpMsg(INT32 authCode, INT64 robotID, INT64 dwGroup, INT64 uin, CSTRING msg);

/*
 * ������������Ϣ
 * @param	INT32		authCode	Ӧ�ñ�ʶ
 * @param	INT64		robotID		ʹ�õĻ�����QQ
 * @param	INT64		dwDiscuss	Ŀ��������
 * @param	CSTRING		msg			��Ϣ����
 * @return	INT32		unknown		(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_sendDiscussMsg(INT32 authCode, INT64 robotID, INT64 dwDiscuss, CSTRING msg);

/*
 * ������������ʱ��Ϣ
 * @param	INT32	 authCode	Ӧ�ñ�ʶ
 * @param	INT64	 robotID	ʹ�õĻ�����QQ
 * @param	INT64	 dwDiscuss	����������
 * @param	INT64	 uin		Ŀ��QQ
 * @param	CSTRING	 msg		��Ϣ����
 * @return	INT32	 unknown	(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_sendDiscussTmpMsg(INT32 authCode, INT64 robotID, INT64 dwDiscuss, INT64 uin, CSTRING msg);

/*
 * ���������ļ�
 * @param	INT32		authCode		Ӧ�ñ�ʶ
 * @param	INT64		robotID			ʹ�õĻ�����QQ
 * @param	INT64		dwUin			Ŀ�����Ⱥ�� / ������ID / ����QQ
 * @param	INT64		dwToUin			QQ�ţ�������ʱ��Ϣʱʹ��
 * @param	INT32		dwMsgType		��Ϣ���ͣ�83/��������Ϣ 141/��ʱ��Ϣ 166/������Ϣ
 * @param	INT32		dwSubMsgType	��ʱ��Ϣ���ͣ�0/Ⱥ��ʱ 1/��������ʱ
 * @param	CSTRING		strLocalPath	�ļ�·��
 * @return	INT32		unknown			(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_sendOfflineFile(INT32 authCode, INT64 robotID, INT64 dwUin, INT64 dwToUin, INT32 dwMsgType, INT32 dwSubMsgType, CSTRING strLocalPath);

/*
 * ����Ϣ����
 * ���������Ҫ����ԱȨ��
 * @param	INT32	 authCode	Ӧ�ñ�ʶ
 * @param	INT64	 robotID	ʹ�õĻ�����QQ
 * @param	CSTRING	 msgInfo	��Ϣ���ݣ�Ϊ�����¼��Ĳ���
 * @return	INT32	 unknown	(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setMessageSvcMsgWithDraw(INT32 authCode, INT64 robotID, CSTRING msgInfo);

/*
 * ɾ������
 * @param	INT32	 authCode	Ӧ�ñ�ʶ
 * @param	INT64	 robotID	ʹ�õĻ�����QQ
 * @param	INT64	 QQUin		Ŀ��QQ
 * @return	INT32	 unknown	(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setDelFriend(INT32 authCode, INT64 robotID, INT64 uin);

/*
 * ��Ⱥ�ļ��ϴ�
 * @param	INT32	 authCode			Ӧ�ñ�ʶ
 * @param	INT64	 robotID			ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup			Ŀ��Ⱥ
 * @param	CSTRING	 strParentFolder	Ⱥ�ļ���·������ ��/��Ϊ��Ŀ¼
 * @param	CSTRING	 strLocalPath		�����ļ�·��
 * @return	INT32	 unknown			(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setGroupFileUpload(INT32 authCode, INT64 robotID, INT64 dwGroup, CSTRING strParentFolder, CSTRING strLocalPath);

/*
 * ��Ⱥ�ļ�ɾ��
 * @param	INT32	 authCode			Ӧ�ñ�ʶ
 * @param	INT64	 robotID			ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup			Ŀ��Ⱥ
 * @param	INT64	 fileBusID			�ļ�����ID
 * @param	CSTRING	 strParentFolder	���ļ���ID Ŀ�� Ⱥ�ļ���·������ ��/��Ϊ��Ŀ¼
 * @param	CSTRING	 fileID				�ļ�ID
 * @return	INT32	 unknown			(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setDelGroupFile(INT32 authCode, INT64 robotID, INT64 dwGroup, INT64 fileBusID, CSTRING strParentFolder, CSTRING fileID);


/*
 * ��ȺԱ�Ƴ�
 * ��Ҫ����ԱȨ��
 * @param	INT32	 authCode			Ӧ�ñ�ʶ
 * @param	INT64	 robotID			ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup			����Ⱥ
 * @param	INT64	 uin				Ŀ��QQ
 * @param	INT32	 ignoreAddRequest	���ٽ��մ��˼�Ⱥ���룬������
 * @return	INT32	 unknown			(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setGroupMembersKick(INT32 authCode, INT64 robotID, INT64 dwGroup, INT64 uin, INT32 ignoreAddRequest);

/*
 * ��ȫȺ����
 * ��Ҫ����ԱȨ��
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		Ŀ��Ⱥ
 * @param	INT32	 newStatus		����
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setGroupWholeBanSpeak(INT32 authCode, INT64 robotID, INT64 dwGroup, INT32 newStatus);

/*
 * ��ȺԱ����
 * ��Ҫ����ԱȨ��
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		����Ⱥ
 * @param	INT64	 uin			Ŀ��QQ
 * @param	INT64	 timeStamp		����ʱ�䣬��λΪ�롣���Ҫ�����������д0
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setGroupMembersBanSpeak(INT32 authCode, INT64 robotID, INT64 dwGroup, INT64 uin, INT64 timeStamp);

/*
 * ��Ⱥ������Ա����
 * ���Ժ��޷����
 * ��Ҫ����ԱȨ��
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		����Ⱥ
 * @param	INT32	 anonHead		�����û���ͷ���ʶ
 * @param	CSTRING	 anonToken		�����û�Token
 * @param	CSTRING	 anonCard		�����û���Ƭ
 * @param	INT64	 timeStamp		����ʱ�䣬��λΪ��
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setGroupAnonymousBanSpeak(INT32 authCode, INT64 robotID, INT64 dwGroup, INT32 anonHead, CSTRING token, CSTRING anonCard, INT64 timeStamp);

/*
 * ����Ⱥ�������쿪��
 * ��Ҫ����ԱȨ��
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		Ŀ��Ⱥ
 * @param	INT32	 newStatus		��״̬��0/��ֹ 1/����
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setGroupAnonymousBan(INT32 authCode, INT64 robotID, INT64 dwGroup, INT32 newStatus);

/*
 * ��Ⱥ��ʱ�Ự����
 * ��ҪȺ��Ȩ��
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		Ŀ��Ⱥ
 * @param	INT32	 newStatus		��״̬��0/��ֹ 1/����
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setGroupPrivateSession(INT32 authCode, INT64 robotID, INT64 dwGroup, INT32 newStatus);

/*
 * ��Ⱥ��Ա����������쿪��
 * ��ҪȺ��Ȩ��
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		Ŀ��Ⱥ
 * @param	INT32	 newStatus		��״̬��0/��ֹ 1/����
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setGroupManyPeopleChat(INT32 authCode, INT64 robotID, INT64 dwGroup, INT32 newStatus);

/*
 * ����Ⱥ����Ա
 * ��ҪȺ��Ȩ��
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		����Ⱥ
 * @param	INT64	 uin			Ŀ��QQ
 * @param	INT32	 newStatus		��״̬��0/ȡ������Ա 1/����Ϊ����Ա
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setGroupAdmini(INT32 authCode, INT64 robotID, INT64 dwGroup, INT64 uin, INT32 newStatus);

/*
 * ����Ⱥ��Ա��Ƭ
 * ��Ҫ����ԱȨ��
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		����Ⱥ
 * @param	INT64	 uin			Ŀ��QQ
 * @param	CSTRING	 newCard		����Ƭ
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setModifyGroupMemberCard(INT32 authCode, INT64 robotID, INT64 dwGroup, INT64 uin, CSTRING newCard);

/*
 * ����Ⱥ��Աר��ͷ��
 * ��ҪȺ��Ȩ��
 * Ŀǰ����׿QQЭ��֧��
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		����Ⱥ
 * @param	INT64	 uin			Ŀ��QQ
 * @param	CSTRING	 specialTitle	ͷ�Σ�����ɾ����������ı�
 * @param	INT32	 expireTime		��Ч�ڣ���λΪ�롣���������Ч������-1
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setGroupSpecialTitle(INT32 authCode, INT64 robotID, INT64 dwGroup, INT64 uin, CSTRING specialTitle, INT32 expireTime);

/*
 * ��Ⱥ�˳�
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup		����Ⱥ
 * @param	INT32	 disband		�Ƿ��ɢȺ��1/��ɢ 0/�˳�
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setExitGroupChat(INT32 authCode, INT64 robotID, INT64 dwGroup, INT32 disband);

/*
 * ���������˳�
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwDiscuss		Ŀ��������
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setExitDiscussChat(INT32 authCode, INT64 robotID, INT64 dwDiscuss);

/*
 * ���������Ա�Ƴ�
 * ��Ҫ������Ȩ��
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	INT64	 robotID		ʹ�õĻ�����QQ
 * @param	INT64	 dwDiscuss		����������
 * @param	INT64	 uin			Ŀ��QQ
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setDiscussMembersKick(INT32 authCode, INT64 robotID, INT64 dwDiscuss, INT64 uin);

/*
 * �����Ⱥ
 * @param	INT32	 authCode			Ӧ�ñ�ʶ
 * @param	INT64	 robotID			ʹ�õĻ�����QQ
 * @param	INT64	 dwGroup			Ŀ��Ⱥ
 * @param	CSTRING	 additionalMsg		������Ϣ
 * @return	INT32	 unknown			(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setAddGroup(INT32 authCode, INT64 robotID, INT64 dwGroup, CSTRING additionalMsg);

/*
 * �ô���Ⱥ�������
 * @param	INT32	 authCode			Ӧ�ñ�ʶ
 * @param	INT64	 robotID			ʹ�õĻ�����QQ
 * @param	CSTRING	 responseFlag		�����¼��յ��ġ�������ʶ������
 * @param	INT32	 requestType		�������ͣ�����/REQUEST_GROUP_INVITE �� ��Ⱥ/REQUEST_GROUP_INVITE
 * @param	INT32	 resultFlag			��������ͨ��/REQUEST_ALLOW �� �ܾ�/REQUEST_DENY
 * @param	CSTRING	 reason				�ܾ����ɣ����� ��Ⱥ �� �ܾ� ʱ����
 * @return	INT32	 unknown			(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setGroupAddRequest(INT32 authCode, INT64 robotID, CSTRING responseFlag, INT32 requestType, INT32 resultFlag, CSTRING reason);

/*
 * �ô�������������
 * @param	INT32	 authCode			Ӧ�ñ�ʶ
 * @param	INT64	 robotID			ʹ�õĻ�����QQ
 * @param	CSTRING	 responseFlag		�����¼��յ��ġ�������ʶ������
 * @param	INT32	 resultFlag			��������ͨ��/REQUEST_ALLOW �� �ܾ�/REQUEST_DENY
 * @param	CSTRING	 remarks			ͨ��ʱΪ��Ӻ�ĺ��ѱ�ע���ܾ�ʱΪ�ܾ�����
 * @return	INT32	 unknown			(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setFriendAddRequest(INT32 authCode, INT64 robotID, CSTRING responseFlag, INT32 resultFlag, CSTRING remarks);

/*
 * ������������ʾ
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	CSTRING	 errorInfo		������Ϣ
 * @return	INT32	 unknown		(�Ʋ�)״̬��
 */
QYAPI(INT32) QY_setFatal(INT32 authCode, CSTRING errorInfo);

/*
 * ����Utf8��Ansi
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	CSTRING	 utf8Content	��Ҫת����UTF-8�����ı�
 * @return	CSTRING	 ansiContent	ת�����ANSI�����ı�
 */
QYAPI(CSTRING) QY_setEncodeUtf8ToAnsi(INT32 authCode, CSTRING utf8Content);

/*
 * ����Ansi��Utf8
 * @param	INT32	 authCode		Ӧ�ñ�ʶ
 * @param	CSTRING	 ansiContent	��Ҫת����ANSI�����ı�
 * @return	CSTRING	 utf8Content	ת�����UTF-8�����ı�
 */
QYAPI(CSTRING) QY_setEncodeAnsiToUtf8(INT32 authCode, CSTRING ansiContent);

#undef QYAPI