#include "stdafx.h"
#include "TTMS_SCU_SaleM_UI_Money.h"

void SaleData_UI_Money(USER * user,int power)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	if (power == 1)
	{
		TTMS_GotoXY(53,6);
		char UserName[15];
		printf_s("�������ۻ�Ա����:");
		scanf_s("%s", UserName, 15);
		auto *Sale_User = Account_Perst_FetchByName(UserName);
		if (!Sale_User || Sale_User->power != 2)
		{
			TTMS_GotoXY(55, 19);
			printf_s("û���ҵ�����ƱԱ!");
			_getch();
			Main_UI_MgtEntry(user);
		}
		auto MoneyMax = 0, MoneySale = 0, MoneyReturn= 0, SaleCount = 0, ReturnCount = 0,SaleMaxCount = EntKeySale_Perst_CompNewKeys();
		for (auto i = 0; i <= SaleMaxCount; i++)
		{
			auto *sale = SaleData_Srv_FetchByID(i);
		//	printf_s("%s\n",sale->data.UserAcc);
		//	_getch();
			if (sale && !strcmp(sale->data.UserAcc, Sale_User->USER_ACCOUT))
			{
				if (sale->data.type == SALE_SELL)
				{
					MoneyMax += sale->data.value;
					MoneySale += sale->data.value;
					SaleCount += 1;
				}
				else if (sale->data.type == SALE_RETURN)
				{
					MoneyMax += sale->data.value;
					MoneyReturn += sale->data.value;
					ReturnCount += 1;
				}
			}
		}
		TTMS_GotoXY(52, 6);
		printf_s("   %s���۶����          ", Sale_User->USER_NAME);
		TTMS_GotoXY(47, 9);
		printf_s("�ܽ��׶�: %d", MoneyMax);
		TTMS_GotoXY(47, 11);
		printf_s("��Ʊ���׶�: %d", MoneySale);
		TTMS_GotoXY(47, 13);
		printf_s("��Ʊ���׶�: %d", MoneyReturn);
		TTMS_GotoXY(47, 15);
		printf_s("��Ʊ����: %d", SaleCount);
		TTMS_GotoXY(47, 17);
		printf_s("��Ʊ����: %d", ReturnCount);
		TTMS_GotoXY(52, 23);
		printf_s("������˳�");
		_getch();
		Main_UI_MgtEntry(user);
	}
	else if (power == 2)
	{
		auto MoneyMax = 0, MoneySale = 0, MoneyReturn = 0, SaleCount = 0, ReturnCount = 0, SaleMaxCount = EntKeySale_Perst_CompNewKeys();
		for (auto i = 0; i <= SaleMaxCount; i++)
		{
			auto *sale = SaleData_Srv_FetchByID(i);
			if (sale && !strcmp(sale->data.UserAcc, user->USER_ACCOUT))
			{
			//	printf_s("%d", sale->data.id);
			//	_getch();
				if (sale->data.type == SALE_SELL)
				{
					MoneyMax += sale->data.value;
					MoneySale += sale->data.value;
					SaleCount += 1;
				}
				else if (sale->data.type == SALE_RETURN)
				{
					MoneyMax += sale->data.value;
					MoneyReturn += sale->data.value;
					ReturnCount += 1;
				}
			}
		}
		TTMS_GotoXY(55, 6);
		printf_s("%s���۶����", user->USER_NAME);
		TTMS_GotoXY(47, 9);
		printf_s("�ܽ��׶�: %d", MoneyMax);
		TTMS_GotoXY(47, 11);
		printf_s("��Ʊ���׶�: %d", MoneySale);
		TTMS_GotoXY(47, 13);
		printf_s("��Ʊ���׶�: %d", MoneyReturn);
		TTMS_GotoXY(47, 15);
		printf_s("��Ʊ����: %d", SaleCount);
		TTMS_GotoXY(47, 17);
		printf_s("��Ʊ����: %d", ReturnCount);
		TTMS_GotoXY(52, 23);
		printf_s("������˳�");
		_getch();
		Main_UI_MgtEntry(user);
	}
}
