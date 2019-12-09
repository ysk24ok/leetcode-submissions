#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minFlips(vector<vector<int>>& mat) {
    if (is_all_zero(mat)) return 0;
    queue<pair<vector<vector<int>>, int>> q;
    unordered_map<string, int> map;
    string key = create_cache_key(mat);
    map[key] = 0;
    for (int i = 0; i < mat.size(); ++i) {
      for (int j = 0; j < mat[0].size(); ++j) {
        vector<vector<int>> mat_copied = mat;
        flip(mat_copied, i, j);
        q.push({mat_copied, 1});
      }
    }
    while (!q.empty()) {
      pair<vector<vector<int>>, int> pair = q.front();
      q.pop();
      mat = pair.first;
      int count = pair.second;
      if (is_all_zero(mat)) return count;
      key = create_cache_key(mat);
      if (map.find(key) != map.end()) continue;
      map[key] = 0;
      for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[0].size(); ++j) {
          vector<vector<int>> mat_copied = mat;
          flip(mat_copied, i, j);
          q.push({mat_copied, count+1});
        }
      }
    }
    return -1;
  }

  void flip(vector<vector<int>>& mat, int r, int c) {
    flip_one(mat, r-1, c);
    flip_one(mat, r, c-1);
    flip_one(mat, r, c);
    flip_one(mat, r, c+1);
    flip_one(mat, r+1, c);
  }

  void flip_one(vector<vector<int>>& mat, int i, int j) {
    if (i >= mat.size() || i < 0 || j >= mat[0].size() || j < 0) return;
    if (mat[i][j] == 0) {
      mat[i][j] = 1;
    } else {
      mat[i][j] = 0;
    }
  }

  bool is_all_zero(const vector<vector<int>>& mat) {
    for (int i = 0; i < mat.size(); ++i) {
      for (int j = 0; j < mat[0].size(); ++j) {
        if (mat[i][j] == 1) return false;
      }
    }
    return true;
  }

  string create_cache_key(const vector<vector<int>>& mat) {
    string s;
    for (int i = 0; i < mat.size(); ++i) {
      for (int j = 0; j < mat[0].size(); ++j) {
        s += to_string(mat[i][j]);
      }
    }
    return s;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> mat;

  mat = {{1,1},{0,1}};
  assert(sol.minFlips(mat) == 1);

  mat = {{0,0},{0,1}};
  assert(sol.minFlips(mat) == 3);

  mat = {{0}};
  assert(sol.minFlips(mat) == 0);

  mat = {{1}};
  assert(sol.minFlips(mat) == 1);

  mat = {{1,1,1},{1,0,1},{0,0,0}};
  assert(sol.minFlips(mat) == 6);

  mat = {{1,0,0},{1,0,0}};
  assert(sol.minFlips(mat) == -1);
}
