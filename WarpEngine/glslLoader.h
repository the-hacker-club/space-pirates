#pragma once
#include "_warpEngine.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace WarpEngine
{

	class glslLoader
	{
	public:
		WARPENGINE_API static const char* load(string fileName);
	};

}
