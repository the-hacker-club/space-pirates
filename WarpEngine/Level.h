#pragma once

#include "_warpEngine.h"

using namespace std;

namespace WarpEngine
{
	class Level
	{
	private:
        Level();
        virtual ~Level();

	public:
        virtual void initialize();
	};
}
