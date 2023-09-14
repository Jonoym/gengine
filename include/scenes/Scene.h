#pragma once

#include <scenes/IScene.h>

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
    };
}