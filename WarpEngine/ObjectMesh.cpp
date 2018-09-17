#include "ObjectMesh.h"

#include <iostream>

using namespace std;

namespace WarpEngine
{

	ObjectMesh::ObjectMesh(vector<float> * vertices): ObjectMesh(vertices, NULL)
	{

	}

	ObjectMesh::ObjectMesh(vector<float> * vertices, vector<int> * indices): vertices(vertices), indices(indices)
	{
		// TODO: May need to refactor this out into a static
		// method for all the object meshes created, not just 1
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		// Generate Element Buffer Object
		if (indices != NULL) {
			glGenBuffers(1, &EBO);
		}
		// Bind Vertex Array Object
		glBindVertexArray(VAO);
		// 0. Copy our vertices array in a buffer for OpenGL to use
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		unsigned int size = this->vertices->size() * sizeof(float);
		glBufferData(GL_ARRAY_BUFFER, size, vertices->data(), GL_STATIC_DRAW);

		if (indices != NULL) {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			size = this->indices->size() * sizeof(int);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices->data(), GL_STATIC_DRAW);
		}

		// TODO: Will need to move this into the shader class
		// and have shaders specify the vertex attributes
		// 1. then set the vertex attributes pointers
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		GameWindow::add(this);
	}

	ObjectMesh::~ObjectMesh()
	{
	}

	void ObjectMesh::render()
	{
		glUseProgram(Shader::shaderProgram);
		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time
		if (indices != NULL) {
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		} else {
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}
		// glBindVertexArray(0); // no need to unbind it every time
	}

}
