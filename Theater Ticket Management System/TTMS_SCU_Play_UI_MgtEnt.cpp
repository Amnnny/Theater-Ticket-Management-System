#include "stdafx.h"
#include "TTMS_SCU_Play_UI_MgtEnt.h"

void Play_UI_MgtEntry(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(53, 6);
	printf_s("��ӭ����,%s", user->USER_NAME);
	TTMS_GotoXY(45, 24);
	printf_s("��UP/DOWNѡ��,ENTERȷ��,ESCע����¼");
	BIOS_GOTO_BOX(22, 100, 23, 22);
	TTMS_GotoXY(47, 9);
	printf_s("NO1:��Ӿ�Ŀ");
	TTMS_GotoXY(47, 11);
	printf_s("NO2:�޸ľ�Ŀ��Ϣ");
	TTMS_GotoXY(47, 13);
	printf_s("NO3:ɾ����Ŀ");
	TTMS_GotoXY(47, 15);
	printf_s("NO4:�ݳ��ƻ�����");
	TTMS_GotoXY(47, 17);
	printf_s("No5:�����Ŀ��Ϣ");
	TTMS_GotoXY(47, 19);
	int flag = GET_OC(44, 9, 44, 17, 2, 1, "->", 0, 1);
	if (flag == 1)
	{
		switch (GET_CURSOR_Y())
		{
		case 9: Play_UI_Add(user); break;
		case 11: break;
		case 13:Play_UI_Delete(user); break;
		case 15: break;
		case 17:Play_UI_Browe(user); break;
		default:
			break;
		}
	}
	else if (flag == 0)
	{
		Main_UI_MgtEntry(user);
	}
}
