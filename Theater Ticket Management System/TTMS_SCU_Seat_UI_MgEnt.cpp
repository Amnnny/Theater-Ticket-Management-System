#include "stdafx.h"
#include "TTMS_SCU_Seat_UI_MgEnt.h"

void Seat_UI_MgtEntry(USER * user)
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
	printf_s("NO1:�������λ");
	TTMS_GotoXY(47, 11);
	printf_s("NO2:�޸���λ");
	TTMS_GotoXY(47, 13);
	printf_s("NO3:ɾ����λ");
	TTMS_GotoXY(47, 19);
	auto flag = GET_OC(44, 9, 44, 13, 2, 1, "->", 0, 1);
	if (flag == 1)
	{
		switch (GET_CURSOR_Y())
		{
		case 9: Seat_UI_Add(user); break;
		case 11: Seat_UI_Mod(user); break;
		case 13: Seat_UI_Delete(user); break;
		default: break;
		}
	}
	else if (flag == 0)
	{
		Studio_UI_MgtEntry(user);
	}
}
