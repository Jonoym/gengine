#pragma once

#include <fstream>
#include <sstream>
#include <iostream>

#include <Includes.h>
#include <utils/Vector2D.h>

namespace Gengine
{

    struct AtlasRegion
    {
        std::string mAnimationName;
        bool mRotate;
        uint8 mRegion;
        Coord mLocation;
        Coord mSize;
        Coord mOriginal;
        Coord mOffset;
        uint8 mIndex;
    };


    class AtlasReader
    {
    public:
        static std::vector<AtlasRegion> ParseAtlasFile(const std::string& atlasFilename);
    private:
        static bool ParseLineBool(const std::string& propertyName);
        static uint8 ParseLineInt(const std::string& propertyName);
        static Coord ParseLineCoord(const std::string& propertyName);
    };
}