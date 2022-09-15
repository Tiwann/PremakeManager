#include <iostream>
#include "Project.h"
#include "Workspace.h"
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"
#include "glad/gl.h"
#include "GLFW/glfw3.h"

static void OnGLFWError(int code, const char* message)
{
    std::cerr << "[GLFW] Error " << code << ": " << message << '\n';
    std::exit(EXIT_FAILURE);
}

int main(int argc, const char** argv)
{
    constexpr uint16_t WIDTH = 1024;
    constexpr uint16_t HEIGHT = 576;

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
    

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 450");


    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render here
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        {
            ImGui::Begin("Premake Manager");
            static bool checked = false;
            ImGui::Checkbox("Test Checkbox", &checked);
            if(checked)
            {
                ImGui::Text("Checkbox checked!");
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
