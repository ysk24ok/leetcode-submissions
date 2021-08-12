#include <gtest/gtest.h>

#include <array>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr size_t N = 26;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, size_t> map;
    vector<vector<string>> ret;
    array<size_t, N> counts;
    for (const string& str : strs) {
      counts = {0};
      for (const char& c : str) {
        counts[static_cast<int>(c - 'a')]++;
      }
      string counts_as_str(counts.begin(), counts.end());
      if (map.find(counts_as_str) != map.end()) {
        ret[map[counts_as_str]].push_back(str);
      } else {
        ret.push_back({str});
        map[counts_as_str] = ret.size() - 1;
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
