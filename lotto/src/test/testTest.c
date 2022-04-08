#include "unity/src/unity.h"
#include "main/test.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_sum(void) {
	TEST_ASSERT_EQUAL(0, sum(3, 7));
}

void test_exam(void) {
	TEST_ASSERT_EQUAL(0, 0);
}

int main (void) {
	int failTests;
	UNITY_BEGIN();
	RUN_TEST(test_sum);
	RUN_TEST(test_exam);
	failTests = UNITY_END();
	if (failTests > 0)
	{
		printf("TEST FAILED ... \n");
	}
	return failTests;
}
