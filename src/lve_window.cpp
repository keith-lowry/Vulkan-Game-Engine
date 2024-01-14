#include "lve_window.hpp"

namespace lve {
    Window::Window(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
        initWindow();
    }

    Window::~Window() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Window::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // don't create opengl context
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // windows shouldn't be resizable, handle ourselves later

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
        // c_str(): pass a null-terminated c-style string to function
    }
}