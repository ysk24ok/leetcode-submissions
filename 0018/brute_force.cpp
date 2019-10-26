#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ret;
    size_t size = nums.size();
    if (size < 4) {
      return ret;
    }
    for (int i = 0; i < size - 3; i++) {
      int a = nums[i];
      for (int j = i+1; j < size - 2; j++) {
        for (int k = j+1; k < size - 1; k++) {
          for (int l = k+1; l < size; l++) {
            if (nums[i] + nums[j] + nums[k] + nums[l] != target) {
              continue;
            }
            vector<int> v = {nums[i], nums[j], nums[k], nums[l]};
            sort(v.begin(), v.end());
            checkAndPush(ret, v);
          }
        }
      }
    }
    return ret;
  }

  void checkAndPush(vector<vector<int>>& ret, vector<int>& v) {
    for (auto& r : ret) {
      if (r == v) {
        return;
      }
    }
    ret.push_back(v);
  }
};

void print_vector(const vector<vector<int>>& v) {
  for (auto& vv : v) {
    for (auto& vvv : vv) {
      cout << vvv << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<vector<int>> got;
  vector<int> nums;
  int target;

  nums = {1, 0, -1, 0, -2, 2};
  target = 0;
  got = sol.fourSum(nums, target);
  print_vector(got);

  nums = {};
  target = 0;
  got = sol.fourSum(nums, target);
  assert(got.size() == 0);

  nums = {0, 1, 2, 3};
  target = 0;
  got = sol.fourSum(nums, target);
  assert(got.size() == 0);
}
