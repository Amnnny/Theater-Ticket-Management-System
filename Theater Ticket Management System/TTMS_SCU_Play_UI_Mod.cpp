#include "stdafx.h"
#include "TTMS_SCU_Play_UI_Mod.h"

void Play_UI_Mod(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(52, 6);
	printf_s("������Ҫ�޸ĵ�ID:");
	int ID;
	scanf_s("%d", &ID);
	PLAY *play = Play_Srv_FetchByID(ID);
	if (play)
	{
		BIOS_GOTO_BOX(22, 100, 23, 22);
		BIOS_GOTO_BOX(58, 58, 8, 22);
		TTMS_GotoXY(35, 24);
		printf_s("�����ҷ�����Ϣ�����޸ģ�������Ҫ�޸���ԭ�ⲻ���ƹ�ȥ");
		int NewDuration, NewType, NewRating, NewPrice;
		char  key[15], NewArea[9], NewName[30];
		TTMS_GotoXY(52, 6);
		printf_s("    ��%d�ž�Ŀ        ", play->data.id);
		TTMS_GotoXY(25, 9);
		printf_s("��Ŀ����: %s", play->data.name);
		TTMS_GotoXY(25, 11);
		printf_s("��������: %s", play->data.area);
		TTMS_GotoXY(25, 13);
		printf_s("��Ŀʱ��: %d", play->data.duration);
		TTMS_GotoXY(25, 15);
		printf_s("��ĿƱ�۸�: %d", play->data.price);
		TTMS_GotoXY(25, 17);
		printf_s("��Ŀ����:");
		switch (play->data.type)
		{
		case PLAY_TYPE_FLIM:printf_s("��Ӱ");
		case PLAY_TYPE_OPEAR:printf_s("���");
		case PLAY_TYPE_CONCERT:printf_s("���ֻ�");
		default:
			break;
		}
		TTMS_GotoXY(25, 19);
		printf_s("��Ŀ����:");
		switch (play->data.rating)
		{
		case PLAY_RATE_CHILD:printf_s("��ͯ");
		case PLAY_RATE_TEENAGE:printf_s("����");
		case PLAY_RATE_ADULT:printf_s("����");
		default:
			break;
		}
		TTMS_GotoXY(60, 9);
		printf_s("�޸ĺ�:");
		TTMS_GotoXY(60, 11);
		printf_s("�޸ĺ�: ");
		TTMS_GotoXY(60, 13);
		printf_s("�޸ĺ�: ");
		TTMS_GotoXY(60, 15);
		printf_s("�޸ĺ�: ");
		TTMS_GotoXY(60, 17);
		printf_s("�޸ĺ�:(��Ӱ=1,���=2,���ֻ�=3):");
		TTMS_GotoXY(60, 19);
		printf_s("�޸ĺ�:(��ͯ=1,����=2,����=3):");
		TTMS_GotoXY(67, 9);
		scanf_s("%s", NewName,31);
		TTMS_GotoXY(67, 11);
		scanf_s("%s", NewArea,9);
		TTMS_GotoXY(67, 13);
		scanf_s("%d", &NewDuration);
		TTMS_GotoXY(67, 15);
		scanf_s("%d", &NewPrice);
		TTMS_GotoXY(92, 17);
		scanf_s("%d", &NewType);
		TTMS_GotoXY(92, 19);
		scanf_s("%d", &NewRating);
		if (NewType > 3 && NewType < 1)
		{
			TTMS_GotoXY(35 , 24);
			printf_s("                                                    ");
			TTMS_GotoXY(50, 24);
			printf_s("����������Ϣ���� !           ");
		}
		else if (NewRating > 3 && NewRating < 1)
		{
			TTMS_GotoXY(35, 24);
			printf_s("                                                     ");
			TTMS_GotoXY(50, 24);
			printf_s("�ȼ�������Ϣ���� !           ");
		}
		else
		{
			strcpy_s(play->data.name,31,NewName);
			strcpy_s(play->data.area, 31, NewArea);
			play->data.duration = NewDuration;
			play->data.price = NewPrice;
			play->data.type = (play_type_t)NewType;
			play->data.rating = (play_rating_t)NewRating;
		}
		TTMS_GotoXY(35, 24);
		printf_s("                                                       ");
		TTMS_GotoXY(52, 24);
		printf_s("Enterȷ���޸ģ�Escȡ��");
		strcpy_s(key, 15, GET_KEY());
		if (strcmp(key, "Enter") == 0)
		{
			Play_Srv_Mod(play);
			TTMS_GotoXY(35, 24);
			printf_s("                                                     ");
			TTMS_GotoXY(50, 24);
			printf_s("�޸ĳɹ�,������˳���");
			_getch();
			Play_UI_MgtEntry(user);
		}
		if (strcmp(key, "Esc") == 0)
		{
			TTMS_GotoXY(35, 24);
			printf_s("                                                    ");
			TTMS_GotoXY(50, 24);
			printf_s("ȡ���ɹ�,������˳���");
			_getch();
			Play_UI_MgtEntry(user);
		}
	}
	else 
	{
		TTMS_GotoXY(35, 24);
		printf_s("                                                       ");
		TTMS_GotoXY(50, 24);
		printf_s("�޴˾�Ŀ,��������˳�");
		_getch();
		Play_UI_MgtEntry(user);
	}
}

