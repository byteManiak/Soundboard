#include "app.h"

#include <SDL.h>
#include "log.h"
#include "_app_backend.h"

bool SB_Backend_Init(SB_App *app)
{
	Backend_State *beState = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) goto fail_init;

	beState = new Backend_State;
	if (!beState) SB_LogError_Goto(fail_alloc, "Couldn't allocate backend state.\n");

	beState->window = SDL_CreateWindow("Soundboard!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_RESIZABLE);
	if (!beState->window) goto fail_create_window;
	beState->renderer = SDL_CreateRenderer(beState->window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	if (!beState->renderer) goto fail_create_renderer;

	app->beState = beState;
	return true;

fail_create_renderer:
	SDL_DestroyWindow(beState->window);
fail_create_window:
	delete(beState);
fail_alloc:
	SDL_Quit();
fail_init:
	return false;
}

void SB_Backend_Destroy(SB_App *app)
{
	SDL_DestroyRenderer(app->beState->renderer);
	SDL_free(app->beState->window);
}