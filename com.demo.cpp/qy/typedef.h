#pragma once

class QYTYPE
{
	public:

	typedef struct {
		INT64	uin;	// QQ��
		string	nick;	// �ǳ�
	} Friend; // ������Ϣ
	typedef std::vector<Friend> FriendList; // �����б�

	typedef struct {
		INT64	tempID;		// ��ʱȺ��
		INT64	id;			// Ⱥ��
		string	name;		// Ⱥ��
	} Group; // Ⱥ��Ϣ
	typedef std::vector<Group> GroupList; // Ⱥ�б�

	typedef struct {
		INT64	id;					// ������ID
		string	name;				// ����������(GB2312����)
		BYTES	nameBuffer;			// ����������(Utf-8����)
		INT32	createTimeStamp;	// ����ʱ���
		INT64	createUin;			// ������
		INT32	infoSeq;			// ��Ϣ����
		INT32	lastInfoTimeStamp;	// �����Ϣʱ���
		INT32	msgSeq;				// ��Ϣ����
		INT32	lastMsgTimeStamp;	// �����Ϣʱ���
		INT32	memberNum;			// ��Ա����
		INT32	flag;				// δ֪
		INT64	inheritOwnerUin;	// �̳д�����
		INT64	groupID;			// Ⱥ��
		INT64	groupTempID;		// ��ʱȺ��
		INT32	confMeetingOrigin;	// δ֪
		INT32	qidianConfType;		// δ֪
		INT32	confMeetingOption;	// δ֪
	} Discuss; // ��������Ϣ
	typedef std::vector<Discuss> DiscussList; // �������б�

	typedef struct {
		INT64	uin;					// QQ��
		string	nick;					// �ǳ�
		string	card;					// ��Ƭ
		INT32	sex;					// �Ա�0/�� 1/Ů 255/δ֪
		INT32	age;					// ����
		string	area;					// ����
		INT32	joinTimeStamp;			// ��Ⱥʱ��(ʱ���)
		INT32	lastSpeakTimeStamp;		// �����ʱ��(ʱ���)
		string	gLevelName;				// ����Ⱥ�ȼ�����
		INT32	permission;				// ����Ȩ�ޣ�1/��Ա 2/����Ա 3/Ⱥ��
		string	sTitle;					// ר��ͷ��
		INT32	sTitleValidPeriod;		// ר��ͷ����Ч��
		bool	isBadMember;			// �Ƿ�Ϊ������Ա
		bool	allowChangeCard;		// �����޸���Ƭ
	} GroupMember; // Ⱥ��Ա��Ϣ
	typedef std::vector<GroupMember> GroupMemberList; // Ⱥ��Ա�б�

	typedef struct {
		INT64	id;						// Ⱥ��
		INT64	ownerUin;				// Ⱥ��QQ
		INT32	createTimeStamp;		// ����ʱ��(ʱ���)
		INT32	memberNum;				// ȺĿǰ����
		INT32	maxMemberNum;			// Ⱥ��������
		string	name;					// Ⱥ����(GB2312����)
		BYTES	nameBuffer;				// Ⱥ����(UTF-8����)
		INT32	level;					// Ⱥ�ȼ�������Ⱥ�����Ի�ȡ���������������Ƿ���ʾ����ЩȺ�����������еȼ�Ҳ����ʾ
		string	introduction;			// Ⱥ����(GB2312����)
		BYTES	introductionBuffer;		// Ⱥ����(UTF-8����)
	} GroupInfo; // Ⱥ����

	typedef struct {
		INT64	uin;				// QQ��
		INT32	permission;		// Ȩ�ޣ�0/Ⱥ�� 1/����Ա
	} GroupAdmin; // Ⱥ����
	typedef std::vector<GroupAdmin> GroupAdminList; // Ⱥ�����б�

	typedef struct {
		INT64	uin;			// QQ��
		INT32	sex;			// �Ա�0/�� 1/Ů 2/δ֪
		string	nick;			// �ǳ�
		string	signature;		// ǩ��
		string	birthday;		// ���գ���ʽ����1990/12/12
		INT32	age;			// ���䣬-1Ϊδ֪
		INT32	level;			// QQ�ȼ�
		INT32	qAge;			// Q�䣬��PCQQЭ��֧�� -1/255 ��ʾ��ѯʧ��
		INT32	likeCount;		// ������
		INT32	isLike;			// �Ƿ���ޣ�0/���� 1/δ�ޣ�����׿QQЭ��֧��
	} QQSummaryInfo; // QQ��Ҫ����

	typedef struct {
		BYTES	token;				// �����û�Token
		string	card;				// �����û���Ƭ �硰����������
		INT64	headMark;			// �����û���ͷ���ʶ
		INT64	expireTimeStamp;	// �����û�����ʱ���
	} Anonymous; // ������Ϣ

	typedef struct {
		string	nick;		// �ǳ�		���ǳƱ�ʾû��Ⱥ�ǳ�	Nick��GCard���ܹ���
		string	gCard;		// Ⱥ�ǳ�	��Ⱥ�ǳƱ�ʾû���ǳ�	Nick��GCard���ܹ���
		INT32	level;		// Ⱥ���˵ȼ�
		INT32	flags;		// δ֪
		INT32	gLevel;		// Ⱥ�ȼ�
		string	sTitle;		// Ⱥͷ��
		INT32	MTID;		// δ֪
	} GroupAdditionalInfo; // ������Ϣ

	typedef struct {
		string	name;			// ����
		INT32	size;			// �ֺ�
		INT32	color;			// ��ɫ
		INT32	effect;			// ��ʽ 1/���� 2/б�� 4/�»���
		INT32	colorTextID;	// ����ID
	} Font; // ������Ϣ

	typedef struct {
		string	name;		// �ļ���
		string	id;			// �ļ�ID
		string	size;		// �ļ���С
		INT64	busID;		// ������������
		INT64	byteSize;	// �ļ���С����λ���ֽ�
	} File; // �ļ���Ϣ

	typedef struct {
		INT64 id;			// QQ��
		INT32 state = 0;	// ����״̬��0/���� 1/����
	} LoginQQ;
	typedef std::vector<LoginQQ> LoginQQList; // ��¼QQ�б�

};