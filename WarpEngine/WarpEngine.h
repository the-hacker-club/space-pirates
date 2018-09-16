#pragma once
#include "GameWindow.h"

#ifdef WARPENGINE_EXPORTS
#define WARPENGINE_API __declspec(dllexport)
#else
#define WARPENGINE_API __declspec(dllimport)
#endif

