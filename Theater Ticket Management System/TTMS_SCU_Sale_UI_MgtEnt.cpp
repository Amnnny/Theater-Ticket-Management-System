#include "stdafx.h"
#include "TTMS_SCU_Sale_UI_MgtEnt.h"
void Sale_UI_Mgt_Entry(USER * user)
{
	Schedule_UI_Browe(user,1);
	TTMS_GotoXY(48, 27);
	printf_s("��Enter�������۹���,Esc�˳�");
	if (strcmp(GET_KEY(), "Esc") == 0)
	{
		Main_UI_MgtEntry(user);
	}
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
		int seat_id = Seat_Perst_FetchByRC(SeatRowCount, SeatColCount, schedule->data.studio_id);
		if (!seat_id)
		{
			TTMS_GotoXY(52, 24);
			printf_s("û�д���λ��Ϣ!");
			_getch();
			Sale_UI_Mgt_Entry(user);
		}
		ticket = (TICKET*)malloc(sizeof(TICKET));
		ticket->data.id = Ticket_Perst_FetchBySS(ScheduleID, seat_id);
		ticket = Ticket_Perst_FetchByID(ticket->data.id);
	//	printf_s("%d    ", ticket->data.id);
		if (ticket)
		{
			if (ticket->data.status != TICKET_AVL)
			{
				TTMS_GotoXY(48, 24);
				printf_s("����λƱ���۳���Ԥ��!");
				_getch();
				Sale_UI_Mgt_Entry(user);
			}
			ticket->data.seat_id = Seat_Perst_FetchByRC(SeatRowCount, SeatColCount, schedule->data.studio_id);
			Ticket_UI_ShowTicketByT(ticket);
			TTMS_GotoXY(55, 24);
			printf_s("Enterȷ����Ʊ");
			if (strcmp(GET_KEY(),"Enter") == 0)
			{
				//��Ʊ
				Sale_Srv_SaleO(ticket, user);
				TTMS_GotoXY(55, 24);
				printf_s("��Ʊ�ɹ�!       ");
				_getch();
				Sale_UI_Mgt_Entry(user);
			}
			else {
				TTMS_GotoXY(55, 24);
				printf_s("ȡ���ɹ�!         ");
				_getch();
				Sale_UI_Mgt_Entry(user);
			}
		}
		else {
			TTMS_GotoXY(52, 24);
			printf_s("û�д�Ʊ��Ϣ!          ");
			_getch();
			Sale_UI_Mgt_Entry(user);
		}
	}
	else if (chiose == 0)
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
		int ScheduleID, SeatRowCount, SeatColCount;
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
		int seat_id = Seat_Perst_FetchByRC(SeatRowCount, SeatColCount, schedule->data.studio_id);
		if (!seat_id)
		{
			TTMS_GotoXY(52, 24);
			printf_s("û�д���λ��Ϣ!");
			_getch();
			Sale_UI_Mgt_Entry(user);
		}
		ticket = (TICKET*)malloc(sizeof(TICKET));
		ticket->data.id = Ticket_Perst_FetchBySS(ScheduleID, seat_id);
	//	printf_s("%d", ticket->data.id);
		ticket = Ticket_Perst_FetchByID(ticket->data.id);
		if (ticket)
		{
	//		printf_s("%d", ticket->data.id);
	//		_getch();
			if (ticket->data.status == TICKET_AVL)
			{
				TTMS_GotoXY(48, 24);
				printf_s("����λƱ��δ�۳�!");
				_getch();
				Sale_UI_Mgt_Entry(user);
			}
			ticket->data.seat_id = seat_id;
			Ticket_UI_ShowTicketByT(ticket);
			TTMS_GotoXY(55, 24);
			printf_s("Enterȷ����Ʊ");
			if (strcmp(GET_KEY(), "Enter") == 0)
			{
				//��Ʊ
				Sale_Srv_SaleI(ticket, user);
				TTMS_GotoXY(55, 24);
				printf_s("��Ʊ�ɹ�!       ");
				_getch();
				Sale_UI_Mgt_Entry(user);
			}
			else {
				TTMS_GotoXY(55, 24);
				printf_s("ȡ���ɹ�!         ");
				_getch();
				Sale_UI_Mgt_Entry(user);
			}
		}
		else {
			TTMS_GotoXY(52, 24);
			printf_s("û�д�Ʊ��Ϣ!          ");
			_getch();
			Sale_UI_Mgt_Entry(user);
		}
	}
	else {
		system("cls");
		TTMS_GotoXY(50, 15);
		printf_s("��������");
	}
}
