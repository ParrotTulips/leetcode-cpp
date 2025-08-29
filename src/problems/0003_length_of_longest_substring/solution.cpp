#include "solution.hpp"

#include <unordered_map>

int Solution::lengthOfLongestSubstring(const std::string& s) {
  std::unordered_map<char, int> charIndexMap;
  int maxLength = 0;
  int start = 0;  // 当前无重复子串的起始位置

  for (int i = 0; i < s.size(); ++i) {
    if (charIndexMap.count(s[i]) && charIndexMap[s[i]] >= start) {
      start = charIndexMap[s[i]] + 1;  // 更新起始位置
    }
    charIndexMap[s[i]] = i;                          // 更新字符最后出现的位置
    maxLength = std::max(maxLength, i - start + 1);  // 更新最大长度
  }

  return maxLength;
}
