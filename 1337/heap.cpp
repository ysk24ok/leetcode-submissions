#include <gtest/gtest.h>

#include <cstdlib>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    auto stronger = [] (const pair<size_t, int>& left, const pair<size_t, int>& right) {
      if (left.second != right.second) {
        return left.second > right.second;
      } else {
        return left.first > right.first;
      }
    };
    priority_queue<pair<size_t, int>, vector<pair<size_t, int>>, decltype(stronger)> queue(stronger);
    for (size_t i = 0; i< mat.size(); ++i) {
      queue.push({i, accumulate(mat[i].begin(), mat[i].end(), 0)});
    }
    vector<int> ret;
    while (k > 0) {
      ret.push_back(queue.top().first);
      queue.pop();
      k--;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> mat;
  int k;
  vector<int> expected;

  mat = {
    {1, 1, 0, 0, 0},
    {1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1}
  }, k = 3, expected = {2, 0, 3};
  EXPECT_EQ(expected, sol.kWeakestRows(mat, k));

  mat = {
    {1, 0, 0, 0},
    {1, 1, 1, 1},
    {1, 0, 0, 0},
    {1, 0, 0, 0},
  }, k = 2, expected = {0, 2};
  EXPECT_EQ(expected, sol.kWeakestRows(mat, k));

  exit(EXIT_SUCCESS);
}
