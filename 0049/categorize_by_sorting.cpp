#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> group;
    for (auto&& str : strs) {
      string s = str;
      sort(s.begin(), s.end());
      group[s].push_back(str);
    }
    vector<vector<string>> values;
    values.reserve(group.size());
    for (auto&& pair: group) {
      values.push_back(pair.second);
    }
    return values;
  }
};

void Print(vector<vector<string>> groups) {
  for (auto&& group: groups) {
    copy(group.begin(), group.end(), ostream_iterator<string>(cout, ","));
    cout << endl;
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<vector<string>> got;
  vector<string> d;

  d = {"eat", "tea", "tan", "ate", "nat", "bat"};
  got = sol.groupAnagrams(d);
  Print(got);

  d = {"", "b", ""};
  got = sol.groupAnagrams(d);
  Print(got);

  d = {"tea", "and", "ace", "ad", "eat", "dans"};
  got = sol.groupAnagrams(d);
  Print(got);
}
