#pragma once

#include "_warpEngine.h"

#include <iostream>
#include <vector>
#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include "Shader.h"

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
	public:
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
