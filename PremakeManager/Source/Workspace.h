#pragma once
#include <string>
#include <vector>
#include "Project.h"

struct Workspace
{
    std::string name;
    std::vector<std::string> configurations;
    std::shared_ptr<Project> start_project; 
    std::vector<std::shared_ptr<Project>> projects;
};
