#include <iostream>
#include "Project.h"
#include "Workspace.h"
#include "Core.h"
#include "ImGui/ImGuiWrapper.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <fmt/printf.h>


static void OnGLFWError(int code, const char* message)
{
    std::cerr << "[GLFW] Error " << code << ": " << message << '\n';
    std::exit(EXIT_FAILURE);
}

static void OnFramebufferResize(GLFWwindow* window, int32_t width, int32_t height)
{
    glViewport(0, 0, width, height);
}

int main(int argc, const char** argv)
{
    constexpr uint16_t WIDTH = 1024;
    constexpr uint16_t HEIGHT = 576;

    PremanAssert(glfwInit() && "Failed to initialize GLFW!");
    
    glfwSetErrorCallback(OnGLFWError);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "PremakeManager", nullptr, nullptr);
    PremanAssert(window && "Failed to create window!");
        
    glfwSetFramebufferSizeCallback(window, OnFramebufferResize);
    glfwMakeContextCurrent(window);
    
    PremanAssert(gladLoadGL(glfwGetProcAddress) && "Failed to initialize OpenGL!");
  
    PremanAssert(ImGuiWrapper::Initialize("#version 450", window, nullptr) && "ImGui init failed!");


    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Render here
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        {
            if(ImGui::Begin("Premake Manager"))
            {
                static bool checked = false;
                ImGui::Checkbox("Test Checkbox", &checked);
                if (checked)
                {
                    ImGui::Text("Checkbox checked!");
                }
            }
            ImGui::End();
        }
        ImGui::EndFrame();

       

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    
	glfwTerminate();
	return 0;
}
