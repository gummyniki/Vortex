#include "Vortex.h"

namespace Vortex {
	void RenderInit(GLuint VAO, GLuint shaderProgram) {
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
	}
}