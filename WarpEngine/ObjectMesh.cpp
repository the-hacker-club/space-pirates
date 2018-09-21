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

		// Use the default shader program
		this->shaderProgram = Shader::shaderProgram;

		// Add this game object to the game window to be rendered
		GameWindow::add(this);
	}

	ObjectMesh::~ObjectMesh()
	{
	}

	void ObjectMesh::render()
	{
		glUseProgram(this->shaderProgram);

		// For each uniform, set it in the shader program
		for(Shader::Uniformf * uniform : this->uniforms) {
			uniform->updateUniform();
		}

		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time
		if (this->vData->indices != NULL) {
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		} else {
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}
		// glBindVertexArray(0); // no need to unbind it every time
	}

	// Add a new vertex shader to the list of vertex shaders used on this object.
	// Must make a call to updateShaderProgram() afterwards.
	void ObjectMesh::addVertexShader(const char * vertexShader)
	{
		unsigned int shader = Shader::loadVertexShader(vertexShader);
		this->vertexShader.push_back(shader);

		updateShaderProgram();
	}

	// Add a new fragment shader to the list of fragment shaders used on this object.
	// Must make a call to updateShaderProgram() afterwards.
	void ObjectMesh::addFragmentShader(const char * fragmentShader)
	{
		unsigned int shader = Shader::loadFragmentShader(fragmentShader);
		this->fragmentShader.push_back(shader);

		updateShaderProgram();
	}

	// Update the shader program with the current list of vertexShaders and fragmentShaders
	void ObjectMesh::updateShaderProgram()
	{
		vector<unsigned int> updateVShader = vector<unsigned int>();
		// Use the default vertex shader if none are present
		if (this->vertexShader.size() == 0) {
			updateVShader.push_back(Shader::vertexShader);
		} else {
			updateVShader = this->vertexShader;
		}

		vector<unsigned int> updateFShader = vector<unsigned int>();
		// Use the default fragment shader if none are present
		if (this->fragmentShader.size() == 0) {
			updateFShader.push_back(Shader::fragmentShader);
		} else {
			updateFShader = this->fragmentShader;
		}

		// Update Program
		this->shaderProgram = Shader::createProgram(this->vertexShader, this->fragmentShader);
	}

	// Add a value to set a uniform to in the shader program
	void ObjectMesh::addShaderUniform(Shader::Uniformf * uniform)
	{
		uniform->location = glGetUniformLocation(this->shaderProgram, uniform->name.c_str());

		this->uniforms.push_back(uniform);
	}

}
