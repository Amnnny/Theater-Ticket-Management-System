#include "stdafx.h"
#include "TTMS_SCU_Schedule_UI_Del.h"

int Schedule_UI_Delete(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(53, 6);
	printf_s("ɾ���ݳ��ƻ�");
	SCHEDULE *schedule;
	int Schedule_ID;
	TTMS_GotoXY(45, 9);
	printf_s("������Ҫɾ����ID:");
	scanf_s("%d", &Schedule_ID);
	schedule = Schedule_Srv_FetchByID(Schedule_ID);
	if (schedule == nullptr)
	{
		TTMS_GotoXY(50, 20);
		printf_s("���ݳ��ƻ�������");
		_getch();
		Schedule_UI_MgtEntry(user);
	}
	else {
		TTMS_GotoXY(45, 12);
		printf_s("�ݳ���ID:%d", schedule->data.studio_id);
		TTMS_GotoXY(45, 14);
		printf_s("��ĿID:%d", schedule->data.play_id);
		TTMS_GotoXY(45, 16);
		printf_s("��λ����:%d", schedule->data.seat_count);
		TTMS_GotoXY(45, 18);
		printf_s("��ӳ��ʼʱ��:%d-%d-%d %d-%d", schedule->time.daytime.year, schedule->time.daytime.month, schedule->time.daytime.day, schedule->time.hour, schedule->time.minute);
		TTMS_GotoXY(52, 24);
		printf_s("Enter������ɾ��!");
		char key[20];
		strcpy_s(key, 20, GET_KEY());
		if (strcmp(key, "Enter") == 0)
		{
			Schedule_Srv_Delete(schedule->data.id);
			TTMS_GotoXY(52, 24);
			printf_s("                        ");
			TTMS_GotoXY(55, 24);
			printf_s("ɾ���ɹ�");
			_getch();
			Schedule_UI_MgtEntry(user);
		}
		else
		{
			Schedule_UI_MgtEntry(user);
		}
	}
	return 0;
}
