#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"

namespace lve {
    /**
     * @brief First application using our Window and
     * Pipeline classes.
     */
    class FirstApp {
        private:
            Window window{WIDTH, HEIGHT, "Hello Vulkan!"};
            Device device{window};
            Pipeline pipeline{device, ".\\shaders\\simple_shader.vert.spv", ".\\shaders\\simple_shader.frag.spv", Pipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
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