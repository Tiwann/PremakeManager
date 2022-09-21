#include "Application.h"
#include "Core.h"
#include "ImGuiWrapper.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <fmt/core.h>
#include <fmt/color.h>

void Application::Initialize()
{
    fmt::print("Creating application...\n");
    
    // Init GLFW
    PremanAssert(glfwInit() && "Failed to initialize GLFW!");
    glfwSetErrorCallback(OnGLFWErrorCallback);
    fmt::print("GLFW initialization successful!\n");
    
    // Create GLFW window
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    m_window = glfwCreateWindow(m_window_size[0], m_window_size[1], m_app_name.c_str(), nullptr, nullptr);
    PremanAssert(m_window && "Failed to create window!");
    fmt::print("GLFW window created!\n");

    // Set the window callbacks then make opengl context current
    glfwSetFramebufferSizeCallback(m_window, OnFramebufferResizeCallback);
    glfwSetWindowSizeCallback(m_window, OnWindowResizeCallback);
    glfwMakeContextCurrent(m_window);

    // Init OpenGL
    PremanAssert(gladLoadGL(glfwGetProcAddress) && "Failed to initialize OpenGL!");
    fmt::print("OpenGL initialization successful!\n");

    // Init ImGui
    PremanAssert(ImGuiWrapper::Initialize("#version 450", m_window, ImGuiWrapper::SetGuiStyleGalaxy) && "ImGui init failed!");
    fmt::print("ImGui initialization successful!\n");
    fmt::print("Application successfully created!\n");

    fmt::print("------------------------------------------\n");
    fmt::print("[Application] Using GLFW version {}.{}.{}\n", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);
    fmt::print("[Application] Using GLAD 2\n");
    fmt::print("[Application] Using OpenGL {}\n", (const char*)glGetString(GL_VERSION));
    fmt::print("[Application] Using ImGui {}\n", ImGui::GetVersion());
    fmt::print("------------------------------------------\n");
}

void Application::Loop()
{
    while(!glfwWindowShouldClose(m_window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //TODO: Create a layer stack for ImGui rendering
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
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}

void Application::End()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    if(m_window != nullptr) glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Application::OnWindowResizeCallback(GLFWwindow* window, int32_t width, int32_t height)
{
    
}

void Application::OnFramebufferResizeCallback(GLFWwindow* window, int32_t width, int32_t height)
{
    
}

void Application::OnGLFWErrorCallback(int code, const char* message)
{
    
}
