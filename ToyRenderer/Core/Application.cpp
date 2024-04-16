#include "Application.h"

namespace wind
{
    Application::Application(uint32_t width, uint32_t height, std::string title) : m_window(width, height, title)
    {
        m_window.Init();
    }

    Application::~Application() {}

    Application* Application::Create(const ApplicationDesc& desc)
    {
        return new Application(desc.windowDesc.width, desc.windowDesc.height, desc.windowDesc.title);
    }

    void Application::Destroy() { delete this; }

    void Application::Run()
    {
        while (!glfwWindowShouldClose(m_window.GetNativeWindow()))
        {
            glfwPollEvents();
        }
    }
} // namespace wind