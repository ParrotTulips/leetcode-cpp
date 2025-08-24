// tests/test_0001_two_sum_catch2.cpp
#include "../../src/problems/0001_two_sum/solution.hpp"

// Catch2 v3 断言与 TEST_CASE 宏
#include <catch2/benchmark/catch_benchmark.hpp> // ← 新增
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

// 基准：仅测量 twoSum 调用本身（避免把数据准备时间算进去）
TEST_CASE("bench twoSum on various sizes", "[two_sum][!benchmark]") {
  Solution sol;

  auto bench_once = [&](std::size_t n) {
    // 准备输入：大致均匀随机，确保始终有解
    std::vector<int> nums;
    nums.reserve(n);
    for (std::size_t i = 0; i < n; ++i)
      nums.push_back(static_cast<int>(i % 10007));
    int target = nums[1] + nums[n - 2];

    // 简单基准（按 Catch2 的采样/自举规则多次测量）
    BENCHMARK("twoSum N=" + std::to_string(n)) {
      // 仅测量被测函数
      return sol.twoSum(nums, target);
    };
  };

  bench_once(1'000);
  bench_once(10'000);
  bench_once(100'000);
}

// 若需要更细的控制（把“准备数据”与“被测代码”严格分离），用 ADVANCED 版本：
TEST_CASE("bench twoSum advanced", "[two_sum][!benchmark]") {
  using Catch::Benchmark::Chronometer;

  Solution sol;
  const std::size_t n = 50'000;

  BENCHMARK_ADVANCED("twoSum advanced N=50k")(Chronometer meter) {
    // —— 准备阶段（不计入测量） ——
    std::vector<int> nums;
    nums.reserve(n);
    for (std::size_t i = 0; i < n; ++i)
      nums.push_back(static_cast<int>(i % 10007));
    int target = nums[123] + nums[n - 321];

    // —— 真正测量 ——（meter 会根据采样策略多次调用 lambda）
    meter.measure([&] { return sol.twoSum(nums, target); });
  };
}
