#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canReorderDoubled(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    unordered_map<int, size_t> counts;
    for (const int& val : arr) {
      if (val > 0 && val % 2 == 1) {
        counts[val]++;
        continue;
      }
      int partner = val > 0 ? val / 2 : val * 2;
      if (counts.find(partner) != counts.end() && counts[partner] > 0) {
        counts[partner]--;
      } else {
        counts[val]++;
      }
    }
    for (const pair<int, size_t>& p: counts) {
      if (p.second != 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<int> arr;
  bool expected;

  arr = {3, 1, 3, 6}, expected = false;
  EXPECT_EQ(expected, sol.canReorderDoubled(arr));

  arr = {2, 1, 2, 6}, expected = false;
  EXPECT_EQ(expected, sol.canReorderDoubled(arr));

  arr = {4, -2, 2, -4}, expected = true;
  EXPECT_EQ(expected, sol.canReorderDoubled(arr));

  arr = {1, 2, 4, 16, 8, 4}, expected = false;
  EXPECT_EQ(expected, sol.canReorderDoubled(arr));

  arr = {4, 1, 2, 8}, expected = true;
  EXPECT_EQ(expected, sol.canReorderDoubled(arr));

  exit(EXIT_SUCCESS);
}
