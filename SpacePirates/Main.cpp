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

int main() {

	unique_ptr<GameWindow> gameWindow = make_unique<GameWindow>();

    //====================
    // 1. Load Game Window
    //====================

    // Create the window
	if (gameWindow->create(800, 600) != 0) {
		cout << "Failed to create window.\n";
	}

    //====================
    // 2. Load Objects
    //====================

    // Create Vertex Data for triangle 1
	vector<float> triangle1Verts {
		// position         	// colors           // texture coords
		-0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,   0.0f, 0.0f, // bottom left
		 0.0f, 0.5f, 0.0f,      0.0f, 1.0f, 0.0f,   0.5f, 1.0f, // top
		 0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f,   1.0f, 0.0f  // bottom right
	};

	vector<float> rectangleColorVerts {
         // positions        // colors          // texture coords
		 0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f, // top right
		 0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f  // top left 
	};

    vector<float> cubeVerts {
        // position          // colors           // texture
        -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 1.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 1.0f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 1.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 1.0f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 1.0f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 1.0f,  1.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 1.0f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 1.0f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 1.0f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 1.0f,  0.0f, 1.0f
    };

    // Specify vertex attribute data
    // TODO: Update to the VertexData class to compute the index, stride and offset
    // Also, possibly refactor into an addAttribute method on VertexData
    vector<vAttribute> v1Attribs = vector<vAttribute>();
    v1Attribs.push_back(vAttribute(0, 3, WarpEngine::vType::FLOAT, false, 8, 0)); // position attribute
    v1Attribs.push_back(vAttribute(1, 3, WarpEngine::vType::FLOAT, false, 8, 3)); // color attribute
    v1Attribs.push_back(vAttribute(2, 2, WarpEngine::vType::FLOAT, false, 8, 6)); // texture attribute

    VertexData cubeVData = VertexData(&cubeVerts, &v1Attribs);

    VertexData lampVData = VertexData(&cubeVerts, &v1Attribs);

    // Create triangle 1
	unique_ptr<ObjectMesh> lamp = make_unique<ObjectMesh>(&lampVData);

    // Create triangle 2
	unique_ptr<ObjectMesh> cube = make_unique<ObjectMesh>(&cubeVData);

    //====================
    // 3. Load Shaders
    //====================

    // Load shaders
    unsigned int rainbowVert = Shader::loadVertexShader("rainbow.vert");
    unsigned int rainbowFrag = Shader::loadFragmentShader("rainbow.frag");
    unsigned int lampFrag = Shader::loadFragmentShader("lamp.frag");

	// Load triangle 1 shaders
	lamp->shader.addVertexShader(rainbowVert);
	lamp->shader.addFragmentShader(lampFrag);

	// Load triangle 2 shaders
	cube->shader.addVertexShader(rainbowVert);
	cube->shader.addFragmentShader(rainbowFrag);

    //====================
    // 4. Load Textures
    //====================

    // Load the texture for triangle 2
    unsigned int texture1 = cube->loadTexture("container.jpg", false);
    unsigned int texture2 = cube->loadTexture("awesomeface.png", true);

    // use the same texture for triangle 1
    // lamp->addTexture(texture1);
    // lamp->shader.setInt("texture1", 0);
    // lamp->shader.setFloat("lightColor", sin(getTime()), sin(getTime()), sin(getTime()), 0.0f);

    // move the lamp over to the left
    lamp->setPosition(vec3(-1.0f, 0.0f, 0.0f));

	// Set uniform for triangle 2 shaders
    cube->shader.setInt("texture1", 0);
    cube->shader.setInt("texture2", 1);
    cube->shader.setFloat("lightColor", 1.0f, 1.0f, 1.0f, 0.0f);

    //====================
    // 5. Main Game Loop
    //====================

    // update the main camera
    gameWindow->mainCamera->translate(0.0f, 0.0f, -3.0f);

    // set the mouse handler
    gameWindow->setMouseHandler(&mouseHandler);

    // lamp->rotate(true, -55.0f, Axis::X_AXIS);
    // cube->rotate(true, -55.0f, Axis::X_AXIS);

	while (!gameWindow->shouldClose()) {
        //====================
        // Update Objects
        //====================
        // lamp->setPosition(-1.0f, 0.5f, 0.0f);
        float scale = sin((float)getTime());
        // lamp->scale(scale, scale, 1.0f);
        // lamp->rotate(true, -55.0f, Axis::X_AXIS);
        lamp->setRotation(true, -55.0f, Axis::X_AXIS);

        cube->setPosition(0.5f, -0.5f, 0.0f);
        cube->setRotation(true, (float)getTime() * 10, Axis::Z_AXIS);
        cube->rotate(true, -55.0f, Axis::X_AXIS);
        lamp->shader.setFloat("lightColor", sin(getTime()), sin(getTime()), sin(getTime()), 0.0f);
        // cube->rotate(-55.0f, Axis::X_AXIS);

        // update camera position
        // float radius = 10.0f;
        // float camX = sin(getTime()) * radius;
        // float camZ = cos(getTime()) * radius;
        // gameWindow->mainCamera->setPosition(vec3(camX, 0.0f, camZ));
        // cout << gameWindow->mainCamera->getPosition().x << ", " << gameWindow->mainCamera->getPosition().y << ", " << gameWindow->mainCamera->getPosition().z << endl;

        //====================
        // Render Objects
        //====================
		gameWindow->render();
	}

	return 0;
}
