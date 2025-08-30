#include "solution.hpp"

double Solution::findMedianSortedArrays(std::vector<int>& nums1,
                                        std::vector<int>& nums2) {
  // Ensure nums1 is the smaller array
  if (nums1.size() > nums2.size()) {
    return findMedianSortedArrays(nums2, nums1);
  }

  int m = nums1.size();
  int n = nums2.size();
  int totalLeft = (m + n + 1) / 2;

  int left = 0;
  int right = m;

  while (left < right) {
    int i = left + (right - left + 1) / 2;  // Partition in nums1
    int j = totalLeft - i;                  // Corresponding partition in nums2

    if (nums1[i - 1] > nums2[j]) {
      right = i - 1;  // Move partition in nums1 to the left
    } else {
      left = i;  // Move partition in nums1 to the right
    }
  }

  int i = left;
  int j = totalLeft - i;

  int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
  int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
  int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
  int nums2RightMin = (j == n) ? INT_MAX : nums2[j];

  if ((m + n) % 2 == 1) {
    return std::max(nums1LeftMax, nums2LeftMax);
  } else {
    return (std::max(nums1LeftMax, nums2LeftMax) +
            std::min(nums1RightMin, nums2RightMin)) /
           2.0;
  }
}
