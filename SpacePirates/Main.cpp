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

	//float triangleVerts[] = {
	vector<float> triangleVerts {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	ObjectMesh* triangle = new ObjectMesh(triangleVerts);

	while (!gameWindow->shouldClose()) {
		gameWindow->render();
	}

	return 0;
}
