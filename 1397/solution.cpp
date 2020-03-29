#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

static constexpr int base_char_idx = static_cast<int>('a');

class Solution {
 public:
  int findGoodStrings(int n, string s1, string s2, string evil) {
    long ret = 0;
    long mod = 10e9 + 7;
    int size = s1.size();
    while (s1 != s2) {
      if (!contains(s1, evil)) ret++;
      update_digit(s1, size - 1);
    }
    if (!contains(s1, evil)) ret++;
    return ret % mod;
  }

  bool contains(const string& str, const string& substr) {
    return str.find(substr) != string::npos;
  }

  /*
  void update(string& str) {
    if (static_cast<int>(str[0]) - base_char_idx < 26) {
      str[0] = static_cast<char>(str[0] + 1);
    } else {
      str[0] = static_cast<char>(base_char_idx);
      update_digit(str, 1);
    }
  }
  */

  void update_digit(string& str, int i) {
    if (i < 0) return;
    str[i] = static_cast<char>(str[i] + 1);
    if (static_cast<int>(str[i]) - base_char_idx == 26) {
      str[i] = 'a';
      update_digit(str, i-1);
    }
  }
};

int main() {
  Solution sol;
  int n;
  string s1, s2, evil;

  n = 2, s1 = "aa", s2 = "da", evil = "b";
  assert(sol.findGoodStrings(n, s1, s2, evil) == 51);

  n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet";
  assert(sol.findGoodStrings(n, s1, s2, evil) == 0);

  n = 2, s1 = "gx", s2 = "gz", evil = "x";
  assert(sol.findGoodStrings(n, s1, s2, evil) == 2);
}
