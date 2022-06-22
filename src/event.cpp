#include "event.h"

void SB_ProcessEvents(SB_App *app)
{
	SB_Event event = SB_ProcessNextEvent(app);
	while (event.eventType != NONE_EVENT)
	{
		if (event.eventType == WINDOW_EVENT && event.eventReason == WINDOW_EVENT_CLOSE) app->quit = true;

		event = SB_ProcessNextEvent(app);
	}
}