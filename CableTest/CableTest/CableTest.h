// CableTest.h : CableTest DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCableTestApp
// �йش���ʵ�ֵ���Ϣ������� CableTest.cpp
//

class CCableTestApp : public CWinApp
{
public:
	CCableTestApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
