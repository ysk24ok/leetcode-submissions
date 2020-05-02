#include <string>
#include <unordered_set>
#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

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
  ExpectEqual(3, sol.numJewelsInStones(J, S));

  J = "z", S = "ZZ";
  ExpectEqual(0, sol.numJewelsInStones(J, S));
}
