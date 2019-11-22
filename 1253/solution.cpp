#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
    vector<vector<int>> ret(2, vector<int>(colsum.size()));
    // check 2 in colsum
    for (int i = 0; i < colsum.size(); i++) {
      if (colsum[i] != 2) continue;
      ret[0][i] += 1;
      upper -= 1;
      ret[1][i] += 1;
      lower -= 1;
    }
    // check 1 in colsum
    for (int i = 0; i < colsum.size(); i++) {
      if (colsum[i] != 1) continue;
      if (upper > 0) {
        ret[0][i] += 1;
        upper -= 1;
      } else {
        ret[1][i] += 1;
        lower -= 1;
      }
    }
    if (upper != 0 || lower != 0) return {};
    return ret;
  }
};

void print_vector(const vector<vector<int>>& v) {
  for (auto& vv : v) {
    for (auto& vvv : vv) {
      cout << vvv << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  Solution  sol;
  vector<int> colsum;
  vector<vector<int>> got;

  colsum = {1,1,1};
  got = sol.reconstructMatrix(2, 1, colsum);
  print_vector(got);

  colsum = {2,2,1,1};
  got = sol.reconstructMatrix(2, 3, colsum);
  assert(got.size() == 0);

  colsum = {2,1,2,0,1,0,1,2,0,1};
  got = sol.reconstructMatrix(5, 5, colsum);
  print_vector(got);

  colsum = {1,2,1,2,0};
  got = sol.reconstructMatrix(4, 2, colsum);
  print_vector(got);

  colsum = {2,1,2,2,1,1,1};
  got = sol.reconstructMatrix(4, 7, colsum);
  print_vector(got);
}
