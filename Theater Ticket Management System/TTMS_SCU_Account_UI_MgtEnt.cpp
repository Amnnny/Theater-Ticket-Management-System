#include "stdafx.h"
#include "TTMS_SCU_Account_UI_MgtEnt.h"

void Account_UI_MgtEntry(USER *user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(53, 6);
	printf_s("��ӭ����,%s", user->USER_NAME);
	TTMS_GotoXY(45, 24);
	printf_s("��UP/DOWNѡ��,ENTERȷ��,ESCע����¼");
	BIOS_GOTO_BOX(22, 100, 23, 22);
	if (user->power == 0)
	{
		TTMS_GotoXY(47, 9);
		printf_s("NO1:���ϵͳ�û�");
		TTMS_GotoXY(47, 11);
		printf_s("NO2:ɾ��ϵͳ�û�");
		TTMS_GotoXY(47, 13);
		printf_s("NO3:�޸�ϵͳ�û�����");
		TTMS_GotoXY(47, 15);
		printf_s("NO4:��ѯϵͳ�û�");
		TTMS_GotoXY(47, 17);
		printf_s("NO5:���ϵͳ�û�");
		int flag = GET_OC(44, 9, 44, 17, 2, 1, "->", 0, 1);
		if (flag == 1)
		{
			switch (GET_CURSOR_Y())
			{
			case 9: Account_UI_Add(user); break;
			case 11:Account_UI_Delete(user); break;
			case 13:
			case 15:
			case 17:Account_UI_Browe(user); break;
			default:
				break;
			}
		}
		else if (flag == 0)
		{
			SysLogin();
		}
	}
	
}
