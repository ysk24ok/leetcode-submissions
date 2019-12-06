#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// time complexity: O(N)
// space complexity: O(N) (If A = {1,1,1,1,1}, map requires O(N))
class Solution {
 public:
  int numSubarraysWithSum(vector<int>& A, int S) {
    vector<int> prefix_sum(A.size()+1);
    for (int i = 0; i < A.size(); i++) {
      prefix_sum[i+1] = prefix_sum[i] + A[i];
    }
    // key: start index of substrings
    // val: number of substrings
    unordered_map<int, int> map;
    int ret = 0;
    for (auto& x: prefix_sum) {
      if (map.find(x) == map.end()) map[x] = 0;
      if (x - S >= 0) {
        ret += map[x-S];
      }
      map[x]++;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> A;

  //   0,1,1,2,2,3
  //   1,0,1
  //   1,0,1,0
  //     0,1,0,1
  //       1,0,1
  A = {1,0,1,0,1};
  assert(sol.numSubarraysWithSum(A, 2) == 4);

  //   0,1,1,2,3,3
  //   1,0,1
  //     0,1,1
  //     0,1,1,0
  //       1,1
  //       1,1,0
  A = {1,0,1,1,0};
  assert(sol.numSubarraysWithSum(A, 2) == 5);

  //   0,0,1,1,2,2
  //   0,1
  //     1
  //   0,1,0
  //     1,0
  //       0,1
  //         1
  //       0,1,0
  //         1,0
  A = {0,1,0,1,0};
  assert(sol.numSubarraysWithSum(A, 1) == 8);

  //   0,0,0,0,0,0
  A = {0,0,0,0,0};
  assert(sol.numSubarraysWithSum(A, 0) == 15);
}
