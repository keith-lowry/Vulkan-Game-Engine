# Summary
In progress small Vulkan game engine built following an online tutorial by [Brendan Galea](https://www.youtube.com/watch?v=lr93-_cC8v4).

Written in C++ for Windows x64.

# To Compile
First, ensure you have the following installed:
- MinGW
- CMake
- make (can be easily installed with the [Chocolatey](https://chocolatey.org/install) package manager)
- Latest Vulkan SDK for [Windows](https://vulkan.lunarg.com/sdk/home#windows)
- 64-bit Windows binaries for [GLFW](https://www.glfw.org/download.html)


Move
- vulkan1.lib
- GLFW\ headers folder
- libglfw3.a
to C:\msys64\mingw64\lib.

Run "make" in your choice of shell in the base directory.

# To Run
Execute "LearnVulkan.exe" in the build\ directory.
