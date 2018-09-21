#pragma once
#include "_warpEngine.h"

#include <glad\glad.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace WarpEngine {
	class Shader
	{
	public:
		class Uniformf {
		protected:
			Uniformf(string name);
		public:
			string name;
			int location;
			virtual void updateUniform() = 0;
			virtual ~Uniformf() { };
		};

		class Uniform4f: public Uniformf {
		public:
			float x;
			float y;
			float z;
			float w;
			WARPENGINE_API Uniform4f(string name, float x, float y, float z, float w);
			virtual void updateUniform();
			virtual ~Uniform4f() { };
		};

		// The basicVert shader loaded into gl
		static unsigned int vertexShader;
		// The basicFrag shader loaded into gl
		static unsigned int fragmentShader;
		WARPENGINE_API static const char * basicVert;
		WARPENGINE_API static const char * basicFrag;

		WARPENGINE_API static unsigned int loadVertexShader(const char * vertexSource);
		WARPENGINE_API static unsigned int loadFragmentShader(const char * vertexSource);
		WARPENGINE_API static unsigned int createProgram();
		WARPENGINE_API static unsigned int createProgram(vector<unsigned int> vertexShader, vector<unsigned int> fragmentShader);
		WARPENGINE_API static void useProgram(unsigned int shaderProgram);
		WARPENGINE_API void useProgram();
		static unsigned int shaderProgram;
	};
}

