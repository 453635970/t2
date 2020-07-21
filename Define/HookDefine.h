// ֻ��Hook�˲��õõ��ı�������
#include <Windows.h>
#include "../Define/Define.h"
#pragma comment(lib, "version.lib")


/*
	�꺯��
	���ֺ�����Ҫ��λ�ö���
*/

// ��ʼ��΢�ź���ָ��
#define Setpwxf(Name, Offset)	\
	pp->pwxf##Name = (ft##Name)((DWORD)pBase + Offset)
// ��ʼ��΢������ָ��
#define Setpwx(Name, Type, Offset)	\
	pp->pwx##Name = (Type)((DWORD)pBase + Offset)
#define SetNULL(Name)			\
	pp->pwxf##Name = NULL;
// Hook����������
#define HookHandlerCreate(Name)		\
	PVOID hh##Name(PVOID pArg);
// �����������
#define CommandHandlerCreate(Name)	\
	VOID ch##Name(const DataList& dl);
// �趨Hook��������������
#define SetHookHandler(Name, HandleType, phh)	\
	phh->hhc##Name.ht = HandleType;	\
	phh->hhc##Name.fthh = hh##Name;
// �趨�������
#define SetCommandHandler(Name, pch)	\
	pch[ct##Name] = ch##Name;
// ������Ҫ��΢�ź���ָ��
#define StoreFuncPtr(Name, pp)				\
	pwxf##Name = pp->##pwxf##Name;
// ������Ҫ��΢������ָ��
#define StoreDataPtr(Name, Type, pp)				\
	pwx##Name = pp->##pwx##Name;
// �൱��Ҫ�ĺ꣬����Hookʱ�ǵ������������Ŀ
#define HookFuncMacro(Macro, ...)		\
	Macro(InitLoginWin, __VA_ARGS__)	\
	Macro(GetQrcode, __VA_ARGS__)		\
	Macro(AfterScan, __VA_ARGS__)		\
	Macro(ScanUserData, __VA_ARGS__)	\
	Macro(ChatView, __VA_ARGS__)		\
	Macro(_ChatView, __VA_ARGS__)		\
	Macro(MutexCheck, __VA_ARGS__)		\
	Macro(OnRecv, __VA_ARGS__)			\
	Macro(OnSend, __VA_ARGS__)		    \
	Macro(OnSelect, __VA_ARGS__)        \
	Macro(OnCaseText, __VA_ARGS__)      \
	Macro(OnShadeWnd, __VA_ARGS__)    \
	Macro(OnNcHit, __VA_ARGS__)      \
	Macro(OnTrayClick, __VA_ARGS__)  \
	Macro(IsFriendCall, __VA_ARGS__)  \
	Macro(AutoDlImg, __VA_ARGS__)   \
	Macro(AutoDlVideo, __VA_ARGS__)   \
	Macro(DelFriend, __VA_ARGS__)   \
	Macro(RoamMsg, __VA_ARGS__)  \
	Macro(Monitor1, __VA_ARGS__)  \
	Macro(GetImgSid, __VA_ARGS__)  \
	Macro(GetImgFile, __VA_ARGS__)  \
	Macro(GetVoice, __VA_ARGS__) \
	Macro(Dtray, __VA_ARGS__)    \
	Macro(DtrayHide, __VA_ARGS__)  \
	Macro(DumpGif, __VA_ARGS__)   \
	Macro(OnUrlKey, __VA_ARGS__)  \
    Macro(MonRemark, __VA_ARGS__)






// ΢�ź���ָ���
#define WXFuncMacro(Macro, ...)		\
	Macro(InitLoginWin, __VA_ARGS__)		\
	Macro(GetQrcode, __VA_ARGS__)		\
	Macro(AfterScan, __VA_ARGS__)		\
	Macro(ScanUserData, __VA_ARGS__)		\
	Macro(SetRichEditText, __VA_ARGS__)		\
	Macro(GetRichEditText, __VA_ARGS__)		\
	Macro(SetEditText, __VA_ARGS__)		\
	Macro(GetEditText, __VA_ARGS__)		\
	Macro(EnableProxy, __VA_ARGS__)		\
	Macro(ProxyNotify, __VA_ARGS__)		\
	Macro(TopRightNotify, __VA_ARGS__)		\
	Macro(RestoreWindow, __VA_ARGS__)		\
	Macro(ChatOnTop, __VA_ARGS__)		\
	Macro(MuteMessage, __VA_ARGS__)		\
	Macro(GetFriInfo, __VA_ARGS__)		\
	Macro(FreeFriInfo, __VA_ARGS__)		\
	Macro(GetGroupInfo, __VA_ARGS__)		\
	Macro(InviteToGroup, __VA_ARGS__)		\
	Macro(SendGroupCard, __VA_ARGS__)		\
	Macro(DelGroupMember, __VA_ARGS__)		\
	Macro(ChatView, __VA_ARGS__)		\
	Macro(_ChatView, __VA_ARGS__)		\
	Macro(ChangeRemark, __VA_ARGS__)		\
	Macro(MutexCheck, __VA_ARGS__)		\
	Macro(SetTalker, __VA_ARGS__)		\
	Macro(SetGroupNick, __VA_ARGS__)		\
	Macro(SetGroupName, __VA_ARGS__)		\
	Macro(SetGroupNotice, __VA_ARGS__)		\
	Macro(CreateGroup, __VA_ARGS__)		\
	Macro(AcceptFriend, __VA_ARGS__)		\
	Macro(SendTextMsg, __VA_ARGS__)		\
	Macro(DBPassword, __VA_ARGS__)		\
	Macro(OnRecv, __VA_ARGS__)		    \
	Macro(GetExtraInfo, __VA_ARGS__)	\
	Macro(FreeMsg, __VA_ARGS__)			\
	Macro(SendImage, __VA_ARGS__)		\
	Macro(SendFile, __VA_ARGS__)		\
	Macro(SendFileArg, __VA_ARGS__)		\
	Macro(GetContact1, __VA_ARGS__)		\
	Macro(GetContact2, __VA_ARGS__)		\
	Macro(SetRead, __VA_ARGS__)			\
	Macro(SendLink, __VA_ARGS__)		\
	Macro(OnSend, __VA_ARGS__)			\
	Macro(GetFriLogo, __VA_ARGS__)		\
	Macro(Recall, __VA_ARGS__)			\
	Macro(AddTask, __VA_ARGS__)			\
	Macro(AddTaskArg, __VA_ARGS__)		\
	Macro(FormatCard, __VA_ARGS__)		\
	Macro(SendGif, __VA_ARGS__)         \
	Macro(OnSelect, __VA_ARGS__)		 \
	Macro(OnCaseText, __VA_ARGS__)       \
	Macro(OnShadeWnd, __VA_ARGS__)       \
	Macro(SendImagePara1, __VA_ARGS__)   \
	Macro(OnNcHit, __VA_ARGS__)     \
	Macro(AddContact, __VA_ARGS__)     \
	Macro(OnTrayClick, __VA_ARGS__)   \
	Macro(AddFriReady, __VA_ARGS__)  \
	Macro(Getest1, __VA_ARGS__)   \
	Macro(IsFriendCall, __VA_ARGS__)   \
	Macro(GetIMInfo1, __VA_ARGS__)	\
	Macro(GetIMInfo2, __VA_ARGS__)   \
	Macro(SetDisturb, __VA_ARGS__)   \
	Macro(SaveInLlist, __VA_ARGS__)   \
	Macro(QuitGroupParam1, __VA_ARGS__)  \
	Macro(QuitGroupParam6, __VA_ARGS__)   \
	Macro(QuitGroup, __VA_ARGS__)   \
	Macro(GetFriBlock, __VA_ARGS__)   \
	Macro(IsDisturb, __VA_ARGS__)    \
	Macro(IsChatOnTop, __VA_ARGS__)  \
	Macro(DelFriend, __VA_ARGS__)   \
	Macro(AutoDlImg, __VA_ARGS__)   \
	Macro(AutoDlVideo, __VA_ARGS__)   \
	Macro(GetImgB1, __VA_ARGS__)   \
	Macro(GetImgB2, __VA_ARGS__)   \
	Macro(RoamMsg, __VA_ARGS__)  \
	Macro(Monitor1, __VA_ARGS__)  \
	Macro(GetImgSid, __VA_ARGS__)  \
	Macro(GetImgFile, __VA_ARGS__) \
	Macro(GetVoice, __VA_ARGS__)   \
	Macro(Dtray, __VA_ARGS__)   \
	Macro(DtrayHide, __VA_ARGS__) \
	Macro(GetGinfo, __VA_ARGS__)   \
    Macro(DumpGif, __VA_ARGS__)    \
	Macro(PayMents, __VA_ARGS__)  \
	Macro(OpenUrl, __VA_ARGS__)   \
	Macro(OnUrlKey, __VA_ARGS__)   \
	Macro(SendLook, __VA_ARGS__)   \
	Macro(RelayFile, __VA_ARGS__)  \
	Macro(RelayLook, __VA_ARGS__)  \
	Macro(SetReadAll, __VA_ARGS__)  \
	Macro(ViaImFriendArg, __VA_ARGS__)  \
	Macro(ViaImFriend, __VA_ARGS__)   \
	Macro(ToFav, __VA_ARGS__)  \
	Macro(AddTag, __VA_ARGS__)   \
	Macro(MsgView, __VA_ARGS__)   \
    Macro(RelayProgram, __VA_ARGS__)  \
    Macro(SendProgram, __VA_ARGS__) \
	Macro(ControlVisible, __VA_ARGS__)   \
	Macro(RefreshQR, __VA_ARGS__)  \
	Macro(MonRemark, __VA_ARGS__)








	


// ΢������ָ���
#define WXDataMacro(Macro, ...)		\
	Macro(WXID, PSTR*, __VA_ARGS__)		\
	Macro(Username, PSTR, __VA_ARGS__)		\
	Macro(UIN, PDWORD, __VA_ARGS__)		\
	Macro(Sex, SexType*, __VA_ARGS__)		\
	Macro(Phone, PSTR, __VA_ARGS__)		\
	Macro(Addr1, PSTR, __VA_ARGS__)		\
	Macro(Addr2, PSTR, __VA_ARGS__)		\
	Macro(Addr3, PSTR, __VA_ARGS__)		\
	Macro(Logo, PSTR*, __VA_ARGS__)		\
	Macro(UID, PSTR, __VA_ARGS__)		\
	Macro(Heap, PHANDLE, __VA_ARGS__)		\
	Macro(Friend, PVOID, __VA_ARGS__)		\
	Macro(InviteArg, PVOID, __VA_ARGS__)		\
	Macro(CreateGroupArg, PVOID, __VA_ARGS__)		\
	Macro(AcceptFriendArg, PVOID*, __VA_ARGS__)		\
	Macro(UserData, PVOID*, __VA_ARGS__)		\
	Macro(SetReadArg, PVOID, __VA_ARGS__)		\
	Macro(SendLinkArg, PVOID, __VA_ARGS__)		\
	Macro(DBPW, PBYTE*, __VA_ARGS__)			\
	Macro(DelGroupMemberArg, PVOID, __VA_ARGS__)  \
	Macro(WxPath, PSTR*, __VA_ARGS__)  \
    Macro(RefreshQRArg, PVOID, __VA_ARGS__)	 \
	Macro(SendLookArg, PVOID, __VA_ARGS__)	 \
	Macro(RelayArg, PVOID, __VA_ARGS__)  \
	Macro(Cefobj, PVOID, __VA_ARGS__)


/* 
	�������Ͷ��� 
*/

// ��Ҫ����α���¼�������(ģ��DuiLib::CString)
typedef struct
{
	PWSTR pwName;
	WCHAR szName[100]; // ��������������д��
					   // ��εĳ���Ӧ���Ƕ�̬�����
}*FakeNotifyString;

// ����α����¼���������
typedef FakeNotifyString(__fastcall* FakeFunc)(PVOID, DWORD, FakeNotifyString);

// α���Notify��������
typedef struct
{
	/* +   0 */ PWSTR pwType; // �¼�����ָ��
	/* +   4 */ WCHAR szType[16]; //�¼����ͣ��ӦΪ14�ַ�������β���ַ�)�����ֶ���
	/* +  24 */ CHAR _1[96]; // ��������ƫ����
	/* +  84 */ PVOID pFakeVTable; // ָ��α���������ڶԽ�ʡ�ռ�Ŀ��ǣ�ֱ��ָ���Լ��Ϳ�����
	/* +  88 */ FakeFunc pFakeFunc; // ����еĵڶ�������������Object������
	/* +  8C */ PWSTR pFakeName; // ָ�������ĸ��ַ���
	/* +  90 */ WCHAR szFakeName[60]; // α�������
	/* + 108 */ PVOID pFakeObject; // ָ��α���object��Ҳ����ָ��pFakeVTable�Ϳ�����
}FakeNotify, *PFakeNotify;

// ΢���й㷺ʹ�õ��ַ�����
typedef struct
{
	const wchar_t* pwStr;
	SIZE_T stLen;
	SIZE_T stMax;
	DWORD dwZero1;
	DWORD dwZero2;
}FakeString, *PFakeString;


typedef struct
{
	DWORD dwx1;
	DWORD dwx2;
	const wchar_t* pwStr;
	SIZE_T stLen;
	SIZE_T stMax;
	DWORD dwZero1;
	DWORD dwZero2;
}FakeString2, *PFakeString2;

// ���˺��ѡ����ں�ʹ�õ���������
typedef struct _LinkList
{
	struct _LinkList* pNext;
	struct _LinkList* pPre;
	const wchar_t** pWXID;
}LinkList, *PLinkList;

// Ⱥ��ʹ�õ�ƽ�����������
typedef struct _BinTree
{
	struct _BinTree* pLeft; // ��(С)
	struct _BinTree* pParent; // ��
	struct _BinTree* pRight; // ��(��)
	char _1; // ռλ
	char bEnd; // �Ƿ���ֹ
	char _2[2]; // ռλ
	const wchar_t* pwWXID;
}BinTree, *PBinTree;

// ��������ʱʹ�õĽṹ��
typedef struct
{
	FakeString fsTitle;
	FakeString fsURL;
	BYTE _1[0x2c];
	FakeString fsImage;
	BYTE _2[0x14];
	FakeString fsDesc;
	BYTE _3[0x80];
}FakeLink, *PFakeLink;




// ΢�ź�����Ϣ
typedef struct
{
	/* 0 */ DWORD _1[2];
	/* 8 */ FakeString fsWXID;
	/* 1C */ FakeString fsUID;
	/* 30 */ FakeString fsV1;
	/* 44 */ DWORD _3;
	/* 48 */ DWORD dwUserType1; // 0: Sys; 2: Group; 3: Normal or public.
	/* 4c */ DWORD dwUserType2; // 0: Normal or Group or Sys; 18: Public
	/* 50 */ FakeString fsRemark;
	/* 64 */ FakeString fsUsername;
	/* 78 */ FakeString _5;
	/* 8C */ DWORD _6[6];
	/* A4 */ FakeString fsPUsername;
	/* B8 */ FakeString fspUsername;
	/* CC */ FakeString fsPRemark;
	/* E0 */ FakeString fspRemark;
	/* F4 */ FakeString fsLogo1;
	/* 108 */ FakeString fsLogo2;
	/* 11C */ DWORD _7[16];
	/* 15C */ SexType stSex;       
	/* 160 */ BYTE _8[0x34];
	/* 194 */ FakeString fsWP;  //ǩ��
	/* 1A8 */ FakeString fsAddr1;   
	/* 1BC */ FakeString fsAddr2;   
	/* 1D0 */ FakeString fsAddr3;   
	/* 1E4 */ FromType ftFrom;   
	/* 1E8 */ DWORD _9[200];
} FakeUserInfo, *PFakeUserInfo;

/*-------------------------΢��2.7.1.82����ǰ-----------------------------------------------------------------------*/
//typedef struct
//{
//	/* 0 */ byte _1[40];
//	/* 28 */
//	union
//	{
//		struct { DWORD dwSrvIDL; DWORD dwSrvIDH; } dwSrvID;
//		QWORD qwSrvID;
//	} SrvID;
//	/* 30 */ MsgType mtType;
//	/* 34 */ DWORD dwIsSend; // 0: Recv; 1: Send
//	/* 38 */ DWORD dwIsDl; // 1: Upload; 2: Download
//	/* 3C */ DWORD dwTime;
//	/* 40 */ FakeString fsTalker;
//	/* 54 */ DWORD _3[5];
//	/* 68 */ FakeString fsContent;
//	/* 7C */ BYTE _7[8];
//	/* 84 */ FakeString fsimgpath;
//	/* 98 */ BYTE _4[124];
//	/* 114 */ FakeString fsSenderInGroup; 
//	/* 128 */ FakeString fsLocalID;
//	/* 13C */ FakeString fsThumb; // ����ͼ
//	/* 150 */ FakeString fsOrigin; // ԭ�ļ�
//	/* 164 */ DWORD _5;
//	/* 168 */ FakeString fsAtlist; //at���б�
//	          DWORD _6[100];
//	/* and more */
//} FakeMsg, *PFakeMsg;
/*-------------------------΢��2.7.1.82-----------------------------------------------------------------------*/






/*-------------------------΢��2.8.0.133��ʼ-----------------------------------------------------------------------*/
typedef struct
{
	/* 0 */ byte _1[40];
	/* 28 */
	union
	{
		struct { DWORD dwSrvIDL; DWORD dwSrvIDH; } dwSrvID;
		QWORD qwSrvID;
	} SrvID;
	/* 30 */ MsgType mtType;
	/* 34 */ DWORD dwIsSend; // 0: Recv; 1: Send
	/* 38 */ DWORD dwIsDl; // 1: Upload; 2: Download
	/* 3C */ DWORD dwTime;
	/* 40 */ FakeString fsTalker;
	/* 54 */ DWORD _3[5];
	/* 68 */ FakeString fsContent;
	/* 7C */ BYTE _7[8];
	/* 84 */ FakeString fsimgpath;
	/* 98 */ BYTE _4[148];
	/* 12C */ FakeString fsSenderInGroup;
	/* 140 */ FakeString fsLocalID;
	/* 154 */ FakeString fsThumb; // ����ͼ
	/* 168 */ FakeString fsOrigin; // ԭ�ļ�
	/* 17c */ DWORD _5;
	/* 180 */ FakeString fsAtlist; //at���б�
	DWORD _6[100];
	/* and more */
} FakeMsg, *PFakeMsg;
/*-------------------------΢��2.8.0.133-----------------------------------------------------------------------*/

//124
enum InfoType
{
	itWXID = 0,
	itUsername,
	itRemark, // �����޶�
	itUID,
	itUIN,
	itAddr1,
	itAddr2,
	itAddr3,
	itPhone,
	itLogo1, // Big
	itLogo2, // Small
	itSex, // δʵ��
	itFrom, // δʵ��
	itType, // ��������
	itNick, // Ⱥ���ǳ�
	itGroup, // ������Ⱥ
	itMaster, // Ⱥ��wxid
	itSum, // Ⱥ��Ա��
	itPname, // ƴ��
	itSignname, //ǩ��
	itType1, // ��������1
};

/* 
	΢�ŵĺ������Ͷ����Լ�����Hook�Ĳ��� 
*/

/* 
	��ҪHook��
*/

// ��ʼ����½����
typedef PVOID(__fastcall*ftInitLoginWin)(PVOID, DWORD, PVOID);
/* ���ô˺����󼴿ɶ�ȡ���ٵ�½��Ϣ */

typedef PVOID(__fastcall*ftGetQrcode)(PVOID, DWORD, PVOID);
typedef PVOID(__fastcall*ftRefreshQR)(PVOID, DWORD);


/* ���ƶ�ά�����ӷ���һ�ξ�ʧЧ�ˣ�����ֱ�ӷ���ͼƬ�Ķ�������Ϣ */
// ��ά��ɨ�����
typedef PVOID(__fastcall*ftAfterScan)(PVOID, DWORD, PVOID);
// ɨ����ɺ�˺����������Σ���һ�λ�ȡͷ�����ӣ��ڶ������û���
// AfterScan���ú����ô�Hook���������κ���ȡ��
typedef PWSTR*(__fastcall*ftScanUserData)(PVOID, DWORD, PVOID, PVOID);
// ExtendChatView����¼����Ҫ�Ľ��棬��Ϊ��½�ɹ��ı�־
typedef PVOID(__fastcall*ftChatView)(PVOID, DWORD);
// ExtendChatView��������������ţ�����ΪLogout�ı�־
typedef PVOID(__fastcall*ft_ChatView)(PVOID, DWORD);
// �࿪�жϣ���Ҫ�࿪�ͷ���FALSE����
typedef PVOID(__stdcall*ftMutexCheck)();
// ���ݿ���Կ
typedef PVOID(__stdcall*ftDBPassword)(PVOID, PVOID, PBYTE);
// ������Ϣ
typedef PVOID(__fastcall*ftOnRecv)(PVOID, DWORD);
// �ϴ���Ϣ
typedef PVOID(__stdcall*ftOnSend)(DWORD, PVOID);
typedef PVOID(__fastcall*ftOnSelect)(PVOID, DWORD, PVOID, DWORD);
typedef PVOID(__fastcall*ftOnFilterText)(PVOID, PVOID);
typedef PVOID(__fastcall*ftOnCaseText)(PVOID, PVOID, PVOID);
typedef PVOID(__fastcall*ftOnTrayClick)(PVOID, PVOID, PVOID, PVOID, PVOID,PVOID, PVOID);
typedef PVOID(__fastcall*ftIsFriendCall)(PVOID, PVOID, PVOID, PVOID, PVOID, PVOID, PVOID, PVOID, PVOID, PVOID, PVOID, PVOID);
typedef PVOID(__fastcall*ftGetImgSid)(PVOID, PVOID, PVOID, PVOID);
typedef PVOID(__fastcall*ftGetImgFile)(PVOID, PVOID);
typedef PVOID(__fastcall*ftGetVoice)(PVOID, PVOID, PVOID, PVOID, PVOID, PVOID);

//ȥ��Ӱ
typedef PVOID (__fastcall*ftOnShadeWnd)(PVOID, PVOID, PVOID);
//��ֹ�ƶ�
typedef PVOID (__fastcall*ftOnNcHit)(PVOID, PVOID, PVOID, PVOID, PVOID, PVOID);

typedef PVOID(__fastcall*ftDtray)(PVOID, PVOID);

typedef PVOID(__fastcall*ftDtrayHide)(PVOID, PVOID);


typedef PVOID(__fastcall*ftDumpGif)(PVOID, PVOID, PVOID);

typedef PVOID(__fastcall*ftOnUrlKey)(PVOID, PVOID, PVOID, PVOID, PVOID, PVOID, PVOID);




typedef struct
{
	PWSTR pwName;
	WCHAR szName[5]; 
}*FakeString1;



typedef bool(__fastcall*ftControlVisible)(PVOID, DWORD);

// ���ø��ı�����
//typedef VOID(__fastcall*ftSetRichEditText)(PVOID, DWORD, PVOID);

typedef VOID(__fastcall*ftSetRichEditText)(PVOID, DWORD, PVOID, PVOID);
// ��ȡ���ı�����
typedef FakeString1(__fastcall*ftGetRichEditText)(PVOID, DWORD, PVOID);
//typedef VOID(__fastcall*ftAddFriReady)(PVOID, PVOID, PVOID, PVOID, PVOID, PVOID, PVOID, PVOID, DWORD, DWORD, PVOID, PVOID, DWORD, DWORD);
typedef VOID(__stdcall*ftAddFriReady)();

typedef VOID(__fastcall*ftGetest1)(PVOID, PVOID, PVOID, PVOID);

// �������������
typedef VOID(__fastcall*ftSetEditText)(PVOID, DWORD, const wchar_t*);
// ��ȡ���������
typedef FakeString(__fastcall*ftGetEditText)(PVOID, DWORD);
// ���ô���
typedef PVOID(__fastcall*ftEnableProxy)(PVOID, DWORD);
// Notifyͨ�ø�ʽ
typedef PVOID(__fastcall*ftNotify)(PVOID, DWORD, PFakeNotify);
// �������ý���
typedef ftNotify ftProxyNotify;
// ���Ͻǰ�ť
typedef ftNotify ftTopRightNotify;
// �ָ�����
typedef VOID(__fastcall*ftRestoreWindow)(PVOID, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
// �趨�Ի���
typedef VOID(__fastcall*ftSetTalker)(PVOID, DWORD, PVOID, DWORD);
// �ö����죨�Ƿ��ö���
typedef VOID(__stdcall*ftChatOnTop)(PVOID, BOOL);
// ���Σ��Ƿ������Ϣ��
typedef VOID(__stdcall*ftMuteMessage)(PVOID, BOOL);
// ͨ��WXID��ȡȨ���ڵ�������Ϣ
typedef VOID(__stdcall*ftGetFriInfo)(const wchar_t*, SIZE_T, DWORD, DWORD, DWORD, PFakeUserInfo);
// Free������Ϣ���ַ���ʱ�ŵ����ϵ�
typedef VOID(__fastcall*ftFreeFriInfo)(PFakeUserInfo, DWORD);
// ��ȡȺ��Ϣ
typedef PVOID(__stdcall*ftGetGroupInfo)();
// ������Ⱥ(<40��Ⱥ)
typedef VOID(__fastcall*ftInviteToGroup)(PVOID, DWORD, PFakeString*, const wchar_t*, SIZE_T, SIZE_T, DWORD, DWORD);
// ����Ⱥ��Ϣ��������Ⱥ(>40��)��
typedef VOID(__fastcall*ftSendGroupCard)(PVOID, DWORD, PFakeString*, const wchar_t*, SIZE_T, SIZE_T, DWORD, DWORD);
// ɾ��ȺԱ
typedef VOID(__fastcall*ftDelGroupMember)(PVOID, DWORD, PFakeString*, const wchar_t*, SIZE_T, SIZE_T, DWORD, DWORD);
// �޸�Ⱥ�ǳ�
typedef VOID(__stdcall*ftSetGroupNick)(const wchar_t*, SIZE_T, SIZE_T, DWORD, DWORD, const wchar_t*, SIZE_T, SIZE_T, DWORD, DWORD, const wchar_t*, SIZE_T, SIZE_T, DWORD, DWORD);
// �޸�Ⱥ��
typedef void(__fastcall*ftSetGroupName)(PFakeString, PFakeString);
// Ⱥ���棨Ҫ�����Ȩ�ޣ�
typedef void(__stdcall*ftSetGroupNotice)(PFakeString*);
// �޸ı�ע
typedef VOID(__stdcall*ftChangeRemark)(PFakeUserInfo, DWORD);
// ����Ⱥ
typedef VOID(__fastcall*ftCreateGroup)(PVOID, DWORD, PVOID, DWORD, PVOID, DWORD, DWORD, DWORD);
// ͬ��Ӻ���
typedef VOID(__fastcall*ftAcceptFriend)(PVOID, DWORD, PVOID, SIZE_T, SIZE_T, DWORD, DWORD, DWORD, PVOID, DWORD, DWORD, PVOID, PVOID, PVOID, PVOID,
	PVOID, PVOID, PVOID, DWORD, DWORD, PVOID, PVOID, PVOID, PVOID, PVOID, PVOID);

// ���ͻ����ı�����Ϣ
//typedef VOID(__stdcall*ftSendTextMsg)(PFakeMsg, PVOID, PVOID, PFakeString[3], MsgType);
typedef VOID(__stdcall*ftSendTextMsg)();

// ��ȡ���������Ϣ
typedef VOID(__fastcall*ftGetExtraInfo)(PFakeUserInfo, DWORD);
// �ͷŷ�����Ϣ��ִ��Դ
typedef VOID(__fastcall*ftFreeMsg)(PFakeMsg, DWORD);


// ����ͼƬ
typedef VOID(__fastcall*ftSendImage)(PVOID, PVOID, PFakeMsg, PFakeString, PFakeString);
typedef PVOID(__cdecl *ftSendImagePara1)(PVOID);





// �����ļ�
#define ftSendFile PVOID
// typedef PVOID ftSendFile;
// typedef VOID(__fastcall*ftSendFile)(PVOID, DWORD, PVOID, const wchar_t*, SIZE_T, SIZE_T, DWORD, DWORD, const wchar_t*, SIZE_T, SIZE_T, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
// 
typedef PVOID(__stdcall*ftSendFileArg)();
//��ȡ�����ϵ��
typedef PVOID(__stdcall*ftGetContact1)();
typedef PWSTR**(__fastcall*ftGetContact2)(PVOID, DWORD);
// ����
typedef VOID(__stdcall*ftRecall)(PFakeMsg);
// ����ͷ����Ϣ
typedef VOID(__fastcall*ftGetFriLogo)(PFakeUserInfo, DWORD, PFakeString);
// ����������Ϣ
typedef VOID(__fastcall*ftSendLink)(PVOID, DWORD, PFakeMsg, const wchar_t*, SIZE_T, SIZE_T, DWORD, DWORD, PFakeLink);
// ����Ѷ�
typedef VOID(__fastcall*ftSetRead)(PVOID _this, DWORD NOUSE, PFakeString pfiWXID, PDWORD arg1, DWORD arg2);
// �����һ��Ϣ���е����񣬵�ǰֻ����ʵ��logout
typedef PVOID(*ftAddTaskArg)();
typedef VOID(__fastcall*ftAddTask)(PVOID _this, DWORD NOUSE, DWORD, DWORD, DWORD, DWORD);
// ��ʽ����Ƭ��Ϣ
typedef VOID(__fastcall*ftFormatCard)(PFakeString, PFakeUserInfo);
//����GIFͼƬ
typedef VOID(__stdcall*ftSendGif)(PVOID, DWORD, DWORD, DWORD, DWORD, PVOID, DWORD, DWORD, DWORD, DWORD, PVOID, DWORD
	, DWORD, DWORD, DWORD, DWORD, PVOID, PVOID, PVOID, PVOID, PVOID, PVOID);
//�����ϵ��,������,����ȥ���ˣ�û�õ�
typedef VOID(__fastcall*ftAddContact)(PVOID, PVOID, PVOID);
//��ȡ��ҵ΢��Ⱥ��Ա
typedef int(__fastcall*ftGetIMInfo1)(PVOID, PVOID);
typedef int(__fastcall*ftGetIMInfo2)(PVOID, PVOID, PVOID, PVOID);

//��Ϣ�����
typedef VOID(__stdcall*ftSetDisturb)(PVOID, BOOL);
//���浽ͨѶ¼
typedef VOID(__stdcall*ftSaveInLlist)(PVOID, DWORD, DWORD, DWORD, DWORD,PVOID, DWORD, DWORD, DWORD, DWORD, BOOL);

//��Ⱥ
typedef PVOID(__fastcall*ftQuitGroupParam6)(PVOID, PVOID, PVOID);//����6
typedef PVOID(__stdcall*ftQuitGroupParam1)();//����1
typedef PVOID(__fastcall*ftQuitGroup)(PVOID, PVOID, DWORD, PVOID, PVOID, PVOID);//�����ܺ���
typedef PVOID(__stdcall*ftGetFriBlock)(PVOID, PVOID);

typedef PVOID(__cdecl * ftPayMents)(PVOID, DWORD, DWORD, DWORD, DWORD, PVOID, DWORD, DWORD, DWORD, DWORD, PVOID, PVOID);
typedef PVOID(__fastcall * ftOpenUrl)(PVOID, PVOID);//���붨���__fastcall, ʵ����__cdecl


typedef PVOID(__fastcall * ftSetReadAll)(PVOID, PVOID);

typedef PVOID(__stdcall * ftViaImFriendArg)();
typedef PVOID(__fastcall * ftViaImFriend)(PVOID, PVOID, PVOID, PVOID);


typedef BOOL(__fastcall*ftIsDisturb)(PVOID, PVOID);//��Ϣ������Ƿ���
typedef BOOL(__stdcall* ftIsChatOnTop)(PVOID);//��Ϣ�ö��Ƿ���

typedef PVOID(__stdcall* ftDelFriend)(PVOID, PVOID);

typedef PVOID(__fastcall*ftAutoDlImg)(PVOID, PVOID);
typedef PVOID(__fastcall*ftAutoDlVideo)(PVOID, PVOID);

//Ⱥ��Ա�䶯 ʵʱ���
typedef PVOID(__fastcall*ftMonitor1)(PVOID, PVOID);
typedef PVOID(__fastcall*ftMonRemark)(PVOID, PVOID, PVOID, PVOID);


//������Ϣ
typedef PVOID(__fastcall*ftRoamMsg)(PVOID, PVOID, PVOID, PVOID, PVOID, PVOID);
//��ȡ��ҵ΢��Ⱥ��Ա
typedef PVOID(__stdcall*ftGetImgB1)();
typedef PVOID(__fastcall*ftGetImgB2)(PVOID, PVOID, PVOID, PVOID, PVOID);
typedef PVOID(__stdcall*ftGetGinfo)();


//�ļ�ת��
typedef PVOID(__fastcall * ftRelayFile)(PVOID, PVOID, PVOID, PVOID);
//����ת��
typedef PVOID(__fastcall * ftRelayLook)(PVOID, PVOID);
//С����ת��
typedef PVOID(__fastcall * ftRelayProgram)(PVOID, PVOID, PVOID, PVOID);
//���ͱ���
typedef PVOID(__fastcall * ftSendLook)(PVOID, PVOID, PVOID, PVOID, PVOID);
//��С����
typedef PVOID(__stdcall * ftSendProgram)(PVOID, DWORD, DWORD, PVOID, PVOID, PVOID, PVOID, PVOID, DWORD, DWORD, DWORD, DWORD);

//��ӵ��ղ�
typedef PVOID(__stdcall*ftToFav)(PVOID);

//��ӱ�ǩ
typedef PVOID(__fastcall * ftAddTag)(PVOID, PVOID, PVOID);


typedef PVOID(__stdcall * ftMsgView)();




#define WXFuncCreate(Name)		\
	ft##Name pwxf##Name;
#define WXDataCreate(Name, Type)	\
	Type pwx##Name;
typedef struct
{

	//PHANDLE pwxHeap;
	//PVOID pwxFriend;
	//PSTR* pwxWXID;
	//PSTR pwxUsername;
	//PDWORD pwxUIN;
	//SexType* pwxSex;
	//PSTR pwxPhone;
	//PSTR pwxAddr1;
	//PSTR pwxAddr2;
	//PSTR pwxAddr3;
	//PSTR* pwxLogo;
	//PSTR pwxUID;
	//PVOID* pwxUserData;
	//PVOID pwxInviteArg;
	//PVOID pwxCreateGroupArg;
	//PVOID* pwxAcceptFriendArg;
	//PVOID pwxSetReadArg;
	//PVOID pwxSendLinkArg;
	//PBYTE* pwxDBPW;
	WXDataMacro(WXDataCreate);
	WXFuncMacro(WXFuncCreate);
	DWORD _1[30]; // ��������
}WXPtrs, *PWXPtrs;


// HookBase������ε���HookHandler����
enum HandleType
{
	htNo = 0, // �����ô�����
	htReplace, // Խ�޴���
	htBefore, // �ȵ���HookHandler���ٵ���ԭ����
	htAfter, // �ȵ���ԭ������Ȼ�����HookHandler
};

// HookHandler
typedef PVOID(*ftHookHandler)(PVOID); // ����һ��ָ�룬ָ����ô�����ɺ������н��

// CommandHandler
typedef void(*ftCommandHandler)(const DataList& dl);


//
typedef struct
{
	HandleType ht;
	ftHookHandler fthh;
}HookHandleControl, *PHookHandleControl;


#define HookHandlersCreate(Name)	\
	HookHandleControl hhc##Name;

// ��ʼ��HookBase Handler�õĲ����ṹ�� �ýṹ�������Ķ����������¾ɰ汾�޷�����
typedef struct
{
	HookFuncMacro(HookHandlersCreate);
}HookHandlers, *PHookHandlers;

#define HookFuncsCreate(Name)		\
	ft##Name pwxf##Name;
// Hook����ָ�룬�������ڳ�ʼ��Hook
typedef struct
{
	HookFuncMacro(HookFuncsCreate);
	DWORD _1[10]; // ����
}HookFuncs, *PHookFuncs;

// ��ʼ����ģ��Ĳ��� // ����ǽṹ��Ƕ�׽ṹ�壬��ô����һ���ṹ��ĸ��Ļᵼ�º���ʣ�½ṹ���ƫ����ȫ���仯���¼��������⣬ȫ��ʹ��ָ��
typedef struct
{
	PCWSTR pwWXVer; // ΢�Ű汾
	DWORD dwVer; // ��ģ��汾
	SOCKET sk; // ͨ����Socket
	PVOID pBase; // WeChatWin.dll�Ļ���ַ
	PHookFuncs phf; // ��ҪHook�ĺ���ָ��
	PHookHandlers phh; // Hook�Ĵ�����
	ftCommandHandler* cfCmdHs; // Command�Ĵ�����
	PWXPtrs pp; // ΢��ָ��
	VOID (*pfOnMsgIDMap)(const wstring&, const wchar_t*); // ����ָ��
	PCWSTR pwWXPath;
}SubInitArg, *PSubInitArg;

static SOCKET skControl = 0;

extern PHANDLE pwxHeap;
// ��΢�ŵĶ�������һ���ڴ�
PVOID WXHeapAlloc(SIZE_T stMemSize);
// ��΢�ŵĶ�������һ���ڴ�Ȼ��д���ַ���
const wchar_t* WXStringAlloc(const wchar_t* pwStr);
const char* WXStringAlloc(const char* psStr);

// ��ʼ��FakeNotify
BOOL MakeFakeNotify(PFakeNotify pFakeNotify, const wchar_t* pwEvent, const wchar_t* pwObject);

// α��Ļ�ȡ��������
FakeNotifyString __fastcall FakeGetName(PVOID pObject, DWORD NOUSE, FakeNotifyString pMem);
