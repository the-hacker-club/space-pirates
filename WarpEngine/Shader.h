#pragma once
#include "_warpEngine.h"

#include <glad\glad.h>
#include <string>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glslLoader.h"

using namespace std;
using namespace glm;

namespace WarpEngine {
	class Shader
	{
    private:
		vector<unsigned int> vertexShader = vector<unsigned int>();
		vector<unsigned int> fragmentShader = vector<unsigned int>();
		unsigned int shaderProgram;
		// vector<Shader::Uniformf*> uniforms = vector<Shader::Uniformf*>();
		unsigned int _createProgramUsingBasicShaders();
		static unsigned int _createProgram(vector<unsigned int> vertexShader, vector<unsigned int> fragmentShader);
	public:
		static const char * basicVert;
		static const char * basicFrag;
		void updateShaderProgram();

        WARPENGINE_API Shader();
        WARPENGINE_API ~Shader();

		WARPENGINE_API static unsigned int loadVertexShader(const char * vertexSourcePath);
		WARPENGINE_API static unsigned int loadFragmentShader(const char * vertexSourcePath);
		static unsigned int loadVertexShaderFromString(string vertexSourcePath);
		static unsigned int loadFragmentShaderFromString(string vertexSourcePath);

		WARPENGINE_API void addVertexShader(const char * vertexShaderPath);
		WARPENGINE_API void addVertexShader(unsigned int vertexShaderID);
		WARPENGINE_API void addFragmentShader(const char * fragmentShaderPath);
		WARPENGINE_API void addFragmentShader(unsigned int vertexShaderID);
		WARPENGINE_API void useProgram();
		WARPENGINE_API void setInt(string name, int v1);
		WARPENGINE_API void setFloat(string name, float v1);
		WARPENGINE_API void setFloat(string name, float v1, float v2);
		WARPENGINE_API void setFloat(string name, float v1, float v2, float v3);
		WARPENGINE_API void setFloat(string name, float v1, float v2, float v3, float v4);
		WARPENGINE_API void setMatrix(string name, mat4 matrix);
	};
}

