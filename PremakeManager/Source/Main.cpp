#include <iostream>
#include "Project.h"
#include "Workspace.h"
#include "Core.h"
#include "Logger.h"
#include "ImGuiWrapper.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <array>
#include <fmt/core.h>

static std::array<std::int32_t, 2> framebuffer_size;
static std::array<std::int32_t, 2> window_size = { 1024, 576 };
static std::string  app_name = "Premake Manager";


static void OnGLFWError(int code, const char* message)
{
    std::cerr << fmt::format("[GLFW] Error {}: {}\n", code, message);
    std::exit(EXIT_FAILURE);
}

static void OnFramebufferResize(GLFWwindow* window, int32_t width, int32_t height)
{
    framebuffer_size[0] = width;
    framebuffer_size[1] = height;
    glViewport(0, 0, framebuffer_size[0], framebuffer_size[1]);

}

static void OnWindowResize(GLFWwindow* window, int32_t width, int32_t height)
{
    window_size[0] = width;
    window_size[1] = height;
}

int main(int argc, const char** argv)
{
    PremanAssert(glfwInit() && "Failed to initialize GLFW!");
    
    glfwSetErrorCallback(OnGLFWError);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);


    GLFWwindow* window = glfwCreateWindow(window_size[0], window_size[1], "PremakeManager", nullptr, nullptr);
    PremanAssert(window && "Failed to create window!");
        
    glfwSetFramebufferSizeCallback(window, OnFramebufferResize);
    glfwMakeContextCurrent(window);
    
    PremanAssert(gladLoadGL(glfwGetProcAddress) && "Failed to initialize OpenGL!");
    
    PremanAssert(ImGuiWrapper::Initialize("#version 450", window, ImGuiWrapper::SetGuiStyleGalaxy) && "ImGui init failed!");

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Render here
        ImGuiWrapper::NewFrame();
        ImGui::NewFrame();
        {
            ImGui::ShowDemoWindow();
            ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Always);
            ImGui::SetNextWindowSize(ImVec2(1024, 576), ImGuiCond_Always);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
            
            const ImGuiWindowFlags flags = ImGuiWindowFlags_MenuBar
                                         | ImGuiWindowFlags_NoDocking
                                         | ImGuiWindowFlags_NoTitleBar
                                         | ImGuiWindowFlags_NoCollapse
                                         | ImGuiWindowFlags_NoResize
                                         | ImGuiWindowFlags_NoMove
                                         | ImGuiWindowFlags_NoBringToFrontOnFocus
                                         | ImGuiWindowFlags_NoNavFocus;

            //ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

            if(ImGui::Begin("Premake manager", nullptr, flags))
            {
                ImGui::PopStyleVar(3);
                ImGui::DockSpace(ImGui::GetID("Dockspace"));
                if(ImGui::BeginMenuBar())
                {
                    if(ImGui::BeginMenu("File"))
                    {
                        if(ImGui::MenuItem("New Workspace", "Ctrl + N"))
                        {
                            
                        }

                        if(ImGui::MenuItem("Open Workspace", "Ctrl + O"))
                        {
                            
                        }

                        if(ImGui::MenuItem("Save", "Ctrl + S", nullptr, false))
                        {
                            
                        }

                        if(ImGui::MenuItem("Save As", "Ctrl + Alt + S", nullptr, false))
                        {
                            
                        }

                        if(ImGui::MenuItem("Exit", "Ctrl + Esc"))
                        {
                            std::exit(EXIT_SUCCESS);
                        }
                        ImGui::EndMenu();
                    }

                    if(ImGui::BeginMenu("Edit"))
                    {
                        if(ImGui::MenuItem("Undo", "Ctrl + Z"))
                        {

                        }

                        if(ImGui::MenuItem("Redo", "Ctrl + Y"))
                        {

                        }
                        ImGui::EndMenu();
                    }

                    if(ImGui::BeginMenu("View"))
                    {
                        if(ImGui::MenuItem("Properties"))
                        {
                            
                        }

                        if(ImGui::MenuItem("Hierarchy"))
                        {
                            
                        }

                        if(ImGui::MenuItem("Console"))
                        {
                            
                        }
                        ImGui::EndMenu();
                    }

                    if(ImGui::BeginMenu("Build"))
                    {
                        ImGui::EndMenu();
                    }

                    if(ImGui::BeginMenu("Help"))
                    {
                        ImGui::EndMenu();
                    }
                    ImGui::EndMenuBar();
                }
                ImGui::End();
            }

            
            ImGui::EndFrame();
        }
        


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
