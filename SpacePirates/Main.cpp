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

	vector<int> indicies{
		0, 1, 3,
		1, 2, 3
	};

	ObjectMesh* triangle = new ObjectMesh(&rectangleVerts, &indicies);

	while (!gameWindow->shouldClose()) {
		gameWindow->render();
	}

	return 0;
}
