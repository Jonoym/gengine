#pragma once

#include <Includes.h>
#include <components/Component.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    enum class BoundType
    {
        CIRCULAR,
        RECTANGLE
    };

    enum class DebugColour
    {
        RED,        // Collisions
        BLUE,       // Assets and Sprites
        GREEN
    };  

    class IDebugRenderableComponent
    {
    public:
        IDebugRenderableComponent(DebugColour colour, BoundType boundType)
            : mColour(colour), mBoundType(boundType) {}
        IDebugRenderableComponent(const IDebugRenderableComponent &other) {}
        virtual void RenderDebug() = 0;
    
    protected:
        DebugColour mColour;
        BoundType mBoundType;
    };
}