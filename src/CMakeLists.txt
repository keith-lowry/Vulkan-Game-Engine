cmake_minimum_required(VERSION 3.28.1)

project(LearnVulkan)

add_executable(${PROJECT_NAME} main.cpp lve_window.cpp lve_pipeline.cpp first_app.cpp)

target_link_libraries(${PROJECT_NAME} -static gcc stdc++ winpthread vulkan-1 gdi32 glfw3)