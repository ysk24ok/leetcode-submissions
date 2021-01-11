#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> nums(m+n);
    size_t idx = 0, idx1 = 0, idx2 = 0;
    while (idx1 < m && idx2 < n) {
      if (nums1[idx1] <= nums2[idx2]) {
        nums[idx++] = nums1[idx1++];
      } else {
        nums[idx++] = nums2[idx2++];
      }
    }
    while (idx1 < m) {
      nums[idx++] = nums1[idx1++];
    }
    while (idx2 < n) {
      nums[idx++] = nums2[idx2++];
    }
    nums1.swap(nums);
  }
};

int main() {
  Solution sol;
  vector<int> nums1, nums2, expected;
  int m, n;

  nums1 = {1, 2, 3, 0, 0, 0}, m = 3, nums2 = {2, 5, 6}, n = 3;
  expected = {1, 2, 2, 3, 5, 6};
  sol.merge(nums1, m, nums2, n);
  EXPECT_EQ(expected, nums1);

  nums1 = {1}, m = 1, nums2 = {}, n = 0;
  expected = {1};
  sol.merge(nums1, m, nums2, n);
  EXPECT_EQ(expected, nums1);

  exit(EXIT_SUCCESS);
}
