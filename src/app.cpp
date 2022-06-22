#include "app.h"

#include "event.h"
#include "render.h"

bool SB_Init(SB_App *app)
{
	memset(app, 0, sizeof(*app));
	if (!SB_Backend_Init(&app->backend)) goto fail_init_be;

	SB_LoadTexture(app, "test.png", "test");
	return true;

fail_init_be:
	return false;
}

void SB_Destroy(SB_App *app)
{
	SB_Backend_Destroy(app->backend);
}

void SB_Run(SB_App *app)
{
	SB_ProcessEvents(app);

	SB_BeginRender(app->backend);
	SB_SetDrawColor(app->backend, 190, 255, 0, 0);
	SB_DrawLine(app->backend, 2, 2, 500, 300);
	SB_DrawTexture(app, "test", 256, 64, 32, 32);
	SB_EndRender(app->backend);
}
