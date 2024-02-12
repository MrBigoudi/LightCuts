#pragma once

#include "globalFrameRenderSubSystem.hpp"
#include "mouseInput.hpp"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <cstdint>
#include <vector>

#include "types.hpp"
#include "window.hpp"

#include "renderer.hpp"

#include "simpleRenderSubSystem.hpp"
#include "camera.hpp"

#include "descriptors.hpp"
#include "components.hpp"

class Application{

    public:
        static const uint32_t WINDOW_WIDTH = 1280;
        static const uint32_t WINDOW_HEIGHT = 720;

    private:
        WindowPtr _Window = nullptr;
        VulkanAppPtr _VulkanApp = nullptr;
        RendererPtr _Renderer = nullptr;

        DescriptorPoolPtr _GlobalPool = nullptr;
        DescriptorPoolPtr _GlobalPoolTmp = nullptr;

        SimpleRenderSubSystemPtr _RenderSubSystem = nullptr;
        GlobalFrameRenderSubSystemPtr _GlobalFrameRenderSubSystem = nullptr;

        CameraPtr _Camera = nullptr;

    private:
        void initWindow();
        void cleanUpWindow();

        void initVulkan();
        void cleanUpVulkan();

        void initGameObjects();
        void initCamera();

        void initRenderer();
        void cleanUpRenderer();

        void initRenderSubSystems();
        void cleanUpRenderSubSystems();

        void initDescriptors();
        void cleanUpDescriptors();

    private:
        void init(){
            initWindow();
            initVulkan();
            initCamera();
            Components::registerComponents();
            initRenderer();
            initDescriptors();
            initRenderSubSystems();
            initGameObjects();
            MouseInput::setMouseCallback(_Camera, _Window);
        }
        void cleanUp(){
            cleanUpDescriptors();
            cleanUpRenderSubSystems();
            cleanUpRenderer();
            cleanUpVulkan();
            cleanUpWindow();
        }

        void mainLoop();

    public:
        Application(){};

        void run(){
            init();
            mainLoop();
            cleanUp();
        }

        WindowPtr getWindow() const {
            return _Window;
        }
};