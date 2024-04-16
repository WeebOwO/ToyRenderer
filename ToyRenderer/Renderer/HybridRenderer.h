#pragma once

#include "Renderer.h"

namespace wind
{
    class HybridRenderer : public Renderer
    {
    public:
        void Render() override;
    };
} // namespace wind