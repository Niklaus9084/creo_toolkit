// FitTolList.h : FitTolList DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFitTolListApp
// �йش���ʵ�ֵ���Ϣ������� FitTolList.cpp
//

class CFitTolListApp : public CWinApp
{
public:
	CFitTolListApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
