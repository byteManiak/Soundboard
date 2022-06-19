#include "event.h"

#include <SDL.h>

void SB_ProcessEvents(SB_App *app)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_CLOSE) app->quit = true;
				break;

			case SDL_QUIT:
				app->quit = true;
				break;
		}
	}
}