#include <gtest/gtest.h>

#include "maths/fixed_queue.h"

TEST(FixedQueue, Test)
{
	core::FixedQueue<int, 10> FQ;
	EXPECT_EQ(FQ.capacity(), 10);
	EXPECT_TRUE(FQ.isEmpty());
	EXPECT_EQ(FQ.size(), 0);
	FQ.enqueue(1);
	FQ.enqueue(2);
	EXPECT_EQ(FQ.size(), 2);
	EXPECT_FALSE(FQ.isEmpty());
	EXPECT_EQ(FQ.front(), 1);
	FQ.dequeue();
	EXPECT_EQ(FQ.front(), 2);
}