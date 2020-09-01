#include "gtest/gtest.h"

#include <unordered_map>

using namespace std;

class LRUCache {
 public:
  LRUCache(int capacity) : capacity_(capacity), timestep_(0), map_() {}

  int get(int key) {
    auto iter = map_.find(key);
    if (iter == map_.end()) { return -1; }
    oldness_[key] = timestep_;
    timestep_++;
    return iter->second;
  }

  void put(int key, int value) {
    // evict
    if (map_.find(key) == map_.end() && map_.size() == capacity_) {
      int oldest = numeric_limits<int>::max();
      pair<int, int> least_used_pair;
      for (const auto& p : oldness_) {
        if (p.second < oldest) {
          least_used_pair = p;
          oldest = p.second;
        }
      }
      map_.erase(least_used_pair.first);
      oldness_.erase(least_used_pair.first);
    }
    map_[key] = value;
    oldness_[key] = timestep_;
    timestep_++;
  }

 private:
  int capacity_;
  int timestep_;
  unordered_map<int, int> map_;
  unordered_map<int, int> oldness_;
};

int main() {
  int capacity = 2;
  LRUCache cache(capacity);
  cache.put(1, 1);
  cache.put(2, 2);
  EXPECT_EQ(1, cache.get(1));
  cache.put(3, 3);    // evicts key 2
  EXPECT_EQ(-1, cache.get(2));
  cache.put(4, 4);    // evicts key 1
  EXPECT_EQ(-1, cache.get(1));
  EXPECT_EQ(3, cache.get(3));
  EXPECT_EQ(4, cache.get(4));
}
