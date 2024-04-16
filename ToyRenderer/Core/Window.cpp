#include "Window.h"

#include <stdexcept>

namespace wind
{
    Window::Window(uint32_t width, uint32_t height, std::string title) :
        m_width(width), m_height(height), m_title(std::move(title))
    {
        if (!glfwInit())
        {
            throw std::runtime_error("Failed to initialize GLFW");
        }
    }

    Window::~Window()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    bool Window::ShouldClose() const noexcept { return glfwWindowShouldClose(m_window); }

    void Window::Init()
    {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(m_window, this);
    }
} // namespace wind