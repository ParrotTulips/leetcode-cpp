#include "../../../src/problems/002_add_two_numbers/solution.hpp"
#include <cassert>
#include <iostream>
#include <vector>

ListNode *createList(const std::vector<int> &vals) {
  ListNode dummy(0);
  ListNode *curr = &dummy;
  for (int v : vals) {
    curr->next = new ListNode(v);
    curr = curr->next;
  }
  return dummy.next;
}

std::vector<int> toVector(ListNode *head) {
  std::vector<int> res;
  while (head) {
    res.push_back(head->val);
    head = head->next;
  }
  return res;
}

void test_addTwoNumbers() {
  Solution sol;
  ListNode *l1 = createList({2, 4, 3});
  ListNode *l2 = createList({5, 6, 4});
  ListNode *result = sol.addTwoNumbers(l1, l2);
  std::vector<int> expected = {7, 0, 8};
  assert(toVector(result) == expected);
  std::cout << "Test 1 passed!\n";

  l1 = createList({0});
  l2 = createList({0});
  result = sol.addTwoNumbers(l1, l2);
  expected = {0};
  assert(toVector(result) == expected);
  std::cout << "Test 2 passed!\n";

  l1 = createList({9, 9, 9, 9, 9, 9, 9});
  l2 = createList({9, 9, 9, 9});
  result = sol.addTwoNumbers(l1, l2);
  expected = {8, 9, 9, 9, 0, 0, 0, 1};
  assert(toVector(result) == expected);
  std::cout << "Test 3 passed!\n";
}

int main() {
  test_addTwoNumbers();
  std::cout << "All tests passed!\n";
  return 0;
}
