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
        vec3 worldUp;
        vec3 rightVector;
        vec3 upVector;
        vec3 forwardVector;
        float nearPlaneDistance;
        float farPlaneDistance;
    public:
        float speed;
        float pitch = 0.0f;
        float yaw = -90.0f;
        float zoom = 45.0f;
        Camera();
        Camera(float fov, float nearPlaneDistance, float farPlaneDistance, float cameraSpeed);
        vec3 getWorldCoordinates();
        vec3 getPosition();
        vec3 getForwardVector();
        vec3 getRightVector();
		mat4 getViewMatrix();
		mat4 getProjectionMatrix();
        void setPosition(float x, float y, float z);
        void setPosition(vec3 position);
        void translate(float x, float y, float z);
        void translate(vec3 translation);
        void lookAt(vec3 target);
        void processMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);
        void processMouseScroll(float xoffset, float yoffset);
        ~Camera();
    };
}
