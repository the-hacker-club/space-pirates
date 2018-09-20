#include "Main.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <memory>

#include "WarpEngine.h"

using namespace std;
using namespace std::chrono;
using namespace WarpEngine;

int main() {

	unique_ptr<GameWindow> gameWindow = make_unique<GameWindow>();

	if (gameWindow->create(800, 600) != 0) {
		cout << "Failed to create window.\n";
	}

	vector<float> rectangleVerts {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};

	vector<float> triangleVerts {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	vector<float> triangle1Verts {
		-1.0f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		 0.0f, -0.5f, 0.0f
	};

	vector<float> triangle2Verts {
		0.0f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		1.0f, -0.5f, 0.0f
	};

	vector<int> indicies{
		0, 1, 3,
		1, 2, 3
	};

	unique_ptr<ObjectMesh> triangle1 = make_unique<ObjectMesh>(&triangle1Verts);
	unique_ptr<ObjectMesh> triangle2 = make_unique<ObjectMesh>(&triangle2Verts);

	string testVert = glslLoader::load("test.vert");
	triangle2->addVertexShader(testVert.c_str());
	string yellowFrag = glslLoader::load("yellow.frag");
	triangle2->addFragmentShader(yellowFrag.c_str());
	triangle2->updateShaderProgram();
	unique_ptr<Shader::Uniform4f> ourColor = make_unique<Shader::Uniform4f>("ourColor", 0.0f, 0.0f, 0.0f, 1.0f);
	triangle2->addShaderUniform(ourColor.get());

	while (!gameWindow->shouldClose()) {
		ourColor->y = (sin(getTime()) / 2.0f) + 0.5f;

		gameWindow->render();
	}

	return 0;
}
