#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int N = 1000001;

class MyHashSet {
 public:
  /** Initialize your data structure here. */
  MyHashSet() {
    for (auto it = arr_.begin(); it != arr_.end(); it++) *it = 0;
  }

  void add(int key) {
    arr_[key] = 1;
  }

  void remove(int key) {
    arr_[key] = 0;
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    return arr_[key] == 1;
  }

 private:
  std::array<int, N> arr_;
};

int main() {
  MyHashSet* obj = new MyHashSet();
  obj->add(1);
  obj->add(2);
  assert(obj->contains(1));
  assert(!obj->contains(3));
  obj->add(2);
  assert(obj->contains(2));
  obj->remove(2);
  assert(!obj->contains(2));
  delete obj;
}
