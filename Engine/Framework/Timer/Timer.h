
#ifndef ENGINE_FRAMEWORK_TIMER_TIMER_H
#define ENGINE_FRAMEWORK_TIMER_TIMER_H

namespace Framework
{
	class Timer
	{
	public:
		Timer();

		void Reset();
		void Pause();
		void Unpause();
		void Tick();

		bool IfSecondElapsed();

		float GetTotalTimeElapsed();
		float GetDeltaTime();

	private:
		__int64 mStartTime;
		__int64 mPausedTime;
		__int64 mPreviousTime;
		__int64 mCurrentTime;

		float mSecondsPerCount;
		float mDeltaTime;
		float mTotalElapsedTime;
		float mLastSecond;

		bool bIsPaused;
		char pad0;
		char pad1;
		char pad2;
	};
}

#endif // !ENGINE_FRAMEWORK_TIMER_TIMER_H


