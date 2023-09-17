#pragma once

#include <screens/IScreen.h>

namespace Gengine
{
    class Screen : public IScreen
    {
    public:
        Screen();
        ~Screen();

        void Initialise() override;
        bool Update() override;
        void Dispose() override;
    };
}