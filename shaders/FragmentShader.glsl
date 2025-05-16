#version 330 core
out vec4 FragColor;
in vec2 TexCoord;
uniform vec4 ourColor;
uniform sampler2D ourTexture;
uniform bool useTexture; // Flag to switch between color and texture
uniform bool useColor; // Flag to switch between color and texture
void main()
{
    if (useTexture) {
        vec4 textureColor = texture(ourTexture, TexCoord);
        FragColor = textureColor; // Apply texture color
    } else {
        FragColor = ourColor;  // Apply color if no texture
    }
}
