#include "solution.hpp"

#include <unordered_map>

int Solution::lengthOfLongestSubstring(const std::string& s) {
  std::unordered_map<char, int> charIndexMap;
  int maxLength = 0;
  int start = 0;  // Start position of current non-repeating substring

  for (int i = 0; i < s.size(); ++i) {
    if (charIndexMap.count(s[i]) && charIndexMap[s[i]] >= start) {
      start = charIndexMap[s[i]] + 1;  // Update start position
    }
    charIndexMap[s[i]] = i;  // Update last occurrence position of character
    maxLength = std::max(maxLength, i - start + 1);  // Update maximum length
  }

  return maxLength;
}
