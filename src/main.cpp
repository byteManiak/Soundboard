#include "app.h"

int main()
{
	SB_App app;
	if (!SB_Init(&app)) return -1;

	while(!app.quit) SB_Run(&app);

	SB_Destroy(&app);
	return 0;
}