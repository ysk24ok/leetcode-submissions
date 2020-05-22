#include <cstdlib>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

auto compare = [](pair<char, int> left, pair<char, int> right) {
  return left.second < right.second;
};

class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<int, int> map;
    for (const auto& c : s) { map[c]++; }
    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(compare)> pq(compare);
    for (const auto& pair : map) { pq.push(pair); }
    string ret;
    while (!pq.empty()) {
      pair<char, int> p = pq.top();
      pq.pop();
      for (int i = 0; i < p.second; ++i) {
        ret += p.first;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string s, got;

  s = "tree";
  got = sol.frequencySort(s);
  EXPECT_TRUE(got == "eetr" || got == "eert");

  s = "cccaaa";
  got = sol.frequencySort(s);
  EXPECT_TRUE(got == "cccaaa" || got == "aaaccc");

  s = "Aabb";
  got = sol.frequencySort(s);
  EXPECT_TRUE(got == "bbAa" || got == "bbaA");

  exit(EXIT_SUCCESS);
}
