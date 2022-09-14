#include <iostream>
#include "Logger.h"
#include "Project.h"
#include "Workspace.h"
#include "glad/gl.h"

int main(int argc, const char** argv)
{


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
	
	
	return 0;
}
