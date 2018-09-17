#pragma once
#include "_warpEngine.h"

#include <glad\glad.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace WarpEngine {
	class Shader
	{
	public:
		// The basicVert shader loaded into gl
		static unsigned int vertexShader;
		// The basicFrag shader loaded into gl
		static unsigned int fragmentShader;
		WARPENGINE_API static const char * basicVert;
		WARPENGINE_API static const char * basicFrag;

		WARPENGINE_API static unsigned int loadVertexShader(const char * vertexSource);
		WARPENGINE_API static unsigned int loadFragmentShader(const char * vertexSource);
		WARPENGINE_API static unsigned int createProgram();
		WARPENGINE_API static unsigned int createProgram(vector<unsigned int> vertexShader, vector<unsigned int> fragmentShader);
		WARPENGINE_API static void useProgram(unsigned int shaderProgram);
		static unsigned int shaderProgram;
	};
}
