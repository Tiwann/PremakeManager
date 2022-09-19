#pragma once
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>
#include <string>

class ImGuiWrapper
{
public:
	static bool Initialize(const std::string& glsl_version, GLFWwindow* window, void (*stylefunc)());
	static void NewFrame();
};