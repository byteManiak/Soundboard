#include "render.h"

#include "sdl2_backend.h"

void SB_BeginRender(Backend *backend)
{
	SDL_RenderClear(backend->renderer);
}

void SB_SetDrawColor(Backend *backend, u8 r, u8 g, u8 b, u8 a)
{
	SDL_SetRenderDrawColor(backend->renderer, r, g, b, a);
}

void SB_DrawLine(Backend *backend, i32 x1, i32 y1, i32 x2, i32 y2)
{
	SDL_RenderDrawLine(backend->renderer, x1, y1, x2, y2);
}

void SB_DrawRectangle(Backend *backend, i32 x, i32 y, i32 w, i32 h, bool fill)
{
	SDL_Rect r = {x, y, w, h};

	if (fill)
	{
		SDL_RenderFillRect(backend->renderer, &r);
	}
	else
	{
		SDL_RenderDrawRect(backend->renderer, &r);
	}
}

void SB_EndRender(Backend *backend)
{
	SDL_SetRenderDrawColor(backend->renderer, 0, 0, 0, 0);
	SDL_RenderPresent(backend->renderer);
}