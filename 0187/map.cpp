#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ret;
    if (s.size() < 10) return ret;
    string substr(10, 'A');
    unordered_map<string, int> map;
    for (int i = 0; i < s.size()-(10-1); i++) {
      substr = s.substr(i, 10);
      if (map.find(substr) == map.end()) {
        map[substr] = 0;
      }
      map[substr]++;
    }
    for (auto& pair : map) {
      assert(pair.first.size() == 10);
      if (pair.second > 1) {
        ret.push_back(pair.first);
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string s;
  vector<string> got;
  vector<string> expected;

  s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  expected = {"AAAAACCCCC", "CCCCCAAAAA"};
  got = sol.findRepeatedDnaSequences(s);
  sort(got.begin(), got.end());
  sort(expected.begin(), expected.end());
  assert(got == expected);

  s = "";
  got = sol.findRepeatedDnaSequences(s);
  assert(got.size() == 0);

  s = "AAAAACCCCC";
  got = sol.findRepeatedDnaSequences(s);
  assert(got.size() == 0);
}
