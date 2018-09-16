#include "Main.h"
#include <iostream>
#include "WarpEngine.h"

using namespace std;
using namespace WarpEngine;

int main() {

	GameWindow* gameWindow = new GameWindow();

	if (gameWindow->create(800, 600) != 0) {
		cout << "Failed to create window.\n";
	}

	while (!gameWindow->shouldClose()) {
		gameWindow->render();
	}

	return 0;
}
