#include "Shader.h"

namespace WarpEngine
{
	const char * Shader::basicVert = 
	"#version 330 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\n\0";

	const char * Shader::basicFrag =
	"#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}\n\0";

	// unsigned int Shader::vertexShader;
	// unsigned int Shader::fragmentShader;
	// unsigned int Shader::shaderProgram;

    Shader::Shader()
    {

    }

    Shader::~Shader()
    {

    }

	// Loads the source code for a vertex shader into gl and returns a reference to it
	unsigned int Shader::loadVertexShader(const char * vertexSourcePath)
    {
        string vertexShader = glslLoader::load(vertexSourcePath);
        return loadVertexShaderFromString(vertexShader);
    }

	// Loads the source code for a vertex shader into gl and returns a reference to it
	unsigned int Shader::loadVertexShaderFromString(string vertexSource)
	{
		unsigned int vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

        const char * vShaderCode = vertexSource.c_str();
		glShaderSource(vertexShaderID, 1, &vShaderCode, NULL);
		glCompileShader(vertexShaderID);

		// Check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShaderID, 512, NULL, infoLog);
			cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
		}
		
		return vertexShaderID;
	}

	// Add a new vertex shader to the list of vertex shaders used on this object.
	void Shader::addVertexShader(const char * vertexShaderPath)
	{
		unsigned int shader = loadVertexShader(vertexShaderPath);
		this->vertexShader.push_back(shader);

		updateShaderProgram();
	}

	// Add a new vertex shader to the list of vertex shaders used on this object.
	void Shader::addVertexShader(unsigned int vertexShaderID)
	{
		this->vertexShader.push_back(vertexShaderID);

		updateShaderProgram();
	}

	unsigned int Shader::loadFragmentShader(const char * fragmentSourcePath)
    {
        string fragmentShader = glslLoader::load(fragmentSourcePath);
        return loadFragmentShaderFromString(fragmentShader);
    }

	// Loads the source code for a fragment shader into gl and returns a reference to it
	unsigned int Shader::loadFragmentShaderFromString(string fragmentSource)
	{
		unsigned int fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

        const char * fShaderCode = fragmentSource.c_str();
		glShaderSource(fragmentShaderID, 1, &fShaderCode, NULL);
		glCompileShader(fragmentShaderID);

		// Check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShaderID, 512, NULL, infoLog);
			cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
		}
		
		return fragmentShaderID;
	}

	// Add a new fragment shader to the list of fragment shaders used on this object.
	void Shader::addFragmentShader(const char * fragmentShaderPath)
	{
		unsigned int shader = loadFragmentShader(fragmentShaderPath);
		this->fragmentShader.push_back(shader);

		updateShaderProgram();
	}

	// Add a new fragment shader to the list of fragment shaders used on this object.
	void Shader::addFragmentShader(unsigned int fragmentShaderID)
	{
		this->fragmentShader.push_back(fragmentShaderID);

		updateShaderProgram();
	}

	// Creates a basic shader program using the basic vertex shader and basic fragment shader
	unsigned int Shader::_createProgramUsingBasicShaders()
	{
		// link shaders
		shaderProgram = glCreateProgram();

		unsigned int vertexShader = loadFragmentShader(basicVert);
		glAttachShader(shaderProgram, vertexShader);
		unsigned int fragmentShader = loadFragmentShader(basicFrag);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

		// Check for program compile errors
		int success;
		char infoLog[512];
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << endl;
		}
		
		// Delete shaders once we've linked them
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return shaderProgram;
	}

	// Create a shader program with the list of vertex shaders and fragment shaders
	unsigned int Shader::_createProgram(vector<unsigned int> vertexShader, vector<unsigned int> fragmentShader)
	{
		// link shaders
		unsigned int shaderProgram = glCreateProgram();

		for (auto &vshader : vertexShader) {
			glAttachShader(shaderProgram, vshader);
		}

		for (auto &fshader : fragmentShader) {
			glAttachShader(shaderProgram, fshader);
		}
		glLinkProgram(shaderProgram);

		// Check for program compile errors
		int success;
		char infoLog[512];
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << endl;
		}
		
		// Delete shaders once we've linked them
		for (auto &vshader : vertexShader) {
			glDeleteShader(vshader);
		}
		for (auto &fshader : fragmentShader) {
			glDeleteShader(fshader);
		}

		return shaderProgram;
	}

	// Update the shader program with the current list of vertexShaders and fragmentShaders
	void Shader::updateShaderProgram()
	{
		vector<unsigned int> updateVShader = vector<unsigned int>();
		// Use the default vertex shader if none are present
		if (this->vertexShader.size() == 0) {
			updateVShader.push_back(Shader::loadVertexShaderFromString(Shader::basicVert));
		} else {
			updateVShader = this->vertexShader;
		}

		vector<unsigned int> updateFShader = vector<unsigned int>();
		// Use the default fragment shader if none are present
		if (this->fragmentShader.size() == 0) {
			updateFShader.push_back(Shader::loadFragmentShaderFromString(Shader::basicFrag));
		} else {
			updateFShader = this->fragmentShader;
		}

		// Update Program
		this->shaderProgram = Shader::_createProgram(updateVShader, updateFShader);
	}

	// Tells gl to use this shaderProgram
	void Shader::useProgram()
	{
        // TODO add a check to see if our program has been created yet

		// 2. use our shader program when we want to render an object
		glUseProgram(shaderProgram);
	}

	// Add a value to set a uniform to in the shader program
	void Shader::setInt(string name, int v1)
	{
        glUseProgram(this->shaderProgram);
		glUniform1i(glGetUniformLocation(this->shaderProgram, name.c_str()), v1);
	}

	// Add a value to set a uniform to in the shader program
	void Shader::setFloat(string name, float v1)
	{
        glUseProgram(this->shaderProgram);
		glUniform1f(glGetUniformLocation(this->shaderProgram, name.c_str()), v1);
	}

	// Add a value to set a uniform to in the shader program
	void Shader::setFloat(string name, float v1, float v2)
	{
        glUseProgram(this->shaderProgram);
		glUniform2f(glGetUniformLocation(this->shaderProgram, name.c_str()), v1, v2);
	}

	// Add a value to set a uniform to in the shader program
	void Shader::setFloat(string name, float v1, float v2, float v3)
	{
        glUseProgram(this->shaderProgram);
		glUniform3f(glGetUniformLocation(this->shaderProgram, name.c_str()), v1, v2, v3);
	}

	// Add a value to set a uniform to in the shader program
	void Shader::setFloat(string name, float v1, float v2, float v3, float v4)
	{
        glUseProgram(this->shaderProgram);
		glUniform4f(glGetUniformLocation(this->shaderProgram, name.c_str()), v1, v2, v3, v4);
	}
}
