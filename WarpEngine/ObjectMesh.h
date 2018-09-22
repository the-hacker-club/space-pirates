#pragma once

#include "_warpEngine.h"

#include <glad\glad.h>
#include <vector>
#include <memory>
#include "GameWindow.h"
#include "Shader.h"
#include "VertexData.h"
#include "stb_image.h"

using namespace std;

namespace WarpEngine
{

	class ObjectMesh
	{
	private:
        const unsigned int glTexture[16] =
        {
            GL_TEXTURE0,
            GL_TEXTURE1,
            GL_TEXTURE2,
            GL_TEXTURE3,
            GL_TEXTURE4,
            GL_TEXTURE5,
            GL_TEXTURE6,
            GL_TEXTURE7,
            GL_TEXTURE8,
            GL_TEXTURE9,
            GL_TEXTURE10,
            GL_TEXTURE11,
            GL_TEXTURE12,
            GL_TEXTURE13,
            GL_TEXTURE14,
            GL_TEXTURE15
        };
		bool wireframeMode;
        VertexData * vData;
		unsigned int VBO;
		unsigned int VAO;
		unsigned int EBO;
        vector<unsigned int> texture = vector<unsigned int>();
	protected:
	public:
        Shader shader;
		WARPENGINE_API ObjectMesh(VertexData * vData);
		WARPENGINE_API ~ObjectMesh();
		WARPENGINE_API unsigned int loadTexture(string texturePath, bool hasAlpha);
		WARPENGINE_API void addTexture(unsigned int textureID);
		WARPENGINE_API void render();
	};

}
