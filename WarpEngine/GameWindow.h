#pragma once

#ifdef WARPENGINE_EXPORTS
#define WARPENGINE_API __declspec(dllexport)
#else
#define WARPENGINE_API __declspec(dllimport)
#endif

#include <iostream>

namespace WarpEngine
{
	class GameWindow
	{
	public:
		WARPENGINE_API GameWindow();
		WARPENGINE_API ~GameWindow();
		WARPENGINE_API void Init();
	};
}
