#include "stdafx.h"
#include "TTMS_SCU_Account_UI_DelByN.h"

void Account_UI_DeleteByName(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	BIOS_GOTO_BOX(22, 100, 23, 22);
	TTMS_GotoXY(52, 6);
	printf_s("û�������Ժ");
	TTMS_GotoXY(43, 9);
	printf_s("%s���ã�������Ҫɾ�����û�ID", user->USER_NAME);
	TTMS_GotoXY(54, 11);
	char delname[USER_LEN];
	scanf_s("%s",delname,USER_LEN);
	if (Account_Perst_CheckAccout(delname) == 1)
	{
		USER *user = Account_Perst_FetchByName(delname);
		Account_Perst_DelByName(delname);
		TTMS_GotoXY(52, 18);
		printf_s("ɾ���ɹ�");
		Account_Srv_Back(user);
	}
	else
	{
		TTMS_GotoXY(43, 15);
		printf_s("û���ҵ���ϵͳ�û�����Enter���Ի�Esc����");
	}
	char key[15];
	strcpy_s(key,15, GET_KEY());
	if (strcmp(key,"Esc") == 0)
	{
		Account_UI_MgtEntry(user);
	}
	else
	{
		Account_UI_DeleteByName(user);
	}
}
