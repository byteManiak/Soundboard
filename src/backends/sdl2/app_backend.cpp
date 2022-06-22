#include "app.h"

#include <SDL.h>
#include "log.h"
#include "sdl2_backend.h"

bool SB_Backend_Init(Backend **backend)
{
	Backend *newBackend = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) goto fail_init;

	newBackend = new Backend;
	if (!newBackend) SB_LogError_Goto(fail_alloc, "Couldn't allocate backend state.\n");

	newBackend->window = SDL_CreateWindow("Soundboard!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_RESIZABLE);
	if (!newBackend->window) goto fail_create_window;
	newBackend->renderer = SDL_CreateRenderer(newBackend->window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	if (!newBackend->renderer) goto fail_create_renderer;

	newBackend->textures.reserve(1024);

	*backend = newBackend;
	return true;

fail_create_renderer:
	SDL_DestroyWindow(newBackend->window);
fail_create_window:
	delete(newBackend);
fail_alloc:
	SDL_Quit();
fail_init:
	return false;
}

void SB_Backend_Destroy(Backend *backend)
{
	SDL_DestroyRenderer(backend->renderer);
	SDL_free(backend->window);
}
