#include "stdafx.h"
#include "TTMS_SCU_Seat_UI_Mod.h"

void Seat_UI_Mod(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(52, 6);
	printf_s("������Ҫ�޸ĵ�ID:");
	int ID;
	scanf_s("%d", &ID);
	SEAT *seat = Seat_Srv_FetchByID(ID);
	if (seat)
	{
		int NewStatus;
		char  key[15];
		TTMS_GotoXY(52, 6);
		printf_s("    ��%d����λ        ",seat->data.id);
		TTMS_GotoXY(48, 9);
		printf_s("��ӳ��ID: %d", seat->data.RoomID);
		TTMS_GotoXY(48, 11);
		printf_s("��λ����: %d", seat->data.row);
		TTMS_GotoXY(48, 13);
		printf_s("��λ����: %d", seat->data.col);
		TTMS_GotoXY(48, 15);
		printf_s("��λ״̬:");
		switch (seat->data.status)
		{     
		case SEAT_GOOD:printf_s("����"); break;
		case SEAT_BROKEN:printf_s("����"); break;
		case SEAT_NODE:printf_s("����λ"); break;
		default:
			break;
		}
		TTMS_GotoXY(45, 17);
		printf_s("��ֻ���޸���λ״̬�������������λ");
		TTMS_GotoXY(45, 19);
		printf_s("��������λ״̬��Ϣ(����:1,����:9)");
		scanf_s("%d",&NewStatus);
		if (NewStatus != 9 && NewStatus != 1)
		{
			TTMS_GotoXY(50, 20);
			printf_s("������Ϣ���� !           ");
		}
		else
		{
			seat->data.status = (SEAT_STATUS)NewStatus;
		}
		TTMS_GotoXY(50, 23);
		printf_s("Enterȷ���޸ģ�Escȡ��");
		strcpy_s(key, 15, GET_KEY());
		if (strcmp(key, "Enter") == 0)
		{
			Seat_Srv_Mod(seat, NewStatus);
			TTMS_GotoXY(50, 23);
			printf_s("�޸ĳɹ�,������˳���");
			_getch();
			Seat_UI_MgtEntry(user);
		}
		if (strcmp(key, "Esc") == 0)
		{
			TTMS_GotoXY(50, 23);
			printf_s("ȡ���ɹ�,������˳���");
			_getch();
			Seat_UI_MgtEntry(user);
		}
	}
	else {
		TTMS_GotoXY(45, 23);
		printf_s("�޴���λ,��������˳�");
		_getch();
		Seat_UI_MgtEntry(user);
	}
}
