#include "lve_pipeline.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace lve {
    Pipeline::Pipeline(const std::string& vertFilePath, const std::string& fragFilePath) {
        createGraphicsPipeline(vertFilePath, fragFilePath);
    }

    std::vector<char> Pipeline::readFile(const std::string& filepath) {
        std::ifstream file(filepath, std::ios::ate | std::ios::binary);
        // seek to end immediately, read in as binary

        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filepath);
        }

        size_t fileSize = static_cast<size_t>(file.tellg()); // get file size (current position)
        std::vector<char> buffer(fileSize);
        
        file.seekg(0); // go to start of file
        file.read(buffer.data(), fileSize); // read entirety of file into our vector
        file.close();
        return buffer;
    }

    void Pipeline::createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath) {
        auto vertCode = readFile(vertFilePath);
        auto fragCode = readFile(fragFilePath);

        std::cout << "Vertex Shader Code Size " << vertCode.size() << "\n";
        std::cout << "Fragment Shader Code Size " << fragCode.size() << "\n";
    }
}