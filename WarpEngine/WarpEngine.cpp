// WarpEngine.cpp : Defines the exported functions for the DLL application.
//

// TODO: check if WINDOWS
// #include "stdafx.h"
// #include "_warpEngine.h"

// TODO: if WINDOWS, change slashes to back-slash
#include <GLFW/glfw3.h>

namespace WarpEngine {

    // Get the current time
    double getTime() {
        return glfwGetTime();
    }
}
