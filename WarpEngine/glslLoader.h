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
		static string load(string fileName);
	};

}
