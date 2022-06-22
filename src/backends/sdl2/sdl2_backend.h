#pragma once

#include <SDL.h>
#include <unordered_map>
#include <string>

struct _Backend {
	SDL_Window *window;
	SDL_Renderer *renderer;

	std::unordered_map<std::string, SDL_Texture*> textures;
};
