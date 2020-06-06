#include <cstdlib>
#include <numeric>
#include <queue>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    auto compare = [](const vector<int>& left, const vector<int>& right) {
      return left[0] > right[0];
    };
    const size_t m = people.size();
    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> q(compare);
    for (const auto& person : people) { q.push(person); }
    vector<vector<int>> ret(m, vector<int>(2, numeric_limits<int>::max()));
    while (!q.empty()) {
      vector<int> person = q.top();
      q.pop();
      int num = 0;
      for (size_t i = 0; i < m; ++i) {
        if (ret[i][0] == numeric_limits<int>::max() && num == person[1]) {
          ret[i][0] = person[0];
          ret[i][1] = person[1];
          break;
        }
        if (ret[i][0] >= person[0]) {
          num++;
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> people, expected;

  people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
  expected = {{5,0},{7,0},{5,2},{6,1},{4,4},{7,1}};
  EXPECT_EQ(expected, sol.reconstructQueue(people));

  exit(EXIT_SUCCESS);
}
