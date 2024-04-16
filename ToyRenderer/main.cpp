#include "Core/Application.h"

int main(int argc, char* argv[]) {
    // Create application description
    wind::ApplicationDesc desc;
    desc.windowDesc.width = 1280;
    desc.windowDesc.height = 720;
    desc.windowDesc.title = "ToyRenderer";

    // Run application
    wind::Application* app = wind::Application::Create(desc);
    app->Run();
    app->Destroy();

    return 0;
}