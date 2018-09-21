#pragma once

#ifdef WARPENGINE_EXPORTS
#define WARPENGINE_API __declspec(dllexport)
#else
#define WARPENGINE_API __declspec(dllimport)
#endif

#include "GameWindow.h"
#include "ObjectMesh.h"
#include "VertexData.h"
#include "vAttribute.h"

// Utility
#include "glslLoader.h"

namespace WarpEngine {
    WARPENGINE_API double getTime();
}