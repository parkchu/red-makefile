#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(testTest)
{
	RUN_TEST_CASE(testTest, test_sum);
	RUN_TEST_CASE(testTest, test_exam1);
	RUN_TEST_CASE(testTest, test_exam2);
	RUN_TEST_CASE(testTest, test_exam3);
}
