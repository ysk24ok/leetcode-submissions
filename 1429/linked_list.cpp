#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class FirstUnique {
 public:
  FirstUnique(vector<int>& nums) : count_(), num_nodes_(0), head_(nullptr), tail_(nullptr) {
    for (size_t i = 0; i < nums.size(); ++i) {
      add(nums[i]);
    }
  }

  ~FirstUnique() {
    ListNode* node = head_;
    while (node) {
      ListNode* next = node->next;
      delete node;
      node = next;
    }
  }

  int showFirstUnique() {
    if (head_) { return head_->val; }
    else { return -1; }
  }

  void add(int value) {
    count_[value]++;
    if (count_[value] == 2) {
      if (head_->val == value) {
        ListNode* node = head_->next;
        delete head_;
        head_ = node;
      } else {
        ListNode* prev = head_;
        ListNode* node = head_->next;
        while (node->val != value) {
          prev = node;
          node = node->next;
        }
        if (node == tail_) {
          prev->next = nullptr;
          tail_ = prev;
        } else {
          prev->next = node->next;
        }
        delete node;
      }
      if (--num_nodes_ == 0) {
        head_ = nullptr;
        tail_ = nullptr;
      }
    } else if (count_[value] == 1) {
      ListNode* node = new ListNode(value);
      if (!head_ && !tail_) {
        head_ = node;
        tail_ = node;
      } else {
        tail_->next = node;
        tail_ = node;
      }
      num_nodes_++;
    }
  }

 private:
  unordered_map<int, int> count_;
  size_t num_nodes_;
  ListNode* head_;
  ListNode* tail_;
};

int main() {
  vector<int> nums;

  nums = {2,3,5};
  FirstUnique* obj1 = new FirstUnique(nums);
  EXPECT_EQ(2, obj1->showFirstUnique());
  obj1->add(5);            // the queue is now [2,3,5,5]
  EXPECT_EQ(2, obj1->showFirstUnique());
  obj1->add(2);            // the queue is now [2,3,5,5,2]
  EXPECT_EQ(3, obj1->showFirstUnique());
  obj1->add(3);            // the queue is now [2,3,5,5,2,3]
  EXPECT_EQ(-1, obj1->showFirstUnique());
  obj1->add(3);            // the queue is now [2,3,5,5,2,3,3]
  EXPECT_EQ(-1, obj1->showFirstUnique());
  delete obj1;

  nums = {7,7,7,7,7,7};
  FirstUnique* obj2 = new FirstUnique(nums);
  EXPECT_EQ(-1, obj2->showFirstUnique());
  obj2->add(7);            // the queue is now [7,7,7,7,7,7,7]
  obj2->add(3);            // the queue is now [7,7,7,7,7,7,7,3]
  obj2->add(3);            // the queue is now [7,7,7,7,7,7,7,3,3]
  obj2->add(7);            // the queue is now [7,7,7,7,7,7,7,3,3,7]
  obj2->add(17);           // the queue is now [7,7,7,7,7,7,7,3,3,7,17]
  EXPECT_EQ(17, obj2->showFirstUnique());
  delete obj2;

  nums = {809};
  FirstUnique* obj3 = new FirstUnique(nums);
  EXPECT_EQ(809, obj3->showFirstUnique());
  obj3->add(809);          // the queue is now [809,809]
  EXPECT_EQ(-1, obj3->showFirstUnique());
  obj3->add(808);
  EXPECT_EQ(808, obj3->showFirstUnique());
  delete obj3;

  nums = {70,80,434,460,432,473,165,251,941,21,867,311,973,739,723,309,254,738,450,531,258,72,174,331,761,211,413,302,752,552,28,693,879,878,703,907,676,653,584,430,21,486,738,975,564,945,529,643,83,103,183,915,180,381,505,322,317,435,583,472,714,114,761,623,340,916,2,570,419,826,965,461,85,460,260,80,659,900,993,72,732,643,85,261,295,609,569,835,684,496,729,220,724,721,566,885,584,256,581,828,184,194,990,861,966,309,552,766,601,706,162,108,143,755,809,84,913,306,802,532,223,434,869,266,37,283,966,179,506,284,591,541,902,823,309,897,143,661,256,143,839,924,352,606,732,638,348,331,265,265,601,731,791,72};
  FirstUnique* obj4 = new FirstUnique(nums);
  delete obj4;
}
