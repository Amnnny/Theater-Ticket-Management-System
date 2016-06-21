#include "stdafx.h"
#include "TTMS_SCU_Play_UI_Del.h"

int Play_UI_Delete(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(53, 6);
	printf_s("ɾ����Ŀ��Ϣ");
	PLAY *play;
	int Seat_ID;
	TTMS_GotoXY(45, 9);
	printf_s("������Ҫɾ����ID:");
	scanf_s("%d", &Seat_ID);
	play = Play_Perst_FetchByID(Seat_ID);
	if (play == nullptr)
	{
		TTMS_GotoXY(50, 20);
		printf_s("�þ�Ŀ������");
		_getch();
		Play_UI_MgtEntry(user);
	}
	else {
		TTMS_GotoXY(45, 12);
		printf_s("��Ŀ����:%s", play->data.name);
		TTMS_GotoXY(45, 14);
		printf_s("��������:%s", play->data.area);
		TTMS_GotoXY(45, 16);
		printf_s("ȫƬʱ��:%d", play->data.duration);
		TTMS_GotoXY(52, 20);
		printf_s("Enter������ɾ��!");
		TTMS_GotoXY(54, 22);
		char key[20];
		strcpy_s(key, 20, GET_KEY());
		if (strcmp(key, "Enter") == 0)
		{
			Play_Perst_DeleteByID(play->data.id);
			EntKeyPlay_Perst_CompKeyM();
			printf_s("ɾ���ɹ�");
			_getch();
			Play_UI_MgtEntry(user);
		}
		else
		{
			Play_UI_MgtEntry(user);
		}
	}
	return 0;
}
