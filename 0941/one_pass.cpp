#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  bool validMountainArray(vector<int>& arr) {
    if (arr.size() < 3) { return false; }
    int prev = arr[0];
    if (arr[0] >= arr[1]) { return false; }
    bool is_increasing = true;
    for (size_t i = 1; i < arr.size(); ++i) {
      const int& curr = arr[i];
      if (curr > prev && !is_increasing) {
        return false;
      } else if (curr < prev && is_increasing) {
        is_increasing = false;
      } else if (curr == prev) {
        return false;
      }
      prev = curr;
    }
    return !is_increasing;
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
