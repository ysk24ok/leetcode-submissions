#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  char findTheDifference(string s, string t) {
    if (s.size() < t.size()) {
      return findChar(t, s);
    } else {
      return findChar(s, t);
    }
  }

  char findChar(const string& longer, const string& shorter) {
    unordered_map<char, int> map;
    for (const char& c : shorter) {
      map[c] += 1;
    }
    char ret;
    for (const char& c : longer) {
      if (map.find(c) == map.end() or map[c] == 0) {
        ret = c;
        break;
      }
      map[c]--;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string s, t;
  char expected;

  s = "abcd", t = "abcde";
  expected = 'e';
  EXPECT_EQ(expected, sol.findTheDifference(s, t));

  s = "abcd", t = "cebad";
  expected = 'e';
  EXPECT_EQ(expected, sol.findTheDifference(s, t));

  s = "abcd", t = "bacad";
  expected = 'a';
  EXPECT_EQ(expected, sol.findTheDifference(s, t));

  exit(EXIT_SUCCESS);
}
