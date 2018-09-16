#include "Main.h"
#include <iostream>
#include "WarpEngine.h"

using namespace std;
using namespace WarpEngine;

int main() {

	GameWindow* gameWindow = new GameWindow();

	if (gameWindow->Init() != 0) {
		cout << "Failed to initialize game window.\n";
	}

	if (gameWindow->Create(800, 600) != 0) {
		cout << "Failed to create window.\n";
	}

	while (true) {
		gameWindow->Render();
	}

	return 0;
}
