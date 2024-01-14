#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"

namespace lve {
    /**
     * @brief First application using our window class.
     * 
     */
    class FirstApp {
        private:
            Window window{WIDTH, HEIGHT, "Hello Vulkan!"};
            Pipeline pipeline{"..\\src\\shaders\\simple_shader.vert.spv", "..\\src\\shaders\\simple_shader.frag.spv"};
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;
            /**
             * @brief Keep a small window open until the user tries
             * to close it.
             */
            void run();
    };
}