#include "stdafx.h"
#include "TTMS_SCU_Account_UI_MgtEnt.h"

void Main_UI_MgtEntry(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(53, 6);
	printf_s("��ӭ����,%s", user->USER_NAME);
	TTMS_GotoXY(45, 24);
	printf_s("��UP/DOWNѡ��,ENTERȷ��,ESCע����¼");
	BIOS_GOTO_BOX(22, 100, 23, 22);
	if (user->power == 0)
	{
		TTMS_GotoXY(47, 9);
		printf_s("No1:ϵͳ�û�����");
		TTMS_GotoXY(47, 11);
		printf_s("No2:�ݳ�������");
		TTMS_GotoXY(47, 13);
		printf_s("No3:�ָ�������");
		if (GET_OC(44, 9, 44, 13, 2, 1, "->", 0, 1) == 1) {
			switch (GET_CURSOR_Y())
			{
			case 9:Account_UI_MgtEntry(user); break;
			case 11:Studio_UI_MgtEntry(user); break;
			case 13:
				system("cls");
				remove("Account.dat");
				remove("Studio.dat");
				remove("EntityKey.dat");
				remove("Seat.dat");
				remove("EntityKeySeat.dat");
				TTMS_INITIAL();
				exit(0);
			default:
				break;
			}
		}
		else {
			SysLogin();
		}
	}
	else if(user->power == 1){
		TTMS_GotoXY(47, 9);
		printf_s("No1:��Ŀ����");
		TTMS_GotoXY(47, 11);
		printf_s("No2:��ѯ�ݳ�");
		TTMS_GotoXY(47, 13);
		printf_s("No3:��ѯ�ݳ�Ʊ");
		TTMS_GotoXY(47, 15);
		printf_s("No4:������������");
		TTMS_GotoXY(47, 17);
		printf_s("No5:ͳ�����۶�");
		TTMS_GotoXY(47, 19);
		printf_s("No5:�޸�����");
		if (GET_OC(44, 9, 44, 19, 2, 1, "->", 0, 1) == 1) {
			switch (GET_CURSOR_Y())
			{
			case 9: Play_UI_MgtEntry(user); break;
			case 11: break;
			case 13:break;
			case 15:break;
			case 17:break;
			case 19:Account_UI_ModPassword(user); break;
			default:
				break;
			}
		}
		else {
			SysLogin();
		}
	}
	else if (user->power == 2) {
		TTMS_GotoXY(47, 9);
		printf_s("No1:��Ʊ");
		TTMS_GotoXY(47, 11);
		printf_s("No2:��ѯ�ݳ�");
		TTMS_GotoXY(47, 13);
		printf_s("No3:��ѯ�ݳ�Ʊ");
		TTMS_GotoXY(47, 15);
		printf_s("No4:������������");
		TTMS_GotoXY(47, 17);
		printf_s("No5:ͳ�����۶�");
		TTMS_GotoXY(47, 19);
		printf_s("No5:�޸�����");
		if (GET_OC(44, 9, 44, 19, 2, 1, "->", 0, 1) == 1) {
			switch (GET_CURSOR_Y())
			{
			case 9: break;
			case 11: break;
			case 13:
			case 15:
			case 17:
			case 19:Account_UI_ModPassword(user); break;
			default:
				break;
			}
		}
		else {
			SysLogin();
		}
	}
}
