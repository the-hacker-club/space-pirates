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
	public:
		WARPENGINE_API GameWindow();
		WARPENGINE_API ~GameWindow();
		WARPENGINE_API int Init();
		WARPENGINE_API int Create(int width, int height);
		WARPENGINE_API void Render();
	};
}
