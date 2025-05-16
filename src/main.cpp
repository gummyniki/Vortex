#include "Vortex.h"




int main(void)
{
    GLFWwindow* window;

    // Initialize GLFW
    if (!glfwInit())
        return -1;

    // Set OpenGL version and profile (optional but good practice)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the OpenGL context current
    glfwMakeContextCurrent(window);

    
    

    // now initialize GLAD
    if (!gladLoadGL(glfwGetProcAddress)) {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    return -1;
    }


    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    

    GLuint VBO;
    GLuint VAO;
    GLuint shaderProgram;

    
    Organizer organizer;



    float rot = 0;

    GLuint texture1 = Texture::loadTexture("images/silly.jpg");
    GLuint texture2 = Texture::loadTexture("images/checkboard.png");

    GLuint vertexShader = Shader::makeVertexShader();
    GLuint fragmentShader = Shader::makeFragmentShader();
    

    VBO = Shader::makeVBO();

    
    VAO = Shader::makeVAO(VBO);
    shaderProgram = Shader::makeShaderProgram(vertexShader, fragmentShader);

    
    
    

    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");


    Shape::Rectangle rect;
    Shape::Rectangle rect2;

    rect2.shaderProgram = shaderProgram;
    rect2.name = "rect2";
    rect2.texture = texture2;
    rect2.VAO = VAO;
    rect2.useTexture = true;
    

    rect.shaderProgram = shaderProgram;
    rect.name = "rect1";
    rect.VAO = VAO;
    rect.color = glm::vec4(0.0f, 1.0f, 0.5f, 1.0f);
	rect.position = glm::vec2(-0.2f, 0.2f);
    rect.useTexture = false;
    rect.rotation = glm::vec3(0.0f, 0.0f, rot);
    rect.useTexture = false;

    
    
    organizer.addShape(&rect);
    organizer.addShape(&rect2);


    
    // Main render loop
    while (!glfwWindowShouldClose(window))
    {

        


        
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);  // dark gray
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Hierarchy");

        for (size_t i = 0; i < organizer.shapes.size(); ++i) {
            if (ImGui::TreeNode((organizer.shapes[i]->name + "##" + std::to_string(i)).c_str())) {
                organizer.shapes[i]->imguiInspector();
                ImGui::TreePop();
            }
        }
        
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());



        Vortex::RenderInit(VAO, shaderProgram);
            
        



        rect2.draw();

        rect.draw();

        rect2.color = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
        

        

        
        
       
        
        

        glfwSwapBuffers(window);
        glfwPollEvents();


    }

    glfwTerminate();
    return 0;
}