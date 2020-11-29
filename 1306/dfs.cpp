#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canReach(vector<int>& arr, int start) {
    vector<bool> visited(arr.size(), false);
    return canReach(arr, start, visited);
  }

  bool canReach(const vector<int>& arr, int start, vector<bool>& visited) {
    if (start < 0 || start > arr.size()) { return false; }
    if (arr[start] == 0) { return true; }
    if (visited[start]) { return false; }
    visited[start] = true;
    return canReach(arr, start - arr[start], visited) ||
           canReach(arr, start + arr[start], visited);
  }
};

int main() {
  Solution sol;
  vector<int> arr;
  int start;

  arr = {4, 2, 3, 0, 3, 1, 2},  start = 5;
  EXPECT_TRUE(sol.canReach(arr, start));

  arr = {4, 2, 3, 0, 3, 1, 2},  start = 0;
  EXPECT_TRUE(sol.canReach(arr, start));

  arr = {3, 0, 2, 1, 2},  start = 2;
  EXPECT_FALSE(sol.canReach(arr, start));

  exit(EXIT_SUCCESS);
}
