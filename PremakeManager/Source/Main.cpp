#include <iostream>
#include "Project.h"
#include "Workspace.h"
#include "glad/gl.h"
#include "GLFW/glfw3.h"

static void OnGLFWError(int code, const char* message)
{
    
}

int main(int argc, const char** argv)
{
    constexpr uint16_t WIDTH = 1280;
    constexpr uint16_t HEIGHT = 720;

    if(!glfwInit())
    {
        std::exit(EXIT_FAILURE);
    }
    glfwSetErrorCallback(OnGLFWError);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_RESIZABLE, false);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "PremakeManager", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    

    if(!gladLoadGL(glfwGetProcAddress))
    {
        std::exit(EXIT_FAILURE);
    }
    
    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render here

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
	glfwTerminate();
	return 0;
}
