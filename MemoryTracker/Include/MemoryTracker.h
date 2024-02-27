
#ifndef MEMORY_TRACKER_H
#define MEMORY_TRACKER_H

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define new new
#endif

namespace ABFramework
{
	class MemoryTracker
	{
	public:
		MemoryTracker() = default;
		~MemoryTracker() = default;

		static void Init();
		static void Terminate();

	};
}

#endif // !MEMORY_TRACKER_H

