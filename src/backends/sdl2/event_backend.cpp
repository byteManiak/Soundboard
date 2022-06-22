#include "event.h"

#include <SDL.h>

SB_Event SB_ProcessNextEvent(SB_App *app)
{
	SB_Event retEvent = {};

	SDL_Event event;
	if (SDL_PollEvent(&event) == 0) return retEvent;

	switch (event.type)
	{
		case SDL_WINDOWEVENT:
			if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			{
				retEvent.eventType = WINDOW_EVENT;
				retEvent.eventReason = WINDOW_EVENT_CLOSE;
			}
			break;

		case SDL_QUIT:
			app->quit = true;
			break;
	}

	return retEvent;
}