#define STB_IMAGE_IMPLEMENTATION

#include "texture.h"
#include <stb_image.h>
#include <iostream>

#include <glad/gl.h>

unsigned int Texture::loadTexture(const std::string& path) {
    int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true); // Flip the image vertically
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    if (!data) {
        std::cout << "Failed to load texture at: " << path << std::endl;
        return 0;
    }

    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);

    return textureID;
}

void Texture::useTexture(unsigned int shaderProgram, unsigned int texture) {
    glUniform1i(glGetUniformLocation(shaderProgram, "useTexture"), true); // use texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(glGetUniformLocation(shaderProgram, "ourTexture"), 0); // Set the texture uniform to use texture unit 0
}

void Texture::useColor(unsigned int shaderProgram) {
    glUniform1i(glGetUniformLocation(shaderProgram, "useTexture"), false); // Don't use texture
    glUniform1i(glGetUniformLocation(shaderProgram, "useColor"), true); // Use color
}