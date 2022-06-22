#pragma once

#include "app.h"

enum SB_EventType {
	NONE_EVENT,
	WINDOW_EVENT,
	QUIT_EVENT
};

enum SB_EventReason {
	WINDOW_EVENT_CLOSE,

	QUIT_EVENT_QUIT
};

typedef struct {
	SB_EventType eventType;
	SB_EventReason eventReason;
	void *eventData;
} SB_Event;

SB_Event SB_ProcessNextEvent(SB_App *app);

void SB_ProcessEvents(SB_App *app);