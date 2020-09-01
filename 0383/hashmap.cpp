#include <gtest/gtest.h>

#include <string>
#include <unordered_map>

using namespace std;

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
  EXPECT_EQ(false, sol.canConstruct("a", "b"));
  EXPECT_EQ(false, sol.canConstruct("aa", "ab"));
  EXPECT_EQ(true, sol.canConstruct("aa", "aab"));
}
