#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int ret = 1;
    vector<int> lengthIS(nums.size(), 1);
    for (int idx = 1; idx < nums.size(); idx++) {
      for (int subidx = 0; subidx < idx; subidx++) {
        if (nums[idx] <= nums[subidx])
          continue;
        int new_length = lengthIS[subidx] + 1;
        if (new_length > lengthIS[idx])
          lengthIS[idx] = new_length;
      }
      if (lengthIS[idx] > ret)
        ret = lengthIS[idx];
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> d;

  d = {10, 9, 2, 5, 3, 7, 101, 18};
  assert(sol.lengthOfLIS(d) == 4);

  d = {};
  assert(sol.lengthOfLIS(d) == 0);

  d = {0};
  assert(sol.lengthOfLIS(d) == 1);

  d = {5, 4, 3, 2, 1};
  assert(sol.lengthOfLIS(d) == 1);

  d = {6, 7, 8, 9, 1, 1, 2, 3, 4, 5};
  assert(sol.lengthOfLIS(d) == 5);
}
