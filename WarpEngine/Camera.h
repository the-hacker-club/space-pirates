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
    private:
        vec3 position;
        vec3 targetPosition;
        vec3 directionVector;
        vec3 rightVector;
        vec3 upVector;
        vec3 forwardVector;
    public:
        float speed;
        mat4 viewMatrix;
        mat4 projectionMatrix;
        WARPENGINE_API Camera();
        WARPENGINE_API Camera(float fov, float nearPlaneDistance, float farPlaneDistance, float cameraSpeed);
        WARPENGINE_API vec3 getPosition();
        WARPENGINE_API vec3 getForwardVector();
        WARPENGINE_API void setPosition(float x, float y, float z);
        WARPENGINE_API void setPosition(vec3 position);
        WARPENGINE_API void translate(float x, float y, float z);
        WARPENGINE_API void translate(vec3 translation);
        WARPENGINE_API void lookAt(vec3 target);
        void _updateCamera();
        WARPENGINE_API ~Camera();
    };
}