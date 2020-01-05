#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> map, map2;
    for (size_t i = 0; i < s.size(); ++i) {
      char s1 = s[i], s2 = t[i];
      if (map.find(s1) == map.end()) {
        if (map2.find(s2) == map.end()) {
          map[s1] = s2;
          map2[s2] = s1;
        } else {
          if (map2[s2] != s1) return false;
        }
      }
      if (map[s1] != s2) return false;
    }
    return true;
  }
};

int main() {
  Solution sol;
  string s, t;

  s = "egg";
  t = "add";
  assert(sol.isIsomorphic(s, t));

  s = "foo";
  t = "bar";
  assert(!sol.isIsomorphic(s, t));

  s = "ab";
  t = "aa";
  assert(!sol.isIsomorphic(s, t));

  s = "ab";
  t = "ca";
  assert(sol.isIsomorphic(s, t));
}
