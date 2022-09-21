#pragma once
#include <array>
#include <string>

struct GLFWwindow;

class Application
{
private:
    std::string m_app_name;
    GLFWwindow* m_window = nullptr;
    std::array<int32_t, 2> m_window_size{};
    std::array<int32_t, 2> m_framebuffer_size{};
public:
    Application(std::string&& app_name, int32_t width, int32_t height)
        : m_app_name(app_name), m_window_size({width, height}) {}
    
    // Member functions
    void Initialize();
    void Loop();
    void End();
private:
    // Callbacks
    static void OnWindowResizeCallback(GLFWwindow* window, int32_t width, int32_t height);
    static void OnFramebufferResizeCallback(GLFWwindow* window, int32_t width, int32_t height);
    static void OnGLFWErrorCallback(int code, const char* message);
};