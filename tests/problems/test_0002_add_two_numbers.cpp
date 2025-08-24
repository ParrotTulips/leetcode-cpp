#include "../../src/problems/0002_add_two_numbers/solution.hpp"
#include <catch2/catch_test_macros.hpp> // v3 断言/测试宏

#include <vector>

// 仅供测试的链表工具
static ListNode *createList(const std::vector<int> &vals) {
  ListNode dummy(0);
  ListNode *curr = &dummy;
  for (int v : vals) {
    curr->next = new ListNode(v);
    curr = curr->next;
  }
  return dummy.next;
}
static std::vector<int> toVector(ListNode *head) {
  std::vector<int> res;
  while (head) {
    res.push_back(head->val);
    head = head->next;
  }
  return res;
}
static void freeList(ListNode *head) {
  while (head) {
    ListNode *n = head->next;
    delete head;
    head = n;
  }
}

TEST_CASE("0002 addTwoNumbers basic cases", "[add_two_numbers]") {
  Solution sol;

  SECTION("case1: [2,4,3] + [5,6,4] -> [7,0,8]") {
    ListNode *l1 = createList({2, 4, 3});
    ListNode *l2 = createList({5, 6, 4});
    ListNode *result = sol.addTwoNumbers(l1, l2);
    REQUIRE(toVector(result) == std::vector<int>({7, 0, 8}));
    freeList(result);
    freeList(l1);
    freeList(l2);
  }

  SECTION("case2: [0] + [0] -> [0]") {
    ListNode *l1 = createList({0});
    ListNode *l2 = createList({0});
    ListNode *result = sol.addTwoNumbers(l1, l2);
    REQUIRE(toVector(result) == std::vector<int>({0}));
    freeList(result);
    freeList(l1);
    freeList(l2);
  }

  SECTION("case3: 长进位 [9,9,9,9,9,9,9] + [9,9,9,9] -> [8,9,9,9,0,0,0,1]") {
    ListNode *l1 = createList({9, 9, 9, 9, 9, 9, 9});
    ListNode *l2 = createList({9, 9, 9, 9});
    ListNode *result = sol.addTwoNumbers(l1, l2);
    REQUIRE(toVector(result) == std::vector<int>({8, 9, 9, 9, 0, 0, 0, 1}));
    freeList(result);
    freeList(l1);
    freeList(l2);
  }
}
