#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    int left = 0, right = nums.size()-1, mid;
    while (left <= right) {
      mid = (left + right) / 2;
      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target){
        left = mid + 1;
      } else return mid;
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {-1,0,3,5,9,12};
  assert(sol.search(nums, 9) == 4);

  nums = {-1,0,3,5,9,12};
  assert(sol.search(nums, 2) == -1);

  nums = {};
  assert(sol.search(nums, 1) == -1);

  nums = {1};
  assert(sol.search(nums, 1) == 0);

  nums = {-1,0,3,5,9,12,17};
  assert(sol.search(nums, 12) == 5);
}
