#include "stdafx.h"
#include "TTMS_SCU_Play_UI_Browe.h"

void Play_UI_Browe(USER* user)
{
	int p = 1;
	system("cls");
	int KeyMaX = EntKeyPlay_Perst_CompNewKeys() - 1;
	Play_UI_LookByPage(p);
	char k[15];
	strcpy_s(k, 15, GET_KEY());
	while (strcmp(k, "Esc") != 0)
	{
		if (strcmp(k, "Right") == 0 && p <= KeyMaX / 5)
		{
			Play_UI_LookByPage(++p);
		}
		if (strcmp(k, "Left") == 0 && p > 1)
		{
			Play_UI_LookByPage(--p);
		}
		strcpy_s(k, 15, GET_KEY());
	}
	Play_UI_MgtEntry(user);
}
