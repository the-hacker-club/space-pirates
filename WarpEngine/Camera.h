#pragma once
#include "_warpEngine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

namespace WarpEngine
{
    class GameWindow;

    class Camera
    {
    public:
        mat4 viewMatrix;
        mat4 projectionMatrix;
        WARPENGINE_API Camera();
        WARPENGINE_API Camera(float fov, float nearPlaneDistance, float farPlaneDistance);
        WARPENGINE_API void translate(float x, float y, float z);
        WARPENGINE_API void translate(vec3 translation);
        WARPENGINE_API ~Camera();
    };
}