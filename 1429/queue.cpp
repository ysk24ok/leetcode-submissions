#include <gtest/gtest.h>

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class FirstUnique {
 public:
  FirstUnique(vector<int>& nums) : count_(), q_() {
    for (size_t i = 0; i < nums.size(); ++i) {
      add(nums[i]);
    }
  }

  int showFirstUnique() {
    while (!q_.empty() && count_[q_.front()] >= 2) {
      q_.pop();
    }
    if (!q_.empty()) { return q_.front(); }
    else { return -1; }
  }

  void add(int value) {
    q_.push(value);
    count_[value]++;
  }

 private:
  unordered_map<int, int> count_;
  queue<int> q_;
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
  delete obj3;
}
