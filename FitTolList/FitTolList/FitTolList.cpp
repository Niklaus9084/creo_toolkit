// FitTolList.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "FitTolList.h"
#include "FitTol.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#pragma region MFC
//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CFitTolListApp

BEGIN_MESSAGE_MAP(CFitTolListApp, CWinApp)
END_MESSAGE_MAP()

// CFitTolListApp ����

CFitTolListApp::CFitTolListApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CFitTolListApp ����

CFitTolListApp theApp;

// CFitTolListApp ��ʼ��

BOOL CFitTolListApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
#pragma endregion

int CurrentMdlType()
{
	ProMdl mdl;
	ProMdlType mdltype;
	ProError status;
	status = ProMdlCurrentGet(&mdl);
	if (status != PRO_TK_NO_ERROR)
		return -1;
	status = ProMdlTypeGet(mdl, &mdltype);
	if (status != PRO_TK_NO_ERROR)
		return -1;
	else
		return mdltype;
}

static uiCmdAccessState AccessASM(uiCmdAccessMode access_mode)
{
	if (CurrentMdlType() == PRO_ASSEMBLY)
		return ACCESS_AVAILABLE;
	else
		return ACCESS_INVISIBLE;
}

void FitTolListCmd1()
{
	GToInterCal();
}
void FitTolListCmd2()
{
	SelpartInterference();
}
extern "C" int user_initialize()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	AfxInitRichEdit2();
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);
	AfxEnableControlContainer();

	ProError status;
	uiCmdCmdId FitTolList_cmd_id1, FitTolList_cmd_id2;
	status = ProMenubarMenuAdd("FitTolList", "FitTolList", "File", PRO_B_TRUE, L"FitTolList.txt");

	status = ProCmdActionAdd("IMI_FitTolList_Act1", (uiCmdCmdActFn)FitTolListCmd1, uiProeImmediate, AccessASM, PRO_B_TRUE, PRO_B_TRUE, &FitTolList_cmd_id1);
	status = ProMenubarmenuPushbuttonAdd("FitTolList", "Cmd1", "Cmd1", "Tips1", NULL, PRO_B_TRUE, FitTolList_cmd_id1, L"FitTolList.txt");

	status = ProCmdActionAdd("IMI_FitTolList_Act2", (uiCmdCmdActFn)FitTolListCmd2, uiProeImmediate, AccessASM, PRO_B_TRUE, PRO_B_TRUE, &FitTolList_cmd_id2);
	status = ProMenubarmenuPushbuttonAdd("FitTolList", "Cmd2", "Cmd2", "Tips2", NULL, PRO_B_TRUE, FitTolList_cmd_id2, L"FitTolList.txt");

	return PRO_TK_NO_ERROR;
}
extern "C" void user_terminate()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
}
