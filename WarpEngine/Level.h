#pragma once

#include "_warpEngine.h"

using namespace std;

namespace WarpEngine
{
	class Level
	{
	private:

	public:
        Level();
        virtual ~Level();
        virtual void load() = 0;
        virtual void update() = 0;
	};
}
