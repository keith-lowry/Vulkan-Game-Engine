default:
	cmake -G "MinGW Makefiles" -S .\src\ -B .\build\

# g++ ./main.cpp -l:libglfw3.a -l:vulkan-1.lib -lgdi32 -o out
# g++ -I C:/Libraries/glfw-3.3.9.bin.WIN64/include -I C:/Libraries/VulkanSDK/1.3.268.0/Include -I C:/Libraries/glm -LC:/Libraries/VulkanSDK/1.3.268.0/Lib/ -LC:/Libraries/glfw-3.3.9.bin.WIN64/lib-mingw-w64 ./main.cpp  -l:libglfw3.a -l:vulkan-1.lib -lgdi32 -o main