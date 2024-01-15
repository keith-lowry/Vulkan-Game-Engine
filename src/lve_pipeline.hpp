#pragma once

#include <string>
#include <vector>

namespace lve {
    // Class representing a Vulkan rendering Pipeline.
    class Pipeline {
        public:
            /**
             * @brief Construct a new Pipeline object.
             * 
             * @param vertFilePath Path to vertex shader file.
             * @param fragFilePath Path to fragment shader file.
             */
            Pipeline(const std::string& vertFilePath, const std::string& fragFilePath);
        private:
            /**
             * @brief Read the entirety of a file into a vector buffer
             * and return it.
             * 
             * @param filepath Path to file to read.
             * @return std::vector<char> Buffer containing the file's contents.
             */
            static std::vector<char> readFile(const std::string& filepath);
            void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath);

    };
}