#include <gtest/gtest.h>

#include <chrono>
#include <random>

#include "../../src/problems/0001_two_sum/solution.hpp"

class TwoSumTest : public ::testing::Test {
 protected:
  Solution sol;
};

// Basic test cases
TEST_F(TwoSumTest, BasicCases) {
  // case1: [2,7,11,15], target=9 -> [0,1]
  std::vector<int> nums1 = {2, 7, 11, 15};
  auto res1 = sol.twoSum(nums1, 9);
  EXPECT_EQ(res1, std::vector<int>({0, 1}));

  // case2: [3,2,4], target=6 -> [1,2]
  std::vector<int> nums2 = {3, 2, 4};
  auto res2 = sol.twoSum(nums2, 6);
  EXPECT_EQ(res2, std::vector<int>({1, 2}));

  // case3: [3,3], target=6 -> [0,1]
  std::vector<int> nums3 = {3, 3};
  auto res3 = sol.twoSum(nums3, 6);
  EXPECT_EQ(res3, std::vector<int>({0, 1}));
}

// Benchmark test class
class TwoSumBenchmark : public ::testing::Test {
 protected:
  Solution sol;

  // Generate test data
  std::pair<std::vector<int>, int> generateTestData(size_t n) {
    std::vector<int> nums;
    nums.reserve(n);

    // Use fixed seed to ensure reproducibility
    std::mt19937 gen(42);
    std::uniform_int_distribution<> dis(1, 10000);

    for (size_t i = 0; i < n; ++i) {
      nums.push_back(dis(gen));
    }

    // Ensure solution exists
    int target = nums[1] + nums[n - 2];

    return {nums, target};
  }
};

// Benchmark test: different input sizes
TEST_F(TwoSumBenchmark, VariousSizes) {
  auto [nums1k, target1k] = generateTestData(1000);
  auto [nums10k, target10k] = generateTestData(10000);
  auto [nums100k, target100k] = generateTestData(100000);

  // Warm up
  for (int i = 0; i < 10; ++i) {
    sol.twoSum(nums1k, target1k);
  }

  // Measure 1000 elements
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 100; ++i) {
    sol.twoSum(nums1k, target1k);
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto duration1k =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  // Measure 10000 elements
  start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 100; ++i) {
    sol.twoSum(nums10k, target10k);
  }
  end = std::chrono::high_resolution_clock::now();
  auto duration10k =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  // Measure 100000 elements
  start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 100; ++i) {
    sol.twoSum(nums100k, target100k);
  }
  end = std::chrono::high_resolution_clock::now();
  auto duration100k =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  // Output results (in tests we only verify the function runs normally)
  EXPECT_TRUE(true);  // Benchmark focuses on performance, here we only verify
                      // functionality

  // Optional: output performance data to console
  std::cout << "Benchmark results:" << std::endl;
  std::cout << "1000 elements: " << duration1k.count() / 100.0 << " μs per call"
            << std::endl;
  std::cout << "10000 elements: " << duration10k.count() / 100.0
            << " μs per call" << std::endl;
  std::cout << "100000 elements: " << duration100k.count() / 100.0
            << " μs per call" << std::endl;
}
