#include <gtest/gtest.h>
#include <maths/dynamic_queue.h>


TEST(DynamicQueue, Test)
{
	core::DynamicQueue<int> DQ;
	EXPECT_TRUE(DQ.isEmpty());
	DQ.enqueue(1);
	DQ.enqueue(2);
	EXPECT_FALSE(DQ.isEmpty());
	EXPECT_EQ(DQ.front(), 1);
	DQ.dequeue();
	EXPECT_EQ(DQ.front(), 2);
	DQ.dequeue();
	DQ.enqueue(10);
	DQ.enqueue(11);
	DQ.enqueue(12);
	DQ.enqueue(13);
	DQ.enqueue(14);
	EXPECT_EQ(DQ.capacity(), 5);
	DQ.enqueue(15);
	DQ.enqueue(16);
	EXPECT_EQ(DQ.capacity(), 7);
	DQ.dequeue();
	DQ.dequeue();
	DQ.dequeue();
	DQ.dequeue();
	DQ.dequeue();
	EXPECT_EQ(DQ.capacity(), 2);

}