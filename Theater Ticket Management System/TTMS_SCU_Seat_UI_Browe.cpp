#include "stdafx.h"
#include "TTMS_SCU_Seat_UI_Browe.h"

void Seat_UI_Browe(USER * user)
{
	system("cls");
	int key = EntKeySeat_Perst_CompNewKeys();
	for (int i = 1; i < key; i++)
	{
		SEAT *seat = Seat_Srv_FetchByID(i);
		if (seat)
		{
			printf_s("\t\t\t\t\t        ��%d����λ\n        ", seat->data.id);    
			printf_s("\t\t\t\t\t��ӳ��ID: %d\n", seat->data.RoomID);
			printf_s("\t\t\t\t\t��λ����: %d\n", seat->data.row);
			printf_s("\t\t\t\t\t��λ����: %d\n", seat->data.col); 
			printf_s("\t\t\t\t\t��λ״̬:");
			switch ((SEAT_STATUS)seat->data.status)
			{
			case SEAT_GOOD:printf_s("����\n"); break;
			case SEAT_BROKEN:printf_s("����\n"); break;
			case SEAT_NODE:printf_s("����λ\n"); break;
			default:
				break;
			}
			printf_s("\n");
		}
	}
	_getch();
	Seat_UI_MgtEntry(user);
}
