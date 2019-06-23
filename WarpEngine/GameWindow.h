#pragma once

#include "_warpEngine.h"

#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>

#include "Shader.h"
#include "Camera.h"

using namespace std;

namespace WarpEngine
{
	class ObjectMesh;

    void _mouseHandler(GLFWwindow * window, double mouseX, double mouseY);
    void _mouseScrollHandler(GLFWwindow * window, double offsetX, double offsetY);

	class GameWindow
	{
	private:
		static GameWindow * _instance;
		GLFWwindow * window;
		void processInput();
		static vector<ObjectMesh*> gameObjects;
        // TODO Create Command class to handle input
        // http://gameprogrammingpatterns.com/command.html

	public:
        int width;
        int height;
        unique_ptr<Camera> mainCamera;

        void (*mouseHandler)(double mouseX, double mouseY);
        void (*mouseScrollHandler)(double offsetX, double offsetY);
		GameWindow();
		~GameWindow();
		static GameWindow * getInstance();
		static void add(ObjectMesh * gameObject);
		int init();
		int create(int width, int height);
		void render();
		void setMouseHandler(void (*mouseHandler)(double mouseX, double mouseY));
		void setMouseScrollHandler(void (*mouseHandler)(double mouseX, double mouseY));
		void setShouldClose(bool shouldClose);
		int shouldClose();
	};
}
