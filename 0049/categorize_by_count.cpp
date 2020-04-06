#include <array>
#include <cassert>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for (const auto& str : strs) {
      map[convert(str)].push_back(str);
    }
    vector<vector<string>> ret;
    for (const auto& pair : map) {
      ret.push_back(pair.second);
    }
    return ret;
  }

  string convert(const string& str) {
    array<int, 26> count;
    count.fill(0);
    for (const auto& c : str) {
      count[static_cast<int>(c - 'a')]++;
    }
    ostringstream oss;
    for (const int& v : count) { oss << '#' << v; }
    return oss.str();
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
