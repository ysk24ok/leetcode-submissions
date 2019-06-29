#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int start = 0;
    int mid = nums.size() / 2;
    int end = nums.size() - 1;
    int min = nums[0];
    while (start < end) {
      if (nums[start] < nums[end]) {
        min = nums[start];
        break;
      }
      mid = (end + start) / 2;
      if (nums[start] > nums[mid]) {
        min = nums[mid];
        end = mid;
        continue;
      }
      if (nums[mid] > nums[end]) {
        min = nums[end];
        start = mid + 1;
        continue;
      }
    }
    return min;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  nums = {1};
  assert(sol.findMin(nums) == 1);

  nums = {1, 2};
  assert(sol.findMin(nums) == 1);

  nums = {2, 1};
  assert(sol.findMin(nums) == 1);

  nums = {1, 2, 3, 4};
  assert(sol.findMin(nums) == 1);

  nums = {4, 1, 2, 3};
  assert(sol.findMin(nums) == 1);

  nums = {3, 4, 1, 2};
  assert(sol.findMin(nums) == 1);

  nums = {2, 3, 4, 1};
  assert(sol.findMin(nums) == 1);

  nums = {3, 4, 5, 1, 2};
  assert(sol.findMin(nums) == 1);

  nums = {4, 5, 6, 7, 0, 1, 2};
  assert(sol.findMin(nums) == 0);

  nums = {2, 3, 4, 5, 6, 7, 8, 9, 1};
  assert(sol.findMin(nums) == 1);
}
