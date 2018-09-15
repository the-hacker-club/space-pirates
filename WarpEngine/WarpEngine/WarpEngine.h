#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace WarpEngine {
	class GameWindow
	{
	public:
		GameWindow();
		~GameWindow();
		void Init();
	};
}

