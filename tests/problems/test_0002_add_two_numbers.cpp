#include <gtest/gtest.h>

#include <vector>

#include "../../src/problems/0002_add_two_numbers/solution.hpp"

// Linked list utilities for testing only
static ListNode* createList(const std::vector<int>& vals) {
  ListNode dummy(0);
  ListNode* curr = &dummy;
  for (int v : vals) {
    curr->next = new ListNode(v);
    curr = curr->next;
  }
  return dummy.next;
}

static std::vector<int> toVector(ListNode* head) {
  std::vector<int> res;
  while (head) {
    res.push_back(head->val);
    head = head->next;
  }
  return res;
}

static void freeList(ListNode* head) {
  while (head) {
    ListNode* n = head->next;
    delete head;
    head = n;
  }
}

class AddTwoNumbersTest : public ::testing::Test {
 protected:
  Solution sol;
};

TEST_F(AddTwoNumbersTest, BasicCases) {
  // case1: [2,4,3] + [5,6,4] -> [7,0,8]
  ListNode* l1 = createList({2, 4, 3});
  ListNode* l2 = createList({5, 6, 4});
  ListNode* result = sol.addTwoNumbers(l1, l2);
  EXPECT_EQ(toVector(result), std::vector<int>({7, 0, 8}));
  freeList(result);
  freeList(l1);
  freeList(l2);
}

TEST_F(AddTwoNumbersTest, ZeroCase) {
  // case2: [0] + [0] -> [0]
  ListNode* l1 = createList({0});
  ListNode* l2 = createList({0});
  ListNode* result = sol.addTwoNumbers(l1, l2);
  EXPECT_EQ(toVector(result), std::vector<int>({0}));
  freeList(result);
  freeList(l1);
  freeList(l2);
}

TEST_F(AddTwoNumbersTest, LongCarryCase) {
  // case3: Long carry [9,9,9,9,9,9,9] + [9,9,9,9] -> [8,9,9,9,0,0,0,1]
  ListNode* l1 = createList({9, 9, 9, 9, 9, 9, 9});
  ListNode* l2 = createList({9, 9, 9, 9});
  ListNode* result = sol.addTwoNumbers(l1, l2);
  EXPECT_EQ(toVector(result), std::vector<int>({8, 9, 9, 9, 0, 0, 0, 1}));
  freeList(result);
  freeList(l1);
  freeList(l2);
}
