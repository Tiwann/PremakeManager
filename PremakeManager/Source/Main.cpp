#include <iostream>
#include "Project.h"
#include "Workspace.h"
#include "Core.h"
#include "Logger.h"
#include "ImGuiWrapper.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>


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
            ImGui::SetNextWindowSize(ImVec2(WIDTH, HEIGHT));
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

            bool can_save = false;
            if(ImGui::Begin("Premake manager", nullptr, flags))
            {
                ImGui::PopStyleVar(3);
                ImGui::DockSpace(ImGui::GetID("Dockspace"));
                if(ImGui::BeginMenuBar())
                {
                    if(ImGui::BeginMenu("File"))
                    {
                        if(ImGui::MenuItem("New Workspace"))
                        {
                            
                        }

                        if(ImGui::MenuItem("Open Workspace"))
                        {
                            
                        }

                        if(ImGui::MenuItem("Save", nullptr, nullptr, can_save))
                        {
                            
                        }

                        if(ImGui::MenuItem("Exit"))
                        {
                            std::exit(EXIT_SUCCESS);
                        }
                        ImGui::EndMenu();
                    }

                    if(ImGui::BeginMenu("Edit"))
                    {
                        ImGui::EndMenu();
                    }

                    if(ImGui::BeginMenu("View"))
                    {
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
