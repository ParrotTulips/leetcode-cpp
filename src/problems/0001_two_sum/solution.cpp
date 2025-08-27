#include "solution.hpp"

#include <unordered_map>

vector<int> Solution::twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> hash;
  for (size_t i = 0; i < nums.size(); ++i) {
    int complement = target - nums[i];
    if (hash.count(complement)) {
      return {hash[complement], static_cast<int>(i)};
    }
    hash[nums[i]] = static_cast<int>(i);
  }
  return {};
}
