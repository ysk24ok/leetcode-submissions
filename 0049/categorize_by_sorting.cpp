#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, size_t> group;
    vector<vector<string>> ret;
    for (const auto& str : strs) {
      string s = str;
      sort(s.begin(), s.end());
      if (group.find(s) != group.end()) {
        ret[group[s]].push_back(str);
      } else {
        ret.push_back({str});
        group[s] = ret.size() - 1;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<string>> expected;
  vector<string> d;

  d = {"eat", "tea", "tan", "ate", "nat", "bat"};
  expected = {{"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}};
  EXPECT_EQ(expected, sol.groupAnagrams(d));

  d = {"", "b", ""};
  expected = {{"", ""}, {"b"}};
  EXPECT_EQ(expected, sol.groupAnagrams(d));

  d = {"tea", "and", "ace", "ad", "eat", "dans"};
  expected = {{"tea", "eat"}, {"and"}, {"ace"}, {"ad"}, {"dans"}};
  EXPECT_EQ(expected, sol.groupAnagrams(d));
}
