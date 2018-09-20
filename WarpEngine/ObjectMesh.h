#pragma once

#include "_warpEngine.h"

#include <glad\glad.h>
#include <vector>
#include <memory>
#include "GameWindow.h"
#include "glslLoader.h"
#include "Shader.h"

using namespace std;

namespace WarpEngine
{

	class ObjectMesh
	{
	private:
		vector<float> * vertices;
		vector<int> * indices;
		bool wireframeMode;
		unsigned int VBO;
		unsigned int VAO;
		unsigned int EBO;
		vector<unsigned int> vertexShader = vector<unsigned int>();
		vector<unsigned int> fragmentShader = vector<unsigned int>();
		unsigned int shaderProgram;
		vector<Shader::Uniformf*> uniforms = vector<Shader::Uniformf*>();
	public:
		WARPENGINE_API ObjectMesh(vector<float> * vertices, vector<int> * indices);
		WARPENGINE_API ObjectMesh(vector<float> * vertices);
		WARPENGINE_API ~ObjectMesh();
		WARPENGINE_API void addVertexShader(const char * vertexShader);
		WARPENGINE_API void addFragmentShader(const char * fragmentShader);
		WARPENGINE_API void updateShaderProgram();
		WARPENGINE_API void addShaderUniform(Shader::Uniformf * uniform);
		WARPENGINE_API void render();
	};

}
