#include "glslLoader.h"

namespace WarpEngine
{

	WARPENGINE_API const char * glslLoader::load(string fileName)
	{
		ifstream in(fileName);

		string content( (istreambuf_iterator<char>(in) ),
						(istreambuf_iterator<char>()   ) );

		cout << "\n" << content << "\n";

		return content.c_str();
	}

}
