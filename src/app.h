#pragma once

#include <imgui.h>

#if (USING_SDL2 && USING_GLFW && USING_SFML)
#error "Only one backend may be used. Possible options: sdl2, glfw or sfml."
#elif ((USING_SDL2 || USING_GLFW || USING_SFML) == 0)
#error "A backend must be defined. Possible options: sdl2, glfw or sfml."
#endif

typedef struct _Backend_State Backend_State;

typedef struct {
	Backend_State *beState; /* Generic handle to the backend's state */

	bool quit;
} SB_App;

bool SB_Init(SB_App *app);
bool SB_Backend_Init(SB_App *app);

void SB_Destroy(SB_App *app);
void SB_Backend_Destroy(SB_App *app);

void SB_Run(SB_App *app);
