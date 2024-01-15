#include "lve_pipeline.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace lve {
    Pipeline::Pipeline(
                Device& device, 
                const std::string& vertFilePath, 
                const std::string& fragFilePath, 
                const PipelineConfigInfo& configInfo) : device{device} {
        createGraphicsPipeline(vertFilePath, fragFilePath, configInfo);
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

    void Pipeline::createGraphicsPipeline(
                const std::string& vertFilePath, 
                const std::string& fragFilePath,
                const PipelineConfigInfo& configInfo) {
        auto vertCode = readFile(vertFilePath);
        auto fragCode = readFile(fragFilePath);

        std::cout << "Vertex Shader Code Size " << vertCode.size() << "\n";
        std::cout << "Fragment Shader Code Size " << fragCode.size() << "\n";
    }

    void Pipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule) {
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

        if (vkCreateShaderModule(device.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create shader module");
        }
    }

    PipelineConfigInfo Pipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
        PipelineConfigInfo configInfo{};
        return configInfo;
    }
}