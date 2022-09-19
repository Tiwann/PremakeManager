#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Project.h"

enum class Architecture : int8_t
{
    UNIVERSAL,
    X86,
    X64,
    ARM,
    ARM64,
    ARMV5,
    ARMV7,
    AARCH64,
    MIPS,
    MIPS64
};

struct Workspace
{
    std::string name;
    Architecture architecture;
    std::vector<std::string> configurations;
    std::shared_ptr<Project> start_project; 
    std::vector<std::shared_ptr<Project>> projects;
};
