#pragma once

#include "_warpEngine.h"

#include <iostream>
#include <vector>
#include <glad\glad.h>
#include <GLFW\glfw3.h>
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

		WARPENGINE_API GameWindow();
		WARPENGINE_API ~GameWindow();
		WARPENGINE_API static GameWindow * getInstance();
		static void add(ObjectMesh * gameObject);
		WARPENGINE_API int init();
		WARPENGINE_API int create(int width, int height);
		WARPENGINE_API void render();
		WARPENGINE_API void setShouldClose(bool shouldClose);
		WARPENGINE_API int shouldClose();
	};
}
