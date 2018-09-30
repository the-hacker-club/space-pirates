#include "Camera.h"

#include "GameWindow.h"

namespace WarpEngine
{

    Camera::Camera(): Camera(45.0f, 0.1f, 100.0f, 0.05f)
    {

    }

    Camera::Camera(float fov, float nearPlaneDistance, float farPlaneDistance, float speed)
    {
        worldUp = vec3(0.0f, 1.0f, 0.0f);

        this->forwardVector = vec3(0.0f, 0.0f, -1.0f);
        this->speed = speed;
        projectionMatrix = glm::perspective(radians(fov), (float)GameWindow::getInstance()->width / (float)GameWindow::getInstance()->height, nearPlaneDistance, farPlaneDistance);

        position = vec3(0.0f, 0.0f, 3.0f);
        targetPosition = vec3(0.0f, 0.0f, 2.0f);
        // Subtracting two vectors from each other results in the difference between
        // the two vectors. If we subtract the position of the camera from the
        // target, we get a vector pointing towards the camera's positive z-axis.
        directionVector = normalize(position - targetPosition);
        // The name direction vector is not the best chosen name,
        // since it is actually pointing in the reverse direction of what it is targeting. 

        // Calculate the camera right vector
        //  we do a cross product on the up vector and the direction vector from step 2.
        // Since the result of a cross product is a vector perpendicular to both vectors,
        // we will get a vector that points in the positive x-axis's direction (if we
        // would switch the vectors we'd get a vector that points in the negative x-axis): 
        vec3 up = vec3(0.0f, 1.0f, 0.0f);
        rightVector = normalize(cross(up, directionVector));

        // Calculate camera up axis
        upVector = cross(directionVector, rightVector);

        // update view matrix
        //_updateCamera();
    }

    Camera::~Camera()
    {
    }

    vec3 Camera::getForwardVector()
    {
        return forwardVector;
    }

    vec3 Camera::getRightVector()
    {
        return rightVector;
    }

    mat4 Camera::getViewMatrix()
    {
        return glm::lookAt(position, position + forwardVector, upVector);
    }

    vec3 Camera::getPosition()
    {
        return this->position;
    }

    vec3 Camera::getWorldCoordinates()
    {
        return getViewMatrix() * vec4(this->position, 1.0f);
    }

    void Camera::setPosition(float x, float y, float z)
    {
        translate(vec3(x, y, z));
    }

    void Camera::setPosition(vec3 position)
    {
        position = position;

        //_updateCamera();
        // viewMatrix = glm::translate(viewMatrix, translation);
    }

    void Camera::translate(float x, float y, float z)
    {
        translate(vec3(x,y,z));
    }

    void Camera::translate(vec3 translation)
    {
        position += translation;

        //_updateCamera();
    }

    // depricated
    void Camera::lookAt(vec3 target)
    {
        this->targetPosition = target;

        // _updateCamera();
    }

    void Camera::processMouseMovement(float xoffset, float yoffset, bool constrainPitch)
    {
        // scale by sensitivity
        float sensitivity = 0.05f;
        xoffset *= sensitivity;
        yoffset *= sensitivity;

        yaw += xoffset;
        pitch += yoffset;

        if (constrainPitch) {
            if(pitch > 89.0f)
                pitch =  89.0f;
            if(pitch < -89.0f)
                pitch = -89.0f;
        }

        vec3 front;
        front.x = cos(radians(pitch)) * cos(radians(yaw));
        front.y = sin(radians(pitch));
        front.z = cos(radians(pitch)) * sin(radians(yaw));

        forwardVector = normalize(front);
        rightVector = normalize(glm::cross(forwardVector, worldUp));
        upVector = normalize(glm::cross(rightVector, forwardVector));

        // cout << forwardVector.x << ", " << forwardVector.y << ", " << forwardVector.z << endl;
    }

}