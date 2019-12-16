#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ret;
    vector<int> vec;
    recursion(ret, vec, n, k, 1);
    return ret;
  }

  void recursion(vector<vector<int>>& ret, vector<int>& vec, int n, int k, int start) {
    for (int i = start; i <= n-(k-1); i++) {
      vector<int> vec_copy = vec;
      if (k > 1) {
        vec_copy.push_back(i);
        recursion(ret, vec_copy, n, k-1, i+1);
      } else {
        ret.push_back(vec);
        ret[ret.size()-1].push_back(i);
      }
    }
  }
};

int main() {
  Solution sol;
  vector<vector<int>> got;

  got = sol.combine(4, 2);
  assert(got.size() == 6);
  assert(got[0][0] == 1 && got[0][1] == 2);
  assert(got[1][0] == 1 && got[1][1] == 3);
  assert(got[2][0] == 1 && got[2][1] == 4);
  assert(got[3][0] == 2 && got[3][1] == 3);
  assert(got[4][0] == 2 && got[4][1] == 4);
  assert(got[5][0] == 3 && got[5][1] == 4);

  got = sol.combine(5, 3);
  assert(got.size() == 10);
  assert(got[0][0] == 1 && got[0][1] == 2 && got[0][2] == 3);
  assert(got[1][0] == 1 && got[1][1] == 2 && got[1][2] == 4);
  assert(got[2][0] == 1 && got[2][1] == 2 && got[2][2] == 5);
  assert(got[3][0] == 1 && got[3][1] == 3 && got[3][2] == 4);
  assert(got[4][0] == 1 && got[4][1] == 3 && got[4][2] == 5);
  assert(got[5][0] == 1 && got[5][1] == 4 && got[5][2] == 5);
  assert(got[6][0] == 2 && got[6][1] == 3 && got[6][2] == 4);
  assert(got[7][0] == 2 && got[7][1] == 3 && got[7][2] == 5);
  assert(got[8][0] == 2 && got[8][1] == 4 && got[8][2] == 5);
  assert(got[9][0] == 3 && got[9][1] == 4 && got[9][2] == 5);

  got = sol.combine(4, 1);
  assert(got.size() == 4);
  assert(got[0][0] == 1);
  assert(got[1][0] == 2);
  assert(got[2][0] == 3);
  assert(got[3][0] == 4);
}
