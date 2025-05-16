#version 330 core

layout (location = 0) in vec3 aPos;        // Vertex position
layout (location = 1) in vec2 aTexCoord;   // Texture coordinates

out vec2 TexCoord;  // Output texture coordinates

uniform mat4 model;  // Model transformation matrix

void main()
{
    gl_Position = model * vec4(aPos, 1.0);  // This is where you set the position
    TexCoord = aTexCoord;                   // Pass texture coordinates to the fragment shader
}
