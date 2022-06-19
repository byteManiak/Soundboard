#pragma once

#include <imgui.h>
#include "backend.h"

#if (USING_SDL2 && USING_GLFW && USING_SFML)
#error "Only one backend may be used. Possible options: sdl2, glfw or sfml."
#elif ((USING_SDL2 || USING_GLFW || USING_SFML) == 0)
#error "A backend must be defined. Possible options: sdl2, glfw or sfml."
#endif

typedef struct {
	Backend *backend; /* Opaque handle to backend-specific data */

	bool quit;
} SB_App;

bool SB_Init(SB_App *app);
bool SB_Backend_Init(Backend **backend);

void SB_Destroy(SB_App *app);
void SB_Backend_Destroy(Backend *backend);

void SB_Run(SB_App *app);
