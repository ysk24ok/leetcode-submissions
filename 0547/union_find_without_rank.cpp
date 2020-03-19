#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    vector<int> parents(M.size());
    for (size_t i = 0; i < M.size(); i++) parents[i] = i;
    for (size_t i = 0; i < M.size(); i++) {
      for (size_t j = i + 1; j < M[i].size(); j++) {
        if (M[i][j] == 0) continue;
        if (belongToSameCircle(parents, i, j)) continue;
        // TODO: consider rank
        parents[findRoot(parents, j)] = findRoot(parents, i);
      }
    }
    unordered_set<int> ret = {};
    for (size_t i = 0; i < M.size(); i++) {
      findRoot(parents, i);
      ret.insert(parents[i]);
    }
    return ret.size();
  }

  int findRoot(vector<int>& parents, int man) {
    if (parents[man] == man) return man;
    int root = findRoot(parents, parents[man]);
    parents[man] = root;
    return root;
  }

  int belongToSameCircle(vector<int>& parents, int i, int j) {
    return findRoot(parents, j) == findRoot(parents, i);
  }
};

int main() {
  Solution sol;
  vector<vector<int>> M;

  M = {
    {1,1,0},
    {1,1,0},
    {0,0,1}
  };
  assert(sol.findCircleNum(M) == 2);

  M = {
    {1,1,0},
    {1,1,1},
    {0,1,1}
  };
  assert(sol.findCircleNum(M) == 1);

  M = {
    {1,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,1,1,0,0,0,0},
    {0,0,0,1,0,1,0,0,0,0,1,0,0,0,0},
    {0,0,0,1,0,0,1,0,1,0,0,0,0,1,0},
    {1,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,0,0,0,0,1,0},
    {0,0,0,0,1,0,0,0,0,1,0,1,0,0,1},
    {0,0,0,0,1,1,0,0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,1,0,1,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,1}
  };
  assert(sol.findCircleNum(M) == 3);
}
