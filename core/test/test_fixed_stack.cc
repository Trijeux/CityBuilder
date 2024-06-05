#include <gtest/gtest.h>

#include "maths/fixed_stack.h"

TEST(FixedStack, Test)
{
	core::FixedStack<int, 10> FS;
	EXPECT_EQ(FS.capacity(), 10);
	EXPECT_EQ(FS.isEmpty(), true);
	FS.push(1);
	FS.push(2);
	EXPECT_EQ(FS.isEmpty(), false);
	EXPECT_EQ(FS.top(), 2);
	FS.pop();
	EXPECT_EQ(FS.top(), 1);
}