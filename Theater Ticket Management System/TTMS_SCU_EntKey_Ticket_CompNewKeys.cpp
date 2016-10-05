#include "stdafx.h"
#include "TTMS_SCU_EntKey_Ticket_CompNewKeys.h"

int EntKeyTicket_Perst_CompNewKeys()
{
	FILE *fp;
	int key;
	errno_t err;
	if ((err = fopen_s(&fp, "EntityKeyTicket.dat", "r") == 0)) {
		fseek(fp, 0, SEEK_END);
		if (ftell(fp) == 0)
		{
			fprintf_s(fp, "%d", 0);
			fclose(fp);
			return 0;
		}
		fseek(fp, 0, SEEK_SET);
		fscanf_s(fp, "%d", &key);
		fclose(fp);
		return key;
	}
	else {
		fopen_s(&fp, "EntitykeyTicket.dat", "w");
		fprintf_s(fp, "%d", 0);
		fclose(fp);
		return 0;
	}
	return 0;
}
