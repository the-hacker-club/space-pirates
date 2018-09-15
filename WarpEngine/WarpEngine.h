#pragma once
#include "GameWindow.h"

// MathLibrary.h - Contains declarations of math functions
#pragma once

#ifdef WARPENGINE_EXPORTS
#define WARPENGINE_API __declspec(dllexport)
#else
#define WARPENGINE_API __declspec(dllimport)
#endif

#include "WarpEngine.h"
