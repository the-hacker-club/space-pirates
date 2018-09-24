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

    // Specify vertex attribute data
    vector<vAttribute> v1Attribs = vector<vAttribute>();
    v1Attribs.push_back(vAttribute(0, 3, WarpEngine::vType::FLOAT, false, 8, 0)); // position attribute
    v1Attribs.push_back(vAttribute(1, 3, WarpEngine::vType::FLOAT, false, 8, 3)); // color attribute
    v1Attribs.push_back(vAttribute(2, 2, WarpEngine::vType::FLOAT, false, 8, 6)); // texture attribute
    VertexData t1VertexData = VertexData(&triangle1Verts, &v1Attribs);

    // Create triangle 1
	unique_ptr<ObjectMesh> triangle1 = make_unique<ObjectMesh>(&t1VertexData);

    // Create Vertex Data for triangle 2
	vector<float> triangle2Verts {
		0.0f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		1.0f, -0.5f, 0.0f
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
	vector<int> indicies{
		0, 1, 3,
		1, 2, 3
	};
    vector<vAttribute> v2Attribs = vector<vAttribute>();
    // TODO: Update to the VertexData class to compute the index, stride and offset
    // Also, possibly refactor into an addAttribute method on VertexData
    v2Attribs.push_back(vAttribute(0, 3, WarpEngine::vType::FLOAT, false, 8, 0)); // position attribute
    v2Attribs.push_back(vAttribute(1, 3, WarpEngine::vType::FLOAT, false, 8, 3)); // color attribute
    v2Attribs.push_back(vAttribute(2, 2, WarpEngine::vType::FLOAT, false, 8, 6)); // texture attribute
    VertexData t2VertexData = VertexData(&cubeVerts, &v2Attribs);

    // Create triangle 2
	unique_ptr<ObjectMesh> triangle2 = make_unique<ObjectMesh>(&t2VertexData);

    //====================
    // 3. Load Shaders
    //====================

    // Load shaders
    unsigned int rainbowVert = Shader::loadVertexShader("rainbow.vert");
    unsigned int rainbowFrag = Shader::loadFragmentShader("rainbow.frag");

	// Load triangle 1 shaders
	triangle1->shader.addVertexShader(rainbowVert);
	triangle1->shader.addFragmentShader(rainbowFrag);

	// Load triangle 2 shaders
	triangle2->shader.addVertexShader(rainbowVert);
	triangle2->shader.addFragmentShader(rainbowFrag);

    //====================
    // 4. Load Textures
    //====================

    // Load the texture for triangle 2
    unsigned int texture1 = triangle2->loadTexture("container.jpg", false);
    unsigned int texture2 = triangle2->loadTexture("awesomeface.png", true);

    // use the same texture for triangle 1
    triangle1->addTexture(texture1);
    triangle1->shader.setInt("texture1", 0);

	// Set uniform for triangle 2 shaders
    triangle2->shader.setInt("texture1", 0);
    triangle2->shader.setInt("texture2", 1);

    //====================
    // 5. Main Game Loop
    //====================

    // update the main camera
    gameWindow->mainCamera->translate(0.0f, 0.0f, -3.0f);

    // triangle1->rotate(true, -55.0f, Axis::X_AXIS);
    // triangle2->rotate(true, -55.0f, Axis::X_AXIS);

	while (!gameWindow->shouldClose()) {
        // Update Objects
        triangle1->translate(-0.5f, 0.5f, 0.0f);
        float scale = sin((float)getTime());
        // triangle1->scale(scale, scale, 1.0f);
        // triangle1->rotate(true, -55.0f, Axis::X_AXIS);
        triangle1->setRotation(true, -55.0f, Axis::X_AXIS);

        triangle2->translate(0.5f, -0.5f, 0.0f);
        triangle2->setRotation(true, (float)getTime() * 10, Axis::Z_AXIS);
        triangle2->rotate(true, -55.0f, Axis::X_AXIS);
        // triangle2->rotate(-55.0f, Axis::X_AXIS);

        // Render Objects
		gameWindow->render();
	}

	return 0;
}
