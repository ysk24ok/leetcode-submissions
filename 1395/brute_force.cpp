#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numTeams(vector<int>& rating) {
    size_t size = rating.size();
    int ret = 0;
    for (size_t i = 0; i < size - 2; ++i) {
      for (size_t j = i + 1; j < size - 1; ++j) {
        for (size_t k = j + 1; k < size; ++k) {
          if ((rating[i] < rating[j] && rating[j] < rating[k]) || (rating[i] > rating[j] && rating[j] > rating[k])) ret++;
        }
      }
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
