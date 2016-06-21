#include "stdafx.h"
#include "TTMS_SCU_Schedule_UI_Add.h"

void Schedule_UI_Add(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	PLAY *play;
	STUDIO *studio;
	SCHEDULE *schedule;
	schedule = (SCHEDULE *)malloc(sizeof(SCHEDULE));
	TTMS_GotoXY(52, 6);
	printf_s("�ϼ��ݳ���Ϣ");
	TTMS_GotoXY(47, 9);
	printf_s("�ݳ���ID:");
	TTMS_GotoXY(47, 11);
	printf_s("��ĿID:");
	TTMS_GotoXY(47, 13);
	printf_s("��λ��:");
	TTMS_GotoXY(47, 15);
	printf_s("��ӳ����(y m d):");
	TTMS_GotoXY(47, 17);
	printf_s("��ӳʱ��(h m):");
	TTMS_GotoXY(56, 9);
	scanf_s("%d", &schedule->data.studio_id);
	TTMS_GotoXY(54, 11);
	scanf_s("%d", &schedule->data.play_id);
	TTMS_GotoXY(54, 13);
	scanf_s("%d", &schedule->data.seat_count);
	TTMS_GotoXY(63, 15);
	scanf_s("%d%d%d", &schedule->time.daytime.year, &schedule->time.daytime.month, &schedule->time.daytime.day);
	TTMS_GotoXY(61, 17);
	scanf_s("%d%d", &schedule->time.hour, &schedule->time.minute);
	if (!(studio = Studio_Srv_FetchByID(schedule->data.studio_id))) {
		TTMS_GotoXY(48, 20);
		printf_s("�޴��ݳ��������������");
		_getch();
		Schedule_UI_MgtEntry(user);
	}
	else if (!(play = Play_Srv_FetchByID(schedule->data.play_id)))
	{
		TTMS_GotoXY(48, 20);
		printf_s("�޴˾�Ŀ��Ϣ�����������");
		_getch();
		Schedule_UI_MgtEntry(user);
	}
	if (!Schedule_Srv_Add(schedule))
	{
		TTMS_GotoXY(48, 20);
		printf_s("�Ѵ��ڴ��ݳ���Ϣ");
		_getch();
		Schedule_UI_MgtEntry(user);
	}
	TTMS_GotoXY(48, 18);
	printf_s("��ӳɹ�,���������");
	_getch();
	Schedule_UI_MgtEntry(user);
}
