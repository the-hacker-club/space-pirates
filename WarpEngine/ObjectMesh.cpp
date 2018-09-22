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
        for(unsigned int i=0; i < this->texture.size(); i++) {
            glActiveTexture(glTexture[i]);
            glBindTexture(GL_TEXTURE_2D, this->texture[i]);
        }

        // apply transforms
        this->_transform = mat4(1.0f);
        // Keep this order for now, but eventuatlly we may need to push translations into a stack
        // and pop them and apply them in the order they were received.

        // translate
        this->_transform = glm::translate(this->_transform, this->_translation);

        // rotate
        this->_transform = glm::rotate(this->_transform, this->_rotation.x_degree, vec3(1.0f, 0.0f, 0.0f));
        this->_transform = glm::rotate(this->_transform, this->_rotation.y_degree, vec3(0.0f, 1.0f, 0.0f));
        this->_transform = glm::rotate(this->_transform, this->_rotation.z_degree, vec3(0.0f, 0.0f, 1.0f));

        // scale
        this->_transform = glm::scale(this->_transform, this->_scale);
        this->shader.setMatrix("model", this->_transform);

        // we don't need to reset these values (for now) because we only update them once, not each frame
        this->shader.setMatrix("view", GameWindow::getInstance()->mainCamera->viewMatrix);
        this->shader.setMatrix("projection", GameWindow::getInstance()->mainCamera->projectionMatrix);

        // reset the model after we've applied it
        this->_transform = mat4(1.0f);

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
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

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

    void ObjectMesh::translate(float x, float y, float z)
    {
        // TODO: apply this translation to the previous translation
        this->_translation = vec3(x, y, z);
    }

    void ObjectMesh::translate(vec3 translate)
    {
        // TODO: apply this translation to the previous translation
        this->_translation = translate;
    }

    // Sets the rotation of the object.
    void ObjectMesh::setRotation(bool radians, float degrees, Axis axis)
    {
        float angle = degrees;
        if (radians) {
            angle = glm::radians(degrees);
        }

        if (axis == X_AXIS) {
            this->_rotation.set(angle, 0.0f, 0.0f);
        } else if (axis == Y_AXIS) {
            this->_rotation.set(0.0f, angle, 0.0f);
        } else if (axis == Z_AXIS) {
            this->_rotation.set(0.0f, 0.0f, angle);
        }
    }

    void ObjectMesh::setRotation(float degrees, Axis axis)
    {
        setRotation(false, degrees, axis);
    }

    // Rotate the objects transform by degrees, over the axis.
    // This will add to any previous rotation present.
    // Also see setRotation
    void ObjectMesh::rotate(bool radians, float degrees, Axis axis)
    {
        float angle = degrees;
        if (radians) {
            angle = glm::radians(degrees);
        }
        this->_rotation.rotate(angle, axis);
    }

    void ObjectMesh::rotate(float degrees, Axis axis)
    {
        rotate(false, degrees, axis);
    }

    void ObjectMesh::scale(vec3 scale)
    {
        this->_scale = scale;
    }

    void ObjectMesh::scale(float x, float y, float z)
    {
        this->_scale = vec3(x, y, z);
    }
}
