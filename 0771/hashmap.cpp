#include <string>
#include <unordered_map>
#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int numJewelsInStones(string J, string S) {
    unordered_map<char, bool> map;
    for (const auto& j : J) {
      map[j] = true;
    }
    int ret = 0;
    for (const auto& s : S) {
      if (map.find(s) != map.end()) { ret++; }
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
