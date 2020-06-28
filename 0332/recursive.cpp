#include <algorithm>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, vector<string>> map;
    for (const auto& ticket : tickets) {
      map[ticket[0]].push_back(ticket[1]);
    }
    for (auto& p : map) {
      sort(p.second.begin(), p.second.end());
    }
    vector<string> ret;
    find(ret, map, "JFK");
    return ret;
  }

  void find(vector<string>& ret, unordered_map<string, vector<string>>& map, const string& airport) {
    while (map.find(airport) != map.end() && map[airport].size() > 0) {
      const string next_airport = map[airport][0];
      map[airport].erase(map[airport].begin());
      find(ret, map, next_airport);
    }
    ret.insert(ret.begin(), airport);
  }
};

int main() {
  Solution sol;
  vector<vector<string>> tickets;
  vector<string> expected;

  tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
  expected = {"JFK", "MUC", "LHR", "SFO", "SJC"};
  EXPECT_EQ(expected, sol.findItinerary(tickets));

  tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
  expected = {"JFK","ATL","JFK","SFO","ATL","SFO"};
  EXPECT_EQ(expected, sol.findItinerary(tickets));

  tickets = {{"JFK", "MUC"}, {"JFK", "SJC"}, {"MUC", "JFK"}, {"SJC", "JFK"}};
  expected = {"JFK", "MUC", "JFK", "SJC", "JFK"};
  EXPECT_EQ(expected, sol.findItinerary(tickets));

  // "KUL" does not exist in map
  tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
  expected = {"JFK","NRT","JFK","KUL"};
  EXPECT_EQ(expected, sol.findItinerary(tickets));

  // "KUL" exist in map
  tickets = {{"JFK","KUL"},{"KUL","JFK"},{"JFK","KUL"},{"KUL","JFK"}};
  expected = {"JFK","KUL","JFK","KUL","JFK"};
  EXPECT_EQ(expected, sol.findItinerary(tickets));

  exit(EXIT_SUCCESS);
}
