#ifndef TEXTURE_H
#define TEXTURE_H


#include <string>

class Texture {
public:
    static unsigned int loadTexture(const std::string& path);
    static void useTexture(unsigned int shaderProgram, unsigned int texture);
    static void useColor(unsigned int shaderProgram);
        
    
};

#endif

