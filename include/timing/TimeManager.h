#pragma once

#include <Includes.h>

namespace Gengine
{
    class TimeManager
    {
    
    public:
        TimeManager();

        void Start();
        void Stop();
        void Pause();
        void Unpause();

        uint32 GetTicks();

    private:

        uint32 mStartTicks;
        uint32 mPausedTicks;

        bool mPaused;
        bool mStarted;
    };
}