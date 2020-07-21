// ��ģ�鹲�õ����Ͷ��壬ͨ�õĲ���䶯�Ļ�������
#pragma once;

#include <Windows.h>
#include <process.h>
#include <vector>
#include <string>
#include <map>
#include <tuple>

using std::vector;
using std::string;
using std::wstring;
using std::map;
using std::tuple;
using std::get;

// ���׺�����ڱ���ʱ�����Զ��徯��
#define STR2(x) #x  
#define STR(x)  STR2(x)  
#define MSG(desc) message(__FILE__ "(" STR(__LINE__) "): " #desc)
#pragma comment(lib, "ws2_32.lib")

// ���ƺ��̫�ྯ��
#pragma warning(disable:4002)

/* ���Ͷ��� */

// Window.h��Ӧ����������Ͷ���
typedef unsigned long long  QWORD;
typedef unsigned long long *PQWORD;

// ѭ�������ص�����
enum LoopEndType
{
	letFriInfo,
	letContact,
	letGroupMember,
};

// �û��˺����
enum UserType
{
	utPerson, // ��ͨ����
	utPublic, // ���ں�
	utGroup, // Ⱥ��
	utInGroup, // ͬ��һ��Ⱥ
	utSys,
};

// �Ա�
enum SexType
{
	stUnknow = 0,
	stMale = 1,   //��
	stFemale = 2, //Ů
};

// ΢������״̬/�¼�
enum StatusType
{
	stQuickLogin, // ���ٵ�½
	stScanQrcode, // ɨ���ά��
	stLogout, // �˳���¼
	stLogin, // ��½
	stDetach, // ����
	stNotRun, // δ����
	stNotLogin, // δ��¼
};

// ������Դ
enum FromType
{
	ftQQ = 1,
	ftSearchWXID = 3,
	ftMobileContact = 0xA,
	ftGroup = 0xE,
	ftSearchMobileNum = 0xF,
	ftCard = 0x11,
	ftNearby = 0x12,
	ftQrCode = 0x1E,
	ftFacebook = 0x1F,
};

// ��Ϣ����
enum MsgType
{
	mtText = 1, // �ı���Ϣ
	mtImage = 3, // ͼƬ
	mtAddFriend = 0x25, // �Ӻ���
	mtCard = 0x2a, // ��Ƭ
	mtsound = 0x22,  //����
	mtVideo = 0x2b, //��Ƶ
	mtLink = 0x31, // ���ӡ�ת�ˡ��ļ�
	mtFile = 0x31, // �ļ�
	mtlook = 0x2f, // ����
	mtGroupMemChange = 0x2710, // Ⱥ��Ա�䶯
				   // mtAt = -1, // Ⱥ@
};

typedef struct
{
	BOOL bAttach; // �Ƿ�Ϊ����ʱ����
	WCHAR szPath[MAX_PATH]; // HookDll����·��
	WCHAR wxdbPath[MAX_PATH];
}HookArg, *PHookArg;

/* Ϊ�˱��ּ����ԣ�������¼����ͱ���ӵײ���� */
// Hook�˷�����¼�����
enum EventType
{
	etDetach = 0,
	etInitComplete,
	etInitFail,
	etQuickLogin,
	etQrcode,
	etScanLogo,
	etScanUsername,
	etLogin,
	etLogout,
	etSend,
	etRecv,
	etFriInfo,
	etRunningStatus,
	etContact,
	etLoopEnd,
	etDBPW,
	etSelete,
	etFilterText,
	etGPid = 555,
};


enum SendMsgID
{
	emtext = 0,
	emimg,
	emfile,
	emcard,
	emgif,
	emattach,
};



enum RoomID
{
	setname = 0,
	setnick,
	sendNotice,
	sendcard,
};

/* Ϊ�˱��ּ����ԣ�������������ͱ���ӵײ���� */
// �൱��Ҫ�ĺ꣬��������ʱ�ǵ������������Ŀ
#define CommandMacro(Macro, ...)			\
	Macro(Detach, __VA_ARGS__)				\
	Macro(GetAllFriInfo, __VA_ARGS__)		\
	Macro(GetFriInfo, __VA_ARGS__) 			\
	Macro(GetGroupMember, __VA_ARGS__) 		\
	Macro(MaxWindow, __VA_ARGS__) 			\
	Macro(MinWindow, __VA_ARGS__) 			\
	Macro(CloseWindow, __VA_ARGS__) 		\
	Macro(RestoreWindow, __VA_ARGS__) 		\
	Macro(InviteToGroup, __VA_ARGS__) 		\
	Macro(SendGroupCard, __VA_ARGS__) 		\
	Macro(SetGroupNick, __VA_ARGS__) 		\
	Macro(SetGroupName, __VA_ARGS__) 		\
	Macro(SetGroupNotice, __VA_ARGS__) 		\
	Macro(DelGroupMember, __VA_ARGS__) 		\
	Macro(MultiFun, __VA_ARGS__) 		\
	Macro(CloseProxy, __VA_ARGS__) 			\
	Macro(EnableProxy, __VA_ARGS__) 		\
	Macro(ChangeRemark, __VA_ARGS__) 		\
	Macro(GetStatus, __VA_ARGS__) 			\
	Macro(CreateGroup, __VA_ARGS__) 		\
	Macro(AcceptFriend, __VA_ARGS__) 		\
	Macro(AddFriendviaGroup, __VA_ARGS__) 	\
	Macro(AddFriendviaCard, __VA_ARGS__) 	\
	Macro(GetContact, __VA_ARGS__) 			\
	Macro(SetRead, __VA_ARGS__) 			\
	Macro(Recall, __VA_ARGS__) 				\
	Macro(DeleteFriend, __VA_ARGS__) 		\
	Macro(SendText, __VA_ARGS__) 			\
	Macro(SendImage, __VA_ARGS__) 			\
	Macro(SendFile, __VA_ARGS__)	 		\
	Macro(SendCard, __VA_ARGS__) 			\
	Macro(SendLink, __VA_ARGS__)			\
	Macro(GetDBPW, __VA_ARGS__)				\
	Macro(Logout, __VA_ARGS__)				\
	Macro(SendGif, __VA_ARGS__)             \
	Macro(SetFilterText, __VA_ARGS__)       \
	Macro(AddContact, __VA_ARGS__)        \
	Macro(SetREText, __VA_ARGS__)    \
	Macro(ISfriends, __VA_ARGS__) 	\
	Macro(GetAllGroupMember, __VA_ARGS__)  \
	Macro(PayMents, __VA_ARGS__)  \
	Macro(OpenUrl, __VA_ARGS__)   \
	Macro(RelayFile, __VA_ARGS__)  \
	Macro(SendLook, __VA_ARGS__)   \
	Macro(RelayLook, __VA_ARGS__)  \
	Macro(ViaImFri, __VA_ARGS__)   \
	Macro(SetAllRead, __VA_ARGS__)  \
	Macro(ToFav, __VA_ARGS__)   \
	Macro(RelayProgram, __VA_ARGS__)  \
	Macro(SendProgram, __VA_ARGS__)  \
	Macro(RefreshQR, __VA_ARGS__) 





#define CommandTypeCreate(Name)	\
	ct##Name,
// Control�˷������������
enum CommandType
{
	CommandMacro(CommandTypeCreate)
};

// �û���Ϣ����
enum UserInfoType
{
	uitWXID = 0,
	uitUsername,
	uitRemark, // �����޶�
	uitUID,
	uitUIN,
	uitAddr1,
	uitAddr2,
	uitAddr3,
	uitPhone,
	uitLogo1, // Big
	uitLogo2, // Small
	uitSex, // δʵ��
	uitFrom, // δʵ��
	uitType, // ��������
	uitNick, // Ⱥ���ǳ�
	uitGroup, // ������Ⱥ
	uitMaster, // Ⱥ��wxid
	uitSum, // Ⱥ��Ա��
	uitPname, // ƴ��
};

// �û���Ϣ�ṹ��
typedef struct
{
	const wchar_t* pwWXID;
	const wchar_t* pwUID;
	const wchar_t* pwName;
	const wchar_t* pwRemark;
	unsigned int dwUIN;
	const wchar_t* pwAddr1;
	const wchar_t* pwAddr2;
	const wchar_t* pwAddr3;
	const wchar_t* pwPhone;
	const wchar_t* pwLogo1;
	const wchar_t* pwLogo2;
	SexType stSex;
	UserType utType;
	FromType ftFrom;
	const wchar_t* pwNick; // Ⱥ���ǳ�
	const wchar_t* pwGroup; // Ⱥ��������Ⱥ
	const wchar_t* pwMaster; // Ⱥ��
	unsigned int dwSum; // Ⱥ��Ա����
	const wchar_t* pPinName;// ƴ������
} UserInfo, *PUserInfo;


struct MyDisturb
{
	PVOID p1;
	DWORD *pVa;
};
// �����ͨ����
typedef vector< vector<byte> > DataList;
/* �������� */
// ģ�庯��������ʱ��չ����������
// ��ӡ�����ַ������DebugViewʹ��
template<typename... T>
void DbgLog(T... args);

// �����ָ�뻹��ָ���ָ��
template<typename T>
T TestPtr(T p);
wstring BV2W(const vector<byte> ba);
const wchar_t* BV2WC(vector<byte>& bv);
vector<byte> W2BV(const wstring ws);
vector<byte> W2BV(const wchar_t* pws);
vector<wstring> DL2WV(const DataList& dl);
vector<byte> I2BV(int i);
int BV2I(const vector<byte> bv);
vector<byte> L2BV(unsigned long long l);
unsigned long long BV2L(const vector<byte> bv);
int count(wstring ws1, wstring sw2);
vector<wstring> split(wstring source, wstring sep = L"^G", unsigned int maxsplit = -1);
BOOL WriteSocketHk(SOCKET sk, EventType t, DataList vvbDatas);//DataList �����úͶ���һ��, ����push��ַ
BOOL WriteSocket(SOCKET sk, CommandType t, DataList vvbDatas);
DataList ReadSocketHk(SOCKET& sk);
DataList ReadSocketCt(SOCKET& sk);
wstring stdformat(const wchar_t *fmt, ...);
string stdformat(const char *fmt, ...);
int stdReplace(string& strContent, const  char *pstrRe, const char *pstrDest);
int stdReplace(wstring& strContent, const  wchar_t *pstrRe, const wchar_t *pstrDest);
wstring UTF8216(const char* pwU8);
string  UTF1628(const wchar_t* psU16);
wstring mb2u16(const char *pbuf);
string  u162mb(const wchar_t *pbuf);
string mb2u8(const char* pbuf);
string u82mb(const char* pbuf);
void splitformat(wstring& out, const wchar_t*p1, const wchar_t* p2);
void splitformat(wstring& out, const wchar_t*p1, int p2);
void TimeLimit();
wstring GetPathName(const wchar_t *p);
SYSTEMTIME TimetToSystemTime(time_t t);

vector<wstring> Format2V(wstring str, const wchar_t *pfen);

wstring substr1(const wchar_t *pdata, const wchar_t *p1, const wchar_t *p2);
wstring substr2(const wchar_t *pdata, const wchar_t *p1);




#define SocketPort 9963
#define SIZEHK 1024*10
#define SIZECT 1024*10
#define SIZEMAX 10240+300


