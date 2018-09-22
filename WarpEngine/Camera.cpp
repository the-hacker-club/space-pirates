#include "Camera.h"

#include "GameWindow.h"

namespace WarpEngine
{

    Camera::Camera(): Camera(45.0f, 0.1f, 100.0f)
    {

    }

    Camera::Camera(float fov, float nearPlaneDistance, float farPlaneDistance)
    {
        viewMatrix = mat4(1.0f);
        projectionMatrix = glm::perspective(radians(fov), (float)GameWindow::getInstance()->width / (float)GameWindow::getInstance()->height, nearPlaneDistance, farPlaneDistance);
    }

    Camera::~Camera()
    {
    }

    void Camera::translate(float x, float y, float z)
    {
        translate(vec3(x, y, z));
    }

    void Camera::translate(vec3 translation)
    {
        viewMatrix = glm::translate(viewMatrix, translation);
    }

}