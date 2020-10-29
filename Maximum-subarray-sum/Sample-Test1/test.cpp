#include "pch.h"
#include "gtest/gtest.h"
#include "../Maximum-subarray-sum/Maximum-subarray-sum.cpp"


TEST(TestCaseName, TestName) {
  ASSERT_EQ(6, maxSequence({ -2, 1, -3, 4, -1, 2, 1, -5, 4 }));
  EXPECT_EQ(6, maxSequence({ -2, 1, -3, 4, -1, 2, 1, -5, 4 }));
  EXPECT_TRUE(true);
}

