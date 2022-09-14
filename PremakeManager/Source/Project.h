#pragma once
#include <vector>

enum class Dialect : int8_t
{
    CPP98,
    CPP11,
    CPP14,
    CPP17,
    CPP20,
    GNU98,
    GNU11,
    GNU14,
    GNU17,
    GNU20,
};

enum class Kind : int8_t
{
    NONE,
    CONSOLEAPP,
    WINDOWEDAPP,
    SHAREDLIB,
    STATICLIB,
    MAKEFILE,
    UTILITY,
    PACKAGING,
    SHAREDITEMS
};

enum class Language : int8_t
{
    C,
    CPP,
    CSHARP,
    FSHARP,
    D
};

struct Project
{
    std::string name;
    Kind kind;
    Language language;
    Dialect dialect;

    std::string targetdir;
    std::string objdir;

    std::vector<std::string> files;
    std::vector<std::string> includedirs;

    std::vector<std::string> defines;
    std::vector<std::shared_ptr<Project>> links;
};
