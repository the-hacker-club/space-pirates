#include "Main.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <memory>

#include "WarpEngine.h"
#include "levels/TestLevel.h"

using namespace std;
using namespace std::chrono;
using namespace WarpEngine;

double lastX = 400;
double lastY = 300;
bool firstMouse;

void mouseHandler(double mouseX, double mouseY)
{
    if (!firstMouse) {
        lastX = mouseX;
        lastY = mouseY;
        firstMouse = true;
    }

    // cout << mouseX << ", " << mouseY << endl;
    float xoffset = mouseX - lastX;
    float yoffset = lastY - mouseY; // reversed since y-coordinates range from bottom to top

    lastX = mouseX;
    lastY = mouseY;

    GameWindow::getInstance()->mainCamera->processMouseMovement(xoffset, yoffset);
}

void scrollHandler(double xoffset, double yoffset)
{
    GameWindow::getInstance()->mainCamera->processMouseScroll(xoffset, yoffset);
}

int main() {

	//unique_ptr<GameWindow> gameWindow = make_unique<GameWindow>();

    //====================
    // 1. Load Game Window
    //====================

    // Create the window
	if (GameWindow::getInstance()->create(800, 600) != 0) {
		cout << "Failed to create window.\n";
	}

    //====================
    // 2. Load Objects
    //====================

    // load Level
    TestLevel* testLevel = new TestLevel();

    testLevel->load();

    //====================
    // 5. Main Game Loop
    //====================

    // update the main camera
    GameWindow::getInstance()->mainCamera->translate(0.0f, 0.0f, -3.0f);

    // set the mouse handlers
    GameWindow::getInstance()->setMouseHandler(&mouseHandler);
    GameWindow::getInstance()->setMouseScrollHandler(&scrollHandler);

    // lamp->rotate(true, -55.0f, Axis::X_AXIS);
    // cube->rotate(true, -55.0f, Axis::X_AXIS);

	while (!GameWindow::getInstance()->shouldClose()) {
        //====================
        // Update Objects
        //====================
        testLevel->update();

        //====================
        // Render Objects
        //====================
		GameWindow::getInstance()->render();
	}

	return 0;
}
