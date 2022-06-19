#include "app.h"

#include "event.h"

bool SB_Init(SB_App *app)
{
	memset(app, 0, sizeof(*app));
	if (!SB_Backend_Init(app)) goto fail_init_be;

	return true;

fail_init_be:
	return false;
}

void SB_Destroy(SB_App *app)
{
	SB_Backend_Destroy(app);
}

void SB_Run(SB_App *app)
{
	SB_ProcessEvents(app);
}