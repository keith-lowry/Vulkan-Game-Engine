# Summary
In progress small Vulkan game engine built following an online tutorial by [Brendan Galea](https://www.youtube.com/watch?v=lr93-_cC8v4).
Currently just opens a blank window.

Written in C++ for Windows x64.

# To Compile with MinGW-w64
First, ensure you have the following installed:
- MinGW
- CMake
- make (can be easily installed with the [Chocolatey](https://chocolatey.org/install) package manager)
- Latest Vulkan SDK for [Windows](https://vulkan.lunarg.com/sdk/home#windows)
- 64-bit Windows binaries for [GLFW](https://www.glfw.org/download.html)


Move
- vulkan\ Vulkan headers folder
- vk_video\ Vulkan headers folder
- GLFW\ headers folder

to C:\msys64\mingw64\include.

Move
- vulkan1.lib
- lib-mingw-w64\libglfw3.a

to C:\msys64\mingw64\lib.

Run "make" in your choice of shell in the base directory.

# To Run
Execute "LearnVulkan.exe" in the build\ directory.

You should not need any extra .dll files, but the executable
may depend on some project files (shaders) present in the src\ directory.
