#include "stdafx.h"
#include "TTMS_SCU_Account_UI_DelByN.h"

void Account_UI_DeleteByName(USER * Admini)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	BIOS_GOTO_BOX(22, 100, 23, 22);
	TTMS_GotoXY(52, 6);
	printf_s("û�������Ժ");
	TTMS_GotoXY(43, 9);
	printf_s("%s���ã�������Ҫɾ�����û�ID", Admini->USER_NAME);
	TTMS_GotoXY(54, 11);
	char delname[USER_LEN];
	scanf_s("%s",delname,USER_LEN);
	if (Account_Perst_CheckAccout(delname) == 1)
	{
		USER *user = Account_Perst_FetchByName(delname);
		TTMS_GotoXY(47, 13);
		printf_s("����:%s", user->USER_NAME);
		TTMS_GotoXY(47, 15);
		printf_s("�˺�:%s", user->USER_ACCOUT);
		TTMS_GotoXY(47, 17);
		printf_s("���:");
		if (user->power == 1)
		{
			printf_s("��Ʊ����");
		}
		else if (user->power == 2)
		{
			printf_s("��ƱԱ");
		}
		else if (user->power == 0)
		{
			printf_s("ϵͳ����Ա");
		}
		TTMS_GotoXY(44, 19);
		printf_s("Enterȷ��ɾ��,�������˳�");
		char Chiose[USER_LEN];
		strcpy_s(Chiose, USER_LEN, GET_KEY());
		if (strcmp(Chiose,"Enter") == 0)
		{
			Account_Perst_DelByName(delname);
			TTMS_GotoXY(53, 20);
			printf_s("ɾ���ɹ�");
			Account_Srv_Back(Admini);
		}
		else {
			TTMS_GotoXY(53, 20);
			printf_s("ȡ���ɹ�");
			Account_Srv_Back(Admini);
		}
	}
	else
	{
		TTMS_GotoXY(43, 20);
		printf_s("û���ҵ���ϵͳ�û�����Enter���Ի�Esc����");
	}
	char key[15];
	strcpy_s(key,15, GET_KEY());
	if (strcmp(key,"Esc") == 0)
	{
		Account_UI_MgtEntry(Admini);
	}
	else
	{
		Account_UI_DeleteByName(Admini);
	}
}
