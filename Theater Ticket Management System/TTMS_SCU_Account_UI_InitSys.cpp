#include "stdafx.h"
#include "TTMS_SCU_Account_UI_InitSys.h"

void Account_UI_InitSys()
{
	TTMS_GotoXY(42, 10);
	printf_s("��ǰϵͳδ��ʼ�����밴�������ʼ��ϵͳ");
	_getch();
	system("cls");
	char useraccount[USER_LEN],username[USER_LEN], userpassword[USER_LEN],password[USER_LEN];
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(54, 6);
	printf_s("û������Ժ");
	TTMS_GotoXY(55, 9);
	printf_s("����ϵͳ����Ա");
	TTMS_GotoXY(50, 11);
	printf_s("����:");
	TTMS_GotoXY(50, 13);
	printf_s("�˺�:");
	TTMS_GotoXY(50, 15);
	printf_s("����:");
	TTMS_GotoXY(50, 17);
	printf_s("ȷ������:");
	TTMS_GotoXY(56, 11);
	scanf_s("%s",username,15);
	TTMS_GotoXY(56, 13);
	INPUT_ACCOUT(useraccount, USER_LEN);
	TTMS_GotoXY(56, 15);
	INPUT_PASSWORD(userpassword, USER_LEN);
	TTMS_GotoXY(59, 17);
	INPUT_PASSWORD(password, USER_LEN);
	if (strcmp(userpassword,password) == 0)
	{
		system("cls");
		TTMS_INITIAL();
		Account_Srv_InitSys(useraccount, username, userpassword, password);
		Main_UI_MgtEntry(Account_Perst_FetchByAccount(useraccount));
	}
}
