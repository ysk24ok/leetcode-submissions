#include <algorithm>
#include <string>
#include <unordered_map>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int firstUniqChar(string s) {
    unordered_map<char, size_t> count;
    unordered_map<char, size_t> index;
    for (size_t i = 0, m = s.size(); i < m; ++i) {
      const char& c = s[i];
      count[c]++;
      index[c] = i;
    }
    size_t ret = numeric_limits<size_t>::max();
    for (const auto& pair : count) {
      if (pair.second > 1) { continue; }
      ret = min(ret, index[pair.first]);
    }
    return ret != numeric_limits<size_t>::max() ? static_cast<int>(ret) : -1;
  }
};

int main() {
  Solution sol;
  ExpectEqual(0, sol.firstUniqChar("leetcode"));
  ExpectEqual(2, sol.firstUniqChar("loveleetcode"));
  ExpectEqual(0, sol.firstUniqChar("c"));
  ExpectEqual(-1, sol.firstUniqChar(""));
  ExpectEqual(-1, sol.firstUniqChar("aabb"));
}
