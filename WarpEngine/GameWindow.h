#pragma once

#ifdef WARPENGINE_EXPORTS
#define WARPENGINE_API __declspec(dllexport)
#else
#define WARPENGINE_API __declspec(dllimport)
#endif

#include <iostream>

#include <glad\glad.h>
#include <GLFW\glfw3.h>

namespace WarpEngine
{

	class GameWindow
	{
	private:
		GLFWwindow* window;
		void processInput();
	public:
		WARPENGINE_API GameWindow();
		WARPENGINE_API ~GameWindow();
		WARPENGINE_API int init();
		WARPENGINE_API int create(int width, int height);
		WARPENGINE_API void render();
		WARPENGINE_API void setShouldClose(bool shouldClose);
		WARPENGINE_API int shouldClose();
	};
}
