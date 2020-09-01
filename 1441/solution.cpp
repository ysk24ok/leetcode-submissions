#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> ret;
    int ptr = 0;
    int i = 1;
    for (int i = 1; i <= n; ++i) {
      if (ptr >= target.size()) { break; }
      ret.push_back("Push");
      if (target[ptr] == i) {
        ++ptr;
      } else {
        ret.push_back("Pop");
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> target;
  int n;
  vector<string> got, expected;

  target = {1,3};
  expected = {"Push", "Push", "Pop", "Push"};
  n = 3;
  got = sol.buildArray(target, n);
  EXPECT_EQ(expected, got);

  target = {1,2,3};
  expected = {"Push", "Push", "Push"};
  n = 3;
  got = sol.buildArray(target, n);
  EXPECT_EQ(expected, got);

  target = {1,2};
  expected = {"Push", "Push"};
  n = 4;
  got = sol.buildArray(target, n);
  EXPECT_EQ(expected, got);

  target = {2,3,4};
  expected = {"Push", "Pop", "Push", "Push", "Push"};
  n = 4;
  got = sol.buildArray(target, n);
  EXPECT_EQ(expected, got);
}
