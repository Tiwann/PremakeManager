#include <iostream>
#include "Logger.h"
#include "Project.h"
#include "Workspace.h"
#include "glad/gl.h"
#include "GLFW/glfw3.h"

int main(int argc, const char** argv)
{
    const uint16_t WIDTH = 1280;
    const uint16_t HEIGHT = 720;

    if(!glfwInit())
    {
        LOG_ERROR("Failed to initialize glfw!\n");
        std::exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

    glfwWindowHint(GLFW_RESIZABLE, false);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "PremakeManager", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    if(!gladLoadGL(glfwGetProcAddress))
    {
        LOG_ERROR("Failed to init Glad!\n");
        std::exit(EXIT_FAILURE);
    }


	Logger::GetLogger().SetFormat("[%time%] [%category%]: %message%");

	Workspace workspace;
	workspace.name = "PremakeManager";
    workspace.architecture = Architecture::X64;
	workspace.configurations = { "Debug", "Release" };
	
	Project project;
	project.name = "PremakeManager";
	project.kind = Kind::CONSOLEAPP;
	project.language = Language::CPP;
	project.dialect = Dialect::CPP20;
	
	workspace.projects.push_back(std::make_shared<Project>(project));
	workspace.start_project = std::make_shared<Project>(project);

    LOG_TEXT("Hello PremakeManager!\n");
    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render here

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
	
    LOG_WARNING("Cleaning then close...\n");
	glfwTerminate();
	return 0;
}
