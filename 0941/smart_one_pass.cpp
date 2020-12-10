#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  bool validMountainArray(vector<int>& arr) {
    if (arr.size() < 3) { return false; }
    size_t idx = 0;
    while (idx + 1 < arr.size() && arr[idx] < arr[idx+1]) { ++idx; }
    if (idx == 0 || idx == arr.size() - 1) { return false; }
    while (idx + 1 < arr.size() && arr[idx] > arr[idx+1]) { ++idx; }
    return idx == arr.size() - 1;
  }
};

int main() {
  Solution sol;
  vector<int> arr;
  bool expected;

  arr = {2, 1};
  expected = false;
  EXPECT_EQ(expected, sol.validMountainArray(arr));

  arr = {3, 5, 5};
  expected = false;
  EXPECT_EQ(expected, sol.validMountainArray(arr));

  arr = {0, 3, 2, 1};
  expected = true;
  EXPECT_EQ(expected, sol.validMountainArray(arr));

  arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  expected = false;
  EXPECT_EQ(expected, sol.validMountainArray(arr));

  arr = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  expected = false;
  EXPECT_EQ(expected, sol.validMountainArray(arr));

  exit(EXIT_SUCCESS);
}
