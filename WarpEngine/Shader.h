#pragma once
#include "_warpEngine.h"

#include <glad\glad.h>
#include <string>
#include <iostream>

using namespace std;

namespace WarpEngine {
	class Shader
	{
	private:
		static unsigned int vertexShader;
		static unsigned int fragmentShader;
	public:
		WARPENGINE_API static const char * basicVert;
		WARPENGINE_API static const char * basicFrag;

		WARPENGINE_API static unsigned int loadVertexShader(const char * vertexSource);
		WARPENGINE_API static unsigned int loadFragmentShader(const char * vertexSource);
		WARPENGINE_API static unsigned int createProgram();
		WARPENGINE_API static void useProgram(unsigned int shaderProgram);
		static unsigned int shaderProgram;
	};
}

