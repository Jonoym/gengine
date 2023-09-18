#include <SDL2/SDL.h>

#include <timing/TimeManager.h>
#include <core/Logger.h>

namespace Gengine
{

    TimeManager::TimeManager()
        : mStartTicks(0)
        , mPausedTicks(0)
        , mStarted(false)
        , mPaused(false)
        , mFrames(0)
        , mCurrentTicks(0)
        , mPreviousTicks(SDL_GetTicks())
        , mDeltaTime(0.0f)
    {
        L_INFO("[TIMER]", "Initialising Time Manager");
    }

    void TimeManager::Start()
    {
        L_INFO("[TIMER]", "Starting Time Manager");

        mStarted = true;
        mPaused = false;
        mStartTicks = SDL_GetTicks();
        mPausedTicks = 0;
    }

    void TimeManager::Stop()
    {
        L_INFO("[TIMER]", "Stopping Time Manager");
        mStarted = false;
        mPaused = false;
        mStartTicks = 0;
        mPausedTicks = 0;
    }

    void TimeManager::Pause()
    {

        if (mStarted && !mPaused)
        {
            L_INFO("[TIMER]", "Pausing Time Manager");
            mPaused = true;
            mPausedTicks = SDL_GetTicks() - mStartTicks;
            mStartTicks = 0;
        }
    }

    void TimeManager::Unpause()
    {
        if (mStarted && mPaused)
        {
            L_INFO("[TIMER]", "Unpausing Time Manager");
            mPaused = false;
            mStartTicks = SDL_GetTicks() - mPausedTicks;
            mPausedTicks = 0;
        }
    }

    uint32 TimeManager::GetTicks()
    {
        if (mStarted)
        {
            if (mPaused)
            {
                L_TRACE("[TIMER]", "Getting Game Ticks for Paused Game: %d", mPausedTicks);
                return mPausedTicks;
            }
            else
            {
                L_TRACE("[TIMER]", "Getting Game Ticks for Running Game: %d", SDL_GetTicks() - mStartTicks);
                return SDL_GetTicks() - mStartTicks;
            }
        }

        L_WARN("[TIMER]", "Timer Manager has not been started");
        return 0;
    }

    uint32 TimeManager::GetTotalTicks()
    {
        return SDL_GetTicks();
    }

    float32 TimeManager::GetDeltaTime()
    {
        return mDeltaTime;
    }

    void TimeManager::Tick()
    {
        mCurrentTicks = SDL_GetTicks();
        mDeltaTime = (mCurrentTicks - mPreviousTicks);
        mPreviousTicks = mCurrentTicks;
        mFrames++;
    }
}