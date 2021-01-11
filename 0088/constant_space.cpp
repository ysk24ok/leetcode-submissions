#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int idx1 = m - 1, idx2 = n - 1, idx = m + n - 1;
    while (idx1 >= 0 && idx2 >= 0) {
      if (nums1[idx1] >= nums2[idx2]) {
        nums1[idx--] = nums1[idx1--];
      } else {
        nums1[idx--] = nums2[idx2--];
      }
    }
    while (idx2 >= 0) {
      nums1[idx--] = nums2[idx2--];
    }
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

  nums1 = {0}, m = 0, nums2 = {1}, n = 1;
  expected = {1};
  sol.merge(nums1, m, nums2, n);
  EXPECT_EQ(expected, nums1);

  exit(EXIT_SUCCESS);
}
