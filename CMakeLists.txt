cmake_minimum_required(VERSION 3.6)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

project(ToyRenderer CXX)
# find need package
find_package(glfw3 CONFIG REQUIRED)

add_subdirectory(DiligentCore)

file(GLOB_RECURSE SOURCE_FILE
    ToyRenderer/*.cpp
)

add_executable(ToyRenderer ${SOURCE_FILE})

target_include_directories(ToyRenderer PRIVATE ToyRenderer)
target_compile_options(ToyRenderer PRIVATE -DUNICODE -DENGINE_DLL)
target_link_libraries(ToyRenderer
    PRIVATE
    Diligent-GraphicsEngineD3D11-shared
    Diligent-GraphicsEngineOpenGL-shared
    Diligent-GraphicsEngineD3D12-shared
    Diligent-GraphicsEngineVk-shared
    Diligent-Common
    glfw
)

copy_required_dlls(ToyRenderer)