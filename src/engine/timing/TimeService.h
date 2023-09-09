#pragma once

#include "../Types.h"

class TimeService
{
public:
    TimeService();

    void start();
    void stop();
    void pause();
    void unpause();
    void incrementFrame();

    uint32 getTicks();
    float32 getTimeSeconds();
    float32 getAverageFramerate();

    bool isStarted();
    bool isPaused();

private:
    uint32 mStartTicks;
    uint32 mPausedTicks;

    uint32 mFrames;

    bool mIsPaused;
    bool mIsStarted;
};