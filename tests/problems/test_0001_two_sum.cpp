// tests/test_0001_two_sum_catch2.cpp
#include "../../src/problems/0001_two_sum/solution.hpp"

// Catch2 v3 断言与 TEST_CASE 宏
#include <catch2/catch_test_macros.hpp>

TEST_CASE("0001 two sum basic cases", "[two_sum]") {
  Solution sol;

  SECTION("case1: [2,7,11,15], target=9 -> [0,1]") {
    std::vector<int> nums = {2, 7, 11, 15};
    auto res = sol.twoSum(nums, 9);
    REQUIRE(res == std::vector<int>({0, 1}));
  }

  SECTION("case2: [3,2,4], target=6 -> [1,2]") {
    std::vector<int> nums = {3, 2, 4};
    auto res = sol.twoSum(nums, 6);
    REQUIRE(res == std::vector<int>({1, 2}));
  }

  SECTION("case3: [3,3], target=6 -> [0,1]") {
    std::vector<int> nums = {3, 3};
    auto res = sol.twoSum(nums, 6);
    REQUIRE(res == std::vector<int>({0, 1}));
  }
}
