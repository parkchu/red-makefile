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
	TEST_ASSERT_EQUAL(1, sum(3, 7));
}

TEST(testTest, test_exam)
{
	TEST_ASSERT_EQUAL(0, 0);
}

void test_sum(void) {
	TEST_ASSERT_EQUAL(10, sum(3, 7));
}

