#pragma once

#include <cstdint>
#include <string>

#include <GLFW/glfw3.h>

namespace wind
{
    struct WindowDesc
    {
        uint32_t    width;
        uint32_t    height;
        std::string title;
    };

    class Window
    {
    public:
        Window(uint32_t width, uint32_t height, std::string string);
        ~Window();

        void Init();

        constexpr auto GetNativeWindow() const noexcept { return m_window; }
        constexpr auto GetWidth() const noexcept { return m_width; }
        constexpr auto GetHeight() const noexcept { return m_height; }

        bool ShouldClose() const noexcept;

    private:
        uint32_t          m_width;
        uint32_t          m_height;
        const std::string m_title;
        GLFWwindow*       m_window;
    };
} // namespace wind