#pragma once

#include <scenes/IScene.h>
#include <services/ServiceManager.h>

namespace Gengine
{
    class Scene : public IScene
    {
    public:
        Scene();
        ~Scene();

        void Initialise() override;
        bool Update() override;
        void Dispose() override;

    private:
        ServiceManager mServiceManager;
        int counter = 0;
    };
}