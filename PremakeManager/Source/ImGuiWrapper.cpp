#include "ImGuiWrapper.h"

bool ImGuiWrapper::Initialize(const std::string& glsl_version, GLFWwindow* window, void (*stylefunc)())
{
    if(!IMGUI_CHECKVERSION()) return false;
    ImGuiContext* context = ImGui::CreateContext();
    if (!context) return false;
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    ImGui::StyleColorsDark();
    if(stylefunc) stylefunc();
    if(!ImGui_ImplGlfw_InitForOpenGL(window, true)) return false;
    if (!ImGui_ImplOpenGL3_Init(glsl_version.c_str())) return false;
    return true;
}

void ImGuiWrapper::NewFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
}
