#include "stdafx.h"

void Account_UI_Add(USER *Admini)
{
	USER *user;
	user = static_cast<USER*>(malloc(sizeof(USER)));
	system("cls");
	auto power = 1;
	BIOS_GOTO_BOX(22,100,5,25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(55, 6);
	printf_s("�������û�");
	TTMS_GotoXY(50, 9);
	printf_s("����:");
	TTMS_GotoXY(50, 11);
	printf_s("�˺�:");
	TTMS_GotoXY(50, 13);
	printf_s("����:");
	TTMS_GotoXY(50, 15);
	printf_s("��Ʊ����");
	TTMS_GotoXY(62, 15);
	printf_s("��ƱԱ");
	TTMS_GotoXY(55, 9);
	scanf_s("%s", user->USER_NAME, USER_LEN);
	TTMS_GotoXY(55, 11);
	INPUT_ACCOUT(user->USER_ACCOUT, USER_LEN);
	TTMS_GotoXY(55, 13);
	INPUT_PASSWORD(user->USER_PASSWORD, USER_LEN);
	GET_OC(47, 15, 59, 15, 0, 12, "->", 1, 0);
	if (GET_CURSOR_X() == 49)
	{
		user->power = 1;
	}
	else if (GET_CURSOR_X() == 61)
	{
		user->power = 2;
	}
	if (Account_Perst_CheckAccout(user->USER_ACCOUT) == 1) {
		TTMS_GotoXY(50, 20);
		printf_s("���˺��Ѿ�����");
		_getch();
		Account_UI_Add(Admini);
	}
	else {
		TTMS_GotoXY(47, 18);
		printf_s("�˺ſ���,��ȷ������:");
		char temppass[USER_LEN];
		INPUT_PASSWORD(temppass, USER_LEN);
		if (strcmp(temppass,user->USER_PASSWORD) != 0)
		{
			TTMS_GotoXY(50, 20);
			printf_s("�������벻һ��");
			_getch();
			Account_UI_Add(Admini);
		}
	}
	user->NODE_NEXT = nullptr;
	user->NODE_PREV = nullptr;
	Account_Perst_Insert(user);
	TTMS_GotoXY(55, 20);
	printf_s("���ӳɹ�");
	Account_Srv_Back(Admini);
	
}
