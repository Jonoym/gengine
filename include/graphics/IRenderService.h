#pragma once

#include <Includes.h>

namespace Gengine
{
    struct IRenderService {
        
        virtual void Render(const std::string& assetName, const Vector2D& position) = 0;

    };

}