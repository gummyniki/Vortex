#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <glm/glm.hpp>
#include "Shape.h"
#include <cmath>
#include "texture.h"
#include <imgui.h>
#include <imgui_internal.h> 
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <vector>
#include "Organizer.h"

namespace Vortex {
	void RenderInit(GLuint VAO, GLuint shaderProgram);
}