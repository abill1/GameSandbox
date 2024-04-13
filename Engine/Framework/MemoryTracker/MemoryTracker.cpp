#include "MemoryTracker.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

void Framework::MemoryTracker::Init()
{
#if _DEBUG
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	// ----- Reports any leaks when the application closes
	std::atexit(Framework::MemoryTracker::Terminate);							
#endif

}

void Framework::MemoryTracker::Terminate()
{
	_CrtDumpMemoryLeaks();
}

