#include "ObjectMesh.h"

#include <iostream>

using namespace std;

namespace WarpEngine
{
	ObjectMesh::ObjectMesh(VertexData * vData): vData(vData)
	{
		// TODO: May need to refactor this out into a static
		// method for all the object meshes created, not just 1
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		// Generate Element Buffer Object
		if (vData->indices != NULL) {
			glGenBuffers(1, &EBO);
		}
		// Bind Vertex Array Object
		glBindVertexArray(VAO);
		// 0. Copy our vertices array in a buffer for OpenGL to use
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		unsigned int size = this->vData->vertices->size() * sizeof(float);
		glBufferData(GL_ARRAY_BUFFER, size, this->vData->vertices->data(), GL_STATIC_DRAW);

		if (this->vData->indices != NULL) {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			size = this->vData->indices->size() * sizeof(int);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, this->vData->indices->data(), GL_STATIC_DRAW);
		}

		// 1. then set the vertex attributes pointers

        for (int i=0; i < (int)vData->vAttributes->size(); i++) {
            vData->vAttributes->operator[](i).enable();
        }

		// ====================
		// Unbind buffers
		// ====================

		// Unbind the VBO as the call to glVertexAttribPointer registered
		// VBO as the vertex attribute's bound vertex buffer object
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// DO NOT unbind EBO while a VAO is active as the boudn element buffer object
		// IS stored in the VAO
		// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		// Unbind the VAO so other VAO calls won't accidentally modify this VAO	
		glBindVertexArray(0);

		// Wireframe mode
		if (wireframeMode) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}

        // Call this to compile the default shaders
        this->shader.updateShaderProgram();

		// Add this game object to the game window to be rendered
		GameWindow::add(this);
	}

	ObjectMesh::~ObjectMesh()
	{
	}

	void ObjectMesh::render()
	{
        this->shader.useProgram();

        // bind each texture
        for(int i=0; i<this->texture.size(); i++) {
            glActiveTexture(glTexture[i]);
            glBindTexture(GL_TEXTURE_2D, this->texture[i]);
        }

		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time
		if (this->vData->indices != NULL) {
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		} else {
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}
		// glBindVertexArray(0); // no need to unbind it every time
	}

    // load a new texture and apply it to this object. Returns the reference id to the texture loaded
    unsigned int ObjectMesh::loadTexture(string texturePath, bool hasAlpha)
    {
        unsigned int texture;
        // load the texture
        glGenTextures(1, &texture);

        // bind the texture
        glBindTexture(GL_TEXTURE_2D, texture);

        // set the texture wrapping/filtering options (on the currently bound texture object)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // generate the texture
        int textureWidth, textureHeight, nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char *data = stbi_load(texturePath.c_str(), &textureWidth, &textureHeight, &nrChannels, 0);
        if (data) {
            unsigned int format = GL_RGB;
            if (hasAlpha) {
                format = GL_RGBA;
            }
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            cout << "Failed to load texture '" << texturePath << "'." << endl;
        }

        // free the image memory
        stbi_image_free(data);

        this->texture.push_back(texture);

        return texture;
    }

    // set the texture to use on this object
    void ObjectMesh::addTexture(unsigned int textureID)
    {
        texture.push_back(textureID);
    }

}
