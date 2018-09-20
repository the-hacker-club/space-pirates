// WarpEngine.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "_warpEngine.h"
#include <GLFW\glfw3.h>

namespace WarpEngine {

    // Get the current time
    WARPENGINE_API double getTime() {
        return glfwGetTime();
    }
}