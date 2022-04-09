#include "unity.h"
#include "unity_fixture.h"
#include "test.h"

TEST_GROUP(testTest);

TEST_SETUP(testTest)
{
}

TEST_TEAR_DOWN(testTest)
{
}

TEST(testTest, test_sum)
{
	int result;
	result = 10;
	TEST_ASSERT_EQUAL(10, sum(3, 7));
}

TEST(testTest, test_exam1)
{
	TEST_IGNORE();
	TEST_ASSERT_EQUAL(0, 0);
}

TEST(testTest, test_exam2)
{
	TEST_ASSERT_EQUAL(0, 0);
}

TEST(testTest, test_exam3)
{
	TEST_ASSERT_EQUAL(1, 0);
}
