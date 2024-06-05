#include <gtest/gtest.h>
#include "maths/dynamic_stack.h"


TEST(DynamicStack, Test)
{
	core::DynamicStack<int> DS;
	EXPECT_EQ(DS.isEmpty(), true);
	DS.push(1);
	DS.push(2);
	EXPECT_EQ(DS.isEmpty(), false);
	EXPECT_EQ(DS.top(), 2);
	DS.pop();
	EXPECT_EQ(DS.top(), 1);
}