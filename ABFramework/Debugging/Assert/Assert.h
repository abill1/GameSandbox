
#ifndef ABFRAMEWORK_ASSERT_H
#define ABFRAMEWORK_ASSERT_H

#include <assert.h>

#define CHECK_NULL(x) assert(x != nullptr)
#define CHECK_SUCCESS(x) assert(x == ABFramework::Code::SUCCESS)
#define CHECK_EQUAL(x, y) assert(x == y)
#define CHECK_LESS(x, y) assert(x < y)
#define CHECK_GREATER(x, y) assert(x > y)
#define CHECK_NOTZERO(x) assert(x != 0)

#endif // !ABFRAMEWORK_ASSERT_H


