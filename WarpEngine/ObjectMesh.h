#pragma once

#include "_warpEngine.h"

#include <glad\glad.h>
#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "GameWindow.h"
#include "Shader.h"
#include "VertexData.h"
#include "stb_image.h"

using namespace std;
using namespace glm;

namespace WarpEngine
{
    enum Axis
    {
        X_AXIS,
        Y_AXIS,
        Z_AXIS
    };

	class ObjectMesh
	{
	private:

        class Rotation
        {
        public:
            float x_degree = 0.0f;
            float y_degree = 0.0f;
            float z_degree = 0.0f;
            Rotation() { }
            void set(float x, float y, float z) {
                this->x_degree = x;
                this->y_degree = y;
                this->z_degree = z;
            }
            void rotate(float degree, Axis axis)
            {
                if (axis == X_AXIS) {
                    this->x_degree += degree;
                } else if (axis == Y_AXIS) {
                    this->y_degree += degree;
                } else if (axis == Z_AXIS) {
                    this->z_degree += degree;
                }
            }
        };

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
        mat4 _transform = mat4(1.0f);
        vec3 _translation = vec3(0.0f, 0.0f, 0.0f);
        vec3 _scale = vec3(1.0f, 1.0f, 1.0f);
        Rotation _rotation = Rotation();
	public:
        Shader shader;
		WARPENGINE_API ObjectMesh(VertexData * vData);
		WARPENGINE_API ~ObjectMesh();
		WARPENGINE_API unsigned int loadTexture(string texturePath, bool hasAlpha);
		WARPENGINE_API void addTexture(unsigned int textureID);
		WARPENGINE_API void render();
		WARPENGINE_API void setPosition(vec3 translate);
		WARPENGINE_API void setPosition(float x, float y, float z);
		WARPENGINE_API void setRotation(bool radians, float degrees, Axis axis);
		WARPENGINE_API void setRotation(float degrees, Axis axis);
		WARPENGINE_API void rotate(bool radians, float degrees, Axis axis);
		WARPENGINE_API void rotate(float degrees, Axis axis);
		WARPENGINE_API void scale(vec3 scale);
		WARPENGINE_API void scale(float x, float y, float z);
	};

}
