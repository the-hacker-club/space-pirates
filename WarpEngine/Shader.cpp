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

	unsigned int Shader::vertexShader;
	unsigned int Shader::fragmentShader;
	unsigned int Shader::shaderProgram;

	Shader::Uniformf::Uniformf(string name): name(name)
	{
	}

	Shader::Uniform4f::Uniform4f(string name, float x, float y, float z, float w): Shader::Uniformf(name), x(x), y(y), z(z), w(w)
	{
	}

	// Updates the value of the uniform in the shader program to the value stored in this uniform
	void Shader::Uniform4f::updateUniform()
	{
		glUniform4f(this->location, this->x, this->y, this->z, this->w);
	}

	// Loads the source code for a vertex shader into gl and returns a reference to it
	unsigned int Shader::loadVertexShader(const char * vertexSource)
	{
		vertexShader = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(vertexShader, 1, &vertexSource, NULL);
		glCompileShader(vertexShader);

		// Check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
		}
		
		return vertexShader;
	}

	// Loads the source code for a fragment shader into gl and returns a reference to it
	unsigned int Shader::loadFragmentShader(const char * fragmentSource)
	{
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
		glCompileShader(fragmentShader);

		// Check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
		}
		
		return fragmentShader;
	}

	// Creates a basic shader program using the basic vertex shader and basic fragment shader
	unsigned int Shader::createProgram()
	{
		// link shaders
		shaderProgram = glCreateProgram();

		glAttachShader(shaderProgram, vertexShader);
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
	unsigned int Shader::createProgram(vector<unsigned int> vertexShader, vector<unsigned int> fragmentShader)
	{
		// link shaders
		shaderProgram = glCreateProgram();

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

	// Tells gl to use the shaderProgram
	void Shader::useProgram(unsigned int shaderProgram)
	{
		// 2. use our shader program when we want to render an object
		glUseProgram(shaderProgram);
	}


}
