#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int left = 0, right = citations.size()-1, len = citations.size();
    while (left <= right) {
      int mid = (right - left) / 2 + left;
      // `num` is the number of values greater than or equal to `citations[mid]`
      int num = len - mid;
      if (num > citations[mid]) {
        left = mid + 1;
      } else if (num < citations[mid]) {
        right = mid - 1;
      } else {
        return citations[mid];
      }
    }
    // TODO: why?
    return len - (right+1);
  }
};

int main() {
  Solution sol;
  vector<int> citations;
  int expected;

  citations = {0,1,3,5,6};
  expected = 3;
  EXPECT_EQ(expected, sol.hIndex(citations));

  citations = {0,1,2,2,2,2,2};
  expected = 2;
  EXPECT_EQ(expected, sol.hIndex(citations));

  citations = {0,1,2,4,5,5,5};
  expected = 4;
  EXPECT_EQ(expected, sol.hIndex(citations));

  citations = {2,5,5,5,5,5};
  expected = 5;
  EXPECT_EQ(expected, sol.hIndex(citations));

  citations = {0};
  expected = 0;
  EXPECT_EQ(expected, sol.hIndex(citations));

  citations = {1};
  expected = 1;
  EXPECT_EQ(expected, sol.hIndex(citations));

  citations = {2};
  expected = 1;
  EXPECT_EQ(expected, sol.hIndex(citations));

  exit(EXIT_SUCCESS);
}
