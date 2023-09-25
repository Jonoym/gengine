#pragma once

#include <Includes.h>

namespace Gengine
{
    class TerrainGenerator
    {
    public:
        TerrainGenerator();
        ~TerrainGenerator();
        void GenerateTerrain(const std::string& map);

    private:

        const int32 SCREEN_WIDTH = 1920;
        const int32 SCREEN_HEIGHT = 1080;

        const int32 TILE_SIZE = 160;
        const int16 ROW_LENGTH = 13;
        const int16 COLUMN_HEIGHT = 8;
    };
}