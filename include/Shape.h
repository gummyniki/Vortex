#pragma once





#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glad/gl.h>
#include "texture.h"
#include <imgui.h>

namespace Shape {
	void Rect(glm::vec2 position, glm::vec2 size, glm::vec4 color, glm::vec3 rotation, GLuint shaderProgram, bool useTexture, GLuint VAO);

	class BaseShape {
	public:
		std::string name;
		glm::vec2 position;
		glm::vec2 size;
		glm::vec4 color;
		glm::vec3 rotation;
		GLuint VAO;
		GLuint shaderProgram;
		GLuint texture;
		bool useTexture;

		virtual void draw() = 0;
		virtual void imguiInspector() = 0;

		virtual ~BaseShape() = default;
	};

    class Rectangle : public BaseShape {
    public:
        Rectangle() {
            name = "Rectangle";
            position = glm::vec2(-0.5f, 0.5f);
            size = glm::vec2(0.3f, 0.4f);
            color = glm::vec4(1.0f, 1.0f, 0.5f, 1.0f);
            rotation = glm::vec3(0.0f, 0.0f, 175.0f);
            useTexture = false;
            shaderProgram = 0;
            VAO = 0;

            std::cout << "Rectangle initialized\n";
        }

        void draw() override {
            if (useTexture) {
                Texture::useTexture(shaderProgram, texture);
            }
            Rect(position, size, color, rotation, shaderProgram, useTexture, VAO);
        }

        void imguiInspector() override {
            ImGui::Text("Shape: %s", name.c_str());
            ImGui::SliderFloat2("Position", &position.x, -1, 1);
            ImGui::SliderFloat2("Size", &size.x, 0.1f, 1.0f);
            ImGui::ColorEdit4("Color", &color.r);
            ImGui::SliderFloat3("Rotation", &rotation.x, 0.0f, 360.0f);
            ImGui::Checkbox("Use Texture", &useTexture);
        }
    };


	

		



}
