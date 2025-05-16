#pragma once





#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <cstddef>

namespace Shader {




	

	GLuint makeVertexShader();
	GLuint makeFragmentShader();
	GLuint makeShaderProgram(GLuint vertexShader, GLuint fragmentShader);
	GLuint makeVBO();
	GLuint makeVAO(GLuint VBO);
	void checkShaderCompile(GLuint shader, std::string name);
}


