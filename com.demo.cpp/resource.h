//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ ���ɵİ����ļ���
// �� com.demo.cpp.rc ʹ��
//
#define IDR_JSON1                       101

// Next default values for new objects
// 
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
#define _APS_NEXT_RESOURCE_VALUE        102
#define _APS_NEXT_COMMAND_VALUE         40001
#define _APS_NEXT_CONTROL_VALUE         1001
#define _APS_NEXT_SYMED_VALUE           101
#endif
#endif

/*
	���¶��ǻ�ȡ��Դ�ļ�����
	��W����Unicode���õ�
	LPCSTR�Ǵ�����ͨ�ַ���ʱ����
	LPCWSTR�Ǵ�����ַ���ʱ����
	GetResourceFileData���ĸ�����������õĺ�������
*/
const char * GetResourceFileW(LPCSTR lpType, int lpName);

const char * GetResourceFileW(LPCWSTR lpType, int lpName);

const char * GetResourceFileA(LPCWSTR lpType, int lpName);

const char * GetResourceFileA(LPCSTR lpType, int lpName);

const char * GetResourceFileData(HMODULE hModule, HRSRC hRsrc);

#ifdef UNICODE
#define GetResourceFile  GetResourceFileW
#else
#define GetResourceFile  GetResourceFileA
#endif // !UNICODE
