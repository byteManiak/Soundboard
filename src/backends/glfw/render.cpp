#include "render.h"

#include "glfw_backend.h"

void SB_BeginRender(Backend *backend) {}

void SB_SetDrawColor(Backend *backend, u8 r, u8 g, u8 b, u8 a) {}

void SB_DrawLine(Backend *backend, i32 x1, i32 y1, i32 x2, i32 y2) {}

void SB_DrawRectangle(Backend *backend, i32 x, i32 y, i32 w, i32 h, bool fill) {}

void SB_EndRender(Backend *backend) {}