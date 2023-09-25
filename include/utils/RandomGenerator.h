#pragma once
#include <Includes.h>

namespace Gengine
{
    namespace RandomGenerator
    {
        uint32 GenerateUnsignedInt();
        uint32 GenerateUnsignedInt(uint32 upperbound);
        uint32 GenerateUnsignedInt(uint32 lowerbound, uint32 upperbound);

        uint32 GenerateSignedInt();
        uint32 GenerateSignedInt(uint32 upperbound);
        uint32 GenerateSignedInt(uint32 lowerbound, uint32 upperbound);
    }
}