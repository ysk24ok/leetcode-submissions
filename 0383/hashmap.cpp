#include <string>
#include <unordered_map>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> map;
    for (const auto& c : magazine) { map[c]++; }
    bool ret = true;
    for (const auto& c : ransomNote) {
      if (map.find(c) == map.end() || --map[c] < 0) {
        ret = false;
        break;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  ExpectEqual(false, sol.canConstruct("a", "b"));
  ExpectEqual(false, sol.canConstruct("aa", "ab"));
  ExpectEqual(true, sol.canConstruct("aa", "aab"));
}
