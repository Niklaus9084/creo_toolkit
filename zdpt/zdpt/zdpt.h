// zdpt.h : zdpt DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CzdptApp
// �йش���ʵ�ֵ���Ϣ������� zdpt.cpp
//

class CzdptApp : public CWinApp
{
public:
	CzdptApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
