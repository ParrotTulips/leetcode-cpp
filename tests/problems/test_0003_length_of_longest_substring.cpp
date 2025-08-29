#include <gtest/gtest.h>

#include <string>

#include "../../src/problems/0003_length_of_longest_substring/solution.hpp"

class LongestSubstringTest : public ::testing::Test {
 protected:
  Solution sol;
};

TEST_F(LongestSubstringTest, HandlesEmptyString) {
  EXPECT_EQ(sol.lengthOfLongestSubstring(""), 0);
}

TEST_F(LongestSubstringTest, SingleCharacter) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("a"), 1);
}

TEST_F(LongestSubstringTest, RepeatingPattern) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST_F(LongestSubstringTest, AllSameCharacters) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("bbbbb"), 1);
}

TEST_F(LongestSubstringTest, ExamplePwwkew) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("pwwkew"), 3);
}

TEST_F(LongestSubstringTest, SingleSpace) {
  EXPECT_EQ(sol.lengthOfLongestSubstring(" "), 1);
}

TEST_F(LongestSubstringTest, MixedCharacters) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("dvdf"), 3);
}

TEST_F(LongestSubstringTest, PalindromeRepetition) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("abba"), 2);
}

TEST_F(LongestSubstringTest, Geeksforgeeks) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("geeksforgeeks"), 7);
}

TEST_F(LongestSubstringTest, MixedPrefixSuffix) {
  EXPECT_EQ(sol.lengthOfLongestSubstring("abcdefabcbb"), 6);
}

// main 函数由 GTest 提供，一般无需手动实现
