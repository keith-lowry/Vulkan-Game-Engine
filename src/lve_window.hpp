#pragma once

#define GLFW_INCLUDE_VULKAN // make GLFW also include vulkan headers
#include <GLFW/glfw3.h>
#include <string>

namespace lve {
    // Class representing a single open GLFW window.
    class Window {
        private:
            /**
             * @brief Initialize the Window.
             * 
             */
            void initWindow();
            const int width;
            const int height;
            std::string windowName;
            GLFWwindow* window;
        public:
            /**
             * @brief Construct a new Window object
             * 
             * @param w Width in pixels
             * @param h Height in pixels
             * @param name Window name / title
             */
            Window(int w, int h, std::string name);
            ~Window();

            /// @brief Should the Window close?
            /// @return True if the user attempted to close the Window.
            bool shouldClose() { return glfwWindowShouldClose(window);}

            // avoid having two Windows sharing the same pointer
            Window(const Window &) = delete; // delete copy constructor
            Window &operator=(const Window &) = delete; // delete copy operator

    };
}