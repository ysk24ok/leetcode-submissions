#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> shortestToChar(string s, char c) {
    queue<pair<size_t, int>> q;
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] == c) {
        q.push({i, 0});
      }
    }
    vector<int> ret(s.size(), numeric_limits<int>::max());
    while (!q.empty()) {
      size_t idx = q.front().first;
      int dist = q.front().second;
      q.pop();
      if (dist < ret[idx]) {
        ret[idx] = dist;
        if (idx > 0) { q.push({idx - 1, dist + 1}); }
        if (idx < s.size() - 1) { q.push({idx + 1, dist + 1}); }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string s;
  char c;
  vector<int> expected;

  s = "loveleetcode", c = 'e', expected = {3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0};
  EXPECT_EQ(expected, sol.shortestToChar(s, c));

  s = "aaab", c = 'b', expected = {3, 2, 1, 0};
  EXPECT_EQ(expected, sol.shortestToChar(s, c));

  exit(EXIT_SUCCESS);
}
