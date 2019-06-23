#include "glslLoader.h"

namespace WarpEngine
{

	string glslLoader::load(string fileName)
	{
		ifstream in(fileName);

		string content( (istreambuf_iterator<char>(in) ),
						(istreambuf_iterator<char>()   ) );

		cout << "\n" << content << "\n";

		return content;
	}

}
