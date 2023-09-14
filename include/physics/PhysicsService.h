#pragma once

#include <services/IService.h>

namespace Gengine
{
    class PhysicsService : public IService
    {
    public:
        PhysicsService();
        ~PhysicsService();
        void Update() override;
    };
}