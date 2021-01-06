#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    int count = 0;
    int kth_missing = 0;
    size_t idx = 0;
    int expected = 1;
    while (count < k) {
      if (idx < arr.size() && arr[idx] == expected) {
        idx++;
      } else {
        count++;
        kth_missing = expected;
      }
      expected++;
    }
    return kth_missing;
  }
};

int main() {
  Solution sol;
  vector<int> arr;
  int k, expected;

  arr = {2, 3, 4, 7, 11}, k = 5, expected = 9;
  EXPECT_EQ(expected, sol.findKthPositive(arr, k));

  arr = {1, 2, 3, 4}, k = 2, expected = 6;
  EXPECT_EQ(expected, sol.findKthPositive(arr, k));

  exit(EXIT_SUCCESS);
}
