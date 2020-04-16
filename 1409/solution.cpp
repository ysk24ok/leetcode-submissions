#include <cassert>
#include <iostream>
#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<int> processQueries(vector<int>& queries, int m) {
    vector<int> ret;
    vector<int> P(m);
    for (size_t i = 0; i < m; ++i) { P[i] = i + 1; }
    for (const auto& q : queries) {
      int pos = std::find(P.begin(), P.end(), q) - P.begin();
      ret.push_back(pos);
      P.erase(P.begin() + pos);
      P.insert(P.begin(), q);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> queries, got, expected;

  queries = {3,1,2,1};
  got = sol.processQueries(queries, 5);
  expected = {2,1,2,1};
  ExpectVectorEqual(expected, got);

  queries = {4,1,2,2};
  got = sol.processQueries(queries, 4);
  expected = {3,1,2,0};
  ExpectVectorEqual(expected, got);

  queries = {7,5,5,8,3};
  got = sol.processQueries(queries, 8);
  expected = {6,5,0,7,5};
  ExpectVectorEqual(expected, got);
}
