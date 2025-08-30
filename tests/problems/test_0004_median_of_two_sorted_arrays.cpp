#include <gtest/gtest.h>

#include "../../src/problems/0004_median_of_two_sorted_arrays/solution.hpp"

class TwoSumTest : public ::testing::Test {
 protected:
  Solution sol;
};
#include <vector>
using std::vector;

class MedianOfTwoSortedArraysTest : public ::testing::Test {
 protected:
  Solution sol;
};
// ---------- 官方/常见示例 ----------

TEST_F(MedianOfTwoSortedArraysTest, Example_SingleInsertBetweenTwo) {
  // [1,3] + [2] => 2.0
  std::vector<int> a{1, 3};
  std::vector<int> b{2};
  EXPECT_DOUBLE_EQ(sol.findMedianSortedArrays(a, b), 2.0);
  // LeetCode 示例。:contentReference[oaicite:1]{index=1}
}

TEST_F(MedianOfTwoSortedArraysTest, Example_EvenTotalLength) {
  // [1,2] + [3,4] => (2 + 3) / 2 = 2.5
  std::vector<int> a{1, 2};
  std::vector<int> b{3, 4};
  EXPECT_DOUBLE_EQ(sol.findMedianSortedArrays(a, b), 2.5);
  // LeetCode 常见讲解场景。:contentReference[oaicite:2]{index=2}
}

// ---------- 一边为空（题目允许总长度>=1） ----------

TEST_F(MedianOfTwoSortedArraysTest, OneArrayEmpty_SingleElement) {
  // [] + [1] => 1.0
  std::vector<int> a{};
  std::vector<int> b{1};
  EXPECT_DOUBLE_EQ(sol.findMedianSortedArrays(a, b), 1.0);
}

TEST_F(MedianOfTwoSortedArraysTest, OneArrayEmpty_EvenCount) {
  // [] + [2,3] => 2.5
  std::vector<int> a{};
  std::vector<int> b{2, 3};
  EXPECT_DOUBLE_EQ(sol.findMedianSortedArrays(a, b), 2.5);
}

TEST_F(MedianOfTwoSortedArraysTest, OneArrayEmpty_AllInFirst) {
  // [1,2,3,4,5] + [] => 3.0
  std::vector<int> a{1, 2, 3, 4, 5};
  std::vector<int> b{};
  EXPECT_DOUBLE_EQ(sol.findMedianSortedArrays(a, b), 3.0);
}

// ---------- 不同长度 / 交错 / 重复 / 负数 ----------

TEST_F(MedianOfTwoSortedArraysTest, DifferentSizes_Interleaving) {
  // [1,3,8,9,15] + [7,11,18,19,21,25] => 合并后中位数 11
  std::vector<int> a{1, 3, 8, 9, 15};
  std::vector<int> b{7, 11, 18, 19, 21, 25};
  EXPECT_DOUBLE_EQ(sol.findMedianSortedArrays(a, b), 11.0);
}

TEST_F(MedianOfTwoSortedArraysTest, Duplicates_AllZeros) {
  // [0,0] + [0,0] => 0.0
  std::vector<int> a{0, 0};
  std::vector<int> b{0, 0};
  EXPECT_DOUBLE_EQ(sol.findMedianSortedArrays(a, b), 0.0);
}

TEST_F(MedianOfTwoSortedArraysTest, WithNegatives) {
  // [-5,-3,-1] + [2,4,6,8] => 2.0
  std::vector<int> a{-5, -3, -1};
  std::vector<int> b{2, 4, 6, 8};
  EXPECT_DOUBLE_EQ(sol.findMedianSortedArrays(a, b), 2.0);
}

TEST_F(MedianOfTwoSortedArraysTest, TinyBothLenOne) {
  // [2] + [3] => 2.5
  std::vector<int> a{2};
  std::vector<int> b{3};
  EXPECT_DOUBLE_EQ(sol.findMedianSortedArrays(a, b), 2.5);
}

// ----------（可选）健壮性：两者皆空时的行为（视实现而定）----------
// LeetCode 语境下通常保证总长度 >=
// 1；若你选择在两者皆空时抛异常，可启用此测例。
// TEST_F(MedianOfTwoSortedArraysTest, BothEmpty_ShouldThrow) {
//     std::vector<int> a{}, b{};
//     EXPECT_ANY_THROW(sol.findMedianSortedArrays(a, b));
// }
