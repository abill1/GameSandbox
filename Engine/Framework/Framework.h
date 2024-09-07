
#ifndef ENGINE_FRAMEWORK_H
#define ENGINE_FRAMEWORK_H

//======================================================================
// Includes
//======================================================================

#include "Buffer/Buffer.h"
#include "Codes/ABCode.h"
#include "Constants/Constants.h"
#include "File/ABFile.h"
#include "MemoryTracker/MemoryTracker.h"
#include "String/ABString.h"
#include "Timer/Timer.h"

//======================================================================
// STD Includes
//======================================================================

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <random>
#include <chrono>

//======================================================================
// Assert Macros
//======================================================================

#include <assert.h>

#define CHECK_NULL(x) assert(x != nullptr)
#define CHECK_SUCCESS(x) assert(x == Framework::Code::SUCCESS);
#define CHECK_EQUAL(x, y) assert(x == y);

//======================================================================
// Helper Macros
//======================================================================

#define UNUSED_VAR(x) (void(x))


#endif // !ENGINE_FRAMEWORK_H

