#include <gtest/gtest.h>

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int numJewelsInStones(string J, string S) {
    unordered_set<char> set;
    for (const auto& j : J) {
      set.insert(j);
    }
    int ret = 0;
    for (const auto& s : S) {
      if (set.count(s) == 1) { ret++; }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string J, S;

  J = "aA", S = "aAAbbbb";
  EXPECT_EQ(3, sol.numJewelsInStones(J, S));

  J = "z", S = "ZZ";
  EXPECT_EQ(0, sol.numJewelsInStones(J, S));
}
