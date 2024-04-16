#pragma once

#include "Core/Window.h"

namespace wind
{
    struct ApplicationDesc
    {
        WindowDesc windowDesc;
    };

    class Application final
    {
    public:
        Application(uint32_t width, uint32_t height, std::string title);
        ~Application();

        static Application* Create(const ApplicationDesc& desc);
        void                Destroy();

        void Run();

    private:
        Window m_window;
    };
} // namespace wind