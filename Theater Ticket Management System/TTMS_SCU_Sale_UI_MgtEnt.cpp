#include "stdafx.h"
#include "TTMS_SCU_Sale_UI_MgtEnt.h"
void Sale_UI_Mgt_Entry(USER * user)
{
	Schedule_UI_Browe(user,1);
	TTMS_GotoXY(48, 27);
	printf_s("��������������۹���");
	TTMS_GotoXY(43, 27);
	printf_s("�����뽻������(��Ʊ = 1,��Ʊ = 0):");
	int chiose = (int)(_getch()- 48);
	if (chiose == 1)
	{
		system("cls");
		BIOS_GOTO_BOX(22, 100, 5, 25);
		BIOS_GOTO_BOX(22, 100, 8, 7);
		TTMS_GotoXY(50, 6);
		printf_s("��Ʊ����ҳ��");
		TTMS_GotoXY(47, 9);
		printf_s("�ݳ��ƻ�ID:");
		TTMS_GotoXY(47, 11);
		printf_s("��λ����:");
		TTMS_GotoXY(47, 13);
		printf_s("��λ����:");
		int ScheduleID, SeatRowCount,SeatColCount;
		TTMS_GotoXY(59, 9);
		scanf_s("%d", &ScheduleID);
		TTMS_GotoXY(57, 11);
		scanf_s("%d", &SeatRowCount);
		TTMS_GotoXY(57, 13);
		scanf_s("%d", &SeatColCount);
		SCHEDULE *schedule = Schedule_Srv_FetchByID(ScheduleID);
		if (!schedule)
		{
			TTMS_GotoXY(52, 24);
			printf_s("û�д��ݳ���Ϣ!");
			_getch();
			Sale_UI_Mgt_Entry(user);
		}
		TICKET *ticket;
		ticket = (TICKET*)malloc(sizeof(TICKET));
		ticket->data.id = Ticket_Perst_FetchBySS(ScheduleID,Seat_Perst_FetchByRC(SeatRowCount, SeatColCount,schedule->data.studio_id));
		ticket = Ticket_Perst_FetchByID(schedule->data.studio_id);
		if (ticket)
		{
			_getch();
			ticket->data.seat_id = Seat_Perst_FetchByRC(SeatRowCount, SeatColCount, schedule->data.studio_id);
			Ticket_UI_ShowTicketByT(ticket);
		}
		else {
			printf_s("!!!!");
		}
	}
	else if (chiose == 2)
	{
		system("cls");
		BIOS_GOTO_BOX(22, 100, 5, 25);
		BIOS_GOTO_BOX(22, 100, 8, 7);
		TTMS_GotoXY(50, 6);
		printf_s("��Ʊ����ҳ��");
	}
	else {
		system("cls");
		TTMS_GotoXY(50, 15);
		printf_s("��������");
	}
}
