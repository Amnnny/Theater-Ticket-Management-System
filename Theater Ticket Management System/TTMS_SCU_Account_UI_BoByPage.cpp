#include "stdafx.h"
#include "TTMS_SCU_Account_UI_BoByPage.h"

int Account_UI_BoByPage( int NumberMin,int NumberMax,USER *Head)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	BIOS_GOTO_BOX(22, 100, 11, 10);
	BIOS_GOTO_BOX(22, 100, 14, 13);
	BIOS_GOTO_BOX(22, 100, 17, 16);
	BIOS_GOTO_BOX(22, 100, 20, 19);
	BIOS_GOTO_BOX(22, 100, 23, 22);
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(45, 45, 5, 22);
	BIOS_GOTO_BOX(70, 70, 5, 22);
	TTMS_GotoXY(30, 6);
	printf_s("����");
	TTMS_GotoXY(55, 6);
	printf_s("�˺�");
	TTMS_GotoXY(85, 6);
	printf_s("ְλ");
	TTMS_GotoXY(37, 24);
	printf_s("Left��һҳ  Right��һҳ  Esc������һ��              PAGE:%d", NumberMin / 5 + 1);
	auto TEMP = Head->NODE_NEXT;
	auto Count = 0;
	while (Count < NumberMin)
	{
		Count++;
		TEMP = TEMP->NODE_NEXT;
	}
	Count = NumberMin;
	while (Count < NumberMax)
	{
		if (TEMP->NODE_NEXT == Head && TEMP)
		{
			return 1;
		}
		TTMS_GotoXY(30, 9 + 3 * (Count - NumberMin));
		printf_s("%s", TEMP->USER_NAME);
		TTMS_GotoXY(55, 9 + 3 * (Count - NumberMin));
		printf_s("%s", TEMP->USER_ACCOUT);
		TTMS_GotoXY(83, 9 + 3 * (Count - NumberMin));
		switch (TEMP->power)
		{
		case 0:printf_s("ϵͳ����Ա"); break;
		case 1:printf_s("��Ʊ����"); break;
		case 2:printf_s("��ƱԱ"); break;
		}
		TTMS_GotoXY(50, 26);
		Count++;
		TEMP = TEMP->NODE_NEXT;
	}
	if (TEMP->NODE_NEXT == Head)
	{
		return 1;
	}
	return 0;
}
