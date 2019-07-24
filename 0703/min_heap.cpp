#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void print_vec(const vector<int>& vec) {
  for (auto& v : vec) {
    cout << v << " ";
  }
  cout << endl;
}

class KthLargest {
 public:
  KthLargest(int k, vector<int>& nums) : k_(k), pq_(nums.begin(), nums.end()) {
    while (pq_.size() > k) pq_.pop();
  }

  int add(int val) {
    pq_.push(val);
    if (pq_.size() > k_) pq_.pop();
    return pq_.top();
  }

 private:
  int k_;
  priority_queue<int, vector<int>, greater<int>> pq_;
};

int main() {
  /**
   * Your KthLargest object will be instantiated and called as such:
   * KthLargest* obj = new KthLargest(k, nums);
   * int param_1 = obj->add(val);
   */
  vector<int> v;
  KthLargest* obj;
  v = {4, 5, 8, 2};
  obj = new KthLargest(3, v);
  assert(obj->add(3) == 4);
  assert(obj->add(5) == 5);
  assert(obj->add(10) == 5);
  assert(obj->add(9) == 8);
  assert(obj->add(4) == 8);
  delete obj;

  v = {};
  obj = new KthLargest(1, v);
  assert(obj->add(5) == 5);
  assert(obj->add(8) == 8);
  assert(obj->add(3) == 8);
  delete obj;
}
