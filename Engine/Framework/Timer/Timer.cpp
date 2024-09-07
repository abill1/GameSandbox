
#include "Timer.h"
#include <Windows.h>

Framework::Timer::Timer()
	:mStartTime(0ll), mPausedTime(0ll), mPreviousTime(0ll), mCurrentTime(0ll),
	mSecondsPerCount(1.0f), mDeltaTime(0.0f), mTotalElapsedTime(0.0f), mLastSecond(0.0f), 
	bIsPaused(false), pad0(0), pad1(0), pad2(0)
{
	LARGE_INTEGER countsPerSec = {0};
	QueryPerformanceFrequency(&countsPerSec);
	this->mSecondsPerCount /= countsPerSec.QuadPart;
	QueryPerformanceCounter((LARGE_INTEGER*)&mStartTime);
	mPreviousTime = mStartTime;
}

void Framework::Timer::Reset()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&mStartTime);
	mPreviousTime = mStartTime;
	bIsPaused = false;
}

void Framework::Timer::Pause()
{
	if (!bIsPaused)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&mCurrentTime);
		mPausedTime = mCurrentTime;
		bIsPaused = true;
	}
}

void Framework::Timer::Unpause()
{
	if (bIsPaused)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&mCurrentTime);
		mPreviousTime = mCurrentTime;
		float timeDiff = (float)mCurrentTime;
		timeDiff -= mPausedTime;
		timeDiff *= mSecondsPerCount;
		mTotalElapsedTime += timeDiff;
		mPausedTime = 0ll;
		bIsPaused = false;

	}
}

void Framework::Timer::Tick()
{
	mDeltaTime = 0.0f;
	if (!bIsPaused)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&mCurrentTime);
		mDeltaTime = (float)mCurrentTime;
		mDeltaTime -= mPreviousTime;
		mDeltaTime *= mSecondsPerCount;
		mTotalElapsedTime += mDeltaTime;

		mPreviousTime = mCurrentTime;
		
	}
}

bool Framework::Timer::IfSecondElapsed()
{
	bool bSecond = false;
	if (mTotalElapsedTime - mLastSecond >= 1.0f)
	{
		mLastSecond = mTotalElapsedTime;
		bSecond = true;
	}
	return bSecond;
}

float Framework::Timer::GetTotalTimeElapsed()
{
	return mTotalElapsedTime;
}

float Framework::Timer::GetDeltaTime()
{
	return mDeltaTime;
}
