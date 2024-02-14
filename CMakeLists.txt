cmake_minimum_required (VERSION 3.6)

project(ToyRenderer CXX)

add_subdirectory(DiligentCore)

aux_source_directory(Toyrenderer SOURCE_FILE)

add_executable(ToyRenderer WIN32 ${SOURCE_FILE})
target_compile_options(ToyRenderer PRIVATE -DUNICODE -DENGINE_DLL)

target_link_libraries(ToyRenderer
        PRIVATE
        Diligent-GraphicsEngineD3D11-shared
        Diligent-GraphicsEngineOpenGL-shared
        Diligent-GraphicsEngineD3D12-shared
        Diligent-GraphicsEngineVk-shared
        Diligent-Common
)
copy_required_dlls(ToyRenderer)