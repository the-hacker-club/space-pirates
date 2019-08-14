#include "WarpEngine.h"
#include <chrono>

using namespace WarpEngine;

class TestLevel : public WarpEngine::Level {
private:
    vec3 lightPos;

    vector<vAttribute> v1Attribs;
    unique_ptr<VertexData> lampVData;
    vector<vAttribute> v2Attribs;
    unique_ptr<VertexData> cubeVData;

    unique_ptr<ObjectMesh> cube;
    unique_ptr<ObjectMesh> lamp;

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

    vector<float> cubeVertsWithNormals {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };
public:
    TestLevel();

    void load();
    void update();
};
