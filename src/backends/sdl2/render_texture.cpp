#include "render.h"

#include "sdl2_backend.h"
#include "log.h"
#include "app.h"

#include <SDL_image.h>

bool SB_LoadTexture(SB_App *app, std::string path, std::string name)
{
	bool retValue = false;
	SDL_Texture *texture;

	SDL_Surface *surface = IMG_Load(path.c_str());
	if (!surface) SB_LogError_Goto(fail_surface, "Couldn't load image \"%s\"\n", path.c_str());

	texture = SDL_CreateTextureFromSurface(app->backend->renderer, surface);
	if (!texture) SB_LogError_Goto(fail_texture, "Couldn't create texture \"%s\"", name.c_str());

	if (app->backend->textures.find(name) == app->backend->textures.end())
	{
		app->backend->textures[name] = texture;	
	}

	retValue = true;

fail_texture:
	SDL_free(surface);
fail_surface:
	return retValue;
}

void SB_DrawTexture(SB_App *app, std::string name, i32 x, i32 y, i32 w, i32 h)
{
	auto &textures = app->backend->textures;

	if (textures.find(name) == textures.end())
	{
		SB_LogError("Texture \"%s\" is not loaded in memory.\n", name.c_str());
	}

	SDL_Texture *texture = textures[name];

	SDL_Rect dst = {x, y, w, h};
	SDL_RenderCopy(app->backend->renderer, texture, nullptr, &dst);
}