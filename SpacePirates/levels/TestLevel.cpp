#include "TestLevel.h"

using namespace std;
using namespace std::chrono;

TestLevel::TestLevel() : lightPos(1.2f, 1.0f, 2.0f) {
}

void TestLevel::load() {

    //========================================
    // Specify vertex attribute data
    //========================================
    // TODO: Update to the VertexData class to compute the index, stride and offset
    // Also, possibly refactor into an addAttribute method on VertexData
    // Create  v1 attribtues, including position, color and texture
    v1Attribs = vector<vAttribute>();
    v1Attribs.push_back(vAttribute(0, 3, WarpEngine::vType::FLOAT, false, 8, 0)); // position attribute
    v1Attribs.push_back(vAttribute(1, 3, WarpEngine::vType::FLOAT, false, 8, 3)); // color attribute
    v1Attribs.push_back(vAttribute(2, 2, WarpEngine::vType::FLOAT, false, 8, 6)); // texture attribute

    lampVData = make_unique<VertexData>(&cubeVerts, &v1Attribs);

    // Create v2 attributes, including position and normals
    v2Attribs = vector<vAttribute>();
    v2Attribs.push_back(vAttribute(0, 3, WarpEngine::vType::FLOAT, false, 8, 0)); // position attribute
    v2Attribs.push_back(vAttribute(1, 3, WarpEngine::vType::FLOAT, false, 8, 3)); // normal attribute
    v2Attribs.push_back(vAttribute(2, 2, WarpEngine::vType::FLOAT, false, 8, 6)); // texture coords

    cubeVData = make_unique<VertexData>(&cubeVertsWithNormals, &v2Attribs);

    // Create triangle 1
	lamp = make_unique<ObjectMesh>(lampVData.get());
    lamp->setPosition(lightPos); // move the lamp over to the left
    lamp->scale(vec3(0.2f));

    // Create triangle 2
	cube = make_unique<ObjectMesh>(cubeVData.get());

    //====================
    // 3. Load Shaders
    //====================

    // Load shaders
    unsigned int rainbowVert = Shader::loadVertexShader("rainbow.vert");
    unsigned int rainbowFrag = Shader::loadFragmentShader("rainbow.frag");
    unsigned int lightFrag = Shader::loadFragmentShader("light.frag");
    unsigned int normalVert = Shader::loadVertexShader("normal.vert");
    unsigned int normalFrag = Shader::loadFragmentShader("normal.frag");

	// Load triangle 1 shaders
	lamp->shader.addVertexShader(rainbowVert);
	lamp->shader.addFragmentShader(lightFrag);

	// Set uniform for lamp shaders
	lamp->shader.setFloat("lightColor", 1.0f, 1.0f, 1.0f, 0.0f);

	// Load triangle 2 shaders
	cube->shader.addVertexShader(normalVert);
	cube->shader.addFragmentShader(normalFrag);

    //====================
    // 4. Load Textures
    //====================

    // Load the texture for triangle 2
    int containerTex = cube->loadTexture("container2.png", true);
    int specularTex = cube->loadTexture("container2_specular.png", true);
    int emissionTex = cube->loadTexture("matrix.jpg", false);

	// Set uniform for cube shaders
    cube->shader.setInt("texture1", 0);
    cube->shader.setInt("texture2", 1);
    cube->shader.setFloat("lightColor", 1.0f, 1.0f, 1.0f, 1.0f);
    cout << "containerTex: " << containerTex << endl;
    cube->shader.setInt("material.diffuse", containerTex);
    cube->shader.setInt("material.specular", specularTex);
    cube->shader.setInt("material.emission", emissionTex);
    // Blank material
    // cube->shader.setFloat("material.ambient", 1.0f, 1.0f, 1.0f);
    // cube->shader.setFloat("material.diffuse", 1.0f, 1.0f, 1.0f);
    // cube->shader.setFloat("material.specular", 0.5f, 0.5f, 0.5f);
    // cube->shader.setFloat("material.shininess", 32);
    
    // Red Plastic
    cube->shader.setFloat("material.ambient", 0.5f, 0.0f, 0.0f);
    cube->shader.setFloat("material.diffuse", 0.5f, 0.0f, 0.0f); // color
    cube->shader.setFloat("material.specular", 0.7f, 0.6f, 0.6f); // red shiny
    cube->shader.setFloat("material.shininess", 25);

    cube->shader.setFloat("dlight.ambient", 0.2f, 0.2f, 0.2f);
    cube->shader.setFloat("dlight.diffuse", 1.0f, 1.0f, 1.0f); // darken the light a bit to fit the scene
    cube->shader.setFloat("dlight.specular", 1.0f, 1.0f, 1.0f);
}

void TestLevel::update() {
    // lamp->setPosition(1.2f, 1.0f, 2.0f);
    // float scale = sin((float)getTime());
    // lamp->scale(scale, scale, 1.0f);
    // lamp->rotate(true, -55.0f, Axis::X_AXIS);
    // lamp->setRotation(true, -55.0f, Axis::X_AXIS);

    // cube->setPosition(0.5f, -0.5f, 0.0f);
    // Update the cubes transform
    cube->setRotation(true, (float)getTime() * 10, Axis::Z_AXIS);
    // Get light coordinates in the world coordinates
    // vec3 lightWorldPos = cube->getRelativeCoordinates(lightPos);
    // cube->shader.setFloat("lightPos", lightWorldPos.x, lightWorldPos.y, lightWorldPos.z);
    // cube->shader.setFloat("lightPos", lightWorldPos.x, lightWorldPos.y, lightWorldPos.z);
    // cube->rotate(true, -55.0f, Axis::X_AXIS);
    // cube->shader.setFloat("lightColor", sin(getTime()), sin(getTime()), sin(getTime()), 0.0f);
    // cube->rotate(-55.0f, Axis::X_AXIS);

    // update light position
    float radius = 2.0f;
    float lightX = sin(getTime()) * radius;
    float lightZ = cos(getTime()) * radius;
    lamp->setPosition(vec3(lightX, 1.0f, lightZ));
    // cout << "lightPos: " << lamp->getPosition().x << ", " << lamp->getPosition().y << ", " << lamp->getPosition().z << endl;
    cube->shader.setFloat("dlight.direction", lamp->getPosition().x, lamp->getPosition().y, lamp->getPosition().z);

    vec3 camPos = GameWindow::getInstance()->mainCamera.get()->getPosition();
    // cout << "camPos: " << camPos.x << ", " << camPos.y << ", " << camPos.z << endl;
    cube->shader.setFloat("viewPos", camPos.x, camPos.y, camPos.z);
    // cout << gameWindow->mainCamera->getPosition().x << ", " << gameWindow->mainCamera->getPosition().y << ", " << gameWindow->mainCamera->getPosition().z << endl;

    cube->shader.setFloat("time", getTime());

    vec3 lightColor;
    lightColor.x = sin(getTime() * 2.0f);
    lightColor.y = sin(getTime() * 0.7f);
    lightColor.z = sin(getTime() * 1.3f);

    vec3 diffuseColor = lightColor * vec3(0.5f); // decrease the influence
    vec3 ambientColor = diffuseColor * vec3(0.8f); // low influence

    // Update light over time
    vec3 lampColor = lightColor + vec3(0.5f);
    // lamp->shader.setFloat("lightColor", lampColor.x, 0., lampColor.y, lampColor.z, 1.0f);
    // cube->shader.setFloat("light.ambient", ambientColor);
    // cube->shader.setFloat("light.diffuse", diffuseColor);
}