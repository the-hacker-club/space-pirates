#include "Main.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "WarpEngine.h"

using namespace std;
using namespace WarpEngine;

int main() {

	GameWindow* gameWindow = new GameWindow();

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

	ObjectMesh* triangle1 = new ObjectMesh(&triangle1Verts);
	ObjectMesh* triangle2 = new ObjectMesh(&triangle2Verts);

	string testVert = glslLoader::load("test.vert");
	triangle2->addVertexShader(testVert.c_str());
	string yellowFrag = glslLoader::load("yellow.frag");
	triangle2->addFragmentShader(yellowFrag.c_str());
	triangle2->updateShaderProgram();

	while (!gameWindow->shouldClose()) {
		gameWindow->render();
	}

	return 0;
}
