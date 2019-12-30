#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq(
      nums.begin(), nums.end());
    while (pq.size() > k) {
      pq.pop();
    }
    return pq.top();
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {3,2,1,5,6,4};
  assert(sol.findKthLargest(nums, 2) == 5);

  nums = {3,2,3,1,2,4,5,5,6};
  assert(sol.findKthLargest(nums, 4) == 4);
}
