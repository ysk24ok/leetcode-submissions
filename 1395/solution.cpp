#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int numTeams(vector<int>& rating) {
    if (rating.size() < 3) return 0;
    int ret = count(rating);
    reverse(rating.begin(), rating.end());
    ret += count(rating);
    return ret;
  }

  int count(const vector<int>& rating) {
    vector<int> two_dp(rating.size());
    for (size_t j = 1; j < rating.size(); ++j) {
      for (size_t i = 0; i < j; ++i) {
        if (rating[i] < rating[j]) two_dp[j]++;
      }
    }
    vector<int> three_dp(rating.size());
    for (size_t k = 2; k < rating.size(); ++k) {
      for (size_t j = 0; j < k; ++j) {
        if (rating[j] < rating[k]) three_dp[k] += two_dp[j];
      }
    }
    return accumulate(three_dp.begin(), three_dp.end(), 0);
  }
};

int main() {
  Solution sol;
  vector<int> rating;

  rating = {2,5,3,4,1};
  assert(sol.numTeams(rating) == 3);

  rating = {2,1,3};
  assert(sol.numTeams(rating) == 0);

  rating = {1,2,3,4};
  assert(sol.numTeams(rating) == 4);
}
