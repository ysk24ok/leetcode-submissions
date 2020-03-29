#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numTeams(vector<int>& rating) {
    size_t size = rating.size();
    int ret = 0;
    for (size_t i = 1; i < size - 1; ++i) {
      int left_less = 0;
      int left_greater = 0;
      int right_less = 0;
      int right_greater = 0;
      for (size_t j = 0; j < size; ++j) {
        if (i == j) continue;
        if (rating[i] < rating[j]) {
          if (i < j) right_greater++;
          else left_greater++;
        } else if (rating[i] > rating[j]) {
          if (i < j) right_less++;
          else left_less++;
        }
      }
      ret += left_less * right_greater + left_greater * right_less;
    }
    return ret;
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
