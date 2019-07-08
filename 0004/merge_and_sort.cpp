#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    copy(nums2.begin(), nums2.end(), back_inserter(nums1));
    sort(nums1.begin(), nums1.end());
    int mid = nums1.size() / 2;
    if (nums1.size() % 2 == 0) {
      return (nums1[mid] + nums1[mid-1]) / 2.0;
    } else {
      return nums1[mid];
    }
  }
};

int main() {
  Solution sol;
  vector<int> v1;
  vector<int> v2;

  v1 = {1, 3};
  v2 = {2};
  assert(sol.findMedianSortedArrays(v1, v2) == 2.0);

  v1 = {1, 2};
  v2 = {3, 4};
  assert(sol.findMedianSortedArrays(v1, v2) == 2.5);

  v1 = {1, 3, 5, 7};
  v2 = {9, 11, 13};
  assert(sol.findMedianSortedArrays(v1, v2) == 7.0);

  v1 = {5, 9, 11};
  v2 = {1, 3, 7, 13};
  assert(sol.findMedianSortedArrays(v1, v2) == 7.0);
}
