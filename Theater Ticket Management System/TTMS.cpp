// Theater Ticket Management System.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	if (pd_state() == 1)
	{
		SysLogin();
	}
	else
	{
		Account_UI_InitSys();
	}
    return 0;
}

