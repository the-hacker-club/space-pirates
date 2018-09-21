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

	vector<int> indicies{
		0, 1, 3,
		1, 2, 3
	};

    // Create Vertex Data for triangle 1
	vector<float> triangle1Verts {
		// position         	// colors
		-1.0f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f,      0.0f, 1.0f, 0.0f,
		 0.0f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f
	};

    vector<vAttribute> v1Attribs = vector<vAttribute>();
    unsigned int index = 0;
    vAttribute va1 = vAttribute(index, 3, WarpEngine::vType::FLOAT, false, 6, 0);
    v1Attribs.push_back(va1);
    index++;
    v1Attribs.push_back(vAttribute(index, 3, WarpEngine::vType::FLOAT, false, 6, 3));
    VertexData t1VertexData = VertexData(&triangle1Verts, &v1Attribs);

    // Create triangle 1
	unique_ptr<ObjectMesh> triangle1 = make_unique<ObjectMesh>(&t1VertexData);

    // Create Vertex Data for triangle 2
	vector<float> triangle2Verts {
		0.0f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		1.0f, -0.5f, 0.0f
	};
    vector<vAttribute> v2Attribs = vector<vAttribute>();
    index = 0;
    v2Attribs.push_back(vAttribute(index, 3, WarpEngine::vType::FLOAT, false, 3, 0));
    VertexData t2VertexData = VertexData(&triangle2Verts, &v2Attribs);

    // Create triangle 2
	unique_ptr<ObjectMesh> triangle2 = make_unique<ObjectMesh>(&t2VertexData);

	// Load triangle 1 shaders
	string rainbowVert = glslLoader::load("rainbow.vert");
	triangle1->addVertexShader(rainbowVert.c_str());
	string rainbowFrag = glslLoader::load("rainbow.frag");
	triangle1->addFragmentShader(rainbowFrag.c_str());

	// Load triangle 2 shaders
	string testVert = glslLoader::load("test.vert");
	triangle2->addVertexShader(testVert.c_str());
	string yellowFrag = glslLoader::load("yellow.frag");
	triangle2->addFragmentShader(yellowFrag.c_str());

	// Set uniform for triangle 2 shaders
	unique_ptr<Shader::Uniform4f> ourColor = make_unique<Shader::Uniform4f>("ourColor", 0.0f, 0.0f, 0.0f, 1.0f);
	triangle2->addShaderUniform(ourColor.get());

	while (!gameWindow->shouldClose()) {
		ourColor->y = (sin(getTime()) / 2.0f) + 0.5f;

		gameWindow->render();
	}

	return 0;
}
