#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

class Solution {
 public:
  int dieSimulator(int n, vector<int>& rollMax) {
    int dp[6][15];
    memset(dp, 0, sizeof(dp));
    for (int die = 0; die < 6; die++) {
      dp[die][0] = 1;
    }
    for (int roll = 1; roll < n; roll++) {
      int new_dp[6][15];
      memset(new_dp, 0, sizeof(new_dp));
      for (int die = 0; die < 6; die++) {
        for (int new_die = 0; new_die < 6; new_die++) {
          for (int j = 0; j < 15; j++) {
            if (die == new_die) {
              if (rollMax[new_die] > j + 1) {
                new_dp[new_die][j+1] += dp[die][j];
                new_dp[new_die][j+1] %= mod;
              }
            } else {
              new_dp[new_die][0] += dp[die][j];
              new_dp[new_die][0] %= mod;
            }
          }
        }
      }
      memcpy(dp, new_dp, sizeof(new_dp));
      /*
      for (int die = 0; die < 6; die++) {
        for (int j = 0; j < 15; j++) {
          cout << dp[die][j] << ",";
        }
        cout << endl;
      }
      cout << endl;
      */
    }
    int ret = 0;
    for (int die = 0; die < 6; die++) {
      for (int j = 0; j < 15; j++) {
        ret += dp[die][j];
        ret %= mod;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int n;
  vector<int> rollMax;

  n = 2;
  rollMax = {1,1,2,2,2,3};
  assert(sol.dieSimulator(n, rollMax) == 34);

  n = 2;
  rollMax = {1,1,1,1,1,1};
  assert(sol.dieSimulator(n, rollMax) == 30);

  n = 3;
  rollMax = {1,1,1,2,2,3};
  assert(sol.dieSimulator(n, rollMax) == 181);

  n = 20;
  rollMax = {8,5,10,8,7,2};
  assert(sol.dieSimulator(n, rollMax) == 822005673);
}
