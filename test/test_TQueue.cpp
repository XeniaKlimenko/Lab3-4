#include "Queue.h"
#include "../gtest/gtest.h"

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> Q(3));
}

TEST(TQueue, cant_create_queue_with_null)
{
	ASSERT_ANY_THROW(TQueue<int> Q(0));
}


TEST(TQueue, create_empty_queue)
{
	TQueue<int> Q(3);

	EXPECT_EQ(true, Q.IsEmpty());
}


TEST(TQueue, can_push)
{
	TQueue<int> Q(3);

	ASSERT_NO_THROW(Q.Push(3));
}

TEST(TQueue, can_get_elem)
{
	TQueue<int> Q(2);
	Q.Push(4);

	EXPECT_EQ(4, Q.Get());
}

TEST(TQueue, cant_get_if_empty)
{
	TQueue<int> Q(1);

	ASSERT_ANY_THROW(Q.Get());
}

TEST(TQueue, can_copy_queue)
{
	TQueue<int> Q1(2);
	Q1.Push(1);

	ASSERT_NO_THROW(TQueue<int> Q2(Q1));
}


TEST(TQueue, can_get_Lenght)
{
	TQueue<int> Q(2);

	EXPECT_EQ(2, Q.Length());
}

TEST(TQueue, can_get_min_elem)
{
	TQueue<int> Q(3);
	Q.Push(1);
	Q.Push(5);
	Q.Push(10);

	EXPECT_EQ(1, Q.min_elem());
}

TEST(TQueue, can_get_max_elem)
{
	TQueue<int> Q(3);
	Q.Push(1);
	Q.Push(5);
	Q.Push(10);

	EXPECT_EQ(10, Q.max_elem());
}