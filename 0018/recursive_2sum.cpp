#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ret;
    if (nums.size() < 4) {
      return ret;
    }
    sort(nums.begin(), nums.end());
    vector<int> result;
    NSum(ret, nums, target, 0, 4, result);
    return ret;
  }

  void NSum(vector<vector<int>>& ret, const vector<int>& nums, int target, size_t start, int N, vector<int>& result) {
    if (N == 2) {
      twoSum(ret, nums, target, start, result);
    } else {
      for (size_t i = start; i < nums.size()-N+1; i++) {
        if (i == start || (i > start && nums[i-1] != nums[i])) {
          int new_target = target - nums[i];
          vector<int> new_result = result;
          new_result.push_back(nums[i]);
          NSum(ret, nums, new_target, i+1, N-1, new_result);
        }
      }
    }
  }

  void twoSum(vector<vector<int>>& ret, const vector<int>& nums, int target, size_t start, vector<int>& result) {
    size_t left = start, right = nums.size() - 1;
    while (left < right) {
      int sum = nums[left] + nums[right];
      if (sum < target) {
        left++;
      } else if (sum > target) {
        right--;
      } else {  // sum == target
        vector<int> new_result = result;
        new_result.push_back(nums[left]);
        new_result.push_back(nums[right]);
        ret.push_back(new_result);
        left++;
        right--;
        // exclude duplicate
        while ((left < right) && (nums[left-1] == nums[left])) left++;
        while ((left < right) && (nums[right] == nums[right+1])) right--;
      }
    }
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

  nums = {0, 0, 0, 0};
  target = 0;
  got = sol.fourSum(nums, target);
  print_vector(got);

  nums = {-3, -2, -1, 0, 0, 1, 2, 3};
  target = 0;
  got = sol.fourSum(nums, target);
  print_vector(got);
}
