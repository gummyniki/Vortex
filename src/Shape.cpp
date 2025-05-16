#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"


namespace Shape {
    void Rect(glm::vec2 position, glm::vec2 size, glm::vec4 color, glm::vec3 rotation, GLuint shaderProgram, bool useTexture, GLuint VAO) {
        glUseProgram(shaderProgram); // Always activate the shader before setting uniforms

        // Bind VAO
        glBindVertexArray(VAO);

        // Setup EBO (you only need to do this once in practice)
        static GLuint EBO = 0;
        if (EBO == 0) {
            unsigned int indices[] = {
                0, 1, 2,
                0, 2, 3
            };
            glGenBuffers(1, &EBO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        }
        else {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        }

        // Model Transform
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(position, 0.0f));
        model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(size, 1.0f));


        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

        // Set color or texture flag
        glUniform1i(glGetUniformLocation(shaderProgram, "useTexture"), useTexture);

        if (!useTexture) {
            glUniform4fv(glGetUniformLocation(shaderProgram, "ourColor"), 1, glm::value_ptr(color));
        }
        else {
            glUniform1i(glGetUniformLocation(shaderProgram, "ourTexture"), 0); // Tell GLSL sampler
        }

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    


    
}



