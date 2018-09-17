#pragma once

#include "_warpEngine.h"

#include <glad\glad.h>
#include <vector>
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
	public:
		WARPENGINE_API ObjectMesh(vector<float> * vertices, vector<int> * indices);
		WARPENGINE_API ObjectMesh(vector<float> * vertices);
		WARPENGINE_API ~ObjectMesh();
		WARPENGINE_API void render();
	};

}
