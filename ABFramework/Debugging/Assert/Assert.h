
#ifndef ABFRAMEWORK_ASSERT_H
#define ABFRAMEWORK_ASSERT_H

#include <assert.h>

#define CHECK_NULL(x) assert(x != nullptr)
#define CHECK_SUCCESS(x) assert(x == ABFramework::Code::SUCCESS);
#define CHECK_EQUAL(x, y) assert(x == y);

#endif // !ABFRAMEWORK_ASSERT_H


