#pragma once

#include "lve_device.hpp"
#include <string>
#include <vector>

namespace lve {
    // Useful for letting application code be able to
    // configure a pipeline and share configurations among
    // multiple pipelines.
    struct PipelineConfigInfo {
        VkViewport viewport;
        VkRect2D scissor;
        VkPipelineViewportStateCreateInfo viewportInfo;
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
        VkPipelineRasterizationStateCreateInfo rasterizationInfo;
        VkPipelineMultisampleStateCreateInfo multisampleInfo;
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
        VkPipelineColorBlendStateCreateInfo colorBlendInfo;
        VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
        VkPipelineLayout pipelineLayout = nullptr;
        VkRenderPass renderPass = nullptr;
        uint32_t subpass = 0;
    };

    // Class representing a Vulkan rendering Pipeline.
    class Pipeline {
        private:
            /**
             * @brief Reads the entirety of a file into a vector buffer
             * and returns it.
             * 
             * @param filepath Path to file to read.
             * @return std::vector<char> Buffer containing the file's contents.
             */
            static std::vector<char> readFile(const std::string& filepath);

            void createGraphicsPipeline(
                const std::string& vertFilePath, 
                const std::string& fragFilePath,
                const PipelineConfigInfo& configInfo);

            void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

            // Reference to our Device object.
            Device& device;
            // ^ Potentially memory unsafe if Device is released BUT
            // we assume that the Device will outlive any Pipeline
            // objects (Pipelines fundamentally need a Device to exist).

            // Handle to Vulkan Pipeline object.
            VkPipeline graphicsPipeline;
            VkShaderModule vertShaderModule;
            VkShaderModule fragShaderModule;
        public:
            /**
             * @brief Construct a new Pipeline object.
             * 
             * @param vertFilePath Path to vertex shader file.
             * @param fragFilePath Path to fragment shader file.
             */
            Pipeline(
                Device& device, 
                const std::string& vertFilePath, 
                const std::string& fragFilePath, 
                const PipelineConfigInfo& configInfo);
            
            /**
             * @brief Destroy the Pipeline object.
             */
            ~Pipeline() {};

            // Delete copy constructor and operator.
            Pipeline(const Pipeline&) = delete;
            void operator=(const Pipeline&) = delete;

            /**
             * @brief Get default Pipeline configuration.
             * 
             * @param width Width of viewport
             * @param height Height of viewport
             * @return PipelineConfigInfo 
             */
            static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);
    };
}