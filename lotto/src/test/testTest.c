#include "unity/src/unity.h"
#include "../main/test.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_sum(void) {
	TEST_ASSERT_EQUAL(10, sum(3, 7));
}

int main (void) {
	UNITY_BEGIN();
	RUN_TEST(test_sum);
	UNITY_END();
}
