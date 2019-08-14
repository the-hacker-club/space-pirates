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
        // TODO: Look into use of virtual destructor?
        // virtual ~Level();
        virtual ~Level();
        virtual void load() = 0;
        virtual void update() = 0;
	};
}
