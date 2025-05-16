#include <glad/gl.h>  
#include <GLFW/glfw3.h>  

#include <iostream> // Include iostream for std::cerr  
#include <string>
#include <fstream>
#include <sstream>


namespace Shader  
{  
	std::string readValueFromFile(const std::string& filename) {
		std::ifstream file(filename);
		std::stringstream buffer;

		if (file.is_open()) {
			buffer << file.rdbuf(); // Read entire contents into buffer
			file.close();
		}
		else {
			std::cerr << "Unable to open file: " << filename << std::endl;
		}

		return buffer.str();
	}


	 // Rectangle vertices (two triangles forming a quad)
	float vertices[] = {
		// positions         // tex coords
	   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,  // bottom-left
		0.5f, -0.5f, 0.0f,   1.0f, 0.0f,  // bottom-right
		0.5f,  0.5f, 0.0f,   1.0f, 1.0f,  // top-right
	   -0.5f,  0.5f, 0.0f,   0.0f, 1.0f   // top-left
	};

	const size_t vertexCount = sizeof(vertices) / sizeof(float);

	void checkShaderCompile(GLuint shader, std::string name) {
		int success;
		char infoLog[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cerr << name << " Shader Compilation Failed:\n" << infoLog << std::endl;
		}
	}



	std::string vertexShaderSourceStr = readValueFromFile("shaders/VertexShader.glsl");
	const char* vertexShaderSource = vertexShaderSourceStr.c_str();

	std::string fragmentShaderSourceStr = readValueFromFile("shaders/FragmentShader.glsl");
	const char* fragmentShaderSource = fragmentShaderSourceStr.c_str();








	GLuint makeVertexShader() {  

		

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);  
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);  
		glCompileShader(vertexShader);  

		return vertexShader;  
	}  

	GLuint makeFragmentShader() {  
		
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);  
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);  
		glCompileShader(fragmentShader);  

		return fragmentShader;  
	}  

	GLuint makeShaderProgram(GLuint vertexShader, GLuint fragmentShader) {  
		

		GLuint shaderProgram = glCreateProgram();  
		glAttachShader(shaderProgram, vertexShader);  
		glAttachShader(shaderProgram, fragmentShader);  
		glLinkProgram(shaderProgram);  

		return shaderProgram;  
	}  

	GLuint makeVBO() {
		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, Shader::vertexCount * sizeof(float), vertices, GL_STATIC_DRAW);
		return VBO;
	}


	GLuint makeVAO(GLuint VBO) {
		GLuint VAO, EBO;
		glGenVertexArrays(1, &VAO);

		glBindVertexArray(VAO); // bind VAO
		glBindBuffer(GL_ARRAY_BUFFER, VBO); // re-bind VBO in context of VAO
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);

		glEnableVertexAttribArray(0);

		// Texture coord attribute
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);


		return VAO;
	}

	



}