#pragma once

#include "componentModel.hpp"
#include "componentTransform.hpp"
#include "componentRenderSubSystem.hpp"

#include "gameCoordinator.hpp"

class Components{

    private:
        Components(){};

    public:
        static void registerComponents(){
            GameCoordinator::registerComponent<ComponentModel>();
            GameCoordinator::registerComponent<ComponentTransform>();
            GameCoordinator::registerComponent<ComponentRenderSubSystem>();
        }

};