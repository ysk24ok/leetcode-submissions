#include <unordered_map>
#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int findJudge(int N, vector<vector<int>>& trust) {
    vector<bool> candidates(N+1, true);
    unordered_map<int, int> trusted;
    for (const auto& t : trust) {
      candidates[t[0]] = false;
      trusted[t[1]]++;
    }
    int ret = -1;
    for (size_t i = 1; i <= N; ++i) {
      if (candidates[i] && trusted[i] == N - 1) {
        ret = i;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int N;
  vector<vector<int>> trust;

  N = 2;
  trust = {{1,2}};
  ExpectEqual(2, sol.findJudge(N, trust));

  N = 3;
  trust = {{1,3},{2,3}};
  ExpectEqual(3, sol.findJudge(N, trust));

  N = 3;
  trust = {{1,3},{2,3},{3,1}};
  ExpectEqual(-1, sol.findJudge(N, trust));

  N = 3;
  trust = {{1,2},{2,3}};
  ExpectEqual(-1, sol.findJudge(N, trust));

  N = 4;
  trust = {{1,3},{1,4},{2,3},{2,4},{4,3}};
  ExpectEqual(3, sol.findJudge(N, trust));
}
