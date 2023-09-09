#include <SDL2/SDL.h>
#include "TimeService.h"

TimeService::TimeService()
    : mStartTicks(0), mPausedTicks(0), mIsPaused(false), mIsStarted(false)
{
}

void TimeService::start()
{
    mIsStarted = true;
    mIsPaused = false;

    mStartTicks = SDL_GetTicks();
    mPausedTicks = 0;
}

void TimeService::stop()
{
    mIsStarted = false;
    mIsPaused = false;

    mStartTicks = 0;
    mPausedTicks = 0;
}

void TimeService::pause()
{
    if (mIsStarted && !mIsPaused)
    {
        mIsPaused = true;

        mPausedTicks = SDL_GetTicks() - mStartTicks;
        mStartTicks = 0;
    }
}

void TimeService::unpause()
{
    if (mIsStarted && mIsPaused)
    {
        mIsPaused = false;

        mStartTicks = SDL_GetTicks() - mPausedTicks;
        mPausedTicks = 0;
    }
}

void TimeService::incrementFrame()
{
    mFrames++;
}

uint32 TimeService::getTicks()
{
    uint32 time = 0;

    if (mIsStarted)
    {
        if (mIsPaused)
        {
            time = mPausedTicks;
        }
        else
        {
            time = SDL_GetTicks() - mStartTicks;
        }
    }

    return time;
}

float32 TimeService::getTimeSeconds()
{
    return getTicks() / 1000.0f;
}

float32 TimeService::getAverageFramerate()
{
    float averageFramesPerSecond = mFrames / getTimeSeconds();

    return (averageFramesPerSecond < 1000) ? averageFramesPerSecond : 0;
}

bool TimeService::isStarted()
{
    return mIsStarted;
}

bool TimeService::isPaused()
{
    return mIsPaused;
}