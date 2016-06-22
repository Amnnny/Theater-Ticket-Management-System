#include "stdafx.h"
#include "TTMS_SCU_Studio_UI_Mod.h"

void Studio_UI_Mod(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(52, 6);
	printf_s("������Ҫ�޸ĵ�ID:");
	int ID;
	scanf_s("%d", &ID);
	STUDIO *studio = Studio_Srv_FetchByID(ID);
	if (studio)
	{
		int  NewRowCount, NewColsCount;
		char NewName[30],key[15];
		BIOS_GOTO_BOX(22, 100, 12, 11);
		BIOS_GOTO_BOX(22, 100, 17, 16);
		BIOS_GOTO_BOX(22, 100, 21, 20);
		BIOS_GOTO_BOX(62, 62, 8, 19);
		TTMS_GotoXY(52, 6);
		printf_s("    ��%d�ŷ�ӳ��        ",studio->data.id);
		TTMS_GotoXY(26, 9);
		printf_s("��    ��: %s",studio->data.name);
		TTMS_GotoXY(26, 14);
		printf_s("��λ����: %d", studio->data.rowsCount);
		TTMS_GotoXY(26, 18);
		printf_s("��λ����: %d", studio->data.colsCount);
		TTMS_GotoXY(65, 9);
		printf_s("������:");
		TTMS_GotoXY(65, 14);
		printf_s("����λ����:");
		TTMS_GotoXY(65, 18);
		printf_s("����λ����:");
		TTMS_GotoXY(72, 9);
		scanf_s("%s", NewName,30);
		TTMS_GotoXY(76, 14);
		scanf_s("%d", &NewRowCount);
		TTMS_GotoXY(76, 18);
		scanf_s("%d", &NewColsCount);
		TTMS_GotoXY(50, 23);
		printf_s("Enterȷ���޸ģ�Escȡ��.");
		strcpy_s(key,15,GET_KEY());
		if (strcmp(key,"Enter") == 0)
		{
			Studio_Srv_Mod(studio, NewName, NewRowCount, NewColsCount);
			TTMS_GotoXY(50, 23);
			printf_s("�޸ĳɹ�,������˳���");
			_getch();
			Studio_UI_MgtEntry(user);
		}
		if (strcmp(key, "Esc") == 0)
		{
			TTMS_GotoXY(50, 23);
			printf_s("ȡ���ɹ�,������˳���");
			_getch();
			Studio_UI_MgtEntry(user);
		}
	}
	else {
		TTMS_GotoXY(45, 23);
		printf_s("�޴˷�ӳ��,��������˳�");
		_getch();
		Studio_UI_MgtEntry(user);
	}
}
