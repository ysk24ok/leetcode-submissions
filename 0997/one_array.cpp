#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
 public:
  int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> vertices(N+1);
    for (const auto& p : trust) {
      vertices[p[0]]--;
      vertices[p[1]]++;
    }
    for (int i = 1; i <= N; ++i) {
      if (vertices[i] == N - 1) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  int N;
  vector<vector<int>> trust;

  N = 2;
  trust = {{1,2}};
  EXPECT_EQ(2, sol.findJudge(N, trust));

  N = 3;
  trust = {{1,3},{2,3}};
  EXPECT_EQ(3, sol.findJudge(N, trust));

  N = 3;
  trust = {{1,3},{2,3},{3,1}};
  EXPECT_EQ(-1, sol.findJudge(N, trust));

  N = 3;
  trust = {{1,2},{2,3}};
  EXPECT_EQ(-1, sol.findJudge(N, trust));

  N = 4;
  trust = {{1,3},{1,4},{2,3},{2,4},{4,3}};
  EXPECT_EQ(3, sol.findJudge(N, trust));
}
