#include "stdafx.h"
#include "TTMS_SCU_Account_Srv_Back.h"

void Account_Srv_Back(USER * user)
{
	TTMS_GotoXY(45, 3);
	printf_s("����������ع���Ա%s�Ĳ˵�", user->USER_NAME);
	_getch();
	Account_UI_MgtEntry(user);
}
