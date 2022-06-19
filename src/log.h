#pragma once

#include <cstdio>

#define SB_LogType(type, msg, ...) \
	do { \
		printf("[%s] %s (%d): " msg, type, __func__, __LINE__, ##__VA_ARGS__); \
	} while (0)

#define SB_LogError(msg, ...) SB_LogType("ERROR", msg, ##__VA_ARGS__)
#define SB_LogWarn(msg, ...)  SB_LogType("WARNING", msg, ##__VA_ARGS__)
#define SB_LogInfo(msg, ...)  SB_LogType("INFO", msg, ##__VA_ARGS__)

#define SB_LogError_Goto(label, msg, ...) \
	do { \
		SB_LogError(msg, ##__VA_ARGS__); \
		goto label; \
	} while (0)
