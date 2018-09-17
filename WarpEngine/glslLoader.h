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
		WARPENGINE_API static string load(string fileName);
	};

}
