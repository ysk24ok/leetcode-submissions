#include <cstdlib>
#include <random>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class RandomizedSet {
 public:
  /** Initialize your data structure here. */
  RandomizedSet() : map_(), engine_(random_device()()) {}

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if (map_.find(val) != map_.end()) { return false; }
    return map_[val] = true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    if (map_.find(val) == map_.end()) { return false; }
    map_.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    int num = engine_() % map_.size();
    auto it = map_.cbegin();
    advance(it, num);
    return it->first;
  }

 private:
  mt19937 engine_;
  unordered_map<int, bool> map_;
};

int main() {
  RandomizedSet random_set;

  EXPECT_TRUE(random_set.insert(1));
  EXPECT_FALSE(random_set.remove(2));
  EXPECT_TRUE(random_set.insert(2));
  int val = random_set.getRandom();
  EXPECT_TRUE(val == 1 || val == 2);

  exit(EXIT_SUCCESS);
}
