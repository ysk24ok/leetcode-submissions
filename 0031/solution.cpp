#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() == 1) return;
    int last_idx = -1;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] < nums[i+1]) {
        last_idx = i;
      }
    }
    if (last_idx == (nums.size() - 1) - 1) {
      swap(nums, last_idx, last_idx + 1);
    } else if (last_idx == -1) {
      reverse(nums, 0);
    } else {
      // 2,1,5,4,3 -> 2,3,1,4,5
      // 2,3,5,4,1 -> 2,4,1,3,5
      // 1,5,1 -> 5,1,1
      int idx_to_swap = last_idx + 1;
      for (int i = last_idx + 1; i < nums.size(); i++) {
        if (nums[last_idx] >= nums[i]) break;
        idx_to_swap = i;
      }
      // first, swap 3 and 4
      // 2,3,5,4,1 -> 2,4,5,3,1
      swap(nums, last_idx, idx_to_swap);
      reverse(nums, last_idx + 1);
    }
  }

  void swap(vector<int>& nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }

  void reverse(vector<int>&nums, int i) {
    int start_idx = i;
    int end_idx = nums.size() - 1;
    while (start_idx < end_idx) {
      swap(nums, start_idx, end_idx);
      start_idx++;
      end_idx--;
    }
  }
};

int main() {
  Solution sol;
  vector<int> d;

  /*
  d = {1};
  sol.nextPermutation(d);
  assert(d[0] == 1);
  d = {1, 2};
  sol.nextPermutation(d);
  assert(d[0] == 2 and d[1] == 1);
  d = {1, 2, 3};
  sol.nextPermutation(d);
  assert(d[0] == 1 and d[1] == 3 and d[2] == 2);
  d = {1, 3, 2};
  sol.nextPermutation(d);
  assert(d[0] == 2 and d[1] == 1 and d[2] == 3);
  d = {2, 1, 3};
  sol.nextPermutation(d);
  assert(d[0] == 2 and d[1] == 3 and d[2] == 1);
  */
  d = {2, 3, 1};
  sol.nextPermutation(d);
  assert(d[0] == 3 and d[1] == 1 and d[2] == 2);
  d = {3, 1, 2};
  sol.nextPermutation(d);
  assert(d[0] == 3 and d[1] == 2 and d[2] == 1);
  d = {3, 2, 1};
  sol.nextPermutation(d);
  assert(d[0] == 1 and d[1] == 2 and d[2] == 3);
  d = {1, 1, 5};
  sol.nextPermutation(d);
  assert(d[0] == 1 and d[1] == 5 and d[2] == 1);
  d = {1, 5, 1};
  sol.nextPermutation(d);
  cout << d[0] << d[1] << d[2] << endl;
  assert(d[0] == 5 and d[1] == 1 and d[2] == 1);
  d = {5, 1, 1};
  sol.nextPermutation(d);
  assert(d[0] == 1 and d[1] == 1 and d[2] == 5);
  d = {1, 2, 3, 4};
  sol.nextPermutation(d);
  assert(d[0] == 1 and d[1] == 2 and d[2] == 4 and d[3] == 3);
  d = {1, 2, 4, 3};
  sol.nextPermutation(d);
  assert(d[0] == 1 and d[1] == 3 and d[2] == 2 and d[3] == 4);
  d = {4, 3, 2, 1};
  sol.nextPermutation(d);
  assert(d[0] == 1 and d[1] == 2 and d[2] == 3 and d[3] == 4);
}
