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
        float32 GetDeltaTime();
        void Tick();

    private:

        uint32 mStartTicks;
        uint32 mPausedTicks;
        uint32 mFrames;

        uint32 mCurrentTicks;
        uint32 mPreviousTicks;
        float32 mDeltaTime;

        bool mPaused;
        bool mStarted;
    };
}