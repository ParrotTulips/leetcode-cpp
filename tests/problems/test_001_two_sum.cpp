#include "../../src/problems/001_two_sum/solution.hpp"
#include <cassert>
#include <iostream>
using namespace std;

void test_two_sum() {
  Solution sol;

  // 测试用例1
  vector<int> nums1 = {2, 7, 11, 15};
  int target1 = 9;
  vector<int> result1 = sol.twoSum(nums1, target1);
  assert(result1 == vector<int>({0, 1}));
  cout << "Test 1 passed!" << endl;

  // 测试用例2
  vector<int> nums2 = {3, 2, 4};
  int target2 = 6;
  vector<int> result2 = sol.twoSum(nums2, target2);
  assert(result2 == vector<int>({1, 2}));
  cout << "Test 2 passed!" << endl;

  // 测试用例3
  vector<int> nums3 = {3, 3};
  int target3 = 6;
  vector<int> result3 = sol.twoSum(nums3, target3);
  assert(result3 == vector<int>({0, 1}));
  cout << "Test 3 passed!" << endl;
}

int main() {
  test_two_sum();
  cout << "All tests passed!" << endl;
  return 0;
}
